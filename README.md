# Dino Skull Capacitive Sensor Project

A capacitive sensor system for a dino skull that detects when a hand is close and triggers the jaw to snap shut. The system uses a servo to open the jaw but relies on an elastic band for closing, ensuring maximum safety with minimal force.

## 🦕 Project Overview

This project creates an interactive dino skull that:
- Uses capacitive touch sensing to detect hand proximity
- Opens the jaw with a servo motor
- Closes the jaw with an elastic band (safe, low-force mechanism)
- Provides visual feedback with LED indicators
- Ensures safety - never traps fingers or causes harm

## 🔧 Hardware Requirements

### Main Controller
- **ESP32-S3 DevKitC-1** (or compatible ESP32-S3 board)
- Built-in capacitive touch sensors (GPIO1-GPIO14)
- USB-C for programming and power

### Actuators
- **Servo Motor** - Opens the jaw (controlled by ESP32-S3)
- **Elastic Band** - Closes the jaw (passive, safe mechanism)

### Sensors
- **Capacitive Electrodes** - Copper sheets or conductive material
- **Optional: Additional sensors** for enhanced detection

### Power
- USB power supply or battery pack
- Servo power requirements (may need external power supply)

## 📁 Project Structure

```
xavier-dino-skull/
├── platformio.ini          # PlatformIO configuration
├── src/
│   └── main.cpp            # Main application code
├── poc/                    # Proof of concept (Arduino IDE)
│   ├── finger-detector-test.ino
│   ├── README.md
│   └── datasheets/
└── README.md               # This file
```

## 🚀 Quick Start

### Prerequisites
- [PlatformIO Core](https://platformio.org/install) or [PlatformIO IDE](https://platformio.org/platformio-ide)
- ESP32-S3 board
- USB-C cable

### Building and Flashing

1. **Clone/Download the project**
   ```bash
   cd xavier-dino-skull
   ```

2. **Build the project**
   ```bash
   pio run
   ```

3. **Flash to ESP32-S3**
   ```bash
   pio run --target upload
   ```

4. **Monitor serial output**
   ```bash
   pio device monitor
   ```

### Expected Behavior
- On startup, the built-in LED will flash 4 times
- Serial output will show initialization messages
- System ready for capacitive sensor implementation

## 🔬 Proof of Concept

The `poc/` folder contains a working proof of concept built with Arduino IDE that demonstrates:
- ESP32-S3 capacitive touch sensing
- External electrode configuration
- Adaptive baseline calibration
- Runtime parameter tuning via CLI
- Saturation prevention for large electrodes

**Key Learnings from POC:**
- ESP32-S3 touch values **increase** when touched (opposite of ESP32)
- External electrodes require reduced sensitivity to prevent saturation
- Detection thresholds are very low (~0.2%) for large electrodes
- USB CDC On Boot must be enabled for convenient development

## 🎯 Implementation Plan

### Phase 1: Basic Setup ✅
- [x] PlatformIO project structure
- [x] LED flash on startup
- [x] Basic serial communication

### Phase 2: Capacitive Sensing
- [ ] Integrate capacitive touch detection from POC
- [ ] Configure multiple touch sensors for different jaw areas
- [ ] Implement proximity detection (not just touch)
- [ ] Add calibration routines

### Phase 3: Servo Control
- [ ] Servo motor integration
- [ ] Jaw opening mechanism
- [ ] Position feedback and control
- [ ] Safety limits and emergency stop

### Phase 4: Safety Systems
- [ ] Elastic band tension monitoring
- [ ] Force limiting mechanisms
- [ ] Emergency release systems
- [ ] User presence detection

### Phase 5: Advanced Features
- [ ] Multiple detection zones
- [ ] Gesture recognition
- [ ] Audio feedback
- [ ] Power management
- [ ] Remote monitoring

## ⚙️ Configuration

### PlatformIO Settings
The project is configured for ESP32-S3 with:
- **Board**: esp32-s3-devkitc-1
- **Framework**: Arduino
- **USB CDC On Boot**: Enabled (for convenient serial monitoring)
- **Upload Speed**: 921600 baud
- **Monitor Speed**: 115200 baud

### Touch Sensor Configuration
Based on POC learnings:
```cpp
// Reduced sensitivity for external electrodes
touchSetCycles(0x1000, 0x1000);

// Low detection threshold for large electrodes
float THRESHOLD = 0.002f;  // 0.2%
```

## 🛡️ Safety Considerations

### Primary Safety Features
1. **Elastic Band Closure** - Low force, cannot cause injury
2. **Servo Opening Only** - No servo power for closing
3. **Proximity Detection** - Warns before closing
4. **Emergency Stop** - Immediate release capability

### Safety Guidelines
- Maximum closing force limited by elastic band
- Servo only opens jaw, never closes it
- Multiple detection zones prevent accidental triggers
- Clear visual/audio warnings before action
- Easy manual override and emergency stop

## 🔧 Development Notes

### ESP32-S3 Specific Considerations
- Touch sensor behavior is opposite to ESP32
- USB CDC On Boot must be enabled
- Reduced sensitivity needed for external electrodes
- Very low detection thresholds for large electrodes

### Debugging
- Use serial monitor for real-time feedback
- LED indicators for system status
- CLI commands for runtime parameter tuning
- Saturation detection and warnings

## 📚 Resources

### Documentation
- [ESP32-S3 Datasheet](poc/datasheets/esp32-s3_datasheet_en.pdf)
- [ESP32-S3 Technical Reference](poc/datasheets/esp32-s3_technical_reference_manual_en.pdf)
- [ESP32-S3 WROOM Module](poc/datasheets/esp32-s3-wroom-1_wroom-1u_datasheet_en.pdf)
- [Pinout Diagram](poc/datasheets/ESP32S3_Pinout.png)

### PlatformIO
- [PlatformIO Documentation](https://docs.platformio.org/)
- [ESP32-S3 Platform](https://docs.platformio.org/en/latest/platforms/espressif32.html)

## 🤝 Contributing

This is a safety-critical project. Please ensure all changes:
1. Maintain or improve safety features
2. Include appropriate testing
3. Document any new functionality
4. Follow the established code structure

## 📄 License

This project is for educational and entertainment purposes. Use at your own risk and ensure appropriate safety measures are in place.

---

**⚠️ Safety Warning**: This project involves moving parts and electrical components. Always prioritize safety and test thoroughly before use around people or pets.

*Last Updated: December 2024*
