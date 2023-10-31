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

#include <eigen3/Eigen/Core>
#include <iostream>

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
    return 0; 
}
