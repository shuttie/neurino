#ifndef NETWORKERROR_H
#define NETWORKERROR_H

#include "networkdata.h"
#include "network.h"

//! A basic error calclation class.
/*!
  For implementing a custom error calculator, you must inherit this class.
  */

class NetworkError {
public:
    NetworkError();
    //! An error function.
    virtual float calculate(Network* net, NetworkData* dataset) = 0;
};

#endif
