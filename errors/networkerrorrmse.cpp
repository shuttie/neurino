#include "networkerrorrmse.h"

NetworkErrorRMSE::NetworkErrorRMSE() {

}

float NetworkErrorRMSE::calculate(Network *net, NetworkData *dataset) {
    return sqrt(NetworkErrorMSE::calculate(net, dataset));
}
