#ifndef STEAMSEARCH_H
#define STEAMSEARCH_H
//#include "steam/steam_api.h"

extern "C"
{
	class steamSearch
	{
	public:
		//functions
		steamSearch();
		~steamSearch();
		void searchFriend(char const *);
		void searchUser(char const *);
		void searchGame(char const *);
		void timePlayed();
		void seeLibrary();
		void showProfile();
		void showFriendsProfile(char const *);
		//variables

	private:
		//variables
		char const *friendList;
		char const *userName;
		int userLevel;
		int numOfGames;
		int friendCount;
	};
}
#endif //STEAMSEARCH_H