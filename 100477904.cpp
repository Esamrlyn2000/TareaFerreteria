#include <iostream>
#include <fstream>
#include "esconu.h"
using namespace std;
const int max_articulos = 20;
const int max_datos = 3;
string devolver(string valor);
void MenuPrincipal();
int main()
{
    BorraPantalla();
    ifstream Entrada;
    ofstream Salida;
    string cod, articulo, marca, precio;
    string guardar[max_articulos][max_datos];
    string respuesta = "";
    char opciones;
    int cArray = 0, borrar, contadoCorL, contadoCorB;
    bool salir = false;
    Entrada.open("BaseDatos.txt");
    Entrada >> cArray;

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            guardar[i][j] = "~~";
        }
    }

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            Entrada >> guardar[i][j];
        }
    }
    Entrada.close();
    do
    {
        BorraPantalla();
        MenuPrincipal();
        cin >> opciones;
        BorraPantalla();
        switch (opciones)
        {
        case '1':
            contadoCorL = 5;
            BorraPantalla();
            CoordenadaXY(36, 1);
            cout << "Listado de articulos en existencia:" << endl;
            CoordenadaXY(21, 2);
            cout << "----------------------------------------------------------------------" << endl;
            CoordenadaXY(21, 3);
            cout << "| Cod.           Articulo            Marca              Precio       |" << endl;
            CoordenadaXY(21, 4);
            cout << "----------------------------------------------------------------------" << endl;
            for (int i = 0; i < 20; i++)
            {
                cout << "    \t\t\t" << i + 1 << ".-";
                for (int j = 0; j < 3; j++)
                {
                    if (j == 0)
                    {
                        CoordenadaXY(39, contadoCorL);
                    }
                    else if (j == 1)
                    {
                        CoordenadaXY(58, contadoCorL);
                    }
                    else if (j == 2)
                    {
                        CoordenadaXY(77, contadoCorL);
                    }
                    cout << guardar[i][j] << " ";
                }
                cout << endl;
                contadoCorL++;
            }

            TeclaPresionada("Precione una Tecla para continuar");
            BorraPantalla();
            break;

        case '2':
            BorraPantalla();
            CoordenadaXY(21, 1);
            cout << "Registro de Artilulos" << endl;
            CoordenadaXY(21, 3);
            cout << "Digite  el Nombre del  Articulo: ";
            cin >> articulo;
            CoordenadaXY(21, 5);
            cout << "Digite  la marca del Articulo: ";
            cin >> marca;
            CoordenadaXY(21, 7);
            cout << "Digite el precio del Articulo: ";
            cin >> precio;
            guardar[cArray][0] = articulo;
            guardar[cArray][1] = marca;
            guardar[cArray][2] = precio;
            cArray++;
            BorraPantalla();
            break;

        case '3':
            BorraPantalla();
            contadoCorB = 5;
            CoordenadaXY(36, 1);
            cout << "cual articulo desea eliminar:" << endl;
            CoordenadaXY(21, 2);
            cout << "----------------------------------------------------------------------" << endl;
            CoordenadaXY(21, 3);
            cout << "| Cod.           Articulo            Marca              Precio       |" << endl;
            CoordenadaXY(21, 4);
            cout << "----------------------------------------------------------------------" << endl;
            for (int i = 0; i < 20; i++)
            {
                cout << "    \t\t\t" << i + 1 << ".-";
                for (int j = 0; j < 3; j++)
                {
                    if (j == 0)
                    {
                        CoordenadaXY(39, contadoCorB);
                    }
                    else if (j == 1)
                    {
                        CoordenadaXY(58, contadoCorB);
                    }
                    else if (j == 2)
                    {
                        CoordenadaXY(77, contadoCorB);
                    }
                    cout << guardar[i][j] << " ";
                }
                cout << endl;
                contadoCorB++;
            }
            cin >> borrar;

            for (int i = borrar - 1; i < 20; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (guardar[i][j] != "~~")
                    {
                        guardar[i][j] = guardar[i + 1][j];
                    }
                }
            }
            cArray - 1;
            TeclaPresionada("Exito El articulo se a Borrado Correctamente \n Precione una tecla para continuar");
            BorraPantalla();
            break;

        case '4':
            BorraPantalla();
            cout << "Deseas Salir S/N?" << endl;
            cin >> respuesta;
            if (respuesta == "S" || respuesta == "s")
            {
                Salida.open("BaseDatos.txt");
                Salida << cArray;
                for (int i = 0; i < 20; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (guardar[i][j] != "~~")
                        {
                            Salida << guardar[i][j] << " ";
                        }
                    }
                    Salida << endl;
                }
                Salida.close();
                salir = true;
            }

            BorraPantalla();

            break;

        default:
            BorraPantalla();
            TeclaPresionada("Esta no es una tecla opcionada Precione una tecla para continuar");
            break;
        }
    } while (salir != true);
    BorraPantalla();
    return 0;
}

void MenuPrincipal()
{
    ColorFondoTexto(12);
    ColorTexto(10);
    CoordenadaXY(21, 1);
    cout << "Bienvenido al sistema de inventario " << endl;
    CoordenadaXY(21, 3);
    cout << "Menu de Opciones" << endl;
    CoordenadaXY(21, 4);
    cout << "1.-Listar Articulo" << endl;
    CoordenadaXY(21, 5);
    cout << "2.-Agregar Articulo" << endl;
    CoordenadaXY(21, 6);
    cout << "3.-Eliminar Articulos" << endl;
    CoordenadaXY(21, 7);
    cout << "4.-Salir" << endl;
    CoordenadaXY(21, 8);
}
