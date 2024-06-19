#include "plotwindow.h"

#include "mainwindow.h"
#include "ui_plotwindow.h"

PlotWindow::PlotWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::PlotWindow) {
  ui->setupUi(this);
  this->setWindowTitle("Plot");
}

PlotWindow::~PlotWindow() { delete ui; }

// void PlotWindow::get_input(QString str) {
//   this->str_ = str;
//     char input[256] = {0};
//     get_str(str, input);
//     drawGraph();
// }

void PlotWindow::set_data() {
  x_begin_ = ui->doubleSpinBox_min_x->value();
  x_end_ = ui->doubleSpinBox_max_x->value();
  y_begin_ = ui->doubleSpinBox_min_y->value();
  y_end_ = ui->doubleSpinBox_max_y->value();
}

void PlotWindow::drawGraph(QString str) {
  set_data();
  str_ = str;
  double step = (x_end_ - x_begin_) / 10000;
  for (current_x_ = x_begin_; current_x_ <= x_end_; current_x_ += step) {
    std::string string = str_.toStdString();
    calculator_controller.Calculate(string, current_x_);
    double res = calculator_controller.get_result();
    x_.push_back(current_x_);
    y_.push_back(res);
  }
  ui->widget->xAxis->setRange(x_begin_, x_end_);
  ui->widget->yAxis->setRange(y_begin_, y_end_);
  ui->widget->addGraph();
  ui->widget->graph(0)->addData(x_, y_);
  ui->widget->graph(0)->setLineStyle(QCPGraph::lsNone);
  ui->widget->graph(0)->setScatterStyle(
      QCPScatterStyle(QCPScatterStyle::ssCircle, 1));
  ui->widget->replot();
}

void PlotWindow::on_pushButton_clicked() {
  ui->widget->clearGraphs();
  drawGraph(str_);
}
