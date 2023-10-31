/**
 * @file test.cpp
 * @author  Phase 0 - Shivam Sehgal (ssehgal7@umd.edu) - Driver,
 *                    Patrik Pordi (ppordi@umd.edu) - Navigator,
 *                    Darshit Desai (darshit@umd.edu) - Code designer
 *          Phase 1 - Shivam Sehgal (ssehgal7@umd.edu) - Navigator,
 *                    Patrik Pordi (ppordi@umd.edu) - Code designer,
 *                    Darshit Desai (darshit@umd.edu) - Driver
 *          Phase 2 - Shivam Sehgal (ssehgal7@umd.edu) - Code designer,
 *                    Patrik Pordi (ppordi@umd.edu) - Driver,
 *                    Darshit Desai (darshit@umd.edu) - Navigator
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
  PID pid;
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
  PID pid;
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
  PID pid;
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
  PID pid;
  pid.setDt(dt);

  // Check if the dt value is set correctly
  ASSERT_DOUBLE_EQ(pid.getDt(), dt);
}
/**
 * @brief Write a test to check PID controller and ackerman steering
 * functionality for forward and left turn
 *
 */
TEST(PID, ForwardMotionLeftTurn) {
  PID pid;
  Eigen::Matrix<double, 2, 1> Kp{0.3, 0.3};
  Eigen::Matrix<double, 2, 1> Ki{0.1, 0.1};
  Eigen::Matrix<double, 2, 1> Kd{0.05, 0.05};
  double dt{0.1};
  pid.setKp(Kp);
  pid.setKi(Ki);
  pid.setKd(Kd);
  pid.setDt(dt);
  double TargetVelocity{0};
  double TargetHeadingAngle{0};
  Eigen::Vector2d CurrentState{0, 0};
  TargetVelocity = 5.0;
  TargetHeadingAngle = 0.5;
  Eigen::Vector2d TargetState{TargetVelocity, TargetHeadingAngle};
  Eigen::Vector2d controllerOutput;
  controllerOutput = pid.ControllerLoop(TargetState, CurrentState);
  // Check output vector elements are in certain range or not or the error norm
  // between Target and output < 0.1
  Eigen::Vector2d error;
  error = TargetState - controllerOutput;
  EXPECT_LT(error.norm(), 0.1);
}

/**
 * @brief Write a test to check PID controller and ackerman steering
 * functionality for forward and 180 degree turn
 *
 */
TEST(PID, ForwardMotion180) {
  PID pid;
  Eigen::Matrix<double, 2, 1> Kp{0.3, 0.3};
  Eigen::Matrix<double, 2, 1> Ki{0.1, 0.1};
  Eigen::Matrix<double, 2, 1> Kd{0.05, 0.05};
  double dt{0.1};
  pid.setKp(Kp);
  pid.setKi(Ki);
  pid.setKd(Kd);
  pid.setDt(dt);
  double TargetVelocity{0};
  double TargetHeadingAngle{0};
  Eigen::Vector2d CurrentState{0, 0};
  TargetVelocity = 20.0;
  TargetHeadingAngle = 3.14;
  Eigen::Vector2d TargetState{TargetVelocity, TargetHeadingAngle};
  Eigen::Vector2d controllerOutput;
  controllerOutput = pid.ControllerLoop(TargetState, CurrentState);
  // Check output vector elements are in certain range or not or the error norm
  // between Target and output < 0.1
  Eigen::Vector2d error;
  error = TargetState - controllerOutput;
  EXPECT_LT(error.norm(), 0.1);
}

/**
 * @brief Write a test to check PID controller and ackerman steering
 * functionality for forward motion and right turn
 *
 */
TEST(PID, ForwardMotionRightTurn) {
  PID pid;
  Eigen::Matrix<double, 2, 1> Kp{0.3, 0.3};
  Eigen::Matrix<double, 2, 1> Ki{0.1, 0.1};
  Eigen::Matrix<double, 2, 1> Kd{0.05, 0.05};
  double dt{0.1};
  pid.setKp(Kp);
  pid.setKi(Ki);
  pid.setKd(Kd);
  pid.setDt(dt);
  double TargetVelocity{0};
  double TargetHeadingAngle{0};
  Eigen::Vector2d CurrentState{0, 0};
  TargetVelocity = 5.0;
  TargetHeadingAngle = -0.5;
  Eigen::Vector2d TargetState{TargetVelocity, TargetHeadingAngle};
  Eigen::Vector2d controllerOutput;
  controllerOutput = pid.ControllerLoop(TargetState, CurrentState);
  // Check output vector elements are in certain range or not or the error norm
  // between Target and output < 0.1
  Eigen::Vector2d error;
  error = TargetState - controllerOutput;
  EXPECT_LT(error.norm(), 0.1);
}
/**
 * @brief Write a test to check PID controller and ackerman steering
 * functionality for forward motion and Heading 180
 *
 */
