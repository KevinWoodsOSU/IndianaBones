all:
	g++ -std=gnu++0x die.cpp human.cpp hole.cpp menu.cpp dog.cpp game.cpp indy.cpp animal.cpp board.cpp grass.cpp item.cpp main.cpp parkBoard.cpp space.cpp wall.cpp -o main


clean:
	rm main
