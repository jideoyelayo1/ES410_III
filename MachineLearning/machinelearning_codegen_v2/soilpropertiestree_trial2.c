/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * soilpropertiestree_trial2.c
 *
 * Code generation for function 'soilpropertiestree_trial2'
 *
 */

/* Include files */
#include "soilpropertiestree_trial2.h"
#include "CompactClassificationTree.h"
#include "rt_nonfinite.h"
#include "soilpropertiestree_trial2_data.h"
#include "soilpropertiestree_trial2_initialize.h"
#include "soilpropertiestree_trial2_types.h"

/* Function Definitions */
void soilpropertiestree_trial2(double temperature, double humidity,
                               double nitrogen, double phosphorus,
                               double potassium, cell_wrap_0 fertilise[1])
{
  static const double mdl_ClassProbability[51] = {0.37076271186440679,
                                                  0.0,
                                                  0.46542553191489355,
                                                  0.96153846153846145,
                                                  0.27573529411764708,
                                                  1.0,
                                                  0.0,
                                                  0.81300813008130057,
                                                  0.11876484560570086,
                                                  1.0,
                                                  0.0,
                                                  0.84745762711864392,
                                                  0.0,
                                                  1.0,
                                                  0.0,
                                                  0.0,
                                                  0.0,
                                                  0.37076271186440679,
                                                  0.0,
                                                  0.46542553191489355,
                                                  0.0,
                                                  0.64338235294117629,
                                                  0.0,
                                                  0.0,
                                                  0.0,
                                                  0.83135391923990476,
                                                  0.0,
                                                  0.0,
                                                  0.0,
                                                  0.96685082872928163,
                                                  0.0,
                                                  0.0,
                                                  1.0,
                                                  0.0,
                                                  0.25847457627118647,
                                                  1.0,
                                                  0.069148936170212866,
                                                  0.03846153846153854,
                                                  0.080882352941176586,
                                                  0.0,
                                                  1.0,
                                                  0.18699186991869951,
                                                  0.049881235154394417,
                                                  0.0,
                                                  1.0,
                                                  0.15254237288135605,
                                                  0.033149171270718314,
                                                  0.0,
                                                  1.0,
                                                  0.0,
                                                  1.0};
  static const double mdl_Children[34] = {
      2.0,  3.0,  0.0,  0.0,  4.0,  5.0,  6.0, 7.0, 8.0, 9.0, 0.0,  0.0,
      0.0,  0.0,  10.0, 11.0, 12.0, 13.0, 0.0, 0.0, 0.0, 0.0, 14.0, 15.0,
      16.0, 17.0, 0.0,  0.0,  0.0,  0.0,  0.0, 0.0, 0.0, 0.0};
  static const double mdl_CutPoint[17] = {58.0, 0.0,  4.5,  38.5, 16.5, 0.0,
                                          0.0,  38.5, 5.25, 0.0,  0.0,  38.5,
                                          38.5, 0.0,  0.0,  0.0,  0.0};
  static const double mdl_CutPredictorIndex[17] = {2.0, 0.0, 5.0, 1.0, 3.0, 0.0,
                                                   0.0, 1.0, 4.0, 0.0, 0.0, 1.0,
                                                   1.0, 0.0, 0.0, 0.0, 0.0};
  static const int mdl_ClassNamesLength[3] = {14, 20, 21};
  static const char mdl_ClassNames[63] = {
      'A', 'D', 'U', 'd', 'o', 'n', 'd', 'n', 's', ' ', '\'', 'u', 'f',
      't', 'i', 'e', ' ', 't', 'r', 'a', 'a', 't', 'd', 'b',  'i', 'd',
      'l', 'l', ' ', 'e', 'i', 'f', ' ', 's', 'e', 'f', 'e',  'r', 'o',
      'r', 't', 'r', ' ', 'i', ' ', ' ', 'l', 'g', ' ', 'i',  'r', ' ',
      's', 'o', ' ', 'e', 'w', ' ', 'r', 't', ' ', ' ', 'h'};
  static const signed char iv[17] = {7, 0, 7, 1, 6, 0, 0, 4, 5,
                                     0, 0, 2, 3, 0, 0, 0, 0};
  static const boolean_T mdl_NanCutPoints[17] = {
      false, true, false, false, false, true, true, false, false,
      true,  true, false, false, true,  true, true, true};
  double mdl_PruneList_data[17];
  double mdl_Cost[9];
  double b_temperature[5];
  int i;
  signed char b_I[9];
  if (!isInitialized_soilpropertiestree_trial2) {
    soilpropertiestree_trial2_initialize();
  }
  for (i = 0; i < 17; i++) {
    mdl_PruneList_data[i] = iv[i];
  }
  for (i = 0; i < 9; i++) {
    b_I[i] = 0;
  }
  b_I[0] = 1;
  b_I[4] = 1;
  b_I[8] = 1;
  for (i = 0; i < 9; i++) {
    mdl_Cost[i] = 1.0 - (double)b_I[i];
  }
  b_temperature[0] = temperature;
  b_temperature[1] = humidity;
  b_temperature[2] = nitrogen;
  b_temperature[3] = phosphorus;
  b_temperature[4] = potassium;
  c_CompactClassificationTree_pre(
      mdl_CutPredictorIndex, mdl_Children, mdl_CutPoint, mdl_PruneList_data,
      mdl_NanCutPoints, mdl_ClassNames, mdl_ClassNamesLength, mdl_Cost,
      mdl_ClassProbability, b_temperature, &fertilise[0]);
}

/* End of code generation (soilpropertiestree_trial2.c) */
