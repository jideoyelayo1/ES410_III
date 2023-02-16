/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_exampledecisiontree2_api.c
 *
 * Code generation for function 'exampledecisiontree2'
 *
 */

/* Include files */
#include "_coder_exampledecisiontree2_api.h"
#include "_coder_exampledecisiontree2_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

emlrtContext emlrtContextGlobal = {
    true,                                                 /* bFirstTime */
    false,                                                /* bInitialized */
    131611U,                                              /* fVersionInfo */
    NULL,                                                 /* fErrorFunction */
    "exampledecisiontree2",                               /* fFunctionName */
    NULL,                                                 /* fRTCallStack */
    false,                                                /* bDebugMode */
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, /* fSigWrd */
    NULL                                                  /* fSigMem */
};

/* Function Declarations */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *temperature,
                               const char_T *identifier);

static const mxArray *emlrt_marshallOut(const emlrtStack *sp,
                                        const cell_wrap_0 u);

/* Function Definitions */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = c_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 0U, (void *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *temperature,
                               const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(temperature), &thisId);
  emlrtDestroyArray(&temperature);
  return y;
}

static const mxArray *emlrt_marshallOut(const emlrtStack *sp,
                                        const cell_wrap_0 u)
{
  const mxArray *b_y;
  const mxArray *m;
  const mxArray *y;
  int32_T iv[2];
  int32_T i;
  y = NULL;
  i = 1;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(1, &i));
  b_y = NULL;
  iv[0] = 1;
  iv[1] = u.f1.size[1];
  m = emlrtCreateCharArray(2, &iv[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, u.f1.size[1], m, &u.f1.data[0]);
  emlrtAssign(&b_y, m);
  emlrtSetCell(y, 0, b_y);
  return y;
}

void exampledecisiontree2_api(const mxArray *const prhs[3],
                              const mxArray **plhs)
{
  cell_wrap_0 yield;
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T nitrogen;
  real_T rainfall;
  real_T temperature;
  st.tls = emlrtRootTLSGlobal;
  /* Marshall function inputs */
  temperature = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "temperature");
  rainfall = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "rainfall");
  nitrogen = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "nitrogen");
  /* Invoke the target function */
  exampledecisiontree2(temperature, rainfall, nitrogen,
                       *(cell_wrap_0(*)[1]) & yield);
  /* Marshall function outputs */
  *plhs = emlrt_marshallOut(&st, yield);
}

void exampledecisiontree2_atexit(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  exampledecisiontree2_xil_terminate();
  exampledecisiontree2_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void exampledecisiontree2_initialize(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

void exampledecisiontree2_terminate(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (_coder_exampledecisiontree2_api.c) */
