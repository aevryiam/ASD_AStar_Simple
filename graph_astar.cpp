#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <climits>
#include <algorithm>
#include <iomanip>

using namespace std;

// Structure to represent a node in the graph
struct Node {
    string name;
    double x, y; // Coordinates for heuristic calculation
    
    Node() : name(""), x(0), y(0) {}
    Node(string n, double xPos = 0, double yPos = 0) : name(n), x(xPos), y(yPos) {}
};

// Structure to represent an edge
struct Edge {
    string destination;
    double weight;
    
    Edge(string dest, double w) : destination(dest), weight(w) {}
};

// Graph class
class Graph {
private:
    map<string, Node> nodes;
    map<string, vector<Edge>> adjacencyList;

public:
    // Add a node to the graph
    void addNode(const string& name, double x = 0, double y = 0) {
        nodes[name] = Node(name, x, y);
        if (adjacencyList.find(name) == adjacencyList.end()) {
            adjacencyList[name] = vector<Edge>();
        }
    }
    
    // Add an edge between two nodes
    void addEdge(const string& from, const string& to, double weight) {
        // Check if both nodes exist
        if (nodes.find(from) == nodes.end() || nodes.find(to) == nodes.end()) {
            cout << "Error: One or both nodes don't exist!" << endl;
            return;
        }
        
        adjacencyList[from].push_back(Edge(to, weight));
        cout << "Edge added: " << from << " -> " << to << " (weight: " << weight << ")" << endl;
    }
    
    // Display the graph
    void displayGraph() {
        cout << "\n=== GRAPH STRUCTURE ===" << endl;
        cout << "Nodes:" << endl;
        for (const auto& pair : nodes) {
            cout << "  " << pair.first << " (x: " << pair.second.x 
                 << ", y: " << pair.second.y << ")" << endl;
        }
        
        cout << "\nEdges:" << endl;
        for (const auto& pair : adjacencyList) {
            if (!pair.second.empty()) {
                cout << "  " << pair.first << " -> ";
                for (size_t i = 0; i < pair.second.size(); i++) {
                    cout << pair.second[i].destination << "(" << pair.second[i].weight << ")";
                    if (i < pair.second.size() - 1) cout << ", ";
                }
                cout << endl;
            }
        }
        cout << "======================" << endl;
    }
    
    // Calculate Euclidean distance as heuristic
    double calculateHeuristic(const string& from, const string& to) {
        if (nodes.find(from) == nodes.end() || nodes.find(to) == nodes.end()) {
            return 0;
        }
        
        Node fromNode = nodes[from];
        Node toNode = nodes[to];
        
        return sqrt(pow(toNode.x - fromNode.x, 2) + pow(toNode.y - fromNode.y, 2));
    }
    
