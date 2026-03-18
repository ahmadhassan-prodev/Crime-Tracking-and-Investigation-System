**Crime Tracking and Investigation System**

A comprehensive C++ application demonstrating advanced data structures to manage criminal records, evidence, and suspect tracking with undo/redo capabilities.

**Overview**

This repository contains a **Crime Tracking and Investigation System** developed as a Data Structures semester project. It serves as a robust demonstration of how various non-linear and linear data structures can be integrated into a functional management system.

**Repository Purpose**

The primary goal of this repository is to showcase the practical implementation of core computer science algorithms and data structures. It simulates a real-world scenario where data must be prioritized (crimes), searched efficiently (suspects), and managed chronologically (investigation logs and evidence).

**Key Features & Concepts**

- **Case Management**: Registering and displaying crime cases using standard and priority-based ordering.
- **Priority-Based Investigation**: Processing crimes based on severity (High, Medium, Low) using a Priority Queue.
- **Efficient Searching**: Utilizing an AVL Tree for logarithmic time complexity when searching for suspects.
- **Evidence Linkage**: Managing a collection of evidence for each specific crime through nested Linked Lists.
- **Action History**: A complete Undo/Redo system implemented via Stacks to revert or repeat system actions.

**Technologies Used**

- **Language**: C++
- **Paradigm**: Object-Oriented Programming (OOP)
- **Data Structures**: AVL Tree, Priority Queue, Queue, Stack, and Linked List

**Project Structure**

Plaintext

Crime-Tracking-and-Investigation-System/

│

├── main.cpp # Application entry point and menu-driven logic

├── Crime.h # Crime class definition and evidence integration

├── Suspect.h # Suspect entity with personal details

├── Evidence.h # Evidence entity definition

├── Action.h # Action structure for undo/redo tracking

├── AVL.h # Self-balancing BST for suspect management

├── LinkedList.h # Template-based list for evidence storage

├── PriorityQueue.h # Priority-based crime processing logic

├── Queue.h # First-In-First-Out (FIFO) crime registration

├── Stack.h # Template-based stack for history management

└── README.md # Project documentation

**How the Code Works**

- **Registration**: When a crime is registered, it is added to a standard Queue for chronological tracking and a PriorityQueue for importance-based processing.
- **Suspect Management**: Suspects are stored in an AVL Tree organized by ID, ensuring the tree remains balanced for fast retrieval even as the database grows.
- **Evidence Tracking**: Each Crime object contains its own LinkedList of Evidence objects, creating a one-to-many relationship.
- **Undo/Redo Logic**: Every state-changing action (adding/deleting) is wrapped in an Action object and pushed onto an undoStack. When "Undo" is selected, the inverse operation is performed and the action moves to the redoStack.

**Usage**

**Compilation**

Use any standard C++ compiler (like G++):

Bash

g++ main.cpp -o CrimeSystem

**Execution**

Run the compiled executable:

Bash

./CrimeSystem

The system provides a numbered menu to register crimes, add evidence, search suspects, or manage investigation history.

**Learning Outcomes**

By studying this codebase, one can learn:

- How to implement **AVL Tree rotations** (LL, RR, LR, RL) to maintain balance.
- Practical application of **Template Classes** in C++ for reusable Stacks and Linked Lists.
- Managing complex data relationships (e.g., a Linked List inside a Queue Node).
- Implementing **State Management** using the Command Pattern (Undo/Redo functionality).
