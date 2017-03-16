#include <GameMain.h>
#include <GameClock.h>

int main()
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
    game.resourceBatch.clear();
    return 0;
}