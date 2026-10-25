#include "Sprite.h"

Sprite::Sprite(Texture2D* texturaCompartida,Vector2 posicionInicial,Vector2 velocidadInicial, float escalaInicial, Color colorInicial, float rotacionInicial)
{
    textura = texturaCompartida;
    posicion = posicionInicial;
    velocidad = velocidadInicial;
    escala = escalaInicial;
    color = colorInicial;
    rotacion = rotacionInicial;
}

void Sprite::Actualizar(float deltaTime)
{
    if (textura == nullptr || textura->id == 0)
    {
        return;
    }

    posicion.x += velocidad.x * deltaTime;
    posicion.y += velocidad.y * deltaTime;

    float ancho = textura->width * escala;
    float alto = textura->height * escala;

    if (posicion.x <= 0.0f)
    {
        posicion.x = 0.0f;
        velocidad.x = -velocidad.x;
    }
    else if (posicion.x + ancho >= GetScreenWidth())
    {
        posicion.x = GetScreenWidth() - ancho;
        velocidad.x = -velocidad.x;
    }

    if (posicion.y <= 150.0f)
    {
        posicion.y = 150.0f;
        velocidad.y = -velocidad.y;
    }
    else if (posicion.y + alto >= GetScreenHeight())
    {
        posicion.y = GetScreenHeight() - alto;
        velocidad.y = -velocidad.y;
    }
}

void Sprite::Dibujar() const
{
    if (textura == nullptr || textura->id == 0)
        return;

    DrawTextureEx(*textura, posicion, rotacion, escala, color);
}

void Sprite::IntercambiarPropiedades(Sprite& otro)
{
    float escalaTemporal = escala;
    escala = otro.escala;
    otro.escala = escalaTemporal;

    Color colorTemporal = color;
    color = otro.color;
    otro.color = colorTemporal;

    float rotacionTemporal = rotacion;
    rotacion = otro.rotacion;
    otro.rotacion = rotacionTemporal;
}

Vector2 Sprite::ObtenerPosicion() const
{
    return posicion;
}

float Sprite::ObtenerEscala() const
{
    return escala;
}

Color Sprite::ObtenerColor() const
{
    return color;
}

float Sprite::ObtenerRotacion() const
{
    return rotacion;
}