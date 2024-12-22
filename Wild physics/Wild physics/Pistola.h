#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace sf;
using namespace std;

class Pistola{
    RectangleShape sprite;
    Vector2f velocidad;


  public:
        Pistola(float x, float y, float speed) {
            sprite.setSize(Vector2f(5, 20));
            sprite.setFillColor(Color::Yellow);
            sprite.setPosition(x, y);
            velocidad = Vector2f(0, speed);
        }

        void actualizar(float dt) {
            sprite.move(velocidad * dt);
        }

        void dibujar(RenderWindow& window) {
            window.draw(sprite);
        }

        FloatRect getColision() const {
            return sprite.getGlobalBounds();
        }
};

