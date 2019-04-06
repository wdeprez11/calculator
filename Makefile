SRC=$(wildcard src/*.cpp)
outdir = out

all: | $(outdir) output
	@echo "Finished"

$(outdir):
	@echo "$(outdir) doesn't exist..."
	mkdir -p $@

output: out main.o precise.o
	g++ out/main.o out/precise.o -o ./calculator

main.o: src/main.cpp
	g++ -c src/main.cpp -o out/main.o

precise.o: src/precise.cpp src/header.h
	g++ -c src/precise.cpp -o out/precise.o

docs: $(SRC) doc/Doxyfile
	doxygen doc/Doxyfile

clean:
	rm -rf out calculator doc/html
