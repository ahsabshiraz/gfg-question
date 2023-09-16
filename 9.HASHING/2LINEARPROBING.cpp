// OPEN ADDRESSING 
// LINEAR PROBING
#include <iostream>
using namespace std;
struct Myhash
{
    int *arr;
    int cap, size;
    Myhash(int c)
    {
        cap = c;
        size = 0;
        arr = new int[cap];
        for (int i = 0; i < cap; i++)
        {
            arr[i] = -1;
        }
    }
    int hash(int key)
    {
        return key % cap;
    }
    bool search(int key)
    {
        int h = hash(key);
        int i = h;
        while (arr[i] != -1)
        {
            if (arr[i] == key)
            {
                return true;
            }
            i = (i + 1) % cap;    //moving to next index
            if (i == h)           //we have iterated through whole the array
            {
                return false;
            }
        }
        return false;
    }

    bool insert(int key)
    {
        if (size == cap)
            return false;
        int i = hash(key);
        while (arr[i] != -1 && arr[i] != -2 && arr[i] != key)
        {
            i = (i + 1) % cap;
        }
        if (arr[i] == key)
        {
            return false;
        }
        else
        {
            arr[i] = key;
            size++;
            return true;
        }
    }

    bool erase(int key)
    {
        int h = hash(key);
        int i = h;
        while (arr[i] != -1)
        {
            if (arr[i] == key)
            {
                arr[i] = -2;
                return true;
            }
            i = (i + 1) % cap;
            if (i == h) // IF we have traversed through whole list item not found then return false.
            {
                return false;
            }
          
        }
        return false;// if it does'nt get in the while loop return false.
    }
};
int main()
{
    Myhash mh(5);
    mh.insert(25);
    mh.insert(78);
    mh.insert(23);
    mh.insert(67);
    mh.insert(35);
    cout<<mh.search(23)<<"\n";
    cout<<mh.erase(23)<<"\n";
    cout<<mh.search(23)<<"\n";
    return 0;
}