TEST(PID, ForwardMotionHeading180) {
  PID pid;
  Eigen::Matrix<double, 2, 1> Kp{0.3, 0.3};
  Eigen::Matrix<double, 2, 1> Ki{0.1, 0.1};
  Eigen::Matrix<double, 2, 1> Kd{0.05, 0.05};
  double dt{0.1};
  pid.setKp(Kp);
  pid.setKi(Ki);
  pid.setKd(Kd);
  pid.setDt(dt);
  double TargetVelocity{0};
  double TargetHeadingAngle{0};
  Eigen::Vector2d CurrentState{0, 0};
  TargetVelocity = 5.0;
  TargetHeadingAngle = -3.14;
  Eigen::Vector2d TargetState{TargetVelocity, TargetHeadingAngle};
  Eigen::Vector2d controllerOutput;
  controllerOutput = pid.ControllerLoop(TargetState, CurrentState);
  // Check output vector elements are in certain range or not or the error norm
  // between Target and output < 0.1
  Eigen::Vector2d error;
  error = TargetState - controllerOutput;
  EXPECT_LT(error.norm(), 0.1);
}

/**
 * @brief Write a test to check PID controller and ackerman steering
 * functionality for forward motion only
 *
 */
TEST(PID, ForwardMotionOnly) {
  PID pid;
  Eigen::Matrix<double, 2, 1> Kp{0.3, 0.3};
  Eigen::Matrix<double, 2, 1> Ki{0.1, 0.1};
  Eigen::Matrix<double, 2, 1> Kd{0.05, 0.05};
  double dt{0.1};
  pid.setKp(Kp);
  pid.setKi(Ki);
  pid.setKd(Kd);
  pid.setDt(dt);
  double TargetVelocity{0};
  double TargetHeadingAngle{0};
  Eigen::Vector2d CurrentState{0, 0};
  TargetVelocity = 20.0;
  TargetHeadingAngle = 0.0;
  Eigen::Vector2d TargetState{TargetVelocity, TargetHeadingAngle};
  Eigen::Vector2d controllerOutput;
  controllerOutput = pid.ControllerLoop(TargetState, CurrentState);
  // Check output vector elements are in certain range or not or the error norm
  // between Target and output < 0.1
  Eigen::Vector2d error;
  error = TargetState - controllerOutput;
  EXPECT_LT(error.norm(), 0.1);
}

/**
 * @brief Write a test to check PID controller and ackerman steering
 * functionality for Reverse motion only
 *
 */
TEST(PID, ReverseMotionOnly) {
  PID pid;
  Eigen::Matrix<double, 2, 1> Kp{0.3, 0.3};
  Eigen::Matrix<double, 2, 1> Ki{0.1, 0.1};
  Eigen::Matrix<double, 2, 1> Kd{0.05, 0.05};
  double dt{0.1};
  pid.setKp(Kp);
  pid.setKi(Ki);
  pid.setKd(Kd);
  pid.setDt(dt);
  double TargetVelocity{0};
  double TargetHeadingAngle{0};
  Eigen::Vector2d CurrentState{0, 0};
  TargetVelocity = -5.0;
  TargetHeadingAngle = 0.0;
  Eigen::Vector2d TargetState{TargetVelocity, TargetHeadingAngle};
  Eigen::Vector2d controllerOutput;
  controllerOutput = pid.ControllerLoop(TargetState, CurrentState);
  // Check output vector elements are in certain range or not or the error norm
  // between Target and output < 0.1
  Eigen::Vector2d error;
  error = TargetState - controllerOutput;
  EXPECT_LT(error.norm(), 0.1);
}

/**
 * @brief Write a test to check PID controller and ackerman steering
 * functionality for Reverse motion and Left turn
 *
 */
TEST(PID, ReverseMotionLeftTest) {
  PID pid;
  Eigen::Matrix<double, 2, 1> Kp{0.3, 0.3};
  Eigen::Matrix<double, 2, 1> Ki{0.1, 0.1};
  Eigen::Matrix<double, 2, 1> Kd{0.05, 0.05};
  double dt{0.1};
  pid.setKp(Kp);
  pid.setKi(Ki);
  pid.setKd(Kd);
  pid.setDt(dt);
  double TargetVelocity{0};
  double TargetHeadingAngle{0};
  Eigen::Vector2d CurrentState{0, 0};
  TargetVelocity = -5.0;
  TargetHeadingAngle = 0.5;
  Eigen::Vector2d TargetState{TargetVelocity, TargetHeadingAngle};
  Eigen::Vector2d controllerOutput;
  controllerOutput = pid.ControllerLoop(TargetState, CurrentState);
  // Check output vector elements are in certain range or not or the error norm
  // between Target and output < 0.1
  Eigen::Vector2d error;
  error = TargetState - controllerOutput;
  EXPECT_LT(error.norm(), 0.1);
}

