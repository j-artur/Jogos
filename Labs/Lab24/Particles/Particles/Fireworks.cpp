/**********************************************************************************
// Fireworks (C�digo Fonte)
// 
// Cria��o:     17 Mar 2013
// Atualiza��o: 27 Out 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Efeito de explos�o usando sistema de part�culas
//
**********************************************************************************/

#include "Refinery.h"
#include "Fireworks.h"

// ---------------------------------------------------------------------------------

Fireworks::Fireworks()
{
    // configura gerador de part�culas
    Generator o;
	o.imgFile = "Resources/Star.png";   // arquivo de imagem
	o.angle = 0.f;            // dire��o das estrelas
	o.spread = 30.0f;                  // espalhamento em graus
	o.lifetime = 1.5f;                  // tempo de vida (em segundos)
	o.frequency = 0.000f;               // tempo entre gera��o de novas part�culas
	o.percentToDim = 0.f;              // desaparece ap�s 60% da vida
	o.minSpeed = 100.0f;                 // velocidade m�nima das part�culas
	o.maxSpeed = 600.0f;                // velocidade m�xima das part�culas
	o.color.r = 1.f;          // cor aleat�ria para part�cula
	o.color.g = 0.5f;          // cor aleat�ria para part�cula
	o.color.b = 0.f;          // cor aleat�ria para part�cula
	o.color.a = 1.0f;                   // transpar�ncia da part�cula

	// configura gerador de part�culas
	Generator y;
	y.imgFile = "Resources/Star.png";   // arquivo de imagem
	y.angle = 0.f;            // dire��o das estrelas
	y.spread = 20.0f;                  // espalhamento em graus
	y.lifetime = 1.5f;                  // tempo de vida (em segundos)
	y.frequency = 0.000f;               // tempo entre gera��o de novas part�culas
	y.percentToDim = 0.f;              // desaparece ap�s 60% da vida
	y.minSpeed = 50.0f;                 // velocidade m�nima das part�culas
	y.maxSpeed = 400.0f;                // velocidade m�xima das part�culas
	y.color.r = 1.f;          // cor aleat�ria para part�cula
	y.color.g = 1.f;          // cor aleat�ria para part�cula
	y.color.b = 0.f;          // cor aleat�ria para part�cula
	y.color.a = 1.0f;                   // transpar�ncia da part�cula

    // cria sistema de part�culas
	orange = new Particles(o);
	yellow = new Particles(y);

    // gera 50 part�culas na posi��o do mouse
	orange->Generate(window->MouseX(), window->MouseY(), 200);
	yellow->Generate(window->MouseX(), window->MouseY(), 200);
    type = FIREWORKS;
}

// ---------------------------------------------------------------------------------

Fireworks::~Fireworks()
{
	delete orange;
	delete yellow;
}

// -------------------------------------------------------------------------------

void Fireworks::Update()
{
    // atualiza posi��o de cada part�cula
	orange->Update(gameTime);
	yellow->Update(gameTime);

    // remove da cena quando todas as part�culas est�o inativas
    if (orange->Inactive() || yellow->Inactive())
        Refinery::scene->Delete();
}

// -------------------------------------------------------------------------------

void Fireworks::Draw()
{
	orange->Draw(Layer::MIDDLE, 0.0f);
	yellow->Draw(Layer::UPPER, 0.0f);
}