
#include"Station.h"
namespace w2{
   Station::Station() {
        name = "";
        student_pass = 0;
        adult_pass = 0;

    }
   void Station::set(const std::string& name1, unsigned s, unsigned a) {
       name = name1;
       student_pass = s;
       adult_pass = a;

    }
   void Station::update(PassType type, int num) {
       switch (type) {
       case student: {
           student_pass += num;
           } break;
       case adult:adult_pass += num; break;

       }

    }
   unsigned Station::inStock(PassType type) {
       switch (type) {
       case student: {
           return student_pass;
       } break;
       case adult:return adult_pass; break;

       }
    }

   const std::string& Station::getName()const {
       return name;
    }


}