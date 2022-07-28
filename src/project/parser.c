#include "parser.h"

int first_opening(char* file_name, counts* count) {
  int error = 0;
  FILE* obj_file = fopen(file_name, "r");
  size_t len;
  char* file_line = NULL;
  char* residue = NULL;

  while (getline(&file_line, &len, obj_file) != EOF) {
    if (file_line[0] == 'v' && file_line[1] == ' ') {
      count->count_of_vertexes++;
    } else if (file_line[0] == 'f' && file_line[1] == ' ') {
      strtok_r(file_line, " ", &residue);
      while (residue != NULL) {
        count->count_of_facets++;
        strtok_r(residue, " ", &residue);
      }
    }
  }
  if (file_line != NULL) free(file_line);
  fclose(obj_file);

  return error;
}

void second_opening(char* file_name, dot* data, int* poligon, counts* count,
                    int* pre_indices) {
  FILE* obj_file = fopen(file_name, "r");
  int a = 0, i = 0, previous;
  double buf = 0;
  size_t len;
  char* file_line = NULL;
  char* residue = NULL;

  while (getline(&file_line, &len, obj_file) != EOF) {
    if (data == NULL || poligon == NULL || pre_indices == NULL) {
      break;
    }
    if (file_line[0] == 'v' && file_line[1] == ' ') {
      strtok_r(file_line, " ", &residue);
      sscanf(residue, "%lf%lf%lf", &data[i].x, &data[i].y, &data[i].z);
      i++;
    }
    if (file_line[0] == 'f' && file_line[1] == ' ') {
      strtok_r(file_line, " ", &residue);
      previous = a;
      int sym = 0, h = 0;
      while (residue[sym] != '\n') {
        if (isdigit(residue[sym])) {
          buf = strtod(residue + sym, &residue);
          h = buf;
          count->count_of_facets_in_line++;
          sym = 0;
          poligon[a] = h - 1;
          a++;
          continue;
        }
        if (residue[sym] == '/') {
          strtok_r(residue, " ", &residue);
          if (residue == NULL) residue = "\n";
          continue;
        }
        sym++;
      }
      strtok_r(residue, " ", &residue);
      new_indices(pre_indices, poligon, count, previous);
      count->count_of_facets_in_line = 0;
      if ((!residue || residue[0] == '\r') && obj_file != NULL) continue;
    }
  }
  if (file_line != NULL) free(file_line);

  fclose(obj_file);
}

void new_indices(int* pre_indices, const int* poligon, counts* count,
                 int previous) {
  int was = 0;
  int k = previous * 2;
  int first_poligon_in_line = 0;

  for (int i = previous; i <= count->count_of_facets_in_line + previous; i++) {
    if (!was) {
      first_poligon_in_line = poligon[i];
      pre_indices[k] = poligon[i];
      k++;
      was++;
    } else if (was < count->count_of_facets_in_line) {
      pre_indices[k] = poligon[i];
      k++;
      pre_indices[k] = poligon[i];
      k++;
      was++;
    } else {
      pre_indices[k] = first_poligon_in_line;
      k++;
      was = 0;
    }
  }
}
