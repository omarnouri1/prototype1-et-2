prog: Main.o ennemi.o minimap.o
	gcc Main.o ennemi.o minimap.o  -lSDL -lSDL_image -lSDL_ttf -o prog
Main.o:Main.c
	gcc -lSDL -lSDL_image -lSDL_ttf -c Main.c -w

ennemi.o:ennemi.c
	gcc -lSDL -lSDL_image -lSDL_ttf -c ennemi.c -w
minimap.o:minimap.c
	gcc -lSDL -lSDL_image -lSDL_ttf -c minimap.c -w
