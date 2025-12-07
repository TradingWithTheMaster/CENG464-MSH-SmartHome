#include "Camera.h"
#include <iostream>

Camera::Camera(int id,
               const std::string& name,
               const std::string& resolution,
               int fps,
               bool nightVision,
               bool motionDetection)
    : Device(id, name, DeviceType::Camera),
      resolution(resolution),
      fps(fps),
      nightVision(nightVision),
      motionDetection(motionDetection) {}

void Camera::enableNightVision(bool enabled) {
    nightVision = enabled;
}

void Camera::enableMotionDetection(bool enabled) {
    motionDetection = enabled;
}

void Camera::turnOn() {
    isActive = true;
    std::cout << "[Camera] " << name << " powered ON" << std::endl;
}

void Camera::turnOff() {
    isActive = false;
    std::cout << "[Camera] " << name << " powered OFF" << std::endl;
}

std::string Camera::getStatus() const {
    return std::string("Camera '") + name + "' is "
        + (isActive ? "ON" : "OFF")
        + " (" + resolution + "@" + std::to_string(fps) + "fps"
        + ", nightVision=" + (nightVision ? "ON" : "OFF")
        + ", motionDetection=" + (motionDetection ? "ON" : "OFF")
        + ")";
}

void Camera::testOperation() {
    std::cout << "[Camera] Testing " << name << std::endl;
}
