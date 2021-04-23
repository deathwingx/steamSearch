#include "steamSearch.h"
#include "JSONParser.h"
#include <dlfcn.h>
#include <iostream>
#include "cpr/include/cpr/cpr.h"
#include <string>

#define WEBAPI_KEY "743F1162E2E66B718D5C10B2CD9FF01B"
#define STEAMID "76561198081634808"

using namespace std;

int main()
{
	steamSearch search;
	search.JSP.menu();
	return 0;
}