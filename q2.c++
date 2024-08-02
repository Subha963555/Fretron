#include <iostream>
#include <vector>

using namespace std;

struct Fru {
    int m;
    bool a;
};

void dis(vector<Fru>& fs, int a, int b, int c) {
    int t = 0;
    int at = 0;
    int bt = 0;
    int ct = 0;

    for (const auto& f : fs) {
        t += f.m;
    }

    int ag = (t * a) / 100;
    int bg = (t * b) / 100;
    int cg = (t * c) / 100;

    for (auto& f : fs) {
        if (!f.a) {
            if (at + f.m <= ag) {
                at += f.m;
                f.a = true;
            } else if (bt + f.m <= bg) {
                bt += f.m;
                f.a = true;
            } else if (ct + f.m <= cg) {
                ct += f.m;
                f.a = true;
            }
        }
    }

    cout << "A: ";
    for (const auto& f : fs) {
        if (f.a && at - f.m >= 0) {
            cout << f.m << " ";
            at -= f.m;
        }
    }
    cout << endl;

    cout << "B: ";
    for (const auto& f : fs) {
        if (f.a && bt - f.m >= 0) {
            cout << f.m << " ";
            bt -= f.m;
        }
    }
    cout << endl;

    cout << "C: ";
    for (const auto& f : fs) {
        if (f.a && ct - f.m >= 0) {
            cout << f.m << " ";
            ct -= f.m;
        }
    }
    cout << endl;
}

int main() {
    vector<Fru> fs;
    int m;

    cout << "Enter mass in grams (-1 to stop): ";
    while (true) {
        cin >> m;
        if (m == -1) break;
        fs.push_back({m, false});
    }

    int a = 50;
    int b = 30;
    int c = 20;

    dis(fs, a, b, c);

    return 0;
}
