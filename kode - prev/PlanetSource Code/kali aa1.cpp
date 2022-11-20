#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <fstream.h>
#include <string.h>
#include <iomanip.h>
#define bit 5000
void main ()
{
ofstream file_output;
file_output.open("hasil_kali.txt");
//char *kar_p,*kar_q;
char *kar_p,*kar_q,*temp;
long int ip,iq,i,j,k,l,selisih,*p,*q;
long int hasil_bagi,sisa_hasil_bagi,*simpan,**hasil_kali,indek;
long int **a,*b,*c;
long int simpan_akhir,cek_nol,kk;
////cout<<"\npanjang bit :";
//cin>>bit;
p=new long int[bit];
q=new long int[bit];
simpan=new long int[bit];
hasil_kali=new long int*[bit];
for(int i=1;i<=bit;i++) hasil_kali[i]=new long int[bit];
a=new long int*[bit];
for(int i=1;i<=bit;i++) a[i]=new long int[bit];
b=new long int[bit];
c=new long int[bit];

//long int ip,iq,loop,i,j,k,l,selisih,*p,*q,*hasil_jml;
//long int hasil_bagi,sisa_hasil_bagi,*simpan,*hasil_kali,*simpan_next,indek;
////cout<<"nilai p = ";cin.getline(kar_p,100);
////cout<<"nilai q = ";cin.getline(kar_q,100);
//kar_p="219405589621149717595397956462797292565725274046306079496491710958838386290764645503575250296127839628011910858991253870398146100725848046868435996130913605840534052262692634577392353664076287902750981209575229409212901230292090745079842446639052297351522309772714179265192100887440976489920580820679016067314518442382634767674205417675413714998470161120443810752674093317571069174302954839213178254205";
//kar_q="1628174216412384210125738921598312";
//kar_p="3099402967041711293559491796284052089487422929822322402226129611528593424176422447431889278091244743238044084587577301765864555657579357572850288082819438122278659331081830779493841450355200552471098580416827031578098";
kar_p="3099402967041711293559491796284052089487422929822322402226129611528593424176422447431889278091244743238044084587577301765864555657579357572850288082819438122278659331081830779493841450355200552471098580416827031578098";
kar_q="43";
//kar_p="1";
//kar_q="100";
//kar_p="19";
//kar_q="10";

/*p=new long int[1000];
q=new long int[1000];
hasil_jml=new long int[1000];
simpan=new long int[1000];
hasil_kali=new long int[1000];
simpan_next=new long int[1000];*/

ip=strlen(kar_p);
iq=strlen(kar_q);

//hasil perkalian
   file_output<<"\npanjang kar_p = "<<ip<<" digit = "<<ip*8<<" bit"<<"\n";
   file_output<<"panjang kar_q = "<<iq<<" digit = "<<iq*8<<" bit"<<"\n\n";
   cout<<"p = "<<kar_p<<"\n";
   cout<<"q = "<<kar_q<<"\n\n";
   file_output<<"p = "<<kar_p<<"\n";
   file_output<<"q = "<<kar_q<<"\n";

cout<<"panjang p = "<<ip<<"\n";
cout<<"panjang q = "<<iq<<"\n";
getch ();
if (ip>=iq)
	{
   kar_p;
   kar_q;
	ip=strlen(kar_p);
	iq=strlen(kar_q);
	}
else if(ip<iq)
	{
	temp=kar_p;
	kar_p=kar_q;
	kar_q=temp;
	ip=strlen(kar_p);
	iq=strlen(kar_q); 
	}

//if(((kar_p[0]-48)==0 || (kar_q[0]-48)==0) && (ip==1 || iq==1))
	//{
if(((kar_p[0]-48)==0 && ip==1 ) || ((kar_q[0]-48)==0 && iq==1))
	{
   //cout<<"\nhasil perkalian p * q adalah \n";
   file_output<<"\nhasil perkalian p * q adalah \n";
   c[1]=0;
  	//cout<<c[1];
   file_output<<c[1];
   }
//else if(((kar_p[0]-48)==1 || (kar_q[0]-48)==1) && (ip==1 || iq==1))
 //	{
else if(((kar_p[0]-48)==1 && ip==1 ) || ((kar_q[0]-48)==1 && iq==1))
	{
   //cout<<"\nhasil perkalian p * q adalah \n";
   file_output<<"\nhasil perkalian p * q adalah \n";
   if(ip==1)
   	{
      for(i=1;i<=iq;i++)
      	{
      	c[i]=kar_q[i-1]-48;
      	//cout<<c[i];
   		file_output<<c[i];
         }
      }
   else if(iq==1)
   	{
      for(i=1;i<=ip;i++)
      	{
      	c[i]=kar_p[i-1]-48;
      	//cout<<c[i];
   		file_output<<c[i];
         }
      } 
   }
else
	{
//inisialisasi matrik kosong untuk a[i][j]
   for(int i=ip;i>=(ip-iq);i--)
   	{
      for(int j=1;j<=(2*ip-1);j++)
      	{
         a[i][j]=0;
      	}
      }

   for(i=1;i<=ip;i++)
   	{
      p[i]=kar_p[i-1]-48;
      //cout<<p[i];
      }
      //cout<<"\n";
   selisih=abs(ip-iq);
   for(j=1;j<=ip;j++)
   	{
      if(j<=selisih)
      	{
         q[j]=0;
         //cout<<q[j];
         }
      else if(j>selisih)
      	{
         indek=selisih+1;//agar indek = 0,1,..
      	q[j]=kar_q[j-indek]-48;
         //cout<<q[j];
      	}
      }
   //cout<<"\n\n";
   simpan_akhir=0;
   for(l=ip;l>=1;l--)
   	{
      simpan[ip+1]=0;
   	for(k=ip;k>=1;k--)
   		{
      	if(q[l]==0 && l<=selisih)
         	{
            hasil_kali[l][k]=p[k]*q[l]+simpan_akhir;
            ////cout<<"\nhasil_kali["<<l<<"]["<<k<<"] = "<<hasil_kali[l][k]<<"\n";
            //getch ();
            if(k==1)
            	{
               if(hasil_kali[l][k]>=10)
               	{
            		hasil_bagi=((hasil_kali[l][k])/10);
               	sisa_hasil_bagi=(hasil_kali[l][k])-10*hasil_bagi;
               	hasil_kali[l][k]=sisa_hasil_bagi;
               	simpan[k]=hasil_bagi;
               	simpan_akhir=hasil_bagi;
                  }
               else if(hasil_kali[l][k]<10)
               	{
                  hasil_kali[l][k]=hasil_kali[l][k];
                  simpan[k]=0;
                  simpan_akhir=0;
                  }
                  //hasil_kali[l][k]=hasil_kali[l][k];
               }
            else
            	{
               hasil_kali[l][k]=0;
               }
            //cout<<"hasil_kali["<<l<<"]["<<k<<"] = "<<hasil_kali[l][k]<<"\n";
            //continue;
            }
         /*else if(ip==1)
         	{
            hasil_kali[l][k]=p[k]*q[l];
            //cout<<hasil_kali[l][k];
            }*/
         else
         	{
         	hasil_kali[l][k]=p[k]*q[l]+simpan[k+1];
            ////cout<<"p["<<k<<"]*q["<<l<<"]="<<hasil_kali[l][k]<<"\n";
         	if(hasil_kali[l][k]<10)
         		{
           		if(k==ip)
               	{
              		simpan[k]=0;
               	}
               else if(k==1 && l!=1)
               		{
                     ////cout<<"simpan_akhir = "<<simpan_akhir<<"\n";
                     hasil_bagi=((hasil_kali[l][k]+simpan_akhir)/10);
            			sisa_hasil_bagi=(hasil_kali[l][k]+simpan_akhir)-10*hasil_bagi;
                     hasil_kali[l][k]=sisa_hasil_bagi;
                  	simpan[k]=hasil_bagi;
                     simpan_akhir=hasil_bagi;
                     ////cout<<"simpan_akhir = "<<simpan_akhir<<"\n";
                  	}
                  else if(k==1 && l==1)
               		{
                     hasil_kali[l][k]=hasil_kali[l][k]+simpan_akhir;
                  	simpan[k]=0;
                  	}
            	else
            		{
            		simpan[k]=0; 
               	}
            	//cout<<"hasil_kali["<<l<<"]["<<k<<"] = "<<hasil_kali[l][k]<<"\n";
               ////cout<<hasil_kali[l][k];
            	////cout<<"\nsimpan["<<k<<"] = "<<simpan[k]<<"\n";
               //getch ();
            	}
         	else if(hasil_kali[l][k]>=10)
         		{
            	if(k==ip)
               	{
               	hasil_bagi=(hasil_kali[l][k]/10);
            		sisa_hasil_bagi=hasil_kali[l][k]-10*hasil_bagi;
            		hasil_kali[l][k]=sisa_hasil_bagi;
            		simpan[k]=hasil_bagi;
               	}
           	 	else
            		{

                  if(k!=1)
               		{
                     hasil_bagi=((hasil_kali[l][k])/10);
            			sisa_hasil_bagi=(hasil_kali[l][k])-10*hasil_bagi;
            			hasil_kali[l][k]=sisa_hasil_bagi;
                  	simpan[k]=hasil_bagi;
                  	}
               	else if(k==1 && l!=1)
               		{
                     ////cout<<"simpan_akhir = "<<simpan_akhir<<"\n";
                     hasil_bagi=((hasil_kali[l][k]+simpan_akhir)/10);
            			sisa_hasil_bagi=(hasil_kali[l][k]+simpan_akhir)-10*hasil_bagi;
                     hasil_kali[l][k]=sisa_hasil_bagi;
                  	simpan[k]=hasil_bagi;
                     simpan_akhir=hasil_bagi;
                     ////cout<<"simpan_akhir = "<<simpan_akhir<<"\n";

                  	}
                  else if(k==1 && l==1)
               		{
                     hasil_kali[l][k]=hasil_kali[l][k]+simpan_akhir;
                  	simpan[k]=hasil_bagi;  
                  	}
               	}
            	//cout<<"hasil_kali["<<l<<"]["<<k<<"] = "<<hasil_kali[l][k]<<"\n";
               ////cout<<hasil_kali[l][k];
            	////cout<<"\nsimpan["<<k<<"] = "<<simpan[k]<<"\n";
               //getch ();
					}
            }
      	}

      //cout<<"\n";
      }
    //cout<<"\n\n";

   //tampilan hasil perkalian
   //cout<<"\nhasil kali dalam matrik : \n";
   file_output<<"\nhasil kali dalam matrik : \n";
   //cout<<setprecision(2);
   //cout<<setiosflags(ios::fixed);
   for(int i=ip;i>=(ip-iq);i--)
   	{
      for(int j=1;j<=ip;j++)
      	{
         //cout<<setw(3)<<hasil_kali[i][j];
         file_output<<setw(3)<<hasil_kali[i][j];
      	}
         //cout<<"\n";
         file_output<<"\n";
      }
   //cout<<"\n\n";
   file_output<<"\n\n";
   //getch ();
   //cout<<"\nhasil kali dalam matrik dalam bentuk siap dijumlahan : \n";
   file_output<<"hasil kali dalam matrik dalam bentuk siap dijumlahan : \n";
   for(int i=ip;i>=(ip-iq);i--)
   	{
      for(int j=(ip-iq);j<=(2*ip-1);j++)
      	{
         a[i][j]=hasil_kali[i][j-(i-1)];
         //if(a[i][j]>=10 && i!=(ip-iq) && j!=(ip-iq))
           //	{
          if(a[i][j]>=10)
           	{
            if(i==1 && j==1)
               {
               a[i][j]=hasil_kali[i][j-(i-1)];
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
   //cout<<"\n\n";
   ////cout<<"a[23][23]= "<<a[25][23]<<"\n";
   ////cout<<"a[23][23]= "<<a[24][23]<<"\n";
   ////cout<<"a[23][23]= "<<a[23][23]<<"\n";
   ////cout<<"\n\n";
   //getch ();
   simpan[2*ip]=0;
   for(int i=(2*ip-1);i>=(ip-iq);i--)
   	{
      b[i]=simpan[i+1];
      ////cout<<"b["<<i<<"]="<<b[i]<<"\n";
      //getch ();
      for(int j=(ip-iq);j<=ip;j++)
      	{
         ////cout<<"a["<<j<<"]["<<i<<"]="<<a[j][i]<<endl;
         /*if(a[j][i]>99)
         	{
            //cout<<"a["<<j<<"]["<<i<<"]="<<a[j][i]<<endl;
            a[j][i]=0;
            //cout<<"a["<<j<<"]["<<i<<"]="<<a[j][i]<<endl;
            //getch ();
            }*/
         //cout<<"a["<<j<<"]["<<i<<"]="<<a[j][i]<<endl;

         b[i]+=a[j][i];
         //cout<<b[i]<<endl;
         //getch ();
         //file_output<<b[i][j];
      	}
      	if(b[i]>=10)
         	{
            if(i==(ip-iq))
            	{
               c[i]=b[i];
            	simpan[i]=0;
               }
            else
            	{
      			c[i]=b[i]%10;
            	simpan[i]=(b[i]-c[i])/10;
               }
            }
         else if(b[i]<10)
         	{
            c[i]=b[i];
            simpan[i]=0;
            }
         /*else if(i==1)
         	{
            c[i]=b[i];
            simpan[i]=0;
            }
         else if(i==0)
         	{
            c[i]=simpan[i+1];
            simpan[i]=0;
            }*/
         //cout<<"c["<<i<<"]="<<c[i]<<endl;
      //getch ();
      //b[i-1]=simpan[i];
      //cout<<"simpan["<<i<<"]="<<simpan[i];
      //cout<<"\n";
      //file_output<<"\n";
      }

   //cout<<"\n\n";
   /*file_output<<"\nhasil perkalian p * q adalah \n";
   for(int i=(ip-iq);i<=(2*ip-1);i++)
   	{
       if(i<selisih)
      	{
         continue;
         }
      else
      	{
      	//cout<<c[i];
         file_output<<c[i];
         }
      }*/

   cek_nol=(ip-iq);
   ////cout<<"\nip - iq ="<<(ip-iq)<<"\n";
   ////cout<<"c["<<(ip-iq)<<"]="<<c[(ip-iq)]<<endl;
   while(c[cek_nol]==0){
   cek_nol++;
   }
   ////cout<<"\ncek_nol ="<<cek_nol<<"\n";
   kk=1;
   cout<<"\nhasil perkalian p * q adalah \n";
   file_output<<"\nhasil perkalian p * q adalah \n";
   for(int i=(ip-iq);i<=(2*ip-1);i++)
   	{
       if(i<cek_nol)
      	{
         continue;
         }
      else
      	{
         c[kk]=c[i];
      	//cout<<c[kk];
         //file_output<<c[kk];
         kk++;
         }
      }
   ////cout<<"\nkk ="<<(kk-1)<<"\n";
   /*file_output<<"\nhasil semua perkalian p * q  dengan nol didepan adalah \n";*/
   for(int i=1;i<=(kk-1);i++)
   	{
      cout<<c[i];
      file_output<<c[i];  
      }
	}
getch ();
}
