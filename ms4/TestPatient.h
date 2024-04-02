/* Citation and Sources...
Final Project Milestone 4
Module: TestPatient
Filename: TestPatient.h
Version 1.0
Author   Thanatorn Wongthanaporn
Revision History
-----------------------------------------------------------
Date      Reason
2023/3/30  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
----------------------------------------------------------- */
#ifndef SENECA_TESTPAT_H
#define SENECA_TESTPAT_H
#include "Patient.h"
#include <iostream>
namespace seneca  {
  extern int nextTestTicket;
  class TestPatient: public Patient {
    public:
      TestPatient();
      char type() const override;
      std::ostream& write(std::ostream& ostr=std::cout) const override;
      std::istream& read(std::istream& istr=std::cin) override;
  };
}
#endif // !SENECA_TESTPAT_H
