import random

def generate_polygon(num_sides, min_coord, max_coord):
    polygon = []
    for i in range(num_sides):
        x = random.uniform(min_coord, max_coord)
        y = random.uniform(min_coord, max_coord)
        polygon.append((x, y))
    return polygon

num_sides = 5
min_coord = 0
max_coord = 1
polygon = generate_polygon(num_sides, min_coord, max_coord)

print(polygon)