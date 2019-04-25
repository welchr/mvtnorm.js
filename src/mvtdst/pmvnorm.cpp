#include "f2c.h"
#undef abs
#include <emscripten/bind.h>
#include <iostream>
#include <vector>
using namespace emscripten;

#ifdef __cplusplus
//extern "C" {
#endif

typedef std::vector<double> DoubleVec;
typedef std::vector<long int> IntVec;

extern "C" int tstmvt_();

extern "C" int mvtdst_(integer *, integer *, doublereal *, 
  doublereal *, integer *, doublereal *, doublereal *, integer *, 
  doublereal *, doublereal *, doublereal *, doublereal *, integer *)
  ;

struct MVNormResult {
  doublereal value;
  doublereal error;
  integer inform;
};

MVNormResult pmvnorm(integer n, integer nu, DoubleVec& lower, 
  DoubleVec& upper, IntVec& infin, DoubleVec& correl, DoubleVec& delta, 
  integer maxpts, doublereal abseps, doublereal releps)
{
  MVNormResult result;
  mvtdst_(&n, &nu, &lower[0], &upper[0], &infin[0], &correl[0], &delta[0], &maxpts, &abseps, &releps, &result.error, &result.value, &result.inform);
  std::cout << "mvtdst_ value: " << result.value << std::endl;
  return result;
}

int boom() { 
  return 42;
}

MVNormResult test() {
  MVNormResult result;
  result.value = 42;
  result.error = 0.0;
  result.inform = 3;
  return result;
}

MVNormResult test2() {
  MVNormResult result;
  result.value = 100;
  std::cout << result.value << std::endl;
  return result;
}

int test3(IntVec& vec) {
  int sum = 0;
  for (auto&& x : vec) {
    sum += x;
  }
  return sum;
}

#ifdef __cplusplus
//}
#endif

EMSCRIPTEN_BINDINGS(mvtnorm) {
  value_object<MVNormResult>("MVNormResult")
    .field("value", &MVNormResult::value)
    .field("error", &MVNormResult::error)
    .field("inform", &MVNormResult::inform);
  function("pmvnorm", &pmvnorm, allow_raw_pointers());
  function("tstmvt", &tstmvt_);
  function("boom", &boom);
  function("test", &test);
  function("test2", &test2);
  function("test3", &test3);
  register_vector<long int>("IntVec");
  register_vector<double>("DoubleVec");
}
