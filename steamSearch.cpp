#include "steamSearch.h"
#include <dlfcn.h>
#include <iostream>
#include <stdlib.h>

#define WEBAPI_KEY "743F1162E2E66B718D5C10B2CD9FF01B"
#define STEAMID "76561198081634808"

using namespace std;
//initialize steam library and default variables
steamSearch::steamSearch()
{
}

steamSearch::~steamSearch()
{
}

//print out library
void steamSearch::seeLibrary()
{
	cpr::Parameters param = cpr::Parameters{{"key", WEBAPI_KEY}, {"steamid", STEAMID}, {"include_appinfo", "true"}};
	cpr::Response res = cpr::Get(cpr::Url{"https://api.steampowered.com/IPlayerService/GetOwnedGames/v1/"}, param);
	JSP.parseResponse(res);
	return;
}

void steamSearch::showProfile()
{
	cpr::Parameters param = cpr::Parameters{{"key", WEBAPI_KEY}, {"steamids", STEAMID}};
	cpr::Response res = cpr::Get(cpr::Url{"https://api.steampowered.com/ISteamUser/GetPlayerSummaries/v2/"}, param);
	//cout << res.text << endl;
	JSP.parseResponse(res);
	return;
}

void steamSearch::recentlyPlayed()
{
	cpr::Parameters param = cpr::Parameters{{"key", WEBAPI_KEY}, {"steamid", STEAMID}};
	cpr::Response res = cpr::Get(cpr::Url{"https://api.steampowered.com/IPlayerService/GetRecentlyPlayedGames/v1/"}, param);
	JSP.parseResponse(res);
	return;
}

void steamSearch::seeFriendsList()
{
	cpr::Parameters param = cpr::Parameters{{"key", WEBAPI_KEY}, {"steamid", STEAMID}};
	cpr::Response res = cpr::Get(cpr::Url{"https://api.steampowered.com/ISteamUser/GetFriendList/v1/"}, param);
	JSP.parseResponse(res);
	return;
}

