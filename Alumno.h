#pragma once
#include <string>
#include <vector>
using namespace std;
class Alumno {
	string nombre;
	double porcentaje;
	double asistencia, audio, noAudio;
public:
	Alumno();
	Alumno(string nombre);
	Alumno& operator ++();
	void aumentarAudio();
	void aumentarNoAudio();
	string toString();
	double calcularPorcentaje();
	friend ostream& operator << (ostream& o, Alumno& p);
	friend void ordenar(vector<Alumno> alumnos);
};