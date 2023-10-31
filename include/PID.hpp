/**
 * @file PID.hpp
 * @author  Phase 0 - Shivam Sehgal (ssehgal7@umd.edu) - Driver,
 *                    Patrik Pordi (ppordi@umd.edu) - Navigator,
 *                    Darshit Desai (darshit@umd.edu) - Code designer
 *          Phase 1 - Shivam Sehgal (ssehgal7@umd.edu) - Navigator,
 *                    Patrik Pordi (ppordi@umd.edu) - Code designer,
 *                    Darshit Desai (darshit@umd.edu) - Driver
 *          Phase 2 - Shivam Sehgal (ssehgal7@umd.edu) - Code designer,
 *                    Patrik Pordi (ppordi@umd.edu) - Driver,
 *                    Darshit Desai (darshit@umd.edu) - Navigator
 * @brief PID controller header file.
 * @version 0.1
 * @date 2023-10-17
 *
 * @copyright Copyright (c) 2023 Darshit Desai, Patrik Pordi, Shivam Sehgal
 * This code is licensed under the MIT License. Please see the
 * accompanying LICENSE file for the full text of the license.
 *
 */

#pragma once

#include <eigen3/Eigen/Core>
#include <vector>
#include <iostream>

/**
 * @brief PID controller class
 *
 */
class PID {
 public:
  /**
   * @brief Construct a new PID object
   *
   */
  PID();
  /**
   * @brief Set the Kp object
   *
   * @param Kp_
   */
  void setKp(Eigen::Matrix<double, 2, 1> Kp_);
  /**
   * @brief Set the Ki object
   *
   * @param Ki_
   */
  void setKi(Eigen::Matrix<double, 2, 1> Ki_);
  /**
   * @brief Set the Kd object
   *
   * @param Kd_
   */
  void setKd(Eigen::Matrix<double, 2, 1> Kd_);
  /**
   * @brief Set the Dt object
   *
   * @param dt_
   */
  void setDt(double dt);
  /**
   * @brief Get the Kp object
   *
   * @return Eigen::Matrix<double,2,3>
   */
  Eigen::Matrix<double, 2, 1> getKp();
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
  Eigen::Matrix<double, 2, 1> getKd();
  /**
   * @brief Get the Dt object
   *
   * @return double
   */
  double getDt();
  /**
   * @brief Controller Loop function for executing the PID controller
   *
   * @param TargetState
   * @param CurrentState
   * @return Eigen::Vector2d
   */
   /**
   * @brief Get the State Vector object
   * 
   * @return std::vector<Eigen::Vector2d> 
   */
  std::vector<Eigen::Vector2d> getStateVector();

  /**
   * @brief Get the Time Vector object
   * 
   * @return std::vector<double> 
   */
  std::vector<double> getTimeVector();

  /**
   * @brief Controller Loop function for executing the PID controller
   * 
   * @param TargetState 
   * @param CurrentState 
   * @return Eigen::Vector2d 
   */
  Eigen::Vector2d ControllerLoop(Eigen::Vector2d TargetState,
                                      Eigen::Vector2d CurrentState);

 private:
  std::vector<Eigen::Vector2d> State_Vector;
  std::vector<double> Time_Vector;
  Eigen::Matrix<double, 2, 1> Kp;
  Eigen::Matrix<double, 2, 1> Ki;
  Eigen::Matrix<double, 2, 1> Kd;
  double dt;
};
