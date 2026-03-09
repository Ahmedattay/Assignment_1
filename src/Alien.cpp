

#include "Alien.h"
#include "Primitives.h"

static const float Z = -3.0f;
static const float Z_NEAR = Z + 0.005f;
static const float Z_FRONT = Z + 0.010f;

// Enemy centered around (0.25, 0.35) pointing DOWN
static const float EX = 0.25f;
static const float EY = 0.35f;

// ---------------------------------------------------------------
//  MAIN HULL  –  angular red body pointing downward
// ---------------------------------------------------------------
static void drawHull()
{
    // Shadow base
    drawRect(EX - 0.090f, EY - 0.240f, EX + 0.090f, EY + 0.190f, Z,
        0.25f, 0.04f, 0.04f);

    // Main hull – dark crimson
    drawRect(EX - 0.082f, EY - 0.232f, EX + 0.082f, EY + 0.182f, Z_NEAR,
        0.65f, 0.10f, 0.10f);

    // Centre stripe – brighter red
    drawRect(EX - 0.022f, EY - 0.225f, EX + 0.022f, EY + 0.175f, Z_NEAR,
        0.85f, 0.18f, 0.12f);

    // Upper hull highlight
    drawRect(EX - 0.060f, EY + 0.080f, EX + 0.060f, EY + 0.182f, Z_NEAR,
        0.72f, 0.14f, 0.10f);

    // Forward nose (pointing DOWN = negative Y)
    drawTriangle(EX - 0.048f, EY - 0.232f,
        EX + 0.048f, EY - 0.232f,
        EX, EY - 0.310f,
        Z_NEAR, 0.60f, 0.08f, 0.08f);

    // Nose highlight stripe
    drawTriangle(EX - 0.014f, EY - 0.232f,
        EX + 0.014f, EY - 0.232f,
        EX, EY - 0.290f,
        Z_FRONT, 0.85f, 0.25f, 0.18f);
}

// ---------------------------------------------------------------
//  SWEPT WINGS  –  wide angular red wings
// ---------------------------------------------------------------
static void drawWings()
{
    // Left wing base – dark red
    drawTriangle(EX - 0.082f, EY - 0.060f,
        EX - 0.082f, EY + 0.120f,
        EX - 0.320f, EY + 0.050f,
        Z_NEAR, 0.50f, 0.07f, 0.07f);

    // Left wing surface – brighter
    drawTriangle(EX - 0.082f, EY - 0.030f,
        EX - 0.082f, EY + 0.090f,
        EX - 0.260f, EY + 0.040f,
        Z_FRONT, 0.68f, 0.12f, 0.10f);

    // Left wing edge accent
    drawTriangle(EX - 0.220f, EY + 0.050f,
        EX - 0.280f, EY + 0.045f,
        EX - 0.320f, EY + 0.050f,
        Z_FRONT, 0.30f, 0.04f, 0.04f);

    // Right wing base
    drawTriangle(EX + 0.082f, EY - 0.060f,
        EX + 0.082f, EY + 0.120f,
        EX + 0.320f, EY + 0.050f,
        Z_NEAR, 0.50f, 0.07f, 0.07f);

    // Right wing surface
    drawTriangle(EX + 0.082f, EY - 0.030f,
        EX + 0.082f, EY + 0.090f,
        EX + 0.260f, EY + 0.040f,
        Z_FRONT, 0.68f, 0.12f, 0.10f);

    // Right wing edge accent
    drawTriangle(EX + 0.220f, EY + 0.050f,
        EX + 0.280f, EY + 0.045f,
        EX + 0.320f, EY + 0.050f,
        Z_FRONT, 0.30f, 0.04f, 0.04f);
}

// ---------------------------------------------------------------
//  REAR THRUSTERS  –  engine pods at TOP (rear, since facing down)
// ---------------------------------------------------------------
static void drawThrusters()
{
    // Left thruster pod
    drawRect(EX - 0.120f, EY + 0.160f, EX - 0.048f, EY + 0.220f, Z_NEAR,
        0.22f, 0.06f, 0.06f);
    drawRect(EX - 0.116f, EY + 0.160f, EX - 0.052f, EY + 0.182f, Z_FRONT,
        0.40f, 0.10f, 0.08f);

    // Right thruster pod
    drawRect(EX + 0.048f, EY + 0.160f, EX + 0.120f, EY + 0.220f, Z_NEAR,
        0.22f, 0.06f, 0.06f);
    drawRect(EX + 0.052f, EY + 0.160f, EX + 0.116f, EY + 0.182f, Z_FRONT,
        0.40f, 0.10f, 0.08f);
}

