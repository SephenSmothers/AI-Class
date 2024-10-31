// Game.cpp - the entry point of the Behavior Tree Game (in the Wumpus World.)
// Code by Jeremiah Blanchard, August 2009
// Updated by Jeremiah Blanchard, January 2012
#include <limits>
#include <iostream>
#include <vector>
#include <queue>

#include "definitions.h"
#include "Game.h"
#include "Agent.h"
#include "Behaviors.h"

using namespace std;
using namespace fullsail_ai::fundamentals;

char world1[6][6] = { { NONE, STENCH, WUMPUS, STENCH, NONE, NONE },
					  { NONE, NONE, BREEZE | STENCH | GOLD, NONE, NONE, NONE },
					  { NONE, BREEZE, PIT, BREEZE, NONE, BREEZE },
					  { NONE, NONE, BREEZE, BREEZE, BREEZE, PIT },
					  { NONE, NONE, BREEZE, PIT, BREEZE, BREEZE },
					  { START, NONE, NONE, BREEZE, NONE, NONE } };

Behavior* buildTreeOne();
Behavior* buildTreeTwo();
void deleteTree(Behavior* root);
void printLeafBehavior(Behavior const* behavior);
void printBehavior(Behavior const* behavior);

namespace fullsail_ai { namespace fundamentals {

	void Game::main()
	{
		char** worldData = new char*[6];
		for (int xIndex = 0; xIndex < 6; xIndex++)
		{
			worldData[xIndex] = new char[6];
			for (int yIndex = 0; yIndex < 6; yIndex++)
				worldData[xIndex][yIndex] = world1[xIndex][yIndex];
		}

		World world(worldData, 6, 6);
		Behavior* behavior = new Sequence("Basic Behavior");
		behavior->addChild(new ProcessPercepts("Process Percepts"));
		behavior->addChild(new Selector("Choose Action"));
		behavior->getChild(1)->addChild(new Sequence("Look For Gold"));
		behavior->getChild(1)->getChild(0)->addChild(new CheckForGold("Check For Gold"));
		behavior->getChild(1)->getChild(0)->addChild(new PickUpGold("Pick Up Gold"));
		behavior->getChild(1)->addChild(new ShootWumpus("Shoot Wumpus"));
		behavior->getChild(1)->addChild(new Selector("Explore"));
		behavior->getChild(1)->getChild(2)->addChild(new ExploreDirection("Explore Up", UP));
		behavior->getChild(1)->getChild(2)->addChild(new ExploreDirection("Explore Down", DOWN));
		behavior->getChild(1)->getChild(2)->addChild(new ExploreDirection("Explore Left", LEFT));
		behavior->getChild(1)->getChild(2)->addChild(new ExploreDirection("Explore Right", RIGHT));

		//		ProcessPercepts* behavior = new ProcessPercepts("Process Percepts");
		Agent agent(world, *behavior, printLeafBehavior);
		agent.enter(world.agentX, world.agentY);

		cout << "\nWorld Information\n-----------------\n";
		cout << "Agent Position: (" << world.agentX << ", " << world.agentY << ")" << endl;
		cout << "Agent Has Arrow: " << world.agentHasArrow << endl;
		cout << "Agent Has Gold: " << world.goldRetrieved << endl;
		cout << "Agent is Alive: " << world.agentAlive << endl;
		cout << "Wumpus is Alive: " << world.wumpusAlive << endl << endl;

		while(world.agentAlive && world.agentHasArrow)
		{
			cout << "Leaf Behaviors\n--------------\n";
			agent.update();

			cout << "\nWorld Information\n-----------------\n";
			cout << "Agent Position: (" << world.agentX << ", " << world.agentY << ")" << endl;
			cout << "Agent Has Arrow: " << world.agentHasArrow << endl;
			cout << "Agent Has Gold: " << world.goldRetrieved << endl;
			cout << "Agent is Alive: " << world.agentAlive << endl;
			cout << "Wumpus is Alive: " << world.wumpusAlive << endl << endl;
		}

		if (!world.agentAlive)
			cout << "You died!" << endl;

		if (world.goldRetrieved)
			cout << "You found the gold!" << endl;

		if (!world.wumpusAlive)
			cout << "You killed the wumpus!" << endl;

		cout << "Press ENTER to continue..." << endl;
		while(cin.get() != '\n') {;}

		deleteTree(behavior);
		for (unsigned index = 0; index < 6; index++)
			delete worldData[index];

		delete[] worldData;
	}
}}

