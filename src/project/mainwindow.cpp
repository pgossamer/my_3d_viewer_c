#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(settings *new_setting, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  install_set(new_setting);
  settin = new_setting;
  ui->setupUi(this);
  ui->openGLWidget->setSetting(settin);

  screenshots_count = 0;
  timer = new QTimer(this);
  gif = new QGifImage;
  connect(timer, SIGNAL(timeout()), this, SLOT(make_gif()));
}

MainWindow::~MainWindow() {
  delete ui;
  record_in_file(settin);
  free(rez);
  free(arr_coordinats);
  free(pre_indices);
}

void MainWindow::install_set(set *setting) {
  QString path = HOME_DIR "/Desktop/3DViewer_v1.0/setting.txt";
  QFile file(path);
  if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    QTextStream in(&file);
    QString line = in.readLine();
    double value = line.toDouble();
    setting->background_settings.setRedF(value);
    line = in.readLine();
    value = line.toDouble();
    setting->background_settings.setGreenF(value);
    line = in.readLine();
    value = line.toDouble();
    setting->background_settings.setBlueF(value);
    line = in.readLine();
    value = line.toDouble();
    setting->background_settings.setAlphaF(value);
    line = in.readLine();
    value = line.toDouble();
    setting->lines_color_settings.setRedF(value);
    line = in.readLine();
    value = line.toDouble();
    setting->lines_color_settings.setGreenF(value);
    line = in.readLine();
    value = line.toDouble();
    setting->lines_color_settings.setBlueF(value);
    line = in.readLine();
    value = line.toDouble();
    setting->lines_color_settings.setAlphaF(value);
    line = in.readLine();
    value = line.toDouble();
    setting->type_of_edges = value;
    line = in.readLine();
    value = line.toDouble();
    setting->type_of_vertices = value;
    line = in.readLine();
    value = line.toDouble();
    setting->flag_proect = value;
    line = in.readLine();
    value = line.toDouble();
    setting->size_of_vertices = value;
    line = in.readLine();
    value = line.toDouble();
    setting->thickness_of_lines = value;
    line = in.readLine();
    value = line.toDouble();
    setting->vert_color_settings.setRedF(value);
    line = in.readLine();
    value = line.toDouble();
    setting->vert_color_settings.setGreenF(value);
    line = in.readLine();
    value = line.toDouble();
    setting->vert_color_settings.setBlueF(value);
    line = in.readLine();
    value = line.toDouble();
    setting->vert_color_settings.setAlphaF(value);
    file.close();
  } else {
    setting->background_settings.setRedF(1);
    setting->background_settings.setGreenF(1);
    setting->background_settings.setBlueF(1);
    setting->background_settings.setAlphaF(1);
    setting->lines_color_settings.setRedF(0);
    setting->lines_color_settings.setGreenF(0);
    setting->lines_color_settings.setBlueF(0);
    setting->lines_color_settings.setAlphaF(1);
    setting->type_of_edges = 0;
    setting->type_of_vertices = 0;
    setting->flag_proect = 0;
    setting->size_of_vertices = 0;
    setting->thickness_of_lines = 0;
    setting->vert_color_settings.setRedF(0);
    setting->vert_color_settings.setGreenF(0);
    setting->vert_color_settings.setBlueF(0);
    setting->vert_color_settings.setAlphaF(1);

    QFile mFile(path);
  }
}

void MainWindow::record_in_file(set *setting) {
  QString path = HOME_DIR "/Desktop/3DViewer_v1.0/setting.txt";

  QFile file(path);
  if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
    QTextStream out(&file);
    QString back_color_r = QString::number(setting->background_settings.redF());
    QString back_color_g =
        QString::number(setting->background_settings.greenF());
    QString back_color_b =
        QString::number(setting->background_settings.blueF());
    QString back_color_a =
        QString::number(setting->background_settings.alphaF());
    QString line_color_r =
        QString::number(setting->lines_color_settings.redF());
    QString line_color_g =
        QString::number(setting->lines_color_settings.greenF());
    ;
    QString line_color_b =
        QString::number(setting->lines_color_settings.blueF());
    QString line_color_a =
        QString::number(setting->lines_color_settings.alphaF());
    QString vert_color_r = QString::number(setting->vert_color_settings.redF());
    QString vert_color_g =
        QString::number(setting->vert_color_settings.greenF());
    ;
    QString vert_color_b =
        QString::number(setting->vert_color_settings.blueF());
    QString vert_color_a =
        QString::number(setting->vert_color_settings.alphaF());
    QString type_edge = QString::number(setting->type_of_edges);
    QString type_vert = QString::number(setting->type_of_vertices);
    QString type_proect = QString::number(setting->flag_proect);
    QString size_vert = QString::number(setting->size_of_vertices);
    QString thickness_of_lines = QString::number(setting->thickness_of_lines);
    out << back_color_r << "\n"
        << back_color_g << "\n"
        << back_color_b << "\n"
        << back_color_a << "\n"
        << line_color_r << "\n"
        << line_color_g << "\n"
        << line_color_b << "\n"
        << line_color_a << "\n"
        << type_edge << "\n"
        << type_vert << "\n"
        << type_proect << "\n"
        << size_vert << "\n"
        << thickness_of_lines << "\n"
        << vert_color_r << "\n"
        << vert_color_g << "\n"
        << vert_color_b << "\n"
        << vert_color_a;

    file.close();
  }
}

