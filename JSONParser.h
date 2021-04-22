#ifndef JSONPARSER_H
#define JSONPARSER_H
#include "gitfiles/include/cpr/cpr.h"

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
			int size = 0;
		};
		struct node
		{
			pair *data;
			node *next;
			node *previous;
		};
		node *HEAD = NULL;
		//functions
		JSONParser();
		~JSONParser();
		void parseResponse(cpr::Response, node *);
		void printList(node *);

	private:
		node *insertNewNode(node **);
		void addToNode(node *, void *, void *);
		void increaseSize(node *);
		void initArray(node **);
		int size = 1;
	};
}
#endif //JSONPARSER_H