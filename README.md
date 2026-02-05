# 1. Project Overview

## 1.1 Project Name
> PTU Controller

## 1.2 Description
 > This project enables remote control of a Pan-Tilt Unit (PTU) from a computer that is not directly connected to the hardware. A Qt-based graphical user interface (GUI) runs on a separate machine and sends control commands over a network to a controller application running on the PTU-connected computer. The controller application interprets these commands, interfaces with the PTU hardware, and returns status updates to the GUI in real time.

## 1.3 Goals & Objectives
- Enable remote control of a Pan-Tilt Unit (PTU) from a separate machine
- Provide a user-friendly graphical interface for issuing PTU commands
- Transmit commands and receive status updates reliably over a network
- Maintain accurate, real-time feedback of PTU position and state

## 1.4 Key Features
- Asynchronous UDP socket communication using Qt networking
- Structured Protobuf messages for PTU commands, acknowledgements, and status updates
- External `.ini` configuration files for network settings and PTU parameters
- Decoupled GUI and controller applications to isolate hardware dependencies
- Real-time monitoring of PTU position and state

---

# 2. Requirements
## 2.1 Hardware Requirements
- Computer capable of running Red Hat Enterprise Linux (RHEL) 9.5
- Network interface for UDP communication between systems
- FLIR Pan-Tilt Unit (PTU)
- Physical connection between the controller machine and the PTU (e.g., serial interface)

## 2.2 Software & Tools
- Red Hat Enterprise Linux (RHEL) 9.5
- Qt Framework (Core, Widgets, Network)
- C++17 compatible compiler (e.g., GCC)
- Qt build system (qmake)
- Protobuf parsing and serialization

## 2.3 Constraints & Challenges
- System must operate reliably over a network with potential packet loss (UDP)
- PTU hardware access limited to the controller machine
- Real-time responsiveness required for PTU control
- Platform constrained to Red Hat Enterprise Linux (RHEL) 9.5
- Error handling required for network and hardware failures
- PTU must be connected prior to starting the controller application

---

# 3. Development Log

## 3.1 Research Links & Resources
| Date | Link | Notes |
| ---- | ---- | ----- |
| 2026 | [PTU Doc][PlDb] | _Documentation for PTU in use_ |

## 3.2 Key Decisions & Changes
- Chose UDP over TCP to minimize command latency
- Separated GUI and controller applications to isolate hardware dependencies
- Adopted Protobuf for quick transmission speeds

## 3.3 Issues & Solutions
* Issue: Inconsistent PTU response due to network packet loss
    * Solution: Added validation and periodic status updates from the controller

---

# 4. Development Process
## 4.1 Initial Steps
- Reviewed FLIR PTU hardware documentation
- Set up Qt development environment on RHEL 9.5
- Established basic UDP communication between machines
- Established serial communication between the controller application and the PTU
- Created .proto file with messages for incoming and outgoing flow

## 4.2 Iterative Development
- Implemented basic command messaging
- Added PTU status feedback
- Integrated GUI controls and visual indicators
- Improved error handling and logging
- Added Protobuf messages

## 4.3 Final Steps
- Verified end-to-end PTU control
- Cleaned up configuration handling
- Documented system architecture and workflows

---

# 5. Testing and Validation
## 5.1 Test Cases
| Test | Expected Result | Actual Result | Status |
| ---- | --------------- | ------------- | ------ |
| Set Pan Angle | PTU moves to target angle | PTU moved correctly | ✅ |
| Network Disconnect | System reports error state | Error handled properly | ✅ |
| Set Pan/Tilt Heading | Pan\Tilt Heading should be updated | Heading updated properly | ✅ |
| PTU Information Updates | Next message should contain updated information | Message updated correctly | ✅ |

## 5.2 Performance & Reliability
- Command latency observed to be within acceptable real-time limits
- System remained stable during extended operation
- PTU position updates consistently reflected actual hardware state

---

# 6. Final Documentation and Learnings
## 6.1 Finalized Steps
- Start PTU controller application on PTU connected computer
- Launch GUI and establish network connection
- Issue PTU commands and monitor status feedback

## 6.2 Lessons Learned
- Clear separation of hardware and UI logic improves system maintainability
- Qt signal/slot architecture simplifies asynchronous communication

## 6.3 Next Steps
- implement GRPC
---

# 7. Additional Notes
- Configuration parameters are stored in a `.ini` configuration file on Desktop
- System intended for internal use and testing


[//]: #
   [PlDb]: <https://movitherm.com/wp-content/uploads/2017/01/PTU-D100E-Manual.pdf?srsltid=AfmBOopyW3k_HJA_HpHfbNSGfjSn0PGs7012HxKF6C0jf06qaDy5CJf7>
   
