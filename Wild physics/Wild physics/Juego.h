#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "Pistola.h"
#include "Movimiento.h"

using namespace sf;
using namespace std;

class Juego {
    RenderWindow ventana;
    RectangleShape jugador;
    vector<Pistola> balas;
    vector<Movimiento> objetos;
    Font fuente;
    Text textoPuntaje;
    int puntaje;
    float temporizadorAparicion;
    const float intervaloAparicion;

    float cooldownDisparo;
    float temporizadorDisparo;

public:
    Juego()
        : ventana(VideoMode(800, 600), "Wild physics"),
        jugador(Vector2f(10, 50)),
        puntaje(0),
        temporizadorAparicion(0.0f),
        intervaloAparicion(1.5f),
        cooldownDisparo(0.3f),
        temporizadorDisparo(0.0f) {
        ventana.setFramerateLimit(60);

        jugador.setFillColor(Color::Green);
        jugador.setPosition(400, 550);

        fuente.loadFromFile("fuente.ttf");
        textoPuntaje.setFont(fuente);
        textoPuntaje.setCharacterSize(24);
        textoPuntaje.setFillColor(Color::White);
        textoPuntaje.setPosition(10, 10);
    }

    void jugar() {
        Clock reloj;
        while (ventana.isOpen()) {
            procesarEventos();
            float dt = reloj.restart().asSeconds();
            actualizar(dt);
            dibujar();
        }
    }

    void procesarEventos() {
        Event evento;
        while (ventana.pollEvent(evento)) {
            if (evento.type == Event::Closed) {
                ventana.close();
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::Left) && jugador.getPosition().x > 0) {
            jugador.move(-300.0f * 1 / 60.0f, 0);
        }
        if (Keyboard::isKeyPressed(Keyboard::Right) && jugador.getPosition().x < 790) {
            jugador.move(300.0f * 1 / 60.0f, 0);
        }

        if (Keyboard::isKeyPressed(Keyboard::Space) && temporizadorDisparo <= 0.0f) {
            balas.emplace_back(jugador.getPosition().x + 2.5f, jugador.getPosition().y, -400.0f);
            temporizadorDisparo = cooldownDisparo;
        }
    }

    void actualizar(float dt) {
        if (temporizadorDisparo > 0.0f) {
            temporizadorDisparo -= dt;
        }

        for (auto& bala : balas) {
            bala.actualizar(dt);
        }

        balas.erase(remove_if(balas.begin(), balas.end(),
            [](const Pistola& b) { return b.getColision().top < 0; }),
            balas.end());

        for (auto& objeto : objetos) {
            objeto.actualizar(dt);
        }

        objetos.erase(remove_if(objetos.begin(), objetos.end(),
            [](const Movimiento& obj) { return obj.getColision().top > 600; }),
            objetos.end());

        for (auto it = balas.begin(); it != balas.end();) {
            bool impacto = false;
            for (auto itObjeto = objetos.begin(); itObjeto != objetos.end();) {
                if (it->getColision().intersects(itObjeto->getColision())) {
                    impacto = true;
                    puntaje += 10;
                    itObjeto = objetos.erase(itObjeto);
                }
                else {
                    ++itObjeto;
                }
            }
            if (impacto) {
                it = balas.erase(it);
            }
            else {
                ++it;
            }
        }

        temporizadorAparicion += dt;
        if (temporizadorAparicion >= intervaloAparicion) {
            generarObjeto();
            temporizadorAparicion = 0.0f;
        }

        textoPuntaje.setString("Puntaje " + to_string(puntaje));
    }

    void generarObjeto() {
        float tipo = rand() % 2;
        float x = tipo == 0 ? -50.0f : rand() % 800;
        float y = tipo == 0 ? std::rand() % 600 : -50.0f;
        float velocidadX = tipo == 0 ? 200.0f : 0.0f;
        float velocidadY = tipo == 0 ? 0.0f : 200.0f;
        float aceleracion = tipo == 0 ? 0.0f : 80.0f;

        objetos.emplace_back(20.0f, x, y, velocidadX, velocidadY, aceleracion);
    }

    void dibujar() {
        ventana.clear();
        ventana.draw(jugador);
        for (auto& bala : balas) {
            bala.dibujar(ventana);
        }
        for (auto& objeto : objetos) {
            objeto.dibujar(ventana);
        }
        ventana.draw(textoPuntaje);
        ventana.display();
    }
};
