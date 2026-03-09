
#include "Spaceship.h"
#include "Primitives.h"

static const float Z = -1.0f;
static const float Z_NEAR = Z + 0.005f;
static const float Z_FRONT = Z + 0.010f;

static const float SX = 0.0f;
static const float SY = -0.55f;

static void drawFuselage()
{
    // Shadow
    drawRect(SX - 0.075f, SY - 0.200f, SX + 0.075f, SY + 0.240f, Z,
        0.35f, 0.22f, 0.15f);
    // Main body – warm tan
    drawRect(SX - 0.068f, SY - 0.195f, SX + 0.068f, SY + 0.235f, Z_NEAR,
        0.78f, 0.58f, 0.42f);
    // Centre highlight stripe
    drawRect(SX - 0.018f, SY - 0.190f, SX + 0.018f, SY + 0.230f, Z_NEAR,
        0.88f, 0.72f, 0.58f);
    // Dark belly panel
    drawRect(SX - 0.060f, SY - 0.195f, SX + 0.060f, SY - 0.100f, Z_NEAR,
        0.55f, 0.38f, 0.26f);
    // Nose tip
    drawTriangle(SX - 0.040f, SY + 0.235f,
        SX + 0.040f, SY + 0.235f,
        SX, SY + 0.310f,
        Z_NEAR, 0.70f, 0.50f, 0.36f);
    // Nose highlight
    drawTriangle(SX - 0.012f, SY + 0.235f,
        SX + 0.012f, SY + 0.235f,
        SX, SY + 0.295f,
        Z_FRONT, 0.88f, 0.70f, 0.56f);
}

static void drawWings()
{
    // Left wing base
    drawTriangle(SX - 0.068f, SY + 0.060f,
        SX - 0.068f, SY - 0.080f,
        SX - 0.300f, SY - 0.130f,
        Z_NEAR, 0.55f, 0.38f, 0.26f);
    // Left wing highlight
    drawTriangle(SX - 0.068f, SY + 0.040f,
        SX - 0.068f, SY - 0.050f,
        SX - 0.240f, SY - 0.100f,
        Z_FRONT, 0.72f, 0.54f, 0.40f);
    // Left wingtip accent
    drawTriangle(SX - 0.200f, SY - 0.090f,
        SX - 0.260f, SY - 0.115f,
        SX - 0.300f, SY - 0.130f,
        Z_FRONT, 0.40f, 0.26f, 0.16f);

    // Right wing base
    drawTriangle(SX + 0.068f, SY + 0.060f,
        SX + 0.068f, SY - 0.080f,
        SX + 0.300f, SY - 0.130f,
        Z_NEAR, 0.55f, 0.38f, 0.26f);
    // Right wing highlight
    drawTriangle(SX + 0.068f, SY + 0.040f,
        SX + 0.068f, SY - 0.050f,
        SX + 0.240f, SY - 0.100f,
        Z_FRONT, 0.72f, 0.54f, 0.40f);
    // Right wingtip accent
    drawTriangle(SX + 0.200f, SY - 0.090f,
        SX + 0.260f, SY - 0.115f,
        SX + 0.300f, SY - 0.130f,
        Z_FRONT, 0.40f, 0.26f, 0.16f);
}

static void drawTailFins()
{
    drawTriangle(SX - 0.068f, SY - 0.120f,
        SX - 0.068f, SY - 0.190f,
        SX - 0.155f, SY - 0.195f,
        Z_NEAR, 0.50f, 0.34f, 0.22f);
    drawTriangle(SX + 0.068f, SY - 0.120f,
        SX + 0.068f, SY - 0.190f,
        SX + 0.155f, SY - 0.195f,
        Z_NEAR, 0.50f, 0.34f, 0.22f);
}

static void drawEnginePods()
{
    // Left pod
    drawRect(SX - 0.110f, SY - 0.210f, SX - 0.042f, SY - 0.145f, Z_NEAR,
        0.25f, 0.20f, 0.18f);
    drawRect(SX - 0.106f, SY - 0.206f, SX - 0.046f, SY - 0.185f, Z_FRONT,
        0.45f, 0.36f, 0.28f);
    // Right pod
    drawRect(SX + 0.042f, SY - 0.210f, SX + 0.110f, SY - 0.145f, Z_NEAR,
        0.25f, 0.20f, 0.18f);
    drawRect(SX + 0.046f, SY - 0.206f, SX + 0.106f, SY - 0.185f, Z_FRONT,
        0.45f, 0.36f, 0.28f);
}

