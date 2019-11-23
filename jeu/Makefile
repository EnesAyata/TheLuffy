SRC=main.c menu.c fonctions_sdl.c collision.c personnage.c
HEADERS=fonctions_sdl.h world.h menu.h collision.h personnage.h
BIN=jeu

LIBS=-
$(BIN): $(SRC) $(HEADERS) 
	gcc -Wall -g  -std=c99 $(SRC) -lm `sdl2-config --cflags --libs` -lSDL2_mixer -lSDL2_ttf -lSDL2_image -o $(BIN)

clean:
	rm -f $(BIN)
