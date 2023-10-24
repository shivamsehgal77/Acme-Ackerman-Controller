/**
 * @file ackerman.hpp
 * @author Phase- 0 : Shivam Sehgal (ssehgal7@umd.edu) - Driver, Patrik Pordi (ppordi@umd.edu) - Navigator, Darshit Desai (darshit@umd.edu) - Code designer
 * @brief 
 * @version 0.1
 * @date 2023-10-17
 * 
 * @copyright Copyright (c) 2023
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
 double SteeringAngle;
 double VehicleVelocity;
 Eigen::Vector3d VehicleState;
 

public:
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
 * @brief Get the Vehicle Velocity object
 * 
 * @return double 
 */
 double getVehicleVelocity();

/**
 * @brief Get the Vehicle State object
 * 
 * @return Eigen::Vector3d 
 */
 Eigen::Vector3d getVehicleState();

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
 void setVehicleState(Eigen::Vector3d State);

/**
 * @brief calcuate ackerman parameters
 * 
 * @return Eigen::Vector3d 
 */
 Eigen::Vector3d calcAckermanParameters();

 /**
  * @brief check angle constrains on ackerman model
  * 
  * @return true 
  * @return false 
  */
 bool checkAngleConstraints();
};
