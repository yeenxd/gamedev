//
//  Entity.hpp
//  SFML tut
//
//  Created by Adili on 04/11/2020.
//  Copyright © 2020 Adili. All rights reserved.
//

#ifndef Entity_hpp
#define Entity_hpp

#include "TextureHolder.h"
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


struct Direction
{
    Direction(float distance);
    float distance;
};

class Entity : public sf::Transformable, TextureHolder
{
    public:

        Entity();
        ~Entity();

        void                setVelocity(sf::Vector2f velocity);
        void                setVelocity(float vx, float vy);
        sf::Vector2f        getVelocity() const;
        void                setTexture(std::string filename);

        sf::Sprite          getSprite();
        void                setSpriteScale(float X, float Y);

        void                loadTexture(const std::string& filename);

        void                load(Textures::ID id, const std::string& filename);
        void                bindTexture(Textures::ID id);
        void                setSpritePosition(float X,float Y);

        sf::Vector2f        getSpritePosition();
        void                setMovement(sf::Vector2f movementVector);

        void                updateMovementPattern(sf::Time dt, float direction);
        float               speed=2.f;

        sf::FloatRect       getBoundary();

        //void                setRect(sf::IntRect rectSprite);

    private:
        sf::Vector2f        mVelocity;
        sf::Texture         mTexture;
        sf::Sprite          spriteObj;
        TextureHolder       textures;

        float               mTravelledDistance;
        int                 mDirectionIndex=0;
        //sf::Sprite          mSprite(textures, rectSprite);

};

#endif /* Entity_hpp */
