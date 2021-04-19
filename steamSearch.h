#ifndef STEAMSEARCH_H
#define STEAMSEARCH_H
#include "cpr/cpr.h"
#include <string.h>

extern "C"
{
	class steamSearch
	{
	public:
		//functions
		steamSearch();
		~steamSearch();
		void searchFriend(char *);
		void searchUser(char *);
		void searchGame(char *);
		void timePlayed();
		void seeLibrary();
		void showProfile();
		void showFriendsProfile(char *);
		//variables

	private:
		//variables
		char const *friendList;
		char const *userName;
		int userLevel;
		int numOfGames;
		int friendCount;
	};

	class JSONParser
	{
	public:
		//functions
		JSONParser();
		~JSONParser();
		char *convertToVec(cpr::Response);
		//variables
		char *vectorResult[1][1];

	private:
		//variables
	};
}
#endif //STEAMSEARCH_H