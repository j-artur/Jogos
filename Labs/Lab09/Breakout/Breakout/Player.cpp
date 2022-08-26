/**********************************************************************************
// Player (Arquivo de Cabeçalho)
//
// Criação:     22 Dez 2012
// Atualização: 18 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Player do jogo Breakout
//
**********************************************************************************/

#include "Player.h"

// ---------------------------------------------------------------------------------

Player::Player()
{
    sprite = new Sprite("Resources/Player.png");
    started = false;
    speed = 400.0f;
}

Player::~Player()
{
    delete sprite;
}

void Player::Update()
{
    if (window->KeyDown(VK_LEFT))
        Translate(-speed * gameTime, 0.0f);
    if (window->KeyDown(VK_RIGHT))
        Translate(speed * gameTime, 0.0f);

    if (x < 0)
        MoveTo(0, y);
    if (x > window->Width() - sprite->Width())
        MoveTo(window->Width() - sprite->Width(), y);
}

// ---------------------------------------------------------------------------------
