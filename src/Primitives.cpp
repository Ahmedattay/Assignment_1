// ---------------------------------------------------------------
//  Primitives.cpp  –  Implementation of reusable drawing helpers
// ---------------------------------------------------------------

#include "Primitives.h"

#include <GL/glew.h>
#include <GL/glut.h>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// ---------------------------------------------------------------
void drawCircle(float cx, float cy, float cz,
                float radius,
                float r, float g, float b,
                int segments)
{
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(cx, cy, cz);
    for (int i = 0; i <= segments; ++i) {
        float angle = 2.0f * static_cast<float>(M_PI) * i / segments;
        glVertex3f(cx + radius * cosf(angle),
                   cy + radius * sinf(angle),
                   cz);
    }
    glEnd();
}

// ---------------------------------------------------------------
void drawRect(float x1, float y1,
              float x2, float y2,
              float z,
              float r, float g, float b)
{
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex3f(x1, y1, z);
    glVertex3f(x2, y1, z);
    glVertex3f(x2, y2, z);
    glVertex3f(x1, y2, z);
    glEnd();
}

// ---------------------------------------------------------------
void drawTriangle(float x1, float y1,
                  float x2, float y2,
                  float x3, float y3,
                  float z,
                  float r, float g, float b)
{
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLES);
    glVertex3f(x1, y1, z);
    glVertex3f(x2, y2, z);
    glVertex3f(x3, y3, z);
    glEnd();
}

// ---------------------------------------------------------------
void drawEllipseRing(float cx, float cy, float cz,
                     float rx, float ry,
                     float r, float g, float b,
                     float lineWidth,
                     int segments)
{
    glColor3f(r, g, b);
    glLineWidth(lineWidth);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < segments; ++i) {
        float angle = 2.0f * static_cast<float>(M_PI) * i / segments;
        glVertex3f(cx + rx * cosf(angle),
                   cy + ry * sinf(angle),
                   cz);
    }
    glEnd();
}
