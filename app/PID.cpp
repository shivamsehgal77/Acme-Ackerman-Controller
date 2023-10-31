/**
 * @file PID.cpp
 * @author  Phase 0 - Shivam Sehgal (ssehgal7@umd.edu) - Driver,
 *                    Patrik Pordi (ppordi@umd.edu) - Navigator,
 *                    Darshit Desai (darshit@umd.edu) - Code designer
 *          Phase 1 - Shivam Sehgal (ssehgal7@umd.edu) - Navigator,
 *                    Patrik Pordi (ppordi@umd.edu) - Code designer,
 *                    Darshit Desai (darshit@umd.edu) - Driver
 *          Phase 2 - Shivam Sehgal (ssehgal7@umd.edu) - Code designer,
 *                    Patrik Pordi (ppordi@umd.edu) - Driver,
 *                    Darshit Desai (darshit@umd.edu) - Navigator
 * @brief PID controller implementation.
 * @version 0.1
 * @date 2023-10-17
 *
 * @copyright Copyright (c) 2023 Darshit Desai, Patrik Pordi, Shivam Sehgal
 * This code is licensed under the MIT License. Please see the
 * accompanying LICENSE file for the full text of the license.
 *
 */

#include "../include/PID.hpp"

#include <Eigen/src/Core/Matrix.h>
#include <eigen3/Eigen/Core>

#include <vector>

#include "../include/ackerman.hpp"

/**
 * @brief Construct a new PID object.
 *
 * @param Kp - The proportional gain matrix.
 * @param Ki - The integral gain matrix.
 * @param Kd - The derivative gain matrix.
 * @param dt - The time step value.
 */

PID::PID() {
  // @TODO : Additional constructor initialization code, if needed
  // Initalize the State and Time vectors
  State_Vector.push_back(Eigen::Vector2d(0.0, 0.0));
  Time_Vector.push_back(0.0);
}

/**
 * @brief Set the Kp object.
 *
 * @param Kp - The new proportional gain matrix.
 */
void PID::setKp(Eigen::Matrix<double, 2, 1> Kp_) {
  // @TODO: Implement the logic to set the proportional gain matrix.
  Kp = Kp_;
}

/**
 * @brief Set the Ki object.
 *
 * @param Ki - The new integral gain matrix.
 */
void PID::setKi(Eigen::Matrix<double, 2, 1> Ki_) {
  // @TODO: Implement the logic to set the integral gain matrix.
  Ki = Ki_;
}

/**
 * @brief Set the Kd object.
 *
 * @param Kd - The new derivative gain matrix.
 */
void PID::setKd(Eigen::Matrix<double, 2, 1> Kd_) {
  // @TODO: Implement the logic to set the derivative gain matrix.
  Kd = Kd_;
}

/**
 * @brief Set the Dt object.
 *
 * @param dt - The new time step value.
 */
void PID::setDt(double dt_) {
  // @TODO: Implement the logic to set the time step.
  dt = dt_;
}

/**
 * @brief Get the Kp object.
 *
 * @return Eigen::Matrix<double,2,1> - The proportional gain matrix.
 */
Eigen::Matrix<double, 2, 1> PID::getKp() {
  // @TODO: Implement the logic to get the Eigen proportional gain matrix.
  return Kp;
}

/**
 * @brief Get the Ki object.
 *
 * @return Eigen::Matrix<double,2,1> - The integral gain matrix.
 */
Eigen::Matrix<double, 2, 1> PID::getKi() {
  // @TODO: Implement the logic to get the Eigen integral gain matrix.
  return Ki;
}

/**
 * @brief Get the Kd object.
 *
 * @return Eigen::Matrix<double,2,1> - The derivative gain matrix.
 */
Eigen::Matrix<double, 2, 1> PID::getKd() {
  // @TODO: Implement the logic to get the Eigen derivative gain matrix.
  return Kd;
}

/**
 * @brief Get the Dt object.
 *
 * @return double - The time step value.
 */
double PID::getDt() {
  // @TODO: Implement the logic to get the time step.
  return dt;
}
/**
 * @brief Get the state vector object
 * 
 * @return std::vector<Eigen::Vector2d> 
 */
std::vector<Eigen::Vector2d> PID::getStateVector() {
  return State_Vector;
}
/**
 * @brief Get the time vector object
 * 
 * @return std::vector<double> 
 */
std::vector<double> PID::getTimeVector() {
  return Time_Vector;
}

/**
 * @brief Controller loop for executing the PID controller.
 *
 * @param TargetState - The target state as an Eigen::Vector2d.
 * @param CurrentState - The current state as an Eigen::Vector2d.
 * @return Eigen::Vector2d - The controller output as an Eigen::Vector2d.
 */
Eigen::Vector2d PID::ControllerLoop(Eigen::Vector2d TargetState,
                                         Eigen::Vector2d CurrentState) {
  // @TODO: Implement the controller logic to calculate and return the
  // controller output.
  Eigen::Vector2d error{0, 0};
  std::vector<Eigen::Vector2d> error_history;
  Ackerman_Steering_Model ackerman;
  ackerman.setWheelBase(4.0);
  ackerman.setAxleWidth(2.0);
  ackerman.setWheelRadius(0.225);
  ackerman.setVehicleState(CurrentState);
  error = TargetState - CurrentState;
  error_history.push_back(error);
  Eigen::Vector2d error_diff{0, 0};
  double total_time{0};
  State_Vector.push_back(CurrentState); // State vector for plotting
  Time_Vector.push_back(total_time); // Time vector for plotting
  while (error.norm() > 0.1) {
    Eigen::Vector2d error_sum{0, 0};
    if (error_history.size() > 1) { 
      for (auto i : error_history) {
        error_sum += i;
      }
      error_diff = error - error_history.at(error_history.size() - 2);
    }
    Eigen::Vector2d output = Kp.cwiseProduct(error) +
                             Ki.cwiseProduct(error_sum) * dt +
                             Kd.cwiseProduct(error_diff) / dt;
    if (TargetState[0] < 0) {
      output[1] = -output[1];
    }
    ackerman.AckermanCalc_StateUpdate(output, dt);
    CurrentState =  ackerman.getVehicleState();
    error = TargetState - CurrentState;
    error_history.push_back(error);
    total_time+=dt;
    State_Vector.push_back(CurrentState); // State vector for plotting
    Time_Vector.push_back(total_time); // Time vector for plotting
    std::cout << "Output: " << output << std::endl;
    std::cout << "Current State, Velocity: " << CurrentState[0] << " Current State, Heading:" << CurrentState[1] << " Time in seconds: " << total_time << std::endl;
  }
  return CurrentState;  
}
