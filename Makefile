SRC=$(wildcard src/*.cpp)
outdir = out

all: | $(outdir) output
	@echo "Finished"

$(outdir):
	@echo "$(outdir) doesn't exist..."
	mkdir -p $@

output: out out/main.o out/precise.o
	g++ out/main.o out/precise.o -o ./calculator

out/main.o: src/main.cpp
	g++ -c src/main.cpp -o out/main.o

out/precise.o: src/precise.cpp src/header.h
	g++ -c src/precise.cpp -o out/precise.o

clean:
	rm -rf out calculator
