// Utilities.h

#pragma once
#include <string>

const unsigned int CODE_WIDTH = 5; 

class Utilities {
  private:
    size_t field_width;
    static char delimiter;
  public:
    Utilities(size_t minimum_field_width = 1u);
    void setFieldWidth(size_t fw);
    size_t getFieldWidth() const;
    const std::string nextToken(const std::string& str, size_t& next_pos, bool& more);
    static void setDelimiter(const char c);
    static const char getDelimiter();
};