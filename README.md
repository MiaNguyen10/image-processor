# Auto-Enhancing Image Processing System

This project implements an auto-enhancing image processing system using OpenCV and OpenMP. The system is designed to improve the brightness, contrast, and sharpness of digital images in bulk. It loads images from a specified input folder, applies enhancements, and saves the enhanced images to an output folder.

## Project Structure

```
image-processor
├── src
│   ├── main.cpp               # Entry point of the application
│   ├── ImageProcessor.cpp      # Implementation of the ImageProcessor class
│   ├── ImageProcessor.h        # Header file for the ImageProcessor class
│   ├── ImageEnhancer.cpp       # Implementation of the ImageEnhancer class
│   └── ImageEnhancer.h         # Header file for the ImageEnhancer class
├── input
│   └── .gitkeep               # Keeps the input directory in version control
├── output
│   └── .gitkeep               # Keeps the output directory in version control
├── CMakeLists.txt             # CMake configuration file
├── Makefile                   # Build instructions for the project
└── README.md                  # Documentation for the project
```

## Setup Instructions

1. **Install Dependencies**: Ensure that you have OpenCV and OpenMP installed on your system. You can install OpenCV using package managers or build it from source.

2. **Clone the Repository**: Clone this repository to your local machine.

3. **Build the Project**:
   - Navigate to the project directory.
   - Use CMake to configure the project:

     ```
     mkdir build
     cd build
     cmake ..
     ```

   - Compile the project using:

     ```
     cmake --build .  
     ```

## Usage Guidelines

1. Place the images you want to enhance in the `input` folder.
2. Run the application:

- Navigate to the project directory

```
    cd build/Debug
   .\ImageProcessor.exe 1.2 30.0 1.5 0.5
```

3. The enhanced images will be saved in the `output` folder.

## Functionalities

- **Brightness Enhancement**: Adjusts the brightness of the images.
- **Contrast Enhancement**: Improves the contrast levels in the images.
- **Sharpness Enhancement**: Increases the sharpness of the images for better clarity.
