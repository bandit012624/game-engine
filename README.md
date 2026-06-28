# ⚔️ C++ Arena Engine Sandbox

A lightweight, cross-platform game engine simulation written completely from scratch in C++. This project serves as a core portfolio demonstration highlighting object-oriented fundamentals, dynamic state manipulation, looping architectures, and manual binary compilation.

## 🚀 Core Architectural Milestones
* **Data Layer:** Implemented strongly-typed primitive variables to track entity states in local memory.
* **Control Flow:** Integrated relational conditional logic trees to automatically evaluate entity lifecycle changes.
* **Simulation Loop:** Engineered a continuous execution loop (`while`) mimicking production game loops to drive real-time gameplay cycles.

## 🛠️ Compilation & Execution Guides

Because this engine utilizes native standard C++, it can be cross-compiled natively across multiple operating systems.

### 🐧 Linux (Fedora 44 / Red Hat Enterprise Environment)
Open your terminal and ensure you have the `gcc-c++` compiler installed via your package manager.

```bash
# Compile human-readable source code into a native binary engine
g++ main.cpp -o engine

# Execute the simulation engine
./engine
```

### 🪟 Windows 11
Open your Command Prompt (`cmd`) ensuring your environmental variables map to your C++ compiler binaries.

```cmd
# Compile the application into an executable image file
g++ main.cpp -o engine.exe

# Execute the standalone application
engine.exe
```

## 📈 Developmental Methodology

This repository follows a strict, disciplined Git-first version tracking methodology. Every development cycle is methodically broken down into granular, semantic code updates to showcase clear problem-solving evolution and repository stewardship.
