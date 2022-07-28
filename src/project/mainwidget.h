#ifndef SRC_PROJECT_MAINWIDGET_H_
#define SRC_PROJECT_MAINWIDGET_H_

#include <math.h>

#include <QBasicTimer>
#include <QColor>
#include <QDir>
#include <QFileDialog>
#include <QFileInfo>
#include <QMainWindow>
#include <QMatrix4x4>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QOpenGLWidget>
#include <QQuaternion>
#include <QTimer>
#include <QVector2D>

#include "qgifimage.h"

class GeometryEngine;

typedef struct settings {
  QColor background_settings;
  QColor lines_color_settings;
  QColor vert_color_settings;
  int type_of_edges;
  int type_of_vertices;
  int flag_proect;
  float size_of_vertices;
  float thickness_of_lines;
} set;

#include "geometryengine.h"

class MainWidget : public QOpenGLWidget, protected QOpenGLFunctions {
  Q_OBJECT

 public:
  using QOpenGLWidget::QOpenGLWidget;
  GeometryEngine *geometries = nullptr;
  void setSetting(settings *new_setting);
  ~MainWidget();
  void paintGL() override;
  void resizeGL(int w, int h) override;

 protected:
  void initializeGL() override;
  void initShaders();

 private:
  QOpenGLShaderProgram program;
  QMatrix4x4 projection;
  settings *wdg_setting;
  int lines_color_location;
};

#endif  // SRC_PROJECT_MAINWIDGET_H_
