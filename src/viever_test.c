#include <check.h>

#include "project/affine_transformations.h"

START_TEST(test_1_pars_file) {
  dot *rez;
  counts count;
  memset(&count, 0, sizeof(count));
  int *poligon;
  int *pre_ind;
  char *file_name = "./objectives/cube.obj";
  first_opening(file_name, &count);
  rez = (dot *)calloc(count.count_of_vertexes, sizeof(dot));
  poligon = (int *)calloc(count.count_of_facets, sizeof(int));
  pre_ind = (int *)calloc(count.count_of_facets * 2, sizeof(int));
  second_opening(file_name, rez, poligon, &count, pre_ind);
  ck_assert_int_eq(count.count_of_facets, 36);
  ck_assert_int_eq(count.count_of_vertexes, 8);
  free(poligon);
  free(rez);
  free(pre_ind);
}
END_TEST

START_TEST(test_1_sdvig_x) {
  dot *rez;
  counts count;
  memset(&count, 0, sizeof(count));
  int *poligon;
  int *pre_ind;
  char *file_name = "./objectives/cube.obj";
  first_opening(file_name, &count);
  rez = (dot *)calloc(count.count_of_vertexes, sizeof(dot));
  poligon = (int *)calloc(count.count_of_facets, sizeof(int));
  pre_ind = (int *)calloc(count.count_of_facets * 2, sizeof(int));
  second_opening(file_name, rez, poligon, &count, pre_ind);
  for (int i = 0; i < count.count_of_vertexes; i++) {
    double k = 1.2, b = 0;
    b = rez[i].x + k;
    sdvigpo_X(rez, k, &count);
    ck_assert_float_eq(rez[i].x, b);
  }
  free(poligon);
  free(rez);
  free(pre_ind);
}
END_TEST

START_TEST(test_1_sdvig_y) {
  dot *rez;
  counts count;
  memset(&count, 0, sizeof(count));
  int *poligon;
  int *pre_ind;
  char *file_name = "./objectives/cube.obj";
  first_opening(file_name, &count);
  rez = (dot *)calloc(count.count_of_vertexes, sizeof(dot));
  poligon = (int *)calloc(count.count_of_facets, sizeof(int));
  pre_ind = (int *)calloc(count.count_of_facets * 2, sizeof(int));
  second_opening(file_name, rez, poligon, &count, pre_ind);
  for (int i = 0; i < count.count_of_vertexes; i++) {
    double k = 0.35, b = 0;
    b = rez[i].y + k;
    sdvigpo_Y(rez, k, &count);
    ck_assert_float_eq(rez[i].y, b);
  }
  free(poligon);
  free(rez);
  free(pre_ind);
}
END_TEST

START_TEST(test_1_sdvig_z) {
  dot *rez;
  counts count;
  memset(&count, 0, sizeof(count));
  int *poligon;
  int *pre_ind;
  char *file_name = "./objectives/cube.obj";
  first_opening(file_name, &count);
  rez = (dot *)calloc(count.count_of_vertexes, sizeof(dot));
  poligon = (int *)calloc(count.count_of_facets, sizeof(int));
  pre_ind = (int *)calloc(count.count_of_facets * 2, sizeof(int));
  second_opening(file_name, rez, poligon, &count, pre_ind);
  for (int i = 0; i < count.count_of_vertexes; i++) {
    double k = 0.197, b = 0;
    b = rez[i].z + k;
    sdvigpo_Z(rez, k, &count);
    ck_assert_float_eq(rez[i].z, b);
  }
  free(poligon);
  free(rez);
  free(pre_ind);
}
END_TEST

START_TEST(test_1_scaling_x) {
  dot *rez;
  counts count;
  memset(&count, 0, sizeof(count));
  int *poligon;
  int *pre_ind;
  char *file_name = "./objectives/cube.obj";
  first_opening(file_name, &count);
  rez = (dot *)calloc(count.count_of_vertexes, sizeof(dot));
  poligon = (int *)calloc(count.count_of_facets, sizeof(int));
  pre_ind = (int *)calloc(count.count_of_facets * 2, sizeof(int));
  second_opening(file_name, rez, poligon, &count, pre_ind);
  for (int i = 0; i < count.count_of_vertexes; i++) {
    double k = 3.2, b = 0;
    b = rez[i].x * k;
    scaling_X(rez, k, &count);
    ck_assert_float_eq(rez[i].x, b);
  }
  free(poligon);
  free(rez);
  free(pre_ind);
}
END_TEST

START_TEST(test_1_scaling_y) {
  dot *rez;
  counts count;
  memset(&count, 0, sizeof(count));
  int *poligon;
  int *pre_ind;
  char *file_name = "./objectives/cube.obj";
  first_opening(file_name, &count);
  rez = (dot *)calloc(count.count_of_vertexes, sizeof(dot));
  poligon = (int *)calloc(count.count_of_facets, sizeof(int));
  pre_ind = (int *)calloc(count.count_of_facets * 2, sizeof(int));
  second_opening(file_name, rez, poligon, &count, pre_ind);
  for (int i = 0; i < count.count_of_vertexes; i++) {
    double k = -1.76, b = 0;
    b = rez[i].y * k;
    scaling_Y(rez, k, &count);
    ck_assert_float_eq(rez[i].y, b);
  }
  free(poligon);
  free(rez);
  free(pre_ind);
}
END_TEST

