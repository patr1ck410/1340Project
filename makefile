FLAGS = -pedantic-errors -std=c++11
main : main.o action.o action.o checkwin.o dellist.o drawcard.o initialization.o insert.o loadandsave.o minigame.o output.o structures.o terminate.o
	g++ $^ -o $@

action.o : action.cpp action.h structures.h output.h
	g++ -c $<

checkwin.o : checkwin.cpp checkwin.h structures.h
	g++ -c $<

dellist.o : dellist.cpp dellist.h structures.h
	g++ -c $<

drawcard.o : drawcard.cpp drawcard.h structures.h
	g++ -c $<

initialization.o : initialization.cpp initialization.h structures.h
	g++ -c $<

insert.o : insert.cpp insert.h structures.h
	g++ -c $<

loadandsave.o : loadandsave.cpp loadandsave.h structures.h insert.h
	g++ -c $<

minigame.o : minigame.cpp minigame.h
	g++ -c $<

output.o : output.cpp output.h structures.h
	g++ -c $<

structures.o : structures.cpp structures.h
	g++ -c $<

terminate.o : terminate.cpp terminate.h
	g++ -c $<

main.o : main.cpp action.h checkwin.h dellist.h drawcard.h initialization.h insert.h loadandsave.h minigame.h output.h structures.h terminate.h
	g++ -c $<

clean:
	rm -f *.o main