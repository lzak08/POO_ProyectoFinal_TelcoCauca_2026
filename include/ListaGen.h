#ifndef LISTAGEN_H
#define LISTAGEN_H
#include <iostream>
#include <stdexcept>

template <typename T>
struct NodoGen {
	T dato;
	NodoGen<T>* siguiente;
	NodoGen(T _d) : dato(_d), siguiente(nullptr) {}
};

template <typename T>
class ListaGen {
private:
	NodoGen<T>* head;
public:
	ListaGen() : head(nullptr) {}
	
	// Destructor Genérico: Purga total del Heap para evitar Memory Leaks
	~ListaGen() {
		NodoGen<T>* actual = head;
		while (actual != nullptr) {
			NodoGen<T>* aux = actual->siguiente;
			delete actual->dato; 
			delete actual; 
			actual = aux;
		}
		head = nullptr;
	}
	
	void insertar(T nuevoDato) {
		NodoGen<T>* nuevo = new NodoGen<T>(nuevoDato);
		nuevo->siguiente = head;
		head = nuevo;
	}
	
	void procesarTodo() {
		NodoGen<T>* actual = head;
		while (actual != nullptr) {
			actual->dato->procesarLectura(); 
			actual = actual->siguiente;
		}
	}
};
#endif
