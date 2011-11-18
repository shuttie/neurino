// Test to check BPropAlgo class usability.

#include "data/networkdataarray.h"
#include <stdio.h>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
    vector<float> xor1in, xor1out, xor2in, xor2out, xor3in, xor3out, xor4in, xor4out;
    xor1in.push_back(0);
    xor1in.push_back(0);
    xor1out.push_back(0);

    xor2in.push_back(0);
    xor2in.push_back(1);
    xor2out.push_back(1);

    xor3in.push_back(1);
    xor3in.push_back(0);
    xor3out.push_back(1);

    xor4in.push_back(1);
    xor4in.push_back(1);
    xor4out.push_back(0);

    vector< vector<float> > dataInput, dataOutput;
    dataInput.push_back(xor1in);
    dataInput.push_back(xor2in);
    dataInput.push_back(xor3in);
    dataInput.push_back(xor4in);

    dataOutput.push_back(xor1out);
    dataOutput.push_back(xor2out);
    dataOutput.push_back(xor3out);
    dataOutput.push_back(xor4out);

    NetworkDataArray data(2, 1, dataInput, dataOutput);
}
