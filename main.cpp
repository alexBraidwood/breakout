#include <GameMain.h>

int main()
{
    core::GameMain game;
    game.init();
    game.start();
    game.update(0.f);
    return 0;
}