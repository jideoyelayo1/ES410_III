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
#include "soilpropertiestree_trial2_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void c_CompactClassificationTree_pre(
    const double obj_CutPredictorIndex[17], const double obj_Children[34],
    const double obj_CutPoint[17], const double obj_PruneList_data[],
    const boolean_T obj_NanCutPoints[17], const char obj_ClassNames[63],
    const int obj_ClassNamesLength[3], const double obj_Cost[9],
    const double obj_ClassProbability[51], const double Xin[5],
    cell_wrap_0 *labels)
{
  double a__1[3];
  double d;
  double ex;
  int i;
  int idx;
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
  for (i = 0; i < 3; i++) {
    a__1[i] = (obj_ClassProbability[m] * obj_Cost[3 * i] +
               obj_ClassProbability[m + 17] * obj_Cost[3 * i + 1]) +
              obj_ClassProbability[m + 34] * obj_Cost[3 * i + 2];
  }
  if (!rtIsNaN(a__1[0])) {
    idx = 1;
  } else {
    idx = 0;
    m = 2;
    exitg1 = false;
    while ((!exitg1) && (m < 4)) {
      if (!rtIsNaN(a__1[m - 1])) {
        idx = m;
        exitg1 = true;
      } else {
        m++;
      }
    }
  }
  if (idx == 0) {
    idx = 1;
  } else {
    ex = a__1[idx - 1];
    i = idx + 1;
    for (m = i; m < 4; m++) {
      d = a__1[m - 1];
      if (ex > d) {
        ex = d;
        idx = m;
      }
    }
  }
  m = obj_ClassNamesLength[idx - 1];
  labels->f1.size[0] = 1;
  labels->f1.size[1] = m;
  for (i = 0; i < m; i++) {
    labels->f1.data[i] = obj_ClassNames[(idx + 3 * i) - 1];
  }
}

/* End of code generation (CompactClassificationTree.c) */
