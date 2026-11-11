#ifndef SENSOR_PRESION_H
#define SENSOR_PRESION_H
#include "Sensor.h"

class SensorPresion : public Sensor {
private:
	double presionMinima;
public:
	SensorPresion(int _id, std::string _ub, double _lect, double _pMin = 15.0);
	void procesarLectura() override;
};
#endif
