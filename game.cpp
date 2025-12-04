#include <iostream>
#include <string>
#include <clocale>    
#ifdef _WIN32
#include <windows.h> 
#endif

using namespace std;

int main() {
  
    #ifdef _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    #endif

 
    setlocale(LC_ALL, "");

    int score = 0;
    int answer;

    cout << "=============================\n";
    cout << "     Викторина по програмиране\n";
    cout << "           Игра на C++\n";
    cout << "=============================\n\n";

    cout << "Въпрос 1: Кой тип данни се използва за цели числа в C++?\n";
    cout << "1) float\n";
    cout << "2) int\n";
    cout << "3) char\n";
    cout << "Вашият отговор: ";
    cin >> answer;
    if (answer == 2) score++;

    cout << "\nВъпрос 2: Кой оператор се използва за извеждане на текст в конзолата?\n";
    cout << "1) cout <<\n";
    cout << "2) cin >>\n";
    cout << "3) print()\n";
    cout << "Вашият отговор: ";
    cin >> answer;
    if (answer == 1) score++;

    cout << "\nВъпрос 3: Как се нарича структура от инструкции, която се изпълнява при извикване?\n";
    cout << "1) Променлива\n";
    cout << "2) Клас\n";
    cout << "3) Функция\n";
    cout << "Вашият отговор: ";
    cin >> answer;
    if (answer == 3) score++;

    cout << "\nВъпрос 4: Какво означава операторът == в C++?\n";
    cout << "1) Присвояване на стойност\n";
    cout << "2) Сравнение за равенство\n";
    cout << "3) Спиране на програмата\n";
    cout << "Вашият отговор: ";
    cin >> answer;
    if (answer == 2) score++;

    cout << "=============================\n";
    cout << "Вашият резултат: " << score << " от 4\n";
    cout << "=============================\n";

    return 0;
}
