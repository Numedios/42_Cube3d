# Cub3d-linux

![Cub3d presentation](image.png)

[**Subject :**](https://cdn.intra.42.fr/pdf/pdf/105492/fr.subject.pdf)

This project is inspired by the game Wolfenstein 3D. Wolfenstein 3D is considered the world's first FPS (first-person shooter).


- The objective is to create a dynamic view (which adapts over time according to the player's movements) and a subjective view (from the player's point of view) and subjective (we see from the point of view of the character's eyes)
- Within a labyrinth with a "realistic" 3D graphic representation, in which you have to find your way.
This project is an exploration of ray-casting (a rendering technique capable of creating a three-dimensional perspective from a two-dimensional map).

## Installation

**Building the program :**

```bash
  git clone https://github.com/Zheylkoss/Cube3d.git
  cd Cube3d
```

Running the program :

I add a file with maps you can use, these are fairly basic cards that you can modify. Files used as maps must consist of 0 and 1, and maps must be firm. In addition, files must have a '.cub' extension. The first 4 lines of information correspond to the textures of the South, North, East and West walls. Then we have the sky and ground colors.

```bash
  make && ./cub3D [map]
```


    
## Roadmap

- Parsing

- Use the Minilibx

- Make a Minimap

- Manage the key :
    
    Press escape to exit cleanly 

    Press left arrow: left rotation

    Press right arrow: right rotation

    Press A: move left

    Press D: move right

- Raycasting :

    Raycasting in "Wolfenstein 3D" involves emitting beams from the player's point of view through each column of the screen, to determine which walls are visible and how far away they are. The game then uses this information to draw the walls in perspective on the screen, creating a 3D impression from a world that is actually stored and calculated in 2D. This method enables fast, efficient rendering, making the game playable on less powerful hardware.


- positioning textures
