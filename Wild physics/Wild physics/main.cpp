#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "Juego.h"
using namespace sf;
using namespace std;

int main() {
    srand(static_cast<unsigned>(std::time(nullptr)));

     Juego game;
     game.jugar();
    

    return 0;
}
