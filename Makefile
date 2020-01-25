CC = g++
exe_file = CrazyEights
$(exe_file): card.o deck.o hand.o player.o game.o prog.o
	$(CC) card.o deck.o hand.o player.o game.o prog.o -o $(exe_file)
card.o: card.cpp
	$(CC) -c card.cpp
deck.o: deck.cpp
	$(CC) -c deck.cpp
hand.o: hand.cpp
	$(CC) -c hand.cpp
player.o: player.cpp
	$(CC) -c player.cpp
game.o: game.cpp
	$(CC) -c game.cpp
prog.o: prog.cpp
	$(CC) -c prog.cpp
clean:
	rm -f *.out *.o $(exe_file)