void MainWindow::update_value_coord() {
  new_coordinat(rez, arr_coordinats, count);
  ui->openGLWidget->geometries->initCubeGeometry(pre_indices, arr_coordinats);
  ui->openGLWidget->update();
}

void MainWindow::obnull() {
  old_value_s_x = 0;
  old_value_s_y = 0;
  old_value_s_z = 0;

  old_value_p_x = 0;
  old_value_p_y = 0;
  old_value_p_z = 0;

  old_value_sl_x = 1;
  old_value_sl_y = 1;
  old_value_sl_z = 1;

  ui->translate_spinBox_x->setValue(old_value_s_x);
  ui->translate_spinBox_y->setValue(old_value_s_y);
  ui->translate_spinBox_z->setValue(old_value_s_z);

  ui->rotate_spinBox_x->setValue(old_value_p_x);
  ui->rotate_spinBox_y->setValue(old_value_p_x);
  ui->rotate_spinBox_z->setValue(old_value_p_x);

  ui->scale_spinBox_x->setValue(old_value_sl_x);
  ui->scale_spinBox_y->setValue(old_value_sl_x);
  ui->scale_spinBox_z->setValue(old_value_sl_x);
}

void new_coordinat(dot *rez, double *arr_coordinats, counts count) {
  int c = 0;
  for (int a = 0; a < count.count_of_vertexes; a++) {
    arr_coordinats[c] = rez[a].x;
    c++;
    arr_coordinats[c] = rez[a].y;
    c++;
    arr_coordinats[c] = rez[a].z;
    c++;
  }
}

void MainWindow::on_open_file_clicked() {
  QString str;
  str = QFileDialog::getOpenFileName(this, "Open a file...", QDir::homePath(),
                                     "OBJ-file (*.obj)");
  if (str != "") {
    free(rez);
    free(arr_coordinats);
    free(pre_indices);
    obnull();
    flag = 1;
    QFileInfo path(str);
    QString name = path.fileName();
    QByteArray arr = str.toLocal8Bit();
    char *array = arr.data();
    memset(&count, 0, sizeof(count));
    int *poligon;
    if (!first_opening(array, &count)) {
      rez = (dot *)calloc(count.count_of_vertexes, sizeof(dot));
      poligon = (int *)calloc(count.count_of_facets, sizeof(int));
      pre_indices = (int *)calloc(count.count_of_facets * 2, sizeof(int));
      second_opening(array, rez, poligon, &count, pre_indices);
      arr_coordinats =
          (double *)calloc(count.count_of_vertexes * 3, sizeof(double));
      new_coordinat(rez, arr_coordinats, count);

      ui->file_name->setText(name);
      ui->openGLWidget->geometries->setcount(count);
      ui->openGLWidget->geometries->initCubeGeometry(pre_indices,
                                                     arr_coordinats);
      ui->num_of_vert->setText(QString::number(count.count_of_vertexes));
      ui->num_of_edges->setText(QString::number(count.count_of_facets / 2));

      free(poligon);
    }
  }
}

void MainWindow::on_translate_down_x_clicked() {
  old_value_s_x = ui->translate_spinBox_x->value();
  if (flag != 0 && old_value_s_x > -100.0) {
    sdvigpo_X(rez, -0.1, &count);
    update_value_coord();
    old_value_s_x -= 0.1;
    ui->translate_spinBox_x->setValue(old_value_s_x);
  }
}

