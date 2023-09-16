// Different ways to pass 2D-array as arguments
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void normalArray(int mat[3][2])
{
    cout<<"noraml 2D-array"<<endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
}
void DoublePointer(int **mat, int m, int n)
{
    cout << "double pointer"
         << "\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat[i][j] = 10;
            cout << mat[i][j] << " ";
        }
        cout << " \n";
    }
}
void ArrayOfPointer(int *mat[], int m, int n)
{
    cout << "array of pointers"
         << "\n";
    for (int i = 0; i < m; i++) // printing
    {
        for (int j = 0; j < n; j++)
        {
            mat[i][j] = 11;
            cout << mat[i][j] << " ";
        }
        cout << " \n";
    }
}
void ArrayOfVector(vector<int> mat[], int m)
{
    cout << "Array of vector"
         << "\n";
    for (int i = 0; i < m; i++) // printing
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
void vectorOFvector(vector<vector<int>> &mat)
{
    cout << "Vectors of Vectors vector<vector<int>>"
         << "\n";
    for (int i = 0; i < mat.size(); i++) // printing
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    // noraml 2D-array
    int ar[3][2] = {{10, 20},
                    {30, 40},
                    {50, 60}};
    normalArray(ar);

    
    
    // using double pointer
    int **arr;
    int m = 3, n = 2;
    arr = new int *[m];                                 // allocating a array of pointersof size[m]
    for (int i = 0; i < m; i++)
    {
        arr[i] = new int[n];                            // each element of array of pointers piont at a array of size(n)
    }
    DoublePointer(arr, m, n);

    
    
    
    // using Array pointer
    int *arr1[m];                                       // array of pointers
    for (int i = 0; i < m; i++)                         // creating 2D-array of size (m*n)
    {
        arr1[i] = new int[n];
    }
    ArrayOfPointer(arr1, m, n);

    
    
    // using Array of vector
    vector<int> arr2[m];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr2[i].push_back(12);
        }
    }
    ArrayOfVector(arr2, m);

    
    // using vector fo vector
    vector<vector<int>> a1;
    for (int i = 0; i < m; i++)
    {
        vector<int> v;
        for (int j = 0; j < n; j++)
        {
            v.push_back(13);
        }
        a1.push_back(v);
    }
    vectorOFvector(a1);

    return 0;
}
