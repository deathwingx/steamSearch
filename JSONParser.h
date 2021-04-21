#ifndef JSONPARSER_H
#define JSONPARSER_H
#include "cpr/cpr.h"

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
			int size = 1;
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
		void insertNewNode(node **, void *, void *);
		void addToNode(node *, void *, void *);
		void increaseSize(node *);
		void initArray(node **);
	};
}
#endif //JSONPARSER_H