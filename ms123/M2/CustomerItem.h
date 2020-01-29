// CustomerItem.h

#pragma once
#include <iostream>
#include <string>

class Item;

class CustomerItem {
    std::string name;
    bool filled;
    unsigned int code;

  public:
    CustomerItem(const std::string& name = std::string());
    bool asksFor(const Item& item) const;
    bool isFilled() const;
    void fill(const unsigned int c);
    void clear();
	const std::string& getName() const;
    void display(std::ostream& os) const;
};