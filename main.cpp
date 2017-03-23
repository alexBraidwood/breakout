#include <GameMain.h>
#include <GameClock.h>
#include <SDL2/SDL.h>

int main(int argc, char* args[])
{
    core::GameMain game;
    core::GameClock clock;
    game.init();
    game.start();
    clock.start();
    while (game.state != GameState::Quit) {
        auto currentDt = clock.deltaTime();
        game.processInput(currentDt);
        game.update(currentDt);
        game.render();
    }
    SDL_Quit();
    game.resourceBatch.clear();
    return 0;
}