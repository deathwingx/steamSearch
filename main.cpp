#include "steamSearch.h"
#include "JSONParser.h"
#include <dlfcn.h>
#include <iostream>
#include "cpr/cpr.h"

#define WEBAPI_KEY "743F1162E2E66B718D5C10B2CD9FF01B"
#define STEAMID "76561198081634808"

using namespace std;

int menu()
{
	int ans;
	cout << "1. Search for User" << endl;
	cout << "2. Search For Game" << endl;
	cout << "3. Search for Friend" << endl;
	cout << "4. See Time Played" << endl;
	cout << "5. See Library" << endl;
	cout << "6. Show Profile" << endl;
	cout << "7. Quit" << endl;
	cout << "What is your answer: ";
	cin >> ans;
	return ans;
}

void action(int ans, steamSearch &searchsteam)
{
	switch (ans)
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		searchsteam.showProfile();
	case 7:
		exit(0);
	default:
		break;
	}
}

int main()
{
	steamSearch search;
	cpr::Parameters param = cpr::Parameters{{"key", WEBAPI_KEY}, {"steamid", STEAMID}};
	cpr::Response res = cpr::Get(cpr::Url{"https://api.steampowered.com/IPlayerService/GetRecentlyPlayedGames/v1/"}, param);
	JSONParser jsp;
	jsp.parseResponse(res, jsp.HEAD);
	int answer = -1;
	while (answer != 7)
	{
		answer = menu();
		action(answer, search);
	}
	return 0;
}