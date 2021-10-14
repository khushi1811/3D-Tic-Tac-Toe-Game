#include <iostream>
#include <unordered_map>
#include <stdio.h>
#include <vector>
#include <cstring>

using namespace std;


vector<int> HumanMoveslist;// vecctor that keeps list of all user's moves
vector<int> ComputerMoveslist;// vecctor that keeps list of all computer's moves
vector<int> forkList;// vecctor that keeps list of all possible fork block conditions for a particular turn
vector<int> Allnum{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27};// vecctor that keeps list of all values of a cube 

int compline=0;//keeps a record of winning lines of computer
int humanline=0;//keeps a record of winning lines of user

int x[3][3][3] =
{
{{8, 24, 10}, {12, 7, 23}, {22, 11, 9}},
{{15, 1, 26}, {25, 14, 3}, {2, 27, 13}},
{{19, 17, 6}, {5, 21, 16}, {18, 4, 20}},
};
//3d array to form 3 square boards


void humanWinLine( char c[3][3][3] , char human, int position)//function to print user's winning lines 
{
	for(int l=0; l<HumanMoveslist.size()-1; l++)
	{
		for(int t=l; t<HumanMoveslist.size()-1; t++ )
		{
			if((HumanMoveslist.at(l) + HumanMoveslist.at(t) + position)==42)//makes sure sum of the 3 elements is 42
			{
				int i, j, k;
     		    int P[3];
			    int Q[3];
			    int R[3];
				int elem1= HumanMoveslist.at(l);//saves elem1 as users first move played 
				int elem2= HumanMoveslist.at(t); //saves elem2 as users t th move played 
				for (i = 0; i < 3; i++)
								{
											for (j = 0; j < 3; j++)
												{
													for (k = 0; k < 3; k++)
												    {   
														if (x[i][j][k] == elem1 && c[i][j][k] == human )
																{
																R[0] = i; //saves dimensions of elem1
																R[1] = j;
																R[2] = k;}
															}
														}
													}
																	for (i = 0; i < 3; i++)
																		{
																		for (j = 0; j < 3; j++)
																			{
																				for (k = 0; k < 3; k++)
																					{
																					if (x[i][j][k] == elem2 && c[i][j][k] == human )
																						{
																						P[0] = i; //saves dimensions of elem2
																						P[1] = j;
																						P[2] = k;
																						break;
																						}
																					}
																			}
																		}
																	for (i = 0; i < 3; i++)
																		{
																				for (j = 0; j < 3; j++)
																					{
																						for (k = 0; k < 3; k++)
																							{
																								if (x[i][j][k] == position && c[i][j][k] == human )
																								{
																									Q[0] = i;
																									Q[1] = j;
																									Q[2] = k;
																									if((((Q[1]-P[1])*(R[2]-P[2])-(R[1]-P[1])*(Q[2]-P[2])) == 0) && (((R[0]-P[0])*(Q[2]-P[2])-(Q[0]-P[0])*(R[2]-P[2])) == 0) && (((Q[0]-P[0])*(R[1]-P[1])-(R[0]-P[0])*(Q[1]-P[1])))==0)
																									{ //checks condition of collinearity in if block
																									humanline++;//increments nuber of user's winning lines
																									cout<< "Your number of lines are: "<< humanline << endl;
																								}
																							}
																						}
			}
		}
	}
}
}
}

void printList()//prints the list of user's and computer's moves
{
   std::cout << "The elements in your list are : ";

   for(int i=0; i < HumanMoveslist.size(); i++)
   std::cout << HumanMoveslist.at(i) << ' ';
   cout<< endl;
    std::cout << "The elements in computer's list are : ";

   for(int i=0; i < ComputerMoveslist.size(); i++)
   std::cout << ComputerMoveslist.at(i) << ' ';
   cout<< endl;
	
}

