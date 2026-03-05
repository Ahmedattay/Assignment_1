// ---------------------------------------------------------------
//  Background.cpp  –  Planet + Stars  (Object 3)
//  Depth: Z = -5 (far layer)
//  Parts: space-sky (rect), planet (circle), ring (ellipse line
//         loop), 18 stars (small circles)
// ---------------------------------------------------------------

#include "Background.h"
#include "Primitives.h"

// Depth constant – farthest from camera
static const float Z = -5.0f;

// ---------------------------------------------------------------
//  Star positions (18 stars scattered across the sky)
// ---------------------------------------------------------------
static const float STARS[][2] = {
    {-0.80f,  0.80f}, {-0.60f,  0.50f}, {-0.30f,  0.90f},
    { 0.10f,  0.70f}, { 0.40f,  0.85f}, { 0.70f,  0.60f},
    { 0.85f,  0.90f}, {-0.90f,  0.20f}, {-0.70f, -0.30f},
    { 0.00f,  0.30f}, { 0.80f,  0.10f}, {-0.20f, -0.70f},
    { 0.20f, -0.60f}, {-0.50f, -0.50f}, { 0.90f, -0.80f},
    {-0.85f, -0.85f}, { 0.60f, -0.20f}, {-0.15f,  0.55f}
};
static const int STAR_COUNT = 18;

// ---------------------------------------------------------------
//  Individual part functions
// ---------------------------------------------------------------

static void drawSpaceSky()
{
    drawRect(-1.0f, -1.0f, 1.0f, 1.0f, Z - 0.5f,
             0.02f, 0.0f, 0.08f);              // very dark purple
}

static void drawPlanet()
{
    drawCircle(0.55f, -0.45f, Z, 0.30f,
               0.2f, 0.3f, 0.7f);              // dark blue planet
}

static void drawPlanetRing()
{
    drawEllipseRing(0.55f, -0.45f, Z,
                    0.42f, 0.10f,
                    0.8f, 0.8f, 0.3f,          // yellow ring
                    2.0f, 60);
}

static void drawStars()
{
    for (int i = 0; i < STAR_COUNT; ++i) {
        float brightness = 0.6f + 0.4f * ((i * 7 + 3) % 10) / 10.0f;
        float size        = 0.012f + 0.006f * (i % 3);
        drawCircle(STARS[i][0], STARS[i][1], Z,
                   size,
                   brightness, brightness, brightness * 0.9f);
    }
}

// ---------------------------------------------------------------
//  Public: draw the entire background
// ---------------------------------------------------------------
void drawBackground()
{
    drawSpaceSky();
    drawPlanet();
    drawPlanetRing();
    drawStars();
}
