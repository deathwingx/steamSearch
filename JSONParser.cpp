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
	node *current = head_ref;
	result.pop_back();
	string key, value, temp;
	string *k, *v;
	bool openQuotes = false;
	bool keyFound = false;
	bool bracketOpen = false;
	bool nonInfo = true;
	int quotes = 0;
	for (int x = 1; x < result.length(); x++)
	{
		if (result[x] != '[' && nonInfo == true)
			continue;
		else if (result[x] == '[' && nonInfo == true)
			nonInfo = false;
		else if (result[x] != '[' && nonInfo == false)
		{
			if (result[x] == '{')
			{
				bracketOpen = true;
				current = insertNewNode(&HEAD);
				continue;
			}
			else if (result[x] == '}')
			{
				bracketOpen = false;
			}
			else if (result[x] == ':')
			{
				if (result[x + 1] != '\"')
				{
					openQuotes = true;
					quotes += 1;
					x += 1;
				}
			}
			else if (result[x] == ',' && keyFound == true)
			{
				value = temp;
				temp = "";
				cout << value << endl;
				addToNode(current, &key, &value);
				keyFound = false;
				value = "";
				key = "";
				quotes = 0;
				
				//addtoNode here
				continue;
			}
			if (result[x] == '\"')
			{
				if (quotes == 0)
				{
					x += 1;
					quotes += 1;
					openQuotes = true;
				}
				else if (quotes == 1)
				{
					openQuotes = false;
					quotes = 0;
					if (keyFound == true)
					{
						value = temp;
						temp = "";
						cout << value << endl;
						keyFound = false;
						addToNode(current, &key, &value);
						value = "";
						key = "";
						//addtoNode here
						continue;
					}
					else if (keyFound == false)
					{
						key = temp;
						temp = "";
						cout << key << "   ";
						keyFound = true;
					}
				}
			}

			if (bracketOpen == true && openQuotes == true)
				temp += result[x];
		}
	}
}

//insert new node into linked list
JSONParser::node *JSONParser::insertNewNode(node **ref)
{
	size += 1;
	cout << size << endl;
	string *key, *value;
	struct node *newNode = (node*)malloc(sizeof(node));
	struct node *end = HEAD;
	//key = (string *)malloc(size * sizeof(string*));
	//value = (string *)malloc(size * sizeof(string*));
	newNode->next = NULL;
	//newNode->data->key = static_cast<void *>(key);
	//newNode->data->value = static_cast<void *>(value);
	if (HEAD == NULL)
	{
		HEAD = newNode;
		return HEAD;
	}
	node *temp = HEAD;
	temp = (node *)realloc(HEAD, size * sizeof(HEAD));
	HEAD = temp;
	end = HEAD;
	while (end->next != NULL)
		end = end->next;
	end->next = newNode;
	newNode->previous = end;
	return newNode;
}

void JSONParser::addToNode(node *current, void *key, void *value)
{
	current->data->size += 1;
	string *k, *v;
	k = (string *)malloc(size * sizeof(string *));
	v = (string *)malloc(size * sizeof(string *));
	current->data->key = k;
	current->data->value = v;
	current->data->key = key;
	current->data->value = value;
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