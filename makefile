all:
	g++ ./src/SerialTest.cpp -o ./bin/SerialTest #`pkg-config --cflags --libs opencv`
#clean:
	#rm -f server client
