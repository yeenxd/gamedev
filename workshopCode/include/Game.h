#ifndef GAME_H
#define GAME_H
#include "Game.h"
#include "TextureHolder.h"
#include "Entity.h"
#include <SFML/Graphics.hpp>

using namespace std;

class Game
{
    public:
        Game();
        virtual ~Game();
        void             run();

    private:
        void             processEvents();
        void             update(sf::Time deltaTime);
        void             render();
        void             handlePlayerInput(sf::Keyboard::Key key,bool isPressed);

    private:
        sf::RenderWindow mWindow;
        sf::CircleShape  mPlayer;
        bool mIsMovingUp = false;
        bool mIsMovingDown = false;
        /*bool mIsMovingLeft = false;
        bool mIsMovingRight = false;*/
        float PlayerSpeed = 100.0f;
        sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
        sf::Sprite playerPlane;
        Entity PlayerOne;

         //define window as boundary, located at (0,0) with a size of the window
        sf::Vector2i mBoundaryPosition=sf::Vector2i(0,0);
        sf::Vector2i mBoundarySize=sf::Vector2i(900,790);
        sf::IntRect mBoundaryRectangle = sf::IntRect(mBoundaryPosition,mBoundarySize);

        Entity Background;

        Entity EnemyOne;
        bool isPlayerHitEnemy = false;
        void setFont(string word);

        sf::Font font;
        sf::Text text;
};








#endif // GAME_H
