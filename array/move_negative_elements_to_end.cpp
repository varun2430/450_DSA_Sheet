#include<iostream>
#include<vector>

// Time Complexity : O(n) 
// Auxiliary space : O(n)
void moveNegative(int arr[], int n)
{
    std::vector<int> v;

    int itr=0;
    for(int i=0 ; i < n ; i++)
    {
        if(arr[i] < 0)
        {
            v.push_back(arr[i]);
        }

        if(arr[i] >= 0)
        {
            arr[itr] = arr[i];
            itr++;
        }
    }

    int k=0;
    while(itr < n)
    {
        arr[itr] = v[k];
        itr++;
        k++;
    }
}

// can be implemented in constant time using modified insersion sort

void print_array(int arr[], int n)
{
    for(int i=0 ; i < n ; i++)
    {
        std::cout << arr[i] << "  ";
    }
    std::cout << std::endl;
}

int main()
{
    int arr[] = {1, -1, 3, 2, -7, -5, 11, 6 };
    const int n = sizeof(arr) / sizeof(arr[0]);

    print_array(arr, n);
    moveNegative(arr, n);
    print_array(arr, n);

    return 0;
}
