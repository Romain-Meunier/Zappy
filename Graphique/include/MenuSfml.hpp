/*
** EPITECH PROJECT, 2020
** B-YEP-410-MAR-4-1-zappy-romain1.meunier
** File description:
** MenuSfml.hpp
*/

#ifndef MENUSFML_HPP
#define MENUSFML_HPP

#include "SFML/Graphics.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Config.hpp>


class MenuSfml
{
private:
//----------------Window----------------//
    sf::RenderWindow _window;
//------------Texture/Sprite------------//
    sf::Texture _menuFont;
    sf::Sprite _menu;
//---------------Font/Tex---------------//
    sf::Font _fontTitle;
    sf::Font _fontPlay;
    sf::Font _fontSetting;
    sf::Font _fontExit;
    sf::Text _title;
    sf::Text _play;
    sf::Text _setting;
    sf::Text _exit;

public:
//---------------MUSIQUE----------------//
    sf::Music menu;
//------------CONSTRUCTEUR-------------//
    MenuSfml(int port);
    MenuSfml(sf::RenderWindow & window, int ret);
//------------DESTRUCTEUR-------------//
    ~MenuSfml();
//---------------INIT----------------//
    int initMenu(sf::RenderWindow & window, sf::Music & menu, int port);
//--------------TITLE---------------//
    void _textTitle();
//---------------FUNC--------------//
    void _buttonPlay();
    void _buttonSetting();
    void _buttonExit();
};






#endif