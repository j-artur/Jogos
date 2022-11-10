/**********************************************************************************
// Debris (Código Fonte)
//
// Criação:     07 Fev 2013
// Atualização: 25 Out 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Animação de explosão
//
**********************************************************************************/

#include "Debris.h"
#include "Asteroids.h"

// ---------------------------------------------------------------------------------

Debris::Debris(float posX, float posY)
{
	Generator gen;
	gen.imgFile = "Resources/Particle.png";
	gen.angle = 0.f;
	gen.spread = 360.f;
	gen.lifetime = 1.5f;
	gen.frequency = 0.f;
	gen.percentToDim = 0.6f;
	gen.minSpeed = 40.f;
	gen.maxSpeed = 80.f;
	gen.color.r = 1.f;
	gen.color.g = 1.f;
	gen.color.b = 1.f;
	gen.color.a = 1.f;

	death = new Particles(gen);
	death->Generate(posX, posY, 30);
}

// ---------------------------------------------------------------------------------

Debris::~Debris()
{
    delete death;
}

// ---------------------------------------------------------------------------------

void Debris::Update()
{
	death->Update(gameTime);

    if (death->Inactive())
        Asteroids::scene->Delete();
}

// ---------------------------------------------------------------------------------