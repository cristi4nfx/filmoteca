#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <limits>
#include <conio.h>
#include <unistd.h>
#include "pelicula.h"
using namespace std;

int main()
{

    system("color 02");
    SetConsoleOutputCP(CP_UTF8);

    Pelicula peliculas[5];
    int opcion = 0, numPeliculas = 0;
    bool salir = false;

    while (!salir)
    {

        system("cls");

        cout << "##################################################\n"
                "###      Sistema Gestión de Videoteca          ###\n"
                "##################################################\n\n"
                "Menú:\n"
                "1. Mostrar todas las películas\n"
                "2. Guardar una nueva película\n"
                "3. Modificar películas\n"
                "4. Eliminar película\n"
                "5. Salir\n\n"
                "Que desea realizar?\n"
                "<<";

        while (!(cin >> opcion) || cin.peek() != '\n' || opcion < 1 || opcion > 5)
        {

            cout << "¡ERROR! Ingrese una opción valida (1-5) \n \n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ingrese una opcion\n"
                    "<<";
        }

        system("cls");

        switch (opcion)
        {

        case 1:

            if (numPeliculas > 0 && numPeliculas <= 5)
            {

                cout << "##################################################\n"
                        "###      Sistema Gestión de Videoteca          ###\n"
                        "##################################################\n\n"
                        "           Películas en la agenda                 \n\n";

                for (int i = 0; i < numPeliculas; i++)
                {

                    if (peliculas[i].getDuracion() > 0)
                    {

                        cout << peliculas[i].toString();
                        sleep(1.5);
                    }
                }
            }
            else
            {

                cout << "No hay peliculas creadas cree al menos una.\n\n";
            }

            cout << "Presione cualquier tecla para volver al menu principal";

            _getch();

            break;

        case 2:

            if (numPeliculas < 5)
            {

                string titulo, director, sinopsis, genero;
                int duracion, anio;
                double calificacion;
                bool disponible;

                cout << "##################################################\n"
                        "###      Sistema Gestión de Videoteca          ###\n"
                        "##################################################\n\n"
                        "              Agregar Pelicula                    \n\n"
                        "Ingrese los datos de la película:\n\n"
                        "Título: ";

                getline(cin >> ws, titulo);
                peliculas[numPeliculas].setTitulo(titulo);
                cout << "Año: ";

                while (!(cin >> anio) || cin.peek() != '\n')
                {

                    cout << "¡ERROR! Ingrese un valor numérico" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    cout << "Año: ";
                }

                peliculas[numPeliculas].setAnio(anio);

                cout << "Director: ";
                getline(cin >> ws, director);
                peliculas[numPeliculas].setDirector(director);

                cout << "Sinopsis: ";
                getline(cin >> ws, sinopsis);
                peliculas[numPeliculas].setSinopsis(sinopsis);

                cout << "Duración (en minutos): ";

                while (!(cin >> duracion) || cin.peek() != '\n' || duracion <= 0)
                {

                    cout << "¡ERROR! Ingrese un valor numérico positivo mayor a 0" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    cout << "Duración (en minutos): ";
                }

                peliculas[numPeliculas].setDuracion(duracion);

                cout << "Género: ";
                getline(cin >> ws, genero);
                peliculas[numPeliculas].setGenero(genero);

                cout << "Calificación (0 al 10): ";

                while (!(cin >> calificacion) || cin.peek() != '\n' || calificacion < 0 || calificacion > 10)
                {

                    cout << "¡ERROR! La calificación debe ser un número entre 0 y 10" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    cout << "Calificación: ";
                }

                peliculas[numPeliculas].setCalificacion(calificacion);

                cout << "Estado (1 = Disponible, 0 = Prestado): ";

                while (!(cin >> disponible) || cin.peek() != '\n' || (disponible != 0 && disponible != 1))
                {

                    cout << "¡ERROR! Ingrese una opción valida \n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    cout << "Estado (1 = Disponible, 0 = Prestado): ";
                }

                peliculas[numPeliculas].setDisponible(disponible);

                cout << "¡Película agregada exitosamente!\n\n";

                numPeliculas++;
            }
            else
            {

                cout << "No se pueden crear mas de 5 películas, elimina y modifica una de las películas existentes para agregar una diferente.\n\n";
            }

            cout << "Presione cualquier tecla para volver al menú principal";

            _getch();

            break;

        case 3:

            if (numPeliculas > 0)
            {

                int opcion, subopcion;

                system("cls");

                cout << "##################################################\n"
                        "###      Sistema Gestión de Videoteca          ###\n"
                        "##################################################\n\n"
                        "           Modificar películas                    \n\n";

                mostrarlistaPeliculas(peliculas, numPeliculas);

                cout << "\n\n¿Que película desea modificar:?\n"
                        "<<";

                while (!(cin >> opcion) || cin.peek() != '\n' || opcion < 1 || opcion > numPeliculas)
                {

                    cout << "¡ERROR! Ingrese un número valido (1-" << numPeliculas << ")\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Que película desea modificar:?\n"
                            "<<";
                }

                do
                {

                    system("cls");

                    cout << "##################################################\n"
                            "###      Sistema Gestión de Videoteca          ###\n"
                            "##################################################\n\n"
                            "           Modificar película:                    \n\n";

                    cout << peliculas[opcion - 1].getTitulo() << " (" << peliculas[opcion - 1].getAnio() << ") - Director: " << peliculas[opcion - 1].getDirector() << "\n\n"
                                                                                                                                                                       "1. Título\n"
                                                                                                                                                                       "2. Director\n"
                                                                                                                                                                       "3. Año\n"
                                                                                                                                                                       "4. Sinopsis\n"
                                                                                                                                                                       "5. Duración\n"
                                                                                                                                                                       "6. Género\n"
                                                                                                                                                                       "7. Calificación\n"
                                                                                                                                                                       "8. Disponible\n"
                                                                                                                                                                       "9. Volver al menú principal\n\n\n"
                                                                                                                                                                       "¿Que desea cambiar?\n"
                                                                                                                                                                       "<<";

                    while (!(cin >> subopcion) || cin.peek() != '\n' || subopcion < 1 || subopcion > 9)
                    {

                        cout << "¡ERROR! Ingrese una opción valida (1-9) \n \n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Que desea cambiar?\n"
                                "<<";
                    }

                    switch (subopcion)
                    {

                    case 1:
                    {

                        string titulo;

                        cout << "Ingrese el nuevo título: ";
                        cin.ignore();
                        getline(cin, titulo);
                        peliculas[opcion - 1].setTitulo(titulo);
                        cout << "¡Título modificado exitosamente!";
                        sleep(1);

                        break;
                    }

                    case 2:
                    {

                        string director;

                        cout << "Ingrese el nuevo director: ";
                        cin.ignore();
                        getline(cin, director);
                        peliculas[opcion - 1].setDirector(director);
                        cout << "¡Director modificado exitosamente!";
                        sleep(1);

                        break;
                    }

                    case 3:

                        int anio;

                        cout << "Ingrese el nuevo año: ";

                        while (!(cin >> anio) || cin.peek() != '\n')
                        {

                            cout << "¡ERROR! Ingrese un valor numérico\n";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');

                            cout << "Ingrese el nuevo año: ";
                        }

                        peliculas[opcion - 1].setAnio(anio);

                        cout << "¡Año modificado exitosamente!";
                        sleep(1);

                        break;

                    case 4:
                    {

                        string sinopsis;

                        cout << "Ingrese la nueva sinopsis: ";
                        cin.ignore();
                        getline(cin, sinopsis);
                        peliculas[opcion - 1].setSinopsis(sinopsis);
                        cout << "¡Sinopsis modificada exitosamente!";
                        sleep(1);

                        break;
                    }

                    case 5:

                        int duracion;

                        cout << "Ingrese la nueva duración: ";

                        while (!(cin >> duracion) || cin.peek() != '\n' || duracion <= 0)
                        {

                            cout << "¡ERROR! Ingrese un valor numérico positivo mayor a 0" << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');

                            cout << "Ingrese la nueva duración: ";
                        }

                        peliculas[opcion - 1].setDuracion(duracion);
                        cout << "¡Duración modificada exitosamente!";
                        sleep(1);

                        break;

                    case 6:
                    {

                        string genero;

                        cout << "Ingrese el nuevo género: ";
                        cin.ignore();
                        getline(cin, genero);
                        peliculas[opcion - 1].setGenero(genero);
                        cout << "¡Género modificado exitosamente!";
                        sleep(1);

                        break;
                    }

                    case 7:

                        double calificacion;

                        cout << "Ingrese la nueva calificación: ";

                        while (!(cin >> calificacion) || cin.peek() != '\n' || calificacion < 0 || calificacion > 10)
                        {

                            cout << "¡ERROR! La calificación debe ser un número entre 0 y 10\n";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');

                            cout << "Ingrese la nueva calificación: ";
                        }

                        peliculas[opcion - 1].setCalificacion(calificacion);
                        cout << "¡Calificación modificada exitosamente!";
                        sleep(1);

                        break;

                    case 8:

                        bool disponible;

                        cout << "Estado (1 = Disponible, 0 = Prestado): ";

                        while (!(cin >> disponible) || cin.peek() != '\n' || (disponible != 0 && disponible != 1))
                        {

                            cout << "¡ERROR! Ingrese una opción valida \n";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');

                            cout << "Estado (1 = Disponible, 0 = Prestado): ";
                        }

                        peliculas[opcion - 1].setDisponible(disponible);
                        cout << "¡Estado modificado exitosamente!";
                        sleep(1);

                        break;

                    case 9:

                        cout << "Volviendo al menu principal.........";
                        sleep(1.5);

                        break;
                    }

                } while (subopcion != 9);
            }
            else
            {

                cout << "No hay películas creadas, cree al menos una.\n\n"
                        "Presione cualquier tecla para volver al menú principal";

                _getch();
            }

            break;

        case 4:

            if (numPeliculas > 0)
            {

                int opcion;

                cout << "##################################################\n"
                        "###      Sistema Gestión de Videoteca          ###\n"
                        "##################################################\n\n"
                        "             Eliminar película                    \n\n";

                mostrarlistaPeliculas(peliculas, numPeliculas);
                cout << numPeliculas + 1 << ". Volver al menú principal\n\n";

                cout << "¿Que película desea eliminar?\n";
                cout << "<<";

                while (!(cin >> opcion) || cin.peek() != '\n' || opcion < 1 || opcion > numPeliculas + 1)
                {

                    cout << "¡ERROR! Ingrese una opción valida (1-" << numPeliculas + 1 << ")\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    cout << "Que película desea eliminar:?\n"
                            "<<";
                }

                if (opcion != numPeliculas + 1)
                {

                    peliculas[opcion - 1] = Pelicula();
                    cout << "¡Pelicula eliminada exitosamente\n\n";
                }
                else
                {

                    cout << "Volviendo al menú principal.........";
                    sleep(1.5);

                    break;
                }
            }
            else
            {

                cout << "No hay películas creadas, cree al menos una.\n\n";
            }

            cout << "Presione cualquier tecla para volver al menú principal";

            _getch();

            break;

        case 5:

            cout << "Saliendo del programa ...........";
            sleep(1.5);
            salir = true;

            break;
        }
    }

    return 0;
}
