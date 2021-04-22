#include <iostream>
#include "cpr/include/cpr/cpr.h"
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
void JSONParser::parseResponse(cpr::Response res)
{
	string result = static_cast<string>(res.text);
	node *current = HEAD;
	static int size = 0;
	result.pop_back();
	string key, value, temp;
	string *k, *v;
	*k = key;
	*v = value;
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
				current = insertNewNode();
				size = 0;
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
				//cout << value << endl;
				size += 1;
				current->size = size;
				//cout << size << endl;
				addToNode(current, &key, &value, size);
				keyFound = false;
				key = "";
				value = "";
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
						v = (string*)realloc(v, sizeof(string));
						value = temp;
						temp = "";
						size += 1;
						current->size = size;
						//cout << size << endl;
						//cout << value << endl;
						keyFound = false;
						addToNode(current, &key, &value, size);
						value = "";
						key = "";
						//addtoNode here
						continue;
					}
					else if (keyFound == false)
					{
						key = temp;
						temp = "";
						//cout << key << "   ";
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
JSONParser::node *JSONParser::insertNewNode()
{
	node *newNode = new node;
	node *last = HEAD;
	newNode->next = NULL;
	if (HEAD == NULL)
	{
		HEAD = newNode;
		return newNode;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = newNode;
	return newNode;
}

//add data to node
void JSONParser::addToNode(node *current, void *k, void *v, int size)
{
	string *newKey = (string *)malloc(sizeof(string *));
	newKey = static_cast<string *>(k);
	string strNewKey = *newKey;
	string *newValue = (string *)malloc(sizeof(string *));
	newValue = static_cast<string *>(v);
	string strNewValue = *newValue;
	current->data = (pair *)realloc(current->data, (size * 2) * sizeof(pair));
	(current->data[size - 1].key) = (string *)realloc(current->data, size * sizeof(string *));
	(current->data[size - 1].value) = (string *)realloc(current->data, size * sizeof(string *));
	(current->data[size - 1].key) = static_cast<string *>(&strNewKey);
	(current->data[size - 1].value) = static_cast<string *>(&strNewValue);
	int a = 1;
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

		for (int x = 0; x < head_ref->size; x++)
		{
			//string key = (head_ref->data + x)->key;
			//string value = (head_ref->data + x)->value;
			string *k = static_cast<string *>(head_ref->data->key);
			string key = *k;
			string *v = static_cast<string *>(head_ref->data->value);
			string value = *v;
			cout << "key: " << key << endl;
			cout << "value: " << value << endl;
		}
	}
	while (head_ref->next != NULL)
	{

		for (int x = 0; x < head_ref->size; x++)
		{
			//string key = (head_ref->data + x)->key;
			//string value = (head_ref->data + x)->value;
			string *k = static_cast<string *>(head_ref->data->key);
			string key = *k;
			string *v = static_cast<string *>(head_ref->data->value);
			string value = *v;
			cout << "key: " << key << endl;
			cout << "value: " << value << endl;
		}
		head_ref = head_ref->next;
	}
}