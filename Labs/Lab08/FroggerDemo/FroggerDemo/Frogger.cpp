/**********************************************************************************
// Frogger (Código Fonte)
//
// Criação:     19 Dez 2012
// Atualização: 14 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Define o objeto Sapo no jogo Frogger
//
**********************************************************************************/

#include "Frogger.h"

// ---------------------------------------------------------------------------------

Frogger::Frogger()
{
    spriteUp = new Sprite("Resources/frog_up.png");
    spriteDown = new Sprite("Resources/frog_down.png");
    spriteLeft = new Sprite("Resources/frog_left.png");
    spriteRight = new Sprite("Resources/frog_right.png");

    direction = UP;

    MoveTo(window->CenterX(), 560.0f, Layer::FRONT);

    ctrlUp = true;
    ctrlDown = true;
    ctrlLeft = true;
    ctrlRight = true;
}

// ---------------------------------------------------------------------------------

Frogger::~Frogger()
{
    delete spriteUp;
    delete spriteDown;
    delete spriteLeft;
    delete spriteRight;
}

// ---------------------------------------------------------------------------------

void Frogger::Update()
{
    // desloca sapo para cima
    if (ctrlUp && window->KeyDown(VK_UP))
    {
        Translate(0.0f, -40.0f);
        ctrlUp = false;
        direction = UP;
    }
    else if (window->KeyUp(VK_UP))
    {
        ctrlUp = true;
    }

    // desloca sapo para baixo
    if (ctrlDown && window->KeyDown(VK_DOWN))
    {
        Translate(0.0f, 40.0f);
        ctrlDown = false;
        direction = DOWN;
    }
    else if (window->KeyUp(VK_DOWN))
    {
        ctrlDown = true;
    }

    // desloca sapo para esquerda
    if (ctrlLeft && window->KeyDown(VK_LEFT))
    {
        Translate(-40.0f, 0.0f);
        ctrlLeft = false;
        direction = LEFT;
    }
    else if (window->KeyUp(VK_LEFT))
    {
        ctrlLeft = true;
    }

    // desloca sapo para direita
    if (ctrlRight && window->KeyDown(VK_RIGHT))
    {
        Translate(40.0f, 0.0f);
        ctrlRight = false;
        direction = RIGHT;
    }
    else if (window->KeyUp(VK_RIGHT))
    {
        ctrlRight = true;
    }

    // mantém sapo dentro da tela
    if (x < 20)
        MoveTo(20, y);
    if (x > 780)
        MoveTo(780, y);
    if (y < 80)
        MoveTo(x, 80);
    if (y > 560)
        MoveTo(x, 560);
}

// ---------------------------------------------------------------------------------

inline void Frogger::Draw()
{
    switch (direction)
    {
    case UP:
        spriteUp->Draw(x - spriteUp->Width() / 2.0f, y - spriteUp->Height() / 2.0f, z);
        break;
    case DOWN:
        spriteDown->Draw(x - spriteDown->Width() / 2.0f, y - spriteDown->Height() / 2.0f, z);
        break;
    case LEFT:
        spriteLeft->Draw(x - spriteLeft->Width() / 2.0f, y - spriteLeft->Height() / 2.0f, z);
        break;
    case RIGHT:
        spriteRight->Draw(x - spriteRight->Width() / 2.0f, y - spriteRight->Height() / 2.0f, z);
        break;
    }
}

// ---------------------------------------------------------------------------------
