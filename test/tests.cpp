#include <gtest/gtest.h>
#include "../include/rhombus.h"
#include "../include/pentagon.h"
#include "../include/hexagon.h"

// ----------- RHOMBUS -----------
TEST(RhombusTest, AreaAndCenter) {
    // Ромб с вершинами (0,0), (2,1), (0,2), (-2,1)
    std::vector<Point<double>> pts = {
        {0, 0}, {2, 1}, {0, 2}, {-2, 1}
    };
    
    Rhombus<double> r(pts);

    EXPECT_NEAR(r.Area(), 4.0, 1e-9);
    EXPECT_NEAR(r.Center().x, 0.0, 1e-9);
    EXPECT_NEAR(r.Center().y, 1.0, 1e-9);
}

TEST(RhombusTest, EqualityOperator) {
    Rhombus<double> r1({{0,0}, {2,1}, {0,2}, {-2,1}});
    Rhombus<double> r2({{0,0}, {2,1}, {0,2}, {-2,1}});
    Rhombus<double> r3({{0,0}, {1,0}, {0,1}, {-1,0}});
    EXPECT_TRUE(r1 == r2);
    EXPECT_FALSE(r1 == r3);
}

// ----------- PENTAGON -----------
TEST(PentagonTest, AreaAndCenter) {
    // Правильный пятиугольник с радиусом 1
    std::vector<Point<double>> pts = {
        {std::cos(0), std::sin(0)},
        {std::cos(2*M_PI/5), std::sin(2*M_PI/5)},
        {std::cos(4*M_PI/5), std::sin(4*M_PI/5)},
        {std::cos(6*M_PI/5), std::sin(6*M_PI/5)},
        {std::cos(8*M_PI/5), std::sin(8*M_PI/5)}
    };
    Pentagon<double> p(pts);

    EXPECT_NEAR(p.Center().x, 0.0, 1e-9);
    EXPECT_NEAR(p.Center().y, 0.0, 1e-9);
    EXPECT_GT(p.Area(), 0.0);
}

TEST(PentagonTest, EqualityOperator) {
    Pentagon<double> p1({{0,0},{1,0},{1,1},{0,1},{-1,0}});
    Pentagon<double> p2({{0,0},{1,0},{1,1},{0,1},{-1,0}});
    Pentagon<double> p3({{0,0},{2,0},{2,2},{0,2},{-2,0}});
    EXPECT_TRUE(p1 == p2);
    EXPECT_FALSE(p1 == p3);
}

// ----------- HEXAGON -----------
TEST(HexagonTest, AreaAndCenter) {
    // Правильный шестиугольник с радиусом 1
    std::vector<Point<double>> pts = {
        {1, 0},
        {0.5, std::sqrt(3)/2},
        {-0.5, std::sqrt(3)/2},
        {-1, 0},
        {-0.5, -std::sqrt(3)/2},
        {0.5, -std::sqrt(3)/2}
    };
    Hexagon<double> h(pts);

    EXPECT_NEAR(h.Center().x, 0.0, 1e-9);
    EXPECT_NEAR(h.Center().y, 0.0, 1e-9);
    EXPECT_NEAR(h.Area(), 3 * std::sqrt(3) / 2.0, 1e-9);
}

TEST(HexagonTest, EqualityOperator) {
    Hexagon<double> h1({
        {1, 0}, {0.5, std::sqrt(3)/2}, {-0.5, std::sqrt(3)/2},
        {-1, 0}, {-0.5, -std::sqrt(3)/2}, {0.5, -std::sqrt(3)/2}
    });
    Hexagon<double> h2({
        {1, 0}, {0.5, std::sqrt(3)/2}, {-0.5, std::sqrt(3)/2},
        {-1, 0}, {-0.5, -std::sqrt(3)/2}, {0.5, -std::sqrt(3)/2}
    });
    Hexagon<double> h3({
        {2, 0}, {1, std::sqrt(3)}, {-1, std::sqrt(3)},
        {-2, 0}, {-1, -std::sqrt(3)}, {1, -std::sqrt(3)}
    });
    EXPECT_TRUE(h1 == h2);
    EXPECT_FALSE(h1 == h3);
}