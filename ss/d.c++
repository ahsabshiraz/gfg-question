#include <bits/stdc++.h>
using namespace std;

void findOctalPermission(string permission) {
    stringstream ss(permission);
    string part;
    int userPerm = 0, groupPerm = 0, otherPerm = 0;

    // Lambda function to convert permissions to octal
    auto permToNum = [](const string &p) {
        int val = 0;
        if (p.find('r') != string::npos) val += 4;
        if (p.find('w') != string::npos) val += 2;
        if (p.find('x') != string::npos) val += 1;
        return val;
    };

    // Splitting input by ',' and processing each part
    while (getline(ss, part, ',')) {
        if (part.size() < 3 || part[1] != '=') continue; // Validate input format
        char who = part[0];
        string perms = part.substr(2);
        int numericVal = permToNum(perms);

        // Assigning permissions
        if (who == 'u') userPerm = numericVal;
        else if (who == 'g') groupPerm = numericVal;
        else if (who == 'o') otherPerm = numericVal;
    }

    // Printing the final octal permission value
    cout << userPerm << groupPerm << otherPerm << endl;
}

int main() {
    string input;
    getline(cin, input);
    findOctalPermission(input);
    return 0;
}
