/**********************************************************************************
// FontDemo
// 
// Criação:     07 Out 2011
// Atualização: 08 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Testa a classe Font com exibição de texto com diversas fontes.
//
**********************************************************************************/

#include "Engine.h"
#include "Game.h"
#include "Font.h"
#include "Sprite.h"
#include "Resources.h"

// ------------------------------------------------------------------------------

class FontDemo : public Game
{
private:
    Sprite * backg    = nullptr;
    Font   * consolas = nullptr;
    Font   * courier  = nullptr;
    Font   * verdana  = nullptr;
	Font  * jetBrains = nullptr;
    
public:
    void Init();
    void Update();
    void Draw();
    void Finalize();
};

// ------------------------------------------------------------------------------

void FontDemo::Init()
{
    // background
    backg = new Sprite("Resources/paper.png");

    // cria fontes
    consolas = new Font("Resources/consolas12.png");
    consolas->Spacing("Resources/consolas12.dat");
    //consolas->Spacing(12);

    courier = new Font("Resources/courier12.png");
    courier->Spacing("Resources/courier12.dat");
    //courier->Spacing(12);

	verdana = new Font("Resources/verdana12.png");
	verdana->Spacing("Resources/verdana12.dat");
	//verdana->Spacing(12);

	jetBrains = new Font("Resources/jetbrains.png");
	jetBrains->Spacing("Resources/jetbrains.dat");
}

// ------------------------------------------------------------------------------

void FontDemo::Update()
{
    // sai com pressionamento do ESC
    if (window->KeyDown(VK_ESCAPE))
        window->Close();
} 

// ------------------------------------------------------------------------------

void FontDemo::Draw()
{
    // desenha background
    backg->Draw(window->CenterX(), window->CenterY());

	Color black (0.0f, 0.0f, 0.0f, 1.0f);
    Color blue  (0.2f, 0.2f, 1.0f, 1.0f);
    Color red   (1.0f, 0.2f, 0.2f, 1.0f);
    Color green (0.1f, 0.6f, 0.1f, 1.0f);

	jetBrains->Draw(60, 40, "JetBrains Mono", black, Layer::FRONT, 1.5f);
	
	jetBrains->Draw(200, 240, "JetBrains Mono", red, Layer::FRONT, 0.5f, -30.0f);
	jetBrains->Draw(300, 260, "JetBrains Mono", blue, Layer::FRONT, 0.75f, 45.0f);
	jetBrains->Draw(60, 440, "JetBrains Mono", green, Layer::FRONT, 1.0f, -90.0f);
} 

// ------------------------------------------------------------------------------

void FontDemo::Finalize()
{
    delete backg;
    delete consolas;
    delete courier;
    delete verdana;
}

// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, 
                     _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    Engine * engine = new Engine();

    // configura motor
    engine->window->Mode(WINDOWED);
    engine->window->Size(600, 474);
    engine->window->Color(240, 240, 120);
    engine->window->Title("Font Demo");
    engine->window->Icon(IDI_ICON);
    //engine->window->Cursor(IDC_CURSOR);
    //engine->graphics->VSync(true);

    // inicia o jogo
    int status = engine->Start(new FontDemo());

    delete engine;
    return status;
}

// ----------------------------------------------------------------------------

