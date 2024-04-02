/* Citation and Sources...
Final Project Milestone 2
Module: IOAble
Filename: IOAble.h
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
#ifndef SENECA_IOABLE_H
#define SENECA_IOABLE_H
#include <iostream>
namespace seneca  {
  class IOAble {
  public:
    virtual ~IOAble() {};
    virtual std::ostream& write(std::ostream& ostr=std::cout) const = 0;
    virtual std::istream& read(std::istream& istr=std::cin) = 0;
  };
  std::ostream& operator<<(std::ostream& ostr, const IOAble& io);
  std::istream& operator>>(std::istream& istr, IOAble& io);
}

#endif // !SENECA_IOABLE_H