    // A* Algorithm implementation
    vector<string> aStar(const string& start, const string& goal) {
        if (nodes.find(start) == nodes.end() || nodes.find(goal) == nodes.end()) {
            cout << "Error: Start or goal node doesn't exist!" << endl;
            return vector<string>();
        }
        
        // Priority queue for open set (f_score, node_name)
        priority_queue<pair<double, string>, vector<pair<double, string>>, greater<pair<double, string>>> openSet;
        
        // Maps to store scores and came_from relationships
        map<string, double> gScore; // Cost from start to node
        map<string, double> fScore; // gScore + heuristic
        map<string, string> cameFrom; // For path reconstruction
        set<string> openSetNodes;
        
        // Initialize all nodes with infinite scores
        for (const auto& pair : nodes) {
            gScore[pair.first] = INT_MAX;
            fScore[pair.first] = INT_MAX;
        }
        
        // Initialize start node
        gScore[start] = 0;
        fScore[start] = calculateHeuristic(start, goal);
        openSet.push({fScore[start], start});
        openSetNodes.insert(start);
        
        while (!openSet.empty()) {
            string current = openSet.top().second;
            openSet.pop();
            openSetNodes.erase(current);
            
            if (current == goal) {
                // Reconstruct path
                vector<string> path;
                string temp = current;
                while (cameFrom.find(temp) != cameFrom.end()) {
                    path.push_back(temp);
                    temp = cameFrom[temp];
                }
                path.push_back(start);
                reverse(path.begin(), path.end());
                return path;
            }
            
            // Check all neighbors
            for (const Edge& edge : adjacencyList[current]) {
                string neighbor = edge.destination;
                double tentativeGScore = gScore[current] + edge.weight;
                
                if (tentativeGScore < gScore[neighbor]) {
                    cameFrom[neighbor] = current;
                    gScore[neighbor] = tentativeGScore;
                    fScore[neighbor] = gScore[neighbor] + calculateHeuristic(neighbor, goal);
                    
                    if (openSetNodes.find(neighbor) == openSetNodes.end()) {
                        openSet.push({fScore[neighbor], neighbor});
                        openSetNodes.insert(neighbor);
                    }
                }
            }
        }
        
        return vector<string>(); // No path found
    }
      // Display A* result
    void displayAStarResult(const string& start, const string& goal) {
        cout << "\n=== A* PATHFINDING RESULT ===" << endl;
        cout << "Finding shortest path from " << start << " to " << goal << endl;
        
        vector<string> path = aStar(start, goal);
        
        if (path.empty()) {
            cout << "No path found!" << endl;
            return;
        }
        
        cout << "Path found: ";
        double totalCost = 0;
        
        for (size_t i = 0; i < path.size(); i++) {
            cout << path[i];
            
            if (i < path.size() - 1) {
                // Find the weight of the edge
                string current = path[i];
                string next = path[i + 1];
                
                for (const Edge& edge : adjacencyList[current]) {
                    if (edge.destination == next) {
                        totalCost += edge.weight;
                        cout << " -(" << edge.weight << ")-> ";
                        break;
                    }
                }
            }
        }
        
        cout << endl;
        cout << "Total path cost: " << fixed << setprecision(2) << totalCost << endl;
        cout << "Number of nodes in path: " << path.size() << endl;
        
        // Add path visualization
        visualizePath(path);
        
        cout << "=============================" << endl;
    }
    
    // Check if a node exists
    bool nodeExists(const string& name) {
        return nodes.find(name) != nodes.end();
    }
      // Get all node names
    vector<string> getAllNodes() {
        vector<string> nodeNames;
        for (const auto& pair : nodes) {
            nodeNames.push_back(pair.first);
        }
        return nodeNames;
    }
    
