#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <fstream.h>
#include <string.h>
#define bit 1024

void main ()
{
ofstream file_output;
file_output.open("_krg.txt");
//char kar_p[100],kar_q[100];
char *kar_p,*kar_q;
int ip,iq,loop,i,j,k,selisih,*p,*q,*hasil_jml,indek,cek_nol;
//cout<<"nilai p = ";cin.getline(kar_p,100);
//cout<<"nilai q = ";cin.getline(kar_q,100);
kar_p="1001";
kar_q="12";

ip=strlen(kar_p);
iq=strlen(kar_q);

file_output<<"\npanjang kar_p = "<<ip<<" digit = "<<ip*8<<" bit"<<"\n";
   file_output<<"panjang kar_q = "<<iq<<" digit = "<<iq*8<<" bit"<<"\n\n";
   cout<<"p = "<<kar_p<<"\n";
   cout<<"q = "<<kar_q<<"\n\n";
   file_output<<"p = "<<kar_p<<"\n";
   file_output<<"q = "<<kar_q<<"\n";

cout<<"panjang kar_p = "<<ip<<" digit = "<<ip*8<<" bit"<<"\n";
cout<<"panjang kar_q = "<<iq<<" digit = "<<iq*8<<" bit"<<"\n";

p=new int[bit];
q=new int[bit];
hasil_jml=new int[bit];
if(ip>iq)
	{
   loop=ip;
   for(i=1;i<=ip;i++)
   	{
      p[i]=kar_p[i-1]-48;
      }
      cout<<"\n";
   selisih=abs(ip-iq);
   for(j=1;j<=ip;j++)
   	{
      if(j<=selisih)
      	{
         q[j]=0;
         }
      else if(j>selisih)
      	{
         indek=selisih+1;//agar indek = 0,1,..
      	q[j]=kar_q[j-indek]-48;
      	}
      }
   hasil_jml[loop]=0;
   for(k=loop;k>=1;k--)
   	{
      hasil_jml[k]+=p[k]-q[k];
      //cout<<hasil_jml[k]<<" ";
      if(hasil_jml[k]<0 && k!=1)
      	{
         hasil_jml[k]=hasil_jml[k]+10;
         //cout<<hasil_jml[k]<<" ";
         hasil_jml[k-1]=-1;
         }
      else
      	{
         hasil_jml[k]=hasil_jml[k];
         hasil_jml[k-1]=0;
         }
      }
   }
   else if(ip<iq)
	{
   loop=iq;
   for(i=1;i<=iq;i++)
   	{
      q[i]=kar_q[i-1]-48;
      }
      cout<<"\n";
   selisih=abs(ip-iq);
   for(j=1;j<=iq;j++)
   	{
      if(j<=selisih)
      	{
         p[j]=0;
         }
      else if(j>selisih)
      	{
         indek=selisih+1;//agar indek = 0,1,..
      	p[j]=kar_p[j-indek]-48;
      	}
      }
   hasil_jml[loop]=0;
   for(k=loop;k>=1;k--)
   	{
      hasil_jml[k]+=q[k]-p[k];
      //cout<<hasil_jml[k]<<" ";
      if(hasil_jml[k]<0 && k!=1)
      	{
         hasil_jml[k]=hasil_jml[k]+10;
         //cout<<hasil_jml[k]<<" ";
         hasil_jml[k-1]=-1;
         }
      else
      	{
         hasil_jml[k]=hasil_jml[k];
         hasil_jml[k-1]=0;
         if(k==1 && hasil_jml[k]!=0)
         	{
            hasil_jml[k]=-1*hasil_jml[k];
            }
         else if(k==1 && hasil_jml[k]==0)
         	{
            hasil_jml[k+1]=-1*hasil_jml[k+1];
            }
         }
      }
   }
   else if(ip==iq)
	{
   	//cout<<"iq ="<<iq<<"\n";
      int ii=0,jj=0,kk=0;
      for(i=1;i<=iq;i++)
   		{
      	p[i]=kar_p[i-1]-48;
      	//cout<<"p["<<i<<"]="<<p[i]<<"\n";
      	q[i]=kar_q[i-1]-48;
      	//cout<<"q["<<i<<"]="<<q[i-1]<<"\n";
   		if (p[i]<q[i])
      		{
      		ii=1;
         	}
     	 	else if(p[i]>q[i])
      		{
         	jj=1;
         	}
      	else if (p[i]==q[i])
      		{
         	kk++;
         	}
      	}
         
    if(ii==1)
    	{
	   loop=iq;
	   for(i=1;i<=iq;i++)
	   	{
	      p[i]=kar_p[i-1]-48;
	      q[i]=kar_q[i-1]-48;
	      }
	      cout<<"\n";
	   selisih=abs(ip-iq);
	   for(j=1;j<=iq;j++)
	   	{
	      if(j<=selisih)
	      	{
	         p[j]=0;
	         }
	      else if(j>selisih)
	      	{
	         indek=selisih+1;//agar indek = 0,1,..
	      	p[j]=kar_p[j-indek]-48;
	      	}
	      }
	   hasil_jml[loop]=0;
	   for(k=loop;k>=1;k--)
	   	{
	      hasil_jml[k]+=q[k]-p[k];
	      //cout<<hasil_jml[k]<<" ";
	      if(hasil_jml[k]<0 && k!=1)
	      	{
	         hasil_jml[k]=hasil_jml[k]+10;
	         //cout<<hasil_jml[k]<<" ";
	         hasil_jml[k-1]=-1;
	         }
	      else
	      	{
	         hasil_jml[k]=hasil_jml[k];
	         hasil_jml[k-1]=0;
	         if(k==1 && hasil_jml[k]!=0)
	         	{
	            hasil_jml[k]=-1*hasil_jml[k];
	            }
	         else if(k==1 && hasil_jml[k]==0)
	         	{
	            hasil_jml[k+1]=-1*hasil_jml[k+1];
	            }
	         }
	      }
      }
      else if(jj==1)
      	{
           loop=ip;
	   for(i=1;i<=ip;i++)
	   	{
	      p[i]=kar_p[i-1]-48;
	      }
	      cout<<"\n";
	   selisih=abs(ip-iq);
	   for(j=1;j<=ip;j++)
	   	{
	      if(j<=selisih)
	      	{
	         q[j]=0;
	         }
	      else if(j>selisih)
	      	{
	         indek=selisih+1;//agar indek = 0,1,..
	      	q[j]=kar_q[j-indek]-48;
	      	}
	      }
	   hasil_jml[loop]=0;
	   for(k=loop;k>=1;k--)
	   	{
	      hasil_jml[k]+=p[k]-q[k];
	      //cout<<hasil_jml[k]<<" ";
	      if(hasil_jml[k]<0 && k!=1)
	      	{
	         hasil_jml[k]=hasil_jml[k]+10;
	         //cout<<hasil_jml[k]<<" ";
	         hasil_jml[k-1]=-1;
	         }
	      else
	      	{
	         hasil_jml[k]=hasil_jml[k];
	         hasil_jml[k-1]=0;
	         }
	      }
         }
      else if(kk==iq)
      	{
         loop=1;
         hasil_jml[1]=0;
         } 
   }
   //tampilan hasil pengurangan
   cout<<"\nhasil pengurangan dalam array = ";
   file_output<<"\nhasil pengurangan dalam array = ";
   cek_nol=1;
   while(hasil_jml[cek_nol]==0){
   cek_nol++;
   }

	for(k=1;k<=loop;k++)
   	{
      if(k<cek_nol && loop!=1)
      	{
         continue;
         }
      else
      	{
      	cout<<hasil_jml[k];
      	file_output<<hasil_jml[k];
         }
      }
getch ();
}

