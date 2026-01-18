#include<bits/stdc++.h>
using namespace std;

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
	Vehicle(int vehicleId, SlotType slotType = SlotType::COMPACT) 
		: vehicleId(vehicleId), slotType(slotType) {};

	int getVehicleId(){
		return vehicleId;
	}

	int getSlotType(){
		return static_cast<int>(slotType);
	}

	void printVehicleData(){
		cout<<"vehicle id : "<<vehicleId<<"\n";
		cout<<"slotTypeIntVal : "<<static_cast<int>(slotType)<<"\n";
		return;
	}


};

class Slot {

private:
	int slotId;
	SlotType slotType;
	int floorId;
	bool free;

public:
	static int slotCount;

	int getSlotId(){
		return slotId;
	}

	Slot(SlotType slotType = SlotType::COMPACT, int floorId = 1) 
		: slotType(slotType), floorId(floorId) 
	{
			slotId = slotCount + 1;
			slotCount++;
			free = true;
	}
	~Slot(){
		cout<<"Deleting slot with slot id : "<<slotId<<"\n";
	}

	bool isFree(){
		return free;
	}

	int getSlotTypeIntVal(){
		return static_cast<int>(slotType);
	}

	void fill(){
		if (free){
			free = false;
			return;
		}
		cout<<"Slot id : "<<slotId<<" is occupied\n";
		return;
	}

	void unfill(){
		if (!free){
			free = true;
			return;
		}
		cout<<"Slot id : "<<slotId<<" is already empty\n";
		return;

	}

};
int Slot::slotCount = 0;

class Ticket {

private:
	int ticketId;
	Vehicle* vehicle;
	Slot* slot;

public:
	static int ticketCount;
	Ticket(bool slotAvailable, Vehicle* vehicle = nullptr, Slot* slot = nullptr) 
		: slot(slot), vehicle(vehicle)
	{
		if (!slotAvailable){
			ticketId = 0;
		} else {
			ticketCount++;
			ticketId = ticketCount;

		}

	}

	~Ticket(){
		cout<<"Deleting Ticket\n";
	}


	void print(){
		cout<<"Ticket id : "<<ticketId<<"\n";
		if (vehicle) cout<<"vehicleId : "<<vehicle->getVehicleId()<<"\n";
		if (slot) cout<<"slotId : "<<slot->getSlotId()<<"\n";
		return;

	}


};

int Ticket::ticketCount = 0;


class SlotCollection {
private:
	vector<Slot*>slots;

public:

	void addSlot(Slot* slot) {
		slots.push_back(slot);
		return;
	}

	Slot* searchAndBookSlot(Vehicle* vehicle){
		int slotIntVal = static_cast<int>(vehicle->getSlotType());

		for (Slot* slot : slots){
			if (slot->isFree() && slot->getSlotTypeIntVal() >= slotIntVal) {
				slot->fill();
				return slot;
			}
		}

		return nullptr;
	}
	void searchAndFreeSlot(Slot* slotNeeded){

		for (Slot* slot : slots ){
			if (slotNeeded != slot) continue;
			slot->unfill();
			return;
		}

		cout<<"Slot Not Found\n";
		return;
	}


};


class TicketManager {

private:
	string name = "Ticket Manager";
	map <Ticket*, Slot*> ticket_slot_map;

public:
	Ticket* makeFailedToParkTicket(Vehicle* vehicle){
		Ticket* failedTicket = new Ticket(false, vehicle);
		return failedTicket;
	}

	Ticket* makeSuccessfulToParkTicket(Vehicle* vehicle, Slot* slot){
		Ticket* successTicket = new Ticket(true, vehicle, slot);
		ticket_slot_map[successTicket] = slot;
		return successTicket;
	}

	Slot* freeSlotAndGetData(Ticket* ticket){
		if (ticket_slot_map.find(ticket) == ticket_slot_map.end()) {
			cout<<"The given ticket is not valid";
			return nullptr;
		}

		Slot* slot = ticket_slot_map[ticket];
		ticket_slot_map.erase(ticket);
		return slot;
	}

};

class SlotManager {

private:
	string name = "Slot Manager";
	TicketManager* ticketManager;
	SlotCollection* slotCollection;

public:
	SlotManager(TicketManager* ticketManager, SlotCollection* slotCollection) 
		: ticketManager(ticketManager),
		slotCollection(slotCollection) {}

	~SlotManager() {
		cout<<"Deleting SlotManager\n";
	}

public:
	Ticket* bookSlot(Vehicle* vehicle){
		Slot* slot = slotCollection->searchAndBookSlot(vehicle);
		if (slot == nullptr){
			return ticketManager->makeFailedToParkTicket(vehicle);
		}
		return ticketManager->makeSuccessfulToParkTicket(vehicle, slot);
	}

	void freeSlot(Ticket* ticket){
		Slot* slot = ticketManager->freeSlotAndGetData(ticket);
		if (slot == nullptr){
			cout<<"Invalid Ticket. Failed to free the slot\n";
			return;
		}
		slotCollection->searchAndFreeSlot(slot);
		return;
	}


};


class ParkingManager {

private:
	string name = "Parking Manager";
	string greeting_msg = "Hello sir";
	SlotManager* slotManager;

public:
	ParkingManager(SlotManager* slotManager) : slotManager(slotManager) {}

	~ParkingManager(){
		cout<<"Deleting ParkingManager\n";
	}

public:
	Ticket* parkVehicle(Vehicle* v) const{
		Ticket* ticket = slotManager->bookSlot(v);
		ticket->print();
		return ticket;
	}

	void unparkVehicle(Ticket* ticket){
		slotManager->freeSlot(ticket);
		return;
	}
};



int main(){
	TicketManager* ticketManager = new TicketManager();

	SlotCollection* slotCollection = new SlotCollection();

	SlotManager* slotManager = new SlotManager(ticketManager, slotCollection);

	Slot* slot1 = new Slot(SlotType::COMPACT, 1);
	Slot* slot2 = new Slot(SlotType::MOTORCYCLE, 2);
	Slot* slot3 = new Slot();
	slotCollection->addSlot(slot1);
	slotCollection->addSlot(slot2);
	slotCollection->addSlot(slot3);

	Vehicle* vehicle1 = new Vehicle(1, SlotType::MOTORCYCLE);
	Vehicle* vehicle2 = new Vehicle(2);

	ParkingManager* parkingManager = new ParkingManager(slotManager);

	Ticket* ticket1 = parkingManager->parkVehicle(vehicle1);
	Ticket* ticket2 = parkingManager->parkVehicle(vehicle2);

	parkingManager->unparkVehicle(ticket1);
	parkingManager->unparkVehicle(ticket2);
	parkingManager->unparkVehicle(ticket2);


	return 0;
}
