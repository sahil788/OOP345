#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<functional>

using namespace std;

class Grades {
    string *name=nullptr;
    double *marks =nullptr;
    string *letter=nullptr;
    size_t count=0;
public:
    Grades(char *filename) {
        fstream file(filename);
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                count++;
            }
            // sets the pointer to read file from starting
            file.clear(); //clear end-of-file condition
            file.seekg(0);

            name = new string[count];
            letter = new string[count];
            marks= new double[count];

            for (size_t i = 0; i < count; i++)
            {
                file >> name[i];
                file >>marks[i] ;
            }

            std::cout << "file " << filename << " has " << count << " lines\n";
            file.close();
        }
        else
        {
            throw std::string("Grade(\"") + filename + "\") - cannot open file \n ";
        }
    }
    void displayGrades(std::ostream& os, std::function<std::string(double mark)> letter)const
    {
        for (size_t i = 0; i < count; i++)
        {
            os << name[i] << " "
                << marks[i] << " "
                << letter(marks[i])
                << "\n";
        }
    }
};