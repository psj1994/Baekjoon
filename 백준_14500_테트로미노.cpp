#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
vector<vector<string>> blocks = {
    {"1111"},
    {"11",
     "11"},
    {"10",
     "10",
     "11"},
    {"10",
     "11",
     "01"},
    {"111",
     "010"}
};
vector<string> mirror(vector<string> &b) {
    vector<string> ans(b.size());
    for (int i=0; i<b.size(); i++) {
        string temp(b[i]);
        reverse(temp.begin(), temp.end());
        ans[i] = temp;
    }
    return ans;
}
vector<string> rotate(vector<string> &b) {
    vector<string> ans(b[0].size());
    for (int j=0; j<b[0].size(); j++) {
        for (int i=(int)b.size()-1; i>=0; i--) {
            ans[j] += b[i][j];
        }
    }
    return ans;
}
int calc(vector<vector<int>> &a, vector<string> &b, int x, int y) {
    int n = a.size();
    int m = a[0].size();
    int sum = 0;
    for (int i=0; i<b.size(); i++) {
        for (int j=0; j<b[0].size(); j++) {
            if (b[i][j] == '0') continue;
            int nx = x+i;
            int ny = y+j;
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                sum += a[nx][ny];
            } else {
                return -1;
            }
        }
    }
    return sum;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            for (auto &block : blocks) {
                vector<string> b(block);
                for (int mir=0; mir<2; mir++) {
                    for (int rot=0; rot<4; rot++) {
                        int cur = calc(a, b, i, j);
                        if (cur != -1 && ans < cur) {
                            ans = cur;
                        }
                        b = rotate(b);
                    }
                    b = mirror(b);
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
