#include <bits/stdc++.h>

using namespace std;

int main()
{
    char c, c1;
    int col = 0, row;
    cin >> col >> c;
    if(col % 2 == 1)
        row = col / 2 +1;
    else
    {
        row = col / 2;
    }
    
    for (int i = 0; i < col; i++)
    {
        cout << c;
    }
    printf("\n");
    for (int i = 2; i < row; i++)
    {
        cout << c;
        for (int j = 0; j < col-2; j++)
        {
            cout << " ";
        }
        printf("%c\n", c);
    }
    for (int i = 0; i < col; i++)
    {
        cout << c;
    }
    

    return 0;
}