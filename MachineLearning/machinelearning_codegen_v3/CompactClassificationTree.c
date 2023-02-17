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
#include "soilpropertiestree_trial3_emxutil.h"
#include "soilpropertiestree_trial3_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void c_CompactClassificationTree_pre(
    const double obj_CutPredictorIndex[77], const double obj_Children[154],
    const double obj_CutPoint[77], const double obj_PruneList_data[],
    const boolean_T obj_NanCutPoints[77], const char obj_ClassNames[630],
    const int obj_ClassNamesLength[10], const double obj_Cost[100],
    const double obj_ClassProbability[770], const double Xin[5],
    cell_wrap_0 *labels)
{
  double a__1[10];
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
  for (i = 0; i < 10; i++) {
    d = 0.0;
    for (idx = 0; idx < 10; idx++) {
      d += obj_ClassProbability[m + 77 * idx] * obj_Cost[idx + 10 * i];
    }
    a__1[i] = d;
  }
  if (!rtIsNaN(a__1[0])) {
    idx = 1;
  } else {
    idx = 0;
    m = 2;
    exitg1 = false;
    while ((!exitg1) && (m < 11)) {
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
    for (m = i; m < 11; m++) {
      d = a__1[m - 1];
      if (ex > d) {
        ex = d;
        idx = m;
      }
    }
  }
  m = obj_ClassNamesLength[idx - 1];
  i = labels->f1->size[0] * labels->f1->size[1];
  labels->f1->size[0] = 1;
  labels->f1->size[1] = m;
  emxEnsureCapacity_char_T(labels->f1, i);
  for (i = 0; i < m; i++) {
    labels->f1->data[i] = obj_ClassNames[(idx + 10 * i) - 1];
  }
}

/* End of code generation (CompactClassificationTree.c) */
