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
file_output.open("_jum.txt");
char *kar_p,*kar_q;
int ip,iq,loop,i,j,k,selisih,*p,*q,*hasil_jml,indek;
//cout<<"nilai p = ";cin.getline(kar_p,100);
//cout<<"nilai q = ";cin.getline(kar_q,100);

p=new int[bit];
q=new int[bit];
hasil_jml=new int[bit];
//kar_p="357230523957912579237598320785723562308956815871759889230958293502859280501802359238606529652610096260000000000579517239532095789729152359823268123345793285793832583215921556732156732467348957349857329563279523857238957329857298579238532562379612389523973295873295873295239852395109593512396513239223752358723653728563528563892579283579357329562356358932031592359235732895623560782849720979578237592758874122639451141473715520434901960";
//kar_q="493852837246637216102117603332758721572380572357235721310235235123051235285623562385632852352352365872356237592837598237592835237529385785723985293752356283901589581395178946984371893573985713928572395728571892355728572839578";
//kar_p="133274327582793585623058147240214239847959185982359863295723573295729517239586165239571238957923523959235895637265823975932175893275912375632562387561234623734384448706819088456459052252688235738318076173674446929536512";
//kar_q="1215523597902529699635061776130112585388017939162784249115428321727";
//kar_p="1332743275827935856230581472402142398479591859823598632957235732957295172395861523957123895792352395923589563726582397593217589327591237563256238756123583925782351236518723518235182365273623756257238957923562357858214";
kar_p="133274327582793585623058147240214239847959185982359863295723573295729517239586165239571238957923523959235895637265823975932175893275912375632562387561235839257982351236518723518235182365273623756257238957923562357858214";
kar_q="25";
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

if (ip>=iq)
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
      hasil_jml[k]+=p[k]+q[k];
      //cout<<hasil_jml[k]<<" ";
      if(hasil_jml[k]>=10 && k!=1)
      	{
         hasil_jml[k]=hasil_jml[k]-10;
         //cout<<hasil_jml[k]<<" ";
         hasil_jml[k-1]=1;
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
   selisih=abs(iq-ip);
   for(j=1;j<=iq;j++)
   	{
      if(j<=selisih)
      	{
         p[j]=0;
         }
      else if(j>selisih)
      	{
         indek=selisih+1;
      	p[j]=kar_p[j-indek]-48;
      	}
      }
   hasil_jml[loop]=0;
   for(k=loop;k>=1;k--)
   	{
      hasil_jml[k]+=q[k]+p[k];
      if(hasil_jml[k]>=10 && k!=1)
      	{
         hasil_jml[k]=hasil_jml[k]-10;
         hasil_jml[k-1]=1;
         }
      else
      	{
         hasil_jml[k]=hasil_jml[k];
         hasil_jml[k-1]=0;
         }
      }
   }
   //tampilan hasil penjumlahan
   cout<<"\nhasil jumlah dalam array = ";
   file_output<<"\nhasil jumlah dalam array = ";
	for(k=1;k<=loop;k++)
   	{
      cout<<hasil_jml[k];
      file_output<<hasil_jml[k];
      }
getch ();
}

