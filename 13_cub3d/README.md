
# Cube3D
42 group project done by [@nicolasgasco](https://github.com/nicolasgasco) and [@isolinis](https://github.com/isolinis). Small 3D video game inspired by _Wolfenstein 3D_ that leverages [raycasting](https://en.wikipedia.org/wiki/Ray_casting) to create a sense of tridimensionality. Written in C using 42's own graphical API [miniLibX](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html).

![screencast-nimbus-capture-2022_08_12-17_53_56_lqj089](https://user-images.githubusercontent.com/73175085/184505477-a271ac22-ed26-4a7a-bd68-f12efd6a4ced.gif)

## Project breakdown
The project roughly involved:
- Parsing and validating the scene description file passed as argument to the program, as shown in this example:
  ```
  // Textures according to orientation
  NO ./path_to_the_north_texture
  SO ./path_to_the_south_texture
  WE ./path_to_the_west_texture
  EA ./path_to_the_east_texture
  
  // Floor and ceiling colors
  F 220,100,0
  C 225,30,0
  
  // Map
  111111
  100001
  111111
  ```
- Transforming the data in a way that can be easily fed to the graphical API
- Doing the raycasting calculation to render the scene
- Adding player movement

## Features
- Customizable textures (XPM) that vary according to orientation (North, South, West, East)
- Customizable ceiling and floor colors
- Player movement (vertical with `W` and `S`, horizontal with `A` and `D`)
- View rotation with left and right arrow keys in mandatory (`src` folder) and by moving the mouse horizontally in bonus (`bonus` folder).

## Run the program (macOs only)
```
git clone https://github.com/nicolasgasco/42_cub3d.git
cd 42_cub3d

# For mandatory (player rotation with arrow keys)
make
./cub3D /maps/scene.cub

# For bonus (player rotation with mouse)
make bonus
./cub3D_bonus /maps/scene.cub
```
