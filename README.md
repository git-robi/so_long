# 🎮 so_long - A classic 2D Game 

Hey there! Welcome to my so_long project, where I created a 2D game using the MLX graphics library. Get ready for a cute adventure where you help a little character (my dog) collect items and find their way to freedom!

## What's This Project About?

This project challenged me to create a small 2D game where:
- I had to work with a graphics library (MLX)
- Parse and validate map files
- Handle player movement and interactions
- Manage sprites and animations
- Create an engaging gaming experience

## Game Features

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

## Visual Design and Implementation

For my game's visual identity, I carefully crafted a minimalist black theme enhanced by charming sprite designs. I created an animated player character that brings personality to the gameplay, set against distinctive wall textures that define the game space. To engage players, I designed collectible items that stand out against the background and implemented a dynamic exit door that responds to game state. I added enemy obstacles to create challenge, and topped it off with a custom move counter featuring a playful paw print design that adds character to the UI.

## The Tricky Parts

Creating this game pushed me to overcome several technical hurdles that expanded my programming expertise.

### Graphics Programming Journey
My first major challenge was mastering the MLX library. I spent considerable time learning its intricacies, from basic window management to handling complex event systems. Through persistent experimentation, I achieved smooth sprite animations and fluid rendering that brings the game world to life. Each frame update and animation transition taught me valuable lessons about graphics programming optimization.

### Game Logic Architecture
Implementing the core gameplay mechanics required careful planning and execution. I developed a robust pathfinding validation system to ensure levels are completable, while my collision detection implementation maintains precise game physics. The state management system I designed handles everything from collectible tracking to win conditions, creating a seamless player experience.

### Map System Design
One of my proudest achievements was implementing the flood fill algorithm for map validation. This system ensures that every level is not only properly constructed but also completable. I developed comprehensive error checking that validates map files, ensuring proper wall enclosure, reachable objectives, and overall map integrity. When errors are found, my system provides clear feedback to help with level design.

## 🎓 What I learned 

This project served as my gateway into game development, teaching me valuable lessons across multiple domains.

### Graphics Engine Expertise
Working with the MLX library gave me hands-on experience with fundamental graphics programming concepts. I mastered window management, event handling, and sprite manipulation techniques. Implementing smooth animations taught me about frame timing and buffer management, skills that are essential for any graphics application.

### Game Development Fundamentals
I gained practical experience implementing core game development concepts. Creating a robust game loop, managing game state, and handling user input taught me how to maintain responsive gameplay. The collision detection system I developed deepened my understanding of spatial relationships in 2D games.

### Problem-Solving Growth
Each challenge in this project pushed me to develop more efficient solutions. From optimizing the map validation algorithms to managing memory usage, I learned to balance performance with maintainability. The experience taught me to approach complex problems systematically, breaking them down into manageable components while maintaining clean, efficient code.

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

## Map Format
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

### Error Handling

The game handles various error cases:
- Invalid maps
- Missing files
- Memory allocation failures
- Invalid characters
- Window management errors

### Assets
For my assets I chose a minimal back and white style. All game assets are custom-made and stored in the `textures/` directory:
- Player animations (walking left/right)
- Wall textures
- Collectible items
- Exit door (open/closed)
- Enemy sprites
- UI elements

## Final Thoughts

Creating this game was an exciting journey into the world of game development! It taught me not just about graphics programming, but also about creating an engaging user experience. The combination of technical challenges and creative design made this project particularly enjoyable.

---
*Built with ❤️ and lots of coffee at 42 School*
