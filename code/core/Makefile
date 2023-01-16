CC=g++
OUTPUT= a.out
SRC= $(wildcard *.cc)

all:
	$(CC) $(SRC) -o $(OUTPUT)

run: $(OUTPUT) file
	./$(OUTPUT) file

clean:
	rm -f $(wildcard *.out)

