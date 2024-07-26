#ifndef UNIDAD_HPP
#define UNIDAD_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

class Unidad {
private:
    int vida;
    int salud;
    int ataque;
    int nivel;
    std::string tipo;

public:
    Unidad() : vida(100), salud(100), ataque(10), nivel(1), tipo("Guerrero") {}

    Unidad(int v, int a, int n, const std::string& t) : vida(v), salud(v), ataque(a), nivel(n), tipo(t) {}

    int getVida() const { return vida; }
    int getSalud() const { return salud; }
    int getAtaque() const { return ataque; }
    int getNivel() const { return nivel; }
    std::string getTipo() const { return tipo; }

    void setVida(int v) { vida = v; }
    void setSalud(int s) { salud = (s < 0) ? 0 : s; }
    void setAtaque(int a) { ataque = a; }
    void setNivel(int n) { nivel = n; }
    void setTipo(const std::string& t) { tipo = t; }

    int calcularPorcentajeSalud() const {
        return (salud * 100) / vida;
    }

    void imprimirBarraVida() const {
        int porcentaje = calcularPorcentajeSalud();
        int numChars = porcentaje / 5;
        for (int i = 0; i < numChars; ++i) {
            std::cout << "%";
        }
        for (int i = numChars; i < 20; ++i) {
            std::cout << "=";
        }
        std::cout << std::endl;
    }

    void recibeAtaque(int ptosAtaque) {
        salud -= ptosAtaque;
        if (salud < 0) salud = 0;
    }

    void atacar(Unidad &objetivo) {
        std::srand(std::time(0));
        int puntosAtaque;
        if (objetivo.getNivel() > nivel) {
            puntosAtaque = std::rand() % (ataque / 2) + 1;
        } else {
            puntosAtaque = std::rand() % (ataque / 2) + (ataque / 2);
        }
        objetivo.recibeAtaque(puntosAtaque);
    }

    void imprimir() const {
        std::cout << tipo << ":" << std::endl;
        std::cout << "Vida máxima: " << vida << std::endl;
        std::cout << "Salud actual: " << salud << std::endl;
        std::cout << "Ataque máximo: " << ataque << std::endl;
        std::cout << "Nivel: " << nivel << std::endl;
        std::cout << "Barra de vida: ";
        imprimirBarraVida();
    }

    bool estaVivo() const {
        return salud > 0;
    }
};

#endif 