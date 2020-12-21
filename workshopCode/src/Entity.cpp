//
//  Entity.cpp
//  SFML tut
//
//  Created by Adili on 04/11/2020.
//  Copyright © 2020 Adili. All rights reserved.
//

#include "Entity.h"
#include "TextureHolder.h"
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


Entity::Entity()
{}

void Entity::setVelocity(sf::Vector2f velocity)
{
    mVelocity = velocity;
}

void Entity::setVelocity(float vx, float vy)
{
    mVelocity.x = vx;
    mVelocity.y = vy;
}

sf::Vector2f Entity::getVelocity() const
{
    return mVelocity;
}


void Entity::setSpriteScale(float X, float Y)
{

    spriteObj.scale(sf::Vector2f(X, Y));

}

sf::Sprite Entity::getSprite()
{
    /*if(Textures::Fish)
        spriteObj=sf::Sprite sprite(textures,(0,0,135,80));*/
    return spriteObj;
}

void Entity::load(Textures::ID id, const std::string& filename)
{
    textures.load(id, filename);
}

void Entity::bindTexture(Textures::ID id)
{
    spriteObj.setTexture(textures.get(id));
}

void Entity::setSpritePosition(float X, float Y)
{
    spriteObj.setPosition(X,Y);
}

sf::Vector2f Entity::getSpritePosition()
{
    return spriteObj.getPosition();
}

void Entity::setMovement(sf::Vector2f movementVector)
{
    spriteObj.move(movementVector);
}

/*void Entity::setRect(sf::IntRect rectSprite)
{
    spriteObj.setTextureRect(0, 0, 135, 80);
}*/

void Entity::updateMovementPattern(sf::Time dt, float direction)
{
    if(!direction==0)
    {
        float distanceToTravel = direction;
        if(mTravelledDistance>distanceToTravel)
        {
            mDirectionIndex = (mDirectionIndex+1);
            mTravelledDistance=0.f;
        }
        setVelocity(speed,speed);
        mTravelledDistance+= speed * dt.asSeconds();
    }
}

sf::FloatRect Entity::getBoundary()
{
    return spriteObj.getGlobalBounds();
}

Entity::~Entity()
{}