void main()
{
	// First, run a general test of the behavior tree mechanisms.
	Behavior* root = buildTreeOne();
	cout << "\nTree One:\n---------\n";
	root->run(printBehavior, NULL);
	deleteTree(root);

	root = buildTreeTwo();
	cout << "\nTree Two:\n----------\n";
	root->run(printBehavior, NULL);
	cout << "\nBreadth-First:\n--------------\n";
	root->breadthFirstTraverse(printBehavior);
	cout << "\nPreorder\n--------\n";
	root->preOrderTraverse(printBehavior);
	cout << "\nPostorder\n---------\n";
	root->postOrderTraverse(printBehavior);
	deleteTree(root);

	cout << "Press ENTER to continue..." << endl;
	while(cin.get() != '\n') {;}

	// Then, run the wumpus world game simulation.
	fullsail_ai::fundamentals::Game::main();
}

Behavior* buildTreeOne()
{
	Behavior* node1, * node2, *node3;

	// Create the root.
	Behavior* root = new Selector("Decider");

	// Build the "Spy" branch.
	node1 = new Sequence("SpyOnEnemy");
	node1->addChild(new TestBehavior("Find", true));
	node1->addChild(new TestBehavior("Follow", true));
	node1->addChild(new TestBehavior("Report", false));
	root->addChild(node1);

	// Build the "Attack" branch.
	node1 = new Selector("Approach");

	node2 = new Sequence("DirectAttack");
	node2->addChild(new TestBehavior("DrawWeapon", true));
	node3 = new Selector("WeaponAttack");
	node3->addChild(new TestBehavior("StabLeft", false));
	node3->addChild(new TestBehavior("StabFront", false));
	node3->addChild(new TestBehavior("StabRight", false));
	node2->addChild(node3);
	node1->addChild(node2);

	node2 = new Sequence("SneakAttack");
	node2->addChild(new TestBehavior("Find", false));
	node2->addChild(new TestBehavior("Follow", true));
	node2->addChild(new TestBehavior("Back-Stab", false));
	node1->addChild(node2);

	root->addChild(node1);

	// Build the "Flee" branch.
	node1 = new Sequence("Flee");
	node1->addChild(new TestBehavior("FindEscape", true));
	node1->addChild(new TestBehavior("FollowPath", true));
	node1->addChild(new TestBehavior("RunAway", true));
	root->addChild(node1);

	return root;
}

Behavior* buildTreeTwo()
{
	Behavior* node1, * node2, *node3;

	// Create the root.
	Behavior* root = new Selector("Decider");

	// Build the "Spy" branch.
	node1 = new Sequence("SpyOnEnemy");
	node1->addChild(new TestBehavior("Find", false));
	node1->addChild(new TestBehavior("Follow", false));
	node1->addChild(new TestBehavior("Report", false));
	root->addChild(node1);

	// Build the "Attack" branch.
	node1 = new Selector("Approach");

	node2 = new Sequence("DirectAttack");
	node2->addChild(new TestBehavior("DrawWeapon", true));
	node3 = new Selector("WeaponAttack");
	node3->addChild(new TestBehavior("StabLeft", true));
	node3->addChild(new TestBehavior("StabFront", true));
	node3->addChild(new TestBehavior("StabRight", true));
	node2->addChild(node3);
	node1->addChild(node2);

	node2 = new Sequence("SneakAttack");
	node2->addChild(new TestBehavior("Find", false));
	node2->addChild(new TestBehavior("Follow", false));
	node2->addChild(new TestBehavior("Back-Stab", true));
	node1->addChild(node2);

	root->addChild(node1);

	// Build the "Flee" branch.
	node1 = new Sequence("Flee");
	node1->addChild(new TestBehavior("FindEscape", true));
	node1->addChild(new TestBehavior("FollowPath", true));
	node1->addChild(new TestBehavior("RunAway", false));
	root->addChild(node1);

	return root;
}

void deleteTree(Behavior* root)
{
	std::queue<Behavior*> q;
	q.push(root);

	while (!q.empty())
	{
		Behavior* current = q.front();
		q.pop();

		for (size_t index = 0; index < current->getChildCount(); index++)
			q.push(current->getChild(index));

		delete current;
	}
}

void printLeafBehavior(Behavior const* behavior)
{
	if (behavior->isLeaf())
		cout << behavior->toString() << endl;
}

void printBehavior(Behavior const* behavior)
{
	cout << behavior->toString() << endl;
}
