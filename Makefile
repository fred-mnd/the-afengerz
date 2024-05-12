output: hero.o gameController.o room.o
	g++ hero.o gameController.o room.o main.cpp -std=c++11 -pthread -o TheAFengerZ && ./TheAFengerZ

hero.o: model/heroes/Hero.cpp
	g++ -c model/heroes/Hero.cpp

room.o: model/map/Room.cpp
	g++ -c model/map/Room.cpp
	
gameController.o: controller/sources/gameController.cpp
	g++ -c controller/sources/gameController.cpp

clean:
	rm *.o