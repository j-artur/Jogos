/**********************************************************************************
// Missile (C�digo Fonte)
// 
// Cria��o:     23 Nov 2011
// Atualiza��o: 13 Out 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Define uma classe para um m�ssil/proj�til
//
**********************************************************************************/

#include "Missile.h"
#include "Vector2D.h"

// ------------------------------------------------------------------------------

Missile::Missile(Plane * plane, float angle, Image * img)
{
    // inicializa sprite
    sprite = new Sprite(img);

    // inicializa vetor velocidade
    speed.RotateTo(angle);
    speed.ScaleTo(500);

    // usa mesma rota��o do avi�o
	RotateTo(90.0f - angle);

	Vector dir = Vector(plane->Angle(), 50.0f);
    
    // move para posi��o
    MoveTo(plane->X() + dir.XComponent() , plane->Y() - dir.YComponent());
}

// ------------------------------------------------------------------------------

Missile::~Missile()
{
    delete sprite;
}

// -------------------------------------------------------------------------------

void Missile::Update()
{
    // desloca m�ssil pelas componentes do vetor speed
    Translate(speed.XComponent() * gameTime, -speed.YComponent() * gameTime);
    
    // se o m�ssil sair da janela
    if (x > window->Width() || x < 0 || y > window->Height() || y < 0)
    {
        Vector2D::audio->Play(EXPLOSION);
        Vector2D::scene->Delete();
    }
}

// -------------------------------------------------------------------------------

void Missile::Draw()
{
    sprite->Draw(x, y, z, scale, rotation);
}

// -------------------------------------------------------------------------------
