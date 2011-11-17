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

class NetworkDataCsv : public NetworkData
{
public:
    NetworkDataCsv(unsigned int inputs, unsigned int outputs, std::string fileName);
};

#endif // NETWORKDATACSV_H
