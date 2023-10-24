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
  PID pid(Kp, Eigen::Vector2d::Zero(), Eigen::Vector2d::Zero(), 0.0);
  pid.setKp(Kp);

  // Check if the Kp values are set correctly
  ASSERT_TRUE(pid.getKp().isApprox(Kp));
}
/**
 * @brief Write a test to check GetKi() function
 *
 */
TEST(PID, setKi) {
  Eigen::Matrix<double, 2, 1> Ki;
  Ki = Eigen::Vector2d(1, 2);
  PID pid(Eigen::Vector2d::Zero(), Ki, Eigen::Vector2d::Zero(), 0.0);
  pid.setKi(Ki);

  // Check if the Ki values are set correctly
  ASSERT_TRUE(pid.getKi().isApprox(Ki));
}
/**
 * @brief Write a test to check GetKd() function
 *
 */
TEST(PID, setKd) {
  Eigen::Matrix<double, 2, 1> Kd;
  Kd = Eigen::Vector2d(1, 2);
  PID pid(Eigen::Vector2d::Zero(), Eigen::Vector2d::Zero(), Kd, 0.0);
  pid.setKd(Kd);

  // Check if the Kd values are set correctly
  ASSERT_TRUE(pid.getKd().isApprox(Kd));
}
/**
 * @brief Write a test to check GetDt() function
 *
 */
TEST(PID, setDt) {
  double dt = 0.1;
  PID pid(Eigen::Vector2d::Zero(), Eigen::Vector2d::Zero(), Eigen::Vector2d::Zero(), dt);
  pid.setDt(dt);

  // Check if the dt value is set correctly
  ASSERT_DOUBLE_EQ(pid.getDt(), dt);
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
  PID pid(Kp, Ki, Kd, dt);
  Eigen::Matrix<double, 2, 1> controllerValues;
  Eigen::Vector2d TargetState(1, 2);
  Eigen::Vector2d CurrentState(1, 2);
  controllerValues = pid.getControllerValues(TargetState, CurrentState);

  // Use Eigen's isApprox function to compare matrices with tolerance
  ASSERT_TRUE(controllerValues.isApprox(Eigen::Matrix<double, 2, 1>::Zero()));
}

/**
 * @brief Write a test to check get wheel radius function in ackerman.hpp
 *
 */
TEST(Ackerman_Steering_Model, getWheelRadius) {
  double wheelBase = 1.0;
  double axleWidth = 0.5;
  double wheelRadius = 0.2;
  Eigen::Vector2d steeringAngle(0.1, 0.2);
  Eigen::Vector2d wheelVelocity(2.0, 1.5);
  Eigen::Vector2d vehicleState(0.0, 0.0);
  Ackerman_Steering_Model ackerman(wheelBase, axleWidth, wheelRadius,
                                 steeringAngle, wheelVelocity, vehicleState);
  ackerman.setWheelRadius(wheelRadius);
  EXPECT_EQ(ackerman.getWheelRadius(), wheelRadius);
}
/**
 * @brief Write a test to check get wheel base function in ackerman.hpp
 *
 */
TEST(Ackerman_Steering_Model, getWheelBase) {
  double wheelBase = 1.0;
  double axleWidth = 0.5;
  double wheelRadius = 0.2;
  Eigen::Vector2d steeringAngle(0.1, 0.2);
  Eigen::Vector2d wheelVelocity(2.0, 1.5);
  Eigen::Vector2d vehicleState(0.0, 0.0);
  Ackerman_Steering_Model ackerman(wheelBase, axleWidth, wheelRadius,
                                 steeringAngle, wheelVelocity, vehicleState);
  ackerman.setWheelBase(wheelBase);
  EXPECT_EQ(ackerman.getWheelBase(), wheelBase);
}

/**
 * @brief Write a test to check get axle width function in ackerman.hpp
 *
 */
TEST(Ackerman_Steering_Model, getAxleWidth) {
  double wheelBase = 1.0;
  double axleWidth = 0.5;
  double wheelRadius = 0.2;
  Eigen::Vector2d steeringAngle(0.1, 0.2);
  Eigen::Vector2d wheelVelocity(2.0, 1.5);
  Eigen::Vector2d vehicleState(0.0, 0.0);
  Ackerman_Steering_Model ackerman(wheelBase, axleWidth, wheelRadius,
                                 steeringAngle, wheelVelocity, vehicleState);
  ackerman.setAxleWidth(axleWidth);
  EXPECT_EQ(ackerman.getAxleWidth(), axleWidth);
}

/**
 * @brief Write a test to check get steering angle function in ackerman.hpp
 *
 */
TEST(Ackerman_Steering_Model, getSteeringAngle) {
  double wheelBase = 1.0;
  double axleWidth = 0.5;
  double wheelRadius = 0.2;
  Eigen::Vector2d steeringAngle(0.1, 0.2);
  Eigen::Vector2d wheelVelocity(2.0, 1.5);
  Eigen::Vector2d vehicleState(0.0, 0.0);
  Ackerman_Steering_Model ackerman(wheelBase, axleWidth, wheelRadius,
                                 steeringAngle, wheelVelocity, vehicleState);
  EXPECT_EQ(ackerman.getSteeringAngle(), steeringAngle);
}

/**
 * @brief Write a test to check setSteeringAngleAndCarVelocity Function
 *
 */
TEST(Ackerman_Steering_Model, setSteeringAngleAndCarVelocity) {
  double wheelBase = 1.0;
  double axleWidth = 0.5;
  double wheelRadius = 0.2;
  Eigen::Vector2d steeringAngle(0.1, 0.2);
  Eigen::Vector2d wheelVelocity(2.0, 1.5);
  Eigen::Vector2d vehicleState(0.0, 0.0);
  Ackerman_Steering_Model ackerman(wheelBase, axleWidth, wheelRadius,
                                 steeringAngle, wheelVelocity, vehicleState);
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
  double wheelBase = 1.0;
  double axleWidth = 0.5;
  double wheelRadius = 0.2;
  Eigen::Vector2d steeringAngle(0.1, 0.2);
  Eigen::Vector2d wheelVelocity(2.0, 1.5);
  Eigen::Vector2d vehicleState(0.0, 0.0);
  Ackerman_Steering_Model ackerman(wheelBase, axleWidth, wheelRadius,
                                 steeringAngle, wheelVelocity, vehicleState);
  ackerman.setVehicleState(vehicleState);
  EXPECT_EQ(ackerman.getVehicleState(), vehicleState);
}

/**
 * @brief Write a test for checkAngleConstraints function
 *
 */
TEST(CheckAngleConstraintsTest, InvalidAngleConstraints) {
  double wheelBase = 1.0;
  double axleWidth = 0.5;
  double wheelRadius = 0.2;
  Eigen::Vector2d steeringAngle(0.1, 0.2);
  Eigen::Vector2d wheelVelocity(2.0, 1.5);
  Eigen::Vector2d vehicleState(0.0, 0.0);
  Ackerman_Steering_Model model(wheelBase, axleWidth, wheelRadius,
                                 steeringAngle, wheelVelocity, vehicleState);
  // Assuming that your function should return false when angle constraints are
  // not met
  bool result = model.checkAngleConstraints();
  EXPECT_FALSE(result);
}
