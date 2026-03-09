

#include "Background.h"
#include "Primitives.h"

static const float Z = -5.0f;
static const float Z_NEAR = Z + 0.005f;
static const float Z_FRONT = Z + 0.010f;

// ---------------------------------------------------------------
//  SPACE SKY  –  deep dark teal, matching reference exactly
// ---------------------------------------------------------------
static void drawSpaceSky()
{
    // Base – very dark teal (matches reference background)
    drawRect(-1.0f, -1.0f, 1.0f, 1.0f, Z - 0.5f,
        0.022f, 0.055f, 0.085f);

    // Slightly lighter teal centre zone
    drawRect(-0.6f, -0.5f, 0.6f, 0.6f, Z - 0.4f,
        0.028f, 0.068f, 0.100f);

    // Subtle darker edges (vignette)
    drawRect(-1.0f, -1.0f, -0.65f, 1.0f, Z - 0.3f,
        0.010f, 0.028f, 0.045f);
    drawRect(0.65f, -1.0f, 1.0f, 1.0f, Z - 0.3f,
        0.010f, 0.028f, 0.045f);
}

// ---------------------------------------------------------------
//  STARS  –  small bright dots with soft glow, scattered densely
// ---------------------------------------------------------------
static const float STARS[][3] = {
    // x        y       size
    {-0.850f,  0.750f, 0.008f},
    {-0.700f,  0.400f, 0.006f},
    {-0.550f,  0.820f, 0.010f},
    {-0.400f,  0.600f, 0.007f},
    {-0.200f,  0.880f, 0.009f},
    { 0.050f,  0.720f, 0.006f},
    { 0.300f,  0.850f, 0.011f},
    { 0.500f,  0.650f, 0.007f},
    { 0.700f,  0.780f, 0.008f},
    { 0.880f,  0.500f, 0.006f},
    { 0.920f,  0.820f, 0.009f},
    {-0.900f,  0.100f, 0.007f},
    {-0.750f, -0.200f, 0.006f},
    {-0.600f,  0.050f, 0.008f},
    { 0.150f,  0.200f, 0.006f},
    { 0.820f,  0.050f, 0.007f},
    {-0.350f, -0.600f, 0.008f},
    { 0.100f, -0.750f, 0.006f},
    {-0.500f, -0.850f, 0.009f},
    { 0.650f, -0.680f, 0.007f},
    { 0.900f, -0.850f, 0.008f},
    {-0.880f, -0.750f, 0.006f},
    { 0.450f, -0.350f, 0.010f},
    {-0.150f,  0.450f, 0.006f},
    { 0.750f,  0.300f, 0.007f},
    {-0.650f,  0.650f, 0.008f},
    { 0.200f, -0.200f, 0.006f},
    {-0.280f,  0.750f, 0.007f},
    { 0.580f, -0.150f, 0.006f},
    {-0.780f, -0.450f, 0.009f},
    { 0.350f,  0.180f, 0.006f},
    {-0.100f, -0.400f, 0.007f},
};
static const int STAR_COUNT = 32;

static void drawStars()
{
    for (int i = 0; i < STAR_COUNT; ++i)
    {
        float x = STARS[i][0];
        float y = STARS[i][1];
        float s = STARS[i][2];
        float b = 0.60f + 0.40f * ((i * 17 + 5) % 10) / 10.0f;

        // Soft glow halo
        drawCircle(x, y, Z_NEAR, s * 2.0f,
            b * 0.15f, b * 0.22f, b * 0.28f);
        // Bright core
        drawCircle(x, y, Z_FRONT, s,
            b * 0.90f, b * 0.95f, b);
    }
}

