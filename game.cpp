#include <iostream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, ""); // поддержка кириллицы

    int score = 0;
    int answer;

    cout << "=============================\n";
    cout << "   Викторина по программированию\n";
    cout << "       Игра на C++\n";
    cout << "=============================\n\n";

    // ВОПРОС 1
    cout << "Вопрос 1: Какой тип данных используется для хранения целых чисел в C++?\n";
    cout << "1) float\n";
    cout << "2) int\n";
    cout << "3) char\n";
    cout << "Ваш ответ: ";
    cin >> answer;

    if (answer == 2) {
        cout << "Правильно!\n\n";
        score++;
    } else {
        cout << "Неправильно. Правильный ответ: 2\n\n";
    }
}