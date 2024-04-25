#include <iostream>

class Vehicle
{
public:
    Vehicle(const int& vehicleSeats,const int& wheels,const std::string& steeringWheel) :
       m_vehicleSeats(vehicleSeats),m_wheels(wheels),m_steeringWheel(steeringWheel)
    {
    }

    ~Vehicle()
    {
    }

public:

void printVehicle()
{
    std::cout<<"Steering wheel: "<<m_steeringWheel<<std::endl;
    std::cout<<"Vehicle seats: "<<m_vehicleSeats<<std::endl;
    std::cout<<"Wheels: "<<m_wheels<<std::endl;
}

private:
    std::string m_steeringWheel;
    int m_vehicleSeats = 0;
    int m_wheels = 0;
    
};

class Car : public Vehicle{
public:
   Car(const int& vehicleSeats,const int& wheels,const std::string& steeringWheel,
       const std::string& make,const std::string& model,const std::string& color,const std::string& motorFuel) 
       :
       Vehicle(vehicleSeats,wheels,steeringWheel),m_make(make),m_model(model),m_color(color),m_motorFuel(motorFuel)
    {
    }

    ~Car()
    {
    }

void printCar()
{
    printVehicle();
    std::cout<<"Make: "<<m_make<<std::endl;
    std::cout<<"Model: "<<m_model<<std::endl;
    std::cout<<"Color: "<<m_color<<std::endl;
    std::cout<<"Motor fuel: "<<m_motorFuel<<std::endl;
}

private:
    std::string m_make;
    std::string m_model;
    std::string m_motorFuel;
    std::string m_color = 0;

};

class PoliceCar : public Car
{
public:

    PoliceCar(const int& vehicleSeats,const int& wheels,const std::string& steeringWheel,const std::string& make,
              const std::string& model,const std::string& color,const std::string& motorFuel,bool flashingLights,
              bool policeBullhorn,bool bullBar)
               :
              Car(vehicleSeats,wheels,steeringWheel,make,model,color,motorFuel),m_flashingLights(flashingLights),
              m_policeBullhorn(policeBullhorn),m_bullBar(bullBar)
    {
    }

    ~PoliceCar()
    {
    }

public:
    void printPoliceCar()
    {
        std::cout<<"Police Car"<<std::endl;
        printCar();

        m_flashingLights 
        ?
        std::cout<<"That police car has flash light:"<<std::endl
        : 
        std::cout<<"That police car has not flash light:"<<std::endl;

        m_policeBullhorn 
        ?
        std::cout<<"That police car has bullhorn:"<<std::endl
        : 
        std::cout<<"That police car has not bullhorn:"<<std::endl;

        m_bullBar 
        ?
        std::cout<<"That police car has bullbar:"<<std::endl
        : 
        std::cout<<"That police car has not bullbar:"<<std::endl;
    }

private:
    bool m_flashingLights;
    bool m_policeBullhorn;
    bool m_bullBar;
};

class Motorcycle : public Vehicle
{
public:
    Motorcycle(const int& vehicleSeats,const int& wheels,const std::string& steeringWheel,
               const std::string& make,const std::string& model) 
               :
               Vehicle(vehicleSeats,wheels,steeringWheel),m_make(make),m_model(model)
    {
    }
    ~Motorcycle()
    {
    }

public:
    void printMotorcycle()
    {
        printVehicle();
        std::cout<<"Make: "<<m_make<<std::endl;
        std::cout<<"Model: "<<m_model<<std::endl;
    }

private:
    std::string m_make;
    std::string m_model;
};

class PoliceMotorcycle : public Motorcycle
{
public:
    PoliceMotorcycle(const int& vehicleSeats,const int& wheels,const std::string& steeringWheel,
                     const std::string& make,const std::string& model,bool flashingLights,
                     bool policeBullhorn)
                     :
                     Motorcycle(vehicleSeats,wheels,steeringWheel,make,model),m_flashingLights(flashingLights),
                     m_policeBullhorn(policeBullhorn)
    {
    }

    ~PoliceMotorcycle()
    {
    }

public:
    void printPoliceMotorcycle()
    {   
       std::cout<<"Police Motorcycle"<<std::endl;
       printMotorcycle();

       m_flashingLights 
        ?
        std::cout<<"That police motorcycle has flash light:"<<std::endl
        : 
        std::cout<<"That police motorcycle has not flash light:"<<std::endl;

        m_policeBullhorn 
        ?
        std::cout<<"That police motorcycle has bullhorn:"<<std::endl
        : 
        std::cout<<"That police motorcycle has not bullhorn:"<<std::endl;
    }

private:
    bool m_flashingLights;
    bool m_policeBullhorn;
};

class Carriage : public Vehicle
{
public:
    Carriage(const int& vehicleSeats,const int& wheels,const std::string& steeringWheel,const int& horses)
             :
             Vehicle(vehicleSeats,wheels,steeringWheel),m_horses(horses)
    {
    }

    ~Carriage()
    {
    }

public:
void prinCarriage(){
    printVehicle();
    std::cout<<"Number of horses: "<<m_horses<<std::endl;
}    

private:
    int m_horses = 0;
};


int main()
{
    PoliceCar car(4,4,"Tilt steering wheel","Toyota","Camry","Black","Gasoline",true,true,true);
    car.printPoliceCar();

    std::cout<<std::endl;

    PoliceMotorcycle moto(2,2,"Handlebar","Harley-Davidson","FLHP",true,true);
    moto.printPoliceMotorcycle();

    std::cout<<std::endl;

    Carriage carriage(2,3,"Cordeo",1);
    carriage.prinCarriage();

    return 0;
}

