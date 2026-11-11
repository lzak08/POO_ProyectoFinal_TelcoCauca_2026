#ifndef SERVIDOR_SOCKETS_H
#define SERVIDOR_SOCKETS_H
#include "ListaGen.h"
#include "Sensor.h"
#include <sys/socket.h>
#include <netinet/in.h>

class ServidorSockets {

private:
	int puerto;         
	int server_fd;      
	ListaGen<Sensor*>& listaPlanta;
public:
	ServidorSockets(int p, ListaGen<Sensor*>& lista);
	~ServidorSockets();
	
	void iniciarEscucha();
	void simularRecepcion(); // Para la prueba que tienes hasta ahora
};
#endif
