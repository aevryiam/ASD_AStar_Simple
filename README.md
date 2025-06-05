# Graph & A* Pathfinder

A C++ program that allows you to create weighted graphs and find the shortest path between nodes using the A* algorithm.

## Features

- **Graph Creation**: Add nodes with coordinates and weighted edges
- **Interactive Input**: User-friendly menu system for building graphs
- **Graph Visualization**: Display the complete graph structure in text and ASCII format
- **ASCII Graph Display**: Visual representation of nodes and edges on a coordinate grid
- **A* Algorithm**: Find shortest paths using the A* pathfinding algorithm
- **Path Visualization**: Visual representation of the shortest path found by A*
- **Heuristic Function**: Uses Euclidean distance based on node coordinates
- **Path Display**: Shows the complete path with weights and total cost

## How to Compile

### Using Make (Recommended)
```bash
make
```

### Manual Compilation
```bash
g++ -std=c++11 -Wall -Wextra -O2 -o graph_astar main.cpp
```

## How to Run

### Using Make
```bash
make run
```

### Direct Execution
```bash
./graph_astar
```

## Usage Guide

### 1. Adding Nodes
- Choose option 1 from the menu
- Enter a unique node name
- Provide x and y coordinates (used for heuristic calculation in A*)

### 2. Adding Edges
- Choose option 2 from the menu  
- Select source and destination nodes from available nodes
- Enter the weight/cost of the edge
- Note: This creates a directed edge (from source to destination)

### 3. Displaying the Graph
- Choose option 3 to see the complete graph structure in text format
- Shows all nodes with their coordinates
- Shows all edges with their weights

### 4. Visualizing the Graph
- Choose option 4 to see an ASCII visual representation of the graph
- Nodes are displayed as their first letter on a coordinate grid
- Edges are shown as lines connecting the nodes
- Grid includes coordinate references for easy reading

### 5. Finding Shortest Path
- Choose option 5 from the menu
- Select start and goal nodes
- The A* algorithm will find the optimal path
- Results show the complete path, individual edge weights, and total cost
- Includes visual representation of the path on the coordinate grid

## Example Usage

```
1. Add nodes: A(0,0), B(3,4), C(6,0), D(3,0)
2. Add edges: A->B(5), A->D(3), D->B(2), D->C(3), B->C(4)
3. Visualize graph to see ASCII representation
4. Find path from A to C
Result: A -(3)-> D -(3)-> C (Total cost: 6)
5. View visual representation of the path with * marking path nodes
```

## Visualization Features

### ASCII Graph Visualization
- 40x20 character grid showing node positions
- Nodes represented by their first letter
- Edges drawn with `-`, `|`, `/`, `\` characters
- Coordinate grid with numbered axes
- Automatic scaling to fit all nodes

### Path Visualization
- Path nodes marked with `*` (asterisk)
- Path edges highlighted with `#` (hash)
- Other nodes shown with first letter
- Clear legend explaining symbols
- Path sequence displayed below the grid

## Algorithm Details

### A* Algorithm
- Uses Euclidean distance as the heuristic function
- Guarantees finding the shortest path if one exists
- Efficient pathfinding with optimal performance
- Time complexity: O(b^d) where b is branching factor and d is depth

### Heuristic Function
- Calculates straight-line distance between nodes
- Formula: √[(x₂-x₁)² + (y₂-y₁)²]
- Admissible heuristic (never overestimates actual cost)

## Program Structure

- **Node**: Represents graph vertices with name and coordinates
- **Edge**: Represents weighted connections between nodes  
- **Graph**: Main class handling all graph operations
- **A* Implementation**: Complete pathfinding algorithm
- **Interactive Menu**: User-friendly interface

## Requirements

- C++11 compatible compiler (g++, clang++, MSVC)
- Standard C++ libraries only (no external dependencies)

## Notes

- The graph supports directed edges only
- Node coordinates are used for heuristic calculation
- Weights should be positive numbers
- Node names are case-sensitive
- Maximum path length is limited by available memory

## Complete Guides

- [Complete Guide](guide.md)