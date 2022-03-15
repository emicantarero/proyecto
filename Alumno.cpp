#include <iostream>
#include "Alumno.h"
#include <iomanip>
using namespace std;
Alumno::Alumno(string nombre) {
	this->nombre = nombre;
	asistencia = 0;
	audio = 0;
	noAudio = 0;
	porcentaje = 0.0;
}
Alumno& Alumno::operator++() {
	this->asistencia++;
	return *this;
}
void Alumno::aumentarAudio() {
	this->audio++;
}
void Alumno::aumentarNoAudio() {
	this->noAudio++;
}
string Alumno::toString() {
	return nombre;
}
double Alumno::calcularPorcentaje() {
	double porcentaje = (audio * 100) / asistencia;
	this->porcentaje = porcentaje;
	return this->porcentaje;
}
ostream& operator << (ostream& o, Alumno& p)
{
	o << defaultfloat;
	o << "Nombre: " << p.nombre << endl;
	o << "Asistencia: " << p.asistencia << endl;
	o << "No Audio: " << p.noAudio << endl;
	o << "Audio: " << p.audio << endl;
	
	o << "Porcentaje: " <<fixed<<setprecision(2) << p.calcularPorcentaje() << "%" << endl;
	o << endl;

	return o;
}