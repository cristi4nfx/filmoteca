#ifndef PELICULA_H
#define PELICULA__H
#include <iostream>
#include <string>
using namespace std;

class Pelicula{

    private: 

        string titulo;
        string director;
        int anio;
        string sinopsis;
        int duracion;
        string genero;
        double calificacion;
        bool disponible;

    public:

        Pelicula();
        Pelicula(string titulo, string director, int anio, string sinopsis, int duracion,string genero, double calificacion, bool disponible);
        string duracionFormatoHora();
        string mostrarDisponible();
        void mostrarlistaPeliculas()const;
        string getTitulo();
        void setTitulo(string titulo);
        string getDirector();
        void setDirector(string director);
        int getAnio();
        void setAnio(int anio);
        string getSinopsis();
        void setSinopsis(string sinopsis);
        int getDuracion();
        void setDuracion(int duracion);
        string getGenero();
        void setGenero(string genero);
        double getCalificacion();
        void setCalificacion(double calificacion);
        bool getDisponible();
        void setDisponible(bool disponible);
        string toString();
};

void mostrarlistaPeliculas(Pelicula peliculas[], int size);

#endif