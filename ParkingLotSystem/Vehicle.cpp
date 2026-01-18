// Vehicle.cpp
#include <iostream>
#include "Vehicle.h" // <--- Connects to your header

// Constructor Implementation
Vehicle::Vehicle(int vehicleId, SlotType slotType) 
    : vehicleId(vehicleId), slotType(slotType) {}

// Method Implementations
int Vehicle::getVehicleId() const {
    return vehicleId;
}

SlotType Vehicle::getSlotType() const {
    return slotType;
}

void Vehicle::printVehicleData() const {
    std::cout << "Vehicle ID: " << vehicleId << "\n";
    // Casting explicitly for printing
    std::cout << "Slot Type: " << static_cast<int>(slotType) << "\n";
}