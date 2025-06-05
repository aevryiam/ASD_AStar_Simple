@echo off
echo Compiling Graph A* Program with Visualization...
g++ -std=c++11 -Wall -Wextra -O2 -o graph_astar.exe main.cpp

if %errorlevel% equ 0 (
    echo Compilation successful!
    echo Running the program...
    echo.
    graph_astar.exe
) else (
    echo Compilation failed!
    echo Make sure you have g++ installed and in your PATH.
    pause
)
