#include <iostream>
#include <sstream>
#include <limits>
#include <vector>

#include "include/point.h"
#include "include/figure.h"
#include "include/trapezoid.h"
#include "include/diamond.h"
#include "include/pentagon.h"
#include "include/figures.h"

static void printFigureInfo(const char* name, const Figure& f) {
    std::cout << name << '\n' << f;
    Point c = f.calcGeometricCenter();
    std::cout << "Геометрический центр: " << c << "\n";
    std::cout << "Площадь: " << static_cast<double>(f) << "\n\n";
}

int main() {
    
    // Массив для хранения фигур 
    Figures figuresArray;
    
    // 1) Создание и вывод фигур вращения
    std::cout << "1. заданные фигуры:\n";
    
    // Равнобедренная трапеция
    Trapezoid t1({ {0,0}, {4,0}, {3,2}, {1,2} });
    if (t1.isValidRotationFigure()) {
        printFigureInfo("Трапеция (равнобедренная)", t1);
    } else {
        std::cout << "Ошибка: трапеция не является фигурой вращения!\n";
    }
    
    // Ромб 
    Diamond d1({ {0,0}, {2,2}, {4,0}, {2,-2} });
    if (d1.isValidRotationFigure()) {
        printFigureInfo("Ромб (правильный)", d1);
    } else {
        std::cout << "Ошибка: ромб не является фигурой вращения!\n";
    }
    
    // Правильный пятиугольник
    Pentagon p1({ {0,1}, {0.951,0.309}, {0.588,-0.809},
                  {-0.588,-0.809}, {-0.951,0.309} });
    if (p1.isValidRotationFigure()) {
        printFigureInfo("Пятиугольник (правильный)", p1);
    } else {
        std::cout << "Ошибка: пятиугольник не является фигурой вращения!\n";
    }
    
    // 2)ввод с кл
    std::cout << "\nввод фигур с клавиатуры\n";
    
    char choice;
    
    do {
        std::cout << "1 - Добавить фигуру в массив\n";
        std::cout << "2 - Работа с массивом фигур\n";
        std::cout << "3 - Демонстрация операций\n";
        std::cout << "q - Выход\n";
        std::cout << "выбор: ";
        std::cin >> choice;
        
        if (choice == '1') {
            // добавления фигуры
            char figureType;
            std::cout << "\nВыберите тип фигуры:\n";
            std::cout << "1 - Трапеция (равнобедренная, 8 чисел)\n";
            std::cout << "2 - Ромб (правильный, 8 чисел)\n";
            std::cout << "3 - Пятиугольник (правильный, 10 чисел)\n";
            std::cout << "b - Назад\n";
            std::cout << "Ваш выбор: ";
            std::cin >> figureType;
            
            if (figureType == '1') {
                std::cout << "Введите 4 точки трапеции (x1 y1 x2 y2 x3 y3 x4 y4): ";
                Trapezoid* trap = new Trapezoid();
                if (std::cin >> *trap) {
                    figuresArray = Figures({trap});
                    std::cout << "Трапеция добавлена! Фигур в массиве: " 
                              << figuresArray.getSize() << "\n";
                } else {
                    std::cout << "Ошибка! Это не равнобедренная трапеция.\n";
                    delete trap;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }
            else if (figureType == '2') {
                std::cout << "Введите 4 точки ромба (x1 y1 x2 y2 x3 y3 x4 y4): ";
                Diamond* diam = new Diamond();
                if (std::cin >> *diam) {
                    figuresArray = Figures({diam});
                    std::cout << "Ромб добавлен! Фигур в массиве: " 
                              << figuresArray.getSize() << "\n";
                } else {
                    std::cout << "Ошибка! Это не правильный ромб.\n";
                    delete diam;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }
            else if (figureType == '3') {
                std::cout << "Введите 5 точек пятиугольника (10 чисел): ";
                Pentagon* pent = new Pentagon();
                if (std::cin >> *pent) {
                    figuresArray = Figures({pent});
                    std::cout << "Пятиугольник добавлен! Фигур в массиве: " 
                              << figuresArray.getSize() << "\n";
                } else {
                    std::cout << "Ошибка! Это не правильный пятиугольник.\n";
                    delete pent;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }
        }
        else if (choice == '2') {
            if (figuresArray.getSize() == 0) {
                std::cout << "Массив пуст! Сначала добавьте фигуры.\n";
                continue;
            }
            
            // Меню работы с массивом
            char arrayChoice;
            do {
                std::cout << "\nработа с фигурами\n";
                std::cout << "Фигур в массиве: " << figuresArray.getSize() << "\n";
                std::cout << "1 - Показать все фигуры\n";
                std::cout << "2 - Показать геометрические центры\n";
                std::cout << "3 - Показать площади\n";
                std::cout << "4 - Показать общую площадь\n";
                std::cout << "5 - Удалить фигуру по индексу\n";
                std::cout << "6 - Добавить демонстрационные фигуры (3 фигуры)\n";
                std::cout << "b - Назад\n";
                std::cout << "выбор: ";
                std::cin >> arrayChoice;
                
                if (arrayChoice == '1') {
                    std::cout << "\nВсе фигуры в массиве:\n";
                    figuresArray.printCenterAndAreaForEachFigure();
                }
                else if (arrayChoice == '2') {
                    std::cout << "\nГеометрические центры:\n";
                    figuresArray.printCenterForEachFigure();
                }
                else if (arrayChoice == '3') {
                    std::cout << "\nПлощади фигур:\n";
                    figuresArray.printAreaForEachFigure();
                }
                else if (arrayChoice == '4') {
                    double total = figuresArray.calcTotalArea();
                    std::cout << "\nОбщая площадь всех фигур: " << total << "\n";
                }
                else if (arrayChoice == '5') {
                    int index;
                    std::cout << "Введите индекс для удаления (0-" 
                              << figuresArray.getSize()-1 << "): ";
                    std::cin >> index;
                    
                    if (index >= 0 && static_cast<size_t>(index) < figuresArray.getSize()) {
                        figuresArray.deleteFigure(index);
                        std::cout << "Фигура удалена. Осталось фигур: " 
                                  << figuresArray.getSize() << "\n";
                    } else {
                        std::cout << "Неверный индекс!\n";
                    }
                }
                else if (arrayChoice == '6') {
                    // Добавляем демонстрационные фигуры
                    Figure* fA = new Trapezoid({ {0,0}, {4,0}, {3,2}, {1,2} });
                    Figure* fB = new Diamond({ {0,0}, {2,2}, {4,0}, {2,-2} });
                    Figure* fC = new Pentagon({ {0,1}, {0.951,0.309}, {0.588,-0.809},
                                                {-0.588,-0.809}, {-0.951,0.309} });
                    
                    figuresArray = Figures({ fA, fB, fC });
                    std::cout << "Демонстрационные фигуры добавлены! Фигур в массиве: " 
                              << figuresArray.getSize() << "\n";
                }
                
            } while (arrayChoice != 'b');
        }
        else if (choice == '3') {
            std::cout << "\nоперации:\n";
            
            // Копирование
            Trapezoid t2 = t1;
            std::cout << "Копирование: t1 == t2 ? " << (t1 == t2 ? "true" : "false") << "\n";
            
            // Перемещение
            Diamond d2 = std::move(d1);
            std::cout << "Перемещение: площадь d2 = " << static_cast<double>(d2) << "\n";
            
            // Сравнение
            Pentagon p_copy = p1;
            std::cout << "Сравнение: p1 == p_copy ? " << (p1 == p_copy ? "true" : "false") << "\n";
        }
        
    } while (choice != 'q');
    
    std::cout << "\nПрограмма завершена.\n";
    return 0;
}