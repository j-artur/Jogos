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

#ifndef _BREAKOUT_PLAYER_H_
#define _BREAKOUT_PLAYER_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Object.h" // interface de Object
#include "Sprite.h" // interface de Sprites
#include "Types.h"  // tipos específicos da engine

// ---------------------------------------------------------------------------------

class Player : public Object
{
  private:
    Sprite *sprite;
    bool started;
    float speed;

  public:
    Player();
    ~Player();

    void Update();
    void Draw();

    int Width();
    int Height();
};

// ---------------------------------------------------------------------------------

inline int Player::Width()
{
    return sprite->Width();
}

inline int Player::Height()
{
    return sprite->Height();
}

inline void Player::Draw()
{
    sprite->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------

#endif