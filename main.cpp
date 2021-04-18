#include "steamSearch.h"
#include <dlfcn.h>
#include <iostream>

using namespace std;

int menu()
{
	int ans;
	cout << "1. Search for User" << endl;
	cout << "2. Search For Game" << endl;
	cout << "3. Search for Friend" << endl;
	cout << "4. See Time Played" << endl;
	cout << "5. See Library" << endl;
	cout << "6. Quit" << endl;
	cout << "What is your answer: ";
	cin >> ans;
	return ans;
}

void action(int ans)
{
	switch (ans)
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		exit(0);
	default:
		break;
	}
}

int main()
{
	steamSearch search;
	int answer;
	action(menu());
	return 0;
}