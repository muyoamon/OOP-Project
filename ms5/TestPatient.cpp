/* Citation and Sources...
Final Project Milestone 4
Module: TestPatient
Filename: TestPatient.cpp
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
#include "TestPatient.h"
namespace seneca  {
  int nextTestTicket = 1;

  char TestPatient::type() const {
    return 'C';
  }
  TestPatient::TestPatient() : Patient::Patient(nextTestTicket) {
    nextTestTicket++;
  }
  std::ostream& TestPatient::write(std::ostream& ostr) const {
    if (&ostr == &std::cout)
      ostr << "Contagion TEST\n";
    return Patient::write(ostr);
  }
  std::istream& TestPatient::read(std::istream& istr) {
    Patient::read(istr);
    if (&istr != &std::cin) {
      nextTestTicket = this->number() + 1;
    }
    return istr;
  }
}
