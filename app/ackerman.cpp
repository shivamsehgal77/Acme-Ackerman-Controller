/**
 * @file ackerman.cpp
 * @author Shivam Sehgal (ssehgal7@umd.edu)
 * @brief 
 * @version 0.1
 * @date 2023-10-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */


# include "ackerman.hpp"
#include <eigen3/Eigen/Core>
#include <iostream>
#include <vector>

double Ackerman_Steering_Model::getWheelBase(){
  return WheelBase;
}

double Ackerman_Steering_Model::getAxleWidth(){
  return AxleWidth;
}

double Ackerman_Steering_Model::getSteeringAngle(){
  return SteeringAngle;
}

double Ackerman_Steering_Model::getVehicleVelocity(){
  return VehicleVelocity;
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

void Ackerman_Steering_Model::setVehicleState(Eigen::Vector3d State){
  VehicleState = State;
}

Eigen::Vector3d calcAckermanParameters(){
return 0;
}

bool checkAngleConstraints(){
  return false;
}