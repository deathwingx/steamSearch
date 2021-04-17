#include "steamSearch.h"
#include "steam/steam_api.h"
#include <dlfcn.h>
#include <iostream>

using namespace std;

void searchFriend(char const *friendName)
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

void searchGame(char const *gameName)
{
}