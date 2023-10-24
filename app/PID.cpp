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

void PID::setKp(Eigen::Matrix<double,2,3> Kp){

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

Eigen::Vector2d PID::getControllerValues(Eigen::Vector3d TargetState, Eigen::Vector3d CurrentState){
  return Eigen::Vector2d(0,0);

}

void PID::Reset(){
  
}
