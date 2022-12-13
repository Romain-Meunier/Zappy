/*
** EPITECH PROJECT, 2020
** B-YEP-410-MAR-4-1-zappy-romain1.meunier
** File description:
** Game.hpp
*/

#ifndef GAME_HPP
#define GAME_HPP

class Game
{
private:
    //------------Texture/Sprite-------------//
    sf::Texture _gameTexture;
    sf::Texture _floorTexture;
    sf::Sprite _gameSprite;
    sf::Sprite _floorSprite;
    //---------------Font/Tex----------------//
    sf::Font _trantorFont;
    sf::Font _returnFont;
    sf::Text _trantorText;
    sf::Text _returnText;
public:
//------------CONSTRUCTEUR-------------//
    Game(sf::RenderWindow & window, int port);
//------------DESTRUCTEUR-------------//
    ~Game();
//---------------INIT----------------//
    int _initGame(sf::RenderWindow & window, int port);
//--------------TITLE---------------//
    void _planetName();
    void _returnName();
    int _createmap(sf::RenderWindow & window, char *map,  sf::RectangleShape rect[], int x, int y);
    
};



#endif