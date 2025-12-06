#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <random>
#include <ctime>
#include <iomanip>

using namespace std;

struct Question {
    string text;
    vector<string> answers;
    int correct;
};

//INPUT FIX
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
}

int safeInputInt(int minVal, int maxVal) {
    int x;
    while (true) {
        cout << "> ";
        cin >> x;

        if (!cin.fail() && x >= minVal && x <= maxVal)
            return x;

        cout << "Invalid choice! Enter a number between "
            << minVal << " and " << maxVal << ".\n";
        clearInput();
    }
}

//QUIZ FUNCTION
void startQuiz(vector<Question> quiz) {
    shuffle(quiz.begin(), quiz.end(), default_random_engine(time(nullptr)));

    int score = 0;
    int answer;

    for (int i = 0; i < (int)quiz.size(); i++) {

        cout << "\n-------------------------\n";
        cout << "Question " << i + 1 << "/" << quiz.size() << "\n";
        cout << quiz[i].text << "\n";

        for (auto& ans : quiz[i].answers)
            cout << ans << "\n";

        while (true) {
            cout << "Your answer: ";
            cin >> answer;

            if (!cin.fail() && answer >= 1 && answer <= (int)quiz[i].answers.size())
                break;

            cout << "Invalid input! Try again.\n";
            clearInput();
        }

        if (answer == quiz[i].correct) {
            cout << "\033[32mCorrect!\033[0m\n";
            score++;
        }
        else {
            cout << "\033[31mWrong!\033[0m Correct answer: "
                << quiz[i].correct << "\n";
        }
    }

    cout << "\n=========================\n";
    cout << "Final score: " << score << "/" << quiz.size() << endl;

    if (score == (int)quiz.size()) cout << "Excellent! Perfect score!\n";
    else if (score > (int)quiz.size() / 2) cout << "Good job!\n";
    else cout << "Keep learning! You can do better.\n";

    //Accuracy + Progress Bar + Color
    double accuracy = (double)score / quiz.size() * 100.0;

    // Set color
    string color;
    if (accuracy < 50.0)
        color = "\033[31m";  // red
    else if (accuracy < 80.0)
        color = "\033[33m";  // yellow
    else
        color = "\033[32m";  // green

}
//MENU
void menu() {
    vector<Question> quiz = {
        {"What is the capital of Bulgaria?",
         {"1) Plovdiv", "2) Sofia", "3) Varna"}, 2},

        {"In which year did Bulgaria join the EU?",
         {"1) 2007", "2) 2004", "3) 2012"}, 1},

        {"What is the highest peak in Bulgaria?",
         {"1) Musala", "2) Cherni Vrah", "3) Vihren"}, 1},

        {"Which city is known as the Sea Capital of Bulgaria?",
         {"1) Burgas", "2) Varna", "3) Sozopol"}, 2},

        {"Who wrote the novel 'Under the Yoke'?",
         {"1) Ivan Vazov", "2) Hristo Botev", "3) Elin Pelin"}, 1},

        {"Which river is the longest in Bulgaria?",
         {"1) Danube", "2) Maritsa", "3) Iskar"}, 3}
    };

    while (true) {
        cout << "\n============================\n";
        cout << "          QUIZ GAME\n";
        cout << "============================\n";
        cout << "1) Start Quiz\n";
        cout << "2) Help\n";
        cout << "3) Exit\n";
        cout << "Choose an option:\n";

        int choice = safeInputInt(1, 3);

        if (choice == 1) {
            startQuiz(quiz);

            cout << "\nDo you want to try again?\n";
            cout << "1) Yes\n2) No\n";

            int repeat = safeInputInt(1, 2);
            if (repeat == 2) {
                cout << "Goodbye!\n";
                break;
            }
        }
        else if (choice == 2) {
            cout << "\n------ HELP MENU ------\n";
            cout << "• Press 1 to start the quiz.\n";
            cout << "• Choose the correct answer by typing 1, 2 or 3.\n";
            cout << "• After completing the quiz, you will see your score.\n";
            cout << "• The program accepts ONLY valid menu options.\n";
            cout << "-----------------------\n\n";

        }
        else if (choice == 3) {
            cout << "Goodbye!\n";
            break;
        }
    }
}

int main() {
    menu();
    return 0;
}