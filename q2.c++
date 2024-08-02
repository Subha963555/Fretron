#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Apple {
    int weight;
    bool allocated;
};

int calculateTargetWeight(int totalWeight, int share) {
    return (totalWeight * share) / 100;
}

void distributeApples(vector<Apple>& apples, int ramShare, int shamShare, int rahimShare) {
    vector<Apple> ramApples, shamApples, rahimApples;
    int totalWeight = 0;

    for (const auto& apple : apples) {
        totalWeight += apple.weight;
    }

    int ramTarget = calculateTargetWeight(totalWeight, ramShare);
    int shamTarget = calculateTargetWeight(totalWeight, shamShare);
    int rahimTarget = calculateTargetWeight(totalWeight, rahimShare);

    sort(apples.begin(), apples.end(), [](const Apple& a, const Apple& b) {
        return a.weight > b.weight;
    });

    for (auto& apple : apples) {
        if (!apple.allocated) {
            if (ramTarget >= apple.weight) {
                ramApples.push_back(apple);
                ramTarget -= apple.weight;
                apple.allocated = true;
            } else if (shamTarget >= apple.weight) {
                shamApples.push_back(apple);
                shamTarget -= apple.weight;
                apple.allocated = true;
            } else if (rahimTarget >= apple.weight) {
                rahimApples.push_back(apple);
                rahimTarget -= apple.weight;
                apple.allocated = true;
            }
        }
    }

    cout << "Distribution Result:" << endl;
    cout << "Ram : ";
    for (const auto& apple : ramApples) {
        cout << apple.weight << " ";
    }
    cout << endl;

    cout << "Sham : ";
    for (const auto& apple : shamApples) {
        cout << apple.weight << " ";
    }
    cout << endl;

    cout << "Rahim : ";
    for (const auto& apple : rahimApples) {
        cout << apple.weight << " ";
    }
    cout << endl;
}

int main() {
    vector<Apple> apples;
    int weight;

    cout << "Enter apple weight in gram (-1 to stop): ";
    while (true) {
        cin >> weight;
        if (weight == -1) break;
        apples.push_back({weight, false});
    }

    int ramShare = 50;
    int shamShare = 30;
    int rahimShare = 20;

    distributeApples(apples, ramShare, shamShare, rahimShare);

    return 0;
}
