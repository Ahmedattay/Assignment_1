#ifndef PRIMITIVES_H
#define PRIMITIVES_H

// ---------------------------------------------------------------
//  Primitives.h  –  Reusable OpenGL drawing helper functions
// ---------------------------------------------------------------

/// Draw a filled circle at (cx, cy, cz) with the given radius and RGB color.
void drawCircle(float cx, float cy, float cz,
                float radius,
                float r, float g, float b,
                int segments = 40);

/// Draw a filled rectangle from (x1,y1) to (x2,y2) at depth z.
void drawRect(float x1, float y1,
              float x2, float y2,
              float z,
              float r, float g, float b);

/// Draw a filled triangle with three vertices at depth z.
void drawTriangle(float x1, float y1,
                  float x2, float y2,
                  float x3, float y3,
                  float z,
                  float r, float g, float b);

/// Draw an elliptical ring (line loop) centered at (cx,cy,cz).
void drawEllipseRing(float cx, float cy, float cz,
                     float rx, float ry,
                     float r, float g, float b,
                     float lineWidth = 2.0f,
                     int segments = 60);

#endif // PRIMITIVES_H
