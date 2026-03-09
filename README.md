https://docs.google.com/videos/d/104iQ5FOZJ7Um5Kq9gRGmec8zvOBBN8RP1wfosm3Kigs/edit?usp=sharing

# Space Shooter — 2D Arcade Scene

A static 2D space-shooter scene built with **OpenGL (GLUT/GLEW)** for the Computer Graphics course (Spring 2026, Assignment 1).

Inspired by classic top-down arcade space shooters, the scene is rendered from a **top-down perspective** with the player ship at the bottom firing upward at an enemy ship, against a richly detailed deep-space background.

---

## Screenshots

### Orthographic Projection

![Orthographic Projection](Screenshots/Orthographic%20projection.png)

### Perspective Projection

![Perspective Projection](Screenshots/Perspective%20projection.png)

---

## Scene Layers

The scene features three layered objects rendered at different Z-depths:

| Layer | Z-Depth | Object | Description |
|-------|---------|--------|-------------|
| Background | -5 | Space Environment | Dark teal space sky, asteroid clusters, nebula dust, 32 glowing stars, and coloured particle specks |
| Middle | -3 | Enemy Ship (Alien) | Top-down red/crimson enemy spacecraft facing downward, with swept wings, glowing orange engines, dark cockpit, wing guns, and hull panel detail |
| Front | -1 | Player Spaceship | Top-down beige/tan fighter jet facing upward, with delta wings, twin blue engine flames, teal cockpit canopy, wing cannon barrels, hull panels, and 3 orange projectile bullets |

---

## Visual Design

Each object was redesigned to match a **top-down arcade shooter aesthetic**, with layered primitives used to simulate shading, highlights, and depth.

### Player Spaceship (Z = -1)
- **Fuselage**: 3-layer warm tan/beige body (shadow → base → centre highlight stripe)
- **Wings**: Swept delta wings with surface highlights and dark wingtip accents
- **Tail fins**: Small rear stabiliser triangles
- **Engine pods**: Twin dark rear pods with 3-layer blue/cyan/white flames
- **Cockpit**: Layered teal glass dome with specular highlight and glint
- **Detail**: Hull panel seams, weapon mounts, wing cannon barrels
- **Bullets**: 3 orange flame-shaped projectiles flying upward

### Enemy Ship / Alien (Z = -3)
- **Hull**: Angular dark crimson body with vertical spine, pointing downward toward player
- **Wings**: Wide swept red wings with lighter surface and dark edge accents
- **Thrusters**: Rear engine pods with layered orange glow circles and ellipse rings
- **Cockpit**: Dark purple-tinted canopy glass with red accent dot
- **Detail**: Horizontal seam lines, vertical spine panel, side panel boxes
- **Weapons**: Wing-mounted gun barrels with glowing orange muzzle tips

### Background (Z = -5)
- **Sky**: Deep dark teal base with subtle lighter centre and vignette edges
- **Stars**: 32 scattered stars, each with a soft halo glow ring
- **Asteroids**: 3 clusters of grey rocky bodies (upper-left, upper-right, side debris) — each asteroid has shadow, surface highlight, and crater detail
- **Nebulae**: Faint teal ellipse ring dust patches on left and right sides
- **Particles**: Red/orange glow speck (left), cyan glow speck (right), and 6 scattered teal pixel dots

---

## Primitives Used

| Primitive | OpenGL Mode | Used For |
|-----------|-------------|----------|
| **Circle** | `GL_TRIANGLE_FAN` | Cockpit, engine glow, stars, asteroids, particles, bullet glow |
| **Rectangle** | `GL_QUADS` | Fuselage, hull panels, engine pods, sky layers, wing seams |
| **Triangle** | `GL_TRIANGLES` | Nose cone, wings, tail fins, engine flames, bullets |
| **Ellipse Ring** | `GL_LINE_LOOP` | Engine glow rings, nebula outlines |

All primitives support layered depth offsets (`Z`, `Z + 0.005`, `Z + 0.010`) to avoid z-fighting between detail layers drawn on the same object.

---

## Project Structure

```
Assignment_1/
├── include/
│   ├── Alien.h             # Enemy ship interface
│   ├── Background.h        # Space background interface
│   ├── HUD.h               # On-screen text overlay
│   ├── Primitives.h        # Reusable drawing helpers
│   └── Spaceship.h         # Player ship interface
├── src/
│   ├── main.cpp            # Entry point, GLUT callbacks, projection setup
│   ├── Alien.cpp           # Enemy ship drawing (top-down red spacecraft)
│   ├── Background.cpp      # Background drawing (teal sky, asteroids, stars)
│   ├── HUD.cpp             # HUD text rendering
│   ├── Primitives.cpp      # OpenGL primitive drawing functions
│   └── Spaceship.cpp       # Player ship drawing (top-down tan fighter)
├── Screenshots/
│   ├── Orthographic projection.png
│   └── Perspective projection.png
├── Assignment_1.sln
├── Assignment_1.vcxproj
├── Assignment_1.vcxproj.filters
├── .gitignore
└── README.md
```

---

## Controls

| Key | Action |
|-----|--------|
| `O` / `o` | Switch to **Orthographic** projection |
| `P` / `p` | Switch to **Perspective** projection |
| `ESC` | Exit the application |

---

## Build Instructions

### Requirements

- **Visual Studio 2022** (MSVC v143 toolset)
- **GLEW** — OpenGL Extension Wrangler (include + lib configured in project properties)
- **GLUT / freeglut** — OpenGL Utility Toolkit

### Setting Up GLEW & GLUT

If you see `Cannot open include file: 'GL/glew.h'`:

1. Download GLEW from https://glew.sourceforge.net/ (Windows precompiled binaries)
2. In Visual Studio project properties (All Configurations | All Platforms):
   - **C/C++ → Additional Include Directories**: add `path\to\glew\include`
   - **Linker → Additional Library Directories**: add `path\to\glew\lib\Release\x64`
   - **Linker → Additional Dependencies**: add `glew32s.lib`
   - **C/C++ → Preprocessor Definitions**: add `GLEW_STATIC`
3. Repeat equivalent steps for freeglut: https://www.transmissionzero.co.uk/software/freeglut-devel/

### Build & Run

1. Open `Assignment_1.sln` in Visual Studio.
2. Select **Debug | x64** (or Release | x64).
3. Press `Ctrl+F5` to build and run.

---

## Team

This assignment was developed as a 4-member team project. Each member was responsible for one main scene object:

| # | Object | File |
|---|--------|------|
| 1 | Player Spaceship | `Spaceship.cpp` |
| 2 | Enemy Ship (Alien) | `Alien.cpp` |
| 3 | Space Background | `Background.cpp` |
| 4 | HUD & Entry Point | `HUD.cpp`, `main.cpp` |

### Team Members

| Name | Student ID |
|------|------------|
| Ali Mahmoud Ahmed | 1230338 |
| Ahmed Attay Kamal | 1230011 |
| Mahmoud Mohamed Abdelfattah | 4220142 |
| Seif Allah Alaa Mohamed | 1200324 |
