#ifndef ERROR_H
#define ERROR_H

#include "data/networkdata.h"
#include "core/network.h"

//! A basic error calclation class.
/*!
  For implementing a custom error calculator, you must inherit this class.
  */

class Error {
public:
    Error();
    //! An error function.
    virtual float calculate(Network* net, NetworkData* dataset) = 0;
};

#endif
