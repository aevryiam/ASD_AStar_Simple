# Complete Graph & A* Pathfinder Guide

A comprehensive C++ program that allows you to create weighted graphs and find the shortest path between nodes using the A* algorithm with ASCII visualization.

## Table of Contents
1. [Features](#features)
2. [Installation & Setup](#installation--setup)
3. [Usage Guide](#usage-guide)
4. [Visualization Features](#visualization-features)
5. [How to Read Visualizations](#how-to-read-visualizations)
6. [Step-by-Step Tutorial](#step-by-step-tutorial)
7. [Sample Test Data](#sample-test-data)
8. [Algorithm Details](#algorithm-details)
9. [Troubleshooting](#troubleshooting)

---

## Features

- **Graph Creation**: Add nodes with coordinates and weighted edges
- **Interactive Input**: User-friendly menu system for building graphs
- **Graph Visualization**: Display the complete graph structure in text and ASCII format
- **ASCII Graph Display**: Visual representation of nodes and edges on a coordinate grid
- **A* Algorithm**: Find shortest paths using the A* pathfinding algorithm
- **Path Visualization**: Visual representation of the shortest path found by A*
- **Heuristic Function**: Uses Euclidean distance based on node coordinates
- **Path Display**: Shows the complete path with weights and total cost

---

## Installation & Setup

### Compilation Options

#### Using Make (Recommended)
```bash
make
```

#### Using Batch File (Windows)
```batch
compile_and_run.bat
```

#### Manual Compilation
```bash
g++ -std=c++11 -Wall -Wextra -O2 -o graph_astar.exe graph_astar.cpp
```

### Running the Program

#### Using Make
```bash
make run
```

#### Direct Execution
```bash
./graph_astar.exe
```

---

## Usage Guide

### Menu Options

The program provides an interactive menu with the following options:

1. **Add Node** - Create nodes with coordinates
2. **Add Edge** - Create weighted connections between nodes
3. **Display Graph (Text)** - Show graph structure in text format
4. **Visualize Graph (ASCII)** - Show visual representation on coordinate grid
5. **Find Shortest Path (A*)** - Find optimal path with visualization
6. **Exit** - Close the program

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
- **Includes visual representation of the path on the coordinate grid**

---

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

---

## How to Read Visualizations

### Understanding the Grid System

```
=== GRAPH VISUALIZATION ===
   0    0    1    1    2    2    3    3
   0123456789012345678901234567890123456789
0  ........................................
1  ........................................
...
10 ....................A...................
...
19 ........................................
```

#### Grid Coordinates:
- **Top row**: Shows tens digits (0, 0, 1, 1, 2, 2, 3, 3)
- **Second row**: Shows units digits (0,1,2,3,4,5,6,7,8,9,0,1,2,3...)
- **Left column**: Shows Y coordinates (0 through 19)

#### Single Node Display:
- **Node Position**: If you see a node in the middle like above, it means you only have one node
- **Centering Effect**: With only one node, the program centers it on the grid
- **Need Multiple Nodes**: To see proper visualization, add at least 2-3 nodes

### Reading Multi-Node Visualizations

#### Graph Structure Example:
```
=== GRAPH VISUALIZATION ===
   0    5    10   15   20   25   30   35   40
   0123456789012345678901234567890123456789
0  A-------B...............................
1  |\      |...............................
2  | \     |...............................
3  |  \    |...............................
4  |   \   |...............................
5  D----\--C...............................
```

#### Path Visualization Example:
```
=== PATH VISUALIZATION ===
   0    5    10   15   20   25   30   35   40
   0123456789012345678901234567890123456789
0  *#######*...............................
1  #\      |...............................
2  # \     |...............................
3  #  \    |...............................
4  #   \   |...............................
5  *####\##*...............................

Path Sequence: A -> D -> C
```

#### Legend:
- **Nodes**: Represented by first letter of node name
- **Edges**: Represented by `-`, `|`, `/`, `\` characters
- **Path Nodes**: `*` (asterisk)
- **Path Edges**: `#` (hash)
- **Empty Space**: `.` (dot)

---

## Step-by-Step Tutorial

Follow these exact steps to see the visualization in action:

### Step 1: Run the Program
```bash
./graph_astar.exe
```

### Step 2: Add Multiple Nodes (Menu Option 1)

**Add Node A:**
- Choose option: 1
- Node name: A
- X coordinate: 0
- Y coordinate: 0

**Add Node B:**
- Choose option: 1  
- Node name: B
- X coordinate: 5
- Y coordinate: 0

**Add Node C:**
- Choose option: 1
- Node name: C
- X coordinate: 5
- Y coordinate: 5

**Add Node D:**
- Choose option: 1
- Node name: D
- X coordinate: 0
- Y coordinate: 5

### Step 3: Add Edges (Menu Option 2)

**Add Edge A to B:**
- Choose option: 2
- Source: A
- Destination: B
- Weight: 5

**Add Edge B to C:**
- Choose option: 2
- Source: B
- Destination: C
- Weight: 5

**Add Edge C to D:**
- Choose option: 2
- Source: C
- Destination: D
- Weight: 5

**Add Edge D to A:**
- Choose option: 2
- Source: D
- Destination: A
- Weight: 5

**Add diagonal shortcut A to C:**
- Choose option: 2
- Source: A
- Destination: C
- Weight: 7

### Step 4: Visualize Graph (Menu Option 4)

You should see something like:
```
=== GRAPH VISUALIZATION ===
     0    5    10   15   20   25   30   35   40
     0123456789012345678901234567890123456789
  0  A-----------------------B................
  1  |                       |................
  2  |\                      |................
  3  | \                     |................
  4  |  \                    |................
  5  |   \                   |................
  6  |    \                  |................
  7  |     \                 |................
  8  |      \                |................
  9  |       \               |................
 10  |        \              |................
 11  |         \             |................
 12  |          \            |................
 13  |           \           |................
 14  |            \          |................
 15  |             \         |................
 16  |              \        |................
 17  |               \       |................
 18  |                \      |................
 19  D-----------------------C................
```

### Step 5: Find Path (Menu Option 5)

**Test Path A to C:**
- Choose option: 5
- Start: A
- Goal: C

You should see the path visualization with:
- `*` marking nodes A and C
- `#` marking the path edges
- The optimal route highlighted

### What You Should See:

1. **Graph Structure**: Square formation with A, B, C, D at corners
2. **Edges**: Lines connecting the nodes
3. **Path Highlighting**: When finding A to C, you'll see if it takes the direct diagonal (weight 7) or goes around (A→B→C, weight 10)

### Understanding the Coordinates:

- **Grid scaling**: Your coordinates (0,0) to (5,5) get scaled to fit the 40x20 display
- **A at (0,0)**: Appears at top-left of the scaled area
- **B at (5,0)**: Appears at top-right of the scaled area  
- **C at (5,5)**: Appears at bottom-right of the scaled area
- **D at (0,5)**: Appears at bottom-left of the scaled area

### Expected A* Result:
- Direct path A→C (cost: 7) should be chosen over A→B→C (cost: 10)
- The visualization will show the direct diagonal path highlighted

---

## Sample Test Data

### Sample Graph 1: Simple Network
```
Nodes:
- A (0, 0)
- B (3, 4) 
- C (6, 0)
- D (3, 0)

Edges:
- A -> B (weight: 5)
- A -> D (weight: 3)
- D -> B (weight: 2)
- D -> C (weight: 3)
- B -> C (weight: 4)
```

#### Test Cases:
1. **Path A to C**: Expected result A -> D -> C (cost: 6)
2. **Path A to B**: Expected result A -> D -> B (cost: 5)
3. **Path B to C**: Expected result B -> C (cost: 4)

### Sample Graph 2: City Network
```
Nodes:
- NYC (0, 0)
- Boston (2, 8)
- Philadelphia (1, 3)
- Washington (2, 5)
- Atlanta (5, 2)

Edges:
- NYC -> Philadelphia (weight: 2)
- NYC -> Boston (weight: 8)
- Philadelphia -> Washington (weight: 3)
- Philadelphia -> Atlanta (weight: 7)
- Washington -> Atlanta (weight: 4)
- Boston -> Washington (weight: 6)
```

#### Test Cases:
1. **NYC to Atlanta**: Test different possible routes
2. **Boston to Atlanta**: Compare direct vs indirect paths

### Test Case 3: Complex Network
```
Nodes:
- S (0, 0)   // Start
- A (2, 1)
- B (4, 3)
- C (1, 4)
- D (3, 6)
- G (6, 5)   // Goal

Edges:
- S -> A (weight: 2)
- S -> C (weight: 4)
- A -> B (weight: 3)
- A -> D (weight: 5)
- B -> G (weight: 4)
- C -> D (weight: 2)
- D -> G (weight: 3)
```

---

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

### Program Structure
- **Node**: Represents graph vertices with name and coordinates
- **Edge**: Represents weighted connections between nodes  
- **Graph**: Main class handling all graph operations
- **A* Implementation**: Complete pathfinding algorithm
- **Interactive Menu**: User-friendly interface

---

## Troubleshooting

### Common Issues

#### Single Node Visualization
**Problem**: Only see one node in the center
**Solution**: Add more nodes with different coordinates

#### No Edges Visible
**Problem**: Don't see connecting lines
**Solution**: 
- Ensure you've added edges between nodes
- Make sure nodes aren't too close together
- Try using more spread out coordinates

#### Clustered Nodes
**Problem**: All nodes appear in same area
**Solution**: Use more diverse coordinate values

#### No Path Found
**Problem**: A* reports "No path found"
**Solution**: 
- Verify edges exist between nodes
- Check that there's a connected path from start to goal
- Ensure edge weights are positive

### What to Look For

#### Graph Visualization (Option 4):
- Nodes appear as single letters
- Lines connecting nodes represent edges
- Coordinate grid helps understand positioning
- All edges are visible as connecting lines

#### Path Visualization (Option 5):
- Path nodes marked with `*` symbols
- Path edges highlighted with `#` symbols
- Non-path nodes still show as letters
- Clear path sequence displayed below grid
- Total cost calculation shown

### Advanced Testing

Try creating graphs with:
- 10+ nodes to test scaling
- Nodes with negative coordinates
- Very close coordinates to test collision handling
- Multiple possible paths to verify A* finds the optimal one

### Expected Behavior

The A* algorithm should:
- Find the optimal (shortest) path when one exists
- Use coordinates to calculate heuristic distances
- Display the complete path with individual edge weights
- Show the total cost of the path

---

## Requirements

- C++11 compatible compiler (g++, clang++, MSVC)
- Standard C++ libraries only (no external dependencies)

## Notes

- The graph supports directed edges only
- Node coordinates are used for heuristic calculation
- Weights should be positive numbers
- Node names are case-sensitive
- Maximum path length is limited by available memory
- The grid auto-scales, so relative positions matter more than absolute values
- Path visualization only shows after finding a valid path

---

## Quick Reference

### Essential Steps for First Use:
1. Add at least 2-3 nodes with different coordinates
2. Add edges connecting the nodes
3. Use menu option 4 to visualize the graph
4. Use menu option 5 to find paths and see path visualization

### Quick Test Setup:
```
Nodes: A(0,0), B(5,0), C(5,5), D(0,5)
Edges: A→B(5), B→C(5), C→D(5), D→A(5), A→C(7)
Test: Find path A to C (should choose direct route cost 7)
```

This complete guide should provide everything you need to understand, use, and troubleshoot the Graph & A* Pathfinder program!
