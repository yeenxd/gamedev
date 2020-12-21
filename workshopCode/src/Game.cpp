#include "Game.h"
#include "TextureHolder.h"
#include "Entity.h"
#include <SFML/Graphics.hpp>

using namespace std;

Game::Game()
: mWindow(sf::VideoMode(1200, 900), "Chupa Trip")
, playerPlane() //mPlayer()
{
    //playerPlane.setTexture)
    /*mPlayer.setRadius(40.f);
    mPlayer.setPosition(100.f, 100.f);
    mPlayer.setFillColor(sf::Color::Cyan);*/
    PlayerOne.load(Textures::Fish, "mainChar.png");
    PlayerOne.bindTexture(Textures::Fish);
    PlayerOne.setSpriteScale(0.35f, 0.35f);
    PlayerOne.setSpritePosition(20.f,630.f);
    Background.load(Textures::Landscape,"bg.png");
    Background.bindTexture(Textures::Landscape);
    Background.setSpriteScale(0.22f,0.22f);
    Background.setSpritePosition(-150.f,-60.f);
    EnemyOne.load(Textures::Enemy,"shark1.png");
    EnemyOne.bindTexture(Textures::Enemy);
    //EnemyOne.setSpriteScale(0.1f,0.1f);
    EnemyOne.setSpritePosition(800.f,630.f);


}//ctor


Game::~Game()
{
    //dtor
}

void Game::handlePlayerInput(sf::Keyboard::Key key,bool isPressed)
{
    if (key == sf::Keyboard::W)
        mIsMovingUp = isPressed;
    else if (key == sf::Keyboard::S)
        mIsMovingDown = isPressed;
    /*else if (key == sf::Keyboard::A)
        mIsMovingLeft = isPressed;
    else if (key == sf::Keyboard::D)
        mIsMovingRight = isPressed;*/
}

void Game::processEvents()
{
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
                break;
            case sf::Event::Closed:
                mWindow.close();
                break;
        }
    }
}

void Game::update(sf::Time deltaTime)
{
    bool isPlayerinWindow=mBoundaryRectangle.contains(PlayerOne.getSpritePosition().x,PlayerOne.getSpritePosition().y);

    sf::Vector2f movement(0.f, 0.f);

    if(isPlayerinWindow)
    {
    if (mIsMovingUp)
        movement.y -= PlayerSpeed;
    if (mIsMovingDown)
        movement.y += PlayerSpeed;
    /*if (mIsMovingLeft)
        movement.x -= PlayerSpeed;
    if (mIsMovingRight)
        movement.x += PlayerSpeed;*/

    PlayerOne.setMovement(movement*deltaTime.asSeconds()); //move(movement * deltaTime.asSeconds());
    EnemyOne.setMovement(sf::Vector2f(-0.8f,0.f));
    }

    if(!isPlayerinWindow)
    {
        if(PlayerOne.getSpritePosition().y >= 789)
            PlayerOne.setSpritePosition(PlayerOne.getSpritePosition().x,789.f);
        if(PlayerOne.getSpritePosition().y <= 500)
            PlayerOne.setSpritePosition(PlayerOne.getSpritePosition().x,500.f);
    }

    if(PlayerOne.getBoundary().intersects(EnemyOne.getBoundary()))
    {
        isPlayerHitEnemy=true;
    }
}

void Game::setFont(string word)
{
    if(!font.loadFromFile("SentyTEA-20190904.ttf"))
        {
            throw std::runtime_error("Font::load - Failed to load font from filename");
        }
        text.setFont(font);
        text.setString(word);
        text.setCharacterSize(70);
        text.setFillColor(sf::Color::Black);
        text.setStyle(sf::Text::Bold | sf::Text::Underlined);
        text.setPosition(480.f,400.f);
}

void Game::run()
{
    sf::Clock clock;
    sf::IntRect rectSprite = sf::IntRect(0,0,135,80);
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while (mWindow.isOpen())
    {
        processEvents();
        /*if(clock.getElapsedTime().asSeconds()>0.2f)
        {
            //set the sprite max value after each tick
            if(rectSprite.left==270)
                rectSprite.left=0;
            else //set the steps of x value in each tick
                rectSprite.left += 135;
            PlayerOne.setRect(rectSprite);
            //PlayerOne.spriteObj.setTextureRect(rectSprite);
            //clock.restart();
        }*/
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }

        //start the clock tick
        //set maximum time for clock ticking


        render();
    }
    /*TextureHolder textures;
    textures.load(Textures::Fish, "mainChar.png");

    playerPlane.setTexture(textures.get(Textures::Fish));
    playerPlane.scale(0.1f,0.1f);*/
}

void Game::render()
{
    mWindow.clear();
    mWindow.draw(Background.getSprite()); //First, draw BG, then draw P1

    if(isPlayerHitEnemy==false)
    {
        mWindow.draw(PlayerOne.getSprite());
    }
    else if(isPlayerHitEnemy==true)
    {
        setFont("Game Over");
        mWindow.draw(text);
    }

    mWindow.draw(EnemyOne.getSprite());
    //mWindow.draw(playerPlane);
    mWindow.display();
}
