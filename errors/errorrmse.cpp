#include "errorrmse.h"

ErrorRMSE::ErrorRMSE() {

}

float ErrorRMSE::calculate(Network *net, NetworkData *dataset) {
    return sqrt(ErrorMSE::calculate(net, dataset));
}
