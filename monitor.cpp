#include "./monitor.h"
#include <iostream>
#include <thread>
#include <chrono>

using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;

bool isTemperatureOk(float temperature) {
    return temperature >= 95 && temperature <= 102;
}

bool isPulseRateOk(float pulseRate) {
    return pulseRate >= 60 && pulseRate <= 100;
}

bool isSpO2Ok(float spo2) {
    return spo2 >= 90;
}

VitalStatus evaluateVitals(float temperature, float pulseRate, float spo2) {
    if (!isTemperatureOk(temperature)) return VitalStatus::TemperatureError;
    if (!isPulseRateOk(pulseRate)) return VitalStatus::PulseError;
    if (!isSpO2Ok(spo2)) return VitalStatus::SpO2Error;
    return VitalStatus::OK;
}

void blinkAlert() {
    for (int i = 0; i < 6; i++) {
        cout << "\r* " << flush;
        sleep_for(seconds(1));
        cout << "\r *" << flush;
        sleep_for(seconds(1));
    }
}

void showAlert(VitalStatus status) {
    switch (status) {
        case VitalStatus::TemperatureError:
            cout << "Temperature is critical!\n";
            break;
        case VitalStatus::PulseError:
            cout << "Pulse Rate is out of range!\n";
            break;
        case VitalStatus::SpO2Error:
            cout << "Oxygen Saturation out of range!\n";
            break;
        default:
            return;
    }
    blinkAlert();
}
