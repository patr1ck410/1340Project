FLAGS = -pedantic-errors -std=c++11
main : main.o initialization.o
	g++ $^ -o $@

initialization.o : initialization.cpp initialization.h
	g++ -c $<

main.o : main.cpp initialization.h
	g++ -c $<


clean:
	rm -f *.o main