build:
	g++ -w -std=c++14 -Wfatal-errors \
	./*.cpp \
	-o particleGenerator \
	-lSDL2;

clean:
	rm ./particleGenerator;

run:
	./particleGenerator;