#ifndef STEAMSEARCH_H
#define STEAMSEARCH_H
#include "cpr/cpr.h"

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

	class JSONParser
	{
	public:
		struct node
		{
			void *data[2];
			node *next;
			node *previous;
		};
		//functions
		JSONParser();
		~JSONParser();
		char *parseResponse(cpr::Response, node *);
		//variables
		void push(node **, void *);
		node HEAD;
	};
}
#endif //STEAMSEARCH_H