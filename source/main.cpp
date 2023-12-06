#include <Game.hpp>
#include <time.h>
#include <SceneGraph/Road/River.hpp>

int main() {
    srand(time(NULL));
    Game game;
    game.run();
    return 0;
}
