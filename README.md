# ⚔️ Fantasy Arena

A modular turn-based battle game developed in **C++** that demonstrates advanced **Object-Oriented Programming (OOP)** concepts including inheritance, polymorphism, composition, aggregation, operator overloading, file handling, and modular software design.

Players create powerful fantasy characters and engage in strategic battles across different arenas while utilizing unique abilities, environmental effects, and tactical decision-making.

---

## 🎮 Overview

Fantasy Arena is a console-based battle simulator where players select different character classes and compete in turn-based combat. Each character possesses unique abilities and statistics that influence battle outcomes.

The project was developed to demonstrate practical implementation of OOP concepts through a real-world game scenario.

---

## ✨ Features

### 🧙 Character System

* Abstract Character base class
* Multiple character types:

  * Warrior
  * Mage
  * Archer
* Unique special abilities
* Character statistics management
* Polymorphic battle actions

### 🏟️ Arena System

* Multiple battle environments
* Environmental buffs and debuffs
* Dynamic battle conditions
* Strategic arena selection

### ⚔️ Battle Mechanics

* Turn-based combat
* Attack and defense calculations
* Special ability system
* Health management
* Victory determination

### 📖 Battle Logging

* Detailed battle history
* Move-by-move logging
* Ability usage tracking
* Battle outcome records

### ➕ Operator Overloading

* `+` Operator for combo attacks
* `==` Operator for character comparison
* `<<` Operator for displaying character details

### ⚙️ Configuration System

* Centralized game settings through Config.h
* Easily customizable gameplay parameters

---

## 🧩 OOP Concepts Implemented

| Concept              | Implementation                         |
| -------------------- | -------------------------------------- |
| Abstraction          | Abstract Character class               |
| Inheritance          | Warrior, Mage, Archer classes          |
| Polymorphism         | Virtual battle functions               |
| Composition          | GameManager controls game systems      |
| Aggregation          | Arena manages participating characters |
| Operator Overloading | Custom game mechanics                  |
| Encapsulation        | Character and arena management         |

---

## 📂 Project Structure

```text
Fantasy-Arena/
│
├── Character.h
├── Character.cpp
│
├── Arena.h
├── Arena.cpp
│
├── GameManager.h
├── GameManager.cpp
│
├── Config.h
│
├── main.cpp
│
├── battleLog.txt
├── OUTPUT.png
│
└── README.md
```

### File Description

* **Character.h / Character.cpp** → Character hierarchy and special abilities.
* **Arena.h / Arena.cpp** → Arena creation and environmental effects.
* **GameManager.h / GameManager.cpp** → Game flow, battles, and player management.
* **Config.h** → Centralized game settings and constants.
* **main.cpp** → Entry point and game execution.
* **battleLog.txt** → Battle history and gameplay logs.
* **OUTPUT.png** → Sample gameplay output.

---

## 🛠 Technologies Used

* C++
* Object-Oriented Programming
* File Handling
* Operator Overloading
* Dynamic Memory Management

---

## 🚀 Learning Outcomes

This project demonstrates:

* Inheritance and Polymorphism
* Abstraction and Encapsulation
* Composition and Aggregation
* Operator Overloading
* Modular Software Design
* File Handling
* Turn-Based Game Development

---

## ▶️ How to Run

### Compile

```bash
g++ main.cpp Character.cpp Arena.cpp GameManager.cpp -o FantasyArena
```

### Execute

```bash
./FantasyArena
```

For Visual Studio:

1. Create a C++ Console Project.
2. Add all `.cpp` and `.h` files.
3. Build and Run the project.

---

## 📌 Project Highlights

* Fully modular architecture
* Multiple playable character classes
* Strategic turn-based gameplay
* Arena-based battle modifiers
* Battle logging system
* Extensive use of OOP principles
* Operator overloading implementation

---

## 🎓 Academic Information

**Course:** Object-Oriented Programming

**Project Title:** Fantasy Arena

**Language:** C++

**Type:** Console-Based Battle Game

**Institution:** FAST National University of Computer and Emerging Sciences

---

## 👨‍💻 Author

**Muhammad Hamza Afzaal**

BS Computer Science

FAST National University of Computer and Emerging Sciences

---

## 📜 License

This project was developed for academic and educational purposes.
