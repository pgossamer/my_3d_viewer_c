#ifndef SRC_PROJECT_PARSER_H_
#define SRC_PROJECT_PARSER_H_

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct counts {
  int count_of_vertexes;
  int count_of_facets;
  int count_of_point_facets;
  int count_of_facets_in_line;
  int count_of_vertexes_in_line;
} counts;

typedef struct points {
  double x;
  double y;
  double z;
} dot;

int first_opening(char* file_name, counts* count);
int open_file(char* file_name, FILE** obj_file);
void second_opening(char* file_name, dot* points, int* poligon, counts* count,
                    int* pre_indices);
void new_indices(int* pre_indices, const int* poligon, counts* count, int previous);

#endif  // SRC_PROJECT_PARSER_H_
