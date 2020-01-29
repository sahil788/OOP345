#ifndef W1_CSTRING_H__
#define W1_CSTRING_H__

#include<iostream>

using namespace std;

namespace w1
{
	void strncpy(char* d, const char* s, int size)     // Manually written strncpyfunction
	{
		for (int i = 0; i < size; i++)
		{
			d[i] = s[i];         // coping s into d...
		}
		d[size] = '\0';
	}

	const int MAX = 3;

	class CString
	{
		char str[MAX + 1];   // + 1 for null character...

	public:

		CString(const char* p)         // constructor with one argument...
		{
			strncpy(str, p, MAX);
			str[MAX] = '\0';
		}
		void display(ostream& ostr)     // displaying the the value in str...
		{
			ostr << str;
		}
	};

	ostream& operator<<(ostream& ostr, CString& cs)
	{
		static int count = 0;
		cout << count << ": ";
		cs.display(ostr);
		cout << endl;
		count++;
		return ostr;
	}
}

#endif