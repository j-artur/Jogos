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

#ifndef _BREAKOUT_BALL_H_
#define _BREAKOUT_BALL_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Object.h" // interface de Object
#include "Player.h" // jogador do Breakout
#include "Sprite.h" // interface de Sprites
#include "Types.h"  // tipos específicos da engine

// ---------------------------------------------------------------------------------

class Ball : public Object
{
  private:
    Sprite *sprite;
    Player *player;
    bool started;
    float xSpeed;
    float ySpeed;

  public:
    Ball(Player *player);
    ~Ball();

    void Update();
    void Draw();

    void BounceVertical();
    void BounceHorizontal();

    int Width();
    int Height();
};

// ---------------------------------------------------------------------------------

inline int Ball::Width()
{
    return sprite->Width();
}

inline int Ball::Height()
{
    return sprite->Height();
}

inline void Ball::Draw()
{
    sprite->Draw(x, y, z);
}

inline void Ball::BounceHorizontal()
{
    xSpeed = -xSpeed;
}

inline void Ball::BounceVertical()
{
    ySpeed = -ySpeed;
}

// ---------------------------------------------------------------------------------

#endif