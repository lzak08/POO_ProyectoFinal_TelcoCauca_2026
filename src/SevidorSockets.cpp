#include "ServidorSockets.h"
#include "ExcepcionesSMTI.h"
#include "SensorTemperatura.h"
#include "SensorPresion.h"
#include "SensorCaudal.h"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>

ServidorSockets::ServidorSockets(int p, ListaGen<Sensor*>& lista) 
	: server_fd(-1), puerto(p), listaPlanta(lista) {}

ServidorSockets::~ServidorSockets() {
	if (server_fd >= 0) {
		close(server_fd);
	}
}

void ServidorSockets::iniciarEscucha() {
	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_fd < 0) {
		throw ExcepcionRedSMTI("No se pudo instanciar el socket.");
	}
	
	// Configuración para reutilizar puerto (opcional pero recomendado)
	int opt = 1;
	setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
	
	sockaddr_in addr;
	std::memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = htons(puerto);
	
	if (bind(server_fd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
		throw ExcepcionRedSMTI("Enlace (bind) fallido en puerto " + std::to_string(puerto));
	}
	
	if (listen(server_fd, 2) < 0) {
		throw ExcepcionRedSMTI("Fallo la operacion listen.");
	}
	
	std::cout << "[SERVIDORSockets] Escuchando telemetria en puerto " << puerto << "..." << std::endl;
}

void ServidorSockets::simularRecepcion() {
	// Inserción dinámica simulada para la prueba (con los nuevos sensores)
	listaPlanta.insertar(new SensorTemperatura(101, "Caldera-01", 92.5));
	listaPlanta.insertar(new SensorTemperatura(102, "Horno-02", 65.0));
	listaPlanta.insertar(new SensorPresion(201, "Tuberia-Principal", 12.0));
	listaPlanta.insertar(new SensorCaudal(301, "Valvula-05", 160.0));
}
