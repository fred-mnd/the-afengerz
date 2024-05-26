output: hero.o gameController.o room.o gamePage.o utils.o actionController.o sleepPage.o timelineController.o trainingPage.o
	g++ hero.o gameController.o room.o gamePage.o utils.o actionController.o sleepPage.o timelineController.o trainingPage.o main.cpp -std=c++11 -pthread -o TheAFengerZ && ./TheAFengerZ

hero.o: model/heroes/Hero.cpp
	g++ -c model/heroes/Hero.cpp -std=c++11

room.o: model/map/Room.cpp
	g++ -c model/map/Room.cpp -std=c++11
	
gameController.o: controller/sources/gameController.cpp
	g++ -c controller/sources/gameController.cpp -std=c++11

actionController.o: controller/sources/actionController.cpp
	g++ -c controller/sources/actionController.cpp -std=c++11

timelineController.o: controller/sources/timelineController.cpp
	g++ -c controller/sources/timelineController.cpp -std=c++11
	
gamePage.o: view/sources/gamePage.cpp
	g++ -c view/sources/gamePage.cpp -std=c++11

sleepPage.o: view/sources/sleepPage.cpp
	g++ -c view/sources/sleepPage.cpp -std=c++11

trainingPage.o: view/sources/trainingPage.cpp
	g++ -c view/sources/trainingPage.cpp -std=c++11

utils.o: etc/utils.cpp
	g++ -c etc/utils.cpp -std=c++11

clean:
	rm *.o