#ifndef SENECA_TIME_H
#define SENECA_TIME_H
#include <iostream>
namespace seneca {
class Time {
  unsigned int m_minutes;

public:
  Time& reset();
  Time(unsigned int min = 0u);
  std::ostream& write(std::ostream& ostr=std::cout);
  std::istream& read(std::istream& istr=std::cin);

  operator unsigned int() const;
  Time& operator*= (int val);
  Time& operator-= (const Time& D);
  Time operator- (const Time& T) const;
  std::ostream& operator<<(std::ostream& ostr);

};
  std::istream& operator>>(std::istream& istr, Time& T);
} // namespace seneca

#endif // !SENECA_TIME_H
