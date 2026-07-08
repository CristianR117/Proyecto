#include <iostream>
#include <fstream>
#include "funciones.h"

using namespace std;

int main()
{
    int opcion;

    do // Menu
{
    cout << "\n===== Bienvenido al sistema de cafeteria =====";
    cout << "\n1. Ver menu";
    cout << "\n2. Agregar al pedido";
    cout << "\n3. Ver pedido";
    cout << "\n4. Modificar pedido";
    cout << "\n5. Confirmar compra";
    cout << "\n6. Cancelar compra";
    cout << "\n7. Salir";
    cout << "\nOpcion: ";
    cin >> opcion;
    MsjErr();

    switch (opcion)
    {        //ver menu
        case 1:
        {
            cout << "\n===== MENU =====\n";

            for (int i = 0; i < N; i++)
            {
                cout << i + 1 << ". "
                     << productos[i]
                     << " $" << precios[i]
                     << " Stock: " << stock[i]
                     << endl;
            }
            break;
        }
        //Agregar al pedido
        case 2:
        {
            int p, c;

            cout << "\n===== MENU =====\n";

            for (int i = 0; i < N; i++)
            {
                cout << i + 1 << ". "
                     << productos[i]
                     << " $" << precios[i]
                     << " Stock: " << stock[i]
                     << endl;
            }

            bool valido = false;
            do {
                cout << "\nProducto: ";
                cin >> p;
                MsjErr();

                cout << "Cantidad: ";
                cin >> c;
                MsjErr();

                if (p >= 1 && p <= N && c > 0 && c <= stock[p - 1])
                {
                    pedido[p - 1] = pedido[p - 1] + c;
                    stock[p - 1] = stock[p - 1] - c;

                    cout << "Producto agregado.\n";
                    valido = true;
                }
                else
                {
                    cout << "Datos incorrectos.\n";
                }
            } while (!valido);

            break;
        }
          //ver pedido
        case 3:
        {
            cout << "\n===== PEDIDO =====\n";

            for (int i = 0; i < N; i++)
            {
                if (pedido[i] > 0)
                {
                    cout << productos[i]
                         << " x "
                         << pedido[i]
                         << " = $"
                         << pedido[i] * precios[i]
                         << endl;
                }
            }

            cout << "TOTAL: $" << calcularTotal() << endl;
            break;
        }
          //Modifica pedido
        case 4: 
        {
            int p;
            bool valido = false;
            bool hayProductos = false;

            cout << "\n===== Productos en el pedido =====\n";

            for (int i = 0; i < N; i++)
            {
                if (pedido[i] > 0)
                {
                    cout << i + 1 << ". "
                         << productos[i]
                         << " x "
                         << pedido[i]
                         << " = $"
                         << pedido[i] * precios[i]
                         << endl;

                    hayProductos = true;
                }
            }

            if (!hayProductos)
            {
                cout << "Aun no se ha iniciado un pedido.\n";
            }
            else
            {
                do {
                    cout << "Producto a eliminar: ";
                    cin >> p;
                    MsjErr();

                    if (p >= 1 && p <= N && pedido[p - 1] > 0)
                    {
                        stock[p - 1] = stock[p - 1] + pedido[p - 1];
                        pedido[p - 1] = 0;

                        cout << "Producto eliminado.\n";
                        valido = true;
                    }
                    else
                    {
                        cout << "Producto invalido.\n";
                    }
                } while (!valido);
            }

            break;
        }    
          //confirmar compra
        case 5:
        {
            bool hayProductos = false;
            bool valido = false;

            for (int i = 0; i < N; i++)
            {
                if (pedido[i] > 0)
                {
                    hayProductos = true;
                    break;
                }
            }

            if (!hayProductos)
            {
                cout << "Aun no hay una compra por confirmar.\n";
            }
            else
            {
            float total = calcularTotal();
            int desc;

            do {
                cout << "\n===== DESCUENTO =====";
                cout << "\n1. Sin descuento";
                cout << "\n2. Estudiante";
                cout << "\n3. Docente";
                cout << "\nOpcion: ";
                cin >> desc;
                MsjErr();

                if (desc == 1 || desc == 2 || desc == 3)
                {
                    valido = true;
                }
                else
                {
                    cout << "Opcion de descuento invalida.\n";
                }

            }while(!valido);

            if (desc == 2)
            {
                total = total * 0.90;
            }
            else if (desc == 3)
            {
                total = total * 0.85;
            }

            cout << "\nTOTAL FINAL: $" << total << endl;

            ofstream archivo("Factura.txt");

            if (archivo.is_open())
            {
                archivo << "******** FACTURA ********" << endl;
                archivo << endl;

                for (int i = 0; i < N; i++)
                {
                    if (pedido[i] > 0)
                    {
                        archivo << productos[i]
                                << " x "
                                << pedido[i]
                                << " = $"
                                << pedido[i] * precios[i]
                                << endl;
                    }
                }

                archivo << endl;
                archivo << "TOTAL: $" << total << endl;

                archivo.close();

                cout << "Factura guardada correctamente." << endl;
            }
            else
            {
                cout << "No se pudo crear el archivo." << endl;
            }

            for (int i = 0; i < N; i++)
            {
                pedido[i] = 0;
            }
            }
            break;
        }
         // Cancelar compra
        case 6:
        {
            bool hayPedidos = false;

            for (int i = 0; i < N; i++)
            {
                if (pedido[i] > 0)
                {
                    hayPedidos = true;
                    break;
                }
            }

            if (!hayPedidos)
            {
                cout << "No hay pedidos que cancelar.\n";
                break;
            }

            int confirmar;
            bool valido = false;

            do {
                cout << "\n===== CONFIRMAR CANCELACION =====";
                cout << "\n1. Si";
                cout << "\n2. No";
                cout << "\nOpcion: ";
                cin >> confirmar;
                MsjErr();

                if (confirmar == 1 || confirmar == 2)
                {
                    valido = true;
                }
                else
                {
                    cout << "Opcion invalida.\n";
                }

            } while (!valido);

            if (confirmar == 1)
            {
                for (int i = 0; i < N; i++)
                {
                    stock[i] = stock[i] + pedido[i];
                    pedido[i] = 0;
                }

                cout << "Compra cancelada.\n";
            }
            else
            {
                cout << "Cancelacion abortada.\n";
            }

            break;
        }
         //salir
        case 7:
        {
            int confirmar;
            bool valido = false;

            do {
                cout << "\n===== Seguro que desea salir? =====";
                cout << "\n1. Si";
                cout << "\n2. No";
                cout << "\nOpcion: ";
                cin >> confirmar;
                MsjErr();

                if (confirmar == 1 || confirmar == 2)
                {
                    valido = true;
                }
                else
                {
                    cout << "Opcion invalida.\n";
                }

            } while (!valido);

            if (confirmar == 1)
            {
                cout << "Fin del programa." << endl;
                break;
            }
            else
            {
                cout << "Cancelando salida...\n";
                opcion = 0;
                break;
            }
        }

        default:
        {
            cout << "Opcion invalida" << endl;
            break;
        }
    }

} while (opcion != 7);

    return 0;
}