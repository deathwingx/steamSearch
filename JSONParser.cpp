#include <iostream>
#include "cpr/include/cpr/cpr.h"
#include "JSONParser.h"
#include "steamSearch.h"
#include <string>

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
	return valuePtr;
}
//parse the http respone
void JSONParser::parseResponse(cpr::Response res)
{
	string result = static_cast<string>(res.text);
	node *current = HEAD;
	static int size = 0, time = 0;
	string temp;
	string *keyPtr, *valuePtr;
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
				valuePtr = (string *)increaseValueSize(valuePtr, size);
				*(valuePtr + (size - 1)) = temp;
				addToNode(current, keyPtr, valuePtr, size);
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
				current->size = size;
				valuePtr = (string *)increaseValueSize(valuePtr, size);
				*(valuePtr + (size - 1)) = temp;
				temp = "";
				keyFound = false;
				quotes = 0;
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
						current->size = size;
						valuePtr = (string *)increaseValueSize(valuePtr, size);
						int a = 1;
						*(valuePtr + (size - 1)) = temp;
						temp = "";
						keyFound = false;
						continue;
					}
					else if (keyFound == false)
					{
						size += 1;
						keyPtr = (string *)increaseKeySize(keyPtr, size);
						*(keyPtr + (size - 1)) = temp;
						temp = "";
						keyFound = true;
					}
				}
			}

			if (bracketOpen == true && openQuotes == true)
				temp += result[x];
		}
	}
	printList(HEAD);
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
	pair *newData = (pair *)malloc(sizeof(2 * sizeof(string[size])));
	string *newKey = static_cast<string *>(k);
	string *newValue = static_cast<string *>(v);
	string *keyPtr = new string[size];
	string *valuePtr = new string[size];
	if (size > 1)
	{
		for (int x = 0; x < size; x++)
		{
			*(keyPtr + x) = *(newKey + x);
			*(valuePtr + x) = *(newValue + x);
		}
	}
	else
	{
		keyPtr = newKey;
		valuePtr = newValue;
	}
	current->data = newData;
	current->data->key = keyPtr;
	current->data->value = valuePtr;
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
	cout << endl;
	if (head_ref->next == NULL)
	{
		for (int x = 0; x < head_ref->size; x++)
		{
			string *k = static_cast<string *>(head_ref->data->key);
			string key = *(k + x);
			string *v = static_cast<string *>(head_ref->data->value);
			string value = *(v + x);
			cout << key << ": " << value << endl;
		}
		cout << endl;
		menu();
		return;
	}
	while (head_ref->next != NULL)
	{

		for (int x = 0; x < head_ref->size; x++)
		{
			string *k = static_cast<string *>(head_ref->data->key);
			string key = *(k + x);
			string *v = static_cast<string *>(head_ref->data->value);
			string value = *(v + x);
			cout << key << ": " << value << "\t";
		}
		//cout << "\n\nnext node" << endl;
		cout << endl;
		head_ref = head_ref->next;
	}
	for (int x = 0; x <= head_ref->size; x++)
	{
		string *k = static_cast<string *>(head_ref->data->key);
		string key = *(k + x);
		string *v = static_cast<string *>(head_ref->data->value);
		string value = *(v + x);
		cout << key << ": " << value << "\t";
	}
	cout << endl;
	menu();
}

int JSONParser::menu()
{
	string ans;
	int numans;
	while (numans != 5)
	{
		cout << "1. Show Profile" << endl;
		cout << "2. See Library" << endl;
		cout << "3. See Friend List" << endl;
		cout << "4. See Recently Played" << endl;
		cout << "5. Quit" << endl;
		cout << "What is your answer: ";
		cin >> ans;
		bool isaNUM = checkInput(&ans);
		if (isaNUM == true)
			action(stoi(ans));
		else
		{
			cout << "\nInvalid Input, Try Again.\n\n";
		}
	}
	return 5;
}

bool JSONParser::checkInput(void *i)
{
	string *in = static_cast<string *>(i);
	string input = *in;
	bool isANum = false;
	if (isdigit(input[0]))
		isANum = true;
	return isANum;
}

void JSONParser::action(int ans)
{
	steamSearch searchsteam;
	switch (ans)
	{
	case 1:
		searchsteam.showProfile();
	case 2:
		searchsteam.seeLibrary();
	case 3:
		searchsteam.seeFriendsList();
	case 4:
		searchsteam.recentlyPlayed();
	case 5:
		exit(0);
	default:
		break;
	}
}