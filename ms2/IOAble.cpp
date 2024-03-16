/* Citation and Sources...
Final Project Milestone 2
Module: IOAble
Filename: IOAble.cpp
Version 1.0
Author   Thanatorn Wongthanaporn
Revision History
-----------------------------------------------------------
Date      Reason
2023/3/15  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
----------------------------------------------------------- */

#include <iostream>
#include "IOAble.h"
namespace seneca {
  


  std::ostream& operator<<(std::ostream& ostr, IOAble& io) {
    return io.write(ostr);
  }
  std::istream& operator>>(std::istream& istr, IOAble& io) {
    return io.read(istr);
  }
}
