#ifndef SRC_PROJECT_AFFINE_TRANSFORMATIONS_H_
#define SRC_PROJECT_AFFINE_TRANSFORMATIONS_H_
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"

void parser(char *file_name, dot *data, counts *count, int *poligon);
void sdvigpo_X(dot *rez, double sdvig_x, counts *count);
void sdvigpo_Y(dot *rez, double sdvig_y, counts *count);
void sdvigpo_Z(dot *rez, double sdvig_z, counts *count);
void scaling_X(dot *rez, double scal_x, counts *count);
void scaling_Y(dot *rez, double scal_y, counts *count);
void scaling_Z(dot *rez, double scal_z, counts *count);
void povorot_X(dot *rez, double gradus, counts *count);
void povorot_Y(dot *rez, double gradus, counts *count);
void povorot_Z(dot *rez, double gradus, counts *count);

#endif /* SRC_PROJECT_AFFINE_TRANSFORMATIONS_H_*/
