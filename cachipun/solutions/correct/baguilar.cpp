#include <iostream>
#include <vector>

using namespace std;

struct RoundTotal {
    int rocks;
    int papers;
    int scissors;
};

void score_round(std::vector<int> &scores, const std::vector<int> &plays, const RoundTotal &round_total) {
    int rock_total = round_total.scissors - round_total.papers;
    int paper_total = round_total.rocks - round_total.scissors;
    int scissors_total = round_total.papers - round_total.rocks;
    for (int i = 0; i < plays.size(); i++) {
            if (plays[i] == 0) {
                scores[i] += rock_total;
            } else if (plays[i] == 1) {
                scores[i] += paper_total;
            } else if (plays[i] == 2) {
                scores[i] += scissors_total;
            } else {
                cout << "assert! found " << scores[i] << endl;
                return;
            }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    std::vector<int> score(n, 0);
    for (int i = 0; i < k; i++) {
    std::vector<int> round(n, -1);
    RoundTotal round_total = {0, 0, 0};
        for (int j = 0; j < n; j++) {
            cin >> round[j];
            if (round[j] == 0) {
                round_total.rocks++;
            } else if (round[j] == 1) {
                round_total.papers++;
            } else if (round[j] == 2) {
                round_total.scissors++;
            } else {
                cout << "assert! round: " << round[j] << endl;
                return 1;
            }
        }
        score_round(score, round, round_total);
    }
    for (auto player_score : score) {
        cout << player_score << " ";
    }
    cout << endl;
    return 0;
}