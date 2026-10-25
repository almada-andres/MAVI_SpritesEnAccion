#ifndef ESCENA_SPRITES_H
#define ESCENA_SPRITES_H

#include "raylib.h"
#include "Sprite.h"

class EscenaSprites
{
    private:
            Texture2D textura;
            Sprite* spriteA;
            Sprite* spriteB;

            void DibujarInformacion(const char* nombre,const Sprite& sprite, int x, int y) const;

    public:
            EscenaSprites();
            ~EscenaSprites();

            void Actualizar(float deltaTime);
            void Dibujar() const;
};

#endif