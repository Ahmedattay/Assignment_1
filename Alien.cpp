// ---------------------------------------------------------------
//  Alien.cpp  –  Alien enemy  (Object 2)
//  Depth: Z = -3 (middle layer)
//  Parts: body (rect), head (circle), 2 horns (triangles),
//         2 eyes (circles), mouth (rect)
// ---------------------------------------------------------------

#include "Alien.h"
#include "Primitives.h"

// Depth constant – middle layer
static const float Z = -3.0f;

// ---------------------------------------------------------------
//  Individual part functions
// ---------------------------------------------------------------

static void drawBody()
{
    drawRect(0.30f, 0.05f, 0.60f, 0.35f, Z,
             0.1f, 0.7f, 0.2f);                // green
}

static void drawHead()
{
    drawCircle(0.45f, 0.50f, Z, 0.14f,
               0.1f, 0.85f, 0.2f);             // bright green
}

static void drawLeftHorn()
{
    drawTriangle(0.34f, 0.55f,
                 0.38f, 0.60f,
                 0.28f, 0.72f,
                 Z,
                 0.8f, 0.2f, 0.8f);            // purple
}

static void drawRightHorn()
{
    drawTriangle(0.52f, 0.60f,
                 0.56f, 0.55f,
                 0.62f, 0.72f,
                 Z,
                 0.8f, 0.2f, 0.8f);            // purple
}

static void drawEyes()
{
    drawCircle(0.40f, 0.53f, Z, 0.030f,
               1.0f, 0.0f, 0.0f);              // left eye – red
    drawCircle(0.50f, 0.53f, Z, 0.030f,
               1.0f, 0.0f, 0.0f);              // right eye – red
}

static void drawMouth()
{
    drawRect(0.40f, 0.42f, 0.50f, 0.44f, Z,
             0.0f, 0.3f, 0.0f);                // dark green
}

// ---------------------------------------------------------------
//  Public: draw the entire alien
// ---------------------------------------------------------------
void drawAlien()
{
    drawBody();
    drawHead();
    drawLeftHorn();
    drawRightHorn();
    drawEyes();
    drawMouth();
}
