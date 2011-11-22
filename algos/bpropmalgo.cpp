#include "bpropmalgo.h"

BPropmAlgo::BPropmAlgo(float learnRate, float momentum)
    :BPropAlgo(learnRate), momentum(momentum) {

}

void BPropmAlgo::updateWeights(Network* net)
{
    for (int l=0; l<net->links.size(); ++l) {
        net->links.at(l)->weight += net->links.at(l)->gradient * learnRate + momentum*net->links.at(l)->gradientPrev;
    }
}
