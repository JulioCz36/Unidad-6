#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace sf;
using namespace std;
class Movimiento {
    CircleShape sprite;
    Vector2f velocidad;
    float aceleracion;

public:
        Movimiento(float radius, float x, float y, float vx, float vy, float accel = 0.0f)
            : velocidad(vx, vy), aceleracion(accel) {
            sprite.setRadius(radius);
            sprite.setFillColor(Color::Red);
            sprite.setPosition(x, y);
        }

        void actualizar(float dt) {
            if (aceleracion != 0.0f) {
                velocidad.y += aceleracion * dt;
            }
            sprite.move(velocidad * dt);
        }

        void dibujar(RenderWindow& window) {
            window.draw(sprite);
        }

        FloatRect getColision() const {
            return sprite.getGlobalBounds();
        }

        void setPosicion(float x, float y) {
            sprite.setPosition(x, y);
        }
};

