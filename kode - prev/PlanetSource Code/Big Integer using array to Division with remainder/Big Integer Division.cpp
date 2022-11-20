/*
/* Autor by ImamkomC++ ver. june 2007
/* email : imamkomc@gmail.com
/* blog  : imamkomc.wordpress.com
/*         imamkomc.blogspot.com
/* addr  : Surabaya-Indonesia

/* Hint :
/* 1.Split num1 such as byte it great than one byte divisor(num2).
/* 2.Run devision num1_split with num2, E.g. x = num1_split / num2.
/* 3.Compute multiplication x with num2, E.g y = x * num2
/* 4.Find different num1 with y appropiate sum of byte and must be same length of the bit, E.g new_num1_split(num1_split)= num1 - y
/* 5.Addition num1_split from step 4 with one array from num1.
/* 6.Replay step 2 while loop of replay less than sum of byte num1.
/*
/* Big Integer Division
*/

#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <fstream.h>
#include <string.h>
#include <iomanip.h>
#define bit 3000
void main ()
{
ofstream file_output;
file_output.open("result_div.txt"); //result p/q
//char *num1,*num2;
char *num1,*num2;
int ip,iq,i,j,k,l,diff;
int *p,*q,*result_div_original,*remainder_end,*save,*result_sub,*check_result_sub,*p_split,*result_add,*b,*c,*result,*save_remainder;
int result_div,result_div_diff,re_result_div,index,hit_loop;
int **a,**result_mul;
int save_end,loop,check_loop,kk,ii,jj,ll,check_float,sum_digit,diff_length,check_zero,loop_split,loop_kk,loop_div,loop_remainder;

p=new int[bit];
q=new int[bit];
result_div_original=new int[bit];
remainder_end=new int[bit];
save=new int[bit];
result_sub=new int[bit];
check_result_sub=new int[bit];
p_split=new int[bit];
result_add=new int[bit];
b=new int[bit];
c=new int[bit];
result=new int[bit];
save_remainder=new int[bit];

result_mul=new int*[bit];
for(int i=1;i<=bit;i++) result_mul[i]=new int[bit];
a=new int*[bit];
for(int i=1;i<=bit;i++) a[i]=new int[bit];
//result num1/num2
num1="9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999";
num2="147457372385923572389573892573758923758923572375892375892375893758237589750892375892375893275892375893725897238957823957892375089237538925789237528970502357";
//num1="133274327582793585623058147240214239847959185982359863295723573295729517239586165239571238957923523959235895637265823975932175893275912375632562387561235839257982351236518723518235182365273623756257238957923562357858239";
//num2="2847249271498127021983403423139571923579123562935665876582735628367";
//num1="133274327582793585623058147240214239847959185982359863295723573295729517239586165239571238957923523959235895637265823975932175893275912375632562387561235839257982351236518723518235182365273623756257238957923562357858239";
//num2="11346346346234";

ip=strlen(num1);
iq=strlen(num2);
diff_length=abs(ip-iq);
//result multiplication
   file_output<<"\nlength num1 = "<<ip<<" digit = "<<ip*8<<" bit"<<"\n";
   file_output<<"length num2 = "<<iq<<" digit = "<<iq*8<<" bit"<<"\n\n";
   cout<<"p = "<<num1<<"\n";
   cout<<"q = "<<num2<<"\n\n";
   file_output<<"p = "<<num1<<"\n";
   file_output<<"q = "<<num2<<"\n";

cout<<"length num1 = "<<ip<<" digit = "<<ip*8<<" bit"<<"\n";
cout<<"length num2 = "<<iq<<" digit = "<<iq*8<<" bit"<<"\n";
cout<<"diff length = "<<diff_length<<"\n";
if(ip<iq)
	{
   result[1]=0;
   sum_digit=1;
   cout<<"\n\nso result_div \n"<<num1<<" / "<<num2<<" is\nresult = ";
   file_output<<"\n\nso result_div \n"<<num1<<" / "<<num2<<" is\nresult = ";
	for(i=sum_digit;i>=1;i--)
      	{
         cout<<result[i];
         file_output<<result[i];
         }
   file_output<<"\n\n";
   cout<<"\n\n";
   cout<<"remainder = ";
   file_output<<"remainder = ";
   for(k=1;k<=ip;k++)
   	{
      check_result_sub[k]=num1[k-1]-48;
      cout<<check_result_sub[k];
      file_output<<check_result_sub[k];
      }
   cout<<"\n";
   file_output<<"\n";
   }
else if(abs(ip-iq)<=5)
	{
ii=0;jj=0;kk=0;
for(i=1;i<=iq;i++)
   		{
         q[i]=num2[i-1]-48;
         p[i]=num1[i-1]-48;
   		if (p[i]<q[i])
      		{
      		ii=1;
            break;
         	}
     	 	else if(p[i]>q[i])
      		{
         	jj=1;
            break;
         	}
      	else if (p[i]==q[i])
      		{
         	kk++;
         	}
      	}
if(ip<iq)
	{
   cout<<"\n\nso result_div \n"<<num1<<" / "<<num2<<" is\nresult = ";
   file_output<<"\n\nso result_div \n"<<num1<<" / "<<num2<<" is\nresult = ";
   for(i=1;i>=1;i--)
      	{
         result[1]=0;
         cout<<result[1];
         file_output<<result[1];
         }
   cout<<"\nremainder = ";
   file_output<<"\nremainder = ";
   for(k=1;k<=ip;k++)
   	{
      cout<<p[k];
      file_output<<p[k];
      }
   }
else if(ip==iq && ii==1)
	{
   cout<<"\n\nso result_div \n"<<num1<<" / "<<num2<<" is\nresult = ";
   file_output<<"\n\nso result_div \n"<<num1<<" / "<<num2<<" is\nresult = ";
   for(i=1;i>=1;i--)
      	{
         result[1]=0;
         cout<<result[1];
         file_output<<result[1];
         }
   cout<<"\nremainder = ";
   file_output<<"\nremainder = ";
   for(k=1;k<=ip;k++)
   	{
      cout<<p[k];
      file_output<<p[k];
      }
   }
else if(ip>=iq)
	{
//////////////////////////////////////////////////////////////////////////////////////////////
check_float=0;
result_div_diff=0;
check_loop=1;
sum_digit=1;
do{
if(ip>iq)
	{
   if(check_loop==1)
		{
   	loop=ip;
   	for(i=1;i<=ip;i++)
   		{
      	p[i]=num1[i-1]-48;
      	}
      	////cout<<"\n";
   	diff=abs(ip-iq);
   	for(j=1;j<=ip;j++)
   		{
      	if(j<=diff)
      		{
         	q[j]=0;
         	}
     	 	else if(j>diff)
      		{
         	index=diff+1;//hope index = 0,1,..
      		q[j]=num2[j-index]-48;
      		}
      	}
    	}
	else if(check_loop==0)
		{
      diff=abs(ip-iq);
      for(j=1;j<=ip;j++)
   		{
      	if(j<=diff)
      		{
         	q[j]=0;
         	}
     	 	else if(j>diff)
      		{
         	index=diff+1;//hope index = 0,1,..
      		q[j]=num2[j-index]-48;
      		}
      	}
      //break;
   	}
   result_sub[loop]=0;
   for(k=loop;k>=1;k--)
   	{
      result_sub[k]+=p[k]-q[k];
      ////cout<<result_sub[k]<<" ";
      if(result_sub[k]<0 && k!=1)
      	{
         result_sub[k]=result_sub[k]+10;
         ////cout<<result_sub[k]<<" ";
         result_sub[k-1]=-1;
         }
      else
      	{
         result_sub[k]=result_sub[k];
         result_sub[k-1]=0;
         }
      }
   }
   else if(ip<iq)
	{
   if(check_loop==1)
		{
   	loop=iq;
   	for(i=1;i<=iq;i++)
   		{
      	q[i]=num2[i-1]-48;
      	}
      	//cout<<"\n";
   	diff=abs(ip-iq);
   	for(j=1;j<=iq;j++)
   		{
      	if(j<=diff)
      		{
         	p[j]=0;
         	}
      	else if(j>diff)
      		{
         	index=diff+1;//hope index = 0,1,..
      		p[j]=num1[j-index]-48;
      		}
         }
      }
   else if(check_loop==0)
   	{
      for(i=1;i<=iq;i++)
   		{
      	q[i]=num2[i-1]-48;
      	}
      //continue;
      }
   result_sub[loop]=0;
   for(k=loop;k>=1;k--)
   	{
      result_sub[k]+=q[k]-p[k];
      ////cout<<result_sub[k]<<" ";
      if(result_sub[k]<0 && k!=1)
      	{
         result_sub[k]=result_sub[k]+10;
         ////cout<<result_sub[k]<<" ";
         result_sub[k-1]=-1;
         }
      else
      	{
         result_sub[k]=result_sub[k];
         result_sub[k-1]=0;
         if(k==1 && result_sub[k]!=0)
         	{
            result_sub[k]=-1*result_sub[k];
            }
         else if(k==1 && result_sub[k]==0)
         	{
            result_sub[k+1]=-1*result_sub[k+1];
            }
         }
      }
   }
   else if(ip==iq)
	{
   ////cout<<"iq ="<<iq<<"\n";
   int ii=0,jj=0,kk=0;
   if(check_loop==1)
		{
      for(i=1;i<=iq;i++)
   		{
      	p[i]=num1[i-1]-48;
      	////cout<<"p["<<i<<"]="<<p[i]<<"\n";
      	q[i]=num2[i-1]-48;
      	////cout<<"q["<<i<<"]="<<q[i-1]<<"\n";
   		if (p[i]<q[i])
      		{
      		ii=1;
            break;
         	}
     	 	else if(p[i]>q[i])
      		{
         	jj=1;
            break;
         	}
      	else if (p[i]==q[i])
      		{
         	kk++;
         	}
      	}
      }
     else if(check_loop==0)
     {
     for(i=1;i<=iq;i++)
   		{
         q[i]=num2[i-1]-48;
   		if (p[i]<q[i])
      		{
      		ii=1;
            break;
         	}
     	 	else if(p[i]>q[i])
      		{
         	jj=1;
            break;
         	}
      	else if (p[i]==q[i])
      		{
         	kk++;
         	}
      	}
     }
    if(ii==1)
    	{
    check_float=1;
    ////cout<<"\n check_float ="<<check_float<<"\n";
   // break;
      if(check_loop==1)
			{
	   	loop=iq;
	   	for(i=1;i<=iq;i++)
	   		{
	      	p[i]=num1[i-1]-48;
	      	q[i]=num2[i-1]-48;
	      	}
	      	//cout<<"\n";
	   	diff=abs(ip-iq);
	   	for(j=1;j<=iq;j++)
	   		{
	      	if(j<=diff)
	      		{
	         	p[j]=0;
	         	}
	     	 	else if(j>diff)
	      		{
	         	index=diff+1;//hope index = 0,1,..
	      		p[j]=num1[j-index]-48;
	      		}
	      	}
         }
      else if(check_loop==0)
      	{
         for(i=1;i<=iq;i++)
   			{
         	q[i]=num2[i-1]-48;
         	}
         }
	   result_sub[loop]=0;
	   for(k=loop;k>=1;k--)
	   	{
	      result_sub[k]+=q[k]-p[k];
	      ////cout<<result_sub[k]<<" ";
	      if(result_sub[k]<0 && k!=1)
	      	{
	         result_sub[k]=result_sub[k]+10;
	         ////cout<<result_sub[k]<<" ";
	         result_sub[k-1]=-1;
	         }
	      else
	      	{
	         result_sub[k]=result_sub[k];
	         result_sub[k-1]=0;
	         if(k==1 && result_sub[k]!=0)
	         	{
	            result_sub[k]=-1*result_sub[k];
	            }
	         else if(k==1 && result_sub[k]==0)
	         	{
	            result_sub[k+1]=-1*result_sub[k+1];
	            }
	         }
	      }
      }
      else if(jj==1)
      	{
         ////cout<<"\n jj ="<<jj<<"\n";
      	if(check_loop==1)
				{
      		loop=ip;
	   		for(i=1;i<=ip;i++)
	   			{
	      		p[i]=num1[i-1]-48;
	      		}
	      		////cout<<"\n";
	   		diff=abs(ip-iq);
	   		for(j=1;j<=ip;j++)
	   			{
	      		if(j<=diff)
	      			{
	         		q[j]=0;
	         		}
	      		else if(j>diff)
	      			{
	         		index=diff+1;//hope index = 0,1,..
	      			q[j]=num2[j-index]-48;
	      			}
	      		}
         	}
         else if(check_loop==0)
         	{
            for(i=1;i<=iq;i++)
   				{
         		q[i]=num2[i-1]-48;
         		}
            }
	   result_sub[loop]=0;
	   for(k=loop;k>=1;k--)
	   	{
	      result_sub[k]+=p[k]-q[k];
	      ////cout<<result_sub[k]<<" ";
	      if(result_sub[k]<0 && k!=1)
	      	{
	         result_sub[k]=result_sub[k]+10;
	         ////cout<<result_sub[k]<<" ";
	         result_sub[k-1]=-1;
	         }
	      else
	      	{
	         result_sub[k]=result_sub[k];
	         result_sub[k-1]=0;
	         }
	      }
         }
      else if(kk==iq)
      	{
      ////cout<<"\n kk ="<<kk<<"\n";
         loop=1;
         result_sub[1]=0;
         }
   }
   //display result subtraction
   ////cout<<"\nresult subtraction within array = ";
   kk=1;
	for(k=1;k<=loop;k++)
   	{
      if(loop!=1 && k==1 && result_sub[k]==0)
      	{
         continue;
         }
      else
      	{
         check_result_sub[kk]=result_sub[k];
         kk++;
         ////cout<<"\nkk ="<<kk<<"\n";
         ////cout<<result_sub[k];
         }
      }

   ////cout<<"\ncheck result subtraction ";
	for(k=1;k<=(kk-1);k++)
   	{
      ////cout<<check_result_sub[k];
      }
   if((kk-1)>iq)
   	{
      check_loop=0;
      }
   else if((kk-1)<iq)
   	{
      check_loop=1;
      check_float=1;
      }
   else if((kk-1)==iq)
   	{
      if((kk-1)==1)
      	{
         ////cout<<"\ncondition_1\n";
         q[1]=num2[0]-48;
         ////cout<<"\nq[1] ="<<q[1]<<"\n";
      	////cout<<check_result_sub[k];
         if(check_result_sub[1]==0)
         	{
            check_loop=1;
            }
         else if(check_result_sub[1]<q[1])
         	{
            ////cout<<"\ncondition_1.2\n";
            check_loop=1;//result berupa float
            check_float=1;
            }
         else if(check_result_sub[1]>q[1] || check_result_sub[1]==q[1])
         	{
            check_loop=0;
            }
          }
      else if((kk-1)>1)
      	{
         ii=0,jj=0,ll=0;
         for(i=1;i<=(kk-1);i++)
         	{
         	if (check_result_sub[i]<q[i])
            	{
               ii=1;
               break;
               }
            else if(check_result_sub[i]>q[i])
            	{
               jj=1;
               break;
               }
            else if (check_result_sub[i]==q[i])
            	{
               ll++;
               }
            }
         if(ii==1)
           	{
            check_loop=1;//stop, result float
            }
         else if(jj==1)
         	{
            check_loop=0;//loop back to
            }
         else if(ll==(kk-1))
         	{
            check_loop=1;
            result_div_diff++;
            kk=2;
            check_result_sub[1]=0;
            }
         }
      } 
    ////cout<<"\ncheck loop ="<<check_loop<<"\n";
    if(check_loop==0)
    	{
      result_div_diff++;
      ////cout<<"\ntukar  check result ke num1\n";
      for(k=1;k<=(kk-1);k++)
   		{
      	p[k]=check_result_sub[k];
         ////cout<<"\p["<<k<<"]="<<p[k]<<"\n";
      	}
      for(k=1;k<=iq;k++)
   		{
         ////cout<<"\q["<<k<<"]="<<q[k]<<"\n";
      	}
      //getch ();
      ip=(kk-1);
      loop=ip;
      }
    else if(check_loop==1)
    	{
      result_div_diff++;
      }

   // compute result div array

    result[1]=result_div_diff; 
      for(i=1;i<=sum_digit;i++)
      	{
         if(i==1)
         	{
            ////cout<<"\ncondition1. result["<<i<<"] = "<<result[i]<<"\n";
         	if(result[1]==10)
            	{
               if(i==sum_digit)
               	{
                  sum_digit++;
                  }
               result_div_diff=0;
               result[1]=0;
               //result[1+1]=1;
               save_remainder[1]=1;
               }
         	 else if(result[1]<10)
             	{
               result[1]=result_div_diff;
               //result[i+1]=0;
               save_remainder[1]=0;
               }
            }
        
         else if(i>1)
         	{
            result[i]=result[i]+save_remainder[i-1];
            //result[i]++;
           // //cout<<"\nkon3. result["<<i<<"] = "<<result[i]<<"\n";
            if(result[i]==10)
         		{
               if(i==sum_digit)
               	{
                  sum_digit++;
                  }
            	result[i]=0;
               //result[i+1]=0;
            	save_remainder[i]=1;
            	}
         	else if(result[i]<10)
         		{
               result[i]=result[i];
               //result[i+1]=0;
            	save_remainder[i]=0;
            	}
            }
         }

    for(i=1;i<=sum_digit;i++)
      	{
         ////cout<<"\nresult["<<i<<"] = "<<result[i]<<"\n";
         } 
}while(check_loop==0);

if(check_float==0)
	{
	cout<<"\n\nso result_div "<<num1<<" / "<<num2<<" is\nresult = ";
   file_output<<"\n\nso result_div "<<num1<<" / "<<num2<<" is\nresult = ";
	for(i=sum_digit;i>=1;i--)
      	{
         cout<<result[i];
         file_output<<result[i];
         }
   //cout<<"\ndiv completed\n";
   file_output<<"\ndiv completed\n";
   cout<<"\nremainder = ";
   file_output<<"\nremainder = ";
   for(k=1;k<=(kk-1);k++)
   	{
      cout<<check_result_sub[k];
      file_output<<check_result_sub[k];
      }
   }
else if(check_float==1)
	{
   cout<<"\n\nso result_div \n"<<num1<<" / "<<num2<<" is\nresult = ";
   file_output<<"\n\nso result_div \n"<<num1<<" / "<<num2<<" is\nresult = ";
   for(i=sum_digit;i>=1;i--)
      	{
         cout<<result[i];
         file_output<<result[i];
         }
   //cout<<"\nnot div completed\n";
   file_output<<"\nnot div completed\n";
   cout<<"\nremainder = ";
   file_output<<"\nremainder = ";
   for(k=1;k<=(kk-1);k++)
   	{
      cout<<check_result_sub[k];
      file_output<<check_result_sub[k];
      }
   }

	}
}
//********************************************************************************************************************************//
else if(abs(ip-iq)>5)
	{ 
if(iq==1 && (num2[0]-48)==1)
	{
   for(i=1;i<=ip;i++)
      	{
         result[i]=num1[i-1]-48;
         //cout<<result[i];
         file_output<<result[i];
         }
   //cout<<"\n";
   ////cout<<"\nnot div completed\n";
   file_output<<"\nnot div completed\n";
   //cout<<"remainder = ";
   file_output<<"remainder = ";
   for(k=1;k<=1;k++)
   	{
      check_result_sub[1]=0;
      //cout<<check_result_sub[1];
      file_output<<check_result_sub[1];
      }
   }
else if(iq==1 && (num2[0]-48)==0)
	{
   //cout<<"\nresult's infinity, value 0 as sign too. \n";
   for(i=1;i<=1;i++)
      	{
         result[1]=0; 
         //cout<<result[1];
         file_output<<result[1];
         }
   //cout<<"\n";
   ////cout<<"\nnot div completed\n";
   file_output<<"\nnot div completed\n";
   //cout<<"remainder = ";
   file_output<<"remainder = ";
   for(k=1;k<=1;k++)
   	{
      check_result_sub[1]=0;
      //cout<<check_result_sub[1];
      file_output<<check_result_sub[1];
      }
   }
else
	{
for(i=1;i<=ip;i++)
	{
   p[i]=num1[i-1]-48;
   }
for(i=1;i<=iq;i++)
	{
   q[i]=num2[i-1]-48;
   //cout<<q[i];
   }
//cout<<"\n";
// split nilai p[i]
for(i=1;i<=(strlen(num2)+1);i++)
	{
   p_split[i]=p[i];
   //cout<<p_split[i];
   }
//cout<<"\n\n";
//getch ();
loop_split=strlen(num2)+1;
loop_kk=strlen(num2)+1;
loop_div=1;
//cout<<"\nPlease waiting..........!\n";
hit_loop=0;
do{
//cout<<"\nup to again \n";
	//*************************************************************************************************//
for(i=1;i<=loop_kk;i++)
	{
   p[i]=p_split[i];
   //cout<<p[i];
   }
// inisialitation
ip=loop_kk;
iq=strlen(num2);

//condition below only for ip=iq
ii=0;jj=0;kk=0;
for(i=1;i<=iq;i++)
   		{
         q[i]=num2[i-1]-48;
         //p[i]=num1[i-1]-48;
   		if (p[i]<q[i])
      		{
      		ii=1;
            break;
         	}
     	 	else if(p[i]>q[i])
      		{
         	jj=1;
            break;
         	}
      	else if (p[i]==q[i])
      		{
         	kk++;
         	}
      	}

if(ip<iq)
	{
   	for(i=1;i<=loop_kk;i++)
			{
   		//cout<<p_split[i];
   		}
   file_output<<"\n\nso result_div ";
   	for(i=1;i<=loop_kk;i++)
			{
   		file_output<<p_split[i];
   		}file_output<<" / "<<num2<<" = ";
   for(i=1;i>=1;i--)
      	{
         result[1]=0;
         result_div_original[loop_div]=result[1];
         //cout<<result_div_original[loop_div];
         file_output<<result_div_original[loop_div];
         loop_div++;
         sum_digit=1;
         }
   //cout<<"\n";
   file_output<<"\n";
   //cout<<"remainder = ";
   file_output<<"remainder = ";
   for(k=1;k<=ip;k++)
   	{
      loop_remainder=ip;
      remainder_end[k]=p[k];
      //cout<<p[k];
      file_output<<p[k];
      }
   }
else if(ip==2 && iq==1 && p[1]==0 && p[2]<q[1])
	{
   //cout<<"\ncondition ip==2 && p[1]==0 \n";
   //cout<<"\n\nso result_div ";
   	for(i=1;i<=loop_kk;i++)
			{
   		//cout<<p_split[i];
   		}
   file_output<<"\n\nso result_div ";
   	for(i=1;i<=loop_kk;i++)
			{
   		file_output<<p_split[i];
   		}file_output<<" / "<<num2<<" = ";
   for(i=1;i>=1;i--)
      	{
         result[1]=0;
         result_div_original[loop_div]=result[1];
         //cout<<result_div_original[loop_div];
         file_output<<result_div_original[loop_div];
         loop_div++;
         sum_digit=1;
         }
   //cout<<"\n";
   file_output<<"\n";
   //cout<<"remainder = ";
   file_output<<"remainder = ";
   for(k=1;k<=ip;k++)
   	{
      loop_remainder=ip;
      remainder_end[k]=p[k];
      //cout<<p[k];
      file_output<<p[k];
      }
   getch ();
   }
else if(ip==iq && ii==1)
	{
   //cout<<"\n\nso result_div ";
   	for(i=1;i<=loop_kk;i++)
			{
   		//cout<<p_split[i];
   		}//cout<<" / "<<num2<<" = "; 
   file_output<<"\n\nso result_div ";
   	for(i=1;i<=loop_kk;i++)
			{
   		file_output<<p_split[i];
   		}file_output<<" / "<<num2<<" = ";
   for(i=1;i>=1;i--)
      	{
         result[1]=0;
         result_div_original[loop_div]=result[1];
         //cout<<result_div_original[loop_div];
         file_output<<result_div_original[loop_div];
         loop_div++;
         sum_digit=1;
         }
   //cout<<"\n";
   file_output<<"\n";
   //cout<<"remainder = ";
   file_output<<"remainder = ";
   for(k=1;k<=ip;k++)
   	{
      loop_remainder=ip;
      remainder_end[k]=p[k];
      //cout<<p[k];
      file_output<<p[k];
      }
   }

else if(ip>=iq)
	{
//cout<<"\ncondition ip>=iq \n";
//////////////////////////////////////////////////////////////////////////////////////////////
check_float=0;
result_div_diff=0;
check_loop=1;
sum_digit=1;
do{
if(ip>iq)
	{
   if(check_loop==1)
		{
   	loop=ip;
   	for(i=1;i<=ip;i++)
   		{
      	p[i]=p_split[i];
      	}
      	////cout<<"\n";
   	diff=abs(ip-iq);
   	for(j=1;j<=ip;j++)
   		{
      	if(j<=diff)
      		{
         	q[j]=0;
         	}
     	 	else if(j>diff)
      		{
         	index=diff+1;//hope index = 0,1,..
      		q[j]=num2[j-index]-48;
      		}
      	}
    	}
	else if(check_loop==0)
		{
      diff=abs(ip-iq);
      for(j=1;j<=ip;j++)
   		{
      	if(j<=diff)
      		{
         	q[j]=0;
         	}
     	 	else if(j>diff)
      		{
         	index=diff+1;//hope index = 0,1,..
      		q[j]=num2[j-index]-48;
      		}
      	}
      //break;
   	}
   result_sub[loop]=0;
   for(k=loop;k>=1;k--)
   	{
      result_sub[k]+=p[k]-q[k];
      ////cout<<result_sub[k]<<" ";
      if(result_sub[k]<0 && k!=1)
      	{
         result_sub[k]=result_sub[k]+10;
         ////cout<<result_sub[k]<<" ";
         result_sub[k-1]=-1;
         }
      else
      	{
         result_sub[k]=result_sub[k];
         result_sub[k-1]=0;
         }
      }
   }
   else if(ip<iq)
	{
   if(check_loop==1)
		{
   	loop=iq;
   	for(i=1;i<=iq;i++)
   		{
      	q[i]=num2[i-1]-48;
      	}
      	//cout<<"\n";
   	diff=abs(ip-iq);
   	for(j=iq;j>=1;j--)
   		{
      	if(j<=diff)
      		{
         	p[j]=0;
         	}
      	else if(j>diff)
      		{
         	//index=diff+1;//hope index = 0,1,..
      		p[j]=p_split[j-diff];
      		}
         }
      }
   else if(check_loop==0)
   	{
      for(i=1;i<=iq;i++)
   		{
      	q[i]=num2[i-1]-48;
      	}
      //continue;
      }
   result_sub[loop]=0;
   for(k=loop;k>=1;k--)
   	{
      result_sub[k]+=q[k]-p[k];
      ////cout<<result_sub[k]<<" ";
      if(result_sub[k]<0 && k!=1)
      	{
         result_sub[k]=result_sub[k]+10;
         ////cout<<result_sub[k]<<" ";
         result_sub[k-1]=-1;
         }
      else
      	{
         result_sub[k]=result_sub[k];
         result_sub[k-1]=0;
         if(k==1 && result_sub[k]!=0)
         	{
            result_sub[k]=-1*result_sub[k];
            }
         else if(k==1 && result_sub[k]==0)
         	{
            result_sub[k+1]=-1*result_sub[k+1];
            }
         }
      }
   }
   else if(ip==iq)
	{
   ////cout<<"iq ="<<iq<<"\n";
   int ii=0,jj=0,kk=0;
   if(check_loop==1)
		{
      for(i=1;i<=iq;i++)
   		{
      	//p[i]=num1[i-1]-48;
      	////cout<<"p["<<i<<"]="<<p[i]<<"\n";
      	q[i]=num2[i-1]-48;
      	////cout<<"q["<<i<<"]="<<q[i-1]<<"\n";
   		if (p[i]<q[i])
      		{
      		ii=1;
            break;
         	}
     	 	else if(p[i]>q[i])
      		{
         	jj=1;
            break;
         	}
      	else if (p[i]==q[i])
      		{
         	kk++;
         	}
      	}
      }
     else if(check_loop==0)
     {
     for(i=1;i<=iq;i++)
   		{
         q[i]=num2[i-1]-48;
   		if (p[i]<q[i])
      		{
      		ii=1;
            break;
         	}
     	 	else if(p[i]>q[i])
      		{
         	jj=1;
            break;
         	}
      	else if (p[i]==q[i])
      		{
         	kk++;
         	}
      	}
     }
    if(ii==1)
    	{
    ////cout<<"\n ii ="<<ii<<"\n"; //
    //properly doesn't compute again because it div not  completed
    check_float=1;
    ////cout<<"\n check_float ="<<check_float<<"\n";
   break;
      if(check_loop==1)
			{
	   	loop=iq;
	   	for(i=1;i<=iq;i++)
	   		{
	      	//p[i]=num1[i-1]-48;
	      	q[i]=num2[i-1]-48;
	      	}
	      	//cout<<"\n";
	   	diff=abs(ip-iq);
	   	for(j=iq;j>=1;j--)
	   		{
	      	if(j<=diff)
	      		{
	         	p[j]=0;
	         	}
	     	 	else if(j>diff)
	      		{
	      		p[j]=p_split[j-diff];
	      		}
	      	}
         }
      else if(check_loop==0)
      	{
         for(i=1;i<=iq;i++)
   			{
         	q[i]=num2[i-1]-48;
         	}
         }
	   result_sub[loop]=0;
	   for(k=loop;k>=1;k--)
	   	{
	      result_sub[k]+=q[k]-p[k];
	      ////cout<<result_sub[k]<<" ";
	      if(result_sub[k]<0 && k!=1)
	      	{
	         result_sub[k]=result_sub[k]+10;
	         ////cout<<result_sub[k]<<" ";
	         result_sub[k-1]=-1;
	         }
	      else
	      	{
	         result_sub[k]=result_sub[k];
	         result_sub[k-1]=0;
	         if(k==1 && result_sub[k]!=0)
	         	{
	            result_sub[k]=-1*result_sub[k];
	            }
	         else if(k==1 && result_sub[k]==0)
	         	{
	            result_sub[k+1]=-1*result_sub[k+1];
	            }
	         }
	      }
      }
      else if(jj==1)
      	{
         ////cout<<"\n jj ="<<jj<<"\n";
      	if(check_loop==1)
				{
      		loop=ip;
	   		for(i=1;i<=ip;i++)
	   			{
	      		p[i]=p_split[i];
	      		}
	      		////cout<<"\n";
	   		diff=abs(ip-iq);
	   		for(j=1;j<=ip;j++)
	   			{
	      		if(j<=diff)
	      			{
	         		q[j]=0;
	         		}
	      		else if(j>diff)
	      			{
	         		index=diff+1;//hope index = 0,1,..
	      			q[j]=num2[j-index]-48;
	      			}
	      		}
         	}
         else if(check_loop==0)
         	{
            for(i=1;i<=iq;i++)
   				{
         		q[i]=num2[i-1]-48;
         		}
            }
	   result_sub[loop]=0;
	   for(k=loop;k>=1;k--)
	   	{
	      result_sub[k]+=p[k]-q[k];
	      ////cout<<result_sub[k]<<" ";
	      if(result_sub[k]<0 && k!=1)
	      	{
	         result_sub[k]=result_sub[k]+10;
	         ////cout<<result_sub[k]<<" ";
	         result_sub[k-1]=-1;
	         }
	      else
	      	{
	         result_sub[k]=result_sub[k];
	         result_sub[k-1]=0;
	         }
	      }
         }
      else if(kk==iq)
      	{
      ////cout<<"\n kk ="<<kk<<"\n";
         loop=1;
         result_sub[1]=0;
         }
   }
   //display result subtraction
   ////cout<<"\nresult subtraction within array = ";
   kk=1;
	for(k=1;k<=loop;k++)
   	{
      if(loop!=1 && k==1 && result_sub[k]==0)
      	{
         continue;
         }
      else
      	{
         check_result_sub[kk]=result_sub[k];
         kk++;
         ////cout<<"\nkk ="<<kk<<"\n";
         ////cout<<result_sub[k];
         }
      }

   ////cout<<"\ncheck result subtraction ";
	for(k=1;k<=(kk-1);k++)
   	{
      ////cout<<check_result_sub[k];
      }
   //getch ();
   if((kk-1)>iq)
   	{
      check_loop=0;
      }
   else if((kk-1)<iq)
   	{
      check_loop=1;
      check_float=1;
      }
   else if((kk-1)==iq)
   	{
      if((kk-1)==1)
      	{
         ////cout<<"\ncondition_1\n";
         q[1]=num2[0]-48;
         ////cout<<"\nq[1] ="<<q[1]<<"\n";
      	////cout<<check_result_sub[k];
         if(check_result_sub[1]==0)
         	{
            check_loop=1;
            }
         else if(check_result_sub[1]<q[1])
         	{
            ////cout<<"\ncondition_1.2\n";
            check_loop=1;//result type float
            check_float=1;
            }
         else if(check_result_sub[1]>q[1] || check_result_sub[1]==q[1])
         	{
            check_loop=0;
            }
          }
      else if((kk-1)>1)
      	{
         ii=0,jj=0,ll=0;
         for(i=1;i<=(kk-1);i++)
         	{
         	if (check_result_sub[i]<q[i])
            	{
               ii=1;
               break;
               }
            else if(check_result_sub[i]>q[i])
            	{
               jj=1;
               break;
               }
            else if (check_result_sub[i]==q[i])
            	{
               ll++;
               }
            }
         if(ii==1)
           	{
            check_loop=1;//stop, result float
            }
         else if(jj==1)
         	{
            check_loop=0;//loop back to
            }
         else if(ll==(kk-1))
         	{
            check_loop=1;
            result_div_diff++;
            kk=2;
            check_result_sub[1]=0;
            }
         }
      } 
    ////cout<<"\ncheck loop ="<<check_loop<<"\n";
    if(check_loop==0)
    	{
      result_div_diff++;
      ////cout<<"\ntukar  check result ke num1\n";
      for(k=1;k<=(kk-1);k++)
   		{
      	p[k]=check_result_sub[k];
         ////cout<<"\p["<<k<<"]="<<p[k]<<"\n";
      	}
      for(k=1;k<=iq;k++)
   		{
         ////cout<<"\q["<<k<<"]="<<q[k]<<"\n";
      	}
      //getch ();
      ip=(kk-1);
      loop=ip;
      }
   // else if(check_loop==1 && ii!=1)
     //	{
    else if(check_loop==1)
    	{
      result_div_diff++;
      }

   // compute result div array 
    result[1]=result_div_diff;  
      for(i=1;i<=sum_digit;i++)
      	{
         if(i==1)
         	{
            ////cout<<"\ncondition1. result["<<i<<"] = "<<result[i]<<"\n";
         	if(result[1]==10)
            	{
               if(i==sum_digit)
               	{
                  sum_digit++;
                  }
               result_div_diff=0;
               result[1]=0;
               //result[1+1]=1;
               save_remainder[1]=1;
               }
         	 else if(result[1]<10)
             	{
               result[1]=result_div_diff;
               //result[i+1]=0;
               save_remainder[1]=0;
               }
            }
         else if(i>1)
         	{
            result[i]=result[i]+save_remainder[i-1];
            //result[i]++;
            if(result[i]==10)
         		{
               if(i==sum_digit)
               	{
                  sum_digit++;
                  }
            	result[i]=0;
               //result[i+1]=0;
            	save_remainder[i]=1;
            	}
         	else if(result[i]<10)
         		{
               result[i]=result[i];
               //result[i+1]=0;
            	save_remainder[i]=0;
            	}
            }
         }
    for(i=1;i<=sum_digit;i++)
      	{
         ////cout<<"\nresult["<<i<<"] = "<<result[i]<<"\n";
         }
}while(check_loop==0);
//cout<<"\ncheck_float :"<<check_float<<"\n";
if(check_float==0)
	{
	//cout<<"\n\nso result_div ";
   	for(i=1;i<=loop_kk;i++)
			{
   			//cout<<p_split[i];
   		}//cout<<" / "<<num2<<" = ";
   file_output<<"\n\nso result_div ";
   	for(i=1;i<=loop_kk;i++)
			{
   		file_output<<p_split[i];
   		}file_output<<" / "<<num2<<" = ";
	for(i=sum_digit;i>=1;i--)
      	{
         result_div_original[loop_div]=result[i];
         //cout<<result_div_original[loop_div];
         file_output<<result[i];
         loop_div++;
         }
   //cout<<"\ndiv completed\n";
   file_output<<"\ndiv completed\n";
   //cout<<"remainder = ";
   file_output<<"remainder = ";
   for(k=1;k<=(kk-1);k++)
   	{
      loop_remainder=kk-1;
      remainder_end[k]=check_result_sub[k];
      //cout<<check_result_sub[k];
      file_output<<check_result_sub[k];
      }
   }
else if(check_float==1)
	{
   //cout<<"\n\nso result_div ";
   	for(i=1;i<=loop_kk;i++)
			{
   		//cout<<p_split[i];
   		}//cout<<" / "<<num2<<" = ";
   file_output<<"\n\nso result_div ";
   	for(i=1;i<=loop_kk;i++)
			{
   		file_output<<p_split[i];
   		}file_output<<" / "<<num2<<" = ";
   for(i=sum_digit;i>=1;i--)
      	{
         result_div_original[loop_div]=result[i];
         //cout<<result_div_original[loop_div];
         file_output<<result[i];
         loop_div++;
         }
   //cout<<"\nnot div completed\n";
   file_output<<"\nnot div completed\n";
   //cout<<"remainder = ";
   file_output<<"remainder = ";
   for(k=1;k<=(kk-1);k++)
   	{
      loop_remainder=kk-1;
      remainder_end[k]=check_result_sub[k];
      //cout<<check_result_sub[k];
      file_output<<check_result_sub[k];
      }
   }

	}

//***************************************************************************************************************************//
// multiplication result div p_split dengan q[i]
//cout<<"\nresult p_split : \n";
 for(i=1;i<=loop_kk;i++)
	{
   //cout<<p_split[i];
   }
 //cout<<"\n\n";
ip=iq;
iq=sum_digit; 
for(i=1;i<=ip;i++)
	{
   p[i]=num2[i-1]-48;
   //cout<<p[i];
   }
//cout<<"\n";
ii=1;
for(i=iq;i>=1;i--)
	{
   q[ii]=result[i];
   //cout<<q[ii];
   ii++;
   }
diff=abs(ip-iq);
//cout<<"\ndiff = "<<diff<<"\n";

if (ip>=iq)
	{
   //cout<<"\n ip>=iq \n";
   for(i=ip;i>=1;i--)
	{
   if(i<=diff)
   	{
      q[i]=0;
      }
   else if(i>diff)
   	{
   	q[i]=q[i-diff];
   	}
   //cout<<"\nresult["<<i<<"]= "<<q[i]<<"\n";
   }
	iq=ip;
   //cout<<"\nip = "<<ip<<"\n";
	//cout<<"\niq = "<<iq<<"\n";
	}
else if(ip<iq)
	{
   //cout<<"\n ip<iq \n";
   for(i=iq;i>=1;i--)
		{
   	if(i<=diff)
   		{
      	q[i]=0;
      	}
   	else if(i>diff)
   		{
   		q[i]=p[i-diff];
   		}
   	//cout<<"\nresult["<<i<<"]= "<<q[i]<<"\n";
   	}
   ii=1;
   for(i=iq;i>=1;i--)
		{
   	p[ii]=result[i];
   	//cout<<p[ii];
   	ii++;
   	}
   ip=iq+ip;
   iq=ip-iq;
	ip=ip-iq;
   iq=ip;
	//cout<<"\nip = "<<ip<<"\n";
   //cout<<"\niq = "<<iq<<"\n";
	}
if((p[1]==0 && ip==1 ) || (q[1]==0 && iq==1))
	{
    //cout<<"\n condition.1 \n";
   //cout<<"\nresult multiplication p * q adalah \n";
   file_output<<"\nresult multiplication p * q adalah \n";
   c[1]=0;
  	//cout<<c[1];
   file_output<<c[1];
   }
//else if(((num1[0]-48)==1 || (num2[0]-48)==1) && (ip==1 || iq==1))
 //	{
else if((p[1]==1 && ip==1 ) || (q[1]==1 && iq==1))
	{
    //cout<<"\n condition.2 \n";
   //cout<<"\nresult multiplication p * q adalah \n";
   file_output<<"\nresult multiplication p * q adalah \n";
   if(ip==1 && iq==1)
   	{
      result_mul[1][1]=p[1]*q[1];
   	if(result_mul[1][1]<10)
   		{
      	c[1]=result_mul[1][1];
      	//cout<<c[1];
   		file_output<<c[1];
      	kk=2;
      	}
   	else if(result_mul[1][1]>=10)
   		{
      	result_div=((result_mul[1][1])/10);
      	re_result_div=(result_mul[1][1])-10*result_div;
      	c[2]=re_result_div;
      	c[1]=result_div;
      	for(i=1;i<=2;i++)
      		{
      		//cout<<c[i]<<" ";
   			file_output<<c[i];
         	}
      	kk=3;
      	}
      }
   else if(ip==1 && iq>1)
   	{
      for(i=1;i<=iq;i++)
      	{
      	c[i]=q[i];
      	//cout<<c[i];
   		file_output<<c[i];
         }
      }
   else if(iq==1 && ip>1)
   	{
      for(i=1;i<=ip;i++)
      	{
      	c[i]=p[i];
      	//cout<<c[i];
   		file_output<<c[i];
         }
      }
   }
else if(ip==1 && iq==1)
	{
   //cout<<"\n condition.3 \n";
   //cout<<"\nresult multiplication p * q adalah \n";
   file_output<<"\nresult multiplication p * q adalah \n";
   result_mul[1][1]=p[1]*q[1];
   if(result_mul[1][1]<10)
   	{
      c[1]=result_mul[1][1];
      //cout<<c[1];
   	file_output<<c[1];
      kk=2;
      }
   else if(result_mul[1][1]>=10)
   	{
      result_div=((result_mul[1][1])/10);
      re_result_div=(result_mul[1][1])-10*result_div;
      c[2]=re_result_div;
      c[1]=result_div;
      for(i=1;i<=2;i++)
      	{
      	//cout<<c[i]<<" ";
   		file_output<<c[i];
         }
      kk=3;
      }
   }
else
	{
   //cout<<"\n condition.4 \n";
   //to ip already difinited
iq=sum_digit;
//inisialisasi blank matric for a[i][j]
   for(int i=ip;i>=(ip-iq);i--)
   	{
      for(int j=1;j<=(2*ip-1);j++)
      	{
         a[i][j]=0;
      	}
      }

   for(i=1;i<=ip;i++)
   	{
      p[i]=p[i];
      //cout<<p[i];
      }    
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
               	re_result_div=(result_mul[l][k])-10*result_div;
               	result_mul[l][k]=re_result_div;
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
            //cout<<"result_mul["<<l<<"]["<<k<<"] = "<<result_mul[l][k]<<"\n";
            //continue;
            } 
         else
         	{
         	result_mul[l][k]=p[k]*q[l]+save[k+1];
            ////cout<<"p["<<k<<"]*q["<<l<<"]="<<result_mul[l][k]<<"\n";
         	if(result_mul[l][k]<10)
         		{
           		if(k==ip)
               	{
              		save[k]=0;
               	}
               else if(k==1 && l!=1)
               		{
                     ////cout<<"save_end = "<<save_end<<"\n";
                     result_div=((result_mul[l][k]+save_end)/10);
            			re_result_div=(result_mul[l][k]+save_end)-10*result_div;
                     result_mul[l][k]=re_result_div;
                  	save[k]=result_div;
                     save_end=result_div;
                     ////cout<<"save_end = "<<save_end<<"\n";
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
            	}
         	else if(result_mul[l][k]>=10)
         		{
            	if(k==ip)
               	{
               	result_div=(result_mul[l][k]/10);
            		re_result_div=result_mul[l][k]-10*result_div;
            		result_mul[l][k]=re_result_div;
            		save[k]=result_div;
               	}
           	 	else
            		{

                  if(k!=1)
               		{
                     result_div=((result_mul[l][k])/10);
            			re_result_div=(result_mul[l][k])-10*result_div;
            			result_mul[l][k]=re_result_div;
                  	save[k]=result_div;
                  	}
               	else if(k==1 && l!=1)
               		{
                     ////cout<<"save_end = "<<save_end<<"\n";
                     result_div=((result_mul[l][k]+save_end)/10);
            			re_result_div=(result_mul[l][k]+save_end)-10*result_div;
                     result_mul[l][k]=re_result_div;
                  	save[k]=result_div;
                     save_end=result_div;
                     ////cout<<"save_end = "<<save_end<<"\n";

                  	}
                  else if(k==1 && l==1)
               		{
                     result_mul[l][k]=result_mul[l][k]+save_end;
                  	save[k]=result_div;  
                  	}
               	}  
					}
            }
      	}

      //cout<<"\n";
      }
    //cout<<"\n\n";
   iq=sum_digit; //to be less size of matric
   file_output<<"\n\n";
   file_output<<"ip ="<<ip<<"\n";
   file_output<<"\niq ="<<iq<<"\n";
   //display result multiplication
   //cout<<"\nresult kali within matrik : \n";
   file_output<<"\nresult kali within matrik : \n";
   //cout<<setprecision(2);
   //cout<<setiosflags(ios::fixed);
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
   file_output<<"ip ="<<ip<<"\n";
   file_output<<"\niq ="<<iq<<"\n";
   //getch ();
   //cout<<"\nresult kali within matrik within bentuk siap dijumlahan : \n";
   file_output<<"result mul within matric ready to add: \n";
   for(int i=ip;i>=(ip-iq);i--)
   	{
      for(int j=(ip-iq);j<=(2*ip-1);j++)
      	{
         a[i][j]=result_mul[i][j-(i-1)];
         //if(a[i][j]>=10 && i!=(ip-iq) && j!=(ip-iq))
           //	{
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
      ////cout<<"b["<<i<<"]="<<b[i]<<"\n";
      //getch ();
      for(int j=(ip-iq);j<=ip;j++)
      	{
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
   ////cout<<"\ncheck_zero ="<<check_zero<<"\n";
   kk=1;
   file_output<<"\nresult multiplication p * q adalah \n";
   for(int i=(ip-iq);i<=(2*ip-1);i++)
   	{
       if(i<check_zero)
      	{
         continue;
         }
      else
      	{
         c[kk]=c[i];
      	////cout<<c[kk];
         //file_output<<c[kk];
         kk++;
         }
      }
   }
  //getch ();
//cout<<"\n\n";
//******************************************************************************************************************************//
 for(int i=1;i<=(kk-1);i++)
   	{
      //cout<<c[i];
      file_output<<c[i];
      }
 //cout<<"\nresult p_split : \n";
 for(i=1;i<=loop_kk;i++)
	{
   //cout<<p_split[i];
   }
//cout<<"\n\n";
//subtraction p_split dengan c[i]  conditionisi
ip=loop_kk;
iq=kk-1;
//cout<<"\n******pada subtraction*********\n";
if(ip>iq)
	{
   loop=ip;
   for(i=1;i<=ip;i++)
   	{
      p[i]=p_split[i];
      //cout<<p[i];
      }
      //cout<<"\n";
   diff=abs(ip-iq);
   for(j=ip;j>=1;j--)
   	{
      if(j<=diff)
      	{
         q[j]=0;
         //cout<<q[j];
         }
      else if(j>diff)
      	{
      	q[j]=c[j-diff];
         //cout<<q[j];
      	}
      }
   result_add[loop]=0;
   for(k=loop;k>=1;k--)
   	{
      result_add[k]+=p[k]-q[k];
      ////cout<<result_add[k]<<" ";
      if(result_add[k]<0 && k!=1)
      	{
         result_add[k]=result_add[k]+10;
         ////cout<<result_add[k]<<" ";
         result_add[k-1]=-1;
         }
      else
      	{
         result_add[k]=result_add[k];
         result_add[k-1]=0;
         }
      }
   }
   
   else if(ip==iq)
	{
   	////cout<<"iq ="<<iq<<"\n";
      //cout<<"\nkod. sama \n";
      for(i=1;i<=iq;i++)
   		{
      	p[i]=p_split[i];
      	//cout<<"p["<<i<<"]="<<p[i]<<"\n";
         }
      //cout<<"\n\n";
      for(i=1;i<=iq;i++)
   		{
      	q[i]=c[i];
      	//cout<<"q["<<i<<"]="<<c[i]<<"\n";
         }
      int ii=0,jj=0,kk=0;
      for(i=1;i<=iq;i++)
   		{
      	//p[i]=p_split[i];
      	////cout<<"p["<<i<<"]="<<p_split[i]<<"\n";
      	//q[i]=c[i];
      	////cout<<"q["<<i<<"]="<<c[i]<<"\n";
   		if (p[i]<q[i])
      		{
      		ii=1;
            break;
         	}
     	 	else if(p[i]>q[i])
      		{
         	jj=1;
            break;
         	}
      	else if (p[i]==q[i])
      		{
         	kk++;
         	}
      	}
         
    if(ii==1)
    	{
	   loop=iq;
      ////cout<<"\nii = "<<(ii)<<"\n";
	   for(i=1;i<=iq;i++)
	   	{
	      //p[i]=p_split[i];
	      q[i]=c[i];
	      }
	      //cout<<"\n";
	   diff=abs(ip-iq);
	   for(j=iq;j>=1;j--)
	   	{
	      if(j<=diff)
	      	{
	         p[j]=0;
	         }
	      else if(j>diff)
	      	{
	      	p[j]=p_split[j-diff];
	      	}
	      }
	   result_add[loop]=0;
	   for(k=loop;k>=1;k--)
	   	{
	      result_add[k]+=q[k]-p[k];
	      ////cout<<result_add[k]<<" ";
	      if(result_add[k]<0 && k!=1)
	      	{
	         result_add[k]=result_add[k]+10;
	         ////cout<<result_add[k]<<" ";
	         result_add[k-1]=-1;
	         }
	      else
	      	{
	         result_add[k]=result_add[k];
	         result_add[k-1]=0;
	         if(k==1 && result_add[k]!=0)
	         	{
	            result_add[k]=-1*result_add[k];
	            }
	         else if(k==1 && result_add[k]==0)
	         	{
	            result_add[k+1]=-1*result_add[k+1];
	            }
	         }
	      }
      }
      else if(jj==1)
      	{
           loop=ip;
	   for(i=1;i<=ip;i++)
	   	{
	      p[i]=p_split[i];
	      }
	      //cout<<"\n";
	   diff=abs(ip-iq);
	   for(j=ip;j>=1;j--)
	   	{
	      if(j<=diff)
	      	{
	         q[j]=0;
	         }
	      else if(j>diff)
	      	{
	         index=diff+1;//hope index = 0,1,..
	      	q[j]=c[j-diff];
	      	}
	      }
	   result_add[loop]=0;
	   for(k=loop;k>=1;k--)
	   	{
	      result_add[k]+=p[k]-q[k];
	      //cout<<"\n"<<result_add[k]<<"\n";

	      if(result_add[k]<0 && k!=1)
	      	{
	         result_add[k]=result_add[k]+10;
	         //cout<<"\n"<<result_add[k]<<"\n";
	         result_add[k-1]=-1;
	         }
	      else
	      	{
	         result_add[k]=result_add[k];
	         result_add[k-1]=0;
	         }
	      }
         }
      else if(kk==iq)
      	{
         loop=1;
         result_add[1]=0;
         } 
   }

   //check potition zero 
   check_zero=1;
   ////cout<<"\nip - iq ="<<(ip-iq)<<"\n";
   while(result_add[check_zero]==0){
   check_zero++;
   }
   //cout<<"\ncheck_zero ="<<check_zero<<endl;
   //display result subtraction
   //cout<<"\nresult subtraction within array = ";
   file_output<<"\nresult subtraction within array = ";
   kk=1;
	for(k=1;k<=loop;k++)
   	{
      if(k<check_zero && loop!=1)
      	{
         continue;
         }
      else
      	{
         result_add[kk]=result_add[k];
         ////cout<<result_add[kk];
         kk++;
         }     
      }

//cout<<"\n\n";
//getch ();
 //******************************************************************************************************************************//
for(k=1;k<=(kk-1);k++)
   	{
      //cout<<result_add[k];
      file_output<<result_add[k];
      }
//cout<<"\nresult addition one array on the split number  = ";
file_output<<"\nresult addition one array on the split number  = ";
for(k=1;k<=((kk-1)+1);k++)
   	{
      p_split[k]=result_add[k];
      if(k==((kk-1)+1) && loop_split<strlen(num1))
      	{
         p_split[k]=num1[loop_split]-48;
         }
      //cout<<p_split[k];
      file_output<<p_split[k];
      }
//cout<<"\n\n";   
if(p_split[1]==0 && kk==2)
	{
//cout<<"\nresult editing addition one array on the split number  = ";
file_output<<"\nresult editing addition one array on the split number  = ";
   kk=1;
   p_split[1]=num1[loop_split]-48;
   //cout<<p_split[1];
   file_output<<p_split[1];
	}
loop_split++;
loop_kk=kk;
hit_loop++;
//cout<<"*"<<hit_loop;
}while(loop_split<=strlen(num1));
//cout<<"\nsum loop :"<<hit_loop<<"\n";
cout<<"\nresult division :\n";
file_output<<"\n\nresult division :\n";
//cout<<"loop_div = "<<(loop_div-1)<<"\n";
for(i=1;i<=(loop_div-1);i++)
	{
   cout<<result_div_original[i];
   file_output<<result_div_original[i];
   }
cout<<"\n\n";
file_output<<"\n\n";
cout<<"remainder :\n";
file_output<<"remainder :\n";
check_zero=1;
   while(remainder_end[check_zero]==0){
   check_zero++;
   }
	for(k=1;k<=loop_remainder;k++)
   	{
      if(k<check_zero && loop_remainder!=1)
      	{
         continue;
         }
      else
      	{
      	cout<<remainder_end[k];
      	file_output<<remainder_end[k];
         }
      }
   }
}
getch ();
}
