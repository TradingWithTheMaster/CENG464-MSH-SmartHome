#include "Detector.h"
#include <iostream>

Detector::Detector(int id,
                   const std::string& name,
                   DeviceType type,
                   bool critical)
    : Device(id, name, type),
      critical(critical) {
    // detectors are typically always active
    isActive = true;
}

void Detector::turnOn() {
    isActive = true;
    std::cout << "[Detector] " << name << " activated" << std::endl;
}

void Detector::turnOff() {
    if (critical) {
        std::cout << "[Detector] " << name
                  << " is critical and cannot be turned OFF"
                  << std::endl;
        return;
    }
    isActive = false;
    std::cout << "[Detector] " << name << " deactivated" << std::endl;
}

// -------- SmokeDetector --------

SmokeDetector::SmokeDetector(int id,
                             const std::string& name)
    : Detector(id, name, DeviceType::SmokeDetector, true) {}

std::string SmokeDetector::getStatus() const {
    return std::string("Smoke detector '") + name + "' is "
        + (isActive ? "ACTIVE" : "INACTIVE");
}

void SmokeDetector::testOperation() {
    std::cout << "[SmokeDetector] Testing " << name << std::endl;
}

// -------- GasDetector --------

GasDetector::GasDetector(int id,
                         const std::string& name)
    : Detector(id, name, DeviceType::GasDetector, true) {}

std::string GasDetector::getStatus() const {
    return std::string("Gas detector '") + name + "' is "
        + (isActive ? "ACTIVE" : "INACTIVE");
}

void GasDetector::testOperation() {
    std::cout << "[GasDetector] Testing " << name << std::endl;
}

// -------- Alarm --------

Alarm::Alarm(int id,
             const std::string& name)
    : Detector(id, name, DeviceType::Alarm, true) {}

void Alarm::turnOff() {
    // Alarm can be silenced but conceptually still “ready”
    std::cout << "[Alarm] " << name << " silenced" << std::endl;
}

std::string Alarm::getStatus() const {
    return std::string("Alarm '") + name + "' is "
        + (isActive ? "READY" : "DISABLED");
}

void Alarm::testOperation() {
    std::cout << "[Alarm] Testing " << name << std::endl;
}
