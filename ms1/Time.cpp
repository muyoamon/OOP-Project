/* Citation and Sources...
Final Project Milestone 1 
Module: Time
Filename: Time.cpp
Version 1.0
Author   Thanatorn Wongthanaporn
Revision History
-----------------------------------------------------------
Date      Reason
2023/3/12  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
----------------------------------------------------------- */
#include "Time.h"
#include "Utils.h"
namespace seneca {
  
  Time& Time::reset() {
    m_minutes = U.getTime();
    return *this;
  }
  Time::Time(unsigned int min) {
    m_minutes = min;
  }
  std::ostream& Time::write(std::ostream& ostr) {
    ostr.width(2);
    ostr.fill('0');
    ostr << m_minutes/60 << ":";
    ostr.width(2);
    ostr << m_minutes%60;
    return ostr;
  }
  std::istream& Time::read(std::istream& istr) {
    uint hour, minute;
    istr >> hour;
    if (istr.peek() != ':') {
      istr.setstate(std::ios::failbit);
    } else {
      istr.ignore(1);
      istr >> minute;
      m_minutes = hour*60+minute;
    }
    return istr;
  }

  Time::operator unsigned int() const {
    return m_minutes;
  }
  Time& Time::operator*= (int val) {
    m_minutes *= val;
    return *this;
  }
  Time& Time::operator-= (const Time& D) {
    if (this->m_minutes < D.m_minutes) {
      this->m_minutes += 1440u;
    }
    this->m_minutes -= D.m_minutes;
    return *this;
  }
  Time Time::operator- (const Time& T) const {
    Time result = *this;
    return Time(result -= T);
  }
  std::ostream& operator<<(std::ostream& ostr, Time T) {
    return T.write(ostr);
  }
  std::istream& operator>>(std::istream& istr, Time& T) {
    return T.read(istr);
  }
}
