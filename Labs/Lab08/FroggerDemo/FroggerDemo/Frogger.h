/**********************************************************************************
// Frogger (Arquivo de Cabeçalho)
//
// Criação:     19 Dez 2012
// Atualização: 14 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Define o objeto Sapo no jogo Frogger
//
**********************************************************************************/

#ifndef _FROGGER_FROGGER_H_
#define _FROGGER_FROGGER_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Object.h" // interface de object
#include "Sprite.h" // interface de sprites
#include "Types.h"  // tipos específicos da engine

// ---------------------------------------------------------------------------------

enum Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Frogger : public Object
{
  private:
    Sprite *spriteUp;
    Sprite *spriteDown;
    Sprite *spriteLeft;
    Sprite *spriteRight;
    Direction direction;
    bool ctrlUp;
    bool ctrlDown;
    bool ctrlLeft;
    bool ctrlRight;

  public:
    Frogger();
    ~Frogger();

    void Update();
    void Draw();
};

// ---------------------------------------------------------------------------------

#endif