START_TEST(test_1_scaling_z) {
  dot *rez;
  counts count;
  memset(&count, 0, sizeof(count));
  int *poligon;
  int *pre_ind;
  char *file_name = "./objectives/cube.obj";
  first_opening(file_name, &count);
  rez = (dot *)calloc(count.count_of_vertexes, sizeof(dot));
  poligon = (int *)calloc(count.count_of_facets, sizeof(int));
  pre_ind = (int *)calloc(count.count_of_facets * 2, sizeof(int));
  second_opening(file_name, rez, poligon, &count, pre_ind);
  for (int i = 0; i < count.count_of_vertexes; i++) {
    double k = 0.13, b = 0;
    b = rez[i].z * k;
    scaling_Z(rez, k, &count);
    ck_assert_float_eq(rez[i].z, b);
  }
  free(poligon);
  free(rez);
  free(pre_ind);
}
END_TEST

START_TEST(test_1_povorot_x) {
  dot *rez;
  counts count;
  memset(&count, 0, sizeof(count));
  int *poligon;
  int *pre_ind;
  char *file_name = "./objectives/cube.obj";
  first_opening(file_name, &count);
  rez = (dot *)calloc(count.count_of_vertexes, sizeof(dot));
  poligon = (int *)calloc(count.count_of_facets, sizeof(int));
  pre_ind = (int *)calloc(count.count_of_facets * 2, sizeof(int));
  second_opening(file_name, rez, poligon, &count, pre_ind);
  for (int i = 0; i < count.count_of_vertexes; i++) {
    double k = 0.13, b_y = 0, b_z = 0;
    double temp_y = 0, temp_z = 0;
    temp_y = rez[i].y;
    temp_z = rez[i].z;
    b_y = cos(k) * temp_y - sin(k) * temp_z;
    b_z = sin(k) * temp_y + cos(k) * temp_z;
    povorot_X(rez, k, &count);
    ck_assert_float_eq(rez[i].y, b_y);
    ck_assert_float_eq(rez[i].z, b_z);
  }
  free(poligon);
  free(rez);
  free(pre_ind);
}
END_TEST

START_TEST(test_1_povorot_y) {
  dot *rez;
  counts count;
  memset(&count, 0, sizeof(count));
  int *poligon;
  int *pre_ind;
  char *file_name = "./objectives/cube.obj";
  first_opening(file_name, &count);
  rez = (dot *)calloc(count.count_of_vertexes, sizeof(dot));
  poligon = (int *)calloc(count.count_of_facets, sizeof(int));
  pre_ind = (int *)calloc(count.count_of_facets * 2, sizeof(int));
  second_opening(file_name, rez, poligon, &count, pre_ind);
  for (int i = 0; i < count.count_of_vertexes; i++) {
    double k = 0.13, b_x = 0, b_z = 0;
    double temp_x = 0, temp_z = 0;
    temp_x = rez[i].x;
    temp_z = rez[i].z;
    b_x = cos(k) * temp_x + sin(k) * temp_z;
    b_z = -sin(k) * temp_x + cos(k) * temp_z;
    povorot_Y(rez, k, &count);
    ck_assert_float_eq(rez[i].x, b_x);
    ck_assert_float_eq(rez[i].z, b_z);
  }
  free(poligon);
  free(rez);
  free(pre_ind);
}
END_TEST

START_TEST(test_1_povorot_z) {
  dot *rez;
  counts count;
  memset(&count, 0, sizeof(count));
  int *poligon;
  int *pre_ind;
  char *file_name = "./objectives/cube.obj";
  first_opening(file_name, &count);
  rez = (dot *)calloc(count.count_of_vertexes, sizeof(dot));
  poligon = (int *)calloc(count.count_of_facets, sizeof(int));
  pre_ind = (int *)calloc(count.count_of_facets * 2, sizeof(int));
  second_opening(file_name, rez, poligon, &count, pre_ind);
  for (int i = 0; i < count.count_of_vertexes; i++) {
    double k = 0.13, b_x = 0, b_y = 0;
    double temp_x = 0, temp_y = 0;
    temp_x = rez[i].x;
    temp_y = rez[i].y;
    b_x = cos(k) * temp_x - sin(k) * temp_y;
    b_y = sin(k) * temp_x + cos(k) * temp_y;
    povorot_Z(rez, k, &count);
    ck_assert_float_eq(rez[i].x, b_x);
    ck_assert_float_eq(rez[i].y, b_y);
  }
  free(poligon);
  free(rez);
  free(pre_ind);
}
END_TEST

int main() {
  Suite *s1 = suite_create("Suite");
  SRunner *sr = srunner_create(s1);
  int nf;

  TCase *tc1_1 = tcase_create("tests");
  suite_add_tcase(s1, tc1_1);

  tcase_add_test(tc1_1, test_1_pars_file);

  tcase_add_test(tc1_1, test_1_sdvig_x);
  tcase_add_test(tc1_1, test_1_sdvig_y);
  tcase_add_test(tc1_1, test_1_sdvig_z);

  tcase_add_test(tc1_1, test_1_scaling_x);
  tcase_add_test(tc1_1, test_1_scaling_y);
  tcase_add_test(tc1_1, test_1_scaling_z);

  tcase_add_test(tc1_1, test_1_povorot_x);
  tcase_add_test(tc1_1, test_1_povorot_y);
  tcase_add_test(tc1_1, test_1_povorot_z);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
