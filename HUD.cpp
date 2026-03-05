// ---------------------------------------------------------------
//  HUD.cpp  –  On-screen text overlay implementation
// ---------------------------------------------------------------

#include "HUD.h"

#include <GL/glew.h>
#include <GL/glut.h>

// Window dimensions (must match glutInitWindowSize in main.cpp)
static const int WIN_W = 800;
static const int WIN_H = 600;

// ---------------------------------------------------------------
void drawText(float x, float y, const char* text)
{
    // Save current projection and switch to 2-D screen coords
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, WIN_W, 0, WIN_H);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    // White text
    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2f(x, y);

    for (const char* c = text; *c; ++c)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);

    // Restore matrices
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
}
