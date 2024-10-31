//! \file Behavior.h
//! \brief Defines the <code>fullsail_ai::fundamentals::Behavior</code> abstract class.
//! \author Jeremiah Blanchard with code from Cromwell D. Enage
#ifndef _FULLSAIL_AI_FUNDAMENTALS_BEHAVIOR_H_
#define _FULLSAIL_AI_FUNDAMENTALS_BEHAVIOR_H_

#include <vector>
#include "../platform.h"

namespace fullsail_ai { namespace fundamentals {

	//! \brief C++ implementation of an n-ary behavior tree node.
	class Behavior
	{
	private:
		static unsigned createdCount;
		static unsigned destroyedCount;

	protected:
		Behavior* parent;
		std::vector<Behavior*> children;
		char const* description;

	public:
		DLLEXPORT static unsigned getCreatedCount();
		DLLEXPORT static unsigned getDestroyedCount();

		//=================
		//  BASIC METHODS
		//=================

		//! \brief Creates a new <code>%Behavior</code>with the description.
		DLLEXPORT Behavior(char const* _description);

		//! \brief Returns a string representation of this <code>%Behavior</code>.
		DLLEXPORT char const* toString() const;

		//! \brief Returns a true if the behavior is a leaf node and false otherwise. (Default: false.)
		DLLEXPORT virtual bool isLeaf() const;

		//! \brief Returns the number of child nodes stored in this <code>%Behavior</code>.
		DLLEXPORT size_t getChildCount() const;

		//! \brief Returns a pointer to the index-th child node stored in this
		//! <code>%Behavior</code>.
		//!
		//! \pre      \a index <code>\< getChildCount()</code>
		//! \post     <code>NULL != getChild(index)</code>
		DLLEXPORT Behavior* getChild(size_t index);
		DLLEXPORT Behavior const* getChild(size_t index) const;

		//! \brief Adds a child to the child behaviors of this <code>%Behavior</code>.
		//!
		//! \pre      \a child <code>\!= NULL</code>
		DLLEXPORT void addChild(Behavior* child);

		//=====================
		//  TRAVERSAL METHODS
		//=====================

		//! \brief Traverses the root and all sub-nodes breadth-first.
		//!
		//! \param   dataFunction  a single-argument function that accepts the traversed node
		//!                        a valid argument.
		//!
		//! \pre     <code>NULL !=</code> \a this
		DLLEXPORT void breadthFirstTraverse(void (*dataFunction)(Behavior const*)) const;

		//! \brief Traverses the root and all sub-nodes in pre-order fashion.
		//!
		//! \param   dataFunction  a single-argument function that accepts the traversed node
		//!                        a valid argument.
		//!
		//! \pre     <code>NULL !=</code> \a this
		DLLEXPORT void preOrderTraverse(void (*dataFunction)(Behavior const*)) const;

		//! \brief Traverses the root and all sub-nodes in post-order fashion.
		//!
		//! \param   dataFunction  a single-argument function that accepts the traversed node
		//!                        a valid argument.
		//!
		//! \pre     <code>NULL !=</code> \a this
		DLLEXPORT void postOrderTraverse(void (*dataFunction)(Behavior const*)) const;

		//=======================================
		//  VIRTUAL (BEHAVIOR-SPECIFIC) METHODS
		//=======================================

		//! \brief Executes the behavior. Returns true (and runs dataFunction) on success, false otherwise.
		//!
		//! \param   dataFunction  a single-argument function that accepts the behavior as 
		//!                        a valid argument.
		//!
		//! \pre     <code>NULL !=</code> \a this
		DLLEXPORT virtual bool run(void (*dataFunction)(Behavior const*), void* context) = 0;
	};
}}  // namespace fullsail_ai::fundamentals

#endif  // _FULLSAIL_AI_FUNDAMENTALS_BEHAVIOR_H_
