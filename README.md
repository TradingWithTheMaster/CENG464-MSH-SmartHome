# My Sweet Home (MSH) – CENG464 Term Project

## 🏠 Overview
My Sweet Home (MSH) is a smart home simulation system developed for the CENG464 Design Patterns with C++ course.  
It provides a menu‑driven interface that allows users to manage IoT devices, control home modes and states, and simulate emergency scenarios such as smoke detection, motion detection, and device failures.

This project demonstrates modular architecture, design patterns, and team-based integration using Git.

---

## ✅ Features
- Interactive command-line menu
- Add/remove devices:
  - Light
  - Camera
  - TV (Samsung/LG)
  - Smoke & Gas Detector
- Power devices on/off (with safety restrictions)
- Change home modes:
  - Normal
  - Evening
  - Party
  - Cinema
- Change system states:
  - Normal
  - Sleep
  - High Performance
  - Previous State
- Scenario simulation:
  - Smoke alarm with countdown
  - Motion detection (security system)
  - Police call
  - Light failure + SMS notification
- Configuration cloning for batch device creation
- Persistent logging of all operations

---

## ✅ Architecture Summary
### **Core Components**
- **MSHController** – Central coordinator of all operations
- **Managers**:
  - DeviceManager
  - ModeManager
  - StateManager
  - DetectionManager
  - SecurityManager
  - LogManager

### **Device Hierarchy**
- Base class: `Device`
- Derived classes:
  - `Light`
  - `Camera`
  - `TV` (Samsung, LG)
  - `Detector` (Smoke & Gas)

### **Design Patterns Used**
- **Factory Pattern** – Device creation
- **Singleton Pattern** – Managers & Controller
- **State Pattern** – System state transitions
- **Strategy Pattern** – Mode behavior

---

## ✅ Folder Structure
```
CENG464-MSH-SmartHome/
│
├── include/        # Header files
├── src/            # Source files
├── docs/           # Reports, scenario, screenshots
├── logs/           # Runtime logs
├── build/          # Build output
│
├── CMakeLists.txt
├── README.md
└── msh_log.txt
```

---

## ✅ Build Instructions

### **Using g++**
```bash
g++ -I include src/*.cpp -o msh.exe
```

### **Using CMake**
```bash
mkdir build
cd build
cmake ..
make
```

---

## ✅ Run the Program
```bash
./msh.exe
```

---

## ✅ Screenshots
All screenshots of:
- Menu operations  
- Device management  
- Mode/state changes  
- Scenario simulation  
- Git commit history  

are included in the `docs/screenshots/` folder and the final report.

---

## ✅ Team Members
- Khalid — Integrator, architecture, debugging, scenario simulation  
- Amin — Device modules, simulation logic  
- Anas — Menu system, state management  
- Mohamed — Device headers, Git workflow  

---

## ✅ Notes
This project was developed using:
- C++98  
- Git for version control  
- Modular architecture  
- Team-based integration  

The final report and presentation are included in the `docs/` folder.

