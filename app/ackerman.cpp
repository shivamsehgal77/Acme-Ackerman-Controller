/**
 * @file ackerman.cpp
 * @author  Phase 0 - Shivam Sehgal (ssehgal7@umd.edu) - Driver,
 *                    Patrik Pordi (ppordi@umd.edu) - Navigator,
 *                    Darshit Desai (darshit@umd.edu) - Code designer
 *          Phase 1 - Shivam Sehgal (ssehgal7@umd.edu) - Navigator,
 *                    Patrik Pordi (ppordi@umd.edu) - Code designer,
 *                    Darshit Desai (darshit@umd.edu) - Driver
 *          Phase 2 - Shivam Sehgal (ssehgal7@umd.edu) - Code designer,
 *                    Patrik Pordi (ppordi@umd.edu) - Driver,
 *                    Darshit Desai (darshit@umd.edu) - Navigator
 * @brief Ackerman steering model implementation.
 * @version 0.1
 * @date 2023-10-23
 *
 * @copyright Copyright (c) 2023 Darshit Desai, Patrik Pordi, Shivam Sehgal
 * This code is licensed under the MIT License. Please see the
 * accompanying LICENSE file for the full text of the license.
 *
 */

#include "../include/ackerman.hpp"

#include <eigen3/Eigen/src/Core/Matrix.h>

#include <eigen3/Eigen/Core>
#include <iostream>
#include <vector>
#include <math.h>

/**
 * @brief Construct a new Ackerman_Steering_Model object
 *
 */
Ackerman_Steering_Model::Ackerman_Steering_Model() {
  WheelVelocity = {0, 0};

}

/**
 * @brief Get the wheel radius.
 *
 * @return The wheel radius.
 */
double Ackerman_Steering_Model::getWheelRadius() {
  // @TODO: Implement the logic to get the wheel radius.
  return WheelRadius;
}

/**
 * @brief Get the wheel base.
 *
 * @return The wheel base.
 */
double Ackerman_Steering_Model::getWheelBase() {
  // @TODO: Implement the logic to get the wheel base.
  return WheelBase;
}

/**
 * @brief Get the axle width.
 *
 * @return The axle width.
 */
double Ackerman_Steering_Model::getAxleWidth() {
  // @TODO: Implement the logic to get the axle width.
  return AxleWidth;
}

/**
 * @brief Get the vehicle state.
 *
 * @return The vehicle state as an Eigen::Vector2d.
 */
Eigen::Vector2d Ackerman_Steering_Model::getVehicleState() {
  // @TODO: Implement the logic to get the vehicle state.
  return VehicleState;
}

/**
 * @brief Set the wheel base.
 *
 * @param length - The new wheel base value.
 */
void Ackerman_Steering_Model::setWheelBase(double length) {
  // @TODO: Implement the logic to set the wheel base.
  WheelBase = length;
}

/**
 * @brief Set the axle width.
 *  
 * @param width - The new axle width value.
 */
void Ackerman_Steering_Model::setAxleWidth(double width) {
  // @TODO: Implement the logic to set the axle width.
  AxleWidth = width;
}

/**
 * @brief Set the wheel radius.
 *
 * @param radius - The new wheel radius value.
 */
void Ackerman_Steering_Model::setWheelRadius(double radius) {
  // @TODO: Implement the logic to set the wheel radius.
  WheelRadius = radius;
}
/**
 * @brief Set the steering angle and car velocity based on controller output.
 *
 * @param controllerOutput - An Eigen::Vector2d containing steering angle and
 * car velocity.
 */
