#include "networkdataarray.h"

NetworkDataArray::NetworkDataArray(unsigned int inputs, unsigned int outputs, std::vector<std::vector<float> > inputData, std::vector<std::vector<float> > outputData)
    :NetworkData(inputs,outputs)
{
    if (inputData.size() != outputData.size())
        printf("NetworkDataArray error: inputData and outputData vector sizes do not match.\n");
    else {
        for (unsigned int i=0; i<inputData.size(); ++i) {
            Sample sample(inputData.at(i), outputData.at(i));
            if ((sample.inputs.size() == inputs) && (sample.outputs.size() == outputs))
                samples.push_back(sample);
            else
                printf("NetworkDataArray error: inconsistency detected in input/output vector sizes.\n");
        }
    }
}
