#include <iostream>
using namespace std;

int main() {
    int N;
    int R = 0, B = 0;
    
    cin >> N >> R >> B;

    int remains = N - (R + B);

    if (R > B + remains) {
        cout << "Yes" << endl;
    } else if (B > R + remains) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
