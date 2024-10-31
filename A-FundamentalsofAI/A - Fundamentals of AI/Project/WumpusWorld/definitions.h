//! \file Agent.h
//! \brief Defines the <code>fullsail_ai::fundamentals::Agent</code> class.
//! \author Jeremiah Blanchard
#ifndef _FULLSAIL_AI_FUNDAMENTALS_WORLD_DEFINITIONS_H_
#define _FULLSAIL_AI_FUNDAMENTALS_WORLD_DEFINITIONS_H_

namespace fullsail_ai { namespace fundamentals {

	static const char NONE = 0x00000000,
	                  UNEXPLORED = 0x00000001,
		              STENCH = 0x00000002,
		              BREEZE = 0x00000004,
		              GOLD = 0x00000008,
					  PIT = 0x00000010,
					  WUMPUS = 0x00000020,
					  START = 0x00000040;

	enum Direction { UP, DOWN, LEFT, RIGHT };

}}  // namespace fullsail_ai::fundamentals

#endif  // _FULLSAIL_AI_FUNDAMENTALS_WORLD_DEFINITIONS_H_
