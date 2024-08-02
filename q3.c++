#include <iostream>
#include <vector>

using namespace std;

struct Soldier {
    int x, y;
};

class Castle {
public:
    Castle(int startX, int startY) : x(startX), y(startY) {}

    void move(int newX, int newY) {
        x = newX;
        y = newY;
    }

    void kill(int targetX, int targetY) {
        cout << "Kill (" << targetX << "," << targetY << "). Turn Left" << endl;
    }

    void jump(int targetX, int targetY) {
        cout << "Jump (" << targetX << "," << targetY << ")" << endl;
    }

    void arrive() {
        cout << "Arrive (" << x << "," << y << ")" << endl;
    }

    int getX() const { return x; }
    int getY() const { return y; }

private:
    int x, y;
};

void showPaths(Castle& castle) {
    cout << "Path 1" << endl;
    cout << "======" << endl;
    cout << "Start (" << castle.getX() << "," << castle.getY() << ")" << endl;
    castle.kill(1, 9);
    castle.jump(5, 9);
    castle.kill(8, 9);
    castle.kill(8, 2);
    castle.jump(4, 2);
    castle.arrive();

    cout << endl << "Path 2" << endl;
    cout << "======" << endl;
    cout << "Start (" << castle.getX() << "," << castle.getY() << ")" << endl;
    castle.kill(1, 9);
    castle.kill(5, 9);
    castle.kill(5, 6);
    castle.kill(2, 6);
    castle.kill(2, 8);
    castle.kill(4, 8);
    castle.jump(4, 2);
    castle.kill(4, 1);
    castle.arrive();
}

int main() {
    int numSoldiers;
    cout << "find_my_home_castle –soldiers ";
    cin >> numSoldiers;

    vector<Soldier> soldiers(numSoldiers);
    for (int i = 0; i < numSoldiers; ++i) {
        cout << "Enter coordinates for soldier " << (i + 1) << ": ";
        cin >> soldiers[i].x >> soldiers[i].y;
    }

    int startX, startY;
    cout << "Enter the coordinates for your \"special\" castle: ";
    cin >> startX >> startY;

    Castle castle(startX, startY);
    showPaths(castle);

    return 0;
}
