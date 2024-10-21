// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
    //Да се напише програма, която прочита от конзолата цяло нечетно число n и чертае вертикална стрелка 
    
    int number;
    cin>>number;
    
    int rows = number * 2 - 1;
    int cols = rows;
    
    
    // Брой точки, след които започват специалните символи 
    int intervalOfDots = ( cols - number ) / 2;
    
    // Две променливи за началния и крайния специален символ
    int mostLeftSymbol = 0; int mostRightSymbol=0;

    for(int currentRow = 1; currentRow<=rows;currentRow++)
    {
        //Ще разделим печатането на стрелката на три части - горна, средна и долна
        
        //Горна част
        if(currentRow<number)
            {
                mostLeftSymbol = intervalOfDots + 1;
                mostRightSymbol = mostLeftSymbol + number - 1;
                
                for(int currentCol = 1; currentCol<=cols;currentCol++)
                {
                    if(currentCol < mostLeftSymbol || currentCol > mostRightSymbol)
                    {
                        cout<<".";
                    }
                    else if(currentRow==1 || (currentCol == mostLeftSymbol || currentCol == mostRightSymbol))
                    {
                        // Ако сме на първия ред, то всички символи между най-левия и най-десния също са специални символи
                        // В другия случай отпечатваме специален символ само ако сме на индекса на някой от крайните специални символи
                        
                        cout<<"#";
                    }
                    else{
                        cout<<".";
                    }
                }
                
                //В края добавяме нов ред
                cout<<endl;
            }
            
            //Средна част
            else if(currentRow == number)
            {
                // Единствено между най-левия и най-десния символ ще има точки
                for(int currentCol = 1;currentCol <= cols; currentCol++)
                {
                    if(currentCol > mostLeftSymbol && currentCol < mostRightSymbol)
                    {
                        cout<<".";
                    }
                    else{
                        cout<<"#";
                    }
                }
                
                //В края добавяме нов ред
                cout<<endl;
                
                //Също променяме мястото на крайния ляв и десен специален елемент
            mostLeftSymbol = 2; mostRightSymbol = cols - 1;

            }
            //Долна част
            else{
                //Сменяме индекса на най-левия и най-десния специален елемент
                for(int currentCol =1;currentCol <= cols;currentCol++)
                {
                    if(currentCol == mostLeftSymbol || currentCol == mostRightSymbol)
                    {
                        cout<<"#";
                    }
                    else{
                        cout<<".";
                    }
                }
                
                // Местим крайния ляв и крайния десен индекс една позиция навътре
                mostLeftSymbol++; mostRightSymbol--;
                
                cout<<endl;
                
            }
        
    }
    
    return 0;
}
