#include "f2c.h"
#undef abs
#include <emscripten/bind.h>
#include <vector>
using namespace emscripten;

#ifdef __cplusplus
extern "C" {
#endif

typedef std::vector<double> DoubleVec;
typedef std::vector<long int> IntVec;

extern int tstmvt_();

extern int mvtdst_(integer *, integer *, doublereal *, 
  doublereal *, integer *, doublereal *, doublereal *, integer *, 
  doublereal *, doublereal *, doublereal *, doublereal *, integer *)
  ;

struct MVNormResult {
  doublereal value;
  doublereal error;
  integer inform;
};

struct MVNormResult pmvnorm(integer n, integer nu, DoubleVec& lower, 
  DoubleVec& upper, IntVec& infin, DoubleVec& correl, DoubleVec& delta, 
  integer maxpts, doublereal abseps, doublereal releps)
{
  struct MVNormResult result;
  mvtdst_(&n, &nu, &lower[0], &upper[0], &infin[0], &correl[0], &delta[0], &maxpts, &abseps, &releps, &result.error, &result.value, &result.inform);
  return result;
}

int boom() { 
  return 42;
}

struct MVNormResult test() {
  struct MVNormResult result;
  result.value = 42;
  result.error = 0.0;
  result.inform = 3;
  return result;
}

#ifdef __cplusplus
}
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
  register_vector<long int>("IntVec");
  register_vector<double>("DoubleVec");
}
