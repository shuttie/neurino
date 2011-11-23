#ifndef ALGO_H
#define ALGO_H

#include "networkdata.h"
#include "network.h"
#include "neurino-math.h"

//! Basic network learning algorithm class.
/*!
  You should inherit this class for implementing new learning algorightm.
  This class is purely abstract.
  */

class Algo {
public:
    //! Default constructor which by defalut does nothing.
    Algo();
    //! Main learning function.
    /*!
      This function should implement a single step (iteration)
      of your learning algorithm.
      */
    virtual void learn(Network* net, NetworkData* data) = 0;
};

#endif //ALGO_H
