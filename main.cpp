#include <SFML/Graphics.hpp>
#include "Engine/GameEngine.hpp"
int main()
{
    GameEngine* UDEngine = new GameEngine;
    UDEngine->Run();
    delete UDEngine;
    UDEngine = nullptr;
    return 0;
}