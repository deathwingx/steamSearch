#ifndef STEAMSEARCH_H
#define STEAMSEARCH_H
#include "cpr/include/cpr/cpr.h"

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
	};
}
#endif //STEAMSEARCH_H