// ItemManager.h

#pragma once
#include <iostream>
#include <vector>

class ItemManager {
  std::vector<Item> items;
  public:
  void push_back(Item&&);
  std::vector<Item>::iterator begin();
  std::vector<Item>::iterator end();
  const std::vector<Item>::const_iterator cbegin() const;
  const std::vector<Item>::const_iterator cend() const;
  void display(std::ostream&, bool = false) const;
};