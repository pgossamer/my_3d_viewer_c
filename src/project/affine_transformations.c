#include "affine_transformations.h"

void sdvigpo_X(dot* rez, double sdvig_x, counts* count) {
  for (int i = 0; i < count->count_of_vertexes; i++)
    rez[i].x += sdvig_x;
}

void sdvigpo_Y(dot* rez, double sdvig_y, counts* count) {
  for (int i = 0; i < count->count_of_vertexes; i++)
    rez[i].y += sdvig_y;
}

void sdvigpo_Z(dot* rez, double sdvig_z, counts* count) {
  for (int i = 0; i < count->count_of_vertexes; i++)
    rez[i].z += sdvig_z;
}

void scaling_X(dot* rez, double scal_x, counts* count) {
  for (int i = 0; i < count->count_of_vertexes; i++)
    rez[i].x *= scal_x;
}

void scaling_Y(dot* rez, double scal_y, counts* count) {
  for (int i = 0; i < count->count_of_vertexes; i++)
    rez[i].y *= scal_y;
}

void scaling_Z(dot* rez, double scal_z, counts* count) {
  for (int i = 0; i < count->count_of_vertexes; i++)
    rez[i].z *= scal_z;
}

void povorot_X(dot* rez, double gradus, counts* count) {
  for (int i = 0; i < count->count_of_vertexes; i++) {
    double temp_y = rez[i].y;
    double temp_z = rez[i].z;
    rez[i].y = cos(gradus) * temp_y - sin(gradus) * temp_z;
    rez[i].z = sin(gradus) * temp_y + cos(gradus) * temp_z;
  }
}

void povorot_Y(dot* rez, double gradus, counts* count) {
  for (int i = 0; i < count->count_of_vertexes; i++) {
    double temp_x = rez[i].x;
    double temp_z = rez[i].z;
    rez[i].x = cos(gradus) * temp_x + sin(gradus) * temp_z;
    rez[i].z = -sin(gradus) * temp_x + cos(gradus) * temp_z;
  }
}

void povorot_Z(dot* rez, double gradus, counts* count) {
  for (int i = 0; i < count->count_of_vertexes; i++) {
    double temp_x = rez[i].x;
    double temp_y = rez[i].y;
    rez[i].x = cos(gradus) * temp_x - sin(gradus) * temp_y;
    rez[i].y = sin(gradus) * temp_x + cos(gradus) * temp_y;
  }
}
