#ifndef STEAMSEARCH_H
#define STEAMSEARCH_H

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

	private:
		//variables
		char const *friendList;
		char const *userName;
	};
}
#endif //STEAMSEARCH_H