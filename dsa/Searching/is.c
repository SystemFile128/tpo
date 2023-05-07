#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct point {
    int x;
    int y;
};

double distance(struct point p1, struct point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

void closest_pair(struct point points[], int n) {
    int i, j;
    double min_distance = INFINITY;
    struct point closest_pair[2];
    
    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
            double d = distance(points[i], points[j]);
            if (d < min_distance) {
                min_distance = d;
                closest_pair[0] = points[i];
                closest_pair[1] = points[j];
            }
        }
    }
    
    printf("Closest pair: (%d,%d) and (%d,%d)\n", closest_pair[0].x, closest_pair[0].y, closest_pair[1].x, closest_pair[1].y);
}

int main() {
    struct point points[] = {{1,1}, {2,2}, {3,3}, {4,4}, {5,5}, {6,6}};
    int n = sizeof(points)/sizeof(points[0]);
    
    closest_pair(points, n);
    
    return 0;
}
/*We define a struct point to represent a point on the x-axis. Each point has an x-coordinate and a y-coordinate.
We define a distance function that calculates the distance between two points using the Pythagorean theorem.
We define a closest_pair function that takes an array of points and the number of points n as input. It uses a nested loop to compare each pair of points and find the pair with the smallest distance. It stores the closest pair in the closest_pair array.
In the main function, we define an array of points and call the closest_pair function with this array and its size.
The program prints the coordinates of the closest pair of points.
For this problem, the brute force approach has a time complexity of O(n^2), which is appropriate for small datasets. However, for larger datasets, a more efficient algorithm such as divide and conquer or a sweep line algorithm may be more appropriate. Sorting the array of points by x-coordinate can also help reduce the time complexity of these algorithms.*/