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
    struct point points[] = {{1,7}, {2,5}, {3,6}, {4,3}, {5,7}, {6,1}};
    int n = sizeof(points)/sizeof(points[0]);
    
    closest_pair(points, n);
    
    return 0;
}
