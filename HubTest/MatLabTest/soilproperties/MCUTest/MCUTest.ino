// #include "soilpropertiestree_trial1.h"
// #include "CompactClassificationTree.h"
#include "rt_nonfinite.h"
// #include "rt_nonfinite.c"
// #include "soilpropertiestree_trial1_data.h"
// #include "soilpropertiestree_trial1_data.c"
// #include "soilpropertiestree_trial1_initialize.h"
// #include "soilpropertiestree_trial1_initialize.c"
// #include "soilpropertiestree_trial1_types.h"
#include "rtGetNaN.h"
// #include "rtGetNaN.c"
#include "rtGetInf.h"
// #include "rtGetInf.c"
// #include "CompactClassificationTree.c"

#include "rtwtypes.h"

// /* Type Definitions */
// #ifndef struct_emxArray_char_T_1x4
#define struct_emxArray_char_T_1x4
struct emxArray_char_T_1x4 {
  char data[4];
  int size[2];
};
// #endif /* struct_emxArray_char_T_1x4 */
// #ifndef typedef_emxArray_char_T_1x4
// #define typedef_emxArray_char_T_1x4
// typedef struct emxArray_char_T_1x4 emxArray_char_T_1x4;
// #endif /* typedef_emxArray_char_T_1x4 */

// #ifndef typedef_cell_wrap_0
#define typedef_cell_wrap_0
typedef struct {
  emxArray_char_T_1x4 f1;
} cell_wrap_0;
// #endif /* typedef_cell_wrap_0 */




boolean_T isInitialized_soilpropertiestree_trial1_static = false;

void soilpropertiestree_trial1_initialize(void)
{
  rt_InitInfAndNaN();
  isInitialized_soilpropertiestree_trial1_static = true;
}

void soilpropertiestree_trial1_terminate(void)
{
  /* (no terminate code required) */
  isInitialized_soilpropertiestree_trial1_static = false;
}

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
  Serial.println(labels->f1.data);
}


/* Function Definitions */
void soilpropertiestree_trial1(double temperature, double rainfall,
                               double nitrogen, cell_wrap_0 yield[1])
{
  static const double mdl_Children[34] = {
      2.0,  3.0,  0.0,  0.0,  4.0, 5.0, 6.0, 7.0, 8.0,  9.0,  0.0,  0.0,
      10.0, 11.0, 12.0, 13.0, 0.0, 0.0, 0.0, 0.0, 14.0, 15.0, 16.0, 17.0,
      0.0,  0.0,  0.0,  0.0,  0.0, 0.0, 0.0, 0.0, 0.0,  0.0};
  static const double mdl_ClassProbability[34] = {0.65030674846625758,
                                                  1.0,
                                                  0.46226415094339618,
                                                  0.81081081081081074,
                                                  0.27536231884057982,
                                                  0.94736842105263153,
                                                  0.66666666666666674,
                                                  0.16666666666666669,
                                                  1.0,
                                                  1.0,
                                                  0.50000000000000011,
                                                  0.074074074074074084,
                                                  1.0,
                                                  0.0,
                                                  1.0,
                                                  0.0,
                                                  1.0,
                                                  0.34969325153374242,
                                                  0.0,
                                                  0.53773584905660377,
                                                  0.18918918918918917,
                                                  0.72463768115942018,
                                                  0.05263157894736839,
                                                  0.33333333333333331,
                                                  0.83333333333333337,
                                                  0.0,
                                                  0.0,
                                                  0.5,
                                                  0.92592592592592582,
                                                  0.0,
                                                  1.0,
                                                  0.0,
                                                  1.0,
                                                  0.0};
  static const double mdl_CutPoint[17] = {
      25.0, 0.0,  2250.0, 1250.0, 4550.0, 0.0, 22.0, 55.0, 0.0,
      0.0,  35.0, 35.5,   0.0,    0.0,    0.0, 0.0,  0.0};
  static const double mdl_CutPredictorIndex[17] = {3.0, 0.0, 2.0, 2.0, 2.0, 0.0,
                                                   1.0, 3.0, 0.0, 0.0, 1.0, 1.0,
                                                   0.0, 0.0, 0.0, 0.0, 0.0};
  static const signed char iv[17] = {5, 0, 5, 1, 4, 0, 1, 3, 0,
                                     0, 1, 2, 0, 0, 0, 0, 0};
  static const char mdl_ClassNames[8] = {'b', 'g', 'a', 'o',
                                         'd', 'o', ' ', 'd'};
  static const boolean_T mdl_NanCutPoints[17] = {
      false, true,  false, false, false, true, false, false, true,
      true,  false, false, true,  true,  true, true,  true};
  double mdl_PruneList_data[17];
  double mdl_Cost[4];
  double b_temperature[3];
  int mdl_ClassNamesLength[2];
  int i;
  if (!isInitialized_soilpropertiestree_trial1_static) {
    soilpropertiestree_trial1_initialize();
  }
  mdl_ClassNamesLength[0] = 3;
  mdl_ClassNamesLength[1] = 4;
  for (i = 0; i < 17; i++) {
    mdl_PruneList_data[i] = iv[i];
  }
  mdl_Cost[0] = 0.0;
  mdl_Cost[1] = 1.0;
  mdl_Cost[2] = 1.0;
  mdl_Cost[3] = 0.0;
  b_temperature[0] = temperature;
  b_temperature[1] = rainfall;
  b_temperature[2] = nitrogen;
  c_CompactClassificationTree_pre(
      mdl_CutPredictorIndex, mdl_Children, mdl_CutPoint, mdl_PruneList_data,
      mdl_NanCutPoints, mdl_ClassNames, mdl_ClassNamesLength, mdl_Cost,
      mdl_ClassProbability, b_temperature, &yield[0]);
}


void setup() {
  Serial.begin(9600);
}

void loop() {
  cell_wrap_0 test;
  int temperature = 20;
  Serial.println("Loop Start!");
  for (int i=0; i<20; i++){
    soilpropertiestree_trial1(temperature, 3000, 30, &test);
    Serial.println(temperature);
    temperature++;
    delay(1000);
  }
  Serial.println("Loop Done!");
}
