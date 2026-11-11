#include "SensorCaudal.h"
#include <iostream>

SensorCaudal::SensorCaudal(int _id, std::string _ub, double _lect, double _cNormal)
	: Sensor(_id, _ub, _lect), caudalNormal(_cNormal) {}

void SensorCaudal::procesarLectura() {
	std::cout << "[CAUDAL POLIMORFICO] " << *this;
	if (lectura > (caudalNormal * 1.5)) {
		std::cout << " --> ALERTA: SOBREFLUJO DETECTADO!";
	}
	std::cout << std::endl;
}
