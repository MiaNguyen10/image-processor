# `src/` Directory – Source Code Overview

This directory contains all the core C++ source files for the **Auto-Enhancing Image Processing System**. The application enhances brightness, contrast, and sharpness of digital images in bulk using **OpenCV** for image manipulation and **OpenMP** for optional parallel processing.

---

## 📄 File Descriptions

### `main.cpp`
- **Purpose:** Entry point of the application.
- **Responsibilities:**
  - Accepts CLI parameters: `brightness (alpha)`, `contrast (beta)`, `sharpness (sigma, strength)`, and an optional `--sequential` flag.
  - Benchmarks and compares **parallel vs. sequential** processing performance.
  - Handles input and output folder paths.
  - Prints execution time and speedup ratio when both modes are run.

---

### `ImageProcessor.h` / `ImageProcessor.cpp`
- **Purpose:** Manages the overall image processing workflow.
- **Responsibilities:**
  - Load all images from the input folder.
  - Execute processing using either **sequential** or **parallel** enhancement functions based on the `parallel` flag.
  - Save enhanced images to the output directory (separate subfolders for comparison).
  - Support benchmarking by allowing images to be reset between runs (`getImages()`, `setImages()`).

---

### `ImageEnhancer.h` / `ImageEnhancer.cpp`
- **Purpose:** Defines and implements the image enhancement algorithms.
- **Functions:**
  - `enhanceBrightness(cv::Mat&, double alpha)`
  - `enhanceContrast(cv::Mat&, double beta)`
  - `enhanceSharpness(cv::Mat&, double sigma, double strength)`
  - `processImage()` – Enhances a single image
  - `processImages()` – Enhances a batch of images in **parallel using OpenMP**
- **Parallelism:** Enabled via OpenMP inside `processImages()` for multi-threaded enhancement.

---

## ⚙️ Design Principles

- **Modular Separation:** Processing logic (`ImageEnhancer`) is decoupled from I/O and workflow logic (`ImageProcessor`).
- **Benchmarking-Friendly:** Supports both processing modes and measures their execution times in one run.
- **Runtime Flexibility:** Users control enhancement parameters and mode via command-line flags.

---

## ▶️ Example CLI Usage (from `build/Debug/`)

### Run with default (parallel) mode:
```bash
./ImageProcessor 1.2 30.0 1.5 0.5
```
> Enhanced images will be saved in separate subfolders like output/parallel/ and output/sequential/ for easy comparison.

## Dependencies

- OpenCV (4.x)
- OpenMP
- C++17+