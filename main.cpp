#include <iostream>
#include <vector>
#include <ctime>
#include <limits>
#include "Unidad.hpp"

void batalla(std::vector<Unidad>& equipo1, std::vector<Unidad>& equipo2) {
    std::srand(std::time(0));

    while (!equipo1.empty() && !equipo2.empty()) {
        int atacante1 = std::rand() % equipo1.size();
        int atacante2 = std::rand() % equipo2.size();

        equipo1[atacante1].atacar(equipo2[atacante2]);
        if (!equipo2[atacante2].estaVivo()) {
            equipo2.erase(equipo2.begin() + atacante2);
        }

        if (!equipo2.empty()) {
            atacante2 = std::rand() % equipo2.size();
            atacante1 = std::rand() % equipo1.size();

            equipo2[atacante2].atacar(equipo1[atacante1]);
            if (!equipo1[atacante1].estaVivo()) {
                equipo1.erase(equipo1.begin() + atacante1);
            }
        }
    }

    if (equipo1.empty()) {
        std::cout << "¡Equipo 2 ha ganado la batalla!" << std::endl;
    } else {
        std::cout << "¡Equipo 1 ha ganado la batalla!" << std::endl;
    }
}

Unidad crearUnidad() {
    int vida, ataque, nivel;
    std::string tipo;

    std::cout << "Introduce el tipo de la unidad: ";
    std::cin >> tipo;

    std::cout << "Introduce la vida de la unidad: ";
    std::cin >> vida;
    while(std::cin.fail() || vida <= 0){
        std::cout << "Por favor introduce un valor válido para la vida: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> vida;
    }

    std::cout << "Introduce el ataque de la unidad: ";
    std::cin >> ataque;
    while(std::cin.fail() || ataque <= 0){
        std::cout << "Por favor introduce un valor válido para el ataque: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> ataque;
    }

    std::cout << "Introduce el nivel de la unidad: ";
    std::cin >> nivel;
    while(std::cin.fail() || nivel <= 0){
        std::cout << "Por favor introduce un valor válido para el nivel: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> nivel;
    }

    return Unidad(vida, ataque, nivel, tipo);
}

int main() {
    int numUnidades;
    std::cout << "Introduce el número de unidades por equipo: ";
    std::cin >> numUnidades;
    while(std::cin.fail() || numUnidades <= 0){
        std::cout << "Por favor introduce un valor válido para el número de unidades: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> numUnidades;
    }

    std::vector<Unidad> equipo1;
    std::vector<Unidad> equipo2;

    std::cout << "Crear unidades para el equipo 1:" << std::endl;
    for (int i = 0; i < numUnidades; ++i) {
        equipo1.push_back(crearUnidad());
    }

    std::cout << "Crear unidades para el equipo 2:" << std::endl;
    for (int i = 0; i < numUnidades; ++i) {
        equipo2.push_back(crearUnidad());
    }

    std::cout << "Equipo 1:" << std::endl;
    for (const auto& u : equipo1) {
        u.imprimir();
    }

    std::cout << "Equipo 2:" << std::endl;
    for (const auto& u : equipo2) {
        u.imprimir();
    }

    batalla(equipo1, equipo2);

    std::cout << "Después de la batalla:" << std::endl;
    std::cout << "Equipo 1:" << std::endl;
    for (const auto& u : equipo1) {
        u.imprimir();
    }

    std::cout << "Equipo 2:" << std::endl;
    for (const auto& u : equipo2) {
        u.imprimir();
    }

    return 0;
}