void MainWindow::on_translate_up_x_clicked() {
  old_value_s_x = ui->translate_spinBox_x->value();
  if (flag != 0 && old_value_s_x < 100.0) {
    sdvigpo_X(rez, 0.1, &count);
    update_value_coord();
    old_value_s_x += 0.1;
    ui->translate_spinBox_x->setValue(old_value_s_x);
  }
}

void MainWindow::on_translate_spinBox_x_editingFinished() {
  if (flag != 0) {
    old_value_s_x = ui->translate_spinBox_x->value();
    sdvigpo_X(rez, old_value_s_x, &count);
    update_value_coord();
  }
}

void MainWindow::on_translate_down_y_clicked() {
  old_value_s_y = ui->translate_spinBox_y->value();
  if (flag != 0 && old_value_s_y > -100.0) {
    sdvigpo_Y(rez, -0.1, &count);
    update_value_coord();
    old_value_s_y -= 0.1;
    ui->translate_spinBox_y->setValue(old_value_s_y);
  }
}

void MainWindow::on_translate_up_y_clicked() {
  old_value_s_y = ui->translate_spinBox_y->value();
  if (flag != 0 && old_value_s_y < 100.0) {
    sdvigpo_Y(rez, 0.1, &count);
    update_value_coord();
    old_value_s_y += 0.1;
    ui->translate_spinBox_y->setValue(old_value_s_y);
  }
}

void MainWindow::on_translate_spinBox_y_editingFinished() {
  if (flag != 0) {
    old_value_s_y = ui->translate_spinBox_y->value();
    sdvigpo_Y(rez, old_value_s_y, &count);
    update_value_coord();
  }
}

void MainWindow::on_translate_down_z_clicked() {
  old_value_s_z = ui->translate_spinBox_z->value();
  if (flag != 0 && old_value_s_z > -100.0) {
    sdvigpo_Z(rez, -0.1, &count);
    update_value_coord();
    old_value_s_z -= 0.1;
    ui->translate_spinBox_z->setValue(old_value_s_z);
  }
}

void MainWindow::on_translate_up_z_clicked() {
  old_value_s_z = ui->translate_spinBox_z->value();
  if (flag != 0 && old_value_s_z < 100.0) {
    sdvigpo_Z(rez, 0.1, &count);
    update_value_coord();
    old_value_s_z += 0.1;
    ui->translate_spinBox_z->setValue(old_value_s_z);
  }
}

void MainWindow::on_translate_spinBox_z_editingFinished() {
  if (flag != 0) {
    old_value_s_z = ui->translate_spinBox_z->value();
    sdvigpo_Z(rez, old_value_s_z, &count);
    update_value_coord();
  }
}

void MainWindow::on_rotate_down_x_clicked() {
  old_value_p_x = ui->rotate_spinBox_x->value();
  if (flag != 0 && old_value_p_x > -360) {
    povorot_X(rez, -0.0174533f, &count);
    update_value_coord();
    ui->rotate_spinBox_x->setValue(old_value_p_x - 1);
  }
}

void MainWindow::on_rotate_up_x_clicked() {
  old_value_p_x = ui->rotate_spinBox_x->value();
  if (flag != 0 && old_value_p_x < 360) {
    povorot_X(rez, 0.0174533f, &count);
    update_value_coord();
    ui->rotate_spinBox_x->setValue(old_value_p_x + 1);
  }
}

void MainWindow::on_rotate_spinBox_x_editingFinished() {
  if (flag != 0) {
    old_value_p_x = ui->rotate_spinBox_x->value();
    double rad = (old_value_p_x * M_PI) / 180;
    povorot_X(rez, rad, &count);
    update_value_coord();
  }
}

void MainWindow::on_rotate_down_y_clicked() {
  old_value_p_y = ui->rotate_spinBox_y->value();
  if (flag != 0 && old_value_p_y > -360) {
    povorot_Y(rez, -0.0174533f, &count);
    update_value_coord();
    ui->rotate_spinBox_y->setValue(old_value_p_y - 1);
  }
}

void MainWindow::on_rotate_up_y_clicked() {
  old_value_p_y = ui->rotate_spinBox_y->value();
  if (flag != 0 && old_value_p_y < 360) {
    povorot_Y(rez, 0.0174533f, &count);
    update_value_coord();
    ui->rotate_spinBox_y->setValue(old_value_p_y + 1);
  }
}

