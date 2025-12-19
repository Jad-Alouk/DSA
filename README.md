# Data Structures & Algorithms

A comprehensive collection of data structures and algorithms implemented from scratch in both C and Python, with performance benchmarking capabilities.

## 🎯 Overview

This repository showcases my understanding and implementation of fundamental data structures and algorithms. Each implementation is built from the ground up without relying on high-level libraries, demonstrating my current understanding of how these concepts work at a low level.

The project includes performance stress tests for each implementation, allowing for empirical analysis and comparison of algorithmic complexity across different input sizes.

## 📁 Repository Structure

```
DSA/
├── chad_c/          # C implementations
│   ├── test.c       # Stress testing suite
│   └── ...          # Data structure and algorithm implementations
├── virgin_python/   # Python implementations
│   ├── test.py      # Stress testing suite
│   └── ...          # Data structure and algorithm implementations
└── README.md
```

## 🔧 Implementations

### Data Structures

- **Heap** - Priority queue implementation with efficient insert and extract operations
- **Singly Linked List (SLL)** - Dynamic linear data structure with forward traversal
- **Doubly Linked List (DLL)** - Bidirectional linked list with efficient insertion/deletion
- **Adjacency List** - Graph representation for efficient edge storage (only in C)

### Algorithms

#### Sorting Algorithms

- **Bubble Sort** - O(n²) comparison-based sorting
- **Selection Sort** - O(n²) in-place sorting algorithm
- **Insertion Sort** - O(n²) efficient for small or nearly sorted data
- **Merge Sort** - O(n log n) divide-and-conquer sorting
- **Quick Sort** - O(n log n) partition-based sorting

#### Search Algorithms

- **Binary Search** - O(log n) search on sorted arrays

#### Graph Algorithms

- **Breadth-First Search (BFS)** - Level-order graph traversal
- **Depth-First Search (DFS)** - Deep exploration graph traversal

## 🚀 Getting Started

### Prerequisites

**For C implementations:**

- GCC compiler or equivalent

**For Python implementations:**

- Python 3.x

### Compilation & Execution

#### C Implementation

```bash
# Navigate to the C directory
cd chad_c

# Compile the test suite
gcc main.c helpers.c tests.c Algorithms/*.c Data_structures/*.c -o <output_file>

# Run stress tests
./<output_file> <test_name>
```

#### Python Implementation

```bash
# Navigate to the Python directory
cd virgin_python

# Run stress tests
python main.py <test_name>
```

## ⚡ Stress Testing

Each data structure and algorithm includes comprehensive stress tests to benchmark performance under various input sizes. The tests measure execution time and verify correctness.

### Running Tests

**Test Options:**

- `all` - Runs all available tests simultaneously
- `heap` - Tests heap operations
- `sll` - Tests singly linked list operations
- `dll` - Tests doubly linked list operations
- `sorting_algos` - Tests all available sorting algorithms
- `bs` - Tests binary search algorithm

### Test Input Sizes

Performance benchmarks are conducted with the following input sizes:

| Test               | C Implementation | Python Implementation |
| ------------------ | ---------------- | --------------------- |
| Heap               | 10,000,000       | 1,000,000             |
| Singly Linked List | 10,000           | 100,000               |
| Doubly Linked List | 10,000           | 100,000               |
| Bubble Sort        | 100,000          | 10,000                |
| Selection Sort     | 100,000          | 10,000                |
| Insertion Sort     | 100,000          | 10,000                |
| Merge Sort         | 100,000,000      | 10,000,000            |
| Quick Sort         | 10,000,000       | 10,000,000            |
| Binary Search      | 1,000,000,000    | 100,000,000           |

_Note: Input sizes vary between C and Python implementations to account for performance differences between compiled and interpreted languages._

### Example Usage

```bash
# Run all tests in C
./<output_file> all

# Run all tests in Python
python main.py all

# Run specific data structure test in C
./<output_file> heap

# Run specific data structure test in Python
python main.py heap

# Run sorting algorithm test in C
./<output_file> sorting_algos

# Run sorting algorithm test in Python
python main.py sorting_algos

# Run specific tests in C
./<output_file> heap sorting_algos

# Run specific tests in Python
python main.py heap sorting_algos
```

## 📊 Performance Insights

The varying input sizes across implementations reflect:

- The performance difference between compiled (C) and interpreted (Python) languages
- Algorithm complexity characteristics (O(n²) algorithms use smaller inputs than O(n log n))
- Practical memory constraints for large-scale testing

## 🛠️ Implementation Philosophy

- **From Scratch**: All implementations are built without using standard library data structures, demonstrating understanding of underlying mechanisms
- **Educational Focus**: Code is written with clarity and educational value in mind (and some memes)
- **Performance Aware**: While educational, implementations consider efficiency, memory constraints and best practices
- **Dual Implementation**: Both C and Python versions allow comparison of low-level vs high-level language characteristics

## 📝 Learning Journey

This repository represents my ongoing journey in mastering data structures and algorithms. Each implementation has been:

- Carefully researched and understood
- Implemented independently without copying code
- Tested extensively to ensure correctness
- Benchmarked to verify expected time complexity

## 🤝 Contributing

While this is a personal learning project, I'm open to suggestions and feedback. Feel free to open an issue if you notice any bugs or have suggestions for improvements.

## 📄 License

This project is open source and available for educational purposes.
