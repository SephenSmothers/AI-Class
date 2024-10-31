//! \file QueueList.h
//! \brief Defines the <code>fullsail_ai::data_structures::QueueList</code> class template
//! interface.
//! \author Cromwell D. Enage
#ifndef _FULLSAIL_AI_FUNDAMENTALS_QUEUELIST_H_
#define _FULLSAIL_AI_FUNDAMENTALS_QUEUELIST_H_

namespace fullsail_ai { namespace fundamentals {

	//! \brief C++ implementation of a singly-linked list that can be treated as a queue.
	//!
	//! \note
	//!   - Elements are inserted to the back and accessed or removed from the front
	//!     in constant time.
	//!   - Elements are accessed or removed from anywhere else in linear time
	//!     with respect to the number of elements.
	template <typename T>
	class QueueList
	{
		struct Node
		{
			T data;
			Node* next;

			explicit Node(T);
			~Node();

			static unsigned int getCreatedNodeCount();
			static unsigned int getDestroyedNodeCount();

		private:
			static unsigned int createdNodeCount;
			static unsigned int destroyedNodeCount;
		};

	public:
		//! \brief Type definition of an iterator through a <code>QueueList</code>.
		class Iterator
		{
			Node const* currentNode;

			// The QueueList needs access to the single-argument constructor.
			friend class QueueList<T>;

			// Used by the QueueList::begin() and QueueList::end() methods.
			explicit Iterator(Node const* node);

		public:
			//! \brief Default constructor.
			//!
			//! Allows user code to delay initialization of this iterator.
			Iterator();

			//! \brief Pre-increment operator.
			//!
			//! Moves the underlying pointer to the next node.
			//!
			//! \return  A reference to this iterator.
			//!
			//! \pre
			//!   - This iterator does not point past the end of the <code>QueueList</code>.
			Iterator& operator++();

			//! \brief Post-increment operator.
			//!
			//! \return  A copy of this iterator.
			//!
			//! \pre
			//!   - This iterator does not point past the end of the <code>QueueList</code>.
			//! \post
			//!   - The <code>QueueList</code> element referred to by this iterator, if any,
			//!     follows the element referred to by the returned iterator.
			Iterator operator++(int);

			//! \brief Dereference operator.
			//!
			//! \return  The element to which this iterator refers.
			//!
			//! \pre
			//!   - This iterator does not point past the end of the <code>QueueList</code>.
			T operator*() const;

			//! \brief Equality operator.
			//!
			//! \return  <code>true</code> if both iterators refer to the same element or if both
			//!          iterators point past the end of the list, <code>false</code> otherwise.
			inline friend bool operator==(Iterator const& lhs, Iterator const& rhs)
			{
				return lhs.currentNode == rhs.currentNode;
			}

			//! \brief Inequality operator.
			//!
			//! \return  <code>true</code> if both iterators refer to different elements or if
			//!          one iterator points past the end of the list but the other does not,
			//!          <code>false</code> otherwise.
			inline friend bool operator!=(Iterator const& lhs, Iterator const& rhs)
			{
				return lhs.currentNode != rhs.currentNode;
			}
		};

	private:
		Node* front;
		Node* back;

	public:
		//! \brief Default constructor.
		QueueList();

		//! \brief Cleans up all internal memory.
		~QueueList();

	private:
		// Do not implement.
		QueueList(QueueList const&);
		QueueList& operator=(QueueList const&);

	public:
		static unsigned int getCreatedNodeCount();
		static unsigned int getDestroyedNodeCount();

		//! \brief Returns an iterator pointing to the beginning of this <code>%QueueList</code>.
		Iterator begin() const;

		//! \brief Returns an iterator pointing past the end of this <code>%QueueList</code>.
		Iterator end() const;

		//! \brief Returns <code>true</code> if this <code>%QueueList</code> does not contain any
		//! elements, <code>false</code> otherwise.
		bool isEmpty() const;

		//! \brief Adds the specified element to this <code>%QueueList</code>.
		//!
		//! \param   element  the specified element.
		//!
		//! \post
		//!   - <code>contains()</code> will return <code>true</code> if \a element is passed in.
		void enqueue(T element);

		//! \brief Returns the first element in this <code>%QueueList</code>.
		//!
		//! \pre
		//!   - <code>isEmpty()</code> returns <code>false</code>.
		T getFront() const;

		//! \brief Removes the first element from this <code>%QueueList</code>.
		//!
		//! \pre
		//!   - <code>isEmpty()</code> returns <code>false</code>.
		//! \post
		//!   - <code>contains()</code> will return <code>false</code> if the removed element
		//!     is passed in.
		void dequeue();

		//! \brief Removes all elements from this <code>%QueueList</code>.
		//!
		//! \post
		//!   - <code>isEmpty()</code> will return <code>true</code>.
		void removeAll();

		//! \brief Returns <code>true</code> if this <code>%QueueList</code>
		//! possesses the specified element, <code>false</code> otherwise.
		bool contains(T element) const;

		//! \brief Finds the first occurrence of the specified element and
		//! removes it from the <code>%QueueList</code>.
		//!
		//! \pre
		//!   - <code>isEmpty()</code> returns <code>false</code>.
		void remove(T element);
	};

	template <typename T>
	unsigned int QueueList<T>::Node::createdNodeCount = 0;

	template <typename T>
	unsigned int QueueList<T>::Node::destroyedNodeCount = 0;

	template <typename T>
	QueueList<T>::Node::Node(T element) : data(element), next(0)
	{
		++createdNodeCount;
	}

	template <typename T>
	QueueList<T>::Node::~Node()
	{
		++destroyedNodeCount;
	}

	template <typename T>
	unsigned int QueueList<T>::getCreatedNodeCount()
	{
		return QueueList<T>::Node::getCreatedNodeCount();
	}

	template <typename T>
	unsigned int QueueList<T>::getDestroyedNodeCount()
	{
		return QueueList<T>::Node::getDestroyedNodeCount();
	}

	template <typename T>
	unsigned int QueueList<T>::Node::getCreatedNodeCount()
	{
		return createdNodeCount;
	}

	template <typename T>
	unsigned int QueueList<T>::Node::getDestroyedNodeCount()
	{
		return destroyedNodeCount;
	}

	template <typename T>
	QueueList<T>::Iterator::Iterator(Node const* node) : currentNode(node)
	{
	}

	template <typename T>
	QueueList<T>::Iterator::Iterator()
	{
	}

	template <typename T>
	typename QueueList<T>::Iterator QueueList<T>::Iterator::operator++(int)
	{
		Iterator itr(*this);
		++(*this);
		return itr;
	}

	template <typename T>
	typename QueueList<T>::Iterator QueueList<T>::begin() const
	{
		return Iterator(front);
	}

	template <typename T>
	typename QueueList<T>::Iterator QueueList<T>::end() const
	{
		return Iterator(0);
	}
}}  // namespace fullsail_ai::fundamentals

#include "QueueList_TODO.h"

#endif  // _FULLSAIL_AI_FUNDAMENTALS_QUEUELIST_H_

