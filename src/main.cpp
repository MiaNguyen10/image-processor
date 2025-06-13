#include <iostream>
#include <filesystem>
#include <opencv2/opencv.hpp>
#include "ImageProcessor.h"

int main(int argc, char* argv[]) {
    cv::utils::logging::setLogLevel(cv::utils::logging::LOG_LEVEL_ERROR);
    std::cout << "Program started" << std::endl;
  
    std::string inputFolder = "../../input/low";
    std::string outputFolder = "../../output/";
    // Default parameters for image processing

    double alpha = 1.0, beta = 0.0, sigma = 1.0, strength = 0.0;

    if (argc >= 5) {
        alpha = std::stod(argv[1]);
        beta = std::stod(argv[2]);
        sigma = std::stod(argv[3]);
        strength = std::stod(argv[4]);
    }

    ImageProcessor imageProcessor;
    try {
        // Load images once from disk
        imageProcessor.loadImages(inputFolder);

        // Store original images for reuse
        auto originalImages = imageProcessor.getImages();

        // 🔁 Run Parallel Mode
        imageProcessor.setImages(originalImages); // Reset to original
        auto start_parallel = std::chrono::high_resolution_clock::now();
        imageProcessor.processImages(alpha, beta, sigma, strength, true);
        auto end_parallel = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> parallel_time = end_parallel - start_parallel;

        // Save output of parallel run
        imageProcessor.saveImages(outputFolder + "/parallel");

        // 🔁 Run Sequential Mode
        imageProcessor.setImages(originalImages); // Reset again
        auto start_seq = std::chrono::high_resolution_clock::now();
        imageProcessor.processImages(alpha, beta, sigma, strength, false);
        auto end_seq = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> seq_time = end_seq - start_seq;

        // Save output of sequential run
        imageProcessor.saveImages(outputFolder + "/sequential");

        // Report speedup
        std::cout << "Parallel Time: " << parallel_time.count() << " seconds" << std::endl;
        std::cout << "Sequential Time: " << seq_time.count() << " seconds" << std::endl;
        std::cout << "Speedup: " << seq_time.count() / parallel_time.count() << "x faster\n";

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}