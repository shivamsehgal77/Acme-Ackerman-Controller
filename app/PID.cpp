/**
 * @file PID.cpp
 * @author Phase 0 - Shivam Sehgal (ssehgal7@umd.edu) - Driver, Patrik Pordi (ppordi@umd.edu) - Navigator, Darshit Desai (darshit@umd.edu) - Code designer
 * @brief 
 * @version 0.1
 * @date 2023-10-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */


# include "PID.hpp"
#include <eigen3/Eigen/Core>


/**
 * @brief Construct a new PID object.
 *
 * @param Kp - The proportional gain matrix.
 * @param Ki - The integral gain matrix.
 * @param Kd - The derivative gain matrix.
 * @param dt - The time step value.
 */
PID::PID(Eigen::Matrix<double, 2, 1> Kp, Eigen::Matrix<double, 2, 1> Ki,
         Eigen::Matrix<double, 2, 1> Kd, double dt)
    : Kp(Kp), Ki(Ki), Kd(Kd), dt(dt), PrevError(Eigen::Vector2d::Zero()),
      SumError(Eigen::Vector2d::Zero()) {
  // @TODO : Additional constructor initialization code, if needed
}

/**
 * @brief Set the Kp object.
 *
 * @param Kp - The new proportional gain matrix.
 */
void PID::setKp(Eigen::Matrix<double, 2, 1> Kp) {
  // @TODO: Implement the logic to set the proportional gain matrix.

}

void PID::setKi(Eigen::Matrix<double,2,3> Ki){
  
}

void PID::setKi(Eigen::Matrix<double,2,3> Kd){
  
}

void PID::setDt(double dt){
  
}

Eigen::Matrix<double,2,3> PID::getKp(){
  return Kp;
}

Eigen::Matrix<double,2,3> PID::getKi(){
  return Ki;
  
}

Eigen::Matrix<double,2,3> PID::getKd(){
  return Kd;
  
}

double getDt(){
  return dt;
  
}


/**
 * @brief Get the Controller Values object.
 *
 * @param TargetState - The target state as an Eigen::Vector2d.
 * @param CurrentState - The current state as an Eigen::Vector2d.
 * @return Eigen::Vector2d - The controller output.
 */
Eigen::Vector2d PID::getControllerValues(Eigen::Vector2d TargetState,
                                         Eigen::Vector2d CurrentState) {
  // @TODO: Implement the controller logic to calculate and return the
  // controller output.
  return Eigen::Vector2d(0, 0);
}
