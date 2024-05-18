#include "../Header Files/Sidebar.h"

Sidebar::Sidebar() {

    mBackground = new Texture("stat_menu.png");
    mBackground->Position(Vector2(Graphics::Instance()->SCREEN_WIDTH * 0.5f, 45.0f));
}

Sidebar::~Sidebar() {

    delete mBackground;
    mBackground = NULL;
}

void Sidebar::Update() {


}

void Sidebar::Render() {

    mBackground->Render();
}