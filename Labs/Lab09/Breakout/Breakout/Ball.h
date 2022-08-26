/**********************************************************************************
// Ball (Arquivo de Cabe�alho)
//
// Cria��o:     22 Dez 2012
// Atualiza��o: 18 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Bola do jogo Breakout
//
**********************************************************************************/

#ifndef _BREAKOUT_BALL_H_
#define _BREAKOUT_BALL_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Object.h" // interface de Object
#include "Player.h" // jogador do Breakout
#include "Sprite.h" // interface de Sprites
#include "Types.h"  // tipos espec�ficos da engine

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