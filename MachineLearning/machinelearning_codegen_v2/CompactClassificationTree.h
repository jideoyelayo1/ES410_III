/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * CompactClassificationTree.h
 *
 * Code generation for function 'CompactClassificationTree'
 *
 */

#ifndef COMPACTCLASSIFICATIONTREE_H
#define COMPACTCLASSIFICATIONTREE_H

/* Include files */
#include "rtwtypes.h"
#include "soilpropertiestree_trial2_types.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void c_CompactClassificationTree_pre(
    const double obj_CutPredictorIndex[17], const double obj_Children[34],
    const double obj_CutPoint[17], const double obj_PruneList_data[],
    const boolean_T obj_NanCutPoints[17], const char obj_ClassNames[63],
    const int obj_ClassNamesLength[3], const double obj_Cost[9],
    const double obj_ClassProbability[51], const double Xin[5],
    cell_wrap_0 *labels);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (CompactClassificationTree.h) */
