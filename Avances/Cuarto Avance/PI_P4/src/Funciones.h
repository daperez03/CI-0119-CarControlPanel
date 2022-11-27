#include <iostream>

/// @brief Verify that the data remains at the thresholds
/// @param data Value to be evaluated
/// @param min Minimum thresholds
/// @param max Top thresholds
/// @return True if the data is outside the thresholds or
/// false if the data is outside the thresholds
extern "C" bool umbrales(int data, int min, int max);

/// @brief Simulation of the gas consume of vehicle
/// @param data Value of gas
/// @param speed Speed at which the vehicle is located
/// @return New value gas of vehicle
extern "C" int gas_simulation(int data, int speed);

/// @brief Simulation of vehicle temperature
/// @param data Current vehicle temperature
/// @param speed Speed at which the vehicle is located
/// @return New value temperature of vehicle
extern "C" int temperature_simulation(int data, int speed);

/// @brief Simulates the tire pressure of a vehicle
/// @param data Tire pressure currently
/// @return New tire pressures
extern "C" int pressure_simulation(int data);

/// @brief Collision simulator
/// @return Return true, if an accident is likely to occur or false if not
extern "C" bool anticollision_simulation();