int checkFork(char c[3][3][3],char computer){//this function checks the elements to find a situation where human/player can make a line
	
int vecsize1 = HumanMoveslist.size();  // size of humans move list is calculated 
int flag=0; 
     int n1;

    //int lastele1 = HumanMoveslist.at(vecsize1-1);
    int m1;
     for (m1=0; m1<vecsize1; m1++){
     	for(n1=m1+1; n1<vecsize1; n1++)
     	{
		 
     	int compare1 = HumanMoveslist.at(m1);   //considering pairs of elements from the humansmove list 
	  	int compare2 = HumanMoveslist.at(n1);  

		 	int element2 = 42 - (compare2 + compare1);// the third element of the line should have a sum of 42 with other two elements
			int i, j, k;
     		int P[3];
			int Q[3];
			int R[3];
			
				for (i = 0; i < 3; i++)
					{
					for (j = 0; j < 3; j++)
						{
							for (k = 0; k < 3; k++)
								{
								if (x[i][j][k] == compare2)// finding coordinates of the three elements considered in the loop iteration
									{
									P[0] = i;
									P[1] = j;
									P[2] = k;
									break;
									}
								}
						}
					}
				for (i = 0; i < 3; i++)
					{
							for (j = 0; j < 3; j++)
								{
									for (k = 0; k < 3; k++)
										{
											if (x[i][j][k] == compare1)// finding coordinates of the three elements considered in the loop iteration
											{
												Q[0] = i;
												Q[1] = j;
												Q[2] = k;
												break;
											}
										}
								}
						}

					if(element2 <= 27 ){
					
								for (i = 0; i < 3; i++)
										{
											for (j = 0; j < 3; j++)
												{
													for (k = 0; k < 3; k++)
												    {   
														if (x[i][j][k] == element2 && c[i][j][k] == 'I')// finding coordinates of the three elements considered in the loop iteration and checking if the element has not been marked yet
																{
																R[0] = i;
																R[1] = j;
																R[2] = k;
																if((((Q[1]-P[1])*(R[2]-P[2])-(R[1]-P[1])*(Q[2]-P[2])) == 0) && (((R[0]-P[0])*(Q[2]-P[2])-(Q[0]-P[0])*(R[2]-P[2])) == 0) && (((Q[0]-P[0])*(R[1]-P[1])-(R[0]-P[0])*(Q[1]-P[1])))==0)//checking the collinearity condition
																{
																forkList.push_back(x[i][j][k]);// a list of winning situation elements is maintained to know how many possible block moves computer has
																flag=flag+1; // tells the number of possible moves
															    cout<< flag <<" "<<x[i][j][k] << endl;
															    
																}   		
																} 
												     
													 }
											}
											
									}
									
								}
								
				
					      
}
	}

	return flag;// returns the possible moves

	
}
	
																												
void forkMove(char c[3][3][3], char computer)// considers the blocking moves computer has and further helps find the best possible alternative amongst the same
{
	 bool flag=false;// a boolean value is maintained until we find an element from fork list that can further help computer make a winning line
	 
	 for(int p=0; p<forkList.size(); p++)// taking elements from forklist one by one
	{
		for(int l=0; l<ComputerMoveslist.size(); l++)// taking elements from computer moves list one my one
		{
			for(int t=0; t<Allnum.size(); t++ )// taking all the elements  one by one
			{
			
			if((ComputerMoveslist.at(l) + forkList.at(p) + Allnum.at(t))==42)// if any three elements form a sum of 42 further conditions are checked
			{
				
				int i, j, k;
     		    int P[3];
			    int Q[3];
			    int R[3];
				int elem1= ComputerMoveslist.at(l);
				int elem2= Allnum.at(t);
				int elem3= forkList.at(p);
			
				for (i = 0; i < 3; i++)
								{
											for (j = 0; j < 3; j++)
												{
													for (k = 0; k < 3; k++)
												    {   
														if (x[i][j][k] == elem1 && c[i][j][k] == computer )// finding coordinates of the three elements considered in the loop iteration
																{
																R[0] = i;
																R[1] = j;
																R[2] = k;}
															}
														}
													}
																	for (i = 0; i < 3 ; i++)
																		{
																		for (j = 0; j < 3; j++)
																			{
																				for (k = 0; k < 3; k++)
																					{
																					if (x[i][j][k] == elem2 && c[i][j][k] == 'I' )// finding coordinates of the three elements considered in the loop iteration
																						{
																						P[0] = i;
																						P[1] = j;
																						P[2] = k;
																						break;
																						}
																					}
																			}
																		}
																	for (i = 0; i < 3; i++)
																		{
																				for (j = 0; j < 3; j++)
																					{
																						for (k = 0; k < 3; k++)
																							{
																								if (x[i][j][k] == elem3 && c[i][j][k] == 'I') // finding coordinates of the three elements considered in the loop iteration
																								{
																									Q[0] = i;
																									Q[1] = j;
																									Q[2] = k;
																									if((((Q[1]-P[1])*(R[2]-P[2])-(R[1]-P[1])*(Q[2]-P[2])) == 0) && (((R[0]-P[0])*(Q[2]-P[2])-(Q[0]-P[0])*(R[2]-P[2])) == 0) && (((Q[0]-P[0])*(R[1]-P[1])-(R[0]-P[0])*(Q[1]-P[1])))==0)//checking the collinearity condition
																									{
																										cout<< "heeloo"<< elem3<< endl;
																									  c[i][j][k] = computer;
																									  ComputerMoveslist.push_back(x[i][j][k]);// adding the most favourable element to the list of computer moves
																									  flag= true;
																									  break;
																									  
																								} 
																							}
																							
																						}
			}
		}
	
}
}

}
if(flag==true)//if we find a better element comparatively we break the loop
 break;
}
if(flag==false)// if all elements are equally favourable it considers the first element in the forklist and adds it to the computer moves
{
	int needed= forkList.at(0);
int W[3];	
int i7, j7, k7;
for (i7 = 0; i7 < 3; i7++)
{
for (j7 = 0; j7 < 3; j7++)
{
for (k7 = 0; k7 < 3; k7++)
{
if (x[i7][j7][k7] == needed)
{
W[0] = i7;
W[1] = j7;
W[2] = k7;
c[i7][j7][k7] = computer;
 ComputerMoveslist.push_back(x[i7][j7][k7]);
 
}
}
}
}
}

																												}																												
																												
																								

void print (char c[3][3][3], int n)// prints the whole cube after every move
{

int t,y,z;
for(t=0; t<3;t++)
{
    for(y=0; y<3;y++)
    {
        for(z=0; z<3;z++)
        {
            if(y == 0 && z == 0){
            
            if(c[t][y][z]== 'I')//if character array at that dimension is 'I' then it prints the value from x 3d array
            cout<<"    " << x[t][y][z] << "  ";
            else
            cout<<"    " << c[t][y][z] << "  ";}//else it prints 'X' or 'O' depending on who played a move at that dimension values
            if(y == 0 && z == 1){
            
            if(c[t][y][z]== 'I')
            cout<<" " << x[t][y][z] << "  ";
            else
            cout<<" " << c[t][y][z] << "  ";}
                if(y == 0 && z == 2){
            
            if(c[t][y][z]== 'I')
            cout<<" " << x[t][y][z] << "  ";
            else
            cout<<" " << c[t][y][z] << "  ";}
            else if(y == 1 && z == 0){
            
            if(c[t][y][z]== 'I')
            cout<<"  " << x[t][y][z] << "  ";
            else
            cout<<"  " << c[t][y][z] << "  ";}
            else if(y == 1 && z == 1){
            
            if(c[t][y][z]== 'I')
            cout<<" " << x[t][y][z] << "  ";
            else
            cout<<" " << c[t][y][z] << "  ";}
            else if(y == 1 && z == 2){
            
            if(c[t][y][z]== 'I')
            cout<<" " << x[t][y][z] << "  ";
            else
            cout<<" " << c[t][y][z] << "  ";}
            else if(y == 2 && z == 0){
            
            if(c[t][y][z]== 'I')
            cout << x[t][y][z] << "  ";
            else
            cout << c[t][y][z] << "  ";}
            else if(y == 2 && z == 1){
            
            if(c[t][y][z]== 'I')
            cout<<" "  << x[t][y][z] << "  ";
            else
            cout<<" "  << c[t][y][z] << "  ";}
                else if(y == 2 && z == 2){
            
            if(c[t][y][z]== 'I')
            cout<<" "  << x[t][y][z] << "  ";
            else
            cout<<" "  << c[t][y][z] << "  ";}
        }
        cout<<endl;
    }
    cout<<endl;
}
cout<<endl;

 



}



