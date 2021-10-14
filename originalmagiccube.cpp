#include <iostream>
#include <cstring>

using namespace std;


void generateCube(int n,int r, int c, int h) {
    int cube[n][n][n] ;
    memset(cube,0,sizeof(cube));
   
    int row = r , col = c, hei = h;
    for(int num = 1; num<=27; num++)
    {
         if(num==19)
           { cout<<hei<<row<<col;
                cout<<endl;
           }
       
       
        if(cube[hei][row][col]==0) // If the space is empty
            cube[hei][row][col] = num;
           
        else //If the space is already filled
        {
            hei = (hei -1)%3;    // shift the height by 1
            col = (col+1)%3;    // shift the column by 1
           
            if(hei<0)
                hei = 2;

            cube[hei][row][col] = num;
        }
       
 
       
        // coordinates for next element
       
        col = (col+2)%3;     // shift column
       
        if(num%n==0)
        {
            row = (row+1)%3;   // shift row
            hei = (hei+1)%3;    // shift the surface by 1
        }
        else
        {
            row = (row+2)%3;  // shift row by 2
        }
           
       
       
    }
    //printcube(cube);
   
    for(int k =0; k<3; k++)
    {
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                cout<<" "<<cube[k][i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
}

int main()
{
   int n = 3;
   
   int row=0, col=1, height=1;
   cout<<"enter row ";
   cin>>row;
   cout<<"enter column";
   cin>>col;
   cout<<"enter height";
   cin>>height;
   
   generateCube(n,row,col,height);
   


    return 0;
}
