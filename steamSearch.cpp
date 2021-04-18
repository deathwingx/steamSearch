#include "steamSearch.h"
#include "steam/steam_api.h"
#include <dlfcn.h>
#include <iostream>

using namespace std;
//initialize steam library and default variables
steamSearch::steamSearch()
{
	void *handle;
	handle = dlopen("libsteam_api.so", RTLD_LAZY);
	AppId_t appID = 480;
	if (SteamAPI_RestartAppIfNecessary(appID)) // Replace with your App ID
	{
		cout << "Restart" << endl;
	}

	if (!SteamAPI_Init())
	{
		printf("Fatal Error - Steam must be running to play this game (SteamAPI_Init() failed).\n");
		exit(1);
	}
	friendList = nullptr;
	userName = SteamFriends()->GetPersonaName();
	}

steamSearch::~steamSearch()
{
}

//search users friend list
void steamSearch::searchFriend(char const *friendName)
{
		int nFriends = SteamFriends()->GetFriendCount(k_EFriendFlagImmediate);
	if (nFriends == -1)
	{
		printf("GetFriendCount returned -1, the current user is not logged in.\n");
		// We always recommend resetting to 0 just in case you were to do something like allocate
		// an array with this value, or loop over it in a way that doesn't take into the -1 into account.
		nFriends = 0;
	}

	for (int i = 0; i < nFriends; ++i)
	{
		CSteamID friendSteamID = SteamFriends()->GetFriendByIndex(i, k_EFriendFlagImmediate);
		const char *friendName = SteamFriends()->GetFriendPersonaName(friendSteamID);
		printf("Friend %d: %lld - %s\n", i, friendSteamID.ConvertToUint64(), friendName);
	}
}

//search steam for Username
void steamSearch::searchUser(char const *userName)
{
}

//search steam for game by name
void steamSearch::searchGame(char const *gameName)
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