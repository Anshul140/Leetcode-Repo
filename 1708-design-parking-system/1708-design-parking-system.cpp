class ParkingSystem {
public:
    int small_cap;
    int big_cap;
    int medium_cap;

    ParkingSystem() {
        small_cap = 0;
        big_cap = 0;
        medium_cap = 0;
    }

    ParkingSystem(int big, int medium, int small) {
        medium_cap = medium;
        big_cap = big;
        small_cap = small;
    }
    
    bool addCar(int ct) {
        if(ct == 1) {
            if(big_cap > 0) {
                big_cap--;
                return true;
            }
            return false;
        }
        else if(ct == 2) {
            if(medium_cap > 0) {
                medium_cap--;
                return true;
            }
            return false;
        }
        else if(ct == 3) {
            if(small_cap > 0) {
                small_cap--;
                return true;
            }
            return false;
        }

        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */