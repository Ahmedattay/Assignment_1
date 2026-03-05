/*
 *  main.cpp  –  Entry point, GLUT callbacks, projection setup
 *
 *  Assignment 1 - 2D Mini Arcade Game: Space Shooter (Static Scene)
 *  ----------------------------------------------------------------
 *  3 Main Objects (3 team members):
 *    1. Spaceship   (Player)      – Spaceship.cpp
 *    2. Alien Enemy (Enemy)       – Alien.cpp
 *    3. Planet      (Background)  – Background.cpp
 *
 *  Controls:
 *    O / o   -> Orthographic Projection
 *    P / p   -> Perspective  Projection
 *    ESC     -> Exit
 */

#include <GL/glew.h>
#include <GL/glut.h>

#include "Spaceship.h"
#include "Alien.h"
#include "Background.h"
#include "HUD.h"

// ---------------------------------------------------------------
//  Constants
// ---------------------------------------------------------------
static const int   WIN_W  = 800;
static const int   WIN_H  = 600;
static const float ASPECT = static_cast<float>(WIN_W) / WIN_H;

// ---------------------------------------------------------------
//  Global state
// ---------------------------------------------------------------
static bool usePerspective = false;   // start with orthographic

// ---------------------------------------------------------------
//  Projection helpers
// ---------------------------------------------------------------
static void applyOrthographic()
{
    glOrtho(-1.0, 1.0, -1.0, 1.0, 0.1, 100.0);
}

static void applyPerspective()
{
    gluPerspective(60.0, ASPECT, 0.1, 100.0);
}

static void setupProjection()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (usePerspective)
        applyPerspective();
    else
        applyOrthographic();
}

static void setupCamera()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 1.0,      // eye
              0.0, 0.0, 0.0,      // center
              0.0, 1.0, 0.0);     // up
}

// ---------------------------------------------------------------
//  GLUT display callback
// ---------------------------------------------------------------
static void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    setupProjection();
    setupCamera();

    // Draw scene layers (back to front)
    drawBackground();      // Z = -5  (farthest)
    drawAlien();           // Z = -3  (middle)
    drawSpaceship();       // Z = -1  (closest)

    // HUD overlay
    if (usePerspective)
        drawText(10, 575, "Projection: PERSPECTIVE  (press O for Ortho)");
    else
        drawText(10, 575, "Projection: ORTHOGRAPHIC (press P for Persp)");

    drawText(10, 10, "Space Shooter - 2D Arcade Scene  |  ESC to exit");

    glutSwapBuffers();
}

// ---------------------------------------------------------------
//  GLUT keyboard callback
// ---------------------------------------------------------------
static void keyboard(unsigned char key, int /*x*/, int /*y*/)
{
    switch (key) {
        case 'o': case 'O': usePerspective = false; break;
        case 'p': case 'P': usePerspective = true;  break;
        case 27:             exit(0);                break;     // ESC
    }
    glutPostRedisplay();
}

// ---------------------------------------------------------------
//  OpenGL one-time init
// ---------------------------------------------------------------
static void initGL()
{
    GLenum err = glewInit();
    if (err != GLEW_OK)
        exit(1);

    glEnable(GL_DEPTH_TEST);
    glClearColor(0.02f, 0.0f, 0.08f, 1.0f);   // dark space
}

// ---------------------------------------------------------------
//  main
// ---------------------------------------------------------------
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(WIN_W, WIN_H);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Assignment 1 - Space Shooter Arcade Scene");

    initGL();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
