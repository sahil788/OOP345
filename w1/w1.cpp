// Sahil Lapsiwala
//132584160
#include<iostream>
#include"CString.h"
#include"process.h"

using namespace std;
using namespace w1;

int main(int argc, char* argv[])
{
	if (argc == 1)     // 1 because there is one default argument... 
	{
		cout << "Command Line : ";
		for (int i = 0; i < argc; i++)
		{
			cout << argv[i] << " ";
		}
		cout << endl;
		cout << "Insufficient number of arguments (min 1)" << endl;
	}
	else
	{
		cout << "Command Line : ";
		for (int i = 0; i < argc; i++)
		{
			cout << argv[i] << " ";
		}
		cout << endl;

		cout << "Maximum number of characters stored : " << MAX << endl;

		for (int i = 1; i < argc; i++)
			process(argv[i]);   
	}
	return 0;
}