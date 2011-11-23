#ifndef NETWORKDATACSV_H
#define NETWORKDATACSV_H

#include "networkdata.h"
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>

using namespace std;

//! A class for creating NetworkData dataset from CSV files.
/*!
  It also performs some sanity checks and discards broken data.
  */

class NetworkDataCsv : public NetworkData
{
public:
    NetworkDataCsv(unsigned int inputs, unsigned int outputs, string fileName, string separator);
};

#endif // NETWORKDATACSV_H
