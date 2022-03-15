// proyecto.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include "Alumno.h"
#include <fstream>
#include <string>

using namespace std;
using std::filesystem::recursive_directory_iterator;

vector<Alumno> alumnos;
void mostrarRutas(vector<string> rutas) {
	for (string s : rutas) {
		cout << "---Mostrando archivo---" << endl;
		cout << s << endl;
	}
}

vector <string> separarArchivos() {
	string path = "./Contenido del Curso";
	vector <string> rutas;
	for (const auto& file : recursive_directory_iterator(path)) {
		string path = file.path().string();
		if (path.find(".txt") != string::npos) {
			rutas.push_back(path);
		}
	}
	return rutas;
}

string separarNombre(string x) {
	string nombre = "";
	int i = 0;
	do {
		nombre += x[i];
		i++;
	} while ((x[i] != ' ') && (i < x.size()));
	return nombre;
}
int pos;
bool inVector(string x) {
	bool inVector = false;
	for (Alumno a : alumnos) {
		if (a.toString() == x)
			inVector = true;
	}
	return inVector;
}

int verificarPos(string x) {
	int i = 0;
	for (Alumno a : alumnos) {
		if (a.toString() == x)
			break;
		i++;
	}
	return i;
}

void listarAlumnos(string texto) {
	if (texto[0] == '2' || texto.find("EXAMEN") != string::npos || texto.find("ASISTIERON") != string::npos || texto.empty()) {

	}
	else {
		string nombre = separarNombre(texto);
		if (alumnos.empty()) {
			Alumno a(nombre);
			++a;
			if (texto.find("NO_AUDIO") != string::npos)
				a.aumentarNoAudio();
			else
				a.aumentarAudio();
			alumnos.push_back(a);
		}
		else {
			if (inVector(nombre)) {
				int pos = verificarPos(nombre);
				++alumnos[pos];
				if (texto.find("NO_AUDIO") != string::npos)
					alumnos[pos].aumentarNoAudio();
				else
					alumnos[pos].aumentarAudio();
			}
			else {
				Alumno a(nombre);
				++a;
				if (texto.find("NO_AUDIO") != string::npos)
					a.aumentarNoAudio();
				else
					a.aumentarAudio();
				alumnos.push_back(a);
			}
		}
	}
}

void mostrarAlumnos(vector<Alumno> a) {
	for (Alumno e : a)
	{
		cout << e << endl;
	}
}

void revisarArchivos(vector<string> rutas) {
	string texto;
	for (string s : rutas)
	{
		ifstream archivo;
		archivo.open(s, ios::in);
		if (!archivo) {
			cerr << "No se pudo abrir el archivo" << endl;
			exit(EXIT_FAILURE);
		}
		else {
			while (!archivo.eof()) {
				getline(archivo, texto);
				cout << texto << endl;
				listarAlumnos(texto);
			}
		}
		archivo.close();
	}

}

int main() {
	vector <string> rutas = separarArchivos();
	mostrarRutas(rutas);
	revisarArchivos(rutas);
	mostrarAlumnos(alumnos);
	cout << alumnos.size();
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
