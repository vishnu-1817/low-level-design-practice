// Vehicle.h
#pragma once 

// Define the Enum here so it's visible to everyone who includes this file
enum class SlotType {
    COMPACT = 3,
    LARGE = 2,
    MOTORCYCLE = 1
};

class Vehicle {
private:
    int vehicleId;
    SlotType slotType;

public:
    // Constructor Declaration
    Vehicle(int vehicleId, SlotType slotType = SlotType::COMPACT);

    // Getter Declarations
    int getVehicleId() const;
    SlotType getSlotType() const;
    void printVehicleData() const;
};