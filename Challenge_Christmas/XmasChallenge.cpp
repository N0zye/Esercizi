#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class ContoAllaRovescia {
private:
    int counter;

public:
    ContoAllaRovescia(int counter) : counter(counter) {}

    void decrementa() {
        counter--;
    }

    bool isGo() {
        return (counter > 0 ? false : true);
    }
};

class EuristicaConfronto {
private:
    double tolleranza;
	int proveFallite, proveSuperate;
public:
    EuristicaConfronto(double tolleranza) : tolleranza(tolleranza), proveFallite(0), proveSuperate(0) {}
	void registraProvaFallita() {
		proveFallite++;
	}
	void registraProvaSuperata() {
		proveSuperate++;
	}
	void stampaEsitoProve() {
		cout << proveFallite << " su " << proveSuperate+proveFallite << endl;
	}
	bool isValoreTollerato(double valore) {
	return (valore < tolleranza ? true : false);
	}
};

class GeneratoreDouble {
private:
    GeneratoreDouble(time_t currentTime) {
        srand(currentTime);
    }

public:
    static GeneratoreDouble &getInstance() {
        static GeneratoreDouble instance(time(nullptr));
        return instance;
    }

    double generaDouble() {
        return rand() % 1000;
    }
};

class Punto2D {
private:
    double X, Y;

public:
    Punto2D(double X, double Y) : X(X), Y(Y) {}

    double getX() { return X; }
    double getY() { return Y; }
};

class Segmento2D {
private:
	Punto2D *estremoA, *estremoB;
	Punto2D* getEstremo(char which) {
		switch (toupper(which))
		{
		case 'A':
			return estremoA;
		case 'B':
			return estremoB;
		default:
			return nullptr;
		}
	}
public:
	Segmento2D(Punto2D *estremoA, Punto2D *estremoB) : estremoA(estremoA), estremoB(estremoB) {}
	double calcolaLunghezza() {
		double Ax = getEstremo('A')->getX();
		double Bx = getEstremo('B')->getX();
		double Ay = getEstremo('A')->getY();
		double By = getEstremo('B')->getY();
		return (sqrt(pow(Ax-Bx,2) + pow(Ay-By,2)));
	}
};

class Triangolo2D {
private:
    Punto2D *A, *B, *C;
	Punto2D* getPunto(char which) {
		switch (toupper(which))
		{
		case 'A':
			return A;
		case 'B':
			return B;
		case 'C':
			return C;	
		default:
			return nullptr;
		}
	}
public:
    Triangolo2D(Punto2D *A, Punto2D *B, Punto2D *C) : A(A), B(B), C(C) {}
	~Triangolo2D() {
        delete A;
        delete B;
        delete C;
    }
	Punto2D* calcolaBaricentro() {
		double X, Y;
		Punto2D M((getPunto('A')->getX() + getPunto('B')->getX()) /2, (getPunto('A')->getY() + getPunto('B')->getY()) /2);
		Punto2D N((getPunto('B')->getX() + getPunto('C')->getX()) /2, (getPunto('B')->getY() + getPunto('C')->getY()) /2);
		Punto2D L((getPunto('C')->getX() + getPunto('A')->getX()) /2, (getPunto('C')->getY() + getPunto('A')->getY()) /2);
		
		X = ((M.getX() + N.getX() + L.getX() ) /3);
		Y = ((M.getY() + N.getY() + L.getY() ) /3);
		return new Punto2D(X, Y);
	}
	Punto2D* calcolaPuntoMedioVertici() {
		double X, Y;
		X = (getPunto('A')->getX() + getPunto('B')->getX() + getPunto('C')->getX())/3;
		Y = (getPunto('A')->getY() + getPunto('B')->getY() + getPunto('C')->getY())/3;
		return new Punto2D(X, Y);
	}
	string getStringaCoordinate() {
		string stringaCoordinate = "";

		stringaCoordinate += "A(" + to_string(getPunto('A')->getX()) + ", " + to_string(getPunto('A')->getY()) + ") ";
		stringaCoordinate += "B(" + to_string(getPunto('B')->getX()) + ", " + to_string(getPunto('B')->getY()) + ") ";
		stringaCoordinate += "C(" + to_string(getPunto('C')->getX()) + ", " + to_string(getPunto('C')->getY()) + ")";

		return stringaCoordinate;
	}
};

int main() {
    srand(time(NULL));

    double tolleranza = pow(10.0, -5);
    EuristicaConfronto ec(tolleranza);
    ContoAllaRovescia countdown(500000);

    do {
        GeneratoreDouble gd = GeneratoreDouble::getInstance();
        Triangolo2D *t = new Triangolo2D(
            new Punto2D(gd.generaDouble(), gd.generaDouble()),
            new Punto2D(gd.generaDouble(), gd.generaDouble()),
            new Punto2D(gd.generaDouble(), gd.generaDouble())
		);
		if(!ec.isValoreTollerato((new Segmento2D(t->calcolaBaricentro(), t->calcolaPuntoMedioVertici()))->calcolaLunghezza())) {
			cout << "Test non superato " << t->getStringaCoordinate() << endl;
			ec.registraProvaFallita();
		}
		else {
			ec.registraProvaSuperata();
		}
        delete t;
		countdown.decrementa();
		if (countdown.isGo()) {
			break;
		}
		
    } while (true);

	ec.stampaEsitoProve();

    return 0;
}