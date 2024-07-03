#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    for (int i = 0; i < skill_trees.size(); i++) {
        int skill_count = 0;
        string k = skill_trees[i];
        bool is_valid = true;
        for (int e = 0; e < k.length(); e++) {
            for (int j = 0; j < skill.length(); j++) {
                if (k[e] == skill[j]) {
                    if (j == skill_count) {
                        skill_count++;
                    } else {
                        is_valid = false;
                        break;
                    }
                }
            }
            if (!is_valid) break;
        }
        if (is_valid) answer++;
    }

    return answer;
}
