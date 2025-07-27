all: run no-bin

mem-check: build
	valgrind ./program

run: build 
	./program

build: program clean

check: program clean no-bin

program: target/*.o
	g++ target/*.o -o program

target/*.o:
	g++ -c src/main/main.cpp
	g++ -c src/main/text_math/*.cpp
	mv *.o target/

no-bin:
	rm program

clean:
	rm target/*.*
	


