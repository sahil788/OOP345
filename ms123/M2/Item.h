// Item.h

#pragma once
#include <iostream>
#include <string>

class Item {
    std::string name;
    std::string source;
    std::string destination;
    std::string details;
    unsigned int code;
    static char delimiter;
    static size_t field_width;

  public:
    Item(const std::string& record = std::string());
    bool empty() const;
    void operator++(int i);
    unsigned int getCode() const;
    const std::string& getName() const;
    const std::string& getSource() const;
    const std::string& getDestination() const;
    void display(std::ostream& os, bool full = false) const;
    static void setDelimiter(const char c);
    static size_t getFieldWidth();
};