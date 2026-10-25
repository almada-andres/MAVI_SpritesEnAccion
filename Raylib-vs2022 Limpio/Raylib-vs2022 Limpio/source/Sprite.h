#ifndef SPRITE_H
#define SPRITE_H

#include "raylib.h"

class Sprite
{
    private:
            Texture2D* textura;
            Vector2 posicion;
            Vector2 velocidad;
            float escala;
            float rotacion;
            Color color;

    public:
            Sprite(Texture2D* texturaCompartida,Vector2 posicionInicial,Vector2 velocidadInicial, float escalaInicial, Color colorInicial, float rotacionInicial);

            void Actualizar(float deltaTime);
            void Dibujar() const;

            void IntercambiarPropiedades(Sprite& otro);

            Vector2 ObtenerPosicion() const;
            float ObtenerEscala() const;
            Color ObtenerColor() const;
            float ObtenerRotacion() const;
};

#endif