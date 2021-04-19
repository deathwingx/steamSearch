#include "steamSearch.h"
#include <dlfcn.h>
#include <iostream>

using namespace std;
//initialize steam library and default variables
steamSearch::steamSearch()
{
}

steamSearch::~steamSearch()
{
}

//search users friend list
void steamSearch::searchFriend(char *friendName)
{
}

//search steam for Username
void steamSearch::searchUser(char *userName)
{
}

//search steam for game by name
void steamSearch::searchGame(char *gameName)
{
}

//show time played for games in library
void steamSearch::timePlayed()
{
}

//print out library
void steamSearch::seeLibrary()
{
}

void steamSearch::showProfile()
{
}

void steamSearch::showFriendsProfile(char *friendUserName)
{
}

JSONParser::JSONParser()
{
}

JSONParser::~JSONParser()
{
}

char *JSONParser::convertToVec(cpr::Response respone)
{
	char *re;
	int size = strlen(respone.text);
	cout << size <<endl;
	return re;
}