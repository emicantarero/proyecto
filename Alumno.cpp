#include <iostream>
#include "Alumno.h"
#include <iomanip>
using namespace std;
Alumno::Alumno() {

}
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
	o.width(16); o <<p.nombre; o.width(8); o << p.audio; o.width(9); o<< p.noAudio;
	o.width(11); o << p.asistencia; o.width(10); o << fixed << setprecision(2) << p.calcularPorcentaje() << "%" << endl;
	return o;
}