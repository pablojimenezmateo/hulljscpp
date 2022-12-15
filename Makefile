.DEFAULT_GOAL := build

build:
	g++ -fPIC -Wall -Wextra -shared -o convex_hull.so Convex-Hull.cpp

clean:
	rm convex_hull.so

test:
	mkdir -p build
	g++ -Wall -Wextra -Werror src/Coordinate.cpp -o build/Coordinate.o -c
	g++ -Wall -Wextra -Werror src/Grid.cpp -o build/Grid.o -c
	g++ -Wall -Wextra -Werror tests/GridTest.cpp -o build/GridTest.o -c
	g++ -Wall -Wextra -Werror -o build/test build/GridTest.o build/Coordinate.o build/Grid.o 
