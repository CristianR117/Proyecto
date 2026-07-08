#include <iostream>
#include <limits>
#include "funciones.h"

using namespace std;

// Productos
string productos[N] =
{
    "Cafe",
    "Capuccino",
    "Te",
    "Pastel",
    "Sandwich",
    "UCA-Cola"
};

// Precios
float precios[N] =
{
    1.50,
    2.50,
    1.25,
    3.00,
    2.75,
    1.00
};

// Stock
int stock[N] =
{
    20,
    15,
    25,
    10,
    12,
    30
};

// Pedido del cliente
int pedido[N] =
{
    0,
    0,
    0,
    0,
    0,
    0
};

// Función para calcular el total
float calcularTotal()
{
    float total = 0;

    for (int i = 0; i < N; i++)
    {
        total = total + (pedido[i] * precios[i]);
    }

    return total;
}

//Mensaje de error
void MsjErr()
{
    if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida, escribe un numero.\n";
        }
}