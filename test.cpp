#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void generarPasajeros(int nv, int pasajeros[][2]);
int generarDistanciaVuelo();
int generarCodigoPasajero();
int calcularEstatus(int codigo);
int calcularBonificacionMillas(int distancia, int estatus);
void actualizarMillas(int nv, int pasajeros[][2], int millas[]);

int main() {
    srand(time(0)); // Inicializar generador de números aleatorios

    int nv; // Número de vuelos
    cout << "Ingrese el número de vuelos: ";
    cin >> nv;

    if (nv <= 0) {
        cout << "El número de vuelos debe ser mayor que 0." << endl;
        return 1;
    }

    int pasajeros[nv][2]; // Arreglo para almacenar códigos de pasajeros y millas
    int millas[nv]; // Arreglo para almacenar millas de cada pasajero

    // Generar vuelos y pasajeros
    for (int i = 0; i < nv; i++) {
        int npasajeros = rand() % 51 + 50; // Número aleatorio de pasajeros entre 50 y 100
        int distancia = rand() % 4501 + 500; // Distancia aleatoria entre 500 y 5000 kilómetros

        for (int j = 0; j < npasajeros; j++) {
            int codigo = generarCodigoPasajero();
            int estatus = calcularEstatus(codigo);
            int bonificacion = calcularBonificacionMillas(distancia, estatus);

            pasajeros[i][0] = codigo; // Código de pasajero
            pasajeros[i][1] = bonificacion; // Millas iniciales
        }
    }

    // Actualizar millas de cada pasajero
    actualizarMillas(nv, pasajeros, millas);

    // Mostrar resultados
    for (int i = 0; i < nv; i++) {
        cout << "Vuelo " << i + 1 << ": " << endl;
        cout << "  Código de pasajero: " << pasajeros[i][0] << endl;
        cout << "  Millas: " << millas[i] << endl;
    }

    return 0;
}

void generarPasajeros(int nv, int pasajeros[][2]) {
    for (int i = 0; i < nv; i++) {
        int npasajeros = rand() % 51 + 50; // Número aleatorio de pasajeros entre 50 y 100
        int distancia = rand() % 4501 + 500; // Distancia aleatoria entre 500 y 5000 kilómetros

        for (int j = 0; j < npasajeros; j++) {
            int codigo = generarCodigoPasajero();
            int estatus = calcularEstatus(codigo);
            int bonificacion = calcularBonificacionMillas(distancia, estatus);

            pasajeros[i][0] = codigo; // Código de pasajero
            pasajeros[i][1] = bonificacion; // Millas iniciales
        }
    }
}

int generarDistanciaVuelo() {
    return rand() % 4501 + 500; // Distancia aleatoria entre 500 y 5000 kilómetros
}

int generarCodigoPasajero() {
    return rand() % 900 + 100; // Código aleatorio entre 100 y 999
}

int calcularEstatus(int codigo) {
    if (codigo % 12 == 0) {
        return 2; // Diamante
    } else if (codigo % 7 == 0) {
        return 1; // VIP
    } else {
        return 0; // Sin estatus especial
    }
}

int calcularBonificacionMillas(int distancia, int estatus) {
    switch (estatus) {
        case 0: // Sin estatus especial
            return distancia / 100;
        case 1: // VIP
            return distancia / 60;
        case 2: // Diamante
            return distancia / 20;
        default:
            return 0;
    }
}

void actualizarMillas(int nv, int pasajeros[][2], int millas[]) {
    for (int i = 0; i < nv; i++) {
        millas[i] = pasajeros[i][1]; // Inicializar millas con bonificación inicial
    }
}
