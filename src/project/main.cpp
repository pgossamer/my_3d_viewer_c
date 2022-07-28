#include <QApplication>
#include <QLabel>
#include <QSurfaceFormat>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  struct settings new_setting;
  new_setting.background_settings.setRgbF(1.0, 1.0, 1.0, 1.0);
  MainWindow w(&new_setting);
  w.show();
  return app.exec();
}
