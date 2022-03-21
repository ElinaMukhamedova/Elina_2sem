//
//  D.cpp
//  
//
//  Created by Elina Mukhamedova on 21.03.2022.
//

#include <iostream>

struct Point {
    float x;
    float y;
    
    Point() {
        x = 0;
        y = 0;
    }

    Point(float t_x, float t_y) {
        x = t_x;
        y = t_y;
    }
    
    bool operator== (const Point & other) const {
        return ((abs(x - other.x) <= 0.001f) && (abs(y - other.y) <= 0.001f));
    }
};

float ctg(Point A, Point B) {
    if (B.y != A.y)
        return (B.x - A.x) / (B.y - A.y);
    else
        return (B.x - A.x) / 0.001f;
}

bool intersect(Point A, Point B, Point C, Point D) {
    Point P = Point();
    bool flag = false;
    if (ctg(A, B) != ctg(C, D)){
        float y = (C.x - A.x + A.y * ctg(A, B) - C.y * ctg(C, D)) / (ctg(A, B) - ctg(C, D));
        float x = A.x + (y - A.y) * ctg(A, B);
        P.x = x;
        P.y = y;
        flag = true;
    }
    else {
        if ((A == C) || (A == D)) {
            P.x = A.x;
            P.y = A.y;
            flag = true;
        }
        if ((B == C) || (B == D)) {
            P.x = B.x;
            P.y = B.y;
            flag = true;
        }
    }
    if (flag == false)
        return false;
    else {
        int x_left = 0, x_right, y_top = 0, y_bottom = 0;
        if (A.x > B.x) {
            x_left = B.x;
            x_right = A.x;
        }
        else {
            x_left = A.x;
            x_right = B.x;
        }
        if (A.y > B.y) {
            y_top = A.y;
            y_bottom = B.y;
        }
        else {
            y_top = B.y;
            y_bottom = A.y;
        }
        return (P.x <= x_right) && (P.x >= x_left) && (P.y <= y_top) && (P.y >= y_bottom);
    }
}

int main() {
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0, x4 = 0, y4 = 0;
    std::cin >> x1 >> y1;
    std::cin >> x2 >> y2;
    std::cin >> x3 >> y3;
    std::cin >> x4 >> y4;
    Point A = Point(x1, y1);
    Point B = Point(x2, y2);
    Point C = Point(x3, y3);
    Point D = Point(x4, y4);
    if (intersect(A, B, C, D))
        std::cout << "NO" << std::endl;
    else
        std::cout << "YES" << std::endl;
}