    // Visualize the graph in ASCII format
    void visualizeGraph() {
        cout << "\n=== GRAPH VISUALIZATION ===" << endl;
        
        if (nodes.empty()) {
            cout << "No nodes to display!" << endl;
            return;
        }
        
        // Find bounds for scaling
        double minX = nodes.begin()->second.x, maxX = nodes.begin()->second.x;
        double minY = nodes.begin()->second.y, maxY = nodes.begin()->second.y;
        
        for (const auto& pair : nodes) {
            minX = min(minX, pair.second.x);
            maxX = max(maxX, pair.second.x);
            minY = min(minY, pair.second.y);
            maxY = max(maxY, pair.second.y);
        }
        
        // Grid dimensions
        const int gridWidth = 40;
        const int gridHeight = 20;
        
        // Create grid
        vector<vector<char>> grid(gridHeight, vector<char>(gridWidth, '.'));
        map<string, pair<int, int>> nodePositions;
        
        // Place nodes on grid
        for (const auto& pair : nodes) {
            double x = pair.second.x;
            double y = pair.second.y;
            
            // Scale to grid
            int gridX = (maxX == minX) ? gridWidth/2 : (int)((x - minX) / (maxX - minX) * (gridWidth - 1));
            int gridY = (maxY == minY) ? gridHeight/2 : (int)((maxY - y) / (maxY - minY) * (gridHeight - 1));
            
            // Ensure within bounds
            gridX = max(0, min(gridWidth - 1, gridX));
            gridY = max(0, min(gridHeight - 1, gridY));
            
            nodePositions[pair.first] = {gridY, gridX};
            grid[gridY][gridX] = pair.first[0]; // Use first character of node name
        }
        
        // Draw edges as lines
        for (const auto& pair : adjacencyList) {
            string from = pair.first;
            if (nodePositions.find(from) == nodePositions.end()) continue;
            
            for (const Edge& edge : pair.second) {
                string to = edge.destination;
                if (nodePositions.find(to) == nodePositions.end()) continue;
                
                int y1 = nodePositions[from].first;
                int x1 = nodePositions[from].second;
                int y2 = nodePositions[to].first;
                int x2 = nodePositions[to].second;
                
                // Simple line drawing using Bresenham-like approach
                drawLine(grid, x1, y1, x2, y2, gridWidth, gridHeight);
            }
        }
        
        // Redraw nodes (to overwrite line characters)
        for (const auto& pair : nodePositions) {
            int y = pair.second.first;
            int x = pair.second.second;
            grid[y][x] = pair.first[0];
        }
        
        // Print grid
        cout << "   ";
        for (int x = 0; x < gridWidth; x++) {
            if (x % 5 == 0) cout << (x / 10);
            else cout << " ";
        }
        cout << endl;
        
        cout << "   ";
        for (int x = 0; x < gridWidth; x++) {
            cout << (x % 10);
        }
        cout << endl;
        
        for (int y = 0; y < gridHeight; y++) {
            cout << setfill(' ') << setw(2) << y << " ";
            for (int x = 0; x < gridWidth; x++) {
                cout << grid[y][x];
            }
            cout << endl;
        }
        
        // Legend
        cout << "\nLegend:" << endl;
        cout << "  Nodes: Represented by first letter of node name" << endl;
        cout << "  Edges: Represented by '-', '|', '/', '\\' characters" << endl;
        cout << "  Empty: Represented by '.' characters" << endl;
        
        // Node coordinates
        cout << "\nNode Positions:" << endl;
        for (const auto& pair : nodes) {
            cout << "  " << pair.first << ": (" << pair.second.x << ", " << pair.second.y << ")" << endl;
        }
        
        cout << "===========================" << endl;
    }
    
