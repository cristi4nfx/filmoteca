#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include "pelicula.h"

using namespace std;

Pelicula::Pelicula(string _titulo, string _director, int _anio, string _sinopsis, int _duracion, string _genero, double _calificacion, bool _disponible){
    
    titulo = _titulo;
    director = _director;
    anio = _anio;
    sinopsis = _sinopsis;
    duracion = _duracion;
    genero = _genero;
    calificacion = _calificacion;
    disponible = _disponible;

}

Pelicula::Pelicula(){

    titulo = "Pelicula eliminada (modificar)";
    director = "";
    anio = 0000;
    sinopsis = "";
    duracion = 0;
    genero = "";
    calificacion = 0.0;
    disponible = 0;

}

string Pelicula::duracionFormatoHora(){

    int horas = duracion / 60;
    int minutos = duracion % 60;

    return to_string(horas) + "h " + to_string(minutos) + " min";
}

string Pelicula::mostrarDisponible(){
    return disponible ? "Disponible" : "Prestado";
}

//Funcion para mostrar una lista de las peliculas registradas
void mostrarlistaPeliculas(Pelicula peliculas[], int size) {

    for (int i = 0; i < size; i++) {
        
        if (peliculas[i].getDuracion() != 0){

            cout << i + 1 << ". " << peliculas[i].getTitulo() << " (" << peliculas[i].getAnio() << ")\n";
        }
        else {

            cout << i + 1 << ". " << peliculas[i].getTitulo() << "\n" ;

        }
    }
    
}

string Pelicula::toString(){

    string infopelicula = "";
    stringstream calificacionmod;

    if (calificacion != 10){

        calificacionmod << fixed << setprecision(1) << calificacion;

    }
    else{

        calificacionmod << calificacion;

    }

    infopelicula += "Titulo:          " + titulo + " (" + to_string(anio) + ")" + "\n";
    infopelicula += "Calificación:    " + calificacionmod.str() + "\n";
    infopelicula += "Duración:        " + duracionFormatoHora() + "\n";
    infopelicula += "Director:        " + director + "\n";
    infopelicula += "Género:          " + genero + "\n";
    infopelicula += "Estado:          " + mostrarDisponible() + "\n";
    infopelicula += "Sinopsis: \n" + sinopsis + "\n\n\n";

    return infopelicula;
}


void Pelicula:: setTitulo(string _titulo){
    titulo = _titulo;
}

void Pelicula:: setDirector(string _director){
    director = _director;
}

void Pelicula:: setAnio(int _anio){
    anio = _anio;
}

void Pelicula:: setSinopsis(string _sinopsis){
    sinopsis = _sinopsis;
}

void Pelicula:: setDuracion(int _duracion){
    duracion = _duracion;
}

void Pelicula:: setGenero(string _genero){
    genero = _genero;
}

void Pelicula:: setCalificacion(double _calificacion){
    calificacion = _calificacion;
}

void Pelicula:: setDisponible(bool _disponible){
    disponible = _disponible;
}

string Pelicula::getTitulo(){
    return titulo;
}

string Pelicula::getDirector(){
    return director;
}

int Pelicula::getAnio(){
    return anio;
}

string Pelicula::getSinopsis(){
    return sinopsis;
}

int Pelicula::getDuracion(){
    return duracion;
}

string Pelicula::getGenero(){
    return genero;
}

double Pelicula::getCalificacion(){
    return calificacion;
}

bool Pelicula::getDisponible(){
    return disponible;
}

//Eliminar peliculas ( reemplazar en el if de eliminar peliculas)

//   for (int i = opcion - 1; i < numPeliculas - 1; ++i) {

//       peliculas[i] = peliculas[i + 1]; // Desplazar los elementos un espacio hacia atras para reemplazar el objeto eliminado

//    }
//    numPeliculas--; 
//    cout << "Pelicula eliminada correctamente.\n\n";