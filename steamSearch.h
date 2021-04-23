#ifndef STEAMSEARCH_H
#define STEAMSEARCH_H
#include "cpr/include/cpr/cpr.h"
#include "JSONParser.h"

extern "C"
{
	class steamSearch
	{
	public:
		//functions
		steamSearch();
		~steamSearch();
		void seeLibrary();
		void showProfile();
		void recentlyPlayed();
		void seeFriendsList();
		
		
		//variables
		JSONParser JSP;
	};
}
#endif //STEAMSEARCH_H