# Hello C++ Codespaces Starter

A minimal C++ "Hello World" project configured for GitHub Codespaces, VS Code, and CMake.

## Quick start (Codespaces)
1. Create a new repo on GitHub and add these files.
2. In the repo page, click **Code > Codespaces > Create codespace on main**.
3. After it opens, build and run:
   - Run task: `Build (CMake)` or press `Ctrl/Cmd+Shift+B`
   - Run the program:
     - Task: `Run Hello`
     - Or use Debug: "Run Hello (gdb)"

## Quick start (local with VS Code)
- Install: [VS Code](https://code.visualstudio.com/), [C/C++ extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools), [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools), and optionally **Dev Containers**.
- If using Dev Containers, open the repo folder in VS Code and "Reopen in Container" to match Codespaces.
- Build/Run via the provided tasks or CMake Tools commands.

## Commands
- Configure: `cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug`
- Build: `cmake --build build -j`
- Run: `./build/hello`

## CI
A basic GitHub Actions workflow builds and runs the program on Linux.
