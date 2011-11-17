#include "networkdatacsv.h"

NetworkDataCsv::NetworkDataCsv(unsigned int inputs, unsigned int outputs, std::string fileName)
    :NetworkData(inputs, outputs)
{
    // reading file into memory
    vector<string> fileContents;

    ifstream ifs(fileName.c_str(), ifstream::in);
    string line;

    while( getline( ifs, line ) )
        fileContents.push_back( line );

    //parsing it
    for (unsigned int i=0; i<fileContents.size(); ++i) {
        istringstream lineStream(fileContents.at(i));
        vector<string> tokens;
        copy(istream_iterator<string>(lineStream),
             istream_iterator<string>(),
             back_inserter<vector<string> >(tokens));
        // if we're going to read existing columns in csv
        if (inputs+outputs <= tokens.size()) {
            Sample s;
            //parsing inputs
            for (unsigned int j=0; j<inputs; ++j) {
                stringstream tokenStream(tokens.at(j));
                float value;
                tokenStream >> value;
                s.inputs.push_back(value);
            }
            //parsing outputs
            for (unsigned int j=inputs; j<inputs+outputs; ++j) {
                stringstream tokenStream(tokens.at(j));
                float value;
                tokenStream >> value;
                s.outputs.push_back(value);
            }
            if ((s.inputs.size() != inputs) || (s.outputs.size() != outputs))
                printf("NetworkDataCsv error: got mismatch between 'inputs', 'outputs' and the actual data.\n");
            else
                samples.push_back(s);
        } else {
            printf("NetworkDataCsv error: going to read %d columns, but got only %d", inputs+outputs, tokens.size());
        }
    }
}
