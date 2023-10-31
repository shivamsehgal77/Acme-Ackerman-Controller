/**
 * @file main.cpp
 * @author  Phase 0 - Shivam Sehgal (ssehgal7@umd.edu) - Driver,
 *                    Patrik Pordi (ppordi@umd.edu) - Navigator,
 *                    Darshit Desai (darshit@umd.edu) - Code designer
 *          Phase 1 - Shivam Sehgal (ssehgal7@umd.edu) - Navigator,
 *                    Patrik Pordi (ppordi@umd.edu) - Code designer,
 *                    Darshit Desai (darshit@umd.edu) - Driver
 *          Phase 2 - Shivam Sehgal (ssehgal7@umd.edu) - Code designer,
 *                    Patrik Pordi (ppordi@umd.edu) - Driver,
 *                    Darshit Desai (darshit@umd.edu) - Navigator
 * @brief Main file for running the PID and Ackerman Steering Model
 * @version 0.1
 * @date 2023-10-17
 *
 * @copyright Copyright (c) 2023 Darshit Desai, Patrik Pordi, Shivam Sehgal
 * This code is licensed under the MIT License. Please see the
 * accompanying LICENSE file for the full text of the license.
 *
 */


#include <matplot/matplot.h>
#include <strings.h>

#include <eigen3/Eigen/Core>
#include <iostream>
#include <vector>

#include "../include/PID.hpp"

int main() {
  PID pid;

  Eigen::Matrix<double, 2, 1> Kp{0.3, 0.3};
  Eigen::Matrix<double, 2, 1> Ki{0.1, 0.1};
  Eigen::Matrix<double, 2, 1> Kd{0.05, 0.05};
  double dt{0.1};
  pid.setKp(Kp);
  pid.setKi(Ki);
  pid.setKd(Kd);
  pid.setDt(dt);
  double TargetVelocity{0};
  double TargetHeadingAngle{0};
  Eigen::Vector2d CurrentState{0, 0};
  std::cout << "Enter the Vehicle's Target State: " << std::endl;
  while (true) {
    std::cout << "Enter the Target Velocity = " << std::endl;
    std::cin >> TargetVelocity;
    // Write a condition check for Target Velocity is a number or not
    if (std::cin.fail()) {
      std::cout << "Invalid Input. Please enter a number." << std::endl;
      std::cin.clear();
      std::cin.ignore(256, '\n');
    } else {
      break;
    }
  }
  while (true) {
    std::cout << "Enter the Target Heading Angle = " << std::endl;
    std::cin >> TargetHeadingAngle;
    // Write a condition check for Target Heading Angle is a number or not
    if (std::cin.fail()) {
      std::cout << "Invalid Input. Please enter a number." << std::endl;
      std::cin.clear();
      std::cin.ignore(256, '\n');
    } else {
      break;
    }
  }
  Eigen::Vector2d TargetState{TargetVelocity, TargetHeadingAngle};
  Eigen::Vector2d FinalState{0, 0};
  FinalState = pid.ControllerLoop(TargetState, CurrentState);
  std::cout << "Final State = " << FinalState << std::endl;

  // plotting the graphs

  std::vector<double> target_velocity;  // Vector to store the velocity values
  std::vector<double>
      target_heading_angle;  // Vector to store the heading angle values
  std::vector<Eigen::Vector2d>
      State_Vector;                   // Vector to store the state values
  std::vector<double> plot_velocity;  // Vector to store the velocity values
  std::vector<double>
      plot_heading_angle;         // Vector to store the heading angle values
  std::vector<double> plot_time;  // Vector to store the time values
  State_Vector = pid.getStateVector();  // get the state vector
  plot_time = pid.getTimeVector();      // get the time vector

  for (int i = 0; i < State_Vector.size(); i++) {
    plot_velocity.push_back(State_Vector[i](0));
    plot_heading_angle.push_back(State_Vector[i](1));
    target_velocity.push_back(TargetState(0));
    target_heading_angle.push_back(TargetState(1));
  }

  auto vec_size{plot_velocity.size()};
  double last_velocity = plot_velocity.at(vec_size - 1);
  double last_heading_angle = plot_heading_angle.at(vec_size - 1);
  double last_time = plot_time.at(vec_size - 1);

  // adding  the last 50 values to get the steady state graph
  for (int i = 1; i < 51; i++) {
    plot_velocity.push_back(last_velocity);
    plot_heading_angle.push_back(last_heading_angle);
    target_velocity.push_back(TargetState(0));
    target_heading_angle.push_back(TargetState(1));
    plot_time.push_back(last_time + i * dt);
  }

  // plotting the  velocity vs time
  matplot::plot(plot_time, plot_velocity, "-r", plot_time, target_velocity,
                "-b");
  matplot::title("Velocity vs Time");
  matplot::xlabel("Time");
  matplot::ylabel("Velocity");
  matplot::save("Results/Visualization/Velocity_vs_Time.png");

  // plotting the heading angle vs time
  matplot::plot(plot_time, plot_heading_angle, "-r", plot_time,
                target_heading_angle, "-b");
  matplot::title("Heading Angle vs Time");
  matplot::xlabel("Time");
  matplot::ylabel("Heading Angle");
  matplot::save("Results/Visualization/Heading_Angle_vs_Time.png");

  return 0;
}
