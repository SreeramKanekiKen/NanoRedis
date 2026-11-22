# NanoRedis

**NanoRedis** is a Redis-inspired, in-memory key-value server implemented in C++. The project explores the internal building blocks of a lightweight data store, including data structures, request processing, networking, and concurrency.

Rather than relying on an existing database implementation, NanoRedis focuses on understanding how the underlying components of a key-value server work and how data structures and system design choices influence performance.

## Overview

NanoRedis is a systems programming project built to explore the design and implementation of a lightweight Redis-like server. It combines core data structures with server-side request handling and supporting utilities.

The project focuses on:

- Building an in-memory data store in C++
- Implementing data structures for efficient storage and retrieval
- Exploring server and client communication
- Understanding concurrency and thread management
- Organizing a systems-level application using modular components

## Architecture & Components

### Data Structures

NanoRedis implements and uses several fundamental data structures:

- **Hash Table** — Supports efficient key-based lookup and storage.
- **AVL Tree** — A self-balancing binary search tree for ordered data operations.
- **Heap** — Implements priority-based operations.
- **Sorted Set** — Combines elements with ordering-related functionality.
- **Linked List** — Provides list-based data organization and supporting operations.

### Server & Client

- **Server** — Handles the server-side functionality and request processing.
- **Client** — Provides a client-side interface for interacting with the server.

### Concurrency

- **Thread Pool** — Includes a thread-pool implementation to explore task execution and concurrency management.

## Tech Stack

- **Language:** C++
- **Build System:** CMake
- **Data Structures:** Hash Tables, AVL Trees, Heaps, Linked Lists
- **Systems Concepts:** Networking, Memory Management, Concurrency

## Project Structure

```text
NanoRedis/
├── server.cpp
├── client.cpp
├── common.h
├── hashtable.cpp
├── hashtable.h
├── avl.cpp
├── avl.h
├── heap.cpp
├── heap.h
├── list.h
├── zset.cpp
├── zset.h
├── thread_pool.cpp
├── thread_pool.h
├── test_cmds.py
├── test_heap.cpp
├── test_offset.cpp
├── testavl.cpp
└── CMakeLists.txt
```

## Building

### Prerequisites

- C++ compiler supporting the project's C++ standard
- CMake
- Git

### Clone the repository

```bash
git clone https://github.com/SreeramKanekiKen/NanoRedis.git
cd NanoRedis
```

### Configure and build

```bash
cmake -S . -B build
cmake --build build
```

The build configuration and generated executable targets are defined in `CMakeLists.txt`.

## Testing

The repository contains test files for validating individual data structures and functionality, including:

- Heap operations
- AVL tree operations
- Offset-related behavior
- Command-level testing

These tests provide a foundation for validating the correctness of the implemented components.

## Learning Objectives

This project provided an opportunity to explore:

- How in-memory key-value storage systems are structured
- The trade-offs between different data structures and their computational complexity
- The role of hashing in efficient key-based retrieval
- How ordered data structures support operations that require maintaining sorted information
- Server-side programming and client-server interaction
- Concurrency and thread-pool design

## Future Improvements

Potential extensions to NanoRedis include:

- Expanding command support
- Improving memory and execution efficiency
- Strengthening concurrency and request handling
- Adding more comprehensive automated tests
- Benchmarking data structures and server performance

## License

Please refer to the repository for licensing information.
