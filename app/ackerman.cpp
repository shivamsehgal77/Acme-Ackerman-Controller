/**
 * @file ackerman.cpp
 * @author Phase 0 - Shivam Sehgal (ssehgal7@umd.edu) - Driver, Patrik Pordi (ppordi@umd.edu) - Navigator, Darshit Desai (darshit@umd.edu) - Code designer
 * @brief 
 * @version 0.1
 * @date 2023-10-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */


# include "ackerman.hpp"
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/src/Core/Matrix.h>
#include <iostream>
#include <vector>


/**
 * @brief Construct a new Ackerman_Steering_Model object
 *
 * @param WheelBase
 * @param AxleWidth
 * @param WheelRadius
 * @param SteeringAngle
 * @param WheelVelocity
 * @param VehicleState
 */
Ackerman_Steering_Model::Ackerman_Steering_Model(
    double WheelBase, double AxleWidth, double WheelRadius,
    Eigen::Vector2d SteeringAngle, Eigen::Vector2d WheelVelocity,
    Eigen::Vector2d VehicleState)
    : WheelBase(WheelBase),
      AxleWidth(AxleWidth),
      WheelRadius(WheelRadius),
      SteeringAngle(SteeringAngle),
      WheelVelocity(WheelVelocity),
      VehicleState(VehicleState) {}

/**
 * @brief Get the wheel radius.
 *
 * @return The wheel radius.
 */
double Ackerman_Steering_Model::getWheelRadius() {
  // @TODO: Implement the logic to get the wheel radius.
  return 0;
}

double Ackerman_Steering_Model::getAxleWidth(){
  return AxleWidth;
}

double Ackerman_Steering_Model::getSteeringAngle(){
  return SteeringAngle;
}

/**
 * @brief Get the steering angle.
 *
 * @return The steering angle.
 */
Eigen::Vector2d Ackerman_Steering_Model::getSteeringAngle() {
  // @TODO: Implement the logic to get the steering angle which is Eigen2d
  // vector.
  return Eigen::Vector2d(0, 0);
}

Eigen::Vector3d Ackerman_Steering_Model::getVehicleState(){
  return VehicleState;
} 

void Ackerman_Steering_Model::setWheelBase(double length){
  WheelBase = length;
}

void Ackerman_Steering_Model::setAxleWidth(double width){
  AxleWidth = width;
}

void Ackerman_Steering_Model::setSteeringAngleAndCarVelocity(Eigen::Vector2d controllerOutput){
  SteeringAngle = controllerOutput(0);
  VehicleVelocity = controllerOutput(1);
}

/**
 * @brief Set the steering angle and car velocity based on controller output.
 *
 * @param controllerOutput - An Eigen::Vector2d containing steering angle and
 * car velocity.
 */
void Ackerman_Steering_Model::setSteeringAngleAndCarVelocity(
    Eigen::Vector2d controllerOutput) {
  // @TODO: Implement the logic to set the steering angle and wheel velocity and
  // also calculate the new vehicle heading and velocity.
  Eigen::Vector2d ackermanParameters = calcAckermanParameters();

}

Eigen::Vector3d calcAckermanParameters(){
return 0;
}

/**
 * @brief Calculate Ackerman parameters.
 *
 * @return An Eigen::Vector2d containing calculated parameters.
 */
Eigen::Vector2d Ackerman_Steering_Model::calcAckermanParameters() {
  // @TODO: Implement the logic to calculate Ackerman parameters.
    return Eigen::Vector2d(0, 0);
}

/**
 * @brief Check angle constraints.
 *
 * @return true if angle constraints are met, false otherwise.
 */
bool Ackerman_Steering_Model::checkAngleConstraints() {
  // @TODO: Implement the logic to check angle constraints.
  return false;  // Modify the return value based on your constraints.

}
