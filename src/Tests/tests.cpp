#include <gtest/gtest.h>

#include "../Controllers/calculator_controller.h"
#include "../Controllers/credit_controller.h"

TEST(CalculatorControllerTest, Test0) {
  s21::CalculatorController controller;
  controller.Calculate("5+-1)", 0);
  EXPECT_EQ(controller.get_status(), s21::CalculatorModel::Status::ERROR);
}

TEST(CalculatorControllerTest, Test1) {
  s21::CalculatorController controller;
  controller.Calculate("sqrt(16)+sin(1)", 0);
  EXPECT_NEAR(controller.get_result(), 4.84147, 1e-6);
}

TEST(CalculatorControllerTest, Test2) {
  s21::CalculatorController controller;
  controller.Calculate("2^(2^(2^2))", 0);
  EXPECT_EQ(controller.get_result(), 65536);
}

TEST(CalculatorControllerTest, Test3) {
  s21::CalculatorController controller;
  controller.Calculate("log(25)-acos(0.45)", 0);
  EXPECT_NEAR(controller.get_result(), 0.293909, 1e-6);
}

TEST(CalculatorControllerTest, Test4) {
  s21::CalculatorController controller;
  controller.Calculate("(4*sin(2.9)+3*cos(0.47))/4", 0);
  EXPECT_NEAR(controller.get_result(), 0.907926, 1e-6);
}

TEST(CalculatorControllerTest, Test5) {
  s21::CalculatorController controller;
  controller.Calculate("log(50)/acos(0.35)*atan(1.1)*sqrt(64)", 0);
  EXPECT_NEAR(controller.get_result(), 9.3318876, 1e-6);
}

TEST(CalculatorControllerTest, Test6) {
  s21::CalculatorController controller;
  controller.Calculate(
      "(sin(1.4)*cos(0.85)/tan(0.68))/(asin(0.38)/"
      "2*acos(0.45)^3-atan(0.54)*sqrt(49))+ln(5)*log(100)",
      0);
  EXPECT_NEAR(controller.get_result(), 2.967829, 1e-6);
}

TEST(CalculatorControllerTest, Test7) {
  s21::CalculatorController controller;
  controller.Calculate(
      "acos(0.25)^ln(2)-atan(1.5)*sqrt(16)*log(10)*sin(2.5)/(cos(1.1)/"
      "tan(1.9)*asin(0.4))",
      0);
  EXPECT_NEAR(controller.get_result(), 38.104222613215, 1e-6);
}

TEST(CalculatorControllerTest, Test8) {
  s21::CalculatorController controller;
  controller.Calculate(
      "((sin(1.7)*acos(0.3)-atan(0.35)*tan(1.5))^2)/sqrt(9)*(ln(7)+log(1000)/"
      "acos(0.6))",
      0);
  EXPECT_NEAR(controller.get_result(), 21.0601731, 1e-6);
}

TEST(CalculatorControllerTest, Test9) {
  s21::CalculatorController controller;
  controller.Calculate(
      "atan(0.75)*log(10)+sqrt(64)*sin(2)-cos(0.576)/acos(0.78)/"
      "5-2*ln(3)*asin(0.29)*tan(1.05)",
      0);
  EXPECT_NEAR(controller.get_result(), 6.5427849584, 1e-6);
}

TEST(CalculatorControllerTest, Test10) {
  s21::CalculatorController controller;
  controller.Calculate(
      "(cos(2.1)^2*sin(1.2)*atan(0.85)+acos(0.4))/"
      "log(250)*sqrt(169)+ln(5)*asin(0.55)*tan(0.5)",
      0);
  EXPECT_NEAR(controller.get_result(), 7.70412863, 1e-6);
}

TEST(CalculatorControllerTest, Test11) {
  s21::CalculatorController controller;
  controller.Calculate(
      "(sin(0.93)+acos(0.71)/atan(1.37)*tan(1.8))/"
      "(sqrt(25)*ln(10)*acos(0.3)-asin(0.6)*cos(1.1))",
      0);
  EXPECT_NEAR(controller.get_result(), -0.193212471, 1e-6);
}

TEST(CalculatorControllerTest, Test12) {
  s21::CalculatorController controller;
  controller.Calculate("sin(cos(tan(ln(log(1234)+1)*2)/3)-4)", 0);
  EXPECT_NEAR(controller.get_result(), -0.134926396, 1e-6);
}

TEST(CalculatorControllerTest, Test13) {
  s21::CalculatorController controller;
  controller.Calculate(
      "(sin(0.93)+acos(0.71)/atan(1.37)*tan(1.8))/"
      "(sqrt(25)*ln(10)*acos(0.3)-asin(0.6)*cos(1.1))-sin(cos(tan(ln(log((cos("
      "2.1)^2*sin(1.2)*atan(0.85)+acos(0.4))/"
      "log(250)*sqrt(169)+ln(5)*asin(0.55)*tan(0.5))+1)*2)/3)-4)",
      0);
  EXPECT_NEAR(controller.get_result(), -0.565264615, 1e-6);
}

TEST(CalculatorControllerTest, Test14) {
  s21::CalculatorController controller;
  controller.Calculate("1/0", 0);
  EXPECT_EQ(controller.get_status(), s21::CalculatorModel::Status::ERROR);
}

