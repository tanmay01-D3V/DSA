# Data Structures and Algorithms

This folder is organized like the roadmap image: start with programming basics, then basic data structures, complexity, searching/sorting, trees, graphs, advanced structures, indexing, and problem-solving patterns.

Most learning content is in `.cpp` files. Empty folders are intentionally kept as placeholders for topics that are part of the roadmap but do not have code yet.

## How to revise from this folder

1. Read the folder name first; it tells you the concept family.
2. Open the `.cpp` file and read the comments before the code.
3. Compile one file at a time:

```bash
clang++ -std=c++17 path/to/file.cpp -o /tmp/dsa_demo
/tmp/dsa_demo
```

4. After understanding a file, rewrite the same algorithm from memory in a scratch file.

## Main Roadmap

- `00_Programming_Fundamentals` - syntax, control flow, pseudocode, functions, and OOP basics.
- `01_Basic_Data_Structures` - arrays, linked lists, queues, stacks, and hash tables.
- `02_Algorithmic_Complexity` - time/space complexity and common runtime classes.
- `03_Sorting_Algorithms` - bubble, insertion, selection, merge, quick, and heap sort.
- `04_Search_Algorithms` - linear search and binary search.
- `05_Graph_Data_Structures` - graph types, BFS/DFS, shortest paths, and MST algorithms.
- `06_Tree_Data_Structures` - binary trees, BSTs, traversals, heaps, AVL, and B-trees.
- `07_Advanced_Data_Structures` - trie, segment tree, Fenwick tree, DSU, and suffix structures.
- `08_Complex_Data_Structures` - 2-3 trees, B/B+ trees, skip lists, and ISAM.
- `09_Indexing` - linear and tree-based indexing.
- `10_Problem_Solving_Techniques` - brute force, backtracking, greedy, DP, two pointers, sliding window, and other patterns.
- `11_Platforms_To_Practice` - LeetCode and Edabit practice tracking.
- `99_Archive` - old compiled outputs and dated practice files kept for reference.

## Naming Convention

- Folder numbers show the suggested learning order.
- File names use lowercase words separated by underscores.
- Code comments focus on what to remember during revision: preconditions, core idea, and complexity.
