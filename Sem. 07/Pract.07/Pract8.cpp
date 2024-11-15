 
#include <iostream>

using namespace std;

constexpr int SIZE = 100; const char specialSymbol = '^';


bool PointsAreColinear(int x1, int y1, int x2, int y2, int x3, int y3)
{
    //Правило на Сарус
    return (x1 * y2 + y1 * x3 + x2 * y3 - y1 * x2 - x1 * y3 - y2 * x3 == 0);


}



int main()
{
    int n; int m;
    cin >> n >> m;

    int counter = 0;

    int counterSymbols = 0;
    int coordinateX[SIZE];
    int coordinateY[SIZE];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char symbol;
            cin >> symbol;
            if (symbol == specialSymbol)
            {
                coordinateX[counterSymbols] = i;
                coordinateY[counterSymbols] = j;

                counterSymbols++;
                
            }

        }
    }

    int x1 = 0; int y1 = 0; int x2 = 0; int y2 = 0; int x3 = 0; int y3 = 0;
    bool elementsOnSameRow = false;

    for (int i = 0; i < counterSymbols; i++)
    {
        elementsOnSameRow = false;
        x1 = coordinateX[i]; y1 = coordinateY[i];

        for (int j = i + 1; j < counterSymbols; j++)
        {
            x2 = coordinateX[j]; y2 = coordinateY[j];

            for (int s = j + 1; s < counterSymbols; s++)
            {
                x3 = coordinateX[s]; y3 = coordinateY[s];

                if (!PointsAreColinear(x1, y1, x2, y2, x3, y3))
                {
                    counter++;
                }

            }
        }

        
    }

    cout << counter;

}

 
