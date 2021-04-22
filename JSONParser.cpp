#include <iostream>
#include "gitfiles/include/cpr/cpr.h"
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
				cout << size << endl;
				//addToNode(current, &key, &value);
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
						size += 1;
						cout << size << endl;
						//cout << value << endl;
						keyFound = false;
						//addToNode(current, &key, &value);
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
	while (last->next!=NULL)
		last = last->next;
	last->next = newNode;
	return newNode;
}

void JSONParser::addToNode(node *current, void *key, void *value, int size)
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