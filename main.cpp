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

bool checkForError(cpr::Response error)
{
	int code = error.status_code;
	switch (code)
	{
	case 200:
		return false;
	case 400:
	{
		cout << "Bad Request" << endl;
		return true;
	}
	case 401:
	{
		cout << "Unauthorized" << endl;
		return true;
	}
	case 403:
	{
		cout << "Forbidden" << endl;
		return true;
	}
	case 404:
	{
		cout << "Not Found" << endl;
		return true;
	}
	case 429:
	{
		cout << "Too Many Request" << endl;
		return true;
	}
	case 500:
	{
		cout << "Internal Server Error" << endl;
		return true;
	}
	case 503:
	{
		cout << "Service Unavailable" << endl;
		return true;
	}
	}
	return true;
}

int main()
{
	steamSearch search;
	cpr::Parameters param = cpr::Parameters{{"key", WEBAPI_KEY}, {"steamid", STEAMID}};
	cpr::Response res = cpr::Get(cpr::Url{"https://api.steampowered.com/ISteamUser/GetFriendList/v1/"}, param);
	JSONParser jsp;
	bool error = checkForError(res);
	if (error==true)
		exit(1);
	jsp.parseResponse(res, jsp.HEAD);
	//jsp.printList(jsp.HEAD);
	int answer = -1;
	//cout << res.text << endl;
	while (answer != 7)
	{
		answer = menu();
		action(answer, search);
	}
	return 0;
}