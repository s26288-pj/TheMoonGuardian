#ifndef _SIDEBAR_H
#define _SIDEBAR_H

#include "Texture.h"

class Sidebar {

private:

    Texture* mBackground;

public:

    Sidebar();
    ~Sidebar();

    void Update();
    void Render();
};

#endif
