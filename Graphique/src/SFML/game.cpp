/*
** EPITECH PROJECT, 2020
** B-YEP-410-MAR-4-1-zappy-romain1.meunier
** File description:
** game.cpp
*/

#include "../../include/General.hpp"
#include  <unistd.h>
char *cli(int port);
Game::Game(sf::RenderWindow &window, int port)
{
    _initGame(window, port);
}

Game::~Game()
{
}

void Game::_planetName()
{
    _trantorFont.loadFromFile("ressource/texture/Bellyn.ttf");
    _trantorText.setFont(_trantorFont);
    _trantorText.setString("TRANTOR");
    _trantorText.setCharacterSize(50);
    _trantorText.setColor(sf::Color::White);
    _trantorText.setStyle(sf::Text::Bold);
    _trantorText.setPosition(855, 0);
}

void Game::_returnName()
{
    _returnFont.loadFromFile("ressource/texture/Bellyn.ttf");
    _returnText.setFont(_returnFont);
    _returnText.setString("RET");
    _returnText.setCharacterSize(50);
    _returnText.setColor(sf::Color::White);
    _returnText.setStyle(sf::Text::Bold);
    _returnText.setPosition(0, 0);
}

int Game::_createmap(sf::RenderWindow &window, char *map, sf::RectangleShape rect[], int width, int heigh)
{
    //--texture floor--//
    sf::Texture grass;
    grass.loadFromFile("ressource/texture/grass.png");
    const sf::Texture *pTexture = &grass;
    //---//------------------------//---//
    //---//----- texture resource ----//---//
    sf::Texture phiras;
    sf::Texture thystame;
    sf::Texture sibur;
    sf::Texture mendiane;
    sf::Texture linemate;
    sf::Texture food;
    sf::Texture deraumere;
    sf::Texture player;
    phiras.loadFromFile("ressource/texture/phiras.png");
    thystame.loadFromFile("ressource/texture/thystame.png");
    sibur.loadFromFile("ressource/texture/sibur.png");
    mendiane.loadFromFile("ressource/texture/mendiane.png");
    linemate.loadFromFile("ressource/texture/linemate.png");
    food.loadFromFile("ressource/texture/food.png");
    deraumere.loadFromFile("ressource/texture/deraumere.png");
    player.loadFromFile("ressource/texture/player.png");
    //------//---sprite ressource-------//----//
    sf::Sprite _spPhiras;
    _spPhiras.setTexture(phiras);
    _spPhiras.setScale(0.3, 0.3);
    sf::Sprite _spthystame;
    _spthystame.setTexture(thystame);
    _spthystame.setScale(0.3, 0.3);
    sf::Sprite _spSibur;
    _spSibur.setTexture(sibur);
    _spSibur.setScale(0.3, 0.3);
    sf::Sprite _spMendiane;
    _spMendiane.setTexture(mendiane);
    _spMendiane.setScale(0.3, 0.3);
    sf::Sprite _splinemate;
    _splinemate.setTexture(linemate);
    _splinemate.setScale(0.3, 0.3);
    sf::Sprite _spFood;
    _spFood.setTexture(food);
    _spFood.setScale(0.3, 0.3);
    sf::Sprite _spDeraumere;
    _spDeraumere.setTexture(deraumere);
    _spDeraumere.setScale(0.3, 0.3);
    sf::Sprite _spPlayer;
    _spPlayer.setTexture(player);
    _spPlayer.setScale(2, 2);
    //---//-------------------//----//
    
    int i = 600, j = 100, l = 0, x = 0, y = 0, _i = i, _j = j;
    
        for (y = 0; y != heigh*width; y++)
        {
           
            if (x == width)
            {
                i = 600;
                j += 71;
                x=0;
            }
            if (map[y] == ' ')
            {
                //rect[l].setFillColor(sf::Color::Green);
                rect[l].setSize(sf::Vector2f(70, 70));
                rect[l].setPosition(i, j);
                rect[l].setTexture(pTexture);
                window.draw(rect[l]);
            }
            if (map[y]== 'P')
            {
                //rect[l].setFillColor(sf::Color::Red);
                rect[l].setSize(sf::Vector2f(70, 70));
                rect[l].setPosition(i, j);
                rect[l].setTexture(pTexture);
                _spPlayer.setPosition(i + 10, j + 10);
                window.draw(rect[l]);
                window.draw(_spPlayer);
               // std::cout << "il y a un player " << i << " " << j << std::endl;
            }
            if (map[y] == 'p')
            {
                // rect[l].setFillColor(sf::Color::Blue);
                rect[l].setSize(sf::Vector2f(70, 70));
                rect[l].setPosition(i, j);
                _spPhiras.setPosition(i + 10, j + 10);
                rect[l].setTexture(pTexture);
                window.draw(rect[l]);
                window.draw(_spPhiras);
            }
            if (map[y] == 't')
            {
                //rect[l].setFillColor(sf::Color::Black);
                rect[l].setSize(sf::Vector2f(70, 70));
                rect[l].setPosition(i, j);
                rect[l].setTexture(pTexture);
                _spthystame.setPosition(i + 10, j + 10);
                window.draw(rect[l]);
                window.draw(_spthystame);
            }
            if (map[y] == 'm')
            {
                //rect[l].setFillColor(sf::Color::Yellow);
                rect[l].setSize(sf::Vector2f(70, 70));
                rect[l].setPosition(i, j);
                rect[l].setTexture(pTexture);
                _spMendiane.setPosition(i + 10, j + 10);
                window.draw(rect[l]);
                window.draw(_spMendiane);
            }
            if (map[y] == 'l')
            {
                //rect[l].setFillColor(sf::Color::Cyan);
                rect[l].setSize(sf::Vector2f(70, 70));
                rect[l].setPosition(i, j);
                rect[l].setTexture(pTexture);
                _splinemate.setPosition(i + 10, j + 10);
                window.draw(rect[l]);
                window.draw(_splinemate);
            }
            if (map[y] == 'f')
            {
                //rect[l].setFillColor(sf::Color::Magenta);
                rect[l].setSize(sf::Vector2f(70, 70));
                rect[l].setPosition(i, j);
                rect[l].setTexture(pTexture);
                _spFood.setPosition(i + 10, j + 10);
                window.draw(rect[l]);
                window.draw(_spFood);
            }
            if (map[y] == 'd')
            {
                //rect[l].setFillColor(sf::Color::White);
                rect[l].setSize(sf::Vector2f(70, 70));
                rect[l].setPosition(i, j);
                rect[l].setTexture(pTexture);
                _spDeraumere.setPosition(i + 10, j + 10);
                window.draw(rect[l]);
                window.draw(_spDeraumere);
            }
            if (map[y] == 's')
            {
                //rect[l].setFillColor(sf::Color::Green);
                rect[l].setSize(sf::Vector2f(70, 70));
                rect[l].setPosition(i, j);
                rect[l].setTexture(pTexture);
                _spSibur.setPosition(i + 10, j + 10);
                window.draw(rect[l]);
                window.draw(_spSibur);
            }
            i += 71;
            l++;
            x++;
        }
    return (0);
}


int Game::_initGame(sf::RenderWindow &window, int port)
{
    int width = 10;
    int heigh = 11;
    char *input;
    //char *input = cli(port);
    //std::cout << input[16];

    sf::RectangleShape _map[width * heigh];
    sf::Vector2i souri = sf::Mouse::getPosition(window);
    _gameTexture.loadFromFile("ressource/texture/game.jpg");
    _gameSprite.setTexture(_gameTexture);
    _planetName();
    _returnName();
       
    while (window.isOpen())
    {
        input = cli(port);
        sf::Event event;
        
        while (window.pollEvent(event))
        {
            
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    if (_returnText.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        MenuSfml menu(window, 0);
                    }
                }
            }
        }

        window.clear();
        window.draw(_gameSprite);
        _createmap(window, input ,_map, width, heigh);
        window.draw(_trantorText);
        window.draw(_returnText);

        window.display();
    }
    return (0);
}