#include "steamSearch.h"
#include <dlfcn.h>
#include <iostream>
#include <stdlib.h>

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

//JSONParser definitions

JSONParser::JSONParser()
{
}

JSONParser::~JSONParser()
{
}

char *JSONParser::parseResponse(cpr::Response respone, JSONParser::node *head)
{
}

void JSONParser::push(node **head_ref, void *data)
{
}