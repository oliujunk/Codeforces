#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <stack>
#include <map>
#include <queue>
using namespace std;

struct cost {
    int p;
    int v;
    bool operator < (const cost& a) const {
        return v < a.v; 
    }
};

cost make(int p, int v) {
    cost ret;
    ret.p = p;
    ret.v = v;
    return ret;
}

char str[50004];
int main() {
    freopen("C:\\Users\\XPH\\Desktop\\input.txt", "r", stdin);
    freopen("C:\\Users\\XPH\\Desktop\\output.txt", "w", stdout);
    scanf("%s", str);
    int cnt = 0;
    int len = strlen(str);
    int a, b;
    priority_queue<cost> q;

    long long ans = 0;
    for (int i = 0; i < len; i++) {
        cnt += str[i] == '(';
        cnt -= str[i] == ')' || str[i] == '?';

        if (str[i] == '?') {
            scanf("%d %d", &a, &b);
            q.push(make(i, b-a));
            ans += b;
            str[i] = ')';
        }

        if (cnt < 0 && q.empty()) {
            ans = -1;
            break;
        }

        if (cnt < 0) {
            cost top = q.top();
            q.pop();
            ans = ans - top.v;
            str[top.p] = '(';
            cnt += 2;
        }
    }

    if (cnt > 0) ans = -1;
    printf("%I64d\n", ans);
    if (ans != -1) printf("%s\n", str);

    return 0;
}