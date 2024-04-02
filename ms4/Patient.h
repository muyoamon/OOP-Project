/* Citation and Sources...
Final Project Milestone 4
Module: Patient
Filename: Patient.h
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
#ifndef SENECA_PATIENT_H
#define SENECA_PATIENT_H
#include <iostream>
#include "IOAble.h"
#include "Ticket.h"
namespace seneca {
class Patient: public IOAble {
char* m_name;
int m_ohipNum;
Ticket m_ticket;
  public:
Patient(int ticketNum);
Patient(Patient& other);
Patient(Patient&& other);
Patient& operator=(Patient& rhs);
virtual ~Patient();
virtual char type() const=0;
bool operator==(const char type) const;
bool operator==(const Patient& rhs) const;
void setArrivalTime();
Time time() const;
int number() const;
operator bool() const;
operator const char*() const;
std::ostream & write(std::ostream &ostr = std::cout) const override;
std::istream & read(std::istream &istr = std::cin) override;
};
}

#endif // !SENECA_PATIENT_H