// ---------------------------------------------------------------
//  ENGINE GLOW  –  orange/red glowing exhaust rings
// ---------------------------------------------------------------
static void drawEngineGlow()
{
    // Left engine glow
    drawCircle(EX - 0.084f, EY + 0.222f, Z_FRONT, 0.030f,
        1.00f, 0.45f, 0.00f);
    drawCircle(EX - 0.084f, EY + 0.222f, Z_FRONT, 0.016f,
        1.00f, 0.80f, 0.20f);
    drawEllipseRing(EX - 0.084f, EY + 0.222f, Z_FRONT,
        0.034f, 0.012f,
        1.00f, 0.55f, 0.05f, 2.0f, 32);

    // Right engine glow
    drawCircle(EX + 0.084f, EY + 0.222f, Z_FRONT, 0.030f,
        1.00f, 0.45f, 0.00f);
    drawCircle(EX + 0.084f, EY + 0.222f, Z_FRONT, 0.016f,
        1.00f, 0.80f, 0.20f);
    drawEllipseRing(EX + 0.084f, EY + 0.222f, Z_FRONT,
        0.034f, 0.012f,
        1.00f, 0.55f, 0.05f, 2.0f, 32);
}

// ---------------------------------------------------------------
//  COCKPIT  –  dark angular canopy
// ---------------------------------------------------------------
static void drawCockpit()
{
    // Frame
    drawCircle(EX, EY + 0.020f, Z_NEAR, 0.058f,
        0.18f, 0.03f, 0.03f);
    // Dark glass
    drawCircle(EX, EY + 0.025f, Z_FRONT, 0.048f,
        0.12f, 0.08f, 0.14f);
    // Glint
    drawCircle(EX - 0.015f, EY + 0.038f, Z_FRONT, 0.016f,
        0.35f, 0.20f, 0.40f);
    // Small red accent
    drawCircle(EX, EY + 0.008f, Z_FRONT, 0.012f,
        0.80f, 0.15f, 0.10f);
}

// ---------------------------------------------------------------
//  HULL PANELS  –  mechanical detail lines
// ---------------------------------------------------------------
static void drawHullPanels()
{
    // Horizontal seam
    drawRect(EX - 0.080f, EY - 0.010f, EX + 0.080f, EY - 0.004f, Z_FRONT,
        0.35f, 0.05f, 0.05f);

    // Upper seam
    drawRect(EX - 0.060f, EY + 0.120f, EX + 0.060f, EY + 0.126f, Z_FRONT,
        0.35f, 0.05f, 0.05f);

    // Left panel
    drawRect(EX - 0.078f, EY - 0.005f, EX - 0.034f, EY - 0.055f, Z_FRONT,
        0.55f, 0.08f, 0.08f);

    // Right panel
    drawRect(EX + 0.034f, EY - 0.005f, EX + 0.078f, EY - 0.055f, Z_FRONT,
        0.55f, 0.08f, 0.08f);

    // Vertical spine
    drawRect(EX - 0.008f, EY - 0.230f, EX + 0.008f, EY + 0.180f, Z_FRONT,
        0.40f, 0.06f, 0.06f);
}

// ---------------------------------------------------------------
//  WING GUNS  –  mounted weapon barrels
// ---------------------------------------------------------------
static void drawWingGuns()
{
    // Left barrel
    drawRect(EX - 0.175f, EY - 0.080f, EX - 0.163f, EY + 0.060f, Z_FRONT,
        0.20f, 0.04f, 0.04f);
    // Left muzzle tip
    drawCircle(EX - 0.169f, EY - 0.085f, Z_FRONT, 0.010f,
        0.70f, 0.20f, 0.10f);

    // Right barrel
    drawRect(EX + 0.163f, EY - 0.080f, EX + 0.175f, EY + 0.060f, Z_FRONT,
        0.20f, 0.04f, 0.04f);
    // Right muzzle tip
    drawCircle(EX + 0.169f, EY - 0.085f, Z_FRONT, 0.010f,
        0.70f, 0.20f, 0.10f);
}

// ---------------------------------------------------------------
//  Public: draw the entire alien enemy ship
// ---------------------------------------------------------------
void drawAlien()
{
    drawWings();
    drawHull();
    drawThrusters();
    drawEngineGlow();
    drawCockpit();
    drawHullPanels();
    drawWingGuns();
}