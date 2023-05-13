#include <iostream>
#include <cmath>

using namespace std;

// A struct to represent a point in 2D space
struct Point {
    int x, y;
};

// Function to compute the Euclidean distance between two points
double euclideanDistance(Point p1, Point p2) {
    int x_diff = p1.x - p2.x;
    int y_diff = p1.y - p2.y;
    return sqrt(x_diff * x_diff + y_diff * y_diff);
}

// Recursive function to compute the Euclidean distance between two points using divide-and-conquer
double recursiveEuclideanDistance(Point points[], int left, int right) {
    // Base case: when there are only two points, compute the Euclidean distance using the euclideanDistance function
    if (left == right - 1) {
        return euclideanDistance(points[left], points[right]);
    }
    
    // Divide the array into two halves
    int mid = (left + right) / 2;
    
    // Recursively compute the Euclidean distance between the points in the left and right halves
    double left_distance = recursiveEuclideanDistance(points, left, mid);
    double right_distance = recursiveEuclideanDistance(points, mid, right);
    
    // Compute the distance between the closest pair of points that straddle the middle line
    double min_distance = min(left_distance, right_distance);
    int j = mid;
    while (j >= left && points[j].x >= points[mid].x - min_distance) {
        int k = j - 1;
        while (k >= left && points[j].x - points[k].x <= min_distance) {
            double distance = euclideanDistance(points[j], points[k]);
            min_distance = min(min_distance, distance);
            k--;
        }
        j--;
    }
    
    return min_distance;
}

int main() {
    Point points[] = {{0, 0}, {1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}, {7, 7}, {8, 8}, {9, 9}};
    int n = sizeof(points) / sizeof(points[0]);
    double result = recursiveEuclideanDistance(points, 0, n - 1);
    cout << "The Euclidean distance between the closest pair of points is " << result << endl;
    return 0;
}
