# AI Lab Assignments - C++ Implementations

This repository contains C++ implementations of fundamental Artificial Intelligence algorithms, ranging from search strategies and constraint satisfaction problems to logic and game theory.

## Table of Contents
1. [Assignment 1: 8-Puzzle Solver](#assignment-1-8-puzzle-solver-bfs--dfs)
2. [Assignment 2: Map Coloring (CSP)](#assignment-2-map-coloring-csp)
3. [Assignment 2.1: Sudoku Solver](#assignment-21-sudoku-solver)
4. [Assignment 3: Family Tree Knowledge Base](#assignment-3-family-tree-knowledge-base)
5. [Assignment 4: A* Pathfinding](#assignment-4-a-pathfinding)
6. [Assignment 5: Tic-Tac-Toe AI](#assignment-5-tic-tac-toe-ai-minimax)
7. [Assignment 6: N-Queens Problem](#assignment-6-n-queens-problem)
8. [Assignment 7: Forward Chaining](#assignment-7-forward-chaining)
9. [Assignment 8: Backward Chaining](#assignment-8-backward-chaining)

---

## Assignment 1: 8-Puzzle Solver (BFS & DFS)
**File:** `assignment1.cpp`

### Description
Solves the sliding tile puzzle to reach the goal state `[1, 2, 3, 4, 5, 6, 7, 8, 0]`. It first calculates inversion counts to determine if the puzzle is solvable.
* **Breadth-First Search (BFS):** Explores level by level to find the shortest path.
* **Depth-First Search (DFS):** Explores deep into one branch before backtracking.

### Technical Details
* **Algorithm:** Uninformed Search (BFS and DFS).
* **Data Structures:** * `std::queue` (for BFS frontier)
    * `std::stack` (for DFS frontier)
    * `std::map` (to track parent nodes for path reconstruction)
    * `std::set` (to track visited states)
* **Time Complexity:** O(b^d) where *b* is branching factor and *d* is depth.
* **Space Complexity:** O(b^d) for BFS (high memory), O(d) for DFS (low memory).

---

## Assignment 2: Map Coloring (CSP)
**File:** `assignment2.cpp`

### Description
Solves a Constraint Satisfaction Problem (CSP) where regions on a map (graph nodes) must be colored such that no two adjacent regions share the same color.

### Technical Details
* **Algorithm:** Backtracking.
* **Data Structures:** * Adjacency List (Graph representation using `vector<vector<int>>`)
    * `vector<int>` (Assignment array)
* **Time Complexity:** O(m^n) (Exponential) where *m* is colors and *n* is regions.
* **Space Complexity:** O(n) for recursion stack.

---

## Assignment 2.1: Sudoku Solver
**File:** `assignment2_1.cpp`

### Description
Fills a 9x9 grid with digits 1-9. It enforces three constraints: unique numbers in every row, every column, and every 3x3 subgrid.

### Technical Details
* **Algorithm:** Backtracking (CSP).
* **Data Structures:** * 2D Array `int grid[9][9]`
* **Time Complexity:** O(9^m) where *m* is the number of empty cells (worst case).
* **Space Complexity:** O(m) for recursion stack.

---

## Assignment 3: Family Tree Knowledge Base
**File:** `assignment3.cpp`

### Description
A simple knowledge representation system that defines parent-child relationships and allows querying for children or siblings of a specific person.

### Technical Details
* **Algorithm:** Dictionary Lookup.
* **Data Structures:** * `std::map<string, vector<string>>` (Parent -> Children)
    * `std::map<string, string>` (Child -> Parent)
* **Time Complexity:** O(1) or O(log N) for lookups.
* **Space Complexity:** O(N) to store relationships.

---

## Assignment 4: A* Pathfinding
**File:** `assignment4.cpp`

### Description
Finds the optimal path in a grid environment from a start point to a goal point using the Manhattan distance heuristic function (`f = g + h`).

### Technical Details
* **Algorithm:** A* Search (Informed Search).
* **Data Structures:** * `priority_queue` (Min-heap for open list)
    * `std::set` (Closed list/visited nodes)
    * `struct Node` (Stores coordinates and f, g, h scores)
* **Time Complexity:** O(b^d) (worst case), but generally faster than BFS due to heuristic pruning.
* **Space Complexity:** O(b^d) (stores all generated nodes).

---

## Assignment 5: Tic-Tac-Toe AI (Minimax)
**File:** `assignment5.cpp`

### Description
An unbeatable Tic-Tac-Toe agent. It simulates all possible future moves to choose the one that maximizes the AI's score while minimizing the human player's score.

### Technical Details
* **Algorithm:** Minimax (Adversarial Search).
* **Data Structures:** * 2D Array `char board[3][3]`
    * Recursion Stack
* **Time Complexity:** O(b^d) (For Tic-Tac-Toe, b approx 9, d=9, so ~9!).
* **Space Complexity:** O(d) (Depth of game tree).

---

## Assignment 6: N-Queens Problem
**File:** `assignment6.cpp`

### Description
Places N chess queens on an NxN board so that no two queens attack each other (no shared row, column, or diagonal).

### Technical Details
* **Algorithm:** Backtracking.
* **Data Structures:** * 2D Vector `board`
* **Time Complexity:** O(N!) (Factorial).
* **Space Complexity:** O(N^2) for board storage + O(N) for recursion.

---

## Assignment 7: Forward Chaining
**File:** `assignment7.cpp`

### Description
A data-driven inference engine. It starts with known facts and iteratively applies rules (`IF A THEN B`) to infer new facts until a specific goal is reached.

### Technical Details
* **Algorithm:** Forward Chaining.
* **Data Structures:** * `struct Rule` (Antecedents -> Consequent)
    * `std::set` (To store unique facts)
* **Time Complexity:** O(R * F) where R is rules and F is facts.
* **Space Complexity:** O(F).

---

## Assignment 8: Backward Chaining
**File:** `assignment8.cpp`

### Description
A goal-driven inference engine. It starts with a hypothesis (goal) and works backward, looking for rules that support the goal, recursively verifying their conditions.

### Technical Details
* **Algorithm:** Backward Chaining (DFS-style logic).
* **Data Structures:** * `struct Rule`
    * `std::set` (To prevent infinite loops/cycles)
* **Time Complexity:** O(R^d) (Exponential in depth of reasoning).
* **Space Complexity:** O(d) for recursion.

---

## compilation
All files can be compiled using a standard C++ compiler (e.g., g++).

```bash
g++ assignment1.cpp -o assign1
./assign1
