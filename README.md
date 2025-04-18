# Leetcode-399.-Evaluate-Division
# 📐 Equation Evaluator with Graph Search (C++)

This project solves the **Evaluate Division** problem using **graph traversal**. Given a list of equations and their results, it computes the result of various division queries using **Depth-First Search (DFS)**.

---

## 📊 Problem Description

You are given equations like `A / B = k`, and must answer queries such as `C / D = ?`. If the path exists in the graph built from the equations, return the calculated value; otherwise, return `-1.0`.

---

## 🚀 Features

- Converts equations into a **bidirectional weighted graph**
- Supports chained and reverse equations
- Efficiently resolves queries using **DFS traversal**
- Handles edge cases like:
  - Variables not present
  - Querying the same variable (e.g., `A / A`)

---

## 🧠 How It Works

1. **Graph Construction**  
   Each equation adds two directed edges:
   - `A → B` with weight `k`
   - `B → A` with weight `1/k`

2. **Query Resolution**  
   For each query, the algorithm:
   - Uses DFS to find a path between nodes
   - Multiplies the weights along the path to compute the result

---

## 🛠️ Technologies

- **Language**: C++
- **Algorithm**: Depth-First Search
- **Data Structures**: Hash maps, vectors, pairs

---

## 📦 Usage

### Input Format

```cpp
vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}};
vector<double> values = {2.0, 3.0};
vector<vector<string>> queries = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
Output
vector<double> result = {6.0, 0.5, -1.0, 1.0, -1.0};