int randomMove(char c[3][3][3], char computer)// when there is no elements helpong any of the players win this function comes into the play
{   bool flag=false;
	 for(int l=0; l<ComputerMoveslist.size(); l++)// we consider computer list elements one by one
	{
		for(int t=0; t<Allnum.size(); t++ )// further taking two elements that can help making a line later if they are not taken by any of the player
		{
			for(int q=t;q<Allnum.size();q++)
			{
			
			if((ComputerMoveslist.at(l) + Allnum.at(t) + Allnum.at(q))==42)// checking the sum condition of magic cube winning lines
			{
				
				int i, j, k;
     		    int P[3];
			    int Q[3];
			    int R[3];
				int elem1= ComputerMoveslist.at(l);
				int elem2= Allnum.at(t);
				int elem3= Allnum.at(q);
				for (i = 0; i < 3; i++)
								{
											for (j = 0; j < 3; j++)
												{
													for (k = 0; k < 3; k++)
												    {   
														if (x[i][j][k] == elem1 && c[i][j][k] == computer )// finding coordinates of the three elements considered in the loop iteration
																{
																R[0] = i;
																R[1] = j;
																R[2] = k;}
															}
														}
													}
																	for (i = 0; i < 3; i++)
																		{
																		for (j = 0; j < 3; j++)
																			{
																				for (k = 0; k < 3; k++)
																					{
																					if (x[i][j][k] == elem2 && c[i][j][k] == 'I' )// finding coordinates of the three elements considered in the loop iteration which is not used
																						{
																						P[0] = i;
																						P[1] = j;
																						P[2] = k;
																						break;
																						}
																					}
																			}
																		}
																	for (i = 0; i < 3; i++)
																		{
																				for (j = 0; j < 3; j++)
																					{
																						for (k = 0; k < 3; k++)
																							{
																								if (x[i][j][k] == elem3 && c[i][j][k] == 'I') // finding coordinates of the three elements considered in the loop iteration
																								{
																									Q[0] = i;
																									Q[1] = j;
																									Q[2] = k;
																									if((((Q[1]-P[1])*(R[2]-P[2])-(R[1]-P[1])*(Q[2]-P[2])) == 0) && (((R[0]-P[0])*(Q[2]-P[2])-(Q[0]-P[0])*(R[2]-P[2])) == 0) && (((Q[0]-P[0])*(R[1]-P[1])-(R[0]-P[0])*(Q[1]-P[1])))==0)
																									{
																										cout<< "heeloo"<< elem3<< endl;
																										c[i][j][k] = computer;
																									  ComputerMoveslist.push_back(x[i][j][k]);// pushes the required element into the list
																									  flag=true;
																								      break;
																								}
																							}
																						}
			}
		}
	
}if(flag==true)
{
	return 1;
}

} //break;

}
}
}


int humanPossibleWin(char c[3][3][3], char computer){
	
int vecsize1 = HumanMoveslist.size();   //saves user's moves vector's size as vecsize1
    int lastele1 = HumanMoveslist.at(vecsize1-1);//stores last element of the vector as lastele1
    int m1;
     for (m1=0; m1<vecsize1-1; m1++){
     	int compare1 = HumanMoveslist.at(m1);  
		 	int element2 = 42 - (lastele1 + compare1);//element2 is the value for which sum of these numbers is 42
			int i, j, k;
     		int P[3];
			int Q[3];
			int R[3];
			
				for (i = 0; i < 3; i++)
					{
					for (j = 0; j < 3; j++)
						{
							for (k = 0; k < 3; k++)
								{
								if (x[i][j][k] == lastele1)
									{
									P[0] = i; //saves dimensions of lastele1
									P[1] = j;
									P[2] = k;
									break;
									}
								}
						}
					}
				for (i = 0; i < 3; i++)
					{
							for (j = 0; j < 3; j++)
								{
									for (k = 0; k < 3; k++)
										{
											if (x[i][j][k] == compare1)
											{
												Q[0] = i;
												Q[1] = j; //saves dimensions of compare1
												Q[2] = k;
												break;
											}
										}
								}
						}

					if(element2 <= 27 ){
					
								for (i = 0; i < 3; i++)
										{
											for (j = 0; j < 3; j++)
												{
													for (k = 0; k < 3; k++)
												    {   
														if (x[i][j][k] == element2 && c[i][j][k] == 'I')
																{
																R[0] = i;
																R[1] = j;
																R[2] = k;
																if((((Q[1]-P[1])*(R[2]-P[2])-(R[1]-P[1])*(Q[2]-P[2])) == 0) && (((R[0]-P[0])*(Q[2]-P[2])-(Q[0]-P[0])*(R[2]-P[2])) == 0) && (((Q[0]-P[0])*(R[1]-P[1])-(R[0]-P[0])*(Q[1]-P[1])))==0)
																{ //checks condition of collinearity in if block
																c[i][j][k] = computer; // adds computer's symbol to character array 
																ComputerMoveslist.push_back(x[i][j][k]); //increments number of computer's moves
															   
																return 1;
																}   		
																} 
												     
													 }
											}
											
									}
									
								}
								
						else if(element2 > 27)
						{
							break;
						}
					      
					    
					}

	return 0;

	
	
}