void MainWindow::on_rotate_spinBox_y_editingFinished() {
  if (flag != 0) {
    old_value_p_y = ui->rotate_spinBox_y->value();
    double rad = (old_value_p_y * M_PI) / 180;
    povorot_Y(rez, rad, &count);
    update_value_coord();
  }
}

void MainWindow::on_rotate_down_z_clicked() {
  old_value_p_z = ui->rotate_spinBox_z->value();
  if (flag != 0 && old_value_p_z > -360) {
    povorot_Z(rez, -0.0174533f, &count);
    update_value_coord();
    ui->rotate_spinBox_z->setValue(old_value_p_z - 1);
  }
}

void MainWindow::on_rotate_up_z_clicked() {
  old_value_p_z = ui->rotate_spinBox_z->value();
  if (flag != 0 && old_value_p_z < 360) {
    povorot_Z(rez, 0.0174533f, &count);
    update_value_coord();
    ui->rotate_spinBox_z->setValue(old_value_p_z + 1);
  }
}

void MainWindow::on_rotate_spinBox_z_editingFinished() {
  if (flag != 0) {
    old_value_p_z = ui->rotate_spinBox_z->value();
    double rad = (old_value_p_z * M_PI) / 180;
    povorot_Z(rez, rad, &count);
    update_value_coord();
  }
}

void MainWindow::on_scale_down_x_clicked() {
  double mean = ui->scale_spinBox_x->value();
  if (flag != 0 && mean > 0.1) {
    scaling_X(rez, old_value_sl_x, &count);
    mean -= 0.1;
    scaling_X(rez, mean, &count);
    update_value_coord();
    ui->scale_spinBox_x->setValue(mean);
    old_value_sl_x = 1 / mean;
  }
}

void MainWindow::on_scale_up_x_clicked() {
  double mean = ui->scale_spinBox_x->value();
  if (flag != 0 && mean < 10.0) {
    scaling_X(rez, old_value_sl_x, &count);
    mean += 0.1;
    scaling_X(rez, mean, &count);
    update_value_coord();
    ui->scale_spinBox_x->setValue(mean);
    old_value_sl_x = 1 / mean;
  }
}

void MainWindow::on_scale_spinBox_x_editingFinished() {
  if (flag != 0) {
    scaling_X(rez, old_value_sl_x, &count);
    double mean = ui->scale_spinBox_x->value();
    scaling_X(rez, mean, &count);
    update_value_coord();
    ui->scale_spinBox_x->setValue(mean);
    old_value_sl_x = 1 / mean;
  }
}

void MainWindow::on_scale_down_y_clicked() {
  double mean = ui->scale_spinBox_y->value();
  if (flag != 0 && mean > 0.1) {
    scaling_Y(rez, old_value_sl_y, &count);
    mean -= 0.1;
    scaling_Y(rez, mean, &count);
    update_value_coord();
    ui->scale_spinBox_y->setValue(mean);
    old_value_sl_y = 1 / mean;
  }
}

void MainWindow::on_scale_up_y_clicked() {
  double mean = ui->scale_spinBox_y->value();
  if (flag != 0 && mean < 10.0) {
    scaling_Y(rez, old_value_sl_y, &count);
    mean += 0.1;
    scaling_Y(rez, mean, &count);
    update_value_coord();
    ui->scale_spinBox_y->setValue(mean);
    old_value_sl_y = 1 / mean;
  }
}

void MainWindow::on_scale_spinBox_y_editingFinished() {
  if (flag != 0) {
    scaling_Y(rez, old_value_sl_y, &count);
    double mean = ui->scale_spinBox_y->value();
    scaling_Y(rez, mean, &count);
    update_value_coord();
    ui->scale_spinBox_y->setValue(mean);
    old_value_sl_y = 1 / mean;
  }
}

void MainWindow::on_scale_down_z_clicked() {
  double mean = ui->scale_spinBox_z->value();
  if (flag != 0 && mean > 0.1) {
    scaling_Z(rez, old_value_sl_z, &count);
    mean -= 0.1;
    scaling_Z(rez, mean, &count);
    update_value_coord();
    ui->scale_spinBox_z->setValue(mean);
    old_value_sl_z = 1 / mean;
  }
}

void MainWindow::on_scale_up_z_clicked() {
  double mean = ui->scale_spinBox_z->value();
  if (flag != 0 && mean < 10.0) {
    scaling_Z(rez, old_value_sl_z, &count);
    mean += 0.1;
    scaling_Z(rez, mean, &count);
    update_value_coord();
    ui->scale_spinBox_z->setValue(mean);
    old_value_sl_z = 1 / mean;
  }
}

