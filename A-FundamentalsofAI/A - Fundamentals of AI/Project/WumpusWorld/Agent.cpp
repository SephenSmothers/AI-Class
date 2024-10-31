//! \file Agent.cpp
//! \brief Implements the <code>fullsail_ai::fundamentals::Agent</code> class.
//! \author Jeremiah Blanchard

#include "Agent.h"

namespace fullsail_ai { namespace fundamentals {

	// Initialize Knowledge
	void Knowledge::init(unsigned _x, unsigned _y, unsigned width, unsigned height)
	{
		// Erase our knowledge of the world.
		modelWorld.resize(width);
		stimulus.resize(width);
		for (unsigned xIndex = 0; xIndex < width; xIndex++)
		{
			stimulus[xIndex].resize(height);
			modelWorld[xIndex].resize(height);

			for (unsigned yIndex = 0; yIndex < height; yIndex++)
			{
				modelWorld[xIndex][yIndex] = UNKNOWN;
				stimulus[xIndex][yIndex] = UNEXPLORED;
			}
		}

		// Forget the previous wumpus location.
		wumpusX = wumpusY = -1;

		// Set the agent's starting location.
		x = _x;
		y = _y;

		// Forget about the gold.
		hasGold = false;
	}

	// Clear out Agent Knowledge
	void Knowledge::shutdown()
	{
		modelWorld.clear();
	}

	// Instantiate an agent.
	Agent::Agent(World& _world, Behavior& _behavior, void (*_behaviorLog)(Behavior const*)) : world(_world), behavior(_behavior)
	{
		behaviorLog = _behaviorLog;
	}

	// Returns a reference to the agent's knowledge.
	Knowledge& Agent::getKnowledge()
	{
		return knowledge;
	}

	// Begin agent functionality.
	void Agent::enter(unsigned _x, unsigned _y)
	{
		// Erase our knowledge of the world.
		knowledge.init(_x, _y, world.getWidth(), world.getHeight());
	}

	// Update the agent's behavior.
	void Agent::update()
	{
		perceive();
		behavior.run(behaviorLog, this);
	}

	// Shut down the agent.
	void Agent::exit()
	{
		knowledge.shutdown();
	}

	// Agent actions
	bool Agent::pickUpGold()
	{
		if (world.retrieveGold())
		{
			knowledge.hasGold = true;
			return true;
		}

		return false;
	}

	bool Agent::move(Direction direction)
	{
		if (world.moveAgent(direction))
		{
			switch (direction)
			{
			case UP:
				knowledge.y--;
				break;
			case DOWN:
				knowledge.y++;
				break;
			case LEFT:
				knowledge.x--;
				break;
			case RIGHT:
				knowledge.x++;
				break;
			}

			return true;
		}

		return false;
	}

	bool Agent::shoot(Direction direction)
	{
		if (knowledge.hasArrow)
		{
			world.attackWumpus(direction);
			knowledge.hasArrow = false;
			return true;
		}

		return false;
	}

	void Agent::perceive()
	{
		// Gather stimulus from the world state.
		knowledge.stimulus[knowledge.x][knowledge.y] = world.getStimulus();
	}
}}
