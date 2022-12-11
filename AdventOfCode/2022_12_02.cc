/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    char me, them;
    unordered_map<char, int> shape_score;
    int score = 0;
    shape_score['X'] = 1; // Rock
    shape_score['Y'] = 2; // Paper
    shape_score['Z'] = 3; // Sicssors 

    shape_score['A'] = 1; // Rock
    shape_score['B'] = 2; // Paper
    shape_score['C'] = 3; // Sicssors
    
    while (cin >> me >> them) {
        if (shape_score[me] == shape_score[them]) {
            score += shape_score[me] + 3;
        } else if (shape_score[me] - shape_score[them] == 1 || shape_score[me] - shape_score[them] == -2) {
            score += shape_score[me] + 6;
        } else {
            score += shape_score[me];
        }
    }
    cout << score << endl;
    return 0;
}