void MainWindow::on_scale_spinBox_z_editingFinished() {
  if (flag != 0) {
    scaling_Z(rez, old_value_sl_z, &count);
    double mean = ui->scale_spinBox_z->value();
    scaling_Z(rez, mean, &count);
    update_value_coord();
    ui->scale_spinBox_z->setValue(mean);
    old_value_sl_z = 1 / mean;
  }
}

void MainWindow::on_printscreen_button_pressed() {
  QImage screen = this->ui->openGLWidget->grabFramebuffer();
  QString file_path =
      QFileDialog::getSaveFileName(this, "Save image as...", QDir::homePath(),
                                   "BMP-file (*.bmp);;JPEG-file (*.jpeg)");
  if (!file_path.isEmpty() || !file_path.isNull()) screen.save(file_path);
}

void MainWindow::on_gif_button_pressed() { timer->start(100); }

void MainWindow::make_gif() {
  if (screenshots_count < 50) {
    QImage screen = this->ui->openGLWidget->grabFramebuffer();
    gif->addFrame(screen, -1);
    screenshots_count++;
  }
  if (screenshots_count == 50) {
    timer->stop();
    screenshots_count = 0;
    QString file_path = QFileDialog::getSaveFileName(
        this, "Save gif as...", QDir::homePath(), "GIF-file (*.gif)");
    if (!file_path.isEmpty() || !file_path.isNull()) gif->save(file_path);
    delete gif;
    gif = new QGifImage;
  }
}

void MainWindow::on_comboBox_type_of_edges_activated(int index) {
  if (index == 0) {
    settin->type_of_edges = 0;
  }
  if (index == 1) {
    settin->type_of_edges = 1;
  }
  ui->openGLWidget->setSetting(settin);
  ui->openGLWidget->update();
}

void MainWindow::on_comboBox_type_of_vertices_activated(int index) {
  if (index == 0) {
    settin->type_of_vertices = 0;
  }
  if (index == 1) {
    settin->type_of_vertices = 1;
  }
  if (index == 2) {
    settin->type_of_vertices = 2;
  }
  ui->openGLWidget->setSetting(settin);
  ui->openGLWidget->update();
}

void MainWindow::on_pushButton_color_of_background_clicked() {
  QColor color = QColorDialog::getColor();
  if (color.isValid()) {
    settin->background_settings = color;
    ui->openGLWidget->setSetting(settin);
    ui->openGLWidget->paintGL();
    ui->openGLWidget->update();
  }
}

void MainWindow::on_pushButton_color_of_edges_clicked() {
  QColor lines_color = QColorDialog::getColor();
  if (lines_color.isValid()) {
    settin->lines_color_settings = lines_color;
    ui->openGLWidget->setSetting(settin);
    ui->openGLWidget->paintGL();
    ui->openGLWidget->update();
  }
}

void MainWindow::on_comboBox_projection_activated(int index) {
  settin->flag_proect = index;
  ui->openGLWidget->setSetting(settin);
  ui->openGLWidget->resizeGL(950, 780);
  ui->openGLWidget->update();
}

void MainWindow::on_comboBox_vertice_size_activated(int index) {
  if (index == 0) {
    settin->size_of_vertices = 5.0;
  }
  if (index == 1) {
    settin->size_of_vertices = 10.0;
  }
  if (index == 2) {
    settin->size_of_vertices = 15.0;
  }
  ui->openGLWidget->setSetting(settin);
  ui->openGLWidget->update();
}

void MainWindow::on_comboBox_edges_thickness_activated(int index) {
  if (index == 0) {
    settin->thickness_of_lines = 1.0;
  }
  if (index == 1) {
    settin->thickness_of_lines = 2.5;
  }
  if (index == 2) {
    settin->thickness_of_lines = 5.0;
  }
  ui->openGLWidget->setSetting(settin);
  ui->openGLWidget->update();
}

void MainWindow::on_pushButton_color_of_vertices_clicked() {
  QColor lines_color = QColorDialog::getColor();
  if (lines_color.isValid()) {
    settin->vert_color_settings = lines_color;
    ui->openGLWidget->setSetting(settin);
    ui->openGLWidget->paintGL();
    ui->openGLWidget->update();
  }
}
