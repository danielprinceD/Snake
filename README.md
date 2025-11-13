# 🐍 Auto Snake Game (C)

A **C-based console Snake game** where the snake **automatically moves toward food** without any keyboard input. Each time the snake eats, it grows longer. The game runs entirely in the terminal using simple text graphics.

---

## 🧩 Overview

This version of Snake is designed as a **simulation** rather than a manual game — the snake automatically detects and moves toward food positions.  
It visually displays the snake, fence boundaries, and food using **Unicode emojis**.

---

## ⚙️ Features

- Fully written in **C** (uses `stdio.h`, `stdlib.h`, `stdbool.h`, `unistd.h`, `time.h`, and `ncurses.h`)
- **Automatic food detection and movement**
- Snake grows automatically when food is eaten
- Random food generation within the boundary
- Simple text-based interface using Unicode symbols
- Adjustable speed, grid size, and snake length
- Cross-platform support (Linux/macOS terminal recommended)

---

## 🕹️ How It Works

1. The game area (grid) is drawn using ASCII borders (`-` and `|`).
2. The snake is represented with:
   - `⚰️` for body parts  
   - `🕺` when the snake eats food
3. The food is shown as `✝️`.
4. The snake **automatically moves** toward the nearest food:
   - It compares its `x` and `y` coordinates with the food’s coordinates.
   - It moves one step in the direction of the food each iteration.
5. Once the snake reaches the food:
   - It grows in size.
   - A new food position is generated randomly.
6. The board updates after each move with a short delay.

---

## 🔧 Configuration

Inside the code, the following constants can be modified:

| Variable | Description | Default |
|-----------|--------------|----------|
| `HEIGHT` | Number of grid rows | 20 |
| `LENGTH` | Number of grid columns | 40 |
| `MAXSIZE` | Maximum snake length | 200 |
| `INITIAL` | Initial snake size | 1 |
| `sleep_ms(200)` | Snake movement speed (milliseconds) | 200 |

You can increase `HEIGHT` or `LENGTH` for a larger board, or adjust the sleep time for faster/slower snake motion.

---

## 📁 File Structure

```
auto-snake/
├── snake.c      # Main game file
├── README.md    # Project documentation
```

---

## 🧠 Logic Flow

1. **Initialization**
   - Sets up random seed.
   - Creates an initial snake with one segment.
   - Spawns a random food location.

2. **Game Loop**
   - Draws the fence and snake on the board.
   - Moves the snake toward the food automatically.
   - If food is reached, increases snake size and respawns new food.
   - Clears the screen and repeats.

3. **Termination**
   - The game currently runs indefinitely until manually stopped (e.g., pressing `Ctrl + C`).

---

## 🧱 Symbols Used

| Symbol | Meaning |
|---------|----------|
| `-` / `|` | Fence boundary |
| `⚰️` | Snake body |
| `🕺` | Snake head / Eating |
| `✝️` | Food |
| *(space)* | Empty cell |

---

## 🚀 Compilation and Execution

### On Linux / macOS
```bash
gcc snake.c -o snake -lncurses
./snake
```

If `ncurses` is not installed:
```bash
sudo apt install libncurses5-dev libncursesw5-dev
```

or for macOS:
```bash
brew install ncurses
```

> The game clears and redraws the console after every move using `system("clear")`, so a terminal environment is required.

---

## 🧩 Example Output

```
----------------------------------------
|                                      |
|        ✝️                            |
|      ⚰️⚰️⚰️⚰️⚰️⚰️⚰️⚰️⚰️⚰️             |
|                                      |
|                                      |
----------------------------------------
```

The snake automatically grows and moves toward the food.

---

## 💡 Possible Improvements

- Add collision detection for self and walls.
- Display score and snake length.
- Implement a game-over screen.
- Use ncurses windows for better performance.
- Add manual control (optional).
- Save high scores to a file.

---

## 🧑‍💻 Author

**Daniel Prince**  
C Developer | Game Logic Designer

---

## 🪪 License

This project is open-source under the **MIT License** — feel free to modify and share.
