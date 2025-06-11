# `src/` Directory – Source Code Overview

This directory contains all the core C++ source files for the **Auto-Enhancing Image Processing System**. The application is designed to enhance brightness, contrast, and sharpness of digital images using OpenCV and OpenMP.

---

## File Descriptions

### `main.cpp`
- **Purpose:** Entry point of the application.
- **Features:**
  - Accepts CLI parameters: brightness (`alpha`), contrast (`beta`), sharpness (`sigma`, `strength`), and an optional `--sequential` flag.
  - Handles input/output folder paths.
  - Measures and prints processing time for benchmarking.

---

### `ImageProcessor.h` / `ImageProcessor.cpp`
- **Purpose:** Handles image batch operations.
- **Responsibilities:**
  - Load images from a folder
  - Call enhancement routines
  - Save processed images to an output folder
  - Offers both sequential and parallel processing based on a flag

---

### `ImageEnhancer.h` / `ImageEnhancer.cpp`
- **Purpose:** Provides core image enhancement logic.
- **Functions:**
  - `enhanceBrightness(cv::Mat&, double alpha)`
  - `enhanceContrast(cv::Mat&, double beta)`
  - `enhanceSharpness(cv::Mat&, double sigma, double strength)`
- **Parallelism:** Uses OpenMP in `processImages()` to enhance images concurrently.

---

## Design Principles

- **Modular Design:** Image processing logic is separated from I/O handling.
- **Parallel-Ready:** Toggled via a runtime flag; OpenMP enables scalable performance.
- **User-Controlled Parameters:** CLI allows fine-tuned control over enhancements.

---

## Example Usage (from `build/Debug/`)

```bash
./ImageProcessor 1.2 30.0 1.5 0.5
# Optional sequential mode
./ImageProcessor 1.2 30.0 1.5 0.5 --sequential
```

## Dependencies

- OpenCV (4.x)
- OpenMP
- C++17+