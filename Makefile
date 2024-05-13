output: hero.o gameController.o room.o gamePage.o
	g++ hero.o gameController.o room.o gamePage.o main.cpp -std=c++11 -pthread -o TheAFengerZ && ./TheAFengerZ

hero.o: model/heroes/Hero.cpp
	g++ -c model/heroes/Hero.cpp -std=c++11

room.o: model/map/Room.cpp
	g++ -c model/map/Room.cpp -std=c++11
	
gameController.o: controller/sources/gameController.cpp
	g++ -c controller/sources/gameController.cpp -std=c++11

gamePage.o: view/sources/gamePage.cpp
	g++ -c view/sources/gamePage.cpp -std=c++11

clean:
	rm *.o