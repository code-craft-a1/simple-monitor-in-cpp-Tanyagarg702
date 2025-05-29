#include <gtest/gtest.h>
#include "./monitor.h"

TEST(Monitor, TemperatureValidation) {
    EXPECT_FALSE(isTemperatureOk(94.9));
    EXPECT_FALSE(isTemperatureOk(102.1));
    EXPECT_TRUE(isTemperatureOk(95.0));
    EXPECT_TRUE(isTemperatureOk(102.0));
}

TEST(Monitor, PulseValidation) {
    EXPECT_FALSE(isPulseRateOk(59));
    EXPECT_FALSE(isPulseRateOk(101));
    EXPECT_TRUE(isPulseRateOk(60));
    EXPECT_TRUE(isPulseRateOk(100));
}

TEST(Monitor, SpO2Validation) {
    EXPECT_FALSE(isSpO2Ok(89.9));
    EXPECT_TRUE(isSpO2Ok(90.0));
}

TEST(Monitor, VitalsEvaluation) {
    EXPECT_EQ(evaluateVitals(94, 70, 95), VitalStatus::TemperatureError);
    EXPECT_EQ(evaluateVitals(98.6, 55, 95), VitalStatus::PulseError);
    EXPECT_EQ(evaluateVitals(98.6, 75, 85), VitalStatus::SpO2Error);
    EXPECT_EQ(evaluateVitals(98.6, 75, 95), VitalStatus::OK);
}
