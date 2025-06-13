#include "ImageProcessor.h"
#include "ImageEnhancer.h"
#include <opencv2/opencv.hpp>
#include <filesystem>
#include <vector>
#include <string>


void ImageProcessor::loadImages(const std::string& inputFolder) {
    for (const auto& entry : std::filesystem::directory_iterator(inputFolder)) {
        if (entry.is_regular_file()) {
            cv::Mat image = cv::imread(entry.path().string());
            if (!image.empty()) {
                images.push_back(image);
                imageNames.push_back(entry.path().filename().string());
            }
        }
    }
}

void ImageProcessor::processImages(double alpha, double beta, double sigma, double strength, bool parallel) {
    if (parallel) {
        ImageEnhancer::processImages(images, alpha, beta, sigma, strength);
    } else {
        for (auto& image : images) {
            ImageEnhancer::processImage(image, alpha, beta, sigma, strength);
        }
    }
}

void ImageProcessor::saveImages(const std::string& outputFolder) {
    for (size_t i = 0; i < images.size(); ++i) {
        cv::imwrite(outputFolder + "/" + imageNames[i], images[i]);
    }
}

std::vector<cv::Mat> ImageProcessor::getImages() const {
    return images;
}

void ImageProcessor::setImages(const std::vector<cv::Mat>& newImages) {
    images.clear();
    for (const auto& img : newImages) {
        images.push_back(img.clone());  // ensure deep copy
    }
}
