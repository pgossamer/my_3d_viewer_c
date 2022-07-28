#include "geometryengine.h"

#include <QDebug>
#include <QFile>
#include <QVector2D>
#include <QVector3D>
#include <iostream>

struct VertexData {
  QVector3D position;
};

GeometryEngine::GeometryEngine() : indexBuf(QOpenGLBuffer::IndexBuffer) {
  initializeOpenGLFunctions();

  // Generate 2 VBOs
  arrayBuf.create();
  indexBuf.create();
}

GeometryEngine::~GeometryEngine() {
  arrayBuf.destroy();
  indexBuf.destroy();
}

void GeometryEngine::initCubeGeometry(int *pre_indices,
                                      double *arr_coordinats) {
  // Transfer vertex data to VBO 0
  arrayBuf.bind();
  arrayBuf.allocate(arr_coordinats,
                    (count.count_of_vertexes) * 3 * sizeof(double));

  // Transfer index data to VBO 1
  indexBuf.bind();
  indexBuf.allocate(pre_indices, (count.count_of_facets) * 2 * sizeof(int));
}

void GeometryEngine::drawCubeGeometry(QOpenGLShaderProgram *program) {
  // Tell OpenGL which VBOs to use
  arrayBuf.bind();
  indexBuf.bind();
  lines_color_location = 4;
  // Offset for position
  quintptr offset = 0;

  // Tell OpenGL programmable pipeline how to locate vertex position data
  int vertexLocation = program->attributeLocation("a_position");
  program->enableAttributeArray(vertexLocation);
  program->setAttributeBuffer(vertexLocation, GL_DOUBLE, offset, 3,
                              sizeof(double) * 3);

  // Draw cube geometry using indices from VBO 1
  if (count.count_of_facets != 0) {
    if (flagpoint == 1 && first_ris == 0) {
      glDrawElements(GL_POINTS, (count.count_of_facets) * 2, GL_UNSIGNED_INT,
                     nullptr);
    }

    glDrawElements(GL_LINES, (count.count_of_facets) * 2, GL_UNSIGNED_INT,
                   nullptr);
  }
}
