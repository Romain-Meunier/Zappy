/*
** EPITECH PROJECT, 2020
** B-YEP-410-MAR-4-1-zappy-romain1.meunier
** File description:
** menu.cpp
*/

#include "../../include/General.hpp"

MenuSfml::MenuSfml(int port)
{
    sf::RenderWindow Window(sf::VideoMode(1920, 1080), "ZAPPY");
    menu.openFromFile("ressource/musique/title.wav");
    menu.setVolume(20);
    menu.setLoop(true);
    menu.play();
    initMenu(Window, menu, port);
}
MenuSfml::MenuSfml(sf::RenderWindow & window, int ret)
{
    initMenu(window, menu, ret);
}

MenuSfml::~MenuSfml()
{
}

void MenuSfml::_textTitle()
{
    _fontTitle.loadFromFile("ressource/texture/Bellyn.ttf");
    _title.setFont(_fontTitle);
    _title.setString("ZAPPY");
    _title.setCharacterSize(100);
    _title.setFillColor(sf::Color::White);
    _title.setStyle(sf::Text::Bold);
    _title.setPosition(800, 100);
}

void MenuSfml::_buttonPlay()
{
    _fontPlay.loadFromFile("ressource/texture/Bellyn.ttf");
    _play.setFont(_fontPlay);
    _play.setString("PLAY");
    _play.setCharacterSize(100);
    _play.setFillColor(sf::Color::White);
    _play.setStyle(sf::Text::Bold);
    _play.setPosition(100, 300);
}

void MenuSfml::_buttonSetting()
{
    _fontSetting.loadFromFile("ressource/texture/Bellyn.ttf");
    _setting.setFont(_fontSetting);
    _setting.setString("SETTING");
    _setting.setCharacterSize(100);
    _setting.setFillColor(sf::Color::White);
    _setting.setStyle(sf::Text::Bold);
    _setting.setPosition(100, 500);
}

void MenuSfml::_buttonExit()
{
    _fontExit.loadFromFile("ressource/texture/Bellyn.ttf");
    _exit.setFont(_fontExit);
    _exit.setString("EXIT");
    _exit.setCharacterSize(100);
    _exit.setFillColor(sf::Color::White);
    _exit.setStyle(sf::Text::Bold);
    _exit.setPosition(100, 700);
}

int MenuSfml::initMenu(sf::RenderWindow & window, sf::Music & menu, int port)
{
    sf::Vector2i souri = sf::Mouse::getPosition(window);
    _menuFont.loadFromFile("ressource/texture/menu.jpg");
    _menu.setTexture(_menuFont);
    _textTitle();
    _buttonPlay();
    _buttonSetting();
    _buttonExit();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {window.close();}
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (_play.getGlobalBounds().contains (event.mouseButton.x, event.mouseButton.y)) {
                        menu.stop();
                        Game play(window, port);

                    }
                    if (_setting.getGlobalBounds().contains (event.mouseButton.x, event.mouseButton.y)) {
                        SettingSfml(window, menu, port);
                    }
                    if (_exit.getGlobalBounds().contains (event.mouseButton.x, event.mouseButton.y)) {
                        window.close();
                    }
                }
            }
        }
        window.clear();
        window.draw(_menu);
        window.draw(_title);
        window.draw(_play);
        window.draw(_exit);
        window.draw(_setting);
        window.display();
    }
   return (0);
}