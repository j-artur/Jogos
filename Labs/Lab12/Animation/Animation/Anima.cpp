/**********************************************************************************
// Animation
//
// Criação:     10 Abr 2012
// Atualização: 27 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Exemplo de uso da classe Animation
//
**********************************************************************************/

#include "Animation.h"
#include "Engine.h"
#include "Game.h"
#include "Object.h"
#include "Resources.h"
#include "Sprite.h"
#include "TileSet.h"

// ------------------------------------------------------------------------------

class Pikachu : public Object
{
  private:
    TileSet *tileset = nullptr;
    Animation *anim = nullptr;

  public:
    Pikachu(float animDelay)
    {
        tileset = new TileSet("Resources/pikachu.png", 220, 188, 5, 17);
        anim = new Animation(tileset, animDelay, true);
    }

    ~Pikachu()
    {
        delete anim;
        delete tileset;
    }

    void Update()
    {
        anim->NextFrame();
    }

    void Draw()
    {
        anim->Draw(x, y);
    }
};

// -----------------------------------------------------------------------------

class Anima : public Game
{
  private:
    Sprite *sprite = nullptr;   // sprite de fundo
    Pikachu *pikachu = nullptr; // objeto pikachu

  public:
    void Init();     // inicializa jogo
    void Update();   // atualiza lógica do jogo
    void Draw();     // desenha jogo
    void Finalize(); // finaliza jogo
};

// -----------------------------------------------------------------------------

void Anima::Init()
{
    sprite = new Sprite("Resources/background.png");
    pikachu = new Pikachu(0.120f);
    pikachu->MoveTo(window->CenterX() + 130.0f, window->CenterY() + 40.0f);
}

// ------------------------------------------------------------------------------

void Anima::Update()
{
    // sai com o pressionamento do ESC
    if (window->KeyDown(VK_ESCAPE))
        window->Close();

    // atualiza pikachu
    pikachu->Update();
}

// ------------------------------------------------------------------------------

void Anima::Draw()
{
    sprite->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
    pikachu->Draw();
}

// ------------------------------------------------------------------------------

void Anima::Finalize()
{
    delete sprite;
    delete pikachu;
}

// ------------------------------------------------------------------------------
//                                  WinMain
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine,
                     _In_ int nCmdShow)
{
    Engine *engine = new Engine();

    // configura janela
    engine->window->Mode(WINDOWED);
    engine->window->Size(960, 540);
    engine->window->Color(0, 0, 0);
    engine->window->Title("Animation");
    engine->window->Icon(IDI_ICON);

    // configura dispositivo gráfico
    // engine->graphics->VSync(true);

    // inicia o jogo
    int status = engine->Start(new Anima());

    delete engine;
    return status;
}

// ----------------------------------------------------------------------------
