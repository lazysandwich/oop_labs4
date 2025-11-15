#include "include/rhombus.h"
#include "include/pentagon.h"
#include "include/hexagon.h"
#include "include/figure.h"
#include <iostream>

int main() {
    int n;
    std::cout << "Введите количество фигур: ";
    std::cin >> n;
    std::vector<std::shared_ptr<Figure<double>>> figures;
    for (int i = 0; i < n; ++i) {
        std::string type;
        std::cout << "Введите тип фигуры (rhombus/pentagon/hexagon): ";
        std::cin >> type;
        if (type == "rhombus") {
            std::cout << "Введите координаты 4-х вершин:";
            auto f = std::make_shared<Rhombus<double>>();
            std::cin >> *f;
            figures.push_back(f);
        }
        else if (type == "pentagon") {
            std::cout << "Введите координаты 5-ти вершин:";
            auto f = std::make_shared<Pentagon<double>>();
            std::cin >> *f;
            figures.push_back(f);
        }
        else if (type == "hexagon") {
            std::cout << "Введите координаты 6-ти вершин:";
            auto f = std::make_shared<Hexagon<double>>();
            std::cin >> *f;
            figures.push_back(f);
        }
        else {
            std::cout << "Неизвестная фигура\n";
            --i;
        }
    }
    double total = 0;
    for (int i = 0; i < figures.size(); ++i) {
        std::cout << *figures[i];
        total += static_cast<double>(*figures[i]);
    }
    std::cout << "Общая площадь: " << total << std::endl;
}
//g++ -std=c++20 -Wall -Wextra main.cpp -o lab