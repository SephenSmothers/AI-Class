//! \file PathSearch.h
//! \brief Defines the fullsail_ai::algorithms::PathSearch class interface.
//! \author Cromwell D. Enage, 2009; Jeremiah Blanchard, 2012; Matthew Tjarks 2017-2019
#ifndef _FULLSAIL_AI_PATH_PLANNER_PATH_SEARCH_H_
#define _FULLSAIL_AI_PATH_PLANNER_PATH_SEARCH_H_

// change this to start the program on whatever default map as you like from the table below
#define USEDEFAULTMAP hex035x035


#define hex006x006 "./Data/hex006x006.txt"
#define hex014x006 "./Data/hex014x006.txt"
#define hex035x035 "./Data/hex035x035.txt"
#define hex054x045 "./Data/hex054x045.txt"
#define hex098x098 "./Data/hex098x098.txt"
#define hex113x083 "./Data/hex113x083.txt"

// change this to 1(true), and change the data below when you want to test specific starting and goal locations on startup
#define OVERRIDE_DEFAULT_STARTING_DATA 0


// Make sure your start and goal are valid locations!
#define DEFAULT_START_ROW 0
#define DEFAULT_START_COL 0
#define DEFAULT_GOAL_ROW ?
#define DEFAULT_GOAL_COL ?


#include <vector>
#include <unordered_map>
#include <chrono>
#include <queue>
#include "../TileSystem/Tile.h"
#include "../TileSystem/TileMap.h"
#include "../platform.h"
#include "../PriorityQueue.h"

namespace fullsail_ai {
	namespace algorithms {

		class PathSearch
		{
		private:
			struct SearchNode
			{
				Tile* tile;
				std::vector<SearchNode*> neighbors;
			};

			struct PlannerNode
			{
				SearchNode* searchNode;
				PlannerNode* parent;

				//TODO: Add cost variables for whichever search you are currently working on
				float cost;
				float heuristicCost;
				float givenCost; 
			};

			struct GreedyComparator {
				bool operator()(const PlannerNode* lhs, const PlannerNode* rhs)
				{
					return (lhs->cost > rhs->cost);
				}
			};

			std::unordered_map<Tile*, SearchNode*> nodes;
			std::unordered_map<SearchNode*, PlannerNode*> visited;

			TileMap* tileMap;
			//TODO: Add other supporting variables and functions
			std::vector<Tile const*> solution;
			PlannerNode* currentNode;
			SearchNode* goalNode;
			SearchNode* startNode;
			//std::queue<PlannerNode*> queue;
			PriorityQueue<PlannerNode*, GreedyComparator> queue;
			std::chrono::steady_clock::time_point startTime;
			float hWeight = 1.0;

			std::pair<int, int> HexagonGridOffsetsEvenRow[6] = {
				{-1, 0},  // West
				{-1,-1},  // Northwest
				{0, -1},  // Northeast
				{1, 0},   // East
				{0, 1},   // Southeast
				{-1, 1}    // Southwest
			};

			std::pair<int, int> HexagonGridOffsetsOddRow[6] = {
				{-1, 0},   // West
				{0, -1},  // Northwest
				{1, -1},   // Northeast
				{1, 0},    // East
				{1, 1},    // Southeast
				{0, 1}    // Southwest
			};

			float estimate(SearchNode* start, SearchNode* end); 


		public:
			//! \brief Default constructor.
			DLLEXPORT PathSearch();

			//! \brief Destructor.
			DLLEXPORT ~PathSearch();

			//! \brief Sets the tile map.
			//!
			//! Invoked when the user opens a tile map file.
			//!
			//! \param   _tileMap  the data structure that this algorithm will use
			//!                    to access each tile's location and weight data.
			DLLEXPORT void initialize(TileMap* _tileMap);

			//! \brief Enters and performs the first part of the algorithm.
			//!
			//! Invoked when the user presses one of the play buttons.
			//!
			//! \param   startRow         the row where the start tile is located.
			//! \param   startColumn      the column where the start tile is located.
			//! \param   goalRow          the row where the goal tile is located.
			//! \param   goalColumn       the column where the goal tile is located.
			DLLEXPORT void enter(int startRow, int startColumn, int goalRow, int goalColumn);

			//! \brief Returns true if and only if no nodes are left open.
			//!
			//! \return true if no nodes are left open, false otherwise.
			DLLEXPORT bool isDone() const;

			//! \brief Performs the main part of the algorithm until the specified time has elapsed or
			//! no nodes are left open.
			DLLEXPORT void update(long timeslice);

			//! \brief Returns an unmodifiable view of the solution path found by this algorithm.
			DLLEXPORT std::vector<Tile const*> const getSolution() const;

			//! \brief Resets the algorithm.
			DLLEXPORT void exit();

			//! \brief Uninitializes the algorithm before the tile map is unloaded.
			DLLEXPORT void shutdown();

			
		};
	}
}  // namespace fullsail_ai::algorithms

#endif  // _FULLSAIL_AI_PATH_PLANNER_PATH_SEARCH_H_

