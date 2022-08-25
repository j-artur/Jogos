/**********************************************************************************
// Frogger (Arquivo de Cabe�alho)
//
// Cria��o:     19 Dez 2012
// Atualiza��o: 14 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Define o objeto Sapo no jogo Frogger
//
**********************************************************************************/

#ifndef _FROGGER_FROGGER_H_
#define _FROGGER_FROGGER_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Object.h" // interface de object
#include "Sprite.h" // interface de sprites
#include "Types.h"  // tipos espec�ficos da engine

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