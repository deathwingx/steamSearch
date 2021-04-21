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
	result.pop_back();
	string key, value, temp;
	bool openQuotes = false;
	bool keyFound = false;
	bool bracketOpen = false;
	bool nonInfo = true;
	int quotes = 0;
	for (int x = 1; x < result.length(); x++)
	{
		if (result[x] != '[' && nonInfo == true)
			continue;
		else if (result[x]=='[' && nonInfo==true)
			nonInfo = false;
		else if (result[x] != '[' && nonInfo == false)
		{
			if (result[x] == '{')
			{
				bracketOpen = true;
			}
			else if (result[x] == '}')
			{
				bracketOpen = false;
				//insertNode here
			}
			if (result[x] == '\"')
			{
				x += 1;
				if (quotes == 0)
				{
					temp += result[x];
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
					}
					else if (keyFound == false)
					{
						key = temp;
						temp = "";
						cout << key << endl;
						cout << temp << endl;
						//addtoNode here
					}
				}
				if (bracketOpen==true && openQuotes==true)
			}
		}
	}
}

//insert new node into linked list
void JSONParser::insertNewNode(node **ref, void *data, void *dataTwo)
{
	string *key = static_cast<string *>(data);
	string *value = static_cast<string *>(dataTwo);
	struct node *newNode = new node;
	struct node *end = HEAD;
	newNode->next = NULL;
	newNode->data->key = key;
	newNode->data->value = value;
	if (HEAD == NULL)
	{
		HEAD = newNode;
		return;
	}
	while (end->next != NULL)
		end = end->next;
	end->next = newNode;
	newNode->previous = end;
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