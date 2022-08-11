/**********************************************************************************
// WinGame
//
// Criação:     19 Mai 2007
// Atualização: 04 Ago 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Um jogo para Windows é uma classe derivada de Game.
//              Crie uma classe derivada e sobrescreva os métodos Init,
//              Update, Draw e Finalize.
//
**********************************************************************************/

#include "Engine.h"
#include "Game.h"
#include "Resources.h"
#include <sstream>
using std::stringstream;

// ------------------------------------------------------------------------------

struct Point
{
    int x;
    int y;
};

class WinGame : public Game
{
  private:
    stringstream textSize;
    stringstream textMode;
    stringstream textMouse;
    Point p1 = {0, 0};
    Point p2 = {0, 0};
    Point p1Speed = {15, 13};
    Point p2Speed = {9, 11};

  public:
    void Init();
    void Update();
    void Draw();
    void Finalize();
};

// ------------------------------------------------------------------------------

void WinGame::Init()
{
    textSize << "Tamanho: " << window->Width() << " x " << window->Height();
    textMode << "Formato: " << (window->Mode() == WINDOWED ? "Em Janela" : "Tela Cheia");
}

// ------------------------------------------------------------------------------

void WinGame::Update()
{
    if (window->KeyDown(VK_ESCAPE))
        window->Close();

    textMouse.str("");
    textMouse << window->MouseX() << " x " << window->MouseY();

    if (p1.x < 0 || p1.x > window->Width())
    {
        p1Speed.x = -p1Speed.x;
    }
    if (p1.y < 0 || p1.y > window->Height())
    {
        p1Speed.y = -p1Speed.y;
    }

    if (p2.x < 0 || p2.x > window->Width())
    {
        p2Speed.x = -p2Speed.x;
    }
    if (p2.y < 0 || p2.y > window->Height())
    {
        p2Speed.y = -p2Speed.y;
    }

    p1.x += p1Speed.x;
    p1.y += p1Speed.y;
    p2.x += p2Speed.x;
    p2.y += p2Speed.y;
}

// ------------------------------------------------------------------------------

void WinGame::Draw()
{
    window->Print("Window Game Demo", 10, 10, RGB(0, 0, 0));
    window->Print(textSize.str(), 10, 50, RGB(0, 0, 0));
    window->Print(textMode.str(), 10, 70, RGB(0, 0, 0));
    window->Print(textMouse.str(), 10, 90, RGB(0, 0, 0));
    window->Line(p1.x, p1.y, p2.x, p2.y);
}

// ------------------------------------------------------------------------------

void WinGame::Finalize()
{
}

// ------------------------------------------------------------------------------
//                                  WinMain
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine,
                     _In_ int nCmdShow)
{
    // cria motor e configura a janela
    Engine *engine = new Engine();
    // engine->window->Mode(WINDOWED);
    // engine->window->Size(960, 540);
    engine->window->Color(240, 240, 140);
    engine->window->Title("Window Game");
    engine->window->Icon(IDI_ICON);
    engine->window->Cursor(IDC_CURSOR);

    // cria e inicia o jogo
    engine->Start(new WinGame());
}

// ----------------------------------------------------------------------------