    // Visualize path on the graph
    void visualizePath(const vector<string>& path) {
        if (path.empty()) {
            cout << "No path to visualize!" << endl;
            return;
        }
        
        cout << "\n=== PATH VISUALIZATION ===" << endl;
        
        // Find bounds for scaling
        double minX = nodes.begin()->second.x, maxX = nodes.begin()->second.x;
        double minY = nodes.begin()->second.y, maxY = nodes.begin()->second.y;
        
        for (const auto& pair : nodes) {
            minX = min(minX, pair.second.x);
            maxX = max(maxX, pair.second.x);
            minY = min(minY, pair.second.y);
            maxY = max(maxY, pair.second.y);
        }
        
        // Grid dimensions
        const int gridWidth = 40;
        const int gridHeight = 20;
        
        // Create grid
        vector<vector<char>> grid(gridHeight, vector<char>(gridWidth, '.'));
        map<string, pair<int, int>> nodePositions;
        
        // Place all nodes on grid
        for (const auto& pair : nodes) {
            double x = pair.second.x;
            double y = pair.second.y;
            
            // Scale to grid
            int gridX = (maxX == minX) ? gridWidth/2 : (int)((x - minX) / (maxX - minX) * (gridWidth - 1));
            int gridY = (maxY == minY) ? gridHeight/2 : (int)((maxY - y) / (maxY - minY) * (gridHeight - 1));
            
            // Ensure within bounds
            gridX = max(0, min(gridWidth - 1, gridX));
            gridY = max(0, min(gridHeight - 1, gridY));
            
            nodePositions[pair.first] = {gridY, gridX};
            
            // Check if node is in path
            bool inPath = find(path.begin(), path.end(), pair.first) != path.end();
            if (inPath) {
                grid[gridY][gridX] = '*'; // Path nodes marked with *
            } else {
                grid[gridY][gridX] = pair.first[0]; // Other nodes with first letter
            }
        }
        
        // Draw path edges with special characters
        for (size_t i = 0; i < path.size() - 1; i++) {
            string from = path[i];
            string to = path[i + 1];
            
            if (nodePositions.find(from) == nodePositions.end() || 
                nodePositions.find(to) == nodePositions.end()) continue;
            
            int y1 = nodePositions[from].first;
            int x1 = nodePositions[from].second;
            int y2 = nodePositions[to].first;
            int x2 = nodePositions[to].second;
            
            // Draw path line with special character
            drawPathLine(grid, x1, y1, x2, y2, gridWidth, gridHeight);
        }
        
        // Redraw path nodes
        for (const string& nodeName : path) {
            if (nodePositions.find(nodeName) != nodePositions.end()) {
                int y = nodePositions[nodeName].first;
                int x = nodePositions[nodeName].second;
                grid[y][x] = '*';
            }
        }
        
        // Print grid
        cout << "   ";
        for (int x = 0; x < gridWidth; x++) {
            if (x % 5 == 0) cout << (x / 10);
            else cout << " ";
        }
        cout << endl;
        
        cout << "   ";
        for (int x = 0; x < gridWidth; x++) {
            cout << (x % 10);
        }
        cout << endl;
        
        for (int y = 0; y < gridHeight; y++) {
            cout << setfill(' ') << setw(2) << y << " ";
            for (int x = 0; x < gridWidth; x++) {
                cout << grid[y][x];
            }
            cout << endl;
        }
        
        // Path information
        cout << "\nPath Sequence: ";
        for (size_t i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i < path.size() - 1) cout << " -> ";
        }
        cout << endl;
        
        cout << "\nLegend:" << endl;
        cout << "  Path Nodes: * (asterisk)" << endl;
        cout << "  Path Edges: # (hash)" << endl;
        cout << "  Other Nodes: First letter of node name" << endl;
        cout << "  Empty Space: . (dot)" << endl;
        
        cout << "==========================" << endl;
    }

private:
    // Helper function to draw line between two points
    void drawLine(vector<vector<char>>& grid, int x1, int y1, int x2, int y2, int width, int height) {
        int dx = abs(x2 - x1);
        int dy = abs(y2 - y1);
        int sx = (x1 < x2) ? 1 : -1;
        int sy = (y1 < y2) ? 1 : -1;
        int err = dx - dy;
        
        int x = x1, y = y1;
        
        while (true) {
            if (x >= 0 && x < width && y >= 0 && y < height) {
                if (grid[y][x] == '.') {
                    // Choose line character based on direction
                    if (dx > dy) {
                        grid[y][x] = '-';
                    } else if (dy > dx) {
                        grid[y][x] = '|';
                    } else {
                        grid[y][x] = (sx == sy) ? '\\' : '/';
                    }
                }
            }
            
            if (x == x2 && y == y2) break;
            
            int e2 = 2 * err;
            if (e2 > -dy) {
                err -= dy;
                x += sx;
            }
            if (e2 < dx) {
                err += dx;
                y += sy;
            }
        }
    }
    
    // Helper function to draw path line with special character
    void drawPathLine(vector<vector<char>>& grid, int x1, int y1, int x2, int y2, int width, int height) {
        int dx = abs(x2 - x1);
        int dy = abs(y2 - y1);
        int sx = (x1 < x2) ? 1 : -1;
        int sy = (y1 < y2) ? 1 : -1;
        int err = dx - dy;
        
        int x = x1, y = y1;
        
        while (true) {
            if (x >= 0 && x < width && y >= 0 && y < height) {
                if (grid[y][x] == '.' || grid[y][x] == '-' || grid[y][x] == '|' || 
                    grid[y][x] == '/' || grid[y][x] == '\\') {
                    grid[y][x] = '#'; // Path line character
                }
            }
            
            if (x == x2 && y == y2) break;
            
            int e2 = 2 * err;
            if (e2 > -dy) {
                err -= dy;
                x += sx;
            }
            if (e2 < dx) {
                err += dx;
                y += sy;
            }
        }
    }
};

