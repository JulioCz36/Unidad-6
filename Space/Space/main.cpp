#include <SFML/Graphics.hpp>

using namespace sf;

int main() {
    const int ancho = 800;
    const int alto = 600;

    const float radio = 30.0f;
    Vector2f velocidad(0.0f, 0.0f);
    const float aceleracion = 50.0f;
    const float frenado = 10.0f;    
    const float velocidadMaxima = 300.0f;

    CircleShape circulo(radio);
    circulo.setFillColor(Color::Red);
    circulo.setPosition(ancho / 2, alto / 2);

    Clock reloj;

    RenderWindow window(VideoMode(ancho, alto), "Space");

    while (window.isOpen()) {
        Event evento;
        while (window.pollEvent(evento)) {
            if (evento.type == Event::Closed) {
                window.close();
            }
        }

        float deltaTime = reloj.restart().asSeconds();

        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            if (velocidad.x < velocidadMaxima) {
                velocidad.x += aceleracion * deltaTime;
            }
        }
        else if (Keyboard::isKeyPressed(Keyboard::Left)) {
            if (velocidad.x > - velocidadMaxima) {
                velocidad.x -= aceleracion * deltaTime;
            }
        }

        if (!Keyboard::isKeyPressed(Keyboard::Right) && !Keyboard::isKeyPressed(Keyboard::Left)) {
            if (velocidad.x > 0) {
                velocidad.x -= frenado * deltaTime;
                if (velocidad.x < 0) velocidad.x = 0;
            }
            else if (velocidad.x < 0) {
                velocidad.x += frenado * deltaTime;
                if (velocidad.x > 0) velocidad.x = 0;
            }
        }

        // "Actualizar"
        circulo.move(velocidad * deltaTime);

        // Limitar el movimiento
        if (circulo.getPosition().x < 0) {
            circulo.setPosition(0, circulo.getPosition().y);
        }
        else if (circulo.getPosition().x + radio * 2 > ancho) {
            circulo.setPosition(ancho - radio * 2, circulo.getPosition().y);
        }

        window.clear();
        window.draw(circulo);
        window.display();
    }

    return 0;
}