// ---------------------------------------------------------------
//  ASTEROID CLUSTERS  –  grey rocky shapes from reference image
// ---------------------------------------------------------------
static void drawAsteroid(float cx, float cy, float r, float shade)
{
    // Rock base – medium grey
    drawCircle(cx, cy, Z_NEAR, r,
        shade * 0.52f, shade * 0.55f, shade * 0.50f);

    // Lighter face
    drawCircle(cx - r * 0.20f, cy + r * 0.20f, Z_NEAR, r * 0.72f,
        shade * 0.65f, shade * 0.68f, shade * 0.62f);

    // Dark shadow side
    drawCircle(cx + r * 0.25f, cy - r * 0.20f, Z_NEAR, r * 0.45f,
        shade * 0.30f, shade * 0.32f, shade * 0.28f);

    // Surface highlight
    drawCircle(cx - r * 0.28f, cy + r * 0.28f, Z_FRONT, r * 0.22f,
        shade * 0.82f, shade * 0.84f, shade * 0.80f);

    // Crater detail
    drawCircle(cx + r * 0.10f, cy - r * 0.05f, Z_FRONT, r * 0.18f,
        shade * 0.25f, shade * 0.27f, shade * 0.23f);
}

static void drawAsteroidClusters()
{
    // Upper-left cluster (matches reference)
    drawAsteroid(-0.700f, 0.680f, 0.090f, 1.0f);
    drawAsteroid(-0.600f, 0.760f, 0.058f, 0.85f);
    drawAsteroid(-0.780f, 0.750f, 0.045f, 0.90f);
    drawAsteroid(-0.650f, 0.620f, 0.035f, 0.80f);

    // Upper-right cluster (matches reference)
    drawAsteroid(0.780f, 0.700f, 0.075f, 0.95f);
    drawAsteroid(0.860f, 0.760f, 0.048f, 0.82f);
    drawAsteroid(0.720f, 0.780f, 0.038f, 0.88f);

    // Left-mid small rock (matches reference)
    drawAsteroid(-0.840f, 0.050f, 0.042f, 0.78f);
    drawAsteroid(-0.900f, 0.100f, 0.028f, 0.70f);

    // Right-mid debris (matches reference)
    drawAsteroid(0.880f, -0.100f, 0.032f, 0.75f);
}

// ---------------------------------------------------------------
//  NEBULA DUST PATCHES  –  large soft teal/blue glows
// ---------------------------------------------------------------
static void drawNebulae()
{
    // Left-centre nebula glow
    drawEllipseRing(-0.50f, 0.25f, Z_NEAR,
        0.280f, 0.140f,
        0.05f, 0.18f, 0.25f,
        1.0f, 48);
    drawEllipseRing(-0.46f, 0.27f, Z_NEAR,
        0.200f, 0.095f,
        0.06f, 0.22f, 0.30f,
        1.0f, 48);

    // Right-bottom subtle glow
    drawEllipseRing(0.60f, -0.30f, Z_NEAR,
        0.220f, 0.110f,
        0.04f, 0.14f, 0.20f,
        1.0f, 48);
}

// ---------------------------------------------------------------
//  GLOWING PARTICLES  –  small coloured specks like reference
// ---------------------------------------------------------------
static void drawParticles()
{
    // Red/orange glowing speck (left side like reference)
    drawCircle(-0.760f, 0.200f, Z_FRONT, 0.022f,
        0.70f, 0.12f, 0.08f);
    drawCircle(-0.760f, 0.200f, Z_FRONT, 0.010f,
        1.00f, 0.40f, 0.20f);

    // Cyan speck (right side like reference)
    drawCircle(0.840f, -0.380f, Z_FRONT, 0.018f,
        0.05f, 0.55f, 0.65f);
    drawCircle(0.840f, -0.380f, Z_FRONT, 0.008f,
        0.30f, 0.90f, 1.00f);

    // Small square-ish pixel dots (teal, like reference scattered pixels)
    float pixelDots[][2] = {
        { 0.680f,  0.250f},
        {-0.320f, -0.120f},
        { 0.120f, -0.550f},
        {-0.600f, -0.350f},
        { 0.400f,  0.050f},
        {-0.180f,  0.680f},
    };
    for (auto& p : pixelDots)
    {
        drawRect(p[0] - 0.008f, p[1] - 0.008f,
            p[0] + 0.008f, p[1] + 0.008f,
            Z_FRONT,
            0.12f, 0.45f, 0.55f);
    }
}

// ---------------------------------------------------------------
//  Public: draw the entire background
// ---------------------------------------------------------------
void drawBackground()
{
    drawSpaceSky();
    drawNebulae();
    drawStars();
    drawAsteroidClusters();
    drawParticles();
}