#ifndef SENECA_MENU_H
#define SENECA_MENU_H
#include <iostream>
namespace seneca {
class Menu {
  const char * m_text;
  int m_optionNum;
  int m_indentation;

public:
  Menu(const char *menuContent, int numberOfTabs = 0);
  Menu(Menu &menu) = delete;
  ~Menu();

  Menu &operator=(Menu &menu) = delete;
  std::ostream& display(std::ostream& ostr=std::cout);
  
  int& operator>>(int& Selection);
  
  std::ostream& indent(std::ostream& ostr=std::cout);
};
} // namespace seneca

#endif // !SENECA_MENU_H
