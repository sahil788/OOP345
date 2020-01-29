
#ifndef W1_PROCESS_H__
#define W1_PROCESS_H__

using namespace std;

namespace w1
{
	void process(char* p)
	{
		CString cs(p); //called the one argument constructor and saved that argument in member variable of the class. 
		cout << cs;    // operator written to dipaly the str in a proper format....
	}
}
#endif