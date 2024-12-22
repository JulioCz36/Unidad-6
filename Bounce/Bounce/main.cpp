#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

int main() {
    const int ancho = 800;
    const int alto = 600;

    // pelota
    const float radio = 30.0f;
    const float gravedad = 500.0f;
    const float rebote = 0.8f;
    const float piso = alto - radio * 2;

    CircleShape pelota(radio);
    pelota.setFillColor(Color::Blue);
    pelota.setPosition(ancho / 2, 0);

    float velocidadY = 0.0f;
    Clock reloj;

    RenderWindow window(VideoMode(ancho, alto), "Bounce");

    while (window.isOpen()) {
        Event evento;
        while (window.pollEvent(evento)) {
            if (evento.type == Event::Closed) {
                window.close();
            }
        }

        // tiempo
        float deltaTime = reloj.restart().asSeconds();

        velocidadY += gravedad * deltaTime;

        // Actualizar 
        pelota.move(0, velocidadY * deltaTime);

        if (pelota.getPosition().y >= piso) {
            pelota.setPosition(pelota.getPosition().x, piso);
            velocidadY = - velocidadY * rebote;      

            if (abs(velocidadY) < 10.0f) {
                velocidadY = 0.0f;
            }
        }

        window.clear();
        window.draw(pelota);
        window.display();
    }

    return 0;
}