void Ackerman_Steering_Model::AckermanCalc_StateUpdate(
    Eigen::Vector2d controllerOutput, double dt) {
  // @TODO: Implement the logic to set the steering angle and wheel velocity and
  // also calculate the new vehicle heading and velocity.
  double BaseAngle = controllerOutput[1];
  double BaseVelocity = controllerOutput[0];
  double TurningRadius{0};
  double dtheta{0};
  if (BaseAngle > 0.001) {
    TurningRadius = WheelBase / tan(BaseAngle);
    // Index 0  corresponds to left wheel and Index 1 corresponds to right wheel
    SteeringAngle[0] = atan(WheelBase / (TurningRadius - (AxleWidth / 2))); //Left = inner wheel
    SteeringAngle[1] = atan(WheelBase / (TurningRadius + (AxleWidth / 2))); //right = outer wheel
    std::cout << "Steering Angles left turn: " << SteeringAngle[0] << " " << SteeringAngle[1] << std::endl;
    if (SteeringAngle[0] > 45 * M_PI / 180) {
      SteeringAngle[0] = 45 * M_PI / 180;
      SteeringAngle[1] = atan(1 / ((AxleWidth / WheelBase) + (1 / tan(SteeringAngle[0]))));
      std::cout << "Steering Angles left turn left wheel >45: " << SteeringAngle[0] << " " << SteeringAngle[1] << std::endl;
    }
    WheelVelocity[1] += BaseVelocity;
    dtheta = WheelRadius * WheelVelocity[1] * dt / (TurningRadius + (AxleWidth / 2));
    WheelVelocity[0] = dtheta * (TurningRadius - (AxleWidth / 2)) / (WheelRadius * dt);
    Eigen::Vector2d State = getVehicleState();
    // State[0] = std::abs(TurningRadius * dtheta) / dt;
    State[0] = TurningRadius * dtheta / dt;
    State[1] = State[1] + dtheta;
    setVehicleState(State);    
  } 
  else if (BaseAngle < -0.001) {
    TurningRadius = std::abs(WheelBase / tan(BaseAngle));   
    // Index 0  corresponds to left wheel and Index 1 corresponds to right wheel
    SteeringAngle[0] = -1 * atan(WheelBase / (TurningRadius + (AxleWidth / 2))); //Left = outer wheel
    SteeringAngle[1] = -1 * atan(WheelBase / (TurningRadius - (AxleWidth / 2))); //right = inner wheel
    std::cout << "Steering Angles right turn: " << SteeringAngle[0] << " " << SteeringAngle[1] << std::endl;
    if (SteeringAngle[1] < -1 * 45 * M_PI / 180) {
        SteeringAngle[1] = - 45 * M_PI / 180;
        SteeringAngle[0] = -1 * atan(1 / ((AxleWidth / WheelBase) + (1 / std::abs(tan(SteeringAngle[1])))));
        std::cout << "Steering Angles right turn right wheel >45: " << SteeringAngle[0] << " " << SteeringAngle[1] << std::endl;
    }
    WheelVelocity[0] += BaseVelocity; //Since left wheel is the outer wheel
    dtheta = WheelRadius * WheelVelocity[0] * dt / (TurningRadius + (AxleWidth / 2));
    WheelVelocity[1] = dtheta * (TurningRadius - (AxleWidth / 2)) / (WheelRadius * dt);
    Eigen::Vector2d State = getVehicleState();
    // State[0] = std::abs(TurningRadius * dtheta) / dt;
    State[0] = TurningRadius * dtheta / dt;
    State[1] = State[1] - dtheta;
    setVehicleState(State); 
  } else {
    std::cout << "Steering Angles straight: " << SteeringAngle[0] << " " << SteeringAngle[1] << std::endl;
    SteeringAngle = {0, 0};
    if (WheelVelocity[0] >= WheelVelocity[1]) {
      WheelVelocity[1] += BaseVelocity;
      WheelVelocity[0] = WheelVelocity[1];
    }
    else {
      WheelVelocity[0] += BaseVelocity;
      WheelVelocity[1] = WheelVelocity[0];
    }
    Eigen::Vector2d State = getVehicleState();
    State[0] = WheelVelocity[0] * WheelRadius;
    State[1] = State[1];
    setVehicleState(State);    
  }
}

/**
 * @brief Set the vehicle state.
 *
 * @param State - An Eigen::Vector2d representing the new vehicle state.
 */
void Ackerman_Steering_Model::setVehicleState(Eigen::Vector2d State) {
  // @TODO: Implement the logic to set the vehicle state.
  VehicleState = State;
}
