/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * soilpropertiestree_trial3_emxAPI.h
 *
 * Code generation for function 'soilpropertiestree_trial3_emxAPI'
 *
 */

#ifndef SOILPROPERTIESTREE_TRIAL3_EMXAPI_H
#define SOILPROPERTIESTREE_TRIAL3_EMXAPI_H

/* Include files */
#include "rtwtypes.h"
#include "soilpropertiestree_trial3_types.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern emxArray_char_T *emxCreateND_char_T(int numDimensions, const int *size);

extern emxArray_char_T *emxCreateWrapperND_char_T(char *data, int numDimensions,
                                                  const int *size);

extern emxArray_char_T *emxCreateWrapper_char_T(char *data, int rows, int cols);

extern emxArray_char_T *emxCreate_char_T(int rows, int cols);

extern void emxDestroyArray_char_T(emxArray_char_T *emxArray);

extern void emxDestroyMatrix_cell_wrap_0(cell_wrap_0 emxArray[1]);

extern void emxInitMatrix_cell_wrap_01(cell_wrap_0 pMatrix[1]);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (soilpropertiestree_trial3_emxAPI.h) */
