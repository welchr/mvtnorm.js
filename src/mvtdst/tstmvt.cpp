/*   This file contains a short test program, software MVTDST for */
/*   the MVT distribution, plus supporting software.  The file is */
/*   self-contained and should compile without errors on standard */
/*   Fortran(77) compilers. The test program demonstrates the use */
/*   of MVTDST for computing MVT distribution values for a five */
/*   dimensional example problem, with four different NU values. */

/*          Alan Genz */
/*          Department of Mathematics */
/*          Washington State University */
/*          Pullman, WA 99164-3113 */
/*          Email : AlanGenz@wsu.edu */

#ifdef __cplusplus
extern "C" {
#endif
#include "f2c.h"

static doublereal c_b4 = 5e-4;
static integer c__1 = 1;
static integer c__5 = 5;
static integer c__25000 = 25000;
static real c_b18 = (float)1.;
static doublereal c_b49 = 0.;
static integer c_n1 = -1;
static logical c_true = TRUE_;
static integer c__0 = 0;
static doublereal c_b92 = 1.;
static doublereal c_b100 = 2.;
static integer c__100 = 100;

/* Subroutine */ int tstmvt_()
{
  /* Initialized data */

  static doublereal up[5] = { 2.,2.,2.,2.,2. };
  static doublereal low[5] = { 0.,0.,0.,0.,0. };
  static doublereal delta[5] = { 1.,1.,1.,1.,1. };
  static integer infin[5] = { 0,0,0,0,0 };
  static doublereal correl[10] = { .75,.75,.75,.75,.75,.75,.75,.75,.75,.75 }
  ;

  /* System generated locals */
  integer i__1;

  /* Builtin functions */
  extern integer s_wsfe(cilist *);
  extern integer e_wsfe(); 
  extern integer do_fio(integer *, char *, ftnlen);

  /* Local variables */
  static integer i__, j, ij, nu;
  static doublereal vals;
  static integer ifts;
  static doublereal errs;
  extern /* Subroutine */ int mvtdst_(integer *, integer *, doublereal *, 
      doublereal *, integer *, doublereal *, doublereal *, integer *, 
      doublereal *, doublereal *, doublereal *, doublereal *, integer *)
    ;

  /* Fortran I/O blocks */
  static cilist io___6 = { 0, 6, 0, "('        Test of MVTDST')", 0 };
  static cilist io___7 = { 0, 6, 0, "(5X, 'Requested Accuracy ',F8.5)", 0 };
  static cilist io___8 = { 0, 6, 0, "(5X,'Number of Dimensions is ',I2)", 0 
  };
  static cilist io___9 = { 0, 6, 0, "('     Maximum # of Function Values i\
    s ',I7)", 0 };
  static cilist io___10 = { 0, 6, 0, "(/' I     Limits'/'    Lower  Upper \
    Delta', 5X, 'Lower Left of Correlation Matrix')", 0 };
  static cilist io___13 = { 0, 6, 0, "(I2, ' -infin  infin ', F7.4, 7F9.4)",
    0 };
  static cilist io___15 = { 0, 6, 0, "(I2, ' -infin', 2F7.4, 1X, 6F9.4)", 0 
  };
  static cilist io___16 = { 0, 6, 0, "(I2, F7.4, '  infin ', F7.4, 6F9.4)", 
    0 };
  static cilist io___17 = { 0, 6, 0, "(I2, 3F7.4, 1X, 6F9.4)", 0 };
  static cilist io___19 = { 0, 6, 0, "(4X,'Nu is ',I3)", 0 };
  static cilist io___23 = { 0, 6, 0, "(' Results for:  MVTDST')", 0 };
  static cilist io___24 = { 0, 6, 0, "(' Value:     ',2(F11.6,I4))", 0 };
  static cilist io___25 = { 0, 6, 0, "(' Error Est.:',2X,'(',F8.6,')',3X)", 
    0 };
  static cilist io___26 = { 0, 6, 0, "(4X,'Nu is Infinity')", 0 };
  static cilist io___27 = { 0, 6, 0, "(' Results for:  MVTDST')", 0 };
  static cilist io___28 = { 0, 6, 0, "(' Value:     ',2(F11.6,I4))", 0 };
  static cilist io___29 = { 0, 6, 0, "(' Error Est.:',2X,'(',F8.6,')',3X)", 
    0 };



  /*     Test program for MVTDST */

  s_wsfe(&io___6);
  e_wsfe();
  s_wsfe(&io___7);
  do_fio(&c__1, (char *)&c_b4, (ftnlen)sizeof(doublereal));
  e_wsfe();
  s_wsfe(&io___8);
  do_fio(&c__1, (char *)&c__5, (ftnlen)sizeof(integer));
  e_wsfe();
  s_wsfe(&io___9);
  do_fio(&c__1, (char *)&c__25000, (ftnlen)sizeof(integer));
  e_wsfe();

  s_wsfe(&io___10);
  e_wsfe();
  ij = 0;
  for (i__ = 1; i__ <= 5; ++i__) {
    if (infin[i__ - 1] < 0) {
      s_wsfe(&io___13);
      do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
      do_fio(&c__1, (char *)&delta[i__ - 1], (ftnlen)sizeof(doublereal))
        ;
      i__1 = i__ - 1;
      for (j = 1; j <= i__1; ++j) {
        do_fio(&c__1, (char *)&correl[ij + j - 1], (ftnlen)sizeof(
              doublereal));
      }
      do_fio(&c__1, (char *)&c_b18, (ftnlen)sizeof(real));
      e_wsfe();
    } else if (infin[i__ - 1] == 0) {
      s_wsfe(&io___15);
      do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
      do_fio(&c__1, (char *)&up[i__ - 1], (ftnlen)sizeof(doublereal));
      do_fio(&c__1, (char *)&delta[i__ - 1], (ftnlen)sizeof(doublereal))
        ;
      i__1 = i__ - 1;
      for (j = 1; j <= i__1; ++j) {
        do_fio(&c__1, (char *)&correl[ij + j - 1], (ftnlen)sizeof(
              doublereal));
      }
      do_fio(&c__1, (char *)&c_b18, (ftnlen)sizeof(real));
      e_wsfe();
    } else if (infin[i__ - 1] == 1) {
      s_wsfe(&io___16);
      do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
      do_fio(&c__1, (char *)&low[i__ - 1], (ftnlen)sizeof(doublereal));
      do_fio(&c__1, (char *)&delta[i__ - 1], (ftnlen)sizeof(doublereal))
        ;
      i__1 = i__ - 1;
      for (j = 1; j <= i__1; ++j) {
        do_fio(&c__1, (char *)&correl[ij + j - 1], (ftnlen)sizeof(
              doublereal));
      }
      do_fio(&c__1, (char *)&c_b18, (ftnlen)sizeof(real));
      e_wsfe();
    } else {
      s_wsfe(&io___17);
      do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
      do_fio(&c__1, (char *)&low[i__ - 1], (ftnlen)sizeof(doublereal));
      do_fio(&c__1, (char *)&up[i__ - 1], (ftnlen)sizeof(doublereal));
      do_fio(&c__1, (char *)&delta[i__ - 1], (ftnlen)sizeof(doublereal))
        ;
      i__1 = i__ - 1;
      for (j = 1; j <= i__1; ++j) {
        do_fio(&c__1, (char *)&correl[ij + j - 1], (ftnlen)sizeof(
              doublereal));
      }
      do_fio(&c__1, (char *)&c_b18, (ftnlen)sizeof(real));
      e_wsfe();
    }
    ij = ij + i__ - 1;
  }
  for (nu = 10; nu <= 110; nu += 25) {
    s_wsfe(&io___19);
    do_fio(&c__1, (char *)&nu, (ftnlen)sizeof(integer));
    e_wsfe();
    mvtdst_(&c__5, &nu, low, up, infin, correl, delta, &c__25000, &c_b49, 
        &c_b4, &errs, &vals, &ifts);
    s_wsfe(&io___23);
    e_wsfe();
    s_wsfe(&io___24);
    do_fio(&c__1, (char *)&vals, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&ifts, (ftnlen)sizeof(integer));
    e_wsfe();
    s_wsfe(&io___25);
    do_fio(&c__1, (char *)&errs, (ftnlen)sizeof(doublereal));
    e_wsfe();
  }
  s_wsfe(&io___26);
  e_wsfe();
  mvtdst_(&c__5, &c_n1, low, up, infin, correl, delta, &c__25000, &c_b49, &
      c_b4, &errs, &vals, &ifts);
  s_wsfe(&io___27);
  e_wsfe();
  s_wsfe(&io___28);
  do_fio(&c__1, (char *)&vals, (ftnlen)sizeof(doublereal));
  do_fio(&c__1, (char *)&ifts, (ftnlen)sizeof(integer));
  e_wsfe();
  s_wsfe(&io___29);
  do_fio(&c__1, (char *)&errs, (ftnlen)sizeof(doublereal));
  e_wsfe();

  return 0;
} /* tstmvt_ */

int main() {
  return tstmvt_();
}

#ifdef __cplusplus
}
#endif
