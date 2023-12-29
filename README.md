# Boids Simulation in C++ with SFML

[![License](https://shields.io/badge/License-GNU%20General%20Public%20License%20v3.0-green)](LICENSE)
[![SFML](https://img.shields.io/badge/SFML-2.6-brightgreen.svg)](https://www.sfml-dev.org/)
[![Linux](https://img.shields.io/badge/Platform-Linux-blue.svg)](https://www.linux.org/)

## Overview

This C++ application uses the Simple and Fast Multimedia Library (SFML) to simulate flocking behaviour. The simulation involves the movement of autonomous agents, or "boids", that follow simple rules to create cohesie and visually appealing group behaviour.

[![Boids Simulation](https://img.youtube.com/vi/skfMvKqt_Qw/0.jpg)](https://www.youtube.com/watch?v=skfMvKqt_Qw)

## Features

- **Flocking Algorithm:** The simulation implements a basic flocking algorithm, where individual agents follow three main rules: separation, alignment and cohesion.
- **SFML Graphics:** The application utilizes SFML for graphical rendering, providing an interactive and visually appealing representation of the flocking simulation.

## Requirements

- C++ compiler
- SFML 2.6 or later ([SFML Installation Guide](https://www.sfml-dev.org/tutorials/2.6/))

## Getting Started

1. Clone the repository
```bash
git clone https://github.com/ignabelitzky/boids-simulation.git
cd boids-simulation
```
2. Build the project using the Makefile
```bash
make
```
3. Run the executable
```bash
./boids
```

## Usage
- Press the close button or Alt+F4 to exit the simulation
- Customize simulation parameters with the sliders, such as speed and forces for alignment, cohesion and separation.

## License

This project is licensed under the [GNU General Public License v3.0](LICENSE). You can find the full text of the license here [LICENSE](LICENSE).
