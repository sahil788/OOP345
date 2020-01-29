#pragma once
#include<iostream>
#include"Message.h"
#define notificationmax 10
using namespace std;
namespace w5 {
    class Notifications
    {
    private:
        Message *message;
        int count=0;
    public:
        Notifications() { message = new Message[notificationmax]; };
        Notifications(const Notifications& src)     //copy constructor
        {
            message = nullptr;
            *this = src;

        }
        Notifications& operator=(const Notifications& rhs)      //assignment operator
        {
            if (this != &rhs) {
                int num;
                delete[] message;
                count = rhs.count;
                message = new  Message[notificationmax];
                for (int i = 0; i < count; i++) {
                    message[i] = rhs.message[i];
                }

            }
            return *this;
        }
        Notifications(Notifications&& src)      //move constructor
        {
            message = nullptr;
            *this = move(src);

        }
        Notifications&& operator=(Notifications&& rhs) //move operator
        {
            if (this != &rhs) {
                *this = rhs;
                rhs.count = 0;
                delete[] rhs.message;


            }
            return move(*this);
        }
        
        void operator+=(const Message& msg)     
        {
            if (count < notificationmax) {
                message[count] = msg;
               
                count++;
          }
            else { cout << "increse the size of notification"; }

        }
        void display(std::ostream& os) const {
            for (int i = 0; i< count; i++) {
                message[i].display(os);
            }
        }
      
    

    };


}
