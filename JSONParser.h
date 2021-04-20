#ifndef JSONPARSER_H
#define JSONPARSER_H
#include "cpr/cpr.h"

extern "C"
{
	class JSONParser
	{
	public:
		struct pair
		{
			void *key;
			void *value;
		};
		struct node
		{
			pair *data[5];
			int size = 5;
			int used = 0;
			node *next;
			node *previous;
		};
		//functions
		void parseResponse(cpr::Response, node *);
		void printList(node *);
		//variables
		node *HEAD = NULL;

	private:
		void insertNewNode(void *, void *);
		void addToNode(node *, void *, void *);
		void increaseSize(node *);
	};
}
#endif //JSONPARSER_H