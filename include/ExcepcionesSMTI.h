#ifndef EXCEPCIONES_SMTI_H
#define EXCEPCIONES_SMTI_H
#include <stdexcept>
#include <string>

// Herencia de std::runtime_error como exige la guía
class ExcepcionRedSMTI : public std::runtime_error {
public:
	explicit ExcepcionRedSMTI(const std::string& mensaje) 
		: std::runtime_error("Error de Red SMTI: " + mensaje) {}
};
#endif
