/**********************************************************************************
// Missile (Código Fonte)
// 
// Criação:     23 Nov 2011
// Atualização: 13 Out 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Define uma classe para um míssil/projétil
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

    // usa mesma rotação do avião
	RotateTo(90.0f - angle);

	Vector dir = Vector(plane->Angle(), 50.0f);
    
    // move para posição
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
    // desloca míssil pelas componentes do vetor speed
    Translate(speed.XComponent() * gameTime, -speed.YComponent() * gameTime);
    
    // se o míssil sair da janela
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
