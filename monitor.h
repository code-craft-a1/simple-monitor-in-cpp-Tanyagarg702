#pragma once

enum class VitalStatus {
    OK,
    TemperatureError,
    PulseError,
    SpO2Error
};

bool isTemperatureOk(float temperature);
bool isPulseRateOk(float pulseRate);
bool isSpO2Ok(float spo2);
VitalStatus evaluateVitals(float temperature, float pulseRate, float spo2);

// I/O functions
void blinkAlert();
void showAlert(VitalStatus status);
