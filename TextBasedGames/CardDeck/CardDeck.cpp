#include <iostream>
#include <string>

using namespace std;

int main () {
    char suites[] = { 'c', 'h', 's', 'd' };
    string ranks[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };

    for (int r = 0; r < (sizeof(ranks) / sizeof(string)); r++) {
        for (int s = 0; s < (sizeof(suites) / sizeof(char)); s++) {
            cout << ranks[r] << suites[s] << " ";
        }
        cout << endl;
    }

    system("pause");

    return 0;
}