#include <iostream>
#include "cpr/cpr.h"
#include "JSONParser.h"

using namespace std;
/*
*************************************
*************************************
DONT FORGET TO REACST BEFORE PRINTING
*************************************
*************************************
*/
//parse the http respone
void JSONParser::parseResponse(cpr::Response res, node *head_ref)
{
}

//insert new node into linked list
void JSONParser::insertNewNode(void *data, void *dataTwo)
{
	//RECAST VOID* TO STRING FIRST
	string *strrecast = static_cast<string *>(data);
	string *strrecastTwo = static_cast<string *>(dataTwo);
	node *newNode = new node;
	node *last = HEAD;
	newNode->data[0]->key = strrecast;
	newNode->data[0]->value = strrecastTwo;
	newNode->used += 1;
	newNode->next = NULL;
	if (HEAD == NULL)
	{
		newNode->previous = NULL;
		HEAD = newNode;
		return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = newNode;
	newNode->previous = last;
}

void JSONParser::addToNode(node *current, void *data, void *dataTwo)
{
	//check used first before adding
}

void JSONParser::increaseSize(node *current)
{
	//need help here
	int newSize = current->size + 5;
	pair *newPair = (pair *)malloc((newSize) * sizeof(pair));
	if (newPair == NULL)
		cout << "failed to allocate memory" << endl;
	else
	{
		for (int x = 0; x < current->size; x++)
			//current->data=newPair;
		current->size += 5;
	}
	return;
}

void JSONParser::printList(node *head_ref)
{
}