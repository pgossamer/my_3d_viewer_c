#ifndef SRC_PROJECT_MAINWINDOW_H_

#define SRC_PROJECT_MAINWINDOW_H_

#include <QMainWindow>
#include <QColorDialog>

#include "mainwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(settings *new_setting,
  QWidget *parent = nullptr);
  ~MainWindow();
  int *pre_indices = nullptr;
  counts count = {0, 0, 0, 0, 0};
  double *arr_coordinats = nullptr;
  dot *rez = nullptr;
  settings *settin = nullptr;
  double old_value_s_x = 0;
  double old_value_s_y = 0;
  double old_value_s_z = 0;

  int old_value_p_x = 0;
  int old_value_p_y = 0;
  int old_value_p_z = 0;

  double old_value_sl_x = 1;
  double old_value_sl_y = 1;
  double old_value_sl_z = 1;

  int flag = 0;

  QTimer *timer;
  int screenshots_count;
  QGifImage *gif;

 public slots:
  void make_gif();

 private slots:
  void on_open_file_clicked();
  void update_value_coord();
  void record_in_file(set* setting);

  void obnull();

  void install_set(set * setting);
  void on_translate_down_x_clicked();
  void on_translate_up_x_clicked();
  void on_translate_spinBox_x_editingFinished();
  void on_translate_down_y_clicked();
  void on_translate_up_y_clicked();
  void on_translate_spinBox_y_editingFinished();
  void on_translate_down_z_clicked();
  void on_translate_up_z_clicked();
  void on_translate_spinBox_z_editingFinished();

  void on_rotate_down_x_clicked();
  void on_rotate_up_x_clicked();
  void on_rotate_spinBox_x_editingFinished();
  void on_rotate_down_y_clicked();
  void on_rotate_up_y_clicked();
  void on_rotate_spinBox_y_editingFinished();
  void on_rotate_down_z_clicked();
  void on_rotate_up_z_clicked();
  void on_rotate_spinBox_z_editingFinished();

  void on_scale_down_x_clicked();
  void on_scale_up_x_clicked();
  void on_scale_spinBox_x_editingFinished();
  void on_scale_down_y_clicked();
  void on_scale_up_y_clicked();
  void on_scale_spinBox_y_editingFinished();
  void on_scale_down_z_clicked();
  void on_scale_up_z_clicked();
  void on_scale_spinBox_z_editingFinished();

  void on_printscreen_button_pressed();
  void on_gif_button_pressed();

  void on_comboBox_type_of_edges_activated(int index);
  void on_comboBox_type_of_vertices_activated(int index);
  void on_pushButton_color_of_background_clicked();
  void on_comboBox_projection_activated(int index);
  void on_pushButton_color_of_edges_clicked();

  void on_comboBox_vertice_size_activated(int index);

  void on_comboBox_edges_thickness_activated(int index);

  void on_pushButton_color_of_vertices_clicked();

 private:
  Ui::MainWindow * ui;
};

void new_coordinat(dot *rez, double *arr_coordinats, counts count);
double slider_to_spinbox(int value);
int spinbox_to_slider(double arg1);

#endif  // SRC_PROJECT_MAINWINDOW_H_
