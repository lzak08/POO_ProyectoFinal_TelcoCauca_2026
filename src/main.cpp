#include <iostream>
#include "ServidorSockets.h"
#include "ExcepcionesSMTI.h"
#include "ListaGen.h"

// Estructura de Trama Industrial exigida en la rúbrica
struct MuestraSensor { 
	int idSensor; 
	double valor; 
	char tipo[12]; 
};

int main() {
	std::cout << "==================================================" << std::endl;
	std::cout << " SMTI: SERVIDOR DE TELEMETRIA DISTRIBUIDA (UNIDAD 9)" << std::endl;
	std::cout << "==================================================" << std::endl;
	
	ListaGen<Sensor*> listaPlanta;
	
	try {
		ServidorSockets servidor(8080, listaPlanta);
		servidor.iniciarEscucha();
		
		// En la evaluacion, el estudiante recibira la trama real via accept() y recv()
		servidor.simularRecepcion(); 
		
		std::cout << "\n--- PROCESAMIENTO POLIMORFICO DE TELEMETRIA ---" << std::endl;
		listaPlanta.procesarTodo();
		
	} catch (const ExcepcionRedSMTI& e) {
		std::cerr << "[EXCEPCION GRAVE SMTI] " << e.what() << std::endl;
		return 1;
	}
	
	return 0; // Al salir de scope, ~ListaGen() libera la memoria Heap limpiamente
}
