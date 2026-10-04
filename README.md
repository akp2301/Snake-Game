# 🐍 Snake Game

A classic **Snake Game implemented in C++** and played directly in the terminal. The project demonstrates object-oriented programming, real-time keyboard input, collision detection, game-state management, and dynamic game rendering using standard C++.

## 🎮 Overview

The objective is simple: control the snake, collect food, grow longer, and avoid colliding with obstacles or the snake's own body.

The game runs entirely in the terminal and uses keyboard input for real-time movement.

## ✨ Features

- 🐍 Classic Snake gameplay
- ⌨️ Real-time keyboard controls
- 🍎 Food spawning and collection
- 📈 Dynamic snake growth
- 💥 Self-collision detection
- 🧱 Boundary/obstacle collision detection
- 🏆 Score tracking based on snake length
- 🖥️ Terminal-based rendering
- 🧩 Object-oriented C++ design
- 🔨 Makefile-based compilation

The game loop continuously handles user input, updates the game state, checks collisions, and redraws the board.

## 🕹️ Controls

| Key | Action |
|---|---|
| `W` | Move Up |
| `A` | Move Left |
| `S` | Move Down |
| `D` | Move Right |

The game uses non-blocking keyboard input so movement can be controlled while the game is running.

## 🛠️ Tech Stack

- **Language:** C++
- **Build System:** GNU Make
- **Input:** Terminal keyboard input
- **Rendering:** ASCII / Unicode terminal characters
- **Data Structures:** `std::vector`
- **Concepts:** Object-Oriented Programming, game loops, collision detection, state management

## 📁 Project Structure

```text
Snake-Game/
│
├── main.cpp          # Application entry point
│
├── Game.cpp          # Main game loop and game mechanics
├── Game.h
│
├── Snake.cpp         # Snake movement and growth logic
├── Snake.h
│
├── Food.cpp          # Food positioning and respawning
├── Food.h
│
├── Obstacle.cpp      # Game board boundaries
├── Obstacle.h
│
├── Object.h          # Common object/position definitions
│
├── getch.h           # Character input utility
├── kbhit.h           # Non-blocking keyboard input utility
│
├── Makefile           # Build configuration
└── .gitignore
```

The repository is organized into separate classes for the game controller, snake, food, and board obstacles, keeping the game logic modular.

## 🧠 How It Works

### 1. Game Initialization

The `Game` class initializes the main game objects:

- Snake
- Food
- Board boundaries
- Game-over state

The initial game configuration creates a snake at `(5,5)`, food at `(10,5)`, and a `20 × 35` game board.

### 2. Game Loop

The game continuously executes three main operations:

```text
Handle Input
     ↓
Update Game State
     ↓
Render Board
     ↓
Repeat
```

The main loop continues until the game-over condition is triggered.

### 3. Snake Movement

The snake maintains a collection of positions representing its head and body.

When the snake moves:

1. Body segments follow the previous segment.
2. The head moves according to the current direction.
3. The board is redrawn with the updated positions.

A small delay is used between movements to control the game speed.

### 4. Food & Growth

When the snake's head reaches the food:

- The score increases as the snake grows.
- A new food position is randomly generated.
- A new segment is added to the snake.

Food is repositioned within the playable area of the board.

### 5. Collision Detection

The game checks for two primary collision conditions:

**Self Collision**

The snake's head is compared against its body. If they occupy the same position, the game ends.

**Boundary Collision**

The snake's head is checked against the board's obstacle positions. Hitting the boundary results in game over.

## 📊 Scoring

The score is based on the length of the snake:

```text
Score = Snake Length - 1
```

Each time food is consumed, the snake grows and the score increases.

## 🚀 Getting Started

### Prerequisites

You need:

- A C++ compiler such as `g++`
- GNU Make
- A Unix-like terminal environment

### Clone the Repository

```bash
git clone https://github.com/akp2301/Snake-Game.git
cd Snake-Game
```

### Build the Game

The project includes a Makefile that compiles the `.cpp` source files and produces an executable named `snake`.

Run:

```bash
make
```

### Run the Game

```bash
./snake
```

### Clean the Build

If you want to remove the generated executable and object files:

```bash
make clean
```

> **Note:** A `clean` target is not currently defined in the repository's Makefile. If you want to support `make clean`, you can add one.

## 🏗️ Architecture

The project follows a simple object-oriented architecture:

```text
                    ┌──────────────┐
                    │    main.cpp  │
                    └──────┬───────┘
                           │
                           ▼
                    ┌──────────────┐
                    │     Game     │
                    └──────┬───────┘
                           │
              ┌────────────┼────────────┐
              ▼            ▼            ▼
         ┌────────┐   ┌────────┐   ┌──────────┐
         │  Snake │   │  Food  │   │ Obstacle │
         └────────┘   └────────┘   └──────────┘
```

### `Game`

Responsible for:

- Game loop
- Input handling
- Game-state updates
- Collision detection
- Rendering
- Score display

### `Snake`

Responsible for:

- Snake position
- Direction
- Movement
- Body updates
- Growth

### `Food`

Responsible for:

- Food position
- Food repositioning

### `Obstacle`

Responsible for:

- Board dimensions
- Boundary positions

This separation keeps individual game responsibilities isolated and makes the code easier to extend.

## 🔮 Possible Improvements

Some ideas for extending the project:

- [ ] Add `make clean` to the Makefile
- [ ] Prevent the snake from reversing directly into itself
- [ ] Add multiple difficulty levels
- [ ] Add pause/resume functionality
- [ ] Add a high-score system
- [ ] Add levels with internal obstacles
- [ ] Improve cross-platform keyboard input
- [ ] Add colored terminal output
- [ ] Add a start/game-over menu
- [ ] Add sound effects
- [ ] Add automated tests for collision and movement logic
- [ ] Improve food placement so it cannot spawn on the snake

## 📚 Concepts Demonstrated

This project is a practical demonstration of:

- Object-Oriented Programming in C++
- Classes and inheritance
- Encapsulation
- Header/source file separation
- Enumerations
- Vectors and dynamic data structures
- Real-time input handling
- Game loops
- Collision detection
- Random number generation
- Terminal rendering
- Makefiles and compilation

## 📄 License

This project does not currently specify a license.

If you intend to make the repository open source, consider adding an appropriate license such as the MIT License.

---

### 👩‍💻 Author

**Aparna K P**

GitHub: [@akp2301](https://github.com/akp2301)

---

⭐ If you found this project interesting, feel free to explore the code and build your own version of the game!
