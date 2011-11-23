#ifndef NEURINO_MATH_H
#define NEURINO_MATH_H

/*
  These preprocessor math routines make a little performance increase.
  */

#define fast_abs(x) ((x)>0?(x):-(x))

#define fast_max(x,y) ((x)>(y)?(x):(y))

#define fast_min(x,y) ((x)<(y)?(x):(y))

#define fast_sign(x) ((x)>0?1:((x)<0?-1:0))

#endif
