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

/**
 * @brief Construct a new Ackerman_Steering_Model object
 *
 */
Ackerman_Steering_Model::Ackerman_Steering_Model() {

}

/**
 * @brief Get the wheel radius.
 *
 * @return The wheel radius.
 */
double Ackerman_Steering_Model::getWheelRadius() {
  // @TODO: Implement the logic to get the wheel radius.
  return 0.0;
}

/**
 * @brief Get the wheel base.
 *
 * @return The wheel base.
 */
double Ackerman_Steering_Model::getWheelBase() {
  // @TODO: Implement the logic to get the wheel base.
  return 0.0;
}

/**
 * @brief Get the axle width.
 *
 * @return The axle width.
 */
double Ackerman_Steering_Model::getAxleWidth() {
  // @TODO: Implement the logic to get the axle width.
  return 0.0;
}

/**
 * @brief Get the vehicle state.
 *
 * @return The vehicle state as an Eigen::Vector2d.
 */
Eigen::Vector2d Ackerman_Steering_Model::getVehicleState() {
  // @TODO: Implement the logic to get the vehicle state.
  return {0, 0};
}

/**
 * @brief Set the wheel base.
 *
 * @param length - The new wheel base value.
 */
void Ackerman_Steering_Model::setWheelBase(double length) {
  // @TODO: Implement the logic to set the wheel base.

}

/**
 * @brief Set the axle width.
 *  
 * @param width - The new axle width value.
 */
void Ackerman_Steering_Model::setAxleWidth(double width) {
  // @TODO: Implement the logic to set the axle width.

}

/**
 * @brief Set the wheel radius.
 *
 * @param radius - The new wheel radius value.
 */
void Ackerman_Steering_Model::setWheelRadius(double radius) {
  // @TODO: Implement the logic to set the wheel radius.

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
