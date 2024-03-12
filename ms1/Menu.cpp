#include "Menu.h"
#include <cstdio>
#include <cstring>
#include <ostream>
#include <cctype>
namespace seneca {
  
  Menu::Menu(const char *menuContent, int numberOfTabs) {
    int i=0; 
    m_text = new char[strlen(menuContent) + 1];
    std::strncpy( (char *) m_text, menuContent, strlen(menuContent));
    m_indentation = numberOfTabs;
    m_optionNum = 0;
    while (menuContent[i] != '\0') {
      if (menuContent[i] == '\n') {
        m_optionNum ++;
      }
      i++;
    }
  }
  Menu::~Menu() {
    delete[] m_text;
  }

  std::ostream& Menu::display(std::ostream& ostr) {
    char* line;
    int i=0;
    this->indent() << "Tester Options menu:\n";
    while (m_text[i] != '\0') {
      line = std::strtok( (char *) m_text, "\n");
      this->indent() << line << std::endl;
      i++;
    }
    this->indent() << "0- Exit\n";
    this->indent() << "> ";
    return ostr;
  }
  
  int& Menu::operator>>(int& Selection) {
    int option;
    bool valid = 1;
    this->display();
    do {
      valid = 1;
      if (!isdigit(std::cin.peek())) {
        valid = 0;
        std::cout << "Bad integer value, try again: ";
      } else {
        std::cin >> option;
        if (std::cin.peek() != EOF) {
          std::cout << "Only enter an integer, try again: ";
          valid = 0;
        } else if (option > m_optionNum) {
          std::cout << "Invalid value enterd, retry[0 <= value <=" << m_optionNum <<"]: ";
          valid = 0;
        }
      }
    } while (!valid);
    Selection = option;
    return Selection;
  }

  std::ostream& Menu::indent(std::ostream& ostr) {
    for (int i=0;i<m_indentation;i++) {
      ostr << " ";
    }
    return ostr;
  }
}
