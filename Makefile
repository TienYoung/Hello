all: 
	clang ./src/main.c -o ./build/mainC

clean:
	rm -rf ./build/*