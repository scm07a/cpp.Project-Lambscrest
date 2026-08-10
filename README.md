# Project Lambscrest

> A top-down 2D pixel-art action-adventure game built from scratch in modern C++ using SDL2.

## About

Project Lambscrest is a long-term game development project focused on building a complete game while strengthening my understanding of modern C++, software engineering, game architecture, and real-time rendering.

Rather than relying on an existing game engine, this project uses **SDL2** to build core game systems from the ground up. Every major system—from rendering and animation to resource management and world generation—is implemented incrementally as both a learning experience and the foundation for the final game.

---

## Current Features

- SDL2 window creation
- Hardware-accelerated rendering
- Frame-independent movement using Delta Time
- Object-oriented game architecture
- Separate input, update, and rendering systems
- Texture management system
- Animated player sprite system
- Directional idle and walking animations
- Animation state machine using `enum class`
- Sprite flipping for left-facing animations
- Tile-based world rendering
- CMake + Ninja build system
- Collision detection

---

## Planned Features

- Camera system
- JSON-based asset loading
- World generation
- Inventory system
- Combat mechanics
- Enemy AI
- NPC interactions
- Audio system
- Save & Load functionality

---

## Tech Stack

| Component | Technology |
|-----------|------------|
| Language | C++23 |
| Graphics | SDL2 |
| Image Loading | SDL2_image |
| Audio | SDL2_mixer |
| Fonts | SDL2_ttf |
| Build System | CMake + Ninja |
| Compiler | GCC (MSYS2 UCRT64) |
| IDE | Visual Studio Code |

---

## Project Structure

```text
Project-Lambscrest/
│
├── assets/
│   ├── audio/
│   ├── fonts/
│   └── textures/
│
├── build/
│
├── include/
│   ├── Game.h
│   ├── Collision.h
│   ├── shrdconst.h
│   ├── Player.h
│   ├── TextureManager.h
│   └── World.h
│
├── src/
│   ├── main.cpp
│   ├── Collision.cpp
│   ├── Game.cpp
│   ├── Player.cpp
│   ├── TextureManager.cpp
│   └── World.cpp
│
├── .gitignore
├── CMakeLists.txt
└── README.md
```

---

## Requirements

- CMake
- Ninja
- GCC (MSYS2 UCRT64)
- SDL2
- SDL2_image
- SDL2_ttf
- SDL2_mixer

---

## Building

### Configure

```bash
cmake -B build -G Ninja
```

### Build

```bash
cmake --build build
```

### Run

Run the generated executable from the `build` directory.

---

## Learning Goals

Project Lambscrest serves as a practical way to improve my understanding of:

- Modern C++
- Object-Oriented Programming
- Game Architecture
- SDL2
- Real-time Rendering
- Delta Time
- Resource Management
- Animation Systems
- State Machines
- Tile-Based Rendering
- Software Engineering Principles
- Clean Code Practices
- Game Development Best Practices

---

## Roadmap

- [x] SDL2 initialization
- [x] Window creation
- [x] Hardware-accelerated renderer
- [x] Delta time implementation
- [x] Game loop
- [x] Player movement
- [x] Input handling
- [x] Texture manager
- [x] Sprite rendering
- [x] Animation system
- [x] Directional player animations
- [x] Tile-based world rendering
- [x] Collision detection
- [ ] Camera system
- [ ] Text/UI rendering
- [ ] Tutorial prompts
- [ ] JSON asset loading
- [ ] Tile map loading
- [ ] Inventory system
- [ ] Combat mechanics
- [ ] Enemy AI
- [ ] NPC interactions
- [ ] Audio system
- [ ] Save & Load functionality

---

## Screenshots

> Screenshots and gameplay GIFs will be added as development progresses.

---

## Project Status

🚧 **Active Development**

Project Lambscrest is under active development. New systems are added incrementally, with an emphasis on writing clean, maintainable code while learning the fundamentals of engine and game development.

---

## License

A license will be selected before the first public release.
