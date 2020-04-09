CXX = g++
CXXFLAGS = -Wall 

DragonWars: Dragon.o Game.o DragonWars.cpp
	$(CXX) $(CXXFLAGS) Dragon.o Game.o DragonWars.cpp -o DragonWars

Game.o: Dragon.o Game.cpp Game.h
	$(CXX) $(CXXFLAGS) -c Game.cpp

Dragon.o: Dragon.cpp Dragon.h
	$(CXX) $(CXXFLAGS) -c Dragon.cpp

clean:
	rm *.o*
	rm *~ 

run:
	./DragonWars
