// QueueList_Main.cpp - the entry point of the queue-list application
// Code by Cromwell D. Enage, December 2008
// Updated by Jeremiah Blanchard, January 2009
// Updated by Cromwell D. Enage, April 2009
#include <limits>
#include <string>
#include <cassert>
#include <iostream>
#include "QueueList/QueueList.h"

using namespace std;
using namespace fullsail_ai::fundamentals;

// Prototypes (allow implementation to follow main)
template <typename T, typename F>
void traverse(QueueList<T> const& q, F& dataFunction);

void printString(string& testString);
void printCString(char const* testString);

int main()
{
	// Get ready.
	QueueList<string&> alist;
	QueueList<char const*> qlist;

	unsigned int numOfStrings = 8;
	string testStrings[] = {
	    "alpha"
	  , "bravo"
	  , "charlie"
	  , "charlie" 
	  , "dog"
	  , "echo"
	  , "foxtrot"
	  , "golf"
	};
	string tempStr;

	// Test isEmpty function.
	assert(qlist.isEmpty() && alist.isEmpty());

	// Test enqueue.
	for (unsigned int index = 0; index < numOfStrings; ++index)
	{
		alist.enqueue(testStrings[index]);
		qlist.enqueue(testStrings[index].c_str());
		assert(qlist.getFront() == alist.getFront().c_str());
		cout << "\tqlist:";
		traverse(qlist, printCString);
		cout << endl;
	}

	// Test dequeue.
	for (;;)
	{
		cout << "Removing the front element:";
		printCString(qlist.getFront());
		qlist.dequeue();
		cout << endl << "\tqlist:";
		traverse(qlist, printCString);
		cout << endl;

		if (qlist.isEmpty())
		{
			cout << "qlist is empty." << endl;
			break;
		}
		else
		{
			alist.dequeue();
		}
	}

	// Test removal of only element.
	cout << "Removing the only element:";
	printCString(alist.getFront().c_str());
	alist.remove(testStrings[numOfStrings - 1]);
	cout << endl << "\talist:";
	traverse(alist, printString);
	cout << endl;

	// Test containment check when empty
	cout << "Testing search for: alpha";
	tempStr = "alpha";
	if (alist.contains(tempStr) == false)
	{
		cout << endl << "\talist:\n";
	}

	// Test enqueue after removal.
	for (unsigned int index = 1; index < numOfStrings; ++index)
	{
		alist.enqueue(testStrings[index]);
		qlist.enqueue(testStrings[index].c_str());
	}

	// Test unsuccessful search.
	cout << "Testing search and remove:";

	if (qlist.contains(testStrings[0].c_str()))
	{
		assert(alist.contains(testStrings[0]) && "alpha not found in alist");
		cout << " " << testStrings[0];
		qlist.remove(testStrings[0].c_str());
		alist.remove(testStrings[0]);
		alist.remove(testStrings[0]);
		cout << endl << "\tqlist:";
		traverse(qlist, printCString);
		cout << endl;
	}
	else
	{
		assert(!alist.contains(tempStr) && "alpha found in alist");
		cout << " ELEMENT NOT FOUND." << endl;
	}

	// Test removal of first element.
	cout << "Testing search and remove:";

	if (qlist.contains(testStrings[1].c_str()))
	{
		assert(alist.contains(testStrings[1]) && "bravo not found in alist");
		cout << " " << testStrings[1];
		qlist.remove(testStrings[1].c_str());
		alist.remove(testStrings[1]);
		alist.remove(testStrings[1]);
		cout << endl << "\tqlist:";
		traverse(qlist, printCString);
		cout << endl;
	}
	else
	{
		assert(!alist.contains(tempStr) && "bravo found in alist");
		cout << " ELEMENT NOT FOUND." << endl;
	}

	// Test removal of middle element.
	cout << "Testing search and remove:";

	if (qlist.contains(testStrings[4].c_str()))
	{
		assert(alist.contains(testStrings[4]) && "dog not found in alist");
		cout << " " << testStrings[4];
		qlist.remove(testStrings[4].c_str());
		alist.remove(testStrings[4]);
		alist.remove(testStrings[4]);
		cout << endl << "\tqlist:";
		traverse(qlist, printCString);
		cout << endl;
	}
	else
	{
		assert(!alist.contains(tempStr) && "dog found in alist");
		cout << " ELEMENT NOT FOUND." << endl;
	}

	// Test removal of last element.
	cout << "Testing search and remove:";

	if (qlist.contains(testStrings[7].c_str()))
	{
		assert(alist.contains(testStrings[7]) && "golf not found in alist");
		cout << " " << testStrings[7];
		qlist.remove(testStrings[7].c_str());
		alist.remove(testStrings[7]);
		alist.remove(testStrings[7]);
		cout << endl << "\tqlist:";
		traverse(qlist, printCString);
		cout << endl;
	}
	else
	{
		assert(!alist.contains(tempStr) && "golf found in alist");
		cout << " ELEMENT NOT FOUND." << endl;
	}

	// Test removal of all elements by method.
	cout << "Removing all elements from qlist...";
	qlist.removeAll();
	cout << endl << "\tqlist:";
	traverse(qlist, printCString);
	cout << endl;

	// Test destructor.
	qlist.enqueue("hotel");
	cout << "\tqlist:";
	traverse(qlist, printCString);
	qlist.enqueue("india");
	cout << endl << "\tqlist:";
	traverse(qlist, printCString);
	qlist.enqueue("juliet");
	cout << endl << "\tqlist:";
	traverse(qlist, printCString);
	cout << endl << "\talist:";
	traverse(alist, printString);
	cout << endl << endl;

	cout << "Press ENTER to continue..." << endl;
	while(cin.get() != '\n') {;}
	return 0;
}

template <typename T, typename F>
void traverse(QueueList<T> const& q, F& dataFunction)
{
	typename QueueList<T>::Iterator itr = q.begin();
	typename QueueList<T>::Iterator itr_end = q.end();

	if (itr != itr_end)
	{
		// Test iterator pre-increment operator return value.
		assert((&(++itr) == &itr) && "Your iterator\'s pre-increment operator is not returning the right object!");
	}

	for (itr = q.begin(); itr != itr_end; ++itr)
	{
		dataFunction(*itr);
	}
}

void printString(string& testString)
{
	cout << ' ' << testString;
}

void printCString(char const* testString)
{
	cout << ' ' << testString;
}

