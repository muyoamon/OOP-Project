/* Citation and Sources...
Final Project Milestone $
Module: PreTriage
Filename: PreTriage.cpp
Version 1.0
Author   Thanatorn Wongthanaporn
Revision History
-----------------------------------------------------------
Date      Reason
2023/4/8  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
----------------------------------------------------------- */
#include "PreTriage.h"
#include "Patient.h"
#include <cstdio>
#include <fstream>
#include <iostream>
#include <strings.h>
#include "TestPatient.h"
#include "TriagePatient.h"
#include "Menu.h"
#include "Utils.h"
namespace seneca {
  const int maxPatients = 100;
  PreTriage::PreTriage(const char* filename) {
    m_testAvgTime = Time(15u);
    m_triAvgTime = Time(5u);
    m_filename = filename;
    m_patientNum = 0;
    load();
  }
  PreTriage::~PreTriage() {
    save();
    for (int i=0 ; i<m_patientNum; i++) {
      delete m_lineup[i];
    }
    delete[] m_lineup;
  }
  
  Time PreTriage::getWaitTime(const Patient& patient) const {
    switch (patient.type()) {
      case 'C':
        return m_testAvgTime;
      case 'T':
        return m_triAvgTime;
      default:
        return Time(0u);
    }
  }

  void PreTriage::setAverageWaitTime(const Patient& patient) {
    
    switch (patient.type()) {
      case 'C':
        m_testAvgTime = ((Time().reset() - patient.time()) + (m_testAvgTime*(patient.number()-1))) / patient.number();
      case 'T':
        m_triAvgTime = ((Time().reset() - patient.time()) + (m_triAvgTime*(patient.number()-1))) / patient.number();
      default:
        break;
    }
  }
  int PreTriage::indexOfFirstInLine(const char type) const {
    for (int i=0 ; i<m_patientNum; i++) {
      if (*m_lineup[i] == type) {
        return i;
      }
    }
    return -1;
  }

  void PreTriage::load() {
    std::ifstream file(m_filename); 
    char currentType;
    std::cout << "Loading data...\n";
    m_lineup = new Patient* [maxPatients]{nullptr};
    if (file) {
      file >> m_testAvgTime;
      file.ignore();
      file >> m_triAvgTime;
      file.ignore();
      for (int i=0;i<maxPatients && !file.fail();i++) {
        currentType = '\0';
        file >> currentType;
        file.ignore();
        if (currentType == 'C') {
          m_lineup[i] = new TestPatient(); 
        } else if (currentType == 'T') {
          m_lineup[i] = new TriagePatient();
        } 
        if (m_lineup[i] != nullptr) {
          file >> *m_lineup[i];
          m_patientNum = i+1;
        }
      }
      if (!file.eof() && m_patientNum > 99) {
        std::cout << "Warning: number of records exceeded 100\n";
      }
    }
    if (m_patientNum != 0) {
      std::cout << m_patientNum << " Records imported...\n\n";
    } else {
      std::cout << "No data or bad data file!\n\n";
    }
    file.close();
  }

  void PreTriage::save() const {
    std::cout << "Saving lineup...\n";
    std::ofstream file(m_filename);
    int testNum = 0;
    int triNum = 0;
    if (file) {
      file << m_testAvgTime;
      file << ",";
      file << m_triAvgTime;
      file << "\n";
      for (int i=0 ; i<m_patientNum; i++) {
        if (*m_lineup[i] == 'C') {
          testNum++;
        } else {
          triNum++;
        }
        file << *m_lineup[i];
        file << "\n";
      }
    std::cout << testNum;
    std::cout << " Contagion Tests and ";
    std::cout << triNum;
    std::cout << " Triage records were saved!\n";

    file.close();
    }
  }

  void PreTriage::regist() {
    Menu options("Select Type of Registration:\n1- Contagion Test\n2- Triage",1);
    int selection;
    if (m_patientNum >= 100) {
      std::cout << "Line up full!\n";
      return;
    }
    options >> selection;
    switch (selection) {
      case 1:
        m_lineup[m_patientNum] = new TestPatient();
        break;
      case 2:
        m_lineup[m_patientNum] = new TriagePatient();
        break;
      case 0:
        return;
      default:
        break;
    }
    std::cout << "Please enter patient information: ";
    std::cin >> *m_lineup[m_patientNum];
    std::cout << "\n";
    std::cout <<"******************************************\n";
    std::cout << m_lineup[m_patientNum];
    std::cout << "Estimated Wait Time: ";
    std::cout << getWaitTime(*m_lineup[m_patientNum]);
    std::cout << "\n" 
      <<"******************************************\n\n";
    m_patientNum ++;
  }

  void PreTriage::admit() {
    Menu options("Select Type of Admittance:\n1- Contagion Test\n2- Triage",1);
    int selection;
    char type;
    options >> selection;
    switch (selection) {
      case 1:
        type = 'C';
        break;
      case 2:
        type = 'T';
        break;
      case 0:
        return;
      default:
        break;
    }
    int index = indexOfFirstInLine(type);
    if (index == -1) {
      std::cout << "Lineup is empty\n";
      return;
    } else {
      std::cout << "\n";
      std::cout << "******************************************\n";
      std::cout << "Call time [H:M]\n";
      std::cout << "Calling for ";
      std::cout << *m_lineup[index];
      std::cout << "******************************************\n\n";
      setAverageWaitTime(*m_lineup[index]);
      removeDynamicElement(m_lineup, index, m_patientNum);
    }
  }

  void PreTriage::lineup() const {
    Menu options("Select The Lineup:\n1- Contagion Test\n2- Triage",1);
    int selection;
    char type;
    int num = 0;
    options >> selection;
    switch (selection) {
      case 1:
        type = 'C';
        break;
      case 2:
        type = 'T';
        break;
      case 0:
        return;
      default:
        break;
    }
    std::clog << "Row - Patient name                                          OHIP     Tk #  Time\n-------------------------------------------------------------------------------\n" ;
    if (m_patientNum ==0) {
      std::clog << "Line up is empty!\n";
    }
    for (int i=0;i<m_patientNum;i++) {
      if (m_lineup[i]->type() == type) {
        std::clog.width(3);
        std::clog.fill(' ');
        std::clog.setf(std::ios_base::left);
        std::clog << num+1;
        std::clog.unsetf(std::ios_base::left);
        std::clog << " - ";
        std::clog << *m_lineup[i] << '\n';
        num++;
      }
    }
    std::clog << "-------------------------------------------------------------------------------\n";
  }

  void PreTriage::run() {

    Menu options("General Healthcare Facility Pre-Triage Application\n1- Register\n2- Admit\n3- View Lineup",0);
    int selection;
    do {
      options >> selection;
      switch (selection) {
        case 1:
          regist();
          break;
        case 2:
          admit();
          break;
        case 3:
          lineup();
          break;
        case 0:
          return;
        default:
          break;
      } 
    } while (selection != 0);
  }
}
