/**
 * @file PID.hpp
 * @author Phase- 0 : Shivam Sehgal (ssehgal7@umd.edu) - Driver, Patrik Pordi (ppordi@umd.edu) - Navigator, Darshit Desai (darshit@umd.edu) - Code designer
 * @brief 
 * @version 0.1
 * @date 2023-10-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

# pragma once

#include <eigen3/Eigen/Core>
# include <iostream>

/**
 * @brief PID controller class
 * 
 */
class PID {
 public:
  /**
   * @brief Construct a new PID object
   *
   * @param Kp
   * @param Ki
   * @param Kd
   * @param dt
   */
  PID(Eigen::Matrix<double, 2, 1> Kp, Eigen::Matrix<double, 2, 1> Ki,
      Eigen::Matrix<double, 2, 1> Kd, double dt);
  /**
   * @brief Set the Kp object
   * 
   * @param Kp 
   */
  void setKp(Eigen::Matrix<double,2,3> Kp);
  /**
   * @brief Set the Ki object
   * 
   * @param Ki 
   */
  void setKi(Eigen::Matrix<double,2,3> Ki);
  /**
   * @brief Set the Kd object
   * 
   * @param Kd 
   */
  void setKd(Eigen::Matrix<double,2,3> Kd);
  /**
   * @brief Set the Dt object
   * 
   * @param dt 
   */
  void setDt(double dt);
  /**
   * @brief Get the Kp object
   * 
   * @return Eigen::Matrix<double,2,3> 
   */
  Eigen::Matrix<double,2,3> getKp();
  /**
   * @brief Get the Ki object
   * 
   * @return Eigen::Matrix<double,2,3> 
   */
  Eigen::Matrix<double, 2, 1> getKi();
  /**
   * @brief Get the Kd object
   * 
   * @return Eigen::Matrix<double,2,3> 
   */
  Eigen::Matrix<double,2,3> getKd();
  /**
   * @brief Get the Dt object
   * 
   * @return double 
   */
  double getDt();
  /**
   * @brief Get the Controller Values object
   * 
   * @param TargetState 
   * @param CurrentState 
   * @return Eigen::Vector2d 
   */
  Eigen::Vector2d getControllerValues(Eigen::Vector3d TargetState, Eigen::Vector3d CurrentState);
  /**
   * @brief Reset the errors
   * 
   */
  void ResetErrors();

  private:
  Eigen::Matrix<double,2,3> Kp;
  Eigen::Matrix<double,2,3> Ki;
  Eigen::Matrix<double,2,3> Kd;
  double dt;
  Eigen::Vector3d PrevError = Eigen::Vector3d::Zero();
  Eigen::Vector3d SumError = Eigen::Vector3d::Zero();

};
