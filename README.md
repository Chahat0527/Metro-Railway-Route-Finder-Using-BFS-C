# Metro-Railway-Route-Finder-Using-BFS-C

📌 Problem Statement
Modern transportation systems consist of a large number of interconnected metro stations and railway cities. Finding the shortest route between two locations efficiently is a major challenge in transportation management systems.
Traditional manual route searching becomes difficult as the network grows in size and complexity. Therefore, there is a need for a system that can model transportation networks as graphs and automatically determine the shortest route between two locations.
This project addresses this challenge by implementing a Metro & Railway Route Finder using the Breadth First Search (BFS) algorithm in C, enabling efficient route discovery, network management, and transportation analysis.

🎯 Project Objective
The main objectives of this project are:
✅ Implement Graph Data Structure for transportation networks
✅ Find shortest routes using Breadth First Search (BFS)
✅ Simulate Metro and Railway transportation systems
✅ Dynamically add and remove stations
✅ Dynamically add and remove route connections
✅ Manage transportation networks through Admin access
✅ Provide route search functionality for users
✅ Demonstrate memory management concepts
✅ Demonstrate structure padding optimization
✅ Implement logging and performance monitoring
✅ Develop a modular and scalable C application

💡 Proposed Solution
The solution models the transportation network as a graph:
Stations/Cities → Vertices
Routes/Connections → Edges
The system contains two major user roles:

👨‍💼 Admin
The administrator manages the transportation network.
Functions include:
1. Add Metro Stations
2. Add Railway Stations
3. Add Connections
4. Remove Connections
5. Remove Stations
6. Save Network
7. Load Network
8. View Network

👨‍💻 User
The user can:
1. Find shortest route
2. View alternate routes
3. View available trains
4. Explore transportation networks
The BFS algorithm is used to determine the shortest path between source and destination nodes.

🔍 Algorithm Used
Breadth First Search (BFS)
Breadth First Search is the core algorithm used in this project.
Why BFS?
✅ Guarantees shortest path in an unweighted graph
✅ Efficient for transportation networks
✅ Explores all neighboring stations level-by-level
✅ Simple and memory-efficient implementation

BFS Working:
1. Start from source station
2. Visit all adjacent stations
3. Mark visited stations
4. Store stations in queue
5. Continue until destination is reached
6. Reconstruct shortest path

📊 Data Structures Used
1. Graph (Adjacency List)
Used to represent transportation networks.
Each station/city is represented as a vertex.
Each route is represented as an edge.
Example:
1. Delhi ── Nagpur
2. Nagpur ── Hyderabad
3. Hyderabad ── Chennai
 
2. Queue
Used by BFS traversal.
Operations:
1. Enqueue
2. Dequeue
3. IsEmpty
 
Queue enables level-wise traversal of stations.

3. Structures
Used for:
1. Station Information
2. Graph Representation
3. Train Information
4. Queue Management
5. Memory Statistics
