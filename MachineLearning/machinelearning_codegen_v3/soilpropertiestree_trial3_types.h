/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * soilpropertiestree_trial3_types.h
 *
 * Code generation for function 'soilpropertiestree_trial3'
 *
 */

#ifndef SOILPROPERTIESTREE_TRIAL3_TYPES_H
#define SOILPROPERTIESTREE_TRIAL3_TYPES_H

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef struct_emxArray_char_T
#define struct_emxArray_char_T
struct emxArray_char_T {
  char *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_char_T */
#ifndef typedef_emxArray_char_T
#define typedef_emxArray_char_T
typedef struct emxArray_char_T emxArray_char_T;
#endif /* typedef_emxArray_char_T */

#ifndef typedef_cell_wrap_0
#define typedef_cell_wrap_0
typedef struct {
  emxArray_char_T *f1;
} cell_wrap_0;
#endif /* typedef_cell_wrap_0 */

#endif
/* End of code generation (soilpropertiestree_trial3_types.h) */
