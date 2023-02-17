/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * CompactClassificationTree.c
 *
 * Code generation for function 'CompactClassificationTree'
 *
 */

/* Include files */
#include "CompactClassificationTree.h"
#include "rt_nonfinite.h"
#include "soilpropertiestree_trial1_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void c_CompactClassificationTree_pre(
    const double obj_CutPredictorIndex[17], const double obj_Children[34],
    const double obj_CutPoint[17], const double obj_PruneList_data[],
    const boolean_T obj_NanCutPoints[17], const char obj_ClassNames[8],
    const int obj_ClassNamesLength[2], const double obj_Cost[4],
    const double obj_ClassProbability[34], const double Xin[3],
    cell_wrap_0 *labels)
{
  double a__1_idx_0;
  double d;
  int i;
  int loop_ub;
  int m;
  boolean_T exitg1;
  m = 0;
  exitg1 = false;
  while (!(exitg1 || (obj_PruneList_data[m] <= 0.0))) {
    d = Xin[(int)obj_CutPredictorIndex[m] - 1];
    if (rtIsNaN(d) || obj_NanCutPoints[m]) {
      exitg1 = true;
    } else if (d < obj_CutPoint[m]) {
      m = (int)obj_Children[m << 1] - 1;
    } else {
      m = (int)obj_Children[(m << 1) + 1] - 1;
    }
  }
  d = obj_ClassProbability[m + 17];
  a__1_idx_0 = obj_ClassProbability[m] * obj_Cost[0] + d * obj_Cost[1];
  d = obj_ClassProbability[m] * obj_Cost[2] + d * obj_Cost[3];
  if ((a__1_idx_0 > d) || (rtIsNaN(a__1_idx_0) && (!rtIsNaN(d)))) {
    m = 1;
  } else {
    m = 0;
  }
  loop_ub = obj_ClassNamesLength[m];
  labels->f1.size[0] = 1;
  labels->f1.size[1] = obj_ClassNamesLength[m];
  for (i = 0; i < loop_ub; i++) {
    labels->f1.data[i] = obj_ClassNames[m + (i << 1)];
  }
}

/* End of code generation (CompactClassificationTree.c) */
