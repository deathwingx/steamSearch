#include <iostream>
#include "cpr/cpr.h"
#include "JSONParser.h"
#include <string>

using namespace std;

JSONParser::JSONParser()
{
	//initArray(&HEAD);
}

JSONParser::~JSONParser()
{
}
//parse the http respone
void JSONParser::parseResponse(cpr::Response res, node *head_ref)
{
	string result = static_cast<string>(res.text);
	string key, value;
	bool openQuotes = false;
	bool keyFound = false;
	bool bracketOpen = false;
	int quotes = 0;
	for (int x = 1; x < result.length(); x++)
	{
		string temp;
		while (openQuotes == false)
		{
			if (result[x] == '{')
			{
				bracketOpen = true;
				//maybe add node here
			}
			else if (result[x] == '}')
			{
				bracketOpen = false;
				//maybe add node here
			}
			if (result[x] == '\"')
			{
				x += 1;
				if (quotes == 0)
				{
					quotes += 1;
					openQuotes = true;
				}
			}
		}
	}
}

//insert new node into linked list
void JSONParser::insertNewNode(node **ref, void *data, void *dataTwo)
{
	struct node *newNode = new node;
	struct node *end = HEAD;
	newNode->next = NULL;
	newNode->data->key = data;
	newNode->data->value = dataTwo;
	if (HEAD == NULL)
	{
		HEAD = newNode;
		return;
	}
	while (end->next != NULL)
		end = end->next;
	end->next = newNode;
	return;
}

void JSONParser::addToNode(node *current, void *data, void *dataTwo)
{
	//get data size to allocate memory first
}

void JSONParser::increaseSize(node *current)
{
	/* 	//need help here
	int newSize = current->size + 5;
	pair *newPair = (pair *)malloc((newSize) * sizeof(pair *));
	if (newPair == NULL)
		cout << "failed to allocate memory" << endl;
	else
	{
		for (int x = 0; x < current->size; x++)
			//current->data=newPair;
			current->size += 5;
	}
	return; */
}
/*
*************************************
*************************************
DONT FORGET TO REACST BEFORE PRINTING
*************************************
*************************************
*/
void JSONParser::printList(node *head_ref)
{
	if (head_ref->next == NULL)
	{
		string *k = static_cast<string *>(head_ref->data->key);
		string *v = static_cast<string *>(head_ref->data->value);
		string key = *k;
		string value = *v;
		cout << "key: " << key << endl;
		cout << "value: " << value << endl;
	}
	while (head_ref->next != NULL)
	{
		string *k = static_cast<string *>(head_ref->data->key);
		string *v = static_cast<string *>(head_ref->data->value);
		string key = *k;
		string value = *v;
		cout << "key: " << key << endl;
		cout << "value: " << value << endl;
		head_ref = head_ref->next;
	}
}