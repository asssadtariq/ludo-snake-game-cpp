#include <iostream>
#include <iomanip>
#include <cstring>
#include <math.h>
#include <ctime>
#include <cstdlib>
using namespace std;
int main ()
{

int r_ows, c_ols, k=0, rc, r_snakes, r_ladder, dice, t_flag=0, o_flag=0, tempo=0, tempt=0;
int p_one=0, p_two=0, po_try=0, pt_try; 
int key, pol=0, pos=0, ptl=0, pts=0;
string p_A;
string p_B;
               
cout<<"Enter Name of Player ONE:- ";
getline(cin, p_A);

cout<<endl<<"Enter Name of Player TWO:- ";
getline(cin, p_B);


cout<<endl<<"Enter Number of ROWS:_";
cin>>r_ows;
const int rows=r_ows;

cout<<endl<<"Enter Number of COLUMNS:_";
cin>>c_ols;
const int colmn=c_ols;


int s_board[rows][colmn];
k=rows*colmn;
rc=rows*colmn;

for (int i=rows-1; i>=0; i--)
{
for (int j=colmn-1; j>=0; j--)
{
s_board[i][j]=k;
k--;
}
}
cout<<endl;

srand(time(NULL));
r_snakes=rand()%colmn;
r_ladder=rand()%colmn;
cout<<endl<<"Total number of SNAKES="<<r_snakes<<endl;
cout<<endl<<"Total number of LADDERS="<<r_ladder<<endl;

cout<<endl<<endl;
for (int i=rows-1; i>=0; i--)
{
for (int j=0; j<colmn; j++)
cout<<"\t"<<s_board[i][j];

cout<<endl;
}

int snake[2][colmn];
int s_head[colmn], s_tail[colmn];

int ladder[2][colmn];
int l_head[colmn], l_tail[colmn];


if (r_snakes==0)
r_snakes=1;


if (r_ladder==0)
r_ladder=1;


// SNAKES

for (int q=0; q<r_snakes; q++)
{

s_head[q]=rand()%rc;
s_tail[q]=rand()%rc;
while (s_tail[q]>=s_head[q] || s_tail[q]==s_tail[q-1])
s_tail[q]=rand()%rc;

while (s_head[q]==s_head[q-1])
s_head[q]=rand()%rc;

}

cout<<endl<<endl<<"Snakes Head\tSnake Tail"<<endl;
for (int s_h=0; s_h<r_snakes; s_h++)
{
	cout<<s_head[s_h]<<"\t\t"<<s_tail[s_h]<<endl;
	
}





// LADDERS

for (int q=0; q<r_ladder; q++)
{

l_head[q]=rand()%rc;
l_tail[q]=rand()%rc;

while (l_tail[q]>=l_head[q] || l_tail[q]==l_tail[q-1]) 
l_tail[q]=rand()%rc;

}



cout<<endl<<endl<<"Ladder Bottom\tLadder Head"<<endl;
for (int s_l=0; s_l<r_ladder; s_l++)
{
	cout<<l_tail[s_l]<<"\t\t"<<l_head[s_l]<<endl;
	
}



cout<<endl<<endl<<"Press any key to Start"<<endl<<endl;
key=getchar();
key=getchar();


// Players

while ( p_one<rc  || p_two<rc )

{

// Player 1

if (o_flag==0)                                              // starting Conditions
po_try=(rand()%6)+1;

if (o_flag<=6 && tempo==0)
cout<<endl<<endl<<"oops!!! Player "<<p_A<<" Not Get 6 so far!!"<<endl<<endl;


if (po_try==6)
               {
               cout<<endl<<endl<<endl<<":::::Player A Turn::::::"<<endl<<endl<<"Press any Key:-";
               key=getchar();
               
               
               dice=(rand()%6)+1;
               p_one=p_one+dice;
               cout<<endl<<"You Got="<<dice<<endl;
               if (p_one > rc)
               p_one=p_one-6;


               for (int c=0; c<r_snakes; c++)
               { 
               if (p_one==s_head[c])
               {
               p_one=s_tail[c];
               cout<<p_A<<" Oh! UNLUCKY You Got Snake!!! "<<endl;
               pos++;
               }

               }

               for (int c=0; c<r_ladder; c++)
               {

                if (p_one==l_tail[c])
               {
               p_one=l_head[c];
               cout<<p_A<<" Wow! lucky You Got Ladder !!! "<<endl;
               pol++;
               }
               o_flag=6;
               }
               cout<<endl<<"Total Score of "<<p_A<<" ="<<p_one<<endl<<endl;
               tempo=1;
               key=getchar();

               }

               
               
if (p_one==rc)
break;




// Player 2

if (t_flag==0)                                              // starting Conditions
pt_try=(rand()%6)+1;

if (t_flag<=6 && tempt==0)
cout<<endl<<endl<<"Unlucky!!! Player "<<p_B<<" Not Get 6 so far!!"<<endl<<endl;



if (pt_try==6)
               {
              
               cout<<endl<<endl<<endl<<":::::Player 2 Turn:::::"<<endl<<endl<<"Press any Key:-";
               key=getchar();
               
               dice=(rand()%6)+1;
               p_two=p_two+dice;
               cout<<endl<<"You got="<<dice<<endl;
               if (p_two > rc)
               p_two=p_two-6;

              
               for (int y=0; y<r_snakes; y++)
               { 

               if (p_two==s_head[y])
               {
               p_two=s_tail[y];
               cout<<p_B<<" oops! SNAKE"<<endl;
               pts++;
               }

               }
                              
               for (int t=0; t<r_ladder; t++)
               {

                if (p_two==l_tail[t])
               {
               p_two=l_head[t];
               cout<<p_B<<" wow! LADDER"<<endl;
               ptl++;
               }
               t_flag=6;
               }
               cout<<endl<<"Total Score of "<<p_B<<" ="<<p_two<<endl<<endl;
	           tempt=1;
               key=getchar();

               }
          

cout<<endl<<endl;               
for (int i=rows-1; i>=0; i--)
{
for (int j=0; j<colmn; j++)
cout<<"\t"<<s_board[i][j];

cout<<endl<<endl;
}

cout<<endl<<endl<<"Snakes Head\tSnake Tail"<<endl;
for (int s_h=0; s_h<r_snakes; s_h++)
{
	cout<<s_head[s_h]<<"\t\t"<<s_tail[s_h]<<endl;
	
}


cout<<endl<<endl<<"Ladder Bottom\tLadder Head"<<endl;
for (int s_l=0; s_l<r_ladder; s_l++)
{
	cout<<l_tail[s_l]<<"\t\t"<<l_head[s_l]<<endl;
	
}

          		       

if (p_two==rc)
break;

}

// Displaying Result

cout<<endl<<":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::---Result---:::::::::::::::::::::::::::::::::::::::::::::::::::::::::  "<<endl<<endl;
if (p_one==rc)
cout<<endl<<"CONGRATULATIONS!! "<<p_A<<" WON "<<endl;
else if (p_two==rc)
cout<<endl<<"CONGRATULATIONS!! "<<p_B<<" WON "<<endl;

cout<<endl<<"Final SCORE of "<<p_A<<" ="<<p_one<<endl;
cout<<endl<<"Final SCORE of "<<p_B<<" ="<<p_two<<endl;


cout<<endl<<endl<<"Snakes bites "<<p_A<<" ="<<pos<<" times"<<endl;
cout<<endl<<"Ladder climb  "<<p_A<<" ="<<pol<<" times"<<endl;

cout<<endl<<endl<<"Snakes bites "<<p_B<<" ="<<pts<<" times"<<endl;
cout<<endl<<"Ladder climb "<<p_B<<" ="<<ptl<<" times"<<endl;





return 0;
}
