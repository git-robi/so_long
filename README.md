# 🎮 so_long - A classic 2D Game 

Hey there! 👋 Welcome to my so_long project, where I created a 2D game using the MLX graphics library. Get ready for a cute adventure where you help a little character collect items and find their way to freedom!

## 🎯 What's This Project About?

This project challenged me to create a small 2D game where:
- 🎨 I had to work with a graphics library (MLX)
- 🗺️ Parse and validate map files
- 🎮 Handle player movement and interactions
- 🖼️ Manage sprites and animations
- 🎵 Create an engaging gaming experience

## 🎨 Game Features

### Map Elements:
- `P` Player - Our adorable protagonist
- `1` Walls - Can't walk through these!
- `0` Empty spaces - Free to move here
- `C` Collectibles - Gotta catch 'em all!
- `E` Exit - The way to freedom
- `X` Enemy - Watch out for these!

### Game Mechanics:
- Smooth player movement with WASD/Arrow keys
- Animated character sprites
- Collectible counting
- Move counter display
- Win/lose conditions
- Clean exit handling

## 🛠️ How I Built It

1. **Graphics Engine**:
   - Used MinilibX for rendering
   - Implemented sprite loading and display
   - Created smooth animations
   - Handled window management

2. **Map Management**:
   - Built a map parser for `.ber` files
   - Implemented map validation:
     - Rectangular shape check
     - Wall surroundings check
     - Required elements check
     - Valid path verification

3. **Game Logic**:
   - Player movement controls
   - Collision detection
   - Collectible tracking
   - Win/lose conditions
   - Score counting

4. **Memory Management**:
   - Proper resource allocation/deallocation
   - Sprite memory handling
   - Clean game exit

## 🎮 Game Design

I chose a black theme with cute sprites:
- Animated player character
- Distinctive wall textures
- Collectible items
- Door for exit
- Enemy obstacles
- Move counter with paw print design

## 🤔 The Tricky Parts

This project came with some interesting challenges:

1. **Graphics Programming**:
   - Learning MLX library
   - Managing window events
   - Handling sprite animations
   - Smooth rendering

2. **Game Logic**:
   - Path finding validation
   - Collision detection
   - Game state management
   - Event handling

3. **Map Validation**:
   - Implementing flood fill algorithm
   - Checking valid paths
   - Ensuring map completeness
   - Error handling

## 🎓 What I Learned

This project was a fantastic introduction to game development:

1. **Graphics Programming**:
   - Window management
   - Event handling
   - Sprite manipulation
   - Animation techniques

2. **Game Development**:
   - Game loop implementation
   - State management
   - User input handling
   - Collision detection

3. **Problem Solving**:
   - Map validation algorithms
   - Memory management
   - Error handling
   - Performance optimization

## 💡 How to Use It

```bash
# Compile the game
make

# Run with a map
./so_long maps/map.ber

# Controls:
# WASD or Arrow Keys - Move
# ESC - Exit game
# Collect all items before reaching the exit!
```

## 🗺️ Map Format
```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```
- Maps must be rectangular
- Surrounded by walls
- Have exactly one player and exit
- At least one collectible
- Have a valid path to win

### 🐛 Error Handling

The game handles various error cases:
- Invalid maps
- Missing files
- Memory allocation failures
- Invalid characters
- Window management errors

### 🎨 Assets
For my assets I chose a minimal back and white style. All game assets are custom-made and stored in the `textures/` directory:
- Player animations (walking left/right)
- Wall textures
- Collectible items
- Exit door (open/closed)
- Enemy sprites
- UI elements

## 🔍 Final Thoughts

Creating this game was an exciting journey into the world of game development! It taught me not just about graphics programming, but also about creating an engaging user experience. The combination of technical challenges and creative design made this project particularly enjoyable.

---
*Built with ❤️ and lots of coffee at 42 School*
