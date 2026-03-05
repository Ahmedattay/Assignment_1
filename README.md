# Space Shooter — 2D Arcade Scene

A static 2D space-shooter scene built with **OpenGL (GLUT/GLEW)** for the Computer Graphics course (Spring 2026, Assignment 1).

## Screenshot Concept

The scene features three layered objects rendered at different depths:

| Layer | Z-Depth | Object | Description |
|-------|---------|--------|-------------|
| Background | -5 | Planet & Stars | Dark space sky, a blue planet with an elliptical ring, and 18 scattered stars |
| Middle | -3 | Alien Enemy | Green alien with purple horns, red eyes, and a rectangular body |
| Front | -1 | Spaceship | Silver-grey player ship with red nose cone, blue wings, cyan cockpit, and orange engine flames |

## Project Structure

```
Assignment_1/
├── include/            # Header files
│   ├── Alien.h         # Alien enemy interface
│   ├── Background.h    # Planet & stars interface
│   ├── HUD.h           # On-screen text overlay
│   ├── Primitives.h    # Reusable drawing helpers (circle, rect, triangle, ellipse ring)
│   └── Spaceship.h     # Player spaceship interface
├── src/                # Source files
│   ├── main.cpp        # Entry point, GLUT callbacks, projection setup
│   ├── Alien.cpp       # Alien drawing implementation
│   ├── Background.cpp  # Background drawing implementation
│   ├── HUD.cpp         # HUD text rendering
│   ├── Primitives.cpp  # OpenGL primitive drawing functions
│   └── Spaceship.cpp   # Spaceship drawing implementation
├── Assignment_1.sln    # Visual Studio solution
├── Assignment_1.vcxproj
├── Assignment_1.vcxproj.filters
├── .gitignore
└── README.md
```

## Controls

| Key | Action |
|-----|--------|
| `O` / `o` | Switch to **Orthographic** projection |
| `P` / `p` | Switch to **Perspective** projection |
| `ESC` | Exit |

## Primitives Used

- **Circle** (`GL_TRIANGLE_FAN`) — planet, stars, cockpit, alien head, eyes
- **Rectangle** (`GL_QUADS`) — spaceship body, alien body, space sky
- **Triangle** (`GL_TRIANGLES`) — nose cone, wings, engine flames, alien horns
- **Ellipse Ring** (`GL_LINE_LOOP`) — planet ring

## Build Instructions

### Requirements

- Visual Studio 2022 (MSVC v143 toolset)
- OpenGL, GLUT, and GLEW libraries installed and configured

### Build

1. Open `Assignment_1.sln` in Visual Studio.
2. Select **Debug | x64** (or your preferred configuration).
3. Build and run (`Ctrl+F5`).

## Team

This assignment was developed as a 3-member team project, where each member was responsible for one main scene object:

1. **Spaceship** (Player) — `Spaceship.cpp`
2. **Alien Enemy** — `Alien.cpp`
3. **Planet & Background** — `Background.cpp`
