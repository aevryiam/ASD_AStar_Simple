@echo off
echo Compiling Graph A* Program with Visualization...
g++ -std=c++11 -Wall -Wextra -O2 -o graph_astar.exe graph_astar.cpp

if %errorlevel% equ 0 (
    echo Compilation successful!
    echo Running the program...
    echo.
    graph_visual.exe
) else (
    echo Compilation failed!
    echo Make sure you have g++ installed and in your PATH.
    pause
)
