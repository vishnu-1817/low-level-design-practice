#include <iostream>
#include <memory>

class Sensor { 
public: 
    ~Sensor() { std::cout << "Sensor Deleted!\n"; } 
};

int main() {
    // Count = 1
    std::shared_ptr<Sensor> ptr1 = std::make_shared<Sensor>();
    
    {
        // Count = 2
        std::shared_ptr<Sensor> ptr2 = ptr1; 
        std::cout << "Inside scope, Count: " << ptr1.use_count() << "\n";
    } 
    // 'ptr2' dies here. Count goes back to 1.
    // Sensor is NOT deleted yet because ptr1 is still alive.

    std::cout << "Outside scope, Count: " << ptr1.use_count() << "\n";

    return 0; 
    // 'ptr1' dies here. Count hits 0. "Sensor Deleted!" prints.
}