int computerPossibleWin(char c[3][3][3], char computer){
    int vecsize = ComputerMoveslist.size();   //saves computer's moves vector's size as vecsize
    int lastele = ComputerMoveslist.at(vecsize-1); //stores last element of the vector as lastele
    int m;
     for (m=0; m<vecsize-1; m++){
     	int compare = ComputerMoveslist.at(m);  
		 	int element1 = 42 - (lastele + compare); //element1 is the value for which sum of these numbers is 42
			int i, j, k;
     		int P[3];
			int Q[3];
			int R[3];
			
				for (i = 0; i < 3; i++)
					{
					for (j = 0; j < 3; j++)
						{
							for (k = 0; k < 3; k++)
								{
								if (x[i][j][k] == lastele)
									{
									P[0] = i;//saves dimensions of lastele
									P[1] = j;
									P[2] = k;
									break;
									}
								}
						}
					}
				for (i = 0; i < 3; i++)
					{
							for (j = 0; j < 3; j++)
								{
									for (k = 0; k < 3; k++)
										{
											if (x[i][j][k] == compare)
											{
												Q[0] = i;//saves dimensions of compare
												Q[1] = j;
												Q[2] = k;
												break;
											}
										}
								}
						}

					if(element1 <= 27 ){
					
								for (i = 0; i < 3; i++)
										{
											for (j = 0; j < 3; j++)
												{
													for (k = 0; k < 3; k++)
												    {   
														if (x[i][j][k] == element1 && c[i][j][k] == 'I')
																{
																R[0] = i;
																R[1] = j;
																R[2] = k;
																if((((Q[1]-P[1])*(R[2]-P[2])-(R[1]-P[1])*(Q[2]-P[2])) == 0) && (((R[0]-P[0])*(Q[2]-P[2])-(Q[0]-P[0])*(R[2]-P[2])) == 0) && (((Q[0]-P[0])*(R[1]-P[1])-(R[0]-P[0])*(Q[1]-P[1])))==0)
																{ //checks condition of collinearity in if block
																c[i][j][k] = computer;  // adds computer's symbol to character array 
																ComputerMoveslist.push_back(x[i][j][k]);  //increments number of computer's vector
																compline++; //increments nuber of computer's winning lines
																cout<< "Computer's number of lines are: "<< compline << endl;
																return 1;
																}    		
																}
													 }
											}
											
									}
									
								}
								
						else if(element1 > 27)
						{
						break;
						}
					      
					    
					}

	return 0;

	
	
}



int blockUser(int num1 , int num2, char c[3][3][3], char computer)
{

int P[3];
int Q[3];
int R[3];
int element = 42 - (num1 + num2);  //element is the value for which sum of these numbers is 42
int i, j, k;
for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{
for (k = 0; k < 3; k++)
{
if (x[i][j][k] == num1)
{
P[0] = i; //saves dimensions of num1
P[1] = j;
P[2] = k;
break;
}
}
}
}
for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{
for (k = 0; k < 3; k++)
{
if (x[i][j][k] == num2)
{
Q[0] = i;//saves dimensions of num2
Q[1] = j;
Q[2] = k;
break;
}
}
}
}