static void drawEngineFlame(float cx, float baseY)
{
    // Outer – pale blue
    drawTriangle(cx - 0.028f, baseY, cx + 0.028f, baseY,
        cx, baseY - 0.110f,
        Z_NEAR, 0.40f, 0.70f, 1.00f);
    // Mid – bright cyan
    drawTriangle(cx - 0.016f, baseY, cx + 0.016f, baseY,
        cx, baseY - 0.085f,
        Z_FRONT, 0.70f, 0.90f, 1.00f);
    // Core – white
    drawTriangle(cx - 0.007f, baseY, cx + 0.007f, baseY,
        cx, baseY - 0.055f,
        Z_FRONT, 1.00f, 1.00f, 1.00f);
}

static void drawEngineFlames()
{
    drawEngineFlame(SX - 0.076f, SY - 0.210f);
    drawEngineFlame(SX + 0.076f, SY - 0.210f);
}

static void drawCockpit()
{
    // Frame shadow
    drawCircle(SX, SY + 0.100f, Z_NEAR, 0.052f,
        0.20f, 0.30f, 0.40f);
    // Glass – dark teal
    drawCircle(SX, SY + 0.105f, Z_FRONT, 0.044f,
        0.15f, 0.50f, 0.65f);
    // Highlight
    drawCircle(SX - 0.014f, SY + 0.118f, Z_FRONT, 0.018f,
        0.55f, 0.82f, 0.95f);
    // Glint
    drawCircle(SX - 0.008f, SY + 0.128f, Z_FRONT, 0.007f,
        0.90f, 0.97f, 1.00f);
}

static void drawHullPanels()
{
    // Mid seam
    drawRect(SX - 0.066f, SY + 0.010f, SX + 0.066f, SY + 0.016f, Z_FRONT,
        0.45f, 0.30f, 0.20f);
    // Upper seam
    drawRect(SX - 0.050f, SY + 0.150f, SX + 0.050f, SY + 0.155f, Z_FRONT,
        0.45f, 0.30f, 0.20f);
    // Left panel box
    drawRect(SX - 0.064f, SY + 0.022f, SX - 0.030f, SY + 0.070f, Z_FRONT,
        0.60f, 0.44f, 0.30f);
    // Right panel box
    drawRect(SX + 0.030f, SY + 0.022f, SX + 0.064f, SY + 0.070f, Z_FRONT,
        0.60f, 0.44f, 0.30f);
    // Weapon mount left
    drawRect(SX - 0.064f, SY + 0.080f, SX - 0.042f, SY + 0.110f, Z_FRONT,
        0.35f, 0.24f, 0.16f);
    // Weapon mount right
    drawRect(SX + 0.042f, SY + 0.080f, SX + 0.064f, SY + 0.110f, Z_FRONT,
        0.35f, 0.24f, 0.16f);
}

static void drawCannons()
{
    // Left barrel
    drawRect(SX - 0.160f, SY - 0.045f, SX - 0.148f, SY + 0.080f, Z_FRONT,
        0.22f, 0.18f, 0.14f);
    // Right barrel
    drawRect(SX + 0.148f, SY - 0.045f, SX + 0.160f, SY + 0.080f, Z_FRONT,
        0.22f, 0.18f, 0.14f);
}

static void drawBullets()
{
    float bx = SX;
    float positions[3] = { SY + 0.42f, SY + 0.65f, SY + 0.88f };

    for (int i = 0; i < 3; ++i)
    {
        float by = positions[i];
        // Outer orange glow
        drawTriangle(bx - 0.022f, by - 0.040f,
            bx + 0.022f, by - 0.040f,
            bx, by + 0.040f,
            Z_NEAR, 0.80f, 0.35f, 0.00f);
        // Mid orange
        drawTriangle(bx - 0.013f, by - 0.032f,
            bx + 0.013f, by - 0.032f,
            bx, by + 0.032f,
            Z_FRONT, 1.00f, 0.60f, 0.05f);
        // Hot white core
        drawTriangle(bx - 0.005f, by - 0.018f,
            bx + 0.005f, by - 0.018f,
            bx, by + 0.020f,
            Z_FRONT, 1.00f, 0.95f, 0.70f);
    }
}

void drawSpaceship()
{
    drawWings();
    drawTailFins();
    drawFuselage();
    drawEnginePods();
    drawEngineFlames();
    drawCockpit();
    drawHullPanels();
    drawCannons();
    drawBullets();
}