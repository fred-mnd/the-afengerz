output: hero.o gameController.o room.o gamePage.o utils.o actionController.o sleepPage.o timelineController.o trainingPage.o Training.o Sleep.o Upgrade.o timeline.o upgradePage.o eatPage.o Eat.o changeHeroPage.o Meeting.o meetingPage.o superheroController.o globals.o Nick.o nickController.o gameOverPage.o
	g++ hero.o gameController.o room.o gamePage.o utils.o actionController.o sleepPage.o timelineController.o trainingPage.o Training.o Sleep.o Upgrade.o timeline.o upgradePage.o eatPage.o Eat.o changeHeroPage.o Meeting.o meetingPage.o superheroController.o globals.o Nick.o nickController.o gameOverPage.o main.cpp -std=c++11 -pthread -o TheAFengerZ && ./TheAFengerZ

# MODEL
hero.o: model/heroes/Hero.cpp
	g++ -c model/heroes/Hero.cpp -std=c++11

room.o: model/map/Room.cpp
	g++ -c model/map/Room.cpp -std=c++11

timeline.o: model/timeline/Timeline.cpp
	g++ -c model/timeline/Timeline.cpp -std=c++11


# CONTROLLER
gameController.o: controller/sources/gameController.cpp
	g++ -c controller/sources/gameController.cpp -std=c++11

actionController.o: controller/sources/actionController.cpp
	g++ -c controller/sources/actionController.cpp -std=c++11

timelineController.o: controller/sources/timelineController.cpp
	g++ -c controller/sources/timelineController.cpp -std=c++11

superheroController.o: controller/sources/superheroController.cpp
	g++ -c controller/sources/superheroController.cpp -std=c++11

nickController.o: controller/sources/nickController.cpp
	g++ -c controller/sources/nickController.cpp -std=c++11


# SPACEBAR
Training.o: controller/spacebar/actions/activities/Training.cpp
	g++ -c controller/spacebar/actions/activities/Training.cpp -std=c++11

Sleep.o: controller/spacebar/actions/activities/Sleep.cpp
	g++ -c controller/spacebar/actions/activities/Sleep.cpp -std=c++11

Upgrade.o: controller/spacebar/actions/activities/Upgrade.cpp
	g++ -c controller/spacebar/actions/activities/Upgrade.cpp -std=c++11

Eat.o: controller/spacebar/actions/activities/Eat.cpp
	g++ -c controller/spacebar/actions/activities/Eat.cpp -std=c++11

Meeting.o: controller/spacebar/actions/activities/Meeting.cpp
	g++ -c controller/spacebar/actions/activities/Meeting.cpp -std=c++11

Nick.o: controller/spacebar/actions/activities/Nick.cpp
	g++ -c controller/spacebar/actions/activities/Nick.cpp -std=c++11


# VIEW
gamePage.o: view/sources/gamePage.cpp
	g++ -c view/sources/gamePage.cpp -std=c++11

sleepPage.o: view/sources/sleepPage.cpp
	g++ -c view/sources/sleepPage.cpp -std=c++11

trainingPage.o: view/sources/trainingPage.cpp
	g++ -c view/sources/trainingPage.cpp -std=c++11

upgradePage.o: view/sources/upgradePage.cpp
	g++ -c view/sources/upgradePage.cpp -std=c++11

eatPage.o: view/sources/eatPage.cpp
	g++ -c view/sources/eatPage.cpp -std=c++11

changeHeroPage.o: view/sources/changeHeroPage.cpp
	g++ -c view/sources/changeHeroPage.cpp -std=c++11

meetingPage.o: view/sources/meetingPage.cpp
	g++ -c view/sources/meetingPage.cpp -std=c++11

gameOverPage.o: view/sources/gameOverPage.cpp
	g++ -c view/sources/gameOverPage.cpp -std=c++11


# ETC
utils.o: etc/utils.cpp
	g++ -c etc/utils.cpp -std=c++11

globals.o: etc/globals.cpp
	g++ -c etc/globals.cpp -std=c++11

clean:
	rm *.o