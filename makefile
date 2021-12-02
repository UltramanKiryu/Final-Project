final: main.o user.o
	g++ main.o user.o -o final -g

user.o: user.cpp user.h
	g++ -c user.cpp -g

main.o: main.cpp user.h
	g++ -c main.cpp -g

clean:
	rm *.o final
