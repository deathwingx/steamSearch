#include <iostream>
#include <dlfcn.h>
#include "steamSearch.h"

using namespace std;

int main(int argc, char const *argv[])
{
	/* code */

	void *handle;
	void (*test)(void);
	char *error;
	handle = dlopen("./libsteamSearch.so", RTLD_LAZY);

	searchGame();
	searchUser();
	return 0;
}