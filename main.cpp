#include <iostream>
#include <math.h> 
#include <string>
#include <cmath>
using namespace std;

const int size = 100;

void tuttobianco(char matrix[][size], int size2){

    //for per metter tutto come ' '
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matrix[i][j]=' ';   
        }        
    }
}

void disegnografico(char matrix[][size], int size){
    for (int i = 0; i < size; i++)
    {
        //quadrato
        matrix[0][i]='*';
        matrix[i][0]='*';
        matrix[i][size-1]='*';
        matrix[size-1][i]='*';

        //assi
        matrix[i][size/2]='|';
        matrix[size/2][i]='-';
    }
            
    //visualizzazione grafico
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout<<" "<<matrix[i][j];
        }
        cout<<endl;
    }
}

int main(){

    cout<<"Menu"<<endl;
    cout<<"1. Funzione esponenziale"<<endl;
    cout<<"2. Parabola"<<endl;
    cout<<"3. y = -x"<<endl;
    cout<<"4. curva sinuisale"<<endl;
    int option;
    cin>>option;
    
    switch (option)
    {
        case 1:
        {
            float a, y;
            float px;
            float py;
            char matrix[size][size]; 

            px = size/2;
            py = size/2;
    
            cout<<"Inserisci la base della funzione"<<endl;
            cin>>a;

            tuttobianco(matrix, size);
            
            for (float x = -px; y < size/2-1; x++)
            {

                y = pow(a,x);   

                if (y < size)
                {
                    matrix[int(-y+py)][int(x+px)]='O';
                }
            }

            disegnografico(matrix, size);
            system("PAUSE");   
        }
        break;

        case 2:
        {
            float y, a, b, c;
            int px = size/2;
            int py = size/2;

            cout<<"a: ";
            cin>>a;
            cout<<"b: ";
            cin>>b;
            cout<<"c: ";
            cin>>c;

            //crezione matrice
            char matrix[size][size]; 

            tuttobianco(matrix, size);

            for (float x = -px; x < size/2-1; x++)
            {

                y = a*pow(x,2) + b*x + c;

                if (y < size)
                {
                    matrix[int(-y+py)][int(x+px)]='O';
                }
            }

            disegnografico(matrix, size);
            system("PAUSE");
        }
        break;
        
        case 3:
        {
            float y;
            int px = size/2;
            int py = size/2;

            //crezione matrice
            char matrix[size][size]; 

            tuttobianco(matrix, size);

            for (float x = -px; x < size/2-1; x++)
            {

                y = -x;

                if (y < size)
                {
                    matrix[int(-y+py)][int(x+px)]='O';
                }
            }

            disegnografico(matrix, size);
            system("PAUSE");
        }
        break;
    
        case 4:
        {
            double y;
            int px = size/2;
            int py = size/2;

            double pi = 2*acos(0.0); //pie 3.14

            double A = 5; // AMPIEZZA
            double LD = 10; //lunghezza d'onda
            double V = 2; //VELOCITà
            char matrix[size][size]; 

            cout<<"Parametri"<<endl;
            cout<<"Ampiezza: ";
            cin>>A;
            cout<<"Velocità: ";
            cin>>V;
            cout<<"Lunghezza d'onda: ";
            cin>>LD;

            double T = LD/V; //periodo
            double F = 1/T; //frequenta
            double K = (2 * pi)/LD; //numero do'onda
            double W = (2 * pi)/T; //Pulsazione

            tuttobianco(matrix, size);

            for (float x = -px; x < size/2-1; x++)
            {
                //l'equazione dell'onda
                y = A*sin(K*x-W*T); 

                if (y < size)
                {
                    matrix[int(-y+py)][int(x+px)]='O';
                }
            }
            
            disegnografico(matrix, size);

            system("PAUSE");
        }
        break;
    }
}
