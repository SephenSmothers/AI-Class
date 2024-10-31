#include "PathSearch.h"
#include <iostream>

namespace fullsail_ai {
	namespace algorithms {

		PathSearch::PathSearch() : tileMap(nullptr)
		{

		}

		PathSearch::~PathSearch()
		{
			shutdown();
		}

		void PathSearch::initialize(TileMap* _tileMap)
		{
			for (auto& pair : nodes) {
				delete pair.second;
			}
			nodes.clear();

			tileMap = _tileMap;

			tileMap->setRadius(_tileMap->getTileRadius());

			//Creating each valid SearchNode
			for (int row = 0; row < tileMap->getRowCount(); ++row) {
				for (int col = 0; col < tileMap->getColumnCount(); ++col) {
					Tile* tile = tileMap->getTile(row, col);
					if (tile && tile->getWeight() > 0) {
						SearchNode* newNode = new SearchNode;
						newNode->tile = tile; 
						nodes[tile] = newNode;
					}
				}
			}

			//Setting the edges for each tile
			for (auto& pair : nodes) {
				Tile* tile = pair.first;
				SearchNode* node = pair.second;


				// Check neighboring tiles
				for (int dir = 0; dir < 6; ++dir) {
					int neighborRow, neighborCol;

					if (tile->getRow() % 2 == 0) {
						// Even row offset

						neighborRow = tile->getRow() + HexagonGridOffsetsEvenRow[dir].second;
						neighborCol = tile->getColumn() + HexagonGridOffsetsEvenRow[dir].first;
					}
					else {
						// Odd row offset

						neighborRow = tile->getRow() + HexagonGridOffsetsOddRow[dir].second;
						neighborCol = tile->getColumn() + HexagonGridOffsetsOddRow[dir].first;
					}

					Tile* neighborTile = tileMap->getTile(neighborRow, neighborCol);
					if (neighborTile && neighborTile->getWeight() > 0) {
						auto neighborNode = nodes.find(neighborTile);
						if (neighborNode != nodes.end()) {
							node->neighbors.push_back(neighborNode->second);
							tile->addLineTo(neighborTile, 0xFFFF00FF);
						}
					}
				}
			}

			startTime = std::chrono::steady_clock::now();
			currentNode = new PlannerNode();
		}

		DLLEXPORT void PathSearch::enter(int startRow, int startColumn, int goalRow, int goalColumn)
		{
			Tile* startTile = tileMap->getTile(startRow, startColumn);
			if (!startTile)
				return;

			solution.clear();

			auto startNodeIter = nodes.find(startTile);
			if (startNodeIter == nodes.end())
				return;


			startNode = startNodeIter->second;

			Tile* goalTile = tileMap->getTile(goalRow, goalColumn);
			if (!goalTile)
				return;


			auto goalNodeIter = nodes.find(goalTile);
			if (goalNodeIter == nodes.end())
				return;

			goalNode = goalNodeIter->second;

			for (auto& pair : visited) {
				delete pair.second;
			}
			visited.clear();

			PlannerNode* startPlannerNode = new PlannerNode;
			startPlannerNode->searchNode = startNode;
			startPlannerNode->parent = nullptr;

			visited[startNode] = startPlannerNode;

			currentNode->searchNode = startNode;
			currentNode->parent = nullptr;

			visited[startNode]->givenCost = 0;
			visited[startNode]->heuristicCost = estimate(startNode, goalNode);
			visited[startNode]->cost = visited[startNode]->givenCost + (visited[startNode]->heuristicCost * hWeight); 
			//visited[startNode]->cost = visited[startNode]->givenCost + visited[startNode]->heuristicCost;

			auto startNodeIterV = visited.find(startNode);

			if (startNodeIterV != visited.end())
				queue.push(startNodeIterV->second);
			else
				return;
		}

		DLLEXPORT bool PathSearch::isDone() const
		{
			return !solution.empty();
		}

		DLLEXPORT void PathSearch::update(long timeslice)
		{
			if (!tileMap || visited.empty())
				return;

			while (!queue.empty())
			{
				currentNode = queue.front();
				queue.pop();

				if (currentNode->searchNode == goalNode)
				{
					solution = getSolution();
					return;
				}

				for (int i = 0; i < currentNode->searchNode->neighbors.size(); i++)
				{
					if (currentNode->searchNode->tile->getWeight() == 0)
					{
						continue;
					}

					SearchNode* successor = currentNode->searchNode->neighbors[i];
					float tempCost = currentNode->givenCost + currentNode->searchNode->neighbors[i]->tile->getWeight();
					//float tempCost = currentNode->givenCost + currentNode->searchNode->tile->getWeight();

					if (visited[successor] != nullptr)
					{
						PlannerNode* visitedNode = visited[successor];
						if (tempCost < visitedNode->givenCost)
						{
							queue.remove(visitedNode);
							visitedNode->givenCost = tempCost;
							//visitedNode->cost = visitedNode->givenCost + visitedNode->heuristicCost;
							visitedNode->cost = visitedNode->givenCost + (visitedNode->heuristicCost * hWeight);
							visitedNode->parent = currentNode;
							visitedNode->searchNode = successor;
							currentNode->searchNode->neighbors[i]->tile->setFill(0xFF0000FF);
							queue.push(visitedNode);
						}
					}
					else
					{
						PlannerNode* visitedNode2 = new PlannerNode();
						visitedNode2->givenCost = tempCost;
						visitedNode2->heuristicCost = estimate(successor, goalNode);
						//visitedNode2->cost = visitedNode2->givenCost + visitedNode2->heuristicCost;
						visitedNode2->cost = visitedNode2->givenCost + (visitedNode2->heuristicCost * hWeight);
						visitedNode2->parent = currentNode;
						visitedNode2->searchNode = successor;
						visited[successor] = visitedNode2;
						currentNode->searchNode->neighbors[i]->tile->setFill(0xFF0000FF);
						queue.push(visitedNode2);
					}
				}

				if (timeslice == 0 && std::chrono::steady_clock::now() >= (startTime + std::chrono::milliseconds(timeslice)))
					break;
			}

			if (queue.empty())
			{
				std::cout << "queue empty but solution not found!\n";
			}
		}
		
		DLLEXPORT std::vector<Tile const*> const PathSearch::getSolution() const
		{
			std::vector<Tile const*> _Solution;
			PlannerNode* currNode = currentNode;
			unsigned int lineColor = 0xFFFF00FF;

			while (currNode != nullptr) {

				if (currNode->parent != nullptr)
					currNode->searchNode->tile->addLineTo(currNode->parent->searchNode->tile, lineColor);

				_Solution.push_back(currNode->searchNode->tile);
				currNode = currNode->parent;
			}

			return _Solution;
		}

		DLLEXPORT void PathSearch::exit()
		{
			// Clear the visited map
			for (auto& pair : visited) {
				delete pair.second;
			}
			visited.clear();

			queue.clear();

			startNode = nullptr;
			goalNode = nullptr;
		}

		DLLEXPORT void PathSearch::shutdown()
		{
			for (auto& pair : nodes) {
				delete pair.second;
			}
			nodes.clear();
		}

		float PathSearch::estimate(SearchNode* start, SearchNode* end)
		{
			float x = std::pow((end->tile->getXCoordinate() - start->tile->getXCoordinate()), 2);
			float y = std::pow((end->tile->getYCoordinate() - start->tile->getYCoordinate()), 2);
			float distance = std::sqrt(x + y);

			return distance * end->tile->getWeight();  
		}
	}
};  // namespace fullsail_ai::algorithms

