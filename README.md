
# Auto-Enhancing Image Processing System

This project implements a batch image enhancement tool using **C++**, **OpenCV**, and **OpenMP**. It automatically improves the **brightness**, **contrast**, and **sharpness** of digital images in bulk. The system reads images from an input folder, processes them with enhancement algorithms, and writes the results to an output folder.

---

## Project Structure

```
image-processor/
├── src/                    # Source code directory
│   ├── main.cpp            # Application entry point
│   ├── ImageProcessor.h/cpp  # Image loading, saving, and processing manager
│   ├── ImageEnhancer.h/cpp   # Enhancement algorithms (brightness, contrast, sharpness)
├── input/                  # Place input images here
│   └── .gitkeep
├── output/                 # Output folder for enhanced images
│   ├── .gitkeep
│   ├── parallel
│   └── sequential
├── CMakeLists.txt          # CMake build configuration
├── Makefile                # Alternative build instructions
└── README.md               # Project documentation
```

---

## Setup Instructions

### 1. Install Dependencies

Ensure you have the following installed on your system:

- **C++ Compiler** with C++17 support (e.g., `g++`, `clang++`, MSVC)
- **OpenCV** (recommended version: 4.x)
- **OpenMP** support (often included with GCC/Clang)

> On Ubuntu:
> ```bash
> sudo apt update
> sudo apt install libopencv-dev build-essential cmake
> ```

> On Windows (with MSVC + vcpkg):
> ```bash
> vcpkg install opencv4
> ```

> Alternative:

### Windows OpenCV Runtime Setup (DLL Copying)

If you're using OpenCV on Windows and building with Visual Studio or CMake, make sure the required OpenCV DLLs are available next to your `ImageProcessor.exe`.

To automate this, we've added a `post-build` step in the `CMakeLists.txt` to copy the necessary DLL files:

```cmake
add_custom_command(TARGET ImageProcessor POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "C:/opencv/build/x64/vc16/bin/opencv_world4110d.dll"
        $<TARGET_FILE_DIR:ImageProcessor>
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "C:/opencv/build/x64/vc16/bin/opencv_videoio_ffmpeg4110_64.dll"
        $<TARGET_FILE_DIR:ImageProcessor>
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "C:/opencv/build/x64/vc16/bin/opencv_videoio_msmf4110_64.dll"
        $<TARGET_FILE_DIR:ImageProcessor>
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "C:/opencv/build/x64/vc16/bin/opencv_videoio_msmf4110_64d.dll"
        $<TARGET_FILE_DIR:ImageProcessor>
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "C:/opencv/build/x64/vc16/bin/opencv_world4110.dll"
        $<TARGET_FILE_DIR:ImageProcessor>
)
```
> This ensures that required OpenCV runtime DLLs are copied to the output folder (e.g., build/Debug/) automatically after every successful build.

> Adjust the paths if your OpenCV version or build location differs.
---

### 2. Clone the Repository

```bash
git clone https://github.com/MiaNguyen10/image-processor.git
cd image-processor
```

---

### 3. Build the Project (Using CMake)

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

> Output binary will be created in `build/Debug` or `build/Release` depending on your compiler.

---

## Usage Instructions

### 1. Prepare Input

Place the images you want to enhance inside the `input/` folder.

---

### 2. Run the Executable

Navigate to the build directory and run the program with CLI parameters:

```bash
cd build/Debug  # or build/Release depending on your platform
./ImageProcessor 1.2 30.0 1.5 0.5
```

---

### CLI Parameters

```bash
./ImageProcessor <brightness> <contrast> <sigma> <sharpness> [--sequential]
```

- `brightness` (`alpha`): e.g., `1.2` — 1.0 means no change
- `contrast` (`beta`): e.g., `30.0` — 0.0 means no change
- `sigma`: blur strength for sharpening, e.g., `1.5`
- `sharpness`: amount of sharpening to apply, e.g., `0.5`
- `--sequential`: *(optional)* runs in sequential (non-parallel) mode for benchmarking

---

### 3. Output

Enhanced images will be saved automatically in the `output/` folder with the same filenames as the original input images.

---

## Benchmarking (Speedup Measurement)

To compare **parallel** vs **sequential** performance:

```bash
# will run both parallel and sequential together
./ImageProcessor 1.2 30.0 1.5 0.5

```

The terminal will output:

```
Parallel Time: XX.XX seconds
Sequential Time: XX.XX seconds
Speedup: Nx faster

```

---

## Functionalities

- **Brightness Enhancement** — Multiplies pixel values by a given factor.
- **Contrast Enhancement** — Adjusts contrast using a linear offset.
- **Sharpness Enhancement** — Applies unsharp masking via Gaussian blur.

---

## 🔍 Source Code Details

To learn more about the structure and functions inside the `src/` directory, including how the image enhancement and processing logic is implemented, refer to the [src/README.md](src/README.md) file.

This includes:
- Class and method descriptions
- How parallel vs sequential processing is handled
- File responsibilities and usage

---


## Recommended Test Datasets

- [LOL Dataset (Low-Light)](https://www.kaggle.com/datasets/soumikrakshit/lol-dataset)
- [CID2013 (Degraded Images)](https://live.ece.utexas.edu/research/Quality/CID2013/)
- [Darmstadt Noise Dataset (DND)](https://noise.visinf.tu-darmstadt.de/)

Place sample images in the `input/` folder before testing.

---

## Credits & References

- **OpenCV** — https://opencv.org
- **OpenMP** — https://www.openmp.org
- **Dataset References**:
  - https://www.kaggle.com/datasets/soumikrakshit/lol-dataset
  - E. C. Larson and D. M. Chandler, *Journal of Electronic Imaging*, 2010 (LC10)

---

## Authors

- Ha Nguyen (ha.t.nguyen@abo.fi)  
- Rifat Bin Monsur (rifat.binmonsur@abo.fi)
