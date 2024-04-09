/* Citation and Sources...
Final Project Milestone $
Module: PreTriage
Filename: PreTriage.h
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
#ifndef SENECA_PRETRIAGE_H
#define SENECA_PRETRIAGE_H
#include "Patient.h"
#include "Time.h"
namespace seneca  {
  int extern const maxPatients;

  class PreTriage {
    Time m_testAvgTime;
    Time m_triAvgTime;
    Patient** m_lineup;
    const char* m_filename;
    int m_patientNum;
    public:
    PreTriage(const char* filename);
    ~PreTriage();
    void run();

    private:
    Time getWaitTime(const Patient&) const;
    void setAverageWaitTime(const Patient&);
    int indexOfFirstInLine(const char type) const;
    void load();
    void save() const;
    void regist();
    void admit();
    void lineup() const;

  };
}

#endif // !SENECA_PRETRIAGE_H

