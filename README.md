# ⚔️ C++ Arena Engine Sandbox

A lightweight, cross-platform game engine simulation written completely from scratch in C++. This project serves as a core portfolio demonstration highlighting object-oriented fundamentals, dynamic state manipulation, looping architectures, and manual binary compilation.

## 🚀 Core Architectural Milestones
* **Data Layer:** Implemented strongly-typed primitive variables to track entity states in local memory.
* **Control Flow:** Integrated relational conditional logic trees to automatically evaluate entity lifecycle changes.
* **Simulation Loop:** Engineered a continuous execution loop (`while`) mimicking production game loops to drive real-time gameplay cycles.
* **Modular Engineering:** Abstracted visualization routines out of the main application flow into custom reusable Functions with distinct parameter signatures.
* **Dynamic Memory Vectors:** Integrated sequential dynamic containers (`std::vector`) and iterative processing loops to scale the architecture from a single actor to a multi-entity arena ecosystem.
* **Object-Oriented Blueprints (`struct`):** Modularized scattered primitive data elements into coherent composite types (`struct`), isolating entity attributes (health, damage vectors, naming strings) to enforce clean data encapsulation rules.
* **Multi-File Header Architecture:** Separated the monolithic code infrastructure into a professional decoupled layout (`.h` interface declarations and `.cpp` operational implementations) to optimize modular build compilation tracking.
* **Memory Pointers (`*` / `->`):** Implemented dynamic runtime hardware addressing layouts utilizing explicit memory pointers (`Monster*`) and pointer member access selectors (`->`) to orchestrate live target tracking without duplicating application data structures in cache layers.






## 🛠️ Compilation & Execution Guides

Because this engine utilizes a modular, multi-file architecture, you must pass all source implementation files (`.cpp`) to the compiler simultaneously so it can link your object dependencies correctly.

### 🐧 Linux (Fedora 44 / Red Hat Enterprise Environment)
Open your terminal and ensure you have the `gcc-c++` compiler group tools installed via your package manager.

```bash
# Compile all source engine components into a single linked native binary
g++ main.cpp Monster.cpp -o engine

# Execute the simulation engine sandbox
./engine
```

### 🪟 Windows 11
Open your Command Prompt (`cmd`) ensuring your system environmental variables map directly to your MinGW/GCC C++ binary pathways.

```cmd
# Compile and link all engine components into a standalone executable image file
g++ main.cpp Monster.cpp -o engine.exe

# Execute the standalone application window
engine.exe
```


## 📈 Developmental Methodology

This repository follows a strict, disciplined Git-first version tracking methodology. Every development cycle is methodically broken down into granular, semantic code updates to showcase clear problem-solving evolution and repository stewardship.
