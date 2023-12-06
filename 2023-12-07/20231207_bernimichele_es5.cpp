#include <iostream>

using namespace std;

class Auto {
private:
	int numWheels, Vmax, Vcurrent, kmTraveled;
public:
	Auto(int numWheels, int Vmax) : numWheels(numWheels), Vmax(Vmax), Vcurrent(0), kmTraveled(0) {}
	void setVelocity(int V) {
		if(V > Vmax) {
			cout << "Impossibile impostare la velocita a " << V << ", eccede la velocita massima" << endl;
			return;
		}
		Vcurrent = V;
	}
	void travel(int km) {
		kmTraveled += km;
	}
};

class Boat {
private:
	int Vmax, Vcurrent, kmTraveled;
public:
	Boat(int Vmax) : Vmax(Vmax), Vcurrent(0), kmTraveled(0) {}
	void setVelocity(int V) {
		if(V > Vmax) {
			cout << "Impossibile impostare la velocita a " << V << ", eccede la velocita massima" << endl;
			return;
		}
		Vcurrent = V;
	}
	void travel(int km) {
		kmTraveled += km;
	}
};

class Anfibio : public Auto, public Boat {
public:
	Anfibio(int landVmax, int numWheels, int waterVmax) : Auto(numWheels, landVmax), Boat(waterVmax) {}
};

int main() {
	
	Anfibio a1(100, 4, 50);
	
	a1.Boat::setVelocity(70);
	
	return 0;
}