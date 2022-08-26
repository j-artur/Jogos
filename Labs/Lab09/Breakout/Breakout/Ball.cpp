/**********************************************************************************
// Ball (Arquivo de Cabeçalho)
//
// Criação:     22 Dez 2012
// Atualização: 18 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Bola do jogo Breakout
//
**********************************************************************************/

#include "Ball.h"

// ---------------------------------------------------------------------------------

Ball::Ball(Player *player)
{
    this->player = player;
    sprite = new Sprite("Resources/Ball.png");
    started = false;
    xSpeed = 320.0f;
    ySpeed = -320.0f;
}

Ball::~Ball()
{
    delete sprite;
}

void Ball::Update()
{
    if (started)
        Translate(xSpeed * gameTime, ySpeed * gameTime);
    else if (window->KeyDown(VK_SPACE))
        started = true;
    else
        MoveTo(player->x + player->Width() / 2 - sprite->Width() / 2, player->y - sprite->Height());

    if (x < 0)
    {
        MoveTo(0, y);
        BounceHorizontal();
    }
    if (x > window->Width() - sprite->Width())
    {
        MoveTo(window->Width() - sprite->Width(), y);
        BounceHorizontal();
    }
    if (y < 0)
    {
        MoveTo(x, 0);
        BounceVertical();
    }
    if (y > window->Height() - sprite->Height())
    {
        MoveTo(x, window->Height() - sprite->Height());
        BounceVertical();
    }
}

// ---------------------------------------------------------------------------------
