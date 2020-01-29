// CustomerOrder.h

#pragma once
#include <iostream>
#include <string>

class Item;
class CustomerItem;

class CustomerOrder {
    std::string name;
    std::string product;
    CustomerItem* order;
    unsigned int nOrders;
    static char delimiter;
    static size_t field_width;

  public:
    CustomerOrder(const std::string& record);
    CustomerOrder(const CustomerOrder& rhs);
    CustomerOrder& operator=(const CustomerOrder&) = delete;
    CustomerOrder(CustomerOrder&& rhs);
    CustomerOrder&& operator=(CustomerOrder&& rhs);
    ~CustomerOrder();
    unsigned int noOrders() const;
    const std::string& operator[](unsigned int i) const;
    void fill(Item& item);
    void remove(Item& item);
    bool empty() const;
    void display(std::ostream& os) const;
    static void setDelimiter(const char c);
};