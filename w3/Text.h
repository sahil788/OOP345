#pragma once
#include<string>
using namespace std;
namespace w3 {
    class Text
    {
        string file_name;
        string * text = nullptr;
        size_t m_size = 0;

    public:
        Text();
        Text(const char* fname);
        ~Text();
        Text(Text& src);//copy constructor
        Text& operator=(Text& rhs);//copy assignment ooperator
        Text(Text&& src); //move constructor
        Text& operator=(Text&& rhs);//move operator
        size_t size() const {
            return m_size;
        }
        void display() {
            cout << "in display" << endl;
            for (int i = 0; i < size(); i++) {
                cout << text[i] << endl;
            }
        }



    };
}