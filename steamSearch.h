#ifndef STEAMSEARCH_H
#define STEAMSEARCH_H
#include "gitfiles/include/cpr/cpr.h"
#include "JSONParser.h"

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
		JSONParser JSP;

	private:
		//variables
	};
}
#endif //STEAMSEARCH_H