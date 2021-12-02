final: main.o user.o
	g++ main.o user.o -o final

user.o: user.cpp user.h
	g++ -c user.cpp

main.o: main.cpp user.h
	g++ -c main.cpp

clean:
	rm *.o final
