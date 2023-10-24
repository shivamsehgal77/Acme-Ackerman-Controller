# Acme Ackerman Controller

[![Coverage Report](https://codecov.io/gh/shivamsehgal77/Acme-Ackerman-Controller/branch/main/graph/badge.svg)](https://codecov.io/gh/shivamsehgal77/Acme-Ackerman-Controller) 
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)
[![Build Status](https://github.com/shivamsehgal77/Acme-Ackerman-Controller/actions/workflows/run-unit-test-and-upload-codecov.yml/badge.svg)](https://github.com/shivamsehgal77/Acme-Ackerman-Controller/actions/workflows/run-unit-test-and-upload-codecov.yml)

## Overview

The three basic components for a functioning robotic system are perception, planning and controls. Based on the inputs from these 3 sub systems the robot's behavior is defined. In this project we have chosen the topic of controls and decided to design a software which acts as a module of a larger self-driving car software stack. The ackerman steering is the most widely used steering constraints in robots to large automobiles. To design a module which takes into account the steering constraints and designs a controller on top of it to achieve a goal pose of the vehicle queried by any other system of the robot like perception or navigation systems.

## Team 

### Phase 0
1. [Patrik Pordi](https://www.github.com/patrikpordi) - Navigator
2. [Shivam Sehgal](https://www.github.com/shivamsehgal77) - Driver
3. [Darshit Desai](https://www.github.com/darshit-desai) - Code designer

### Phase 1 (Changes coming soon for this phase)
1. [Patrik Pordi](https://www.github.com/patrikpordi) - Code designer
2. [Shivam Sehgal](https://www.github.com/shivamsehgal77) - Navigator
3. [Darshit Desai](https://www.github.com/darshit-desai) - Driver

## Phase 0:
During Phase 0, we initiated the project with a high-level design, focusing on UML, and created an activity diagram that includes classes. This diagram serves as a valuable tool for comprehending the project's process flow. Comprehensive explanations of the Phase 0 process and its implementation are available in a video accessible through this google drive [link](https://drive.google.com/file/d/1D6kjTWbVGHKaCZbz6bTfUVqyngHtdGbq/view?usp=share_link)
* The Quad Chart can be found [here](https://github.com/shivamsehgal77/Acme-Ackerman-Controller/tree/main/QuadChart/Initial_Phase0)
* The Project Proposal Report for Phase 0 can be found [here](https://github.com/shivamsehgal77/Acme-Ackerman-Controller/blob/main/Reports/Phase0/ENPM808X_Proposal_Phase0_AckermanSteeringControl.pdf)
* The Initial UML Diagrams are found [here](https://github.com/shivamsehgal77/Acme-Ackerman-Controller/tree/main/UML%20diagrams/Initial_Phase0)
* The Activity Diagram found [here](https://github.com/shivamsehgal77/Acme-Ackerman-Controller/blob/main/UML%20diagrams/Initial_Phase0/acme-ackerman-class-diagram.png)
![Acme Ackerman Class Diagram](UML-diagrams/Initial_Phase0/acme-ackerman-class-diagram.png)

## Phase 1:
During Phase 0 we did design and even added the stubs that we had to do for phase1. For phase1 in the first sprint meeting we decided to update the plan, correspondingly we changed UML class diagram and stubs. Product Backlog, Iteration backlog and work log excel sheet [Sheet](https://docs.google.com/spreadsheets/d/1ph1sYep433EigfkVelYI8igBHbYIN74LMEw9CF0V7-I/edit#gid=0 )
| Unique ID | Task                                              | Sprint | Estimated Time (min) |
|-----------|---------------------------------------------------|--------|----------------------|
| 1.1       | Research on Ackerman Steering                     | 1      | 60                   |
| 1.2       | Figuring out the state vectors                    | 1      | 30                   |
| 1.3       | Research on PID controller                        | 1      | 50                   |
| 1.4       | Writing up the dynamic equations                  | 1      | 30                   |
| 1.5       | Revisiting the project description on elms        | 1      | 20                   |
| 1.6       | Creating the GitHub repository                    | 1      | 10                   |
| 1.7       | Cloning cpp-boilerplate                           | 1      | 10                   |
| 1.8       | Creating the initial Activity diagram             | 1      | 30                   |
| 1.9       | Creating the UML diagram for Ackerman Steering    | 1      | 30                   |
| 2         | Creating the UML diagram for PID                  | 1      | 30                   |
| 2.1       | Creating the skeleton hpp files                   | 1      | 30                   |
| 2.2       | Revise the UML diagrams                           | 1      | 50                   |
| 2.3       | Create UML diagram for Robot class                | 1      | 20                   |
| 2.4       | Creating the skeleton hpp file for the new class  | 1      | 20                   |
| 2.5       | Create iteration 1 branch                         | 1      | 10                   |
| 2.6       | Selecting and adding the license file             | 1      | 30                   |
| 2.7       | Implementing the solitary test for PID class      | 1      | 20                   |
| 2.8       | Implementing the solitary test for Ackerman class | 1      | 30                   |
| 2.9       | Cpplint errors                                    | 1      | 10                   |
| 3         | Cppcheck errors                                   | 1      | 10                   |
| 3.1       | Revising PID hpp                                  | 1      | 40                   |
| 3.2       | Revising Ackerman hpp                             | 1      | 30                   |
| 3.3       | Updating the cpp files                            | 1      | 30                   |
| 3.4       | Updating the CMakeLists.txt                       | 1      | 30                   |
| 3.5       | Update Update run-unit-test-code-coverage.yml file to include eigen 3                          | 1      |            10          |
| 3.6       | Updating Readme.md                                | 1      | 30                   |

* The Revised UML Diagrams are found [here](https://github.com/shivamsehgal77/Acme-Ackerman-Controller/tree/main/UML%20diagrams/Revised_Phase1)

* The Activity Diagram found [here](https://github.com/shivamsehgal77/Acme-Ackerman-Controller/blob/main/UML%20diagrams/Revised_Phase1/acme-ackerman-class-diagram.png)
![Acme Ackerman Class Diagram](UML-diagrams/Revised_Phase1/acme-ackerman-class-diagram.png)
