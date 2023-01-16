#include<iostream>

void getMinMax(int arr[], int n)
{
    if(n == 1)
    {
        std::cout << "max: " << arr[0] << std::endl;
        std::cout << "min: " << arr[0] << std::endl;
    }

    int max=0, min=0;
    if(arr[0] > arr[1])
    {
        max = arr[0];
        min = arr[1];
    }
    else
    {
        max = arr[1];
        min = arr[0];
    }

    for(int i=2 ; i < n ; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }

        if(arr[i] < min)
        {
            min = arr[i];
        }
    }

    std::cout << "max: " << max << std::endl;
    std::cout << "min: " << min << std::endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    const int n = sizeof(arr) / sizeof(arr[0]);

    getMinMax(arr, n);

    return 0;
}
