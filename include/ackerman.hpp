/**
 * @file ackerman.hpp
 * @author Phase- 0 : Shivam Sehgal (ssehgal7@umd.edu) - Driver,
 *         Patrik Pordi (ppordi@umd.edu) - Navigator,
 *         Darshit Desai (darshit@umd.edu) - Code designer
 * @brief 
 * @version 0.1
 * @date 2023-10-17
 * 
 * @copyright Copyright (c)
 * 
 */

#pragma once

#include <eigen3/Eigen/Core>
#include <iostream>
#include <vector>

class Ackerman_Steering_Model {
private:
  double WheelBase;
  double AxleWidth;
  double WheelRadius;
  Eigen::Vector2d SteeringAngle;
  Eigen::Vector2d WheelVelocity;
  Eigen::Vector2d VehicleState;
public:
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
   Ackerman_Steering_Model(double WheelBase, double AxleWidth, double WheelRadius, Eigen::Vector2d SteeringAngle, Eigen::Vector2d WheelVelocity, Eigen::Vector2d VehicleState)
      : WheelBase(WheelBase), AxleWidth(AxleWidth), WheelRadius(WheelRadius), SteeringAngle(SteeringAngle), WheelVelocity(WheelVelocity), VehicleState(VehicleState) {}

/**
 * @brief Get the Wheel Radius object
 * 
 * @return double 
 */
double getWheelRadius();

/**
 * @brief Get the Wheel Base object
 * 
 * @return double 
 */
  double getWheelBase();

/**
 * @brief Get the Axle Width object
 * 
 * @return double 
 */
  double getAxleWidth();

/**
 * @brief Get the Steering Angle object
 * 
 * @return double 
 */
  double getSteeringAngle();

/**
 * @brief Get the Vehicle State object
 * 
 * @return Eigen::Vector2d 
 */
  Eigen::Vector2d getVehicleState();

/**
 * @brief Set the Wheel Base object
 * 
 * @param length 
 */
  void setWheelBase(double length);

/**
 * @brief Set the Axle Width object
 * 
 * @param width 
 */
  void setAxleWidth(double width);

/**
 * @brief Set the Wheel Radius object
 * 
 * @param radius 
 */
  void setWheelRadius(double radius);

/**
 * @brief Set the Steering Angle And Car Velocity object
 * 
 * @param controllerOutput 
 */
  void setSteeringAngleAndCarVelocity(Eigen::Vector2d controllerOutput);

/**
 * @brief Set the Vehicle State object
 * 
 * @param State 
 */
  void setVehicleState(Eigen::Vector2d State);

/**
 * @brief 
 * 
 * @return Eigen::Vector2d 
 */
  Eigen::Vector2d calcAckermanParameters();

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
  bool checkAngleConstraints();
};
