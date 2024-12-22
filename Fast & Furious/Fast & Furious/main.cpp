#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
using namespace sf;

int main() {
    const int ancho = 800;
    const int alto = 600;

    // Variables del circulo
    const float radio = 30.0f;
    float velocidadInicial = 100.0f;
    const float velocidadFinal = 400.0f;
    const float incremento = 20.0f;

    CircleShape circulo(radio);
    circulo.setFillColor(Color::Red);
    circulo.setPosition(0, alto / 2 - radio);

    Clock reloj;

    RenderWindow window(VideoMode(ancho, alto), "Fast & Furious");

    while (window.isOpen()) {
        
        Event evento;
        while (window.pollEvent(evento)) {
            if (evento.type == Event::Closed) {
                window.close();
            }
        }

        // Calculo de tiempo
        float deltaTime = reloj.restart().asSeconds();


        Vector2f posicion = circulo.getPosition();
        posicion.x += velocidadInicial * deltaTime;


        if (posicion.x - radio > ancho) {
            posicion.x = - radio * 2;
            velocidadInicial += incremento;

            if (velocidadInicial > velocidadFinal) {
                velocidadInicial = velocidadFinal;
            }
        }
        
        // El "actualizar"
        circulo.setPosition(posicion);

        window.clear();
        window.draw(circulo);
        window.display();
    }

    return 0;
}
