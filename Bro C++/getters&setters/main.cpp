#include<iostream>

class Stove{
    private:
        int temperature = 0; //hidden
    public:
    Stove(int temperature){
        setTemperature(temperature);
    }

    int getTemp(){
        return temperature;
    }

    void setTemperature(int temperature){
        if(temperature < 0){
            this-> temperature = 0;
        }
        else if(temperature >= 10){
            this-> temperature = 10;
        }
        else{
        this-> temperature = temperature;
        }
    }
};

int main()
{
    //abstraction - hide unnecessary data from outside a class
    //getter -> function that makes a private attr READABLE
    //setter -> function that makes a private attr WRITEABLE
    
    Stove stove(5);
    //stove.temperature = 1000;
    stove.setTemperature(1000);

    std::cout << "temp: " << stove.getTemp() << "\n";
    return 0;
}