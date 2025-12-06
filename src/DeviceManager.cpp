#include "../include/DeviceManager.h"
#include "../include/LogManager.h"

DeviceManager::DeviceManager(LogManager* logger)
    : log_(logger) {
    if (log_) log_->log("INFO", "DeviceManager initialized.");
}

DeviceManager::~DeviceManager() {
    if (log_) log_->log("INFO", "DeviceManager shutting down.");
}

void DeviceManager::addDevice(const std::string& name) {
    devices_[name] = false;
    if (log_) log_->log("INFO", "Device added: " + name);
}

void DeviceManager::removeDevice(const std::string& name) {
    devices_.erase(name);
    if (log_) log_->log("INFO", "Device removed: " + name);
}

void DeviceManager::setPowerState(const std::string& name, bool on) {
    auto it = devices_.find(name);
    if (it != devices_.end()) {
        it->second = on;
        if (log_) log_->log("INFO", std::string("Power ") + (on?"ON":"OFF") + " for " + name);
    } else {
        if (name == "AllLights") {
            for (auto &p : devices_) {
                if (p.first.find("Light") != std::string::npos) p.second = on;
            }
            if (log_) log_->log("INFO", std::string("Power ") + (on?"ON":"OFF") + " for AllLights");
        } else if (log_) {
            log_->log("WARN", "Unknown device: " + name);
        }
    }
}

std::string DeviceManager::getStatus() {
    std::string out;
    for (auto &p : devices_) out += p.first + "=" + (p.second?"ON":"OFF") + "; ";
    if (out.empty()) out = "No devices registered.";
    if (log_) log_->log("INFO", "Device status requested.");
    return out;
}

void DeviceManager::simulateLightFailure(const std::string& name) {
    if (log_) log_->log("ERROR", "Light failure on " + name + ". Sending SMS to owner.");
}
