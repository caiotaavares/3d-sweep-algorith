# 3D Renderer - Sweep and Z-Buffer Algorithms

## Description
This project is a tool for simplified 3D rendering, developed in C++ with a focus on classic computer graphics algorithms like Sweep and Z-Buffer. The interactive graphical interface allows users to visualize 3D objects while applying fundamental rasterization and surface-hiding techniques.

## Features
- **Sweep Algorithm:** Efficient polygon rasterization.
- **Z-Buffer Algorithm:** Depth management for surface hiding.
- **Interactive Graphical Interface:** 3D object visualization and manipulation.
- Modular architecture for extending or improving existing algorithms.

## Project Architecture
- **`canvas.h` and `canvas.cpp`:** Manages the drawing area where objects are rendered.
- **`sweep.h` and `sweep.cpp`:** Implements the Sweep algorithm.
- **`zbuffer.h` and `zbuffer.cpp`:** Implements the Z-Buffer algorithm.
- **`mainwindow.cpp`:** Handles interaction between the graphical interface and algorithms.

## Requirements
- **Language:** C++
- **Dependencies:**
  - Graphical library for the interface (e.g., Qt)
  - Modern C++ compiler (supporting C++17 or newer)
