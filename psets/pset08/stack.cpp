/*On my honor, I pledge that I have neither received nor provided improper assistance in
the completion of this assignment.
Signed:김영빈 Section: pset08 Student Number: 21600108 */


//  stack.cpp
//  Created by idebtor@gmail.com on December 12, 2018.
/*
* Description:	This program implements a stack using singly-linked list
* without a head structure and without sentinel nodes. It simply links
* node to node. The caller is responsible for maintaining the the first
* node (head) of the list. Most functions need the first node to work
* with the list and returns the first node of the list since it may be
* changed inside of the functions.
*/
#include <iomanip>
#include "stack.h"

// removes all the nodes from the list (which are destroyed),
// and leaving the container nullptr or its size to 0.
pNode clear(pNode p) {
	if (empty(p)) return nullptr;
	DPRINT(cout << "clear: ";);

	while(p != nullptr)
	{
		pNode copy = p;
		p = p->next;
		delete copy;
	}
	cout << "\n\tAll things are cleared.\n";
	return nullptr;
}

// returns the number of nodes in the list.
int size(pNode p) {
	if (empty(p)) return 0;
	int count = 1;
	while(p->next != nullptr)
	{
		p = p->next;
		count++;
	}
	return count;
}

// returns true if the list is empty or no nodes.
// To remove all the nodes of a list, see clear().
bool empty(pNode p) {
	return p == nullptr;
}

// inserts a new node with val at the beginning of the list.
// This effectively increases the list size by N.
pNode push(pNode hp, int val, int N) {
	DPRINT(cout << ">push val=" << val << " N="<< N << endl;);

	if(N == 1)
	{
		pNode temp = new Node{val,hp};
		hp = temp;
	}
	else
	{
		for(val; val < N; val++)
		{
			pNode temp = new Node{val,hp};
			hp = temp;
		}
	}
	DPRINT(cout << "<push size=" << size(hp) << endl;);
	return hp;
}

// removes the first node in the list and returns the new first node.
// This destroys the removed node, effectively reduces its size by N.
pNode pop(pNode hp, int N) {
	DPRINT(cout << ">pop size=" << size(hp) << " N="<< N << endl;);
	if (empty(hp)) return nullptr;
	int s_size = size(hp);
	if(s_size <  N)
		N = s_size;
	for(int i = 0; i < N; i++)
	{
		pNode copy = hp;
		hp = hp->next;
		delete copy;
	}

	DPRINT(cout << "<pop size=" << size(hp) << endl;);
	return hp;
}

// returns the first node in the list. This does not destroy the node.
pNode top(pNode hp) {
	DPRINT(cout << ">top size=" << size(hp) << endl;);
	if (empty(hp)) return nullptr;

	return hp;
}

// shows the values of all the nodes in the list if all is true or
// the list size is less than or equal to pmax * 2. If there are more than
// (pmax * 2) nodes, then it shows only pmax number of nodes from
// the beginning and the end in the list.
void show(pNode hp, bool all, int pmax) {
	DPRINT(cout << "show(" << size(hp) << ")\n";);
	if (empty(hp)) {
		cout << "\n\tThe list is empty.\n";
		return;
	}
	int num = size(hp);
	if(num < pmax * 2 || all == true)
	{
		for(int i = 0; i < num; i++)
		{
			cout << " -> " << hp->item;
			hp = hp->next;

			if(((i + 1) % pmax) == 0)
				cout << endl;
		}
	}
	else
	{
		for(int i = 0; i < pmax; i++)
		{
			cout << " -> " << hp->item;
			hp = hp->next;
		}

		cout << endl << "...left out..." << endl;

		for(int j = 0; j < (num-(pmax*2)); j++)
			hp = hp->next;

		for(int i = 0; i < pmax; i++)
		{
			cout << " -> " << hp->item;
			hp = hp->next;
		}
	}
}