if(element <= 27 ){

for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{
for (k = 0; k < 3; k++)
{
if (x[i][j][k] == element && c[i][j][k] == 'I')
{
R[0] = i;
R[1] = j; //saves dimensions of element
R[2] = k;
if((((Q[1]-P[1])*(R[2]-P[2])-(R[1]-P[1])*(Q[2]-P[2])) == 0) && (((R[0]-P[0])*(Q[2]-P[2])-(Q[0]-P[0])*(R[2]-P[2])) == 0) && (((Q[0]-P[0])*(R[1]-P[1])-(R[0]-P[0])*(Q[1]-P[1])))==0) //checks condition of collinearity in if block
{
c[i][j][k] = computer; // adds computer's symbol to character array 
ComputerMoveslist.push_back(x[i][j][k]); //increments number of computer's vector
return 1;
}else {
	return 0;
}

}
else{
return 0;
}

}
}
}

}
else {
	return 0;
}

}



void humanMoves ( char c[3][3][3], char human)
{


cout << "Your turn: " << endl;
int position;
cin >> position; // inputs position where human wants to play 




for (int i = 0; i < 3; i++)

{

for (int j = 0; j < 3; j++)

{

for (int k = 0; k < 3; k++)

{

if (x[i][j][k] == position)

{

c[i][j][k] = human; //saves dimensions of human


}

}

}

}

HumanMoveslist.push_back(position); //increments number of computer's moves
print (c, 3);//prints the updated 3d array by calling print function
humanWinLine(c ,human, position); // humanWinLine is called to print number of user's winning lines
printList(); // prints user's updated played moves in a list

}



void computerMoves (char c[3][3][3], char computer, int counter)
{
if(counter == 1 && c[1][1][1] == 'I')//When counter == 1 that means the computer gets to choose first and it chooses the centre.
{
c[1][1][1] = computer;
ComputerMoveslist.push_back(x[1][1][1]);

}

else if(counter == 2 && c[1][1][1] == 'I')// For counter == 2 if the user hasn’t taken the centre it plays there else it plays position i=0, j=0, k = 0.
{
c[1][1][1] = computer;
ComputerMoveslist.push_back(x[1][1][1]);
}
else if(counter == 2 && c[1][1][1] != 'I' && c[0][0][0] == 'I')
{
c[0][0][0] = computer;
ComputerMoveslist.push_back(x[0][0][0]);
}
else if(counter == 3 )//For counter == 3 if after taking the centre when the computer is X it takes one of the suitable corners. 
{
if(c[2][0][0] != 'I' || c[2][2][2] !='I')
{
c[0][0][2] = computer;
ComputerMoveslist.push_back(x[0][0][2]);
}
else if(c[2][0][2] != 'I' || c[2][2][0] !='I')
{
c[0][0][0] = computer;
ComputerMoveslist.push_back(x[0][0][0]);
}
else if(c[0][0][0] != 'I' || c[0][2][2] !='I')
{
c[2][0][2] = computer;
ComputerMoveslist.push_back(x[2][0][2]);
}
else if(c[0][2][0] != 'I' || c[0][0][2] !='I')
{
c[2][0][0] = computer;
ComputerMoveslist.push_back(x[2][0][0]);
} 
else
{
	c[0][0][0] = computer;
ComputerMoveslist.push_back(x[0][0][0]);
}

}
else if(counter == 4)//For counter == 4 blockUser function is called 
{

int a1 = HumanMoveslist[0];

int a2 = HumanMoveslist.at(1);

int diya= blockUser(a1, a2, c, computer);
if(diya==0)
{
	int xyz = randomMove(c,computer);
}
}


    else if(counter >= 5 && counter<28)// for counter 5 and above functions computerPossibleWin, checkFork, humanPossibleWin, randomMove and forkMove are called sequentially.

{
    int avan = computerPossibleWin(c,computer);
	cout << " win:"<< avan<< endl;
	if(avan==0)
	{
		
		int fork= checkFork(c,computer);
		cout << "flag "  << fork << endl;
		for(int dog=0;dog<forkList.size(); dog++)
		{
			cout<< forkList.at(dog) << endl;
		}
		if(fork==1)
		{
		int khus= humanPossibleWin(c,computer);
		forkList.clear();
	    }
		
		else if(fork==0  )
		{
		    cout << "hello random" << endl;

			int xyz = randomMove(c,computer);
		
			//

			
		}
		else if(fork>1)
		{
			
			cout << "hello" << endl;
			forkMove(c,computer);
			forkList.clear();
			
		}
	}
}



cout << "Computer has played " << endl;



print (c, 3);//prints updated cube 
printList();//prints computer's list
}




