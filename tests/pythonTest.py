def getHullData(coordinates):
    """
    This function takes a list of coordinates and returns the convex hull, area and perimeter.
    The coordinates are expected to be a list of lists, where each sublist contains two numbers.
    The first number is the x coordinate and the second number is the y coordinate.
    The function returns a tuple of three elements:
    - The first element is a list of coordinates that form the convex hull.
    - The second element is the area of the convex hull.
    - The third element is the perimeter of the convex hull.
    """

    import os
    from ctypes import CDLL, POINTER, Structure, c_double, c_int, c_ulong, cast
    from pathlib import Path

    # Where can we find the shared library
    shared_library_path = os.path.join(
        os.path.dirname(os.path.realpath(Path(__file__).parent)), "convex_hull.so"
    )

    # This is an internal structure used by the CPP code
    class Coordinate(Structure):
        _fields_ = [("m_x", c_double), ("m_y", c_double)]

    # Here we need to define the signatures of the methods
    convex_hull = CDLL(shared_library_path)
    convex_hull.getConvexHull.argtypes = [POINTER(Coordinate), c_int, POINTER(c_ulong)]
    convex_hull.getConvexHull.restype = POINTER(Coordinate)
    convex_hull.freeHull.argtypes = [POINTER(Coordinate)]
    convex_hull.freeHull.restype = None
    convex_hull.getHullArea.argtypes = [POINTER(Coordinate), c_int]
    convex_hull.getHullArea.restype = c_double
    convex_hull.getHullPerimeter.argtypes = [POINTER(Coordinate), c_int]
    convex_hull.getHullPerimeter.restype = c_double

    # Create the CPP structure
    c_coordinates_size = (Coordinate * len(coordinates))()
    c_coordinates = cast(c_coordinates_size, POINTER(Coordinate))

    for i, coordinate in enumerate(coordinates):
        c_coordinates[i].m_x = coordinate[0]
        c_coordinates[i].m_y = coordinate[1]

    hull_size = c_ulong()
    hull = convex_hull.getConvexHull(c_coordinates, len(coordinates), hull_size)

    hull_p = []

    for i in range(hull_size.value):
        hull_p.append([hull[i].m_x, hull[i].m_y])

    # Area
    area = convex_hull.getHullArea(hull, hull_size.value)

    # Perimeter
    perimeter = convex_hull.getHullPerimeter(hull, hull_size.value)

    convex_hull.freeHull(hull)

    return (hull_p, area, perimeter)


if __name__ == "__main__":

    # First test
    coordinates = [[16, 3], [12, 17], [0, 6], [-4, -6]]

    (hull_p, area, perimeter) = getHullData(coordinates=coordinates)
    print(
        f"Hull: {hull_p}\n Area: {area} expected [208.0]\n Perimeter: {perimeter} expected [65.41986321479557]"
    )

    # Second test
    coordinates = [
        [16, 3],
        [12, 17],
        [0, 6],
        [-4, -6],
        [16, 6],
        [16, -7],
        [16, -3],
        [17, -4],
        [5, 19],
        [19, -8],
        [3, 16],
        [12, 13],
        [3, -4],
        [17, 5],
        [-3, 15],
        [-3, -9],
        [0, 11],
        [-9, -3],
        [-4, -2],
        [12, 10],
    ]

    (hull_p, area, perimeter) = getHullData(coordinates=coordinates)
    print(
        f"Hull: {hull_p}\n Area: {area} expected [560.5] \n Perimeter: {perimeter} expected [92.10352640720562]"
    )
