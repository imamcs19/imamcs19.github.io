#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <fstream.h>
#include <string.h>
#include <iomanip.h>
#define n 10

/*
  Author: ImamkomC++ 
  Date: 21/12/07 09:32
  Description: I will give to display Variant of anything shape like "*"
  with using command for..   
*/

void main(){
int i,j,move;
cout<<"Display Variant of shape :\n";
cout<<"==============================\n";
   //shape of cube
	for(i=1;i<=n;i++){
   	for(j=1;j<=n;j++){
   		cout<<"*"<<" ";
      }
      cout<<"\n";
   }

   cout<<"\n\n";
   //shape of triangle
	for(i=1;i<=n;i++){
   	for(j=i;j<=n;j++){
   		cout<<"*"<<" ";
      }
      cout<<"\n";
   }

   cout<<"\n\n";
   //shape of cube cross
	for(i=1;i<=n;i++){
   	for(j=1;j<=n;j++){
      	if((i+j)%2==0){
   			cout<<"*"<<" ";
         }
         else{
         	cout<<"+"<<" ";
         }
      }
      cout<<"\n";
   }

   cout<<"\n\n";
   //shape of triangle middle left lamp
	for(i=1;i<=n;i++){
   	move=0;
   	do{
      	cout<<" ";
         move++;
      }while(move!=i);
   	for(j=1;j<=i;j++){
   		cout<<"*"<<" ";
      }
      cout<<"\n";
   }

   cout<<"\n\n";
   //shape of triangle middle up
	for(i=1;i<=n;i++){
   	move=0;
   	do{
      	cout<<" ";
         move++;
      }while(move<=(n-i));
   	for(j=1;j<=i;j++){
   		cout<<"*"<<" ";
      }
      cout<<"\n";
   }

   cout<<"\n\n";
   //shape of triangle middle down
	for(i=n;i>=1;i--){
   	move=0;
   	do{
      	cout<<" ";
         move++;
      }while(move<=(n-i));
   	for(j=1;j<=i;j++){
   		cout<<"*"<<" ";
      }
      cout<<"\n";
   }

   cout<<"\n\n";
   //shape of triangle middle aligment up
	for(i=1;i<=2*n;i++){
   	if(i%2==0){
      	continue;
      }
      else{
   		move=0;
   		do{
      		cout<<" ";
         	move++;
      	}while(move<=(2*n-i));
   		for(j=1;j<=i;j++){
   			cout<<"*"<<" ";
      	}
      	cout<<"\n";
      }
   }

   cout<<"\n\n";
   //shape of triangle middle aligment down
	for(i=2*n;i>=1;i--){
   	if(i%2==0){
      	continue;
      }
      else{
   		move=0;
   		do{
      		cout<<" ";
         	move++;
      	}while(move<=(2*n-i));
   		for(j=1;j<=i;j++){
   			cout<<"*"<<" ";
      	}
      	cout<<"\n";
      }
   }

   cout<<"\n\n";
   //shape of triangle middle blank
	for(i=1;i<=2*n;i++){
   	if(i%2==0){
      	continue;
      }
      else{
   		move=0;
   		do{
      		cout<<" ";
         	move++;
      	}while(move<=(2*n-i));
   		for(j=1;j<=i;j++){
         	if(j==1 || j==i){
   				cout<<"*"<<" ";
            }
            else{
            	cout<<"  ";
            }
      	}
      	cout<<"\n";
      }
   }
getch();
}
