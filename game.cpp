#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Question {
    string text;
    vector<string> answers;
    int correct;
};

int main() {
    vector<Question> quiz = {
        {
            "What is the capital of Bulgaria?",
            {"1) Plovdiv", "2) Sofia", "3) Varna"},
            2
        },
        {
            "In which year did Bulgaria join the EU?",
            {"1) 2007", "2) 2004", "3) 2012"},
            1
        },
        {
            "What is the highest peak in Bulgaria?",
            {"1) Musala", "2) Cherni Vrah", "3) Vihren"},
            1
        },
        {
            "Which city is known as the Sea Capital of Bulgaria?",
            {"1) Burgas", "2) Varna", "3) Sozopol"},
            2
        },
        {
            "Who wrote the novel 'Under the Yoke'?",
            {"1) Ivan Vazov", "2) Hristo Botev", "3) Elin Pelin"},
            1
        },
        {
            "Which river is the longest in Bulgaria?",
            {"1) Danube", "2) Maritsa", "3) Iskar"},
            3
        }
    };

    int score = 0;
    int a;

    for (int i = 0; i < quiz.size(); i++) {
        cout << quiz[i].text << "\n";
        for (auto& ans : quiz[i].answers) cout << ans << "\n";
        cin >> a;
        if (a == quiz[i].correct) score++;
    }

    cout << "Score: " << score << "/" << quiz.size() << endl;
    return 0;
}
