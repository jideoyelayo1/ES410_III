/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * soilpropertiestree_trial3_emxutil.h
 *
 * Code generation for function 'soilpropertiestree_trial3_emxutil'
 *
 */

#ifndef SOILPROPERTIESTREE_TRIAL3_EMXUTIL_H
#define SOILPROPERTIESTREE_TRIAL3_EMXUTIL_H

/* Include files */
#include "rtwtypes.h"
#include "soilpropertiestree_trial3_types.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void emxCopyStruct_cell_wrap_0(cell_wrap_0 *dst, const cell_wrap_0 *src);

extern void emxCopy_char_T(emxArray_char_T **dst, emxArray_char_T *const *src);

extern void emxEnsureCapacity_char_T(emxArray_char_T *emxArray, int oldNumel);

extern void emxFreeMatrix_cell_wrap_0(cell_wrap_0 *pMatrix);

extern void emxFreeStruct_cell_wrap_0(cell_wrap_0 *pStruct);

extern void emxFree_char_T(emxArray_char_T **pEmxArray);

extern void emxInitMatrix_cell_wrap_0(cell_wrap_0 *pMatrix);

extern void emxInitStruct_cell_wrap_0(cell_wrap_0 *pStruct);

extern void emxInit_char_T(emxArray_char_T **pEmxArray, int numDimensions);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (soilpropertiestree_trial3_emxutil.h) */
