# 📈 Stock Portfolio Management System

A console-based **Stock Portfolio Manager** built in **C++** using core Object-Oriented Programming principles and file handling. Designed as a practical demonstration of OOP concepts including inheritance, polymorphism, and encapsulation.

---

## 🧠 Concepts Demonstrated

| Concept | Implementation |
|---|---|
| **Abstraction** | `Asset` base class defines a common interface |
| **Inheritance** | `Stock` extends `Asset` |
| **Polymorphism** | `display()` and `toString()` are overridden virtually |
| **Encapsulation** | Private/protected members with controlled access |
| **File Handling** | Persistent storage using `fstream` (append & read) |

---

## 🗂️ Project Structure

```
stock-portfolio-manager/
│
├── main.cpp          # Full source code
├── portfolio.txt     # Auto-generated data file (created on first save)
└── README.md
```

---

## 🏗️ Class Design

```
Asset  (Base Class)
  └── Stock  (Derived Class)

PortfolioManager  (File Handler)
```

### `Asset` — Base Class
- Holds `name` and `value`
- Virtual methods: `display()`, `toString()`

### `Stock` — Derived Class
- Inherits from `Asset`
- Adds `ticker` symbol
- Overrides `display()` and `toString()` for stock-specific formatting

### `PortfolioManager` — File Manager
- Handles all file I/O
- `saveAsset(Asset*)` — appends a record to `portfolio.txt`
- `loadAssets()` — reads and prints all saved records

---

## ▶️ How to Run

### Prerequisites
- A C++ compiler (g++, clang++, or MSVC)
- C++11 or later

### Compile & Run

```bash
# Compile
g++ -o portfolio main.cpp

# Run
./portfolio
```

> On Windows: `portfolio.exe`

---

## 💻 Usage

```
1. Add Stock
2. View Portfolio
3. Exit
Enter Choice: 1

Enter Ticker: AAPL
Enter Name: Apple Inc.
Enter Price: 189.50
Data saved to file!
```

The portfolio is saved persistently in `portfolio.txt`:

```
STOCK,AAPL,Apple Inc.,189.500000
STOCK,TSLA,Tesla Inc.,245.300000
```

---

## 🔮 Possible Enhancements

- [ ] Add `MutualFund` and `ETF` derived classes
- [ ] Implement delete/update operations on records
- [ ] Calculate total portfolio value
- [ ] Add buy/sell quantity tracking
- [ ] Export portfolio as CSV

---

## 📚 Built With

- **Language:** C++
- **Standard:** C++11
- **I/O:** `fstream`, `iostream`
- **Paradigm:** Object-Oriented Programming

---

## 👨‍💻 Author

Built as a C++ OOP learning project covering inheritance, polymorphism, and file handling.
