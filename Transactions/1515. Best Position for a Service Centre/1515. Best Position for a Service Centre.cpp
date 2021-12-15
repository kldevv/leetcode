/*
Number: 1515
Topic: Best Position for a Service Centre
Date: 2021/12/7
Rate: Hard

A delivery company wants to build a new service centre in a new city. The company knows the positions of all the customers in this city on a 2D-Map and wants to build the new centre in a position such that the sum of the euclidean distances to all customers is minimum.

Given an array positions where positions[i] = [xi, yi] is the position of the ith customer on the map, return the minimum sum of the euclidean distances to all customers.

In other words, you need to choose the position of the service centre [xcentre, ycentre] such that the following formula is minimized:

Answers within 10^-5 of the actual value will be accepted.

Constraints:
    * 1 <= positions.length <= 50
    * positions[i].length == 2
    * 0 <= positions[i][0], positions[i][1] <= 100
*/

#include <cmath>
#include <vector>

using namespace std;

class Solution {
   private:
    vector<vector<int>> positions;
    double PRECISION = 1e-6;
    double EPSILON = 1e-20;

   public:
    double getMinDistSum(vector<vector<int>>& positions) {
        /*
        init:
            x = 0
            y = 0
            step = 1

        while (step < PRECISION):
            gradient = calGrad(x, y)
            adjX = x - gradient * step;
            adjY = y - gradient * step;

            if (objective(adjX, adjY) < objective(x, y)) {
                x = adjX
                y = adjY
            } else {
                step /= 2
            }

        objective:
            sqrt(pow(x - x_mean), pow(y - y_mean) + epsilon)

        gradient for x:
            (x - x_mean) / sqrt(pow(x - x_mean), pow(y - y_mean) + epsilon)

        gradient for y:
            (x - x_mean) / sqrt(pow(x - x_mean), pow(y - y_mean) + epsilon)
        */
        if (positions.size() == 1)
            return 0.0;
        this->positions = positions;
        double x = 0;
        double y = 0;
        double step = 1.0;

        while (step > EPSILON) {
            double gradientX = calGradientX(x, y);
            double gradientY = calGradientY(x, y);

            double adjX = x - step * gradientX;
            double adjY = y - step * gradientY;

            // cout << calObjective(x, y) << endl;
            // cout << calObjective(adjX, adjY) << endl;

            if (calObjective(adjX, adjY) < calObjective(x, y)) {
                x = adjX;
                y = adjY;
            } else {
                step *= 0.5;
            }
        }
        return calObjective(x, y);
    }

    double calGradientX(double x, double y) {
        double result = 0.0;
        for (vector<int> position : positions) {
            double diffX = (x - position[0]);
            double diffY = (y - position[1]);

            result += diffX / sqrt(pow(diffX, 2) + pow(diffY, 2) + EPSILON);
        }
        return result;
    }

    double calGradientY(double x, double y) {
        double result = 0.0;
        for (vector<int> position : positions) {
            double diffX = (x - position[0]);
            double diffY = (y - position[1]);

            result += diffY / sqrt(pow(diffX, 2) + pow(diffY, 2) + EPSILON);
        }
        return result;
    }

    double calObjective(double x, double y) {
        double result = 0.0;
        for (vector<int> position : positions) {
            double diffX = (x - position[0]);
            double diffY = (y - position[1]);

            result += sqrt(pow(diffX, 2) + pow(diffY, 2));
        }
        return result;
    }
};