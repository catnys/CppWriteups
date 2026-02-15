#include <iostream>

using namespace std;

class ElectricalVehicle{
    private:
    string brand;
    int batteryPercentage;
    
    public:

    ElectricalVehicle(string brand_val, int batteryPercentage) {
        setBrand(brand_val);
        setBatteryPercentage(batteryPercentage);
    };

    virtual ~ElectricalVehicle() {
        cout << "car is now deleted...." << endl;
    };

    virtual void showCharge() {
        cout << "\nbrand: " << getBrand() << " battery: " << getBatteryPercentage() << endl;
    }

    void charge(int val) {
        this->batteryPercentage = (this->batteryPercentage + val > 100) ? 100 : this->batteryPercentage + val;
    }

    // getters and setters- btw i dont use ai anymore:))
    string getBrand() {
        return this->brand;
    }

    int getBatteryPercentage() {
        return this->batteryPercentage;
    }

    void setBrand(string value) {
        this->brand = value;
    }

    void setBatteryPercentage(int value) {
        this->batteryPercentage = value;
    }

    
};

class Tesla: public ElectricalVehicle {
    private:
    bool autoP;
 
    public:
    Tesla(string b, int bat, bool autoP) : ElectricalVehicle(b, bat) {
        // ElectricalVehicle(b,bat); --> bunu böyle de yapabilir miydik ?
        this->autoP = autoP;       
    }

    void showCharge() override {
        cout << "now we're in virtual void showCharge(): "  << getBrand() << " charge: %" << getBatteryPercentage() << "autopilot: " << this->autoP << endl; 
    }

    ~Tesla() { cout << "Tesla parcasi yok oldu bitti gitti..." << endl;};

};


int main() {

    ElectricalVehicle* my_ptr = new Tesla("Tesla", 20, false);

    cout << my_ptr->getBrand() << endl;
    cout << my_ptr->getBatteryPercentage() << endl;

    /*
    ElectricalVehicle  my_vehicle("BMW", 50);
    my_vehicle.showCharge();
    my_vehicle.charge(10);
    my_vehicle.showCharge();

    Tesla my_tesla("Tesla", 20, false);
    my_tesla.showCharge();
    */
    return 0;
}