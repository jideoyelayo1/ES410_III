/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * exampledecisiontree2_initialize.c
 *
 * Code generation for function 'exampledecisiontree2_initialize'
 *
 */

/* Include files */
#include "exampledecisiontree2_initialize.h"
#include "exampledecisiontree2_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void exampledecisiontree2_initialize(void)
{
  rt_InitInfAndNaN();
  isInitialized_exampledecisiontree2 = true;
}

/* End of code generation (exampledecisiontree2_initialize.c) */