void ticTacToeGame (int x[3][3][3], char human)
{

int counter = 1;

char computer;

char moveno = human;

// a character array is formed which stores all the symbols according to the cube’s dimensions turn by turn after every move

char c[3][3][3] =
{
{{'I', 'I', 'I'}, {'I', 'I', 'I'}, {'I', 'I', 'I'}},
{{'I', 'I', 'I'}, {'I', 'I', 'I'}, {'I', 'I', 'I'}},
{{'I', 'I', 'I'}, {'I', 'I', 'I'}, {'I', 'I', 'I'}},
};
[20:11] Khushi Chawla
//computer is assigned a symbol

while (human == 'X')
{

computer = 'O';

cout << "You are : " << human << " and Computer is : " << computer <<
" \n ";

cout << "Let's begin ";



int j = 0;

while (1)
//  orderwise turns are given to user and computer with the help of a counter variable.

{int alpha1=0;

if (counter % 2 == 0)

{

computerMoves (c,computer,counter);

counter++;

}

else if (counter % 2 != 0)
{

humanMoves ( c, human);

counter++;

}

j++;


for (int i = 0; i < 3; i++)
{
for (int q = 0; q < 3; q++)
{
for (int k = 0; k < 3; k++)
{
if(c[i][q][k]=='I')
{
alpha1++;
}
}
}
}

 if(alpha1==0){
if(compline> humanline)//if computer's winning lines are greater than human's winning lines then computer wins
{
cout<<" ~~YOU LOST, BETTER LUCK NEXT TIME~~" << endl;
}
else if(humanline>compline)//if human's winning lines are greater than computer's winning lines then human wins

{
cout<<" ~~YOU WON, CONGRATULATIONS~~" << endl;

 } else if(humanline==compline)//if human's winning lines are equal t0 computer's winning lines then there is a draw

 {
cout<<" ~~DRAW~~" << endl;

 }
break;
}
}break;
}

while(human=='O')
{

computer = 'X';

cout << "You are : " << human << " and Computer is : " << computer <<
" \n ";



int j = 0;

while (1)
{int alpha2=0;

if (counter % 2 != 0)

{

computerMoves (c,computer,counter);

counter++;

}

else if (counter % 2 == 0)
{

humanMoves ( c, human);

//khushi++;

counter++;

}

j++;


for (int i = 0; i < 3; i++)
{
for (int q = 0; q < 3; q++)
{
for (int k = 0; k < 3; k++)
{
if(c[i][q][k]=='I')
{
alpha2++;
}
}
}
}
if(alpha2==0){
if(compline> humanline)
{
cout<<" ~~YOU LOST, BETTER LUCK NEXT TIME~~" << endl;
}
else if(humanline>compline)
{
cout<<" ~~YOU WON, CONGRATULATIONS~~" << endl;

 } else if(humanline==compline)
{
cout<<" ~~DRAW~~" << endl;

 }
break;
}

}break;
}

}



int main ()
{

cout << x[0][0][0] << " " << x[0][0][1] << " " << x[0][0][2] << endl;//Prints the initial cube for the user to interact with 

cout << x[0][1][0] << " " << x[0][1][1] << " " << x[0][1][2] << endl;

cout << x[0][2][0] << " " << x[0][2][1] << " " << x[0][2][2] << endl;

cout << " " << endl;

cout << x[1][0][0] << " " << x[1][0][1] << " " << x[1][0][2] << endl;

cout << x[1][1][0] << " " << x[1][1][1] << " " << x[1][1][2] << endl;

cout << x[1][2][0] << " " << x[1][2][1] << " " << x[1][2][2] << endl;

cout << " " << endl;

cout << x[2][0][0] << " " << x[2][0][1] << " " << x[2][0][2] << endl;

cout << x[2][1][0] << " " << x[2][1][1] << " " << x[2][1][2] << endl;

cout << x[2][2][0] << " " << x[2][2][1] << " " << x[2][2][2] << endl;



char a;

cout << "Do you want to play first type Y if yes type N if no "; // user types a char Y/y or N/n and presses enter
cin >> a; // Get user input from the keyboard
char human;//Value X or O is assigned to the user

if (a == 'Y' || a == 'y')

human = 'X';

else if( a == 'N' || a == 'n')

human = 'O';


ticTacToeGame (x, human);


return (0);



}

