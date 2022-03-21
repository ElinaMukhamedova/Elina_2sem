//
//  E.cpp
//  
//
//  Created by Elina Mukhamedova on 21.03.2022.
//

#include <iostream>

struct Segment {
    int left;
    int right;
    
    Segment() {
        left = 0;
        right = 0;
    }
    
    Segment(int a, int b) {
        if (a < b) {
            left = a;
            right = b;
        }
        else {
            left = b;
            right = a;
        }
    }
    
    bool operator==(const Segment & other) const {
        return (other.left <= right) && (left <= other.right);
    }
};

Segment inner(Segment a, Segment b) {
    int r = 0, l = 0;
    if (a.left < b.left)
        l = b.left;
    else
        l = a.left;
    if (a.right < b.right)
        r = a.right;
    else
        r = b.right;
    Segment result = Segment(l, r);
    return result;
}

int main() {
    int n = 0;
    std::cin >> n;
    Segment *m = new Segment[n];
    int a = 0, b = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> a >> b;
        m[i] = Segment(a, b);
    }
    bool flag = true;
    Segment s = Segment();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (m[i] == m[j]) {
                m[i] = inner(m[i], m[j]);
            }
            else
                flag = false;
        }
    }
    if (flag == true)
        std::cout << "YES" << std::endl;
    else
        std::cout << "NO" << std::endl;
    delete[] m;
}
