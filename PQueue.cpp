/*
 * LaQueue
 * 
 * 
 * This is part of a series of labs for the Liberal Arts and Science Academy.
 * The series of labs provides a mockup of an POSIX Operating System
 * referred to as LA(SA)nix or LAnix.
 *  
 * (c) copyright 2018, James Shockey - all rights reserved
 * 
 * */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "PQueue.h"

void PQueue::push(void *item, int priority)
{
	node *tmp = new node();
	tmp -> data = item;
	tmp -> priority = priority;
	if (front == NULL) {
		tmp -> link = front;
		front = tmp;
	}
	else {
		node *current = front;
		while (current != NULL && priority < current->priority) {
			current = current->link;
		}
		tmp -> link = current;
		current = tmp;
	}
}

void* PQueue::top()
{
	if (front == NULL) {
		return NULL;
	}
	else {
		return front->data; 
	}
}

void* PQueue::pop()
{
	if (front == NULL) {
		return NULL;
	}
	else {
		return front->data; 
		node *tmp = front;
		front = front->link;
		delete(tmp);
	}
}

void PQueue::display()
{

	node *ptr = front;
	while (ptr != NULL)
	{
		std::cout<<ptr->priority<<" "<<(char*)ptr->data<<std::endl;
		ptr = ptr->link;
	}
	std::cout<<"\n";
}
	