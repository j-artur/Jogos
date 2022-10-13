/**********************************************************************************
// Missile (Código Fonte)
// 
// Criação:     23 Nov 2011
// Atualização: 18 Out 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Define uma classe para um míssil/projétil
//
**********************************************************************************/

#include "Missile.h"
#include "Inertia.h"
#include "Explosion.h"
#include "Ship.h"

// ------------------------------------------------------------------------------

Missile::Missile(Ship * ship)
{
    // cria sprite
    sprite = new Sprite("Resources/Missile.png");

    // bounding box
    BBox(new Point());

    // inicializa velocidade
    speed.RotateTo(ship->direction.Angle());
    speed.ScaleTo(10.0f);
    
    // posição inicial do míssil
    MoveTo(ship->X() + 20 * cos(speed.Radians()), ship->Y() - 20 * sin(speed.Radians()));

    // rotação do míssil
    RotateTo(ship->Rotation());
}

// ------------------------------------------------------------------------------

Missile::~Missile()
{
    delete sprite;
}

// -------------------------------------------------------------------------------

void Missile::Update()
{
    // deslocamento padrão
    float deltaT = 50 * gameTime;

    // move míssel usando o vetor
    Translate(speed.XComponent() * deltaT, -speed.YComponent() * deltaT);
    
    // destrói míssil que saí da tela
	if (X() > window->Width() || X() < 0 || Y() > window->Height() || Y() < 0)
	{
		if (rebound)
		{
			Inertia::audio->Play(EXPLOSION);
			Explosion* explo = new Explosion(Inertia::exploSet);
			explo->MoveTo(x, y);
			Inertia::scene->Add(explo, STATIC);
			Inertia::scene->Delete();
		}
		else
		{
			auto normal = Vector(0.0f, 2.0f * speed.Magnitude());
			if (X() > window->Width())
				normal.RotateTo(180.0f);
			else if (X() < 0)
				normal.RotateTo(0.0f);
			else if (Y() > window->Height())
				normal.RotateTo(90.0f);
			else if (Y() < 0)
				normal.RotateTo(270.0f);

			speed.Add(normal);
			Translate(speed.XComponent() * deltaT, -speed.YComponent() * deltaT);

			rebound = true;
		}
	}
}

// -------------------------------------------------------------------------------

void Missile::Draw()
{
    sprite->Draw(x, y, z, scale, rotation);
}

// -------------------------------------------------------------------------------
