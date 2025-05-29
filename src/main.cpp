#include <iostream>
#include <filesystem>
#include <opencv2/opencv.hpp>
#include "ImageProcessor.h"

int main(int argc, char* argv[]) {
    cv::utils::logging::setLogLevel(cv::utils::logging::LOG_LEVEL_ERROR);
    std::cout << "Program started" << std::endl;
    std::string inputFolder = "../../input/";
    std::string outputFolder = "../../output/";
    double alpha = 1.0, beta = 0.0, sigma = 1.0, strength = 0.0;

    if (argc >= 5) {
        alpha = std::stod(argv[1]);
        beta = std::stod(argv[2]);
        sigma = std::stod(argv[3]);
        strength = std::stod(argv[4]);
    }

    ImageProcessor imageProcessor;
    try {
        std::cout << "Before loadImages" << std::endl;
        imageProcessor.loadImages(inputFolder);
        std::cout << "Loaded images from " << inputFolder << std::endl;
        imageProcessor.processImages(alpha, beta, sigma, strength);
        imageProcessor.saveImages(outputFolder);
        std::cout << "Image processing completed successfully." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}