/**
 * @brief Write a test to check PID controller and ackerman steering
 * functionality for Reverse motion and Right turn
 *
 */
TEST(PID, ReverseMotionRightTest) {
  PID pid;
  Eigen::Matrix<double, 2, 1> Kp{0.3, 0.3};
  Eigen::Matrix<double, 2, 1> Ki{0.1, 0.1};
  Eigen::Matrix<double, 2, 1> Kd{0.05, 0.05};
  double dt{0.1};
  pid.setKp(Kp);
  pid.setKi(Ki);
  pid.setKd(Kd);
  pid.setDt(dt);
  double TargetVelocity{0};
  double TargetHeadingAngle{0};
  Eigen::Vector2d CurrentState{0, 0};
  TargetVelocity = -5.0;
  TargetHeadingAngle = -0.5;
  Eigen::Vector2d TargetState{TargetVelocity, TargetHeadingAngle};
  Eigen::Vector2d controllerOutput;
  controllerOutput = pid.ControllerLoop(TargetState, CurrentState);
  // Check output vector elements are in certain range or not or the error norm
  // between Target and output < 0.1
  Eigen::Vector2d error;
  error = TargetState - controllerOutput;
  EXPECT_LT(error.norm(), 0.1);
}

/**
 * @brief Write a test to check get wheel radius function in ackerman.hpp
 *
 */
TEST(Ackerman_Steering_Model, getWheelRadius) {
  double wheelRadius = 0.2;
  Ackerman_Steering_Model ackerman;
  ackerman.setWheelRadius(wheelRadius);
  EXPECT_EQ(ackerman.getWheelRadius(), wheelRadius);
}
/**
 * @brief Write a test to check get wheel base function in ackerman.hpp
 *
 */
TEST(Ackerman_Steering_Model, getWheelBase) {
  double wheelBase = 1.0;
  Ackerman_Steering_Model ackerman;
  ackerman.setWheelBase(wheelBase);
  EXPECT_EQ(ackerman.getWheelBase(), wheelBase);
}

/**
 * @brief Write a test to check get axle width function in ackerman.hpp
 *
 */
TEST(Ackerman_Steering_Model, getAxleWidth) {
  double axleWidth = 0.5;
  Ackerman_Steering_Model ackerman;
  ackerman.setAxleWidth(axleWidth);
  EXPECT_EQ(ackerman.getAxleWidth(), axleWidth);
}

/**
 * @brief Write a test to check setSteeringAngleAndCarVelocity Function
 *
 */
TEST(Ackerman_Steering_Model, AckermanCalc_StateUpdate) {
  Ackerman_Steering_Model ackerman;
  ackerman.setAxleWidth(2.0);
  ackerman.setWheelBase(4.0);
  ackerman.setWheelRadius(0.225);
  Eigen::Vector2d controllerOutput{
      1.5,
      0.15};  // Considering the same PID parameters in earlier test cases and
              // target velocity and heading angle of 5 and 0.5 respectively
  double dt = 0.1;
  ackerman.AckermanCalc_StateUpdate(controllerOutput, dt);
  Eigen::Vector2d state = ackerman.getVehicleState();
  EXPECT_NEAR(state[0], 0.325, 0.01);
  EXPECT_GT(state[1], 0);  // Checks heading is >0 since we set it to left turn
                           // which is positive
}
/**
 * @brief Write a test to check get vehicle state function in ackerman.hpp
 *
 */
TEST(Ackerman_Steering_Model, getVehicleState) {
  Eigen::Vector2d vehicleState(0.0, 0.0);
  Ackerman_Steering_Model ackerman;
  ackerman.setVehicleState(vehicleState);
  EXPECT_EQ(ackerman.getVehicleState(), vehicleState);
}
/**
 * @brief Write a test to check whether TimeVector is empty or not in PID.hpp
 *
 */
TEST(PID, CheckTimeVectorEmpty) {
  PID pid;
  // Check if the time vector is empty or not
  ASSERT_FALSE(pid.getTimeVector().empty());
}
/**
 * @brief Write a test to check whether StateVector is empty or not in PID.hpp
 *
 */
TEST(PID, CheckStateVectorEmpty) {
  PID pid;
  // Check if the time vector is empty or not
  ASSERT_FALSE(pid.getStateVector().empty());
}
