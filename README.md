# TragicCardGameinC

## Tragic The Card Game

Tragic The Card Game is a text-based card game where two players compete using decks of cards to attack, defend, and strategize to win the match.

### **Main Components:**
- **main.c**: The main entry point of the game. Manages the game loop, displays the menu, and handles player actions through user input.
- **gamelib.h**: Declarations of the data structures and functions used in the game, such as cards, players, and battlefields.
- **gamelib.c**: Implements the game logic, including card management, player attacks, drawing cards, and displaying the game state.


### **Prerequisites**

Ensure you have a C compiler installed (e.g., GCC).

### **Compiling the Game**

Navigate to the directory containing the files and run the following command to compile the game:

```gcc main.c gamelib.c -o tragic_game ```

### **Running the Game**
After compiling, run the game with the following command:

```./tragic_game```

### **Notes**
- Ensure all source files (main.c, gamelib.h, gamelib.c) are in the same directory.
- The game is text-based and runs entirely in the terminal.

This game was made as a university project and is an example of an interactive text-based game, useful for learning programming concepts such as data structure management, flow control, and user interaction.
