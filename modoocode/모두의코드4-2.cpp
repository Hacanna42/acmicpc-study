// 모두의코드 4-2
// https://modoocode.com/173
// 2023-11-09

#include <iostream>

class Point {
    int x_, y_;

   public:
    Point(int x, int y) : x_(x), y_(y) {}

    int getX() const { return x_; }
    int getY() const { return y_; }
};

class Geometry {
   public:
    Geometry() { num_points = 0; }

    void AddPoint(const Point& point) {
        point_array[num_points++] = new Point(point.getX(), point.getY());
    }

    // 모든 점들 간의 거리를 출력하는 함수 입니다.
    void PrintDistance() {
        for (int i = 0; i < num_points; i++) {
            std::cout << i << "번째 Point의 좌표는 (" << point_array[i]->getX()
                      << ", " << point_array[i]->getY() << ")" << std::endl;
        }
    }

    // 모든 점들을 잇는 직선들 간의 교점의 수를 출력해주는 함수 입니다.
    // 참고적으로 임의의 두 점을 잇는 직선의 방정식을 f(x,y) = ax+by+c = 0
    // 이라고 할 때 임의의 다른 두 점 (x1, y1) 과 (x2, y2) 가 f(x,y)=0 을
    // 기준으로 서로 다른 부분에 있을 조건은 f(x1, y1) * f(x2, y2) <= 0 이면
    // 됩니다.
    void PrintNumMeets();

   private:
    // 점 100 개를 보관하는 배열.
    Point* point_array[100];
    int num_points;
};

int main() {
    Point pt(10, 10);
    Geometry geo;
    geo.AddPoint(pt);
    geo.PrintDistance();
}