/*
** EPITECH PROJECT, 2020
** B-YEP-410-MAR-4-1-zappy-romain1.meunier
** File description:
** setting.cpp
*/


#include "../../include/General.hpp"

SettingSfml::SettingSfml(sf::RenderWindow & window, sf::Music  & menu, int port)
{
    _initSetting(window, menu, port);
}

SettingSfml::~SettingSfml()
{
}

void SettingSfml::_buttonStompMusic()
{
    _settingSongStop.loadFromFile("ressource/texture/Bellyn.ttf");
    _songStop.setFont(_settingSongStop);
    _songStop.setString("STOP SONG");
    _songStop.setCharacterSize(100);
    _songStop.setFillColor(sf::Color::White);
    _songStop.setStyle(sf::Text::Bold);
    _songStop.setPosition(700, 900);
}

void SettingSfml::_buttonReturn()
{
    _settngTextReturn.loadFromFile("ressource/texture/Bellyn.ttf");
    _settingReturn.setFont(_settngTextReturn);
    _settingReturn.setString("RETURN");
    _settingReturn.setCharacterSize(100);
    _settingReturn.setFillColor(sf::Color::White);
    _settingReturn.setStyle(sf::Text::Bold);
    _settingReturn.setPosition(100, 0);
}

int SettingSfml::_initSetting(sf::RenderWindow & window, sf::Music & menu, int port)
{
    int song = 0;
    int ret = 0;
    _settingBackground.loadFromFile("ressource/texture/setting.jpg");
    _setStettingBackground.setTexture(_settingBackground);
    _buttonStompMusic();
    _buttonReturn();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {window.close();}
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (_settingReturn.getGlobalBounds().contains (event.mouseButton.x, event.mouseButton.y)) {
                        MenuSfml menu(window, port);
                    }
                    if (_songStop.getGlobalBounds().contains (event.mouseButton.x, event.mouseButton.y)) {
                        song = song + 1;
                        if (song == 1) {
                            menu.stop();
                            ret = 0;
                        }
                    }
                }
            }
        }
            window.clear();
            window.draw(_setStettingBackground);
            window.draw(_settingReturn);
            window.draw(_songStop);
            window.display();
    }
    return (0);
}