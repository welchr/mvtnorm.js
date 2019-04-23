function run_mvt_test() {
  const pmvnorm = Module.pmvnorm;
  const IntVec = Module.IntVec;
  const DoubleVec = Module.DoubleVec;

  // Parameters
  let n = 4;
  let df = 0;

  let lower = new DoubleVec();
  lower.push_back(-0.68280434415179325);
  lower.push_back(-0.68280434415179325);
  lower.push_back(-0.68280434415179325);
  lower.push_back(-0.68280434415179325);

  let upper = new DoubleVec();
  upper.push_back(0.68280434415179325);
  upper.push_back(0.68280434415179325);
  upper.push_back(0.68280434415179325);
  upper.push_back(0.68280434415179325);

  let infin = new IntVec();
  infin.push_back(2);
  infin.push_back(2);
  infin.push_back(2);
  infin.push_back(2);

  let corr = new DoubleVec();
  corr.push_back(0.7068817630734282);
  corr.push_back(0.5769894472718361);
  corr.push_back(0.81624431021682053);
  corr.push_back(0.24500706924085489);
  corr.push_back(0.34659039585584789);
  corr.push_back(0.42460934167161291);

  let delta = new DoubleVec();
  delta.push_back(0);
  delta.push_back(0);
  delta.push_back(0);
  delta.push_back(0);

  let maxpts = 50000;
  let abseps = 0.001;
  let releps = 0.0;

  let result = pmvnorm(n, df, lower, upper, infin, corr, delta, maxpts, abseps, releps);
  return result;
}
