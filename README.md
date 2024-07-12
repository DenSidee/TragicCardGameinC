# TragicCardGameinC

### Tragic The Card Game

**Description:**
Tragic The Card Game is a text-based card game where two players compete using decks of cards to attack, defend, and strategize to win the match.

**Main Components:**
- **main.c**: The main entry point of the game. Manages the game loop, displays the menu, and handles player actions through user input.
- **gamelib.h**: Declarations of the data structures and functions used in the game, such as cards, players, and battlefields.
- **gamelib.c**: Implements the game logic, including card management, player attacks, drawing cards, and displaying the game state.

**Features:**
- **Game Setup**: Initializes the initial game state.
- **Deck and Hand Management**: Functions for drawing, adding, and removing cards.
- **Attack Logic**: Manages attacks between players.
- **Display**: Shows the current state of the players' hands and battlefields.

**Instructions:**
Compile the game using the following command:
```gcc main.c gamelib.c -o tragic_game```

This game was made as a university project and is an example of an interactive text-based game, useful for learning programming concepts such as data structure management, flow control, and user interaction.
