#include "mainwidget.h"

#include <QMouseEvent>
#include <cmath>

void MainWidget::setSetting(settings *new_setting) {
  wdg_setting = new_setting;
}

MainWidget::~MainWidget() {
  makeCurrent();
  delete geometries;
  doneCurrent();
}

void MainWidget::initializeGL() {
  initializeOpenGLFunctions();
  glClearColor(0.0, 0.0, 1.0, 0.0);
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  initShaders();

  geometries = new GeometryEngine;
}

void MainWidget::initShaders() {
  // Compile vertex shader
  if (!program.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/vshader.glsl"))
    close();

  // Compile fragment shader
  if (!program.addShaderFromSourceFile(QOpenGLShader::Fragment,
                                       ":/fshader.glsl"))
    close();

  // Link shader pipeline
  if (!program.link()) close();

  // Bind shader pipeline for use
  if (!program.bind()) close();
}

void MainWidget::resizeGL(int w, int h) {
  // Calculate aspect ratio
  qreal aspect = qreal(w) / qreal(h ? h : 1);

  // Set near plane to 0.1, far plane to 10000.0, field of view 70 degrees
  const qreal zNear = 0.1, zFar = 10000.0, fov = 70.0;
  // Reset projection
  projection.setToIdentity();

  // Set perspective projection
  if (wdg_setting->flag_proect == 0) {
    projection.perspective(fov, aspect, zNear, zFar);
  } else {
    projection.ortho(-aspect, aspect, -1.0, 1.0, zNear, zFar);
  }
}

void MainWidget::paintGL() {
  lines_color_location = 4;

  glClearColor(wdg_setting->background_settings.redF(),
               wdg_setting->background_settings.greenF(),
               wdg_setting->background_settings.blueF(),
               wdg_setting->background_settings.alphaF());
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Calculate model view transformation
  QMatrix4x4 matrix;
  matrix.translate(0.0, 0.0, -5.0);

  // Set modelview-projection matrix
  program.setUniformValue("mvp_matrix", projection * matrix);

  // Draw lines
  if (wdg_setting->type_of_edges == 0) {
    glDisable(GL_LINE_STIPPLE);
    glEnable(GL_LINES);
  }
  if (wdg_setting->type_of_edges == 1) {
    glLineStipple(5, 0x00FF);
    glEnable(GL_LINE_STIPPLE);
  }

  // Draw dots
  if (wdg_setting->type_of_vertices == 0) {
    glDisable(GL_POINT_SMOOTH);
    geometries->flagpoint = 0;
  }
  if (wdg_setting->type_of_vertices == 1 ||
      wdg_setting->type_of_vertices == 2) {
    if (wdg_setting->type_of_vertices == 1) {
      glEnable(GL_POINT_SMOOTH);
    } else {
      glDisable(GL_POINT_SMOOTH);
    }
    glPointSize(wdg_setting->size_of_vertices);
    geometries->flagpoint = 1;
    glUniform4f(lines_color_location, wdg_setting->vert_color_settings.redF(),
                wdg_setting->vert_color_settings.greenF(),
                wdg_setting->vert_color_settings.blueF(),
                wdg_setting->vert_color_settings.alphaF());
    geometries->drawCubeGeometry(&program);
    geometries->first_ris = 1;
  }

  glLineWidth(wdg_setting->thickness_of_lines);
  glUniform4f(lines_color_location, wdg_setting->lines_color_settings.redF(),
              wdg_setting->lines_color_settings.greenF(),
              wdg_setting->lines_color_settings.blueF(),
              wdg_setting->lines_color_settings.alphaF());
  // Draw cube geometry
  geometries->drawCubeGeometry(&program);
  geometries->first_ris = 0;
}
