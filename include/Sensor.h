#ifndef SENSOR_H
#define SENSOR_H
#include <iostream>
#include <string>

class Sensor {
protected:
	int id;
	std::string ubicacion;
	double lectura;
public:
	Sensor(int _id, std::string _ub, double _lect);
	virtual ~Sensor(); // Destructor virtual
	
	int getId() const;
	double getLectura() const;
	
	// Método Virtual Puro
	virtual void procesarLectura() = 0;
	
	// Sobrecarga de Operador Amiga
	friend std::ostream& operator<<(std::ostream& os, const Sensor& s);
};
#endif
