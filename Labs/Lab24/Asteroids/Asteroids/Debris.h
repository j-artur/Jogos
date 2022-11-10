/**********************************************************************************
// Debris (Arquivo de Cabeçalho)
// 
// Criação:     07 Fev 2013
// Atualização: 25 Out 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Animação de explosão
//
**********************************************************************************/

#ifndef _ASTEROIDS_DEBRIS_H_
#define _ASTEROIDS_DEBRIS_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"                          // tipos específicos da engine
#include "Object.h"                         // objetos do jogo
#include "Animation.h"                      // animação de sprites
#include "Particles.h"

// ---------------------------------------------------------------------------------

class Debris : public Object
{
private:
	Particles* death;

public:
    Debris(float posX, float posY);         // construtor
    ~Debris();                              // destrutor

    void Update();                          // atualização
    void Draw();                            // desenho
};

// ---------------------------------------------------------------------------------
// Função Membro Inline

inline void Debris::Draw()
{ death->Draw(Layer::UPPER); }

// ---------------------------------------------------------------------------------

#endif