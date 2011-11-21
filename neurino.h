#ifndef NEURINO_H
#define NEURINO_H

/*
  Global include file to for the whole Neurino library.
  */

#include "algos/algo.h"
#include "algos/bpropalgo.h"

#include "core/layers/layer.h"
#include "core/layers/inputlayer.h"
#include "core/layers/outputlayer.h"

#include "core/link.h"
#include "core/network.h"
#include "core/neuron.h"

#include "data/networkdata.h"
#include "data/networkdataarray.h"
#include "data/networkdatacsv.h"
#include "data/sample.h"

#include "errors/errormse.h"
#include "errors/errorrmse.h"

#include "functions/function.h"
#include "functions/elliottfunction.h"
#include "functions/elliottsymmfunction.h"
#include "functions/linearfunction.h"
#include "functions/sigmoidfunction.h"
#include "functions/tanhfunction.h"
#include "functions/thresholdfunction.h"

#endif
