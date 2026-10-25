#include "EscenaSprites.h"

EscenaSprites::EscenaSprites()
{
    textura = { 0 };
    spriteA = nullptr;
    spriteB = nullptr;

    textura = LoadTexture("Assets/WaterBall.png");

    SetTextureFilter(textura, TEXTURE_FILTER_BILINEAR);

    spriteA = new Sprite(&textura,{ 100.0f, 260.0f },{ 150.0f, 100.0f },0.15f,WHITE,0.0f);

    spriteB = new Sprite(&textura,{ 650.0f, 300.0f },{ -120.0f, 80.0f },0.22f,{ 100, 190, 255, 255 },250.0f);
}

EscenaSprites::~EscenaSprites()
{
    delete spriteA;
    delete spriteB;

    if (textura.id != 0)
    {
        UnloadTexture(textura);
    }
}

void EscenaSprites::Actualizar(float deltaTime)
{
    if (spriteA == nullptr || spriteB == nullptr)
    {
        return;
    }

    spriteA->Actualizar(deltaTime);
    spriteB->Actualizar(deltaTime);

    if (IsKeyPressed(KEY_SPACE))
    {
        spriteA->IntercambiarPropiedades(*spriteB);
    }
}

void EscenaSprites::DibujarInformacion(const char* nombre, const Sprite& sprite, int x, int y) const
{
    Vector2 posicion = sprite.ObtenerPosicion();
    float escala = sprite.ObtenerEscala();
    Color color = sprite.ObtenerColor();

    DrawText(nombre, x, y, 22, WHITE);

    DrawText(TextFormat("Posicion: X = %.1f | Y = %.1f",posicion.x, posicion.y),x, y + 30, 18, RAYWHITE);

    DrawText(TextFormat("Escala: %.2f", escala),x, y + 55, 18, RAYWHITE);

    DrawText(TextFormat("Color RGBA: %d, %d, %d, %d",(int)color.r, (int)color.g,(int)color.b, (int)color.a),x, y + 80, 18, RAYWHITE);

    DrawText(TextFormat("Rotacion: %.1f grados", sprite.ObtenerRotacion()),x, y + 105, 18, RAYWHITE);
}

void EscenaSprites::Dibujar() const
{
    ClearBackground({ 35, 35, 65, 255 });

    DrawText("Presione ESPACIO para intercambiar escala y color",20, 55, 18, YELLOW);

    DibujarInformacion("SPRITE A", *spriteA, 20, 100);
    DibujarInformacion("SPRITE B", *spriteB, 520, 100);

    spriteA->Dibujar();
    spriteB->Dibujar();
}