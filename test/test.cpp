/**
 * @file test.cpp
 * @author  Phase 0 - Shivam Sehgal (ssehgal7@umd.edu) - Driver,
 *                    Patrik Pordi (ppordi@umd.edu) - Navigator,
 *                    Darshit Desai (darshit@umd.edu) - Code designer
 *          Phase 1 - Shivam Sehgal (ssehgal7@umd.edu) - Navigator,
 *                    Patrik Pordi (ppordi@umd.edu) - Code designer,
 *                    Darshit Desai (darshit@umd.edu) - Driver
 * @brief Test file for PID and Ackerman Steering Model
 * @version 0.1
 * @date 2023-10-23
 *
 * @copyright Copyright (c) 2023 Darshit Desai, Patrik Pordi, Shivam Sehgal
 * This code is licensed under the MIT License. Please see the
 * accompanying LICENSE file for the full text of the license.
 *
 */

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "../include/PID.hpp"
#include "../include/ackerman.hpp"

/**
 * @brief Write a test to check GetKp() function
 *
 */
TEST(PID, setKp) {
  Eigen::Matrix<double, 2, 1> Kp;
  Kp = Eigen::Vector2d(1, 2);
  PID pid;
  pid.setKp(Kp);
  EXPECT_EQ(pid.getKp(), Kp);
}
/**
 * @brief Write a test to check GetKi() function
 *
 */
TEST(PID, setKi) {
  Eigen::Matrix<double, 2, 1> Ki;
  Ki = Eigen::Vector2d(1, 2);
  PID pid;
  pid.setKi(Ki);
  EXPECT_EQ(pid.getKi(), Ki);
}
/**
 * @brief Write a test to check GetKd() function
 *
 */
TEST(PID, setKd) {
  Eigen::Matrix<double, 2, 1> Kd;
  Kd = Eigen::Vector2d(1, 2);
  PID pid;
  pid.setKd(Kd);
  EXPECT_EQ(pid.getKd(), Kd);
}
/**
 * @brief Write a test to check GetDt() function
 *
 */
TEST(PID, setDt) {
  double dt = 0.1;
  PID pid;
  pid.setDt(dt);
  EXPECT_EQ(pid.getDt(), dt);
}
/**
 * @brief Write a test to check get controller values function in PID.hpp
 *
 */
TEST(PID, getControllerValues) {
  Eigen::Matrix<double, 2, 1> Kp;
  Kp = Eigen::Vector2d(1, 2);
  Eigen::Matrix<double, 2, 1> Ki;
  Ki = Eigen::Vector2d(1, 2);
  Eigen::Matrix<double, 2, 1> Kd;
  Kd = Eigen::Vector2d(1, 2);
  double dt = 0.1;
  PID pid;
  pid.setKp(Kp);
  pid.setKi(Ki);
  pid.setKd(Kd);
  pid.setDt(dt);
  Eigen::Matrix<double, 2, 1> controllerValues;
  controllerValues = pid.getControllerValues();
  EXPECT_EQ(controllerValues, Eigen::Matrix<double, 2, 1>::Zero());
}

/**
 * @brief Write a test to check get wheel radius function in ackerman.hpp
 *
 */
TEST(Ackerman_Steering_Model, getWheelRadius) {
  double WheelRadius = 0.1;
  Ackerman_Steering_Model ackerman;
  ackerman.setWheelRadius(WheelRadius);
  EXPECT_EQ(ackerman.getWheelRadius(), WheelRadius);
}
/**
 * @brief Write a test to check get wheel base function in ackerman.hpp
 *
 */
TEST(Ackerman_Steering_Model, getWheelBase) {
  double WheelBase = 0.1;
  Ackerman_Steering_Model ackerman;
  ackerman.setWheelBase(WheelBase);
  EXPECT_EQ(ackerman.getWheelBase(), WheelBase);
}

/**
 * @brief Write a test to check get axle width function in ackerman.hpp
 *
 */
TEST(Ackerman_Steering_Model, getAxleWidth) {
  double AxleWidth = 0.1;
  Ackerman_Steering_Model ackerman;
  ackerman.setAxleWidth(AxleWidth);
  EXPECT_EQ(ackerman.getAxleWidth(), AxleWidth);
}

/**
 * @brief Write a test to check get steering angle function in ackerman.hpp
 *
 */
TEST(Ackerman_Steering_Model, getSteeringAngle) {
  Eigen::Vector2d steeringAngle;
  steeringAngle = Eigen::Vector2d(0, 0);
  Ackerman_Steering_Model ackerman;
  ackerman.setSteeringAngle(steeringAngle);
  EXPECT_EQ(ackerman.getSteeringAngle(), steeringAngle);
}

/**
 * @brief Write a test to check setSteeringAngleAndCarVelocity Function
 *
 */
TEST(Ackerman_Steering_Model, setSteeringAngleAndCarVelocity) {
  Eigen::Vector2d steeringAngle;
  steeringAngle = Eigen::Vector2d(0, 0);
  Ackerman_Steering_Model ackerman;
  Eigen::Vector2d pidoutput;
  pidoutput = Eigen::Vector2d(0, 0);
  ackerman.setSteeringAngleAndCarVelocity(pidoutput);
  EXPECT_EQ(ackerman.getSteeringAngle(), steeringAngle);
}
/**
 * @brief Write a test to check get vehicle state function in ackerman.hpp
 *
 */
TEST(Ackerman_Steering_Model, getVehicleState) {
  Eigen::Vector2d vehicleState;
  vehicleState = Eigen::Vector2d(0, 0);
  Ackerman_Steering_Model ackerman;
  ackerman.setVehicleState(vehicleState);
  EXPECT_EQ(ackerman.getVehicleState(), vehicleState);
}

/**
 * @brief Write a test for checkAngleConstraints function
 *
 */
TEST(CheckAngleConstraintsTest, InvalidAngleConstraints) {
  Ackerman_Steering_Model model;
  // Assuming that your function should return false when angle constraints are
  // not met
  bool result = model.checkAngleConstraints();
  EXPECT_FALSE(result);
}
