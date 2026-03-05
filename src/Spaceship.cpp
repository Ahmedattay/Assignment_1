// ---------------------------------------------------------------
//  Spaceship.cpp  –  Player spaceship  (Object 1)
//  Depth: Z = -1 (front layer)
//  Parts: body (rect), nose (triangle), 2 wings (triangles),
//         cockpit (circle), 2 engine flames (triangles)
// ---------------------------------------------------------------

#include "Spaceship.h"
#include "Primitives.h"

// Depth constant – closest to camera
static const float Z = -1.0f;

// ---------------------------------------------------------------
//  Individual part functions
// ---------------------------------------------------------------

static void drawBody()
{
    drawRect(-0.55f, -0.65f, -0.35f, -0.35f, Z,
             0.6f, 0.6f, 0.7f);                // silver-grey
}

static void drawNoseCone()
{
    drawTriangle(-0.55f, -0.35f,
                 -0.35f, -0.35f,
                 -0.45f, -0.20f,
                 Z,
                 1.0f, 0.3f, 0.3f);            // red
}

static void drawLeftWing()
{
    drawTriangle(-0.55f, -0.55f,
                 -0.55f, -0.40f,
                 -0.72f, -0.60f,
                 Z,
                 0.2f, 0.4f, 0.9f);            // blue
}

static void drawRightWing()
{
    drawTriangle(-0.35f, -0.55f,
                 -0.35f, -0.40f,
                 -0.18f, -0.60f,
                 Z,
                 0.2f, 0.4f, 0.9f);            // blue
}

static void drawCockpit()
{
    drawCircle(-0.45f, -0.43f, Z, 0.045f,
               0.2f, 0.9f, 1.0f);              // cyan
}

static void drawEngineFlames()
{
    // Left flame
    drawTriangle(-0.52f, -0.65f,
                 -0.48f, -0.65f,
                 -0.50f, -0.75f,
                 Z,
                 1.0f, 0.6f, 0.0f);            // orange

    // Right flame
    drawTriangle(-0.42f, -0.65f,
                 -0.38f, -0.65f,
                 -0.40f, -0.73f,
                 Z,
                 1.0f, 0.6f, 0.0f);            // orange
}

// ---------------------------------------------------------------
//  Public: draw the entire spaceship
// ---------------------------------------------------------------
void drawSpaceship()
{
    drawBody();
    drawNoseCone();
    drawLeftWing();
    drawRightWing();
    drawCockpit();
    drawEngineFlames();
}
