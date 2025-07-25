# 🧾 Receipt Generator – Group 3 (C++ OOP Project)

A simple yet functional console-based receipt generator built using **C++** and **SQLite**. This project demonstrates core Object-Oriented Programming principles and fundamental programming concepts, while persisting data using an embedded relational database.

---

## 📌 Project Overview

This application simulates a small shop's point-of-sale system, allowing the user to:

* Set or retrieve shop details (name, phone, address) from a database.
* Dynamically add items to a customer's invoice.
* Print a well-structured receipt.
* Clear the invoice or update shop data interactively.

This is ideal for practicing:

* Fundamental programming principles: variables, control flow, functions, data structures.
* Object-Oriented Programming (OOP) concepts.
* File structure organization in C++.
* SQLite integration in C++ projects.

---

## 📁 File Structure

```
├── group-6-assignment-console.cpp  # Main application entry point
├── Database.h                  # Declaration of database initialization
├── Helpers.h                   # Utility functions (input, receipt printing, etc.)
├── Item.h                      # Base class and derived item types
├── Shop.h                      # Shop metadata management and persistence
└── README.md                   # This documentation
```

---

## 🔧 Setup & Installation

### Prerequisites

* Visual Studio 2019 or Later with Desktop development with c++ module installed

### Installation and Building Steps

```bash
# Clone this repository
git clone https://github.com/your-org/receipt-generator.git](https://github.com/ajedamilola/group-3-assignment-console
```
- Open Visual Studio 2019
- Select "Open Project or Solution"
- Navigate to Project folder and select the group-3-assignment-console.sln file
- After project is open; navigate to "Project"->"Manage Nuget Packages"
- you should see a message saying "Some packages are missing from this solution, Restore packages online" and a "Restore" button which you will click
- After successful package restoration you cna now proceed to build and run. simply by clicking run or pressing f5

Note: You only need to restore packages once


## ⚙️ How It Works – Summary

1. Store Setup

   * On first launch, the program initializes the SQLite database and attempts to load shop metadata.
   * If no data exists, the user is prompted to enter the shop name, address, and phone number. Data is saved for future sessions.

2. Add Products

   * Users enter product details: name, quantity, price, and optional description.
   * Each product is instantiated as an `InvoiceItem` object and added to a dynamic array (`std::vector`).

3. **Automatic Calculations

   * For each `InvoiceItem`, the program calculates `price × quantity` and accumulates a running total.

4. Formatted Receipt Display

   * A clear, structured receipt is printed to the console, showing all items, line subtotals, and grand total.

5. Optional Actions

   * `clear`: Reset the current invoice list.
   * `set-data`: Update shop metadata.
   * `exit`: Quit the application.

---

## 🧩 Problem Statement

Manual receipt processes in many small shops lead to:

* Error-Prone Calculations
* Difficulty Tracking Multiple Products
* Inconsistent, Unprofessional Receipts
* Time-Consuming Transactions
* Lack of Digital Records for Auditing

---

## 🎯 Why We Chose This Project

* Solves real-world challenges for small retailers.
* Reinforces key OOP principles and fundamental programming skills.
* Demonstrates integration with SQLite for persistent storage.
* Provides a scalable foundation for full-featured POS or inventory systems.

---

## 🧱 Fundamental Programming Concepts

1. Variables & Data Types

   * Use of built-in types (`int`, `float`, `std::string`) to store data.

2. Control Flow

   * `if`/`else if`/`else` statements for command handling.
   * Loops (`while`) for interactive user sessions.

3. Functions

   * Modular helper functions (`insertValue`, `printReceipt`, `collectShopDetails`) for clean separation of concerns.

4. Data Structures

   * Use of `std::vector<InvoiceItem>` for dynamic list management.

5. Error Handling

   * Checking return codes from SQLite operations.
   * Validating user input before object creation.

---

## 🧠 Object-Oriented Programming Concepts

### 1. Encapsulation

* Definition: Bundling data and methods operating on that data within classes, restricting direct access to some components.
* Example: The `Item` class declares `qty` as a private member and exposes public methods `setQty()`, `getQty()`, `incrementQty()`, and `decrementQty()` to safely manipulate quantity.

### 2. Inheritance

* Definition: Establishing new classes (derived) from existing ones (base) to reuse code and extend functionality.
* Example: `StoreItem` and `InvoiceItem` inherit from `Item`, reusing properties (`name`, `description`, `price`) and behavior (quantity management).

### 3. Abstraction

* Definition: Hiding complex implementation details and exposing only essential features.
* Example: The `Shop` class abstracts database interactions behind methods like `setDetails()` and `persistState()`, shielding the main logic from SQL command complexity.

### 4. Polymorphism (Foundation)

* Definition: Ability to treat objects of different derived classes uniformly through base class interfaces.
* Note: While runtime polymorphism via virtual functions isn't implemented, the class hierarchy allows easy future integration of polymorphic behavior (e.g., different receipt formats).

---

## 🔮 Future Improvements

* Implement runtime polymorphism for different item types or receipt layouts.
* Extend `InvoiceItem` with discount and tax fields.
* Add file export (TXT, PDF) or email functionality for receipts.
* Build a graphical interface (Qt, ImGui) on top of the core logic.

---

## 📜 License

This project is licensed under the **MIT License** — see [LICENSE](LICENSE) for details.
