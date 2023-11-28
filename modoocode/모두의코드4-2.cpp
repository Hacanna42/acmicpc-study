// 모두의코드 4-2
// https://modoocode.com/173
// 2023-11-09

// 5일간의 풀이 끝에 과제 종료. 231116 노트 참고.

#include <cmath>
#include <iostream>

class Point {
    double x_, y_;

   public:
    Point(double x, double y) : x_(x), y_(y) {}

    double getX() const { return x_; }
    double getY() const { return y_; }
};

class Geometry {
   public:
    Geometry() { num_points = 0; }

    void AddPoint(const Point& point) {
        point_array[num_points++] = new Point(point.getX(), point.getY());
    }

    Point GetPoint(int pointer) { return *point_array[pointer - 1]; }

    int PrintPointNum() { return num_points; }

    // 모든 점들 간의 거리를 출력하는 함수 입니다.
    void PrintDistance() {
    }  // 이거는 보류, 모든 점들 간의 거리를 출력하는게 대체 무슨 말이지?

    double PrintBetweenDistance(const Point& pt1, const Point& pt2) {
        double x_distance = abs(pt1.getX() - pt2.getX());
        double y_distance = abs(pt1.getY() - pt2.getY());
        double distance = sqrt(static_cast<double>(x_distance * x_distance) +
                               static_cast<double>(y_distance * y_distance));
        return distance;
    }

    // 모두 코드의 설명
    // 모든 점들을 잇는 직선들 간의 교점의 수를 출력해주는 함수 입니다.
    // 참고적으로 임의의 두 점을 잇는 직선의 방정식을 f(x,y) = ax+by+c = 0
    // 이라고 할 때 임의의 다른 두 점 (x1, y1) 과 (x2, y2) 가 f(x,y)=0 을
    // 기준으로 서로 다른 부분에 있을 조건은 f(x1, y1) * f(x2, y2) <= 0 이면
    // 됩니다.

    int PrintNumMeets() {
        // 기본적으로, PrintNumMeets는 Point[]의 {0, 1}번째 {2, 3}번째
        // 순서대로의 두개의 짝이 직선을 이뤘을 때 최대 50개 선의 교차점 개수를
        // 구합니다.
        int indicator;
        if (num_points < 4) {
            std::cout
                << "계산을 수행할 수 없습니다. 점이 4개 이상 선언되어야합니다."
                << std::endl;
            return 0;
        }
        int answer = 0;
        for (int i = 0; i < num_points - 1; i += 2) {
            Point pt1 = *point_array[i];
            Point pt2 = *point_array[i + 1];
            for (int j = 0; j < num_points - 1; j += 2) {
                Point l1 = *point_array[j];
                Point l2 = *point_array[j + 1];
                answer += GetLineEquation(pt1, pt2, l1, l2);
            }
        }
        return answer / 2;
    }

    int GetLineEquation(const Point& pt1, const Point& pt2, const Point& l1,
                        const Point& l2) {
        // 기울기 m 계산
        double x_distance = l1.getX() - l2.getX();
        double y_distance = l1.getY() - l2.getY();
        double a, b, c, m;
        // x_distance나 y_distanace가 0 일경우 0으로 나누기는 성립하지 않기에
        // NaN 에러가 나서 다르게 처리해야함.
        // 수평선 혹은 수직선일때는 x|y = k 형태의 방정식을 따름. m을 계산할
        // 필요가 없어짐 (기울기가 무한대, 없음.)
        if (x_distance == 0) {
            // 수직선의 경우 ax + by + c = 0 을 x = k로 단순화
            a = 1;
            b = 0;
            c = -l1.getX();
        } else if (y_distance == 0) {
            // 수평선의 경우 y = k 로 단순화
            a = 0;
            b = 1;
            c = -l1.getY();
        } else {
            m = y_distance / x_distance;
            // a = -m, b = 1, c = -ax1-by1
            a = m * -1;
            b = 1;
            c = (-a * l1.getX()) - (b * l1.getY());
        }
        // 직선의 방정식을 점에 대입해서, 음수인지 양수인지 확인
        double result_p1 = (a * pt1.getX()) + (b * pt1.getY()) + c;
        double result_p2 = (a * pt2.getX()) + (b * pt2.getY()) + c;
        std::cout << "p1 = " << result_p1 << std::endl;
        std::cout << "p2 = " << result_p2 << std::endl;
        double result = result_p1 * result_p2;
        if (result < 0) {
            return 1;
        }
        return 0;
    }

   private:
    // 점 100 개를 보관하는 배열.
    Point* point_array[100];
    int num_points;
};

void addPoint(Geometry& geo) {
    double x, y;
    char comma;
    std::cout << "x, y : ";
    std::cin >> x >> comma >> y;
    Point pt(x, y);
    geo.AddPoint(pt);
    std::cout << "점 " << geo.PrintPointNum() << "이 추가되었습니다."
              << std::endl
              << "-" << std::endl;
}

int main() {
    Geometry geo;
    while (true) {
        int action = 0;
        std::cout << "1. 점 추가\n2. 두 점간의 거리 구하기\n3. 모든 선에 대해 "
                     "교차점 확인\n4. 두 선에 "
                     "대해 교차점 확인"
                  << std::endl;
        std::cin >> action;

        switch (action) {
            case 1:
                addPoint(geo);
                break;
            case 2:
                int pointer1, pointer2;
                char comma;
                std::cout << "점 두개를 입력해주세요 (pt1, pt2) : ";
                std::cin >> pointer1 >> comma >> pointer2;
                std::cout << geo.PrintBetweenDistance(geo.GetPoint(pointer1),
                                                      geo.GetPoint(pointer2))
                          << std::endl;
                break;
            case 3:
                std::cout << "모든 선의 교차점은 총 " << geo.PrintNumMeets()
                          << "개 입니다." << std::endl;
                break;
            case 4: {
                int pt1, pt2, l1, l2;
                std::cout << "점 네개를 입력해주세요 (pt1, pt2, l1, l2) : ";
                std::cin >> pt1 >> comma >> pt2 >> comma >> l1 >> comma >> l2;
                int answer = 0;
                answer =
                    geo.GetLineEquation(geo.GetPoint(pt1), geo.GetPoint(pt2),
                                        geo.GetPoint(l1), geo.GetPoint(l2));
                if (answer < 0) {
                    std::cout << "교차합니다!" << std::endl;
                } else if (answer == 0) {
                    std::cout << "두 선이 완전히 일치합니다." << std::endl;
                } else
                    std::cout << "교차하지 않습니다." << std::endl;
                break;
            }
            default:
                std::cout << "올바르지 않은 입력입니다." << std::endl;
        }
    }
    // Point pt1(-10, 0);
    // Point pt2(10, 0);
    // Point l1(0, -10);
    // Point l2(0, 10);
    // Geometry geo;
    // geo.getLineEquation(pt1, pt2, l1, l2);
}