// Function to display menu
void displayMenu() {
    cout << "\n======= GRAPH & A* PATHFINDER =======" << endl;
    cout << "1. Add Node" << endl;
    cout << "2. Add Edge" << endl;
    cout << "3. Display Graph (Text)" << endl;
    cout << "4. Visualize Graph (ASCII)" << endl;
    cout << "5. Find Shortest Path (A*)" << endl;
    cout << "6. Exit" << endl;
    cout << "====================================" << endl;
    cout << "Choose an option: ";
}

int main() {
    Graph graph;
    int choice;
    
    cout << "Welcome to Graph & A* Pathfinder!" << endl;
    cout << "This program allows you to create a graph and find shortest paths using A* algorithm." << endl;
    
    while (true) {
        displayMenu();
        cin >> choice;
        
        switch (choice) {
            case 1: {
                string nodeName;
                double x, y;
                
                cout << "\nEnter node name: ";
                cin >> nodeName;
                
                cout << "Enter x coordinate (for heuristic): ";
                cin >> x;
                
                cout << "Enter y coordinate (for heuristic): ";
                cin >> y;
                
                graph.addNode(nodeName, x, y);
                cout << "Node '" << nodeName << "' added successfully!" << endl;
                break;
            }
            
            case 2: {
                string from, to;
                double weight;
                
                // Display available nodes
                vector<string> nodes = graph.getAllNodes();
                if (nodes.empty()) {
                    cout << "No nodes available. Please add nodes first." << endl;
                    break;
                }
                
                cout << "\nAvailable nodes: ";
                for (const string& node : nodes) {
                    cout << node << " ";
                }
                cout << endl;
                
                cout << "Enter source node: ";
                cin >> from;
                
                if (!graph.nodeExists(from)) {
                    cout << "Source node doesn't exist!" << endl;
                    break;
                }
                
                cout << "Enter destination node: ";
                cin >> to;
                
                if (!graph.nodeExists(to)) {
                    cout << "Destination node doesn't exist!" << endl;
                    break;
                }
                
                cout << "Enter edge weight: ";
                cin >> weight;
                
                graph.addEdge(from, to, weight);
                break;
            }
              case 3: {
                graph.displayGraph();
                break;
            }
            
            case 4: {
                graph.visualizeGraph();
                break;
            }
            
            case 5: {
                string start, goal;
                
                // Display available nodes
                vector<string> nodes = graph.getAllNodes();
                if (nodes.empty()) {
                    cout << "No nodes available. Please add nodes first." << endl;
                    break;
                }
                
                cout << "\nAvailable nodes: ";
                for (const string& node : nodes) {
                    cout << node << " ";
                }
                cout << endl;
                
                cout << "Enter start node: ";
                cin >> start;
                
                if (!graph.nodeExists(start)) {
                    cout << "Start node doesn't exist!" << endl;
                    break;
                }
                
                cout << "Enter goal node: ";
                cin >> goal;
                
                if (!graph.nodeExists(goal)) {
                    cout << "Goal node doesn't exist!" << endl;
                    break;
                }
                
                graph.displayAStarResult(start, goal);
                break;
            }
              case 6: {
                cout << "Thank you for using Graph & A* Pathfinder!" << endl;
                return 0;
            }
            
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    }
    
    return 0;
}
