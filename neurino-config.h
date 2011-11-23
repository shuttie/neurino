#ifndef CONFIG_H
#define CONFIG_H

/*
  This file stores neural network constants.
  */

#define DEFAULT_STEEPNESS 0.5f
#define DEFAULT_BPROP_LEARNRATE 0.6f
#define DEFAULT_BPROPM_MOMENTUM 0.1f

#define DEFAULT_RPROP_DELTAZERO     0.1f
#define DEFAULT_RPROP_DELTAMAX      50.0f
#define DEFAULT_RPROP_DELTAMIN      0.000001f
#define DEFAULT_RPROP_NUMINUS       0.5f
#define DEFAULT_RPROP_NUPLUS        1.2f

#endif // CONFIG_H
