//! \file World.h
//! \brief Defines the <code>fullsail_ai::fundamentals::World</code> class.
//! \author Jeremiah Blanchard
#ifndef _FULLSAIL_AI_FUNDAMENTALS_WORLD_H_
#define _FULLSAIL_AI_FUNDAMENTALS_WORLD_H_

#include <vector>
#include "definitions.h"

using namespace std;

namespace fullsail_ai { namespace fundamentals {

	class World
	{
		friend class Game;

	private:
		vector<vector<char>> stimulus;
		int width, height;
		int agentX, agentY;

		bool agentAlive;
		bool wumpusAlive;
		bool goldRetrieved;
		bool agentHasArrow;

	public:
		// Constructor
		World(char** _stimulus, unsigned _width, unsigned _height);

		// Get methods
		char getStimulus();
		unsigned getWidth();
		unsigned getHeight();

		// Agent commands
		bool moveAgent(Direction);
		bool retrieveGold();

		void attackWumpus(Direction);
	};

}}  // namespace fullsail_ai::fundamentals

#endif  // _FULLSAIL_AI_FUNDAMENTALS_WORLD_H_
