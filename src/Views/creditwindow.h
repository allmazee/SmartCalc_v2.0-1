#ifndef CREDITWINDOW_H
#define CREDITWINDOW_H

#include <QMessageBox>
#include <QWidget>

#include "../Controllers/credit_controller.h"

namespace Ui {
class CreditWindow;
}

class CreditWindow : public QWidget {
  Q_OBJECT

 public:
  explicit CreditWindow(QWidget *parent = nullptr);
  ~CreditWindow();

 private slots:
  //    double annuity_payment(double sum, double percent, int term);
  //    double diff_payment(double sum, double percent, int term, int month);
  void on_pushButton_calculate_clicked();

 private:
  Ui::CreditWindow *ui;
  s21::CreditController controller;
};

#endif  // CREDITWINDOW_H
