// Test to check NetworkData class usability.

#include "data/networkdatacsv.h"
#include <stdio.h>

int main(int argc, char** argv) {
    if (argc == 2) {
        string sdir(argv[1]);
        NetworkDataCsv data(47,4,sdir+"/tests/input.csv");
        if (data.samples.size() == 1000)
            printf("PASS\n");
        else
            printf("FAIL\n");
    } else
        printf("FAIL");
}
