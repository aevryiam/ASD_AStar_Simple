// Example program showing visualization features
// This demonstrates the ASCII visualization capabilities

/*
SAMPLE VISUALIZATION OUTPUT:

=== GRAPH VISUALIZATION ===
     0    5    10   15   20   25   30   35   40
     0123456789012345678901234567890123456789
  0  A........................................
  1  |\......................................
  2  | \....................................
  3  |  \...................................
  4  |   B..................................
  5  |   |\................................
  6  |   | \..............................
  7  |   |  \............................
  8  D---+---C............................
  9  ........................................
 10  ........................................

Legend:
  Nodes: Represented by first letter of node name
  Edges: Represented by '-', '|', '/', '\' characters
  Empty: Represented by '.' characters

Node Positions:
  A: (0, 0)
  B: (3, 4)
  C: (6, 8)
  D: (0, 8)

===========================

=== PATH VISUALIZATION ===
Finding shortest path from A to C

     0    5    10   15   20   25   30   35   40
     0123456789012345678901234567890123456789
  0  *........................................
  1  #\......................................
  2  # \....................................
  3  #  \...................................
  4  #  *..................................
  5  #  #\................................
  6  #  # \..............................
  7  #  #  \............................
  8  *##*##*............................
  9  ........................................
 10  ........................................

Path Sequence: A -> D -> C

Legend:
  Path Nodes: * (asterisk)
  Path Edges: # (hash)
  Other Nodes: First letter of node name
  Empty Space: . (dot)

==========================

Path found: A -(4)-> D -(6)-> C
Total path cost: 10.00
Number of nodes in path: 3

This visualization shows:
1. The complete graph structure with nodes and edges
2. The optimal path highlighted with special characters
3. Coordinate grid for reference
4. Clear legend explaining the symbols
5. Path details with weights and total cost

The A* algorithm considers both the actual distance (edge weights) 
and the heuristic (Euclidean distance) to find the optimal path.
*/

#include "main.cpp"

// This file serves as documentation for the visualization features
// Run the main main.cpp program to use the interactive interface
