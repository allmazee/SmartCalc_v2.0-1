#include "creditwindow.h"

#include "mainwindow.h"
#include "ui_creditwindow.h"

CreditWindow::CreditWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::CreditWindow) {
  ui->setupUi(this);
  this->setWindowTitle("Credit Calculator");
  ui->radioButton_annuity->setChecked(true);
}

CreditWindow::~CreditWindow() { delete ui; }

// TODO: Correct diff payment realization:
//       1. first_payment ... last_payment
//       2. reset values when pressing button

void CreditWindow::on_pushButton_calculate_clicked() {
  s21::CreditModel::CreditType type;
  if (ui->radioButton_annuity->isChecked()) {
    type = s21::CreditModel::CreditType::ANNUITY;
  } else {
    type = s21::CreditModel::CreditType::DIFF;
  }
  double sum = ui->doubleSpinBox_sum->value();
  int term = ui->spinBox_term->value();
  int percent = ui->spinBox_percent->value();
  controller.set_data(type, sum, term, percent);
  controller.Calculate();
  std::vector<double> per_month = controller.get_monthly_payment();
  QString per_month_result =
      QString::number(per_month.front(), 'f', 2) + " ₽";
  if (type == s21::CreditModel::CreditType::DIFF) {
    per_month_result +=
        " ... " + QString::number(per_month.back(), 'f', 2) + " ₽";
  }

  //    double monthly_payment = 0, total_payment = 0, overpayment = 0,
  //    first_payment = 0; if (ui->radioButton_annuity->isChecked()) {
  //        monthly_payment = annuity_payment(sum, percent, term);
  //        total_payment = monthly_payment * term;
  //        overpayment = total_payment - sum;
  //        per_month_result = QString::number(monthly_payment, 'f', 2) + "
  //        ₽";
  //    } else if (ui->radioButton_diff->isChecked()) {
  //        monthly_payment = diff_payment(sum, percent, term, 1);
  //        first_payment = monthly_payment;
  //        for (int i = 0; i < term; i++) {
  //            total_payment += monthly_payment;
  //            overpayment = total_payment - sum;
  //            monthly_payment = diff_payment(sum, percent, term, i + 1);
  //        }
  //        per_month_result = QString::number(first_payment, 'f', 2) + " ₽
  //        ... " + QString::number(monthly_payment, 'f', 2) + " ₽";
  //    }
  ui->label_permonth_value->setText(per_month_result);
  ui->label_charges_value->setText(
      QString::number(controller.get_overpayment(), 'f', 2) + " ₽");
  ui->label_fullsum_value->setText(
      QString::number(controller.get_total_payment(), 'f', 2) + " ₽");
}
