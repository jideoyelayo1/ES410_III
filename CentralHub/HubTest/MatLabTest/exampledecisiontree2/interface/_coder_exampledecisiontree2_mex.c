/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_exampledecisiontree2_mex.c
 *
 * Code generation for function 'exampledecisiontree2'
 *
 */

/* Include files */
#include "_coder_exampledecisiontree2_mex.h"
#include "_coder_exampledecisiontree2_api.h"

/* Function Definitions */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&exampledecisiontree2_atexit);
  /* Module initialization. */
  exampledecisiontree2_initialize();
  /* Dispatch the entry-point. */
  unsafe_exampledecisiontree2_mexFunction(nlhs, plhs, nrhs, prhs);
  /* Module termination. */
  exampledecisiontree2_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2021a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL);
  return emlrtRootTLSGlobal;
}

void unsafe_exampledecisiontree2_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                             int32_T nrhs,
                                             const mxArray *prhs[3])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4,
                        20, "exampledecisiontree2");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 20,
                        "exampledecisiontree2");
  }
  /* Call the function. */
  exampledecisiontree2_api(prhs, &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

/* End of code generation (_coder_exampledecisiontree2_mex.c) */
