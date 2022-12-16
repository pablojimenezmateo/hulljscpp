.DEFAULT_GOAL := build

build:
	g++ -fPIC -Wall -Wextra -shared -o convex_hull.so Convex-Hull.cpp

clean:
	rm convex_hull.so

test:
	mkdir -p build
	g++ -Wall -Wextra -Werror src/Coordinate.cpp -o build/Coordinate.o -c
	g++ -Wall -Wextra -Werror src/Grid.cpp -o build/Grid.o -c
	g++ -Wall -Wextra -Werror src/Intersect.cpp -o build/Intersect.o -c
	g++ -Wall -Wextra -Werror src/Hull.cpp -o build/Hull.o -c
	g++ -Wall -Wextra -Werror src/Convex.cpp -o build/Convex.o -c

	g++ -Wall -Wextra -Werror tests/GridTest.cpp -o build/GridTest.o -c
	g++ -Wall -Wextra -Werror tests/IntersectTest.cpp -o build/IntersectTest.o -c
	g++ -Wall -Wextra -Werror tests/HullTest.cpp -o build/HullTest.o -c

	g++ -Wall -Wextra -Werror -o build/gridTest build/GridTest.o build/Coordinate.o build/Grid.o 
	./build/gridTest

	g++ -Wall -Wextra -Werror -o build/intersectTest build/IntersectTest.o build/Coordinate.o build/Intersect.o 
	./build/intersectTest

	g++ -Wall -Wextra -Werror -o build/HullTest build/HullTest.o build/Coordinate.o build/Hull.o build/Intersect.o build/Grid.o build/Convex.o
	./build/HullTest