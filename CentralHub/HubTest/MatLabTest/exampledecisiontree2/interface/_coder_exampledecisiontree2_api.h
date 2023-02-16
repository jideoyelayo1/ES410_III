/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_exampledecisiontree2_api.h
 *
 * Code generation for function 'exampledecisiontree2'
 *
 */

#ifndef _CODER_EXAMPLEDECISIONTREE2_API_H
#define _CODER_EXAMPLEDECISIONTREE2_API_H

/* Include files */
#include "emlrt.h"
#include "tmwtypes.h"
#include <string.h>

/* Type Definitions */
#ifndef struct_emxArray_char_T_1x4
#define struct_emxArray_char_T_1x4
struct emxArray_char_T_1x4 {
  char_T data[4];
  int32_T size[2];
};
#endif /* struct_emxArray_char_T_1x4 */
#ifndef typedef_emxArray_char_T_1x4
#define typedef_emxArray_char_T_1x4
typedef struct emxArray_char_T_1x4 emxArray_char_T_1x4;
#endif /* typedef_emxArray_char_T_1x4 */

#ifndef typedef_cell_wrap_0
#define typedef_cell_wrap_0
typedef struct {
  emxArray_char_T_1x4 f1;
} cell_wrap_0;
#endif /* typedef_cell_wrap_0 */

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void exampledecisiontree2(real_T temperature, real_T rainfall, real_T nitrogen,
                          cell_wrap_0 yield[1]);

void exampledecisiontree2_api(const mxArray *const prhs[3],
                              const mxArray **plhs);

void exampledecisiontree2_atexit(void);

void exampledecisiontree2_initialize(void);

void exampledecisiontree2_terminate(void);

void exampledecisiontree2_xil_shutdown(void);

void exampledecisiontree2_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (_coder_exampledecisiontree2_api.h) */
