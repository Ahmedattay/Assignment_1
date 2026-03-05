#ifndef HUD_H
#define HUD_H

// ---------------------------------------------------------------
//  HUD.h  –  On-screen text overlay
// ---------------------------------------------------------------

/// Draw a string at pixel position (x, y) using a 2-D overlay.
/// Assumes an 800x600 window.
void drawText(float x, float y, const char* text);

#endif // HUD_H
