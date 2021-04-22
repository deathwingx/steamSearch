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
		void parseResponse(cpr::Response);
		void printList(node *);

	private:
		node *insertNewNode();
		void addToNode(node *, void *, void *, int);
	};
}
#endif //JSONPARSER_H