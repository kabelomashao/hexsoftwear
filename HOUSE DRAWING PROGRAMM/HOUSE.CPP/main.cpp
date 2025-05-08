#include <iostream>

using namespace std;

void drawHouse(int width, int height) {
    int roofWidth = width / 2;

    // Draw Roof
    for (int i = 0; i <= roofWidth; i++) {
        for (int j = 0; j < roofWidth - i; j++)
            cout << " ";
        for (int j = 0; j < (2 * i + 1); j++)
            cout << "*";
        cout << endl;
    }

    // Draw Walls
    for (int i = 0; i < height; i++) {
        cout << "|";
        for (int j = 0; j < width; j++)
            cout << " ";
        cout << "|" << endl;
    }

    // Draw Door and Windows
    cout << "|  []  []  |" << endl;
    cout << "|    ||    |" << endl;
    cout << "|__________|" << endl;
}

int main() {
    int width, height;

    cout << "Enter house width: ";
    cin >> width;
    cout << "Enter house height: ";
    cin >> height;

    cout << "\nHere is your ASCII house:\n";
    drawHouse(width, height);

    return 0;
}
