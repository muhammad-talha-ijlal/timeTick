#include <iostream>
using namespace std;

const int size = 20;
char arr[size][size];
int grid = 0;
void fillGrid()
{
    for (int i = 0; i < grid; i++)
    {
        for (int j = 0; j < grid; j++)
        {
            int random = rand();
            if (random % 2 == 0)
            {
                arr[i][j] = '#';
            }
            else
            {
                arr[i][j] = '-';
            }
        }
    }
}
char temp[size];
bool gravity = false;
bool isBlackHole = false;
void displayBoard()
{
    system("cls");
    cout << "\n\n\n";
    for (int i = 0; i < grid; i++)
    {
        cout << "\t\t";
        for (int j = 0; j < grid; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl
         << endl
         << endl;
}

void updateBoard()
{
    if (gravity)
    {
        if (isBlackHole)
        {
            for (int i = 0; i < grid; i++)
            {
                temp[i] = arr[grid - 1][i];
                arr[grid - 1][i] = '-';
            }
        }
        for (int i = grid - 2; i >= 0; i--)
        {
            for (int j = 0; j < grid; j++)
            {
                if (arr[i][j] == '#' && arr[i + 1][j] == '-')
                {
                    arr[i][j] = '-';
                    arr[i + 1][j] = '#';
                }
            }
        }
        if (isBlackHole)
        {
            for (int i = 0; i < grid; i++)
            {
                arr[0][i] = temp[i];
            }
        }
    }
}

main()
{
    cout << "Enter Grid Size(1-20): ";
    cin >> grid;
    fillGrid();
    cout << "Turn Gravity On? (Y/N): ";
    char response;
    cin >> response;
    if (response == 'Y')
    {
        gravity = true;
    }
    else
    {
        gravity = false;
    }
    cout << "Turn BlackHole effect on? (Y/N): ";
    cin >> response;
    if (response == 'Y')
    {
        isBlackHole = true;
    }
    else
    {
        isBlackHole = false;
    }
    cout << "Enter times: ";
    int time;
    cin >> time;
    for (int k = 0; k < time; k++)
    {
        system("pause");
        displayBoard();
        updateBoard();
    }
}