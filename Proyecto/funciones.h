#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string>

using namespace std;

const int N = 6;

// Variables globales
extern string productos[N];
extern float precios[N];
extern int stock[N];
extern int pedido[N];

// Función
float calcularTotal();
void MsjErr();

#endif