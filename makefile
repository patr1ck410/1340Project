FLAGS = -pedantic-errors -std=c++11
main : main.o action.o initialization.o insert.o loadandsave.o structures.o
	g++ $^ -o $@

action.o : action.cpp action.h
	g++ -c $<

initialization.o : initialization.cpp initialization.h
	g++ -c $<

insert.o : insert.cpp insert.h
	g++ -c $<

loadandsave.o : loadandsave.cpp loadandsave.h
	g++ -c $<

structures.o : structures.cpp structures.h
	g++ -c $<


main.o : main.cpp initialization.h insert.h loadandsave.h structures.h
	g++ -c $<

clean:
	rm -f *.o main