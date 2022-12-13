/*
** EPITECH PROJECT, 2020
** B-YEP-410-MAR-4-1-zappy-romain1.meunier
** File description:
** SettingSfml.hpp
*/

#include "General.hpp"

#ifndef SETTINGSFML_HPP
#define SETTINGSFML_HPP

class SettingSfml
{
private:
//------------Texture/Sprite------------//
    sf::Texture _settingBackground;
    sf::Sprite _setStettingBackground;
//---------------Font/Tex---------------//
    sf::Font _settngTextReturn;
    sf::Font _settingSongStop;
    sf::Text _settingReturn;
    sf::Text _songStop;
public:
//------------CONSTRUCTEUR-------------//
    SettingSfml(sf::RenderWindow & window, sf::Music & menu, int port);
//------------DESTRUCTEUR-------------//
    ~SettingSfml();
//--------------TITLE---------------//
    int _initSetting(sf::RenderWindow & window, sf::Music & menu, int port);
//---------------FUNC--------------//
    void _buttonStompMusic();
    void _buttonReturn();
};



#endif