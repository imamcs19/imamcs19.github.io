/*
Autor by ImamkomC++ ver. june 2007
email : imamkomc@gmail.com
blog  : imamkomc.wordpress.com
        imamkomc.blogspot.com
add   : Surabaya-Indonesia
*/
#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <fstream.h>
#include <string.h>
#include <iomanip.h>
#define bit 5000 // max bit
void main ()
{
ofstream file_output;
file_output.open("result_multiplication.txt");
char *num1,*num2,*temp;
long int ip,iq,i,j,k,l,diff,*p,*q;
long int result_div,remainder_result_div,*save,**result_mul,indek;
long int **a,*b,*c;
long int save_end,check_zero,kk;
p=new long int[bit];
q=new long int[bit];
save=new long int[bit];
result_mul=new long int*[bit];
for(int i=1;i<=bit;i++) result_mul[i]=new long int[bit];
a=new long int*[bit];
for(int i=1;i<=bit;i++) a[i]=new long int[bit];
b=new long int[bit];
c=new long int[bit];

//input number test to compute multiplication
//num1="2";
//num2="2847249271498127021";
num1="46808099633885973992660683677437347740684614980846936058664511789650724829345880973520148358382759122117472129288352908717416882271074298759944103655936";
num2="2847249271498127021983403423139571923579123562935665876582735628367";
ip=strlen(num1);
iq=strlen(num2); 

   file_output<<"\nlength num1 = "<<ip<<" digit = "<<ip*8<<" bit"<<"\n";
   file_output<<"length num2 = "<<iq<<" digit = "<<iq*8<<" bit"<<"\n\n";
   cout<<"p = "<<num1<<"\n";
   cout<<"q = "<<num2<<"\n\n";
   file_output<<"p = "<<num1<<"\n";
   file_output<<"q = "<<num2<<"\n";

cout<<"length p = "<<ip<<"\n";
cout<<"length q = "<<iq<<"\n";
getch ();
if (ip>=iq)
	{
   num1;
   num2;
	ip=strlen(num1);
	iq=strlen(num2);
	}
else if(ip<iq)
	{
	temp=num1;
	num1=num2;
	num2=temp;
	ip=strlen(num1);
	iq=strlen(num2); 
	}

if(((num1[0]-48)==0 && ip==1 ) || ((num2[0]-48)==0 && iq==1))
	{
   cout<<"\nresult multiplication p * q is \n\n";
   file_output<<"\nresult multiplication p * q is \n";
   c[1]=0;
  	cout<<c[1];
   file_output<<c[1];
   }
else if(((num1[0]-48)==1 && ip==1 ) || ((num2[0]-48)==1 && iq==1))
	{
   cout<<"\nresult multiplication p * q is \n\n";
   file_output<<"\nresult multiplication p * q is \n";
   if(ip==1)
   	{
      for(i=1;i<=iq;i++)
      	{
      	c[i]=num2[i-1]-48;
      	cout<<c[i];
   		file_output<<c[i];
         }
      }
   else if(iq==1)
   	{
      for(i=1;i<=ip;i++)
      	{
      	c[i]=num1[i-1]-48;
      	cout<<c[i];
   		file_output<<c[i];
         }
      } 
   }
else
	{
//inisialitation blank matric a[i][j]
   for(int i=ip;i>=(ip-iq);i--)
   	{
      for(int j=1;j<=(2*ip-1);j++)
      	{
         a[i][j]=0;
      	}
      }

   for(i=1;i<=ip;i++)
   	{
      p[i]=num1[i-1]-48;
      //cout<<p[i];
      }
      //cout<<"\n";
   diff=abs(ip-iq);
   for(j=1;j<=ip;j++)
   	{
      if(j<=diff)
      	{
         q[j]=0;
         //cout<<q[j];
         }
      else if(j>diff)
      	{
         indek=diff+1;//agar indek = 0,1,..
      	q[j]=num2[j-indek]-48;
         //cout<<q[j];
      	}
      }
   //cout<<"\n\n";
   save_end=0;
   for(l=ip;l>=1;l--)
   	{
      save[ip+1]=0;
   	for(k=ip;k>=1;k--)
   		{
      	if(q[l]==0 && l<=diff)
         	{
            result_mul[l][k]=p[k]*q[l]+save_end;
            ////cout<<"\nresult_mul["<<l<<"]["<<k<<"] = "<<result_mul[l][k]<<"\n";
            //getch ();
            if(k==1)
            	{
               if(result_mul[l][k]>=10)
               	{
            		result_div=((result_mul[l][k])/10);
               	remainder_result_div=(result_mul[l][k])-10*result_div;
               	result_mul[l][k]=remainder_result_div;
               	save[k]=result_div;
               	save_end=result_div;
                  }
               else if(result_mul[l][k]<10)
               	{
                  result_mul[l][k]=result_mul[l][k];
                  save[k]=0;
                  save_end=0;
                  }
                  //result_mul[l][k]=result_mul[l][k];
               }
            else
            	{
               result_mul[l][k]=0;
               }
            }  
         else
         	{
         	result_mul[l][k]=p[k]*q[l]+save[k+1];
         	if(result_mul[l][k]<10)
         		{
           		if(k==ip)
               	{
              		save[k]=0;
               	}
               else if(k==1 && l!=1)
               		{
                     result_div=((result_mul[l][k]+save_end)/10);
            			remainder_result_div=(result_mul[l][k]+save_end)-10*result_div;
                     result_mul[l][k]=remainder_result_div;
                  	save[k]=result_div;
                     save_end=result_div;
                  	}
                  else if(k==1 && l==1)
               		{
                     result_mul[l][k]=result_mul[l][k]+save_end;
                  	save[k]=0;
                  	}
            	else
            		{
            		save[k]=0; 
               	}
            	//cout<<"result_mul["<<l<<"]["<<k<<"] = "<<result_mul[l][k]<<"\n"; 
            	}
         	else if(result_mul[l][k]>=10)
         		{
            	if(k==ip)
               	{
               	result_div=(result_mul[l][k]/10);
            		remainder_result_div=result_mul[l][k]-10*result_div;
            		result_mul[l][k]=remainder_result_div;
            		save[k]=result_div;
               	}
           	 	else
            		{

                  if(k!=1)
               		{
                     result_div=((result_mul[l][k])/10);
            			remainder_result_div=(result_mul[l][k])-10*result_div;
            			result_mul[l][k]=remainder_result_div;
                  	save[k]=result_div;
                  	}
               	else if(k==1 && l!=1)
               		{
                     result_div=((result_mul[l][k]+save_end)/10);
            			remainder_result_div=(result_mul[l][k]+save_end)-10*result_div;
                     result_mul[l][k]=remainder_result_div;
                  	save[k]=result_div;
                     save_end=result_div;
                  	}
                  else if(k==1 && l==1)
               		{
                     result_mul[l][k]=result_mul[l][k]+save_end;
                  	save[k]=result_div;  
                  	}
               	}
            	//cout<<"result_mul["<<l<<"]["<<k<<"] = "<<result_mul[l][k]<<"\n";
					}
            }
      	}

      //cout<<"\n";
      }
    //cout<<"\n\n";

   //cout<<"\nresult in matric : \n";
   file_output<<"\nresult in matric : \n";
   cout<<setprecision(2);
   cout<<setiosflags(ios::fixed);
   for(int i=ip;i>=(ip-iq);i--)
   	{
      for(int j=1;j<=ip;j++)
      	{
         //cout<<setw(3)<<result_mul[i][j];
         file_output<<setw(3)<<result_mul[i][j];
      	}
         //cout<<"\n";
         file_output<<"\n";
      }
   //cout<<"\n\n";
   file_output<<"\n\n";
   //cout<<"\nresult in matric and ready to sum : \n";
   file_output<<"result in matric and ready to sum : \n";
   for(int i=ip;i>=(ip-iq);i--)
   	{
      for(int j=(ip-iq);j<=(2*ip-1);j++)
      	{
         a[i][j]=result_mul[i][j-(i-1)];  
          if(a[i][j]>=10)
           	{
            if(i==1 && j==1)
               {
               a[i][j]=result_mul[i][j-(i-1)];
               }
            else
            	{
               a[i][j]=0;
               }
            }
         //cout<<setw(5)<<a[i][j];
         file_output<<setw(5)<<a[i][j];
      	}
         //cout<<"\n";
         file_output<<"\n";
      }

   save[2*ip]=0;
   for(int i=(2*ip-1);i>=(ip-iq);i--)
   	{
      b[i]=save[i+1];
      for(int j=(ip-iq);j<=ip;j++)
      	{
         //cout<<"a["<<j<<"]["<<i<<"]="<<a[j][i]<<endl;
         b[i]+=a[j][i]; 
      	}
      	if(b[i]>=10)
         	{
            if(i==(ip-iq))
            	{
               c[i]=b[i];
            	save[i]=0;
               }
            else
            	{
      			c[i]=b[i]%10;
            	save[i]=(b[i]-c[i])/10;
               }
            }
         else if(b[i]<10)
         	{
            c[i]=b[i];
            save[i]=0;
            }
      }

   check_zero=(ip-iq);
   while(c[check_zero]==0){
   check_zero++;
   }
   kk=1;
   file_output<<"\nresult multiplication p * q is \n\n";
   cout<<"\nresult multiplication p * q is \n\n";
   for(int i=(ip-iq);i<=(2*ip-1);i++)
   	{
       if(i<check_zero)
      	{
         continue;
         }
      else
      	{
         c[kk]=c[i];
      	cout<<c[kk];
         file_output<<c[kk];
         kk++;
         }
      }
	}
getch ();
}
