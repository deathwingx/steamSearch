#ifndef JSONPARSER_H
#define JSONPARSER_H
#include "cpr/include/cpr/cpr.h"

extern "C"
{
	class JSONParser
	{
	public:
		//variables
		struct pair
		{
			void *key;
			void *value;
		};
		struct node
		{
			pair *data;
			node *next;
			int size = 0;
		};
		node *HEAD = NULL;
		//functions
		JSONParser();
		~JSONParser();
		void parseResponse(cpr::Response);
		void printList(node *);
		//menu items
		int menu();
		bool checkInput(void *);
		void action(int);

	private:
		node *insertNewNode();
		void addToNode(node *, void *, void *, int);
		void *increaseKeySize(void *, int);
		void *increaseValueSize(void *, int);

		
	};
}
#endif //JSONPARSER_H