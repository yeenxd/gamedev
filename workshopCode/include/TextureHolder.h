#ifndef TEXTUREHOLDER_H
#define TEXTUREHOLDER_H
#include <SFML/Graphics.hpp>

namespace Textures
{
    enum ID {Landscape, Fish, Missile, Enemy};
}

class TextureHolder
{
    public:
        TextureHolder();
        virtual ~TextureHolder();
        void                load (Textures::ID id, const std::string& filename);
        sf::Texture&        get(Textures::ID id);
        const sf::Texture&  get(Textures::ID id) const;


    protected:

    private:
        std::map<Textures::ID, std::unique_ptr<sf::Texture>> mTextureMap;
};



#endif // TEXTUREHOLDER_H
