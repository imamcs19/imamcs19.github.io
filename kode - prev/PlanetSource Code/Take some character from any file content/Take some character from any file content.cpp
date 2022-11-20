#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <stdio.h>
#include <dos.h>

void main()
{
	char m_file[100],string_take[]="";
   int loop_all,j,loop_take;
   int limit_one,limit_two;

         ///////////////////////////////////////////////
         // m_file[100] to patch all character from file
         // string_take[]="" to patch part of m_file
         // loop_all to count total all character from file
         // j is variable to loop on command for {..
         // loop_take as index string_take[]
         // limit_one is number take start
         // limit_two is number take finish
         //////////////////////////////////////////////////////////

         // Process to open content of file "nmfile.txt"
         cout<<"This is Content of file is :\n";
         cout<<"==============================\n";
         FILE *input_nmfile;
         input_nmfile = fopen("nmfile.txt", "r");
         loop_all=0;
         while((m_file[loop_all]=char(fgetc(input_nmfile)))!= EOF){
            cout<<m_file[loop_all];
         	loop_all++;
         }

         cout<<"\nAmount All Character ="<<(loop_all-1)<<"\n";
         do{
         cout<<"\nEnter Number Start Take :";
         cin>>limit_one;
         }while(limit_one<1 || limit_one>(loop_all-1));

         /////////////////////////////////////////////////
         // input limit_one must satisfy this condition :
         // while(limit_one<1 or limit_one>(loo_all-1)) And
         // input limit_two must satisfy this condition :
         // while(limit_two<=limit_one or limit_two>(loo_all-1))
         /////////////////////////////////////////////////////////////

         do{
         cout<<"Enter Number Finish Take :";
         cin>>limit_two;
         }while(limit_two<=limit_one || limit_two>(loop_all-1));

         /////////////////////////////////////////////
         // Proses to take character from file like :
         // e.g. content of file is :
         // "hk.txt","sandi_hk.txt"
         // if you Enter Number Start Take : 2 Then
         // Enter Number Finish Take :5
         // Result is :
         // hk.t
         ///////////////////////////////////////////////////////////////

         loop_take=0;
         for(j=(limit_one-1);j<limit_two;j++){
         string_take[loop_take]=m_file[j];
         loop_take++;
         }
         string_take[loop_take]= '\0';  // to destroy noise
         cout<<"\nYour Take Character from "<<limit_one<<" to "<<limit_two<<"\n";
         cout<<"The Result String Take is ="<<string_take<<"\n";
getch();
}
