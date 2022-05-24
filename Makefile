output: main.o f1.o
	g++ main.o -o output

main.o: main.cpp
	g++ -c main.cpp

f1.o: f1.cpp f1.h
	g++ -c f1.cpp

clean:
	rm *.o output

# $ make
# $ ./output
# $ 