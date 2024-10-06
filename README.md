# Smart CCTV Camera System

## Overview
This project is a smart CCTV system developed as part of a final project for a Bootcamp in collaboration with Mobileye (September – November 2023). The system utilizes a **Raspberry Pi** to capture and transmit images to a server using **gRPC**. It features a graphical user interface (GUI) developed using **Qt**, and the project code is primarily written in **C++** with **CMake** for build automation and **Docker** for containerization.

## Features
- **Image Transmission**: Captures images using a Raspberry Pi and transmits them to a central server via gRPC.
- **GUI**: User-friendly interface for monitoring and controlling the system, built using Qt.
- **Cross-Platform Compatibility**: Utilizes Docker for easy deployment across different platforms.
- **Build Automation**: CMake is used for managing the build process and dependencies.

## Technologies Used
- **C++**: Core programming language for system logic and image processing.
- **gRPC**: Remote procedure call (RPC) framework used for communication between the Raspberry Pi and the server.
- **Qt**: Framework for creating the GUI.
- **CMake**: Build automation tool.
- **Docker**: Containerization for easy setup and consistent environment management.

## Installation and Setup

### Prerequisites
- Raspberry Pi (for image capture)
- Docker
- CMake
- Qt (for building the GUI)
- gRPC libraries

### Steps
1. **Clone the repository**:
    ```bash
    git clone https://github.com/your-repo/smart-cctv-system.git
    ```
2. **Build the project**:
    ```bash
    mkdir build
    cd build
    cmake ..
    make
    ```
3. **Run the application**:
    - Start the Docker container for the server:
    ```bash
    docker-compose up
    ```
    - Launch the client application (Qt GUI):
    ```bash
    ./client
    ```

## Usage
- The system will automatically start capturing images and transmitting them to the server.
- The GUI allows the user to monitor the camera feed, adjust settings, and view logs.

## Future Improvements
- **AI-based Motion Detection**: Implement real-time AI-based motion detection for more efficient event monitoring.
- **Cloud Integration**: Add support for cloud storage and remote access.
- **Multi-Camera Support**: Extend the system to support multiple cameras.

## Contributors
- **[Your Name]** - Project lead and developer.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
