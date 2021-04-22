#include <iostream>
#include "cpr/include/cpr/cpr.h"
#include "JSONParser.h"
#include <cstring>

using namespace std;

JSONParser::JSONParser()
{
}

JSONParser::~JSONParser()
{
}

//return pointer to new array with increased size
void *JSONParser::increaseKeySize(void *k, int size)
{
	string *newKey = static_cast<string *>(k);
	string *keyPtr = new string[size + 1];
	if (size > 1)
	{
		for (int x = 0; x < size; x++)
			*(keyPtr + x) = *(newKey + x);
	}
	//for (int x = 0; x < size-1; x++)
	//cout << *(strPtr + x) << endl;
	return keyPtr;
}

void *JSONParser::increaseValueSize(void *v, int size)
{
	string *valuePtr = new string[size + 1];
	string *newValue = static_cast<string *>(v);
	if (size > 1)
	{
		for (int x = 0; x < size; x++)
			*(valuePtr + x) = *(newValue + x);
	}
	for (int x = 0; x < size - 1; x++)
		cout << *(valuePtr + x) << endl;
	return valuePtr;
}
//parse the http respone
void JSONParser::parseResponse(cpr::Response res)
{
	string result = static_cast<string>(res.text);
	node *current = HEAD;
	static int size = 0;
	result.pop_back();
	string temp;
	string *keyPtr, *valuePtr;
	//keyPtr = key;
	//valuePtr = value;
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
				//cout << value << endl;
				//size += 1;
				current->size = size;
				valuePtr = (string *)increaseValueSize(valuePtr, size);
				*(valuePtr+(size-1)) = temp;
				temp = "";
				//cout << size << endl;
				//addToNode(current, keyPtr, valuePtr, size);
				keyFound = false;
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

						//size += 1;
						current->size = size;
						valuePtr = (string *)increaseValueSize(valuePtr, size);
						int a = 1;
						*(valuePtr+(size-1)) = temp;
						//memcpy(valuePtr[size], &temp, temp.size() + 1);
						temp = "";
						//cout << size << endl;
						//cout << value << endl;
						keyFound = false;
						//addToNode(current, keyPtr, valuePtr, size);
						//addtoNode here
						continue;
					}
					else if (keyFound == false)
					{
						size += 1;
						keyPtr = (string *)increaseKeySize(keyPtr, size);
						*(keyPtr + (size - 1)) = temp;
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