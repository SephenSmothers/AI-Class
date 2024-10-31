//! \file QueueList_TODO.h
//! \brief Defines the <code>fullsail_ai::data_structures::QueueList</code> class template
//! implementation.
//! \author Cromwell D. Enage
#ifndef _FULLSAIL_AI_FUNDAMENTALS_QUEUELIST_TODO_H_
#define _FULLSAIL_AI_FUNDAMENTALS_QUEUELIST_TODO_H_

namespace fullsail_ai { namespace fundamentals {

	//! \TODO
	//!   - Complete the definition of the <code>QueueList::Iterator</code> pre-increment operator.
	//!   - Complete the definition of the <code>QueueList::Iterator</code> dereference operator.
	//!   - Define the <code>QueueList</code> constructor.
	//!   - Define the <code>QueueList</code> destructor.
	//!   - Define the <code>QueueList</code> methods.


	template <typename T>
	typename QueueList<T>::Iterator& QueueList<T>::Iterator::operator++()
	{
		// TODO: Complete the definition of this operator.
		return *this;
	}

	template <typename T>
	T QueueList<T>::Iterator::operator*() const
	{
		// TODO: Complete the definition of this operator.

	}


}}  // namespace fullsail_ai::fundamentals

#endif  // _FULLSAIL_AI_FUNDAMENTALS_QUEUELIST_TODO_H_