TEST(CalculatorControllerTest, Test15) {
  s21::CalculatorController controller;
  controller.Calculate("sqrt(-16)", 0);
  EXPECT_EQ(controller.get_status(), s21::CalculatorModel::Status::ERROR);
}

TEST(CalculatorControllerTest, Test16) {
  s21::CalculatorController controller;
  controller.Calculate("654+", 0);
  EXPECT_EQ(controller.get_status(), s21::CalculatorModel::Status::ERROR);
}

TEST(CalculatorControllerTest, Test17) {
  s21::CalculatorController controller;
  controller.Calculate("(5+", 0);
  EXPECT_EQ(controller.get_status(), s21::CalculatorModel::Status::ERROR);
}

TEST(CalculatorControllerTest, Test18) {
  s21::CalculatorController controller;
  controller.Calculate("sin(x)", 1);
  EXPECT_NEAR(controller.get_result(), 0.841471, 1e-06);
}

TEST(CalculatorControllerTest, Test19) {
  s21::CalculatorController controller;
  controller.Calculate("=1+06", 0);
  EXPECT_EQ(controller.get_status(), s21::CalculatorModel::Status::ERROR);
}

TEST(CalculatorControllerTest, Test20) {
  s21::CalculatorController controller;
  controller.Calculate("+", 0);
  EXPECT_EQ(controller.get_status(), s21::CalculatorModel::Status::ERROR);
}

TEST(CalculatorControllerTest, Test21) {
  s21::CalculatorController controller;
  controller.Calculate("INCORRECT", 0);
  EXPECT_EQ(controller.get_status(), s21::CalculatorModel::Status::ERROR);
}

TEST(CalculatorControllerTest, Test22) {
  s21::CalculatorController controller;
  controller.Calculate("1+999)", 0);
  EXPECT_EQ(controller.get_status(), s21::CalculatorModel::Status::ERROR);
}

TEST(CalculatorControllerTest, Test23) {
  s21::CalculatorController controller;
  controller.Calculate("1-(900", 0);
  EXPECT_EQ(controller.get_status(), s21::CalculatorModel::Status::ERROR);
}

TEST(CalculatorControllerTest, Test24) {
  s21::CalculatorController controller;
  controller.Calculate("-1-(-1-(-1-(-2-1)))", 0);
  EXPECT_EQ(controller.get_result(), 2);
}

TEST(CalculatorControllerTest, Test25) {
  s21::CalculatorController controller;
  controller.Calculate("1--1", 0);
  EXPECT_EQ(controller.get_status(), s21::CalculatorModel::Status::ERROR);
}

TEST(CalculatorControllerTest, Test26) {
  s21::CalculatorController controller;
  controller.Calculate("1-sin(1)", 0);
  EXPECT_NEAR(controller.get_result(), 0.158529, 1e-6);
}

TEST(CalculatorControllerTest, Test27) {
  s21::CalculatorController controller;
  controller.Calculate("+5+5", 0);
  EXPECT_EQ(controller.get_result(), 10);
}

TEST(CalculatorControllerTest, Test28) {
  s21::CalculatorController controller;
  controller.Calculate("+5*(-5)", 0);
  EXPECT_EQ(controller.get_result(), -25);
}

TEST(CalculatorControllerTest, Test29) {
  s21::CalculatorController controller;
  controller.Calculate("", 0);
  EXPECT_EQ(controller.get_status(), s21::CalculatorModel::Status::ERROR);
}

TEST(CalculatorControllerTest, Test30) {
  s21::CalculatorController controller;
  controller.Calculate("log(-1)*ln(-2)", 0);
  EXPECT_EQ(controller.get_status(), s21::CalculatorModel::Status::ERROR);
}

TEST(CalculatorControllerTest, Test31) {
  s21::CalculatorController controller;
  controller.Calculate("ln(0)", 0);
  EXPECT_EQ(controller.get_status(), s21::CalculatorModel::Status::ERROR);
}

TEST(CalculatorControllerTest, Test32) {
  s21::CalculatorController controller;
  controller.Calculate("20%5", 0);
  EXPECT_EQ(controller.get_status(), s21::CalculatorModel::Status::OK);
  EXPECT_EQ(controller.get_result(), 0);
}

TEST(CalculatorControllerTest, Test33) {
  s21::CalculatorController controller;
  controller.Calculate("1 + 3", 0);
  EXPECT_EQ(controller.get_result(), 4);
}

TEST(CalculatorControllerTest, Test34) {
  s21::CalculatorController controller;
  controller.Calculate("sin0", 0);
  EXPECT_EQ(controller.get_status(), s21::CalculatorModel::Status::ERROR);
}

TEST(CalculatorControllerTest, Test35) {
  s21::CalculatorController controller;
  controller.Calculate("2%", 0);
  EXPECT_EQ(controller.get_status(), s21::CalculatorModel::Status::ERROR);
}

TEST(CalculatorControllerTest, Test36) {
  s21::CalculatorController controller;
  controller.Calculate("^5", 0);
  EXPECT_EQ(controller.get_status(), s21::CalculatorModel::Status::ERROR);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}