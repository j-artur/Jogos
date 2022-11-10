/**********************************************************************************
// Fireworks (Código Fonte)
// 
// Criação:     17 Mar 2013
// Atualização: 27 Out 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Efeito de explosão usando sistema de partículas
//
**********************************************************************************/

#include "Refinery.h"
#include "Fireworks.h"

// ---------------------------------------------------------------------------------

Fireworks::Fireworks()
{
    // configura gerador de partículas
    Generator o;
	o.imgFile = "Resources/Star.png";   // arquivo de imagem
	o.angle = 0.f;            // direção das estrelas
	o.spread = 30.0f;                  // espalhamento em graus
	o.lifetime = 1.5f;                  // tempo de vida (em segundos)
	o.frequency = 0.000f;               // tempo entre geração de novas partículas
	o.percentToDim = 0.f;              // desaparece após 60% da vida
	o.minSpeed = 100.0f;                 // velocidade mínima das partículas
	o.maxSpeed = 600.0f;                // velocidade máxima das partículas
	o.color.r = 1.f;          // cor aleatória para partícula
	o.color.g = 0.5f;          // cor aleatória para partícula
	o.color.b = 0.f;          // cor aleatória para partícula
	o.color.a = 1.0f;                   // transparência da partícula

	// configura gerador de partículas
	Generator y;
	y.imgFile = "Resources/Star.png";   // arquivo de imagem
	y.angle = 0.f;            // direção das estrelas
	y.spread = 20.0f;                  // espalhamento em graus
	y.lifetime = 1.5f;                  // tempo de vida (em segundos)
	y.frequency = 0.000f;               // tempo entre geração de novas partículas
	y.percentToDim = 0.f;              // desaparece após 60% da vida
	y.minSpeed = 50.0f;                 // velocidade mínima das partículas
	y.maxSpeed = 400.0f;                // velocidade máxima das partículas
	y.color.r = 1.f;          // cor aleatória para partícula
	y.color.g = 1.f;          // cor aleatória para partícula
	y.color.b = 0.f;          // cor aleatória para partícula
	y.color.a = 1.0f;                   // transparência da partícula

    // cria sistema de partículas
	orange = new Particles(o);
	yellow = new Particles(y);

    // gera 50 partículas na posição do mouse
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
    // atualiza posição de cada partícula
	orange->Update(gameTime);
	yellow->Update(gameTime);

    // remove da cena quando todas as partículas estão inativas
    if (orange->Inactive() || yellow->Inactive())
        Refinery::scene->Delete();
}

// -------------------------------------------------------------------------------

void Fireworks::Draw()
{
	orange->Draw(Layer::MIDDLE, 0.0f);
	yellow->Draw(Layer::UPPER, 0.0f);
}