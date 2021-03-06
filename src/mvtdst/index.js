function run_mvt_test() {
  return new Promise((resolve, reject) => {
    mvtdstpack().then(Module => {
      const pmvnorm = Module.pmvnorm;
      const IntVec = Module.IntVec;
      const DoubleVec = Module.DoubleVec;

      // Parameters
      let n = 4;
      let df = 0;

      let lower = new Module.DoubleVec();
      lower.push_back(-0.68280434415179325);
      lower.push_back(-0.68280434415179325);
      lower.push_back(-0.68280434415179325);
      lower.push_back(-0.68280434415179325);

      let upper = new Module.DoubleVec();
      upper.push_back(0.68280434415179325);
      upper.push_back(0.68280434415179325);
      upper.push_back(0.68280434415179325);
      upper.push_back(0.68280434415179325);

      let infin = new Module.IntVec();
      infin.push_back(2);
      infin.push_back(2);
      infin.push_back(2);
      infin.push_back(2);

      let corr = new Module.DoubleVec();
      corr.push_back(0.7068817630734282);
      corr.push_back(0.5769894472718361);
      corr.push_back(0.81624431021682053);
      corr.push_back(0.24500706924085489);
      corr.push_back(0.34659039585584789);
      corr.push_back(0.42460934167161291);

      let delta = new Module.DoubleVec();
      delta.push_back(0);
      delta.push_back(0);
      delta.push_back(0);
      delta.push_back(0);

      let maxpts = 50000;
      let abseps = 0.001;
      let releps = 0.0;

      console.log("Error should be: ", "0.000031585624965638197");
      console.log("Value should be: ", "0.12164661836389246");
      console.log("Inform should be 0")
      resolve(Module.mvtdst(n, df, lower, upper, infin, corr, delta, maxpts, abseps, releps));
    });
  });
}

/**
 * DOES NOT WORK
 */
function test_wasm() {
  var importObject = { 
    imports: { 
      i: arg => console.log(arg) 
    }, 
    env: {
      abort: console.log
    },
    global: {
      "Infinity": Infinity
    }
  };

  fetch("mvtdstpack.wasm")
  .then(r => r.arrayBuffer())
  .then(bytes => WebAssembly.instantiate(bytes, importObject));
  return importObject;
}
