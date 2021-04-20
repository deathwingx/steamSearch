#include "cpr/cpr.h"

using namespace std;

class JSONParser
{
public:
	struct node
	{
		string data[2];
		node *next;
		node *previous;
	};
	//functions
	JSONParser();
	~JSONParser();
	void parseResponse(cpr::Response, node *);
	//variables
	void push(node **, string);
	node HEAD;
};