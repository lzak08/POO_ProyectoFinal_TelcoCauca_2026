#include "SensorPresion.h"
#include <iostream>

SensorPresion::SensorPresion(int _id, std::string _ub, double _lect, double _pMin)
	: Sensor(_id, _ub, _lect), presionMinima(_pMin) {}

void SensorPresion::procesarLectura() {
	std::cout << "[PRESION POLIMORFICO] " << *this;
	if (lectura < presionMinima) {
		std::cout << " --> ALERTA: CAIDA DE PRESION EN TUBERIA!";
	}
	std::cout << std::endl;
}
