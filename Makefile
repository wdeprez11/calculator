
output: main.o precise.o
	g++ main.o precise.o -o output

main.o: main.cpp
	g++ -c main.cpp

message.o: precise.cpp header.h
	g++ -c precise.cpp

clean:
	rm *.o output
