# FDF
## Project Overview
FDF is a 42 Project to learn about 3d programming. The program takes a map as parameter and creates its 3d representation.
* Render a 3D map from a 2D representation. Initially I was using vectors and simple formulas as illustrated by formula.c file. Later I switched to matrixes.
* You can rotate, increase altitude coefficient and zoom in/out. All transformations are done through matrixes transformations except for the one translating the picture.



## Mathematics And MiniLibX Sources 
Also many thanks to these very informative sites:
* https://www.scratchapixel.com/lessons/mathematics-physics-for-computer-graphics/geometry/spherical-coordinates-and-trigonometric-functions
* https://web.archive.org/web/20150225192611/http://www.arcsynthesis.org/gltut/index.html
* http://inside.mines.edu/fs_home/gmurray/ArbitraryAxisRotation/
* https://github.com/VBrazhnik/FdF/wiki
* https://github.com/keuhdall/images_example
* https://harm-smits.github.io/42docs/

## Installation
```
git clone https://github.com/Mohamed-Moumni/FDF.git
```
```
make 
./fdf ./test_maps/map.fdf
```
For Bonus Use This Rule
```
make bonus
./fdf ./test_maps/map.fdf
```
