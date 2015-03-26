//
// CST 136 - Assignment #3
//
// Author: Leander Rodriguez
//
// File: refCounter.h
//
// Due date:  Sunday, May 12th by 11:59pm
//




//
// This file contains the declaration for a
// reference counter class.
//

#ifndef  refCounter_H
#define  refCounter_H


class RefCounter
{
  public  :

    RefCounter();

    RefCounter(const RefCounter  &rhs);

    ~RefCounter();

    bool  onlyInstance() const {  return *m_cnt == 1;  }

  private  :

    int  *m_cnt;
};


#endif
