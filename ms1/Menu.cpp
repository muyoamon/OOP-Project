/* Citation and Sources...
Final Project Milestone 1 
Module: Menu
Filename: Menu.cpp
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
#include "Menu.h"
#include <cstdio>
#include <cstring>
#include <ios>
#include <iostream>
#include <cctype>
#include <limits>
namespace seneca {
  
  Menu::Menu(const char *menuContent, int numberOfTabs) {
    int i=0; 
    m_text = new char[strlen(menuContent) + 1];
    std::strcpy( (char *) m_text, menuContent);
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
    char* lines = new char[std::strlen(m_text) + 1];
    std::strcpy(lines,m_text);
    char * line = std::strtok(lines, "\n");
    while (line != NULL) {
      this->indent() << line << std::endl;
      line = std::strtok(NULL, "\n\0");
    }
    this->indent() << "0- Exit\n";
    this->indent() << "> ";
    delete[] lines;
    return ostr;
  }
  
  int& Menu::operator>>(int& Selection) {
    int option;
    bool valid = 1;
    this->display();
    do {
      valid = 1;
      std::cin.setstate(std::ios_base::goodbit);
      std::cin >> option;
      if (std::cin.fail()) {
        valid = 0;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Bad integer value, try again: ";
      } else {
        if (std::cin.peek() != '\n') {
          std::cout << "Only enter an integer, try again: ";
          valid = 0;
        } else if (option > m_optionNum || option < 0) {
          std::cout << "Invalid value enterd, retry[0 <= value <= " << m_optionNum << "]: ";
          valid = 0;
        }
      }
    } while (!valid);
    Selection = option;
    return Selection;
  }

  std::ostream& Menu::indent(std::ostream& ostr) {
    for (int i=0;i<m_indentation;i++) {
      ostr << "   ";
    }
    return ostr;
  }
}
