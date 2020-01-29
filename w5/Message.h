#pragma once
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

namespace w5 {
    class Message
    {
    private:
        string user, tweet, reply;
    public:
        Message(){

        }
        Message(std::ifstream& in, char c) {
            string templine;
            getline(in, templine, c);
            auto cr = templine.find("\r");
            if (cr != string::npos) {
                templine.erase(cr);
            }
            size_t index = 0;
            
            while (index < templine.size() && templine[index] != ' ') {
                user += templine[index];
                index++;
            }
            index++; //skips one character
            if (index < templine.size() && templine[index] == '@') {
                index++; //skips @
                while (index < templine.size() && templine[index] != ' ') {
                    reply += templine[index];
                    index++;
                }
                
            }
            index++;//skips the space
          while(index < templine.size()) {
                tweet += templine[index];
                index++;
            }
        }
        bool empty() const{
            return tweet.empty();
        }
        void display(std::ostream&ostr) const {
            if (!empty()) {
                ostr << "Message\n";
                ostr << "  User  : " << user << "\n";
                if (!reply.empty()) {
                    ostr << "  Reply : " << reply << "\n";
                }
                ostr << "  Tweet : " << tweet << "\n";
            }
        }
        

   

    };

    

}