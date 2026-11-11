#ifndef SENSOR_CAUDAL_H
#define SENSOR_CAUDAL_H
#include "Sensor.h"

class SensorCaudal : public Sensor {
private:
	double caudalNormal;
public:
	SensorCaudal(int _id, std::string _ub, double _lect, double _cNormal = 100.0);
	void procesarLectura() override;
};
#endif
