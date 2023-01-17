#include<iostream>

void printSpiral(int arr[4][4], int row, int col)
{
    int srow=0, erow=row;
    int scol=0, ecol=col;

    while(srow < erow && scol < ecol)
    {
        // right
        for(int i=scol ; i < ecol ; i++)
        {
            std::cout << arr[srow][i] << "  ";
        }
        srow++;

        // down
        for(int i=srow ; i < erow ; i++)
        {
            std::cout << arr[i][ecol-1] << "  ";
        }
        ecol--;

        // left
        if(srow < erow)
        {
            for(int i=ecol-1 ; i >= scol ; i--)
            {
                std::cout << arr[erow-1][i] << "  ";
            }
            erow--;
        }

        // up
        if(scol < ecol)
        {
            for(int i=erow-1 ; i >= srow ; i--)
            {
                std::cout << arr[i][scol] << "  ";
            }
            scol++;
        }
    }
}

int main()
{
    const int row=4, col=4;
    int arr[row][col] = {   { 1, 2, 3, 4 },
                            { 5, 6, 7, 8 },
                            { 9, 10, 11, 12 },
                            { 13, 14, 15, 16 }  };
  
    printSpiral(arr, row, col);
    return 0;
}