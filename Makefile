.DEFAULT_GOAL := build
.PHONY: build

build:
	g++ -fPIC -Wall -Wextra -Werror -shared -o convex_hull.so src/Coordinate.cpp src/Grid.cpp src/Intersect.cpp src/Hull.cpp src/Convex.cpp

buildpython:
	g++ -fPIC -Wall -Wextra -Werror -shared -o convex_hull.so src/Coordinate.cpp src/Grid.cpp src/Intersect.cpp src/Hull.cpp misc/PythonEntryPoint.cpp src/Convex.cpp

standalone:
	mkdir -p build
	g++ -Wall -Wextra -Werror src/Coordinate.cpp -o build/Coordinate.o -c
	g++ -Wall -Wextra -Werror src/Grid.cpp -o build/Grid.o -c
	g++ -Wall -Wextra -Werror src/Intersect.cpp -o build/Intersect.o -c
	g++ -Wall -Wextra -Werror src/Hull.cpp -o build/Hull.o -c
	g++ -Wall -Wextra -Werror src/Convex.cpp -o build/Convex.o -c
	g++ -Wall -Wextra -Werror src/Utils.cpp -o build/Utils.o -c
	g++ -Wall -Wextra -Werror misc/Main.cpp -o build/Main.o -c

	g++ -Wall -Wextra -Werror -o build/main build/Coordinate.o build/Grid.o build/Main.o build/Utils.o build/Hull.o build/Intersect.o build/Convex.o

clean:
	rm -rf build
	rm -f convex_hull.so

test:
	mkdir -p build
	g++ -Wall -Wextra -Werror src/Coordinate.cpp -o build/Coordinate.o -c
	g++ -Wall -Wextra -Werror src/Grid.cpp -o build/Grid.o -c
	g++ -Wall -Wextra -Werror src/Intersect.cpp -o build/Intersect.o -c
	g++ -Wall -Wextra -Werror src/Hull.cpp -o build/Hull.o -c
	g++ -Wall -Wextra -Werror src/Convex.cpp -o build/Convex.o -c
	g++ -Wall -Wextra -Werror src/Utils.cpp -o build/Utils.o -c

	g++ -Wall -Wextra -Werror tests/GridTest.cpp -o build/GridTest.o -c
	g++ -Wall -Wextra -Werror tests/IntersectTest.cpp -o build/IntersectTest.o -c
	g++ -Wall -Wextra -Werror tests/HullTest.cpp -o build/HullTest.o -c

	g++ -Wall -Wextra -Werror -o build/gridTest build/GridTest.o build/Coordinate.o build/Grid.o 
	./build/gridTest

	g++ -Wall -Wextra -Werror -o build/intersectTest build/IntersectTest.o build/Coordinate.o build/Intersect.o 
	./build/intersectTest

	g++ -Wall -Wextra -Werror -o build/HullTest build/HullTest.o build/Coordinate.o build/Hull.o build/Intersect.o build/Grid.o build/Convex.o build/Utils.o
	./build/HullTest