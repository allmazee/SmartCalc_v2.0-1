#ifndef PLOTWINDOW_H
#define PLOTWINDOW_H

#include <QVector>
#include <QWidget>

#include "../Controllers/calculator_controller.h"

namespace Ui {
class PlotWindow;
}

class PlotWindow : public QWidget {
  Q_OBJECT

 public:
  explicit PlotWindow(QWidget *parent = nullptr);
  ~PlotWindow();

 private:
  s21::CalculatorController calculator_controller;
  Ui::PlotWindow *ui;

  double x_begin_;
  double x_end_;
  double y_begin_;
  double y_end_;
  double current_x_;
  double current_y_;
  //    double h;
  //    int N;

  QVector<double> x_, y_;
  QString str_;

 public slots:
  // void get_input(QString str);
  void drawGraph(QString str);

 private slots:
  void set_data();
  void on_pushButton_clicked();
};

#endif  // PLOTWINDOW_H
