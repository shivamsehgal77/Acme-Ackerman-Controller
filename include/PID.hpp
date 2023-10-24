/**
 * @file PID.hpp
 * @author  Phase 0 - Shivam Sehgal (ssehgal7@umd.edu) - Driver,
 *                    Patrik Pordi (ppordi@umd.edu) - Navigator,
 *                    Darshit Desai (darshit@umd.edu) - Code designer
 *          Phase 1 - Shivam Sehgal (ssehgal7@umd.edu) - Navigator,
 *                    Patrik Pordi (ppordi@umd.edu) - Code designer,
 *                    Darshit Desai (darshit@umd.edu) - Driver
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
   * @param Kp
   * @param Ki
   * @param Kd
   * @param dt
   */
  PID(Eigen::Matrix<double, 2, 1> Kp, Eigen::Matrix<double, 2, 1> Ki,
      Eigen::Matrix<double, 2, 1> Kd, double dt)
      : Kp(Kp),
        Ki(Ki),
        Kd(Kd),
        dt(dt),
        PrevError(Eigen::Vector2d::Zero()),
        SumError(Eigen::Vector2d::Zero()) {}
  /**
   * @brief Set the Kp object
   *
   * @param Kp
   */
  void setKp(Eigen::Matrix<double, 2, 1> Kp);
  /**
   * @brief Set the Ki object
   *
   * @param Ki
   */
  void setKi(Eigen::Matrix<double, 2, 1> Ki);
  /**
   * @brief Set the Kd object
   *
   * @param Kd
   */
  void setKd(Eigen::Matrix<double, 2, 1> Kd);
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
  Eigen::Matrix<double, 2, 1> getKp();
  /**
   * @brief Get the Ki object
   *
   * @return Eigen::Matrix<double,2,3>
   */
  Eigen::Matrix<double, 2, 3> getKi();
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
   * @brief Get the Controller Values object
   *
   * @param TargetState
   * @param CurrentState
   * @return Eigen::Vector2d
   */
  Eigen::Vector2d getControllerValues(Eigen::Vector2d TargetState,
                                      Eigen::Vector2d CurrentState);

 private:
  Eigen::Matrix<double, 2, 1> Kp;
  Eigen::Matrix<double, 2, 1> Ki;
  Eigen::Matrix<double, 2, 1> Kd;
  double dt;
  Eigen::Vector2d PrevError;
  Eigen::Vector2d SumError;
};
