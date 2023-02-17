#include <iostream>
#include<vector>
using namespace std;

void threeWayPartition(vector<int>& array, int a, int b)
{
    int left = 0;
    int right = array.size() - 1;

    for (int i = 0; i <= right; i++)
    {
        if (array[i] < a)
        {
            swap(array[i], array[left]);
            left++;
        }
        else if (array[i] > b)
        {
            swap(array[i], array[right]);
            right--;
            i--;
        }
    }
}

void printArray(vector<int>& array)
{
    for(int& num : array)
    {
        cout << num << "  ";
    }
    cout << endl;
}

int main()
{
    vector<int> array = {1, 14, 5, 20, 4, 2, 54, 20, 87, 98, 3, 1, 32};

    printArray(array);
    threeWayPartition(array, 14, 20);
    printArray(array);

    return 0;
}
