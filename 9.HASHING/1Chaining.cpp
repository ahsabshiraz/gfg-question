// CHAINING
#include <iostream>
#include <list>
using namespace std;

struct MyHash
{
    int BUCKET;
    list<int> *table;
    MyHash(int b)
    {
        BUCKET = b;
        table = new list<int>[b];
    }
    void insert(int key)
    {
        int i = key % BUCKET;
        table[i].push_back(key);
    }
    void remove(int key)
    {
        int i = key % BUCKET;
        table[i].remove(key);
    }
    bool search(int key)
    {
        int i = key % BUCKET;
        for (auto x : table[i])
            if (x == key)
                return true;
        return false;
    }
};

int main()
{
    MyHash h(5);
    h.insert(10);
    h.insert(15);
    h.insert(20);
    h.insert(25);
    h.insert(30);
    bool result = h.search(23);
    cout << result;
    for (int n : h.table[0])
        cout << n << " ";

    return 0;
}
