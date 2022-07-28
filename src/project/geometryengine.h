#ifndef SRC_PROJECT_GEOMETRYENGINE_H_
#define SRC_PROJECT_GEOMETRYENGINE_H_

#include <QColor>
#include <QOpenGLBuffer>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
// #include "mainwidget.h"

extern "C" {
#include "affine_transformations.h"
#include "parser.h"
}

class GeometryEngine : protected QOpenGLFunctions {
 public:
  void initCubeGeometry(int *pre_indices, double *arr_coordinats);
  GeometryEngine();
  virtual ~GeometryEngine();
  void setcount(counts newcount) { count = newcount; }
  void drawCubeGeometry(QOpenGLShaderProgram *program);
  int flagpoint = 0;
  int first_ris = 0;

 private:
  counts count = {0, 0, 0, 0, 0};
  QOpenGLBuffer arrayBuf;
  QOpenGLBuffer indexBuf;
  int lines_color_location;
};

#endif  // SRC_PROJECT_GEOMETRYENGINE_H_
