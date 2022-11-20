#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <fstream.h>
#include <string.h>
#include <iomanip.h>
//#include "Array.h"

#define bit 1024
void main ()
{
ofstream file_output;
file_output.open("_mod.txt");
//char *kar_p,*kar_q;
char *kar_p,*kar_q;
long int ip,iq,i,j,k,l,selisih;
long int *p,*q,*hasil_bagi_asli,*sisa_akhir,*simpan,*hasil_krg,*cek_hasil_krg,*p_split,*hasil_jml,*b,*c,*hasil,*simpan_sisa;
long int hasil_bagi,hasil_bagi_sel,sisa_hasil_bagi,indek;
long int **a,**hasil_kali;
long int simpan_akhir,loop,cek_loop,kk,ii,jj,ll,cek_float,byk_digit,sel_panj,cek_nol,loop_split,loop_kk,loop_bagi,loop_sisa;

p=new long int[bit];
q=new long int[bit];
hasil_bagi_asli=new long int[bit];
sisa_akhir=new long int[bit];
simpan=new long int[bit];
hasil_krg=new long int[bit];
cek_hasil_krg=new long int[bit];
p_split=new long int[bit];
hasil_jml=new long int[bit];
b=new long int[bit];
c=new long int[bit];
hasil=new long int[bit];
simpan_sisa=new long int[bit];

hasil_kali=new long int*[bit];
for(int i=1;i<=bit;i++) hasil_kali[i]=new long int[bit];
a=new long int*[bit];
for(int i=1;i<=bit;i++) a[i]=new long int[bit];

//SimpleArray<SimpleIArray> a,hasil_kali;
//SimpleIArray p,q,hasil_bagi_asli,sisa_akhir,simpan,hasil_krg,cek_hasil_krg,b,c,hasil,simpan_sisa,p_split,hasil_jml;

/*a.setSize(mak);
hasil_kali.setSize(mak);
p.setSize(mak);
q.setSize(mak);
hasil_bagi_asli.setSize(mak);
sisa_akhir.setSize(mak);
simpan.setSize(mak);
hasil_krg.setSize(mak);
cek_hasil_krg.setSize(mak);
b.setSize(mak);
c.setSize(mak);
hasil.setSize(mak);
simpan_sisa.setSize(mak);
p_split.setSize(mak);
hasil_jml.setSize(mak); */

//long int ip,iq,loop,i,j,k,l,selisih,*p,*q,*hasil_krg;
//long int hasil_bagi,sisa_hasil_bagi,*simpan,*hasil_bagi,*simpan_next,indek;
////cout<<"nilai p = ";cin.getline(kar_p,100);
////cout<<"nilai q = ";cin.getline(kar_q,100);
//kar_p="131249723985409213521357215712385792759289213765829621309636987692745682371568237968238";
//kar_q="15564364361438957395739507349572345743829";
kar_p="133274327582793585623058147240214239847959185982359863295723573295729517239586165239571238957923523959235895637265823975932175893275912375632562387561235839257982351236518723518235182365273623756257238957923562357858239";
kar_q="2847249271498127021983403423139571923579123562935665876582735628367";
//kar_p="133274327582793585623058147240214239847959185982359863295723573295729517239586165239571238957923523959235895637265823975932175893275912375632562387561235839257982351236518723518235182365273623756257238957923562357858239";
//kar_q="10";
//kar_p="133274327582793585623058147240214239847959185982359863295723573295729517239586165239571238957923523959235895637265823975932175893275912375632562387561235839257982351236518723518235182365273623756257238957923562357858239133274327582793585623058147240214239847959185982359863295723573295729517239586165239571238957923523959235895637265823975932175893275912375632562387561235839257982351236518723518235182365273623756257238957923562357858239";
//kar_q="2";
//kar_p="15055555555555555594385934750984";
//kar_q="154357983425793475";
/*p=new long int[1000];
q=new long int[1000];
hasil_krg=new long int[1000];
simpan=new long int[1000];
hasil_bagi=new long int[1000];
simpan_next=new long int[1000];*/

ip=strlen(kar_p);
iq=strlen(kar_q);
sel_panj=abs(ip-iq);
cout<<"\nselisih panjang = "<<sel_panj<<"\n";
//hasil perkalian
   file_output<<"\npanjang kar_p = "<<ip<<" digit = "<<ip*8<<" bit"<<"\n";
   file_output<<"panjang kar_q = "<<iq<<" digit = "<<iq*8<<" bit"<<"\n\n";
   cout<<"p = "<<kar_p<<"\n";
   cout<<"q = "<<kar_q<<"\n\n";
   file_output<<"p = "<<kar_p<<"\n";
   file_output<<"q = "<<kar_q<<"\n";

cout<<"panjang kar_p = "<<ip<<" digit = "<<ip*8<<" bit"<<"\n";
cout<<"panjang kar_q = "<<iq<<" digit = "<<iq*8<<" bit"<<"\n";
getch ();

//aturan pengali di generate kemudian dikalikan dengan pembagi yaitu q
//kemudian misal, p_baru = p - (pengali*q)
//maka p_baru - q sampai nilai p_baru < q
//kemudian hasilnya = pengali + banyak iterasi p_baru - q sampai nilai p_baru < q
if(ip<iq)
	{
   //cout<<"sisa = ";
   file_output<<"sisa = ";
   for(k=1;k<=ip;k++)
   	{
      cek_hasil_krg[k]=kar_p[k-1]-48;
      //cout<<cek_hasil_krg[k];
      file_output<<cek_hasil_krg[k];
      }
   //cout<<"\n";
   file_output<<"\n";
   }
else if(abs(ip-iq)<=5)
	{
ii=0;jj=0;kk=0;
for(i=1;i<=iq;i++)
   		{
         q[i]=kar_q[i-1]-48;
         p[i]=kar_p[i-1]-48;
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
//cout<<"\nii = "<<ii<<"\n";
//cout<<"\njj = "<<jj<<"\n";
//cout<<"\nkk = "<<kk<<"\n";

//getch ();
if(ip<iq)
	{
   //cout<<"\n\njadi hasil_bagi "<<kar_p<<" / "<<kar_q<<" = "; //untuk bit yang lebih besar ini, akan pakai array
   file_output<<"\n\njadi hasil_bagi "<<kar_p<<" / "<<kar_q<<" = ";
   for(i=1;i>=1;i--)
      	{
         hasil[1]=0;
         //cout<<hasil[1];
         file_output<<hasil[1];
         }
   //cout<<"\n";
   ////cout<<"\ntidak membagi habis\n";
   //file_output<<"\ntidak membagi habis\n";
   //cout<<"sisa = ";
   file_output<<"sisa = ";
   for(k=1;k<=ip;k++)
   	{
      //cout<<p[k];
      file_output<<p[k];
      }
   }

else if(ip==iq && ii==1)
	{
   //cout<<"\n\njadi hasil_bagi "<<kar_p<<" / "<<kar_q<<" = "; //untuk bit yang lebih besar ini, akan pakai array
   file_output<<"\n\njadi hasil_bagi "<<kar_p<<" / "<<kar_q<<" = ";
   for(i=1;i>=1;i--)
      	{
         hasil[1]=0;
         //cout<<hasil[1];
         file_output<<hasil[1];
         }
   //cout<<"\n";
   ////cout<<"\ntidak membagi habis\n";
   //file_output<<"\ntidak membagi habis\n";
   //cout<<"sisa = ";
   file_output<<"sisa = ";
   for(k=1;k<=ip;k++)
   	{
      //cout<<p[k];
      file_output<<p[k];
      }
   }
else if(ip>=iq)
	{
//////////////////////////////////////////////////////////////////////////////////////////////
cek_float=0;
hasil_bagi_sel=0;
cek_loop=1;
byk_digit=1;
do{
////cout<<"\n***************\n";
////cout<<"\nip ="<<ip<<"\n";
////cout<<"\niq ="<<iq<<"\n";
////cout<<"\n***************\n";

if(ip>iq)
	{
   if(cek_loop==1)
		{
   	loop=ip;
   	for(i=1;i<=ip;i++)
   		{
      	p[i]=kar_p[i-1]-48;
      	}
      	////cout<<"\n";
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
    	}
	else if(cek_loop==0)
		{
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
      //break;
   	}
   hasil_krg[loop]=0;
   for(k=loop;k>=1;k--)
   	{
      hasil_krg[k]+=p[k]-q[k];
      ////cout<<hasil_krg[k]<<" ";
      if(hasil_krg[k]<0 && k!=1)
      	{
         hasil_krg[k]=hasil_krg[k]+10;
         ////cout<<hasil_krg[k]<<" ";
         hasil_krg[k-1]=-1;
         }
      else
      	{
         hasil_krg[k]=hasil_krg[k];
         hasil_krg[k-1]=0;
         }
      }
   }
   else if(ip<iq)
	{
   if(cek_loop==1)
		{
   	loop=iq;
   	for(i=1;i<=iq;i++)
   		{
      	q[i]=kar_q[i-1]-48;
      	}
      	//cout<<"\n";
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
      }
   else if(cek_loop==0)
   	{
      for(i=1;i<=iq;i++)
   		{
      	q[i]=kar_q[i-1]-48;
      	}
      //continue;
      }
   hasil_krg[loop]=0;
   for(k=loop;k>=1;k--)
   	{
      hasil_krg[k]+=q[k]-p[k];
      ////cout<<hasil_krg[k]<<" ";
      if(hasil_krg[k]<0 && k!=1)
      	{
         hasil_krg[k]=hasil_krg[k]+10;
         ////cout<<hasil_krg[k]<<" ";
         hasil_krg[k-1]=-1;
         }
      else
      	{
         hasil_krg[k]=hasil_krg[k];
         hasil_krg[k-1]=0;
         if(k==1 && hasil_krg[k]!=0)
         	{
            hasil_krg[k]=-1*hasil_krg[k];
            }
         else if(k==1 && hasil_krg[k]==0)
         	{
            hasil_krg[k+1]=-1*hasil_krg[k+1];
            }
         }
      }
   }
   else if(ip==iq)
	{
   ////cout<<"iq ="<<iq<<"\n";
   int ii=0,jj=0,kk=0;
   if(cek_loop==1)
		{
      for(i=1;i<=iq;i++)
   		{
      	p[i]=kar_p[i-1]-48;
      	////cout<<"p["<<i<<"]="<<p[i]<<"\n";
      	q[i]=kar_q[i-1]-48;
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
     else if(cek_loop==0)
     {
     for(i=1;i<=iq;i++)
   		{
         q[i]=kar_q[i-1]-48;
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
    //seharusnya tidak usah dihitung lagi karena pasti tidak membagi habis
    cek_float=1;
    ////cout<<"\n cek_float ="<<cek_float<<"\n";
    break;
      if(cek_loop==1)
			{
	   	loop=iq;
	   	for(i=1;i<=iq;i++)
	   		{
	      	p[i]=kar_p[i-1]-48;
	      	q[i]=kar_q[i-1]-48;
	      	}
	      	//cout<<"\n";
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
         }
      else if(cek_loop==0)
      	{
         for(i=1;i<=iq;i++)
   			{
         	q[i]=kar_q[i-1]-48;
         	}
         }
	   hasil_krg[loop]=0;
	   for(k=loop;k>=1;k--)
	   	{
	      hasil_krg[k]+=q[k]-p[k];
	      ////cout<<hasil_krg[k]<<" ";
	      if(hasil_krg[k]<0 && k!=1)
	      	{
	         hasil_krg[k]=hasil_krg[k]+10;
	         ////cout<<hasil_krg[k]<<" ";
	         hasil_krg[k-1]=-1;
	         }
	      else
	      	{
	         hasil_krg[k]=hasil_krg[k];
	         hasil_krg[k-1]=0;
	         if(k==1 && hasil_krg[k]!=0)
	         	{
	            hasil_krg[k]=-1*hasil_krg[k];
	            }
	         else if(k==1 && hasil_krg[k]==0)
	         	{
	            hasil_krg[k+1]=-1*hasil_krg[k+1];
	            }
	         }
	      }
      }
      else if(jj==1)
      	{
         ////cout<<"\n jj ="<<jj<<"\n";
      	if(cek_loop==1)
				{
      		loop=ip;
	   		for(i=1;i<=ip;i++)
	   			{
	      		p[i]=kar_p[i-1]-48;
	      		}
	      		////cout<<"\n";
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
         	}
         else if(cek_loop==0)
         	{
            for(i=1;i<=iq;i++)
   				{
         		q[i]=kar_q[i-1]-48;
         		}
            }
	   hasil_krg[loop]=0;
	   for(k=loop;k>=1;k--)
	   	{
	      hasil_krg[k]+=p[k]-q[k];
	      ////cout<<hasil_krg[k]<<" ";
	      if(hasil_krg[k]<0 && k!=1)
	      	{
	         hasil_krg[k]=hasil_krg[k]+10;
	         ////cout<<hasil_krg[k]<<" ";
	         hasil_krg[k-1]=-1;
	         }
	      else
	      	{
	         hasil_krg[k]=hasil_krg[k];
	         hasil_krg[k-1]=0;
	         }
	      }
         }
      else if(kk==iq)
      	{
      ////cout<<"\n kk ="<<kk<<"\n";
         loop=1;
         hasil_krg[1]=0;
         }
   }
   //tampilan hasil pengurangan
   ////cout<<"\nhasil pengurangan dalam array = ";
   kk=1;
	for(k=1;k<=loop;k++)
   	{
      if(loop!=1 && k==1 && hasil_krg[k]==0)
      	{
         continue;
         }
      else
      	{
         cek_hasil_krg[kk]=hasil_krg[k];
         kk++;
         ////cout<<"\nkk ="<<kk<<"\n";
         ////cout<<hasil_krg[k];
         }
      }

   ////cout<<"\npengecekan hasil pengurangan ";
	for(k=1;k<=(kk-1);k++)
   	{
      ////cout<<cek_hasil_krg[k];
      }
   //getch ();
   if((kk-1)>iq)
   	{
      cek_loop=0;
      }
   else if((kk-1)<iq)
   	{
      cek_loop=1;
      cek_float=1;
      }
   else if((kk-1)==iq)
   	{
      if((kk-1)==1)
      	{
         ////cout<<"\nkond_1\n";
         q[1]=kar_q[0]-48;
         ////cout<<"\nq[1] ="<<q[1]<<"\n";
      	////cout<<cek_hasil_krg[k];
         if(cek_hasil_krg[1]==0)
         	{
            cek_loop=1;
            }
         else if(cek_hasil_krg[1]<q[1])
         	{
            ////cout<<"\nkond_1.2\n";
            cek_loop=1;//hasil berupa float
            cek_float=1;
            }
            /*else if(cek_hasil_krg[1]<kar_q[1])
            	{
               cek_loop=1;//hasil berupa float
               cek_float=1;
               p[1]=cek_hasil_krg[1];
               p[2]=0;
               loop=2;
               hasil_bagi_float++;
               }*/
         else if(cek_hasil_krg[1]>q[1] || cek_hasil_krg[1]==q[1])
         	{
            cek_loop=0;
            }
          }
      else if((kk-1)>1)
      	{
         ii=0,jj=0,ll=0;
         for(i=1;i<=(kk-1);i++)
         	{
         	if (cek_hasil_krg[i]<q[i])
            	{
               ii=1;
               break;
               }
            else if(cek_hasil_krg[i]>q[i])
            	{
               jj=1;
               break;
               }
            else if (cek_hasil_krg[i]==q[i])
            	{
               ll++;
               }
            }
         if(ii==1)
           	{
            cek_loop=1;//berhenti, hasil float
            }
         else if(jj==1)
         	{
            cek_loop=0;//loop kembali
            }
         else if(ll==(kk-1))
         	{
            cek_loop=1;
            hasil_bagi_sel++;
            kk=2;
            cek_hasil_krg[1]=0;
            }
         }
      } 
    ////cout<<"\ncek loop ="<<cek_loop<<"\n";
    if(cek_loop==0)
    	{
      hasil_bagi_sel++;
      ////cout<<"\ntukar  cek hasil ke kar_p\n";
      for(k=1;k<=(kk-1);k++)
   		{
      	p[k]=cek_hasil_krg[k];
         ////cout<<"\p["<<k<<"]="<<p[k]<<"\n";
      	}
      for(k=1;k<=iq;k++)
   		{
         ////cout<<"\q["<<k<<"]="<<q[k]<<"\n";
      	}
      //getch ();
      ip=(kk-1);
      loop=ip;
      ////cout<<"\n_ip ="<<ip<<"\n";
		////cout<<"\n_iq ="<<iq<<"\n";
      ////cout<<"\n_loop ="<<loop<<"\n";
      }
    else if(cek_loop==1)
    	{
      hasil_bagi_sel++;
      }

   // perhitungan hasil bagi array

    hasil[1]=hasil_bagi_sel;
    //if(hasil[1]%10!=0 )
    	//{
      ////cout<<"\nhasil[1]="<<hasil[1]<<"\n";
      //getch ();
     // }
    //else if(hasil[1]%10==0)
    	//{
      ////cout<<"\nkond. 2\n";
      //hasil[1]=0;
      //hasil[2]=1;
      //buat nambah array
      ////cout<<"\nbanyak digit = "<<byk_digit<<"\n";
      ////cout<<"\nhasil_bagi_sel = "<<hasil_bagi_sel<<"\n";

      //getch ();
      /*else
      	{
         continue;
         }*/
      /*if(hasil[byk_digit]==10)
      		{
         		//cout<<"\ntambah array\n";
         		byk_digit+=2;
         		//cout<<"\nbanyak digit = "<<byk_digit<<"\n";
         		//hasil[byk_digit]=1;
         	}*/

      for(i=1;i<=byk_digit;i++)
      	{
         if(i==1)
         	{
            ////cout<<"\nkond1. hasil["<<i<<"] = "<<hasil[i]<<"\n";
         	if(hasil[1]==10)
            	{
               if(i==byk_digit)
               	{
                  byk_digit++;
                  }
               hasil_bagi_sel=0;
               hasil[1]=0;
               //hasil[1+1]=1;
               simpan_sisa[1]=1;
               }
         	 else if(hasil[1]<10)
             	{
               hasil[1]=hasil_bagi_sel;
               //hasil[i+1]=0;
               simpan_sisa[1]=0;
               }
            }
         /*else if(i==2)
         	{
            hasil[2]=hasil[2]+simpan_sisa[1];
            ////cout<<"\nkon2. hasil["<<i<<"] = "<<hasil[i]<<"\n";
         	if(hasil[2]==10)
         		{
               if(i==byk_digit)
               	{
                  byk_digit++;
                  }
            	hasil[2]=0;
               //hasil[i+1]=1;
            	simpan_sisa[2]=1;
            	}
         	else if(hasil[2]<10)
         		{
            	hasil[2]=hasil[2];
               //hasil[i+1]=0;
               simpan_sisa[2]=0;
            	}
            }*/
         else if(i>1)
         	{
            hasil[i]=hasil[i]+simpan_sisa[i-1];
            //hasil[i]++;
           // //cout<<"\nkon3. hasil["<<i<<"] = "<<hasil[i]<<"\n";
            if(hasil[i]==10)
         		{
               if(i==byk_digit)
               	{
                  byk_digit++;
                  }
            	hasil[i]=0;
               //hasil[i+1]=0;
            	simpan_sisa[i]=1;
            	}
         	else if(hasil[i]<10)
         		{
               hasil[i]=hasil[i];
               //hasil[i+1]=0;
            	simpan_sisa[i]=0;
            	}
            }
         }

      /*for(i=1;i<=byk_digit;i++)
      	{
         if(i==1)
         	{
            ////cout<<"\nkond1. hasil["<<i<<"] = "<<hasil[i]<<"\n";
         	if(hasil[1]==10)
            	{
               //hasil_bagi_sel=0;
               hasil[1]=0;
               //hasil[1+1]=1;
               simpan_sisa[1]=1;
               }
         	 else if(hasil[1]<10)
             	{
               hasil[1]=hasil_bagi_sel;
               //hasil[i+1]=0;
               simpan_sisa[1]=0;
               }
            }
         /*else if(i==2)
         	{
            hasil[2]=hasil[2]+simpan_sisa[1];
            ////cout<<"\nkon2. hasil["<<i<<"] = "<<hasil[i]<<"\n";
         	if(hasil[2]==10)
         		{
            	hasil[2]=0;
               //hasil[i+1]=1;
            	simpan_sisa[2]=1;
            	}
         	else if(hasil[2]<10)
         		{
            	hasil[2]=hasil[2];
               //hasil[i+1]=0;
               simpan_sisa[2]=0;
            	}
            }*/
         /*else if(i>1)
         	{
            hasil[i]=hasil[i]+simpan_sisa[i-1];
            //hasil[i]++;
            ////cout<<"\nkon3. hasil["<<i<<"] = "<<hasil[i]<<"\n";
            if(hasil[i]==10)
         		{
            	hasil[i]=0;
               //hasil[i+1]=0;
            	simpan_sisa[i]=1;
            	}
         	else if(hasil[i]<10)
         		{
               hasil[i]=hasil[i];
               //hasil[i+1]=0;
            	simpan_sisa[i]=0;
            	}
            }
        }*/
       ////cout<<"\n\n";
      // tampilan hasil

      ////cout<<"\nhasil[1]="<<hasil[1]<<"\n";
      ////cout<<"\nhasil[2]="<<hasil[2]<<"\n";

      //getch ();
      //}
    for(i=1;i<=byk_digit;i++)
      	{
         ////cout<<"\nhasil["<<i<<"] = "<<hasil[i]<<"\n";
         }
    //getch ();
    //update hasil bagi dalam array
   /*loop_array=2;
   hasil[loop_array]=0;
   if(hasil_bagi_sel==10)
   	{
       hasil[loop_array]+=1;
       if(hasil[loop_array]==10)
       loop_array++;
      }
    //cout<<"\nhasil bagi ="<<hasil_bagi<<"\n";
    //cout<<"\ncek_float ="<<cek_float<<"\n";*/


   //getch ();
}while(cek_loop==0);

if(cek_float==0)
	{
   cout<<"sisa = ";
   file_output<<"sisa = ";
   for(k=1;k<=(kk-1);k++)
   	{
      cout<<cek_hasil_krg[k];
      file_output<<cek_hasil_krg[k];
      }
   }
else if(cek_float==1)
	{
   cout<<"sisa = ";
   file_output<<"sisa = ";
   for(k=1;k<=(kk-1);k++)
   	{
      cout<<cek_hasil_krg[k];
      file_output<<cek_hasil_krg[k];
      }
   }
/*//cout<<"\n\nbanyak digit = "<<byk_digit<<"\n";
for(i=1;i<=byk_digit;i++)
      	{
         //cout<<"\nhasil["<<i<<"] = "<<hasil[i]<<"\n";
         }*/
	}
}
//********************************************************************************************************************************//
else if(abs(ip-iq)>5)
	{
//cout<<"\nkond 21\n";
//getch ();
if(iq==1 && (kar_q[0]-48)==1)
	{
   cout<<"sisa = ";
   file_output<<"sisa = ";
   for(k=1;k<=1;k++)
   	{
      cek_hasil_krg[1]=0;
      cout<<cek_hasil_krg[1];
      file_output<<cek_hasil_krg[1];
      }
   }
else if(iq==1 && (kar_q[0]-48)==0)
	{
   cout<<"sisa = ";
   file_output<<"sisa = ";
   for(k=1;k<=1;k++)
   	{
      cek_hasil_krg[1]=0;
      cout<<cek_hasil_krg[1];
      file_output<<cek_hasil_krg[1];
      }
   }
else
	{
for(i=1;i<=ip;i++)
	{
   p[i]=kar_p[i-1]-48;
   }
for(i=1;i<=iq;i++)
	{
   q[i]=kar_q[i-1]-48;
   //cout<<q[i];
   }
//cout<<"\n";
// split nilai p[i]
for(i=1;i<=(strlen(kar_q)+1);i++)
	{
   p_split[i]=p[i];
   //cout<<p_split[i];
   }
//cout<<"\n\n";
getch ();
loop_split=strlen(kar_q)+1;
loop_kk=strlen(kar_q)+1;
loop_bagi=1;
do{
//cout<<"\natas lagi \n";
	//*************************************************************************************************//
for(i=1;i<=loop_kk;i++)
	{
   p[i]=p_split[i];
   //cout<<p[i];
   }
// inisiasi
ip=loop_kk;
iq=strlen(kar_q);
//cout<<"\nloop_kk : "<<loop_kk<<"\n";
//cout<<"\n\n";
//getch ();

//kondisi dibawah ini hanya untuk ip=iq
ii=0;jj=0;kk=0;
for(i=1;i<=iq;i++)
   		{
         q[i]=kar_q[i-1]-48;
         //p[i]=kar_p[i-1]-48;
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
//cout<<"\nii = "<<ii<<"\n";
//cout<<"\njj = "<<jj<<"\n";
//cout<<"\nkk = "<<kk<<"\n";

//cout<<"\n\n ip ="<<ip<<"\n";
//cout<<"\n iq ="<<iq<<"\n\n";


if(ip<iq)
	{
   //cout<<"\nkond ip<iq \n";
   //cout<<"\n\njadi hasil_bagi ";
   	for(i=1;i<=loop_kk;i++)
			{
   		//cout<<p_split[i];
   		}//cout<<" / "<<kar_q<<" = ";
   file_output<<"\n\njadi hasil_bagi ";
   	for(i=1;i<=loop_kk;i++)
			{
   		file_output<<p_split[i];
   		}file_output<<" / "<<kar_q<<" = ";
   for(i=1;i>=1;i--)
      	{
         hasil[1]=0;
         hasil_bagi_asli[loop_bagi]=hasil[1];
         //cout<<hasil_bagi_asli[loop_bagi];
         file_output<<hasil_bagi_asli[loop_bagi];
         loop_bagi++;
         byk_digit=1;
         }
   //cout<<"\n";
   file_output<<"\n";
   ////cout<<"\ntidak membagi habis\n";
   //file_output<<"\ntidak membagi habis\n";
   //cout<<"sisa = ";
   file_output<<"sisa = ";
   for(k=1;k<=ip;k++)
   	{
      loop_sisa=ip;
      sisa_akhir[k]=p[k];
      //cout<<p[k];
      file_output<<p[k];
      }
   }
else if(ip==2 && iq==1 && p[1]==0 && p[2]<q[1])
	{
   //cout<<"\nkond ip==2 && p[1]==0 \n";
   //cout<<"\n\njadi hasil_bagi ";
   	for(i=1;i<=loop_kk;i++)
			{
   		//cout<<p_split[i];
   		}//cout<<" / "<<kar_q<<" = "; //untuk bit yang lebih besar ini, akan pakai array
   file_output<<"\n\njadi hasil_bagi ";
   	for(i=1;i<=loop_kk;i++)
			{
   		file_output<<p_split[i];
   		}file_output<<" / "<<kar_q<<" = ";
   for(i=1;i>=1;i--)
      	{
         hasil[1]=0;
         hasil_bagi_asli[loop_bagi]=hasil[1];
         //cout<<hasil_bagi_asli[loop_bagi];
         file_output<<hasil_bagi_asli[loop_bagi];
         loop_bagi++;
         byk_digit=1;
         }
   //cout<<"\n";
   file_output<<"\n";
   ////cout<<"\ntidak membagi habis\n";
   //file_output<<"\ntidak membagi habis\n";
   //cout<<"sisa = ";
   file_output<<"sisa = ";
   for(k=1;k<=ip;k++)
   	{
      loop_sisa=ip;
      sisa_akhir[k]=p[k];
      //cout<<p[k];
      file_output<<p[k];
      }
   getch ();
   }
else if(ip==iq && ii==1)
	{
   //cout<<"\n\njadi hasil_bagi ";
   	for(i=1;i<=loop_kk;i++)
			{
   		//cout<<p_split[i];
   		}//cout<<" / "<<kar_q<<" = "; //untuk bit yang lebih besar ini, akan pakai array
   file_output<<"\n\njadi hasil_bagi ";
   	for(i=1;i<=loop_kk;i++)
			{
   		file_output<<p_split[i];
   		}file_output<<" / "<<kar_q<<" = ";
   for(i=1;i>=1;i--)
      	{
         hasil[1]=0;
         hasil_bagi_asli[loop_bagi]=hasil[1];
         //cout<<hasil_bagi_asli[loop_bagi];
         file_output<<hasil_bagi_asli[loop_bagi];
         loop_bagi++;
         byk_digit=1;
         }
   //cout<<"\n";
   file_output<<"\n";
   ////cout<<"\ntidak membagi habis\n";
   //file_output<<"\ntidak membagi habis\n";
   //cout<<"sisa = ";
   file_output<<"sisa = ";
   for(k=1;k<=ip;k++)
   	{
      loop_sisa=ip;
      sisa_akhir[k]=p[k];
      //cout<<p[k];
      file_output<<p[k];
      }
   }

else if(ip>=iq)
	{
//cout<<"\nkond ip>=iq \n";
//////////////////////////////////////////////////////////////////////////////////////////////
cek_float=0;
hasil_bagi_sel=0;
cek_loop=1;
byk_digit=1;
do{
////cout<<"\n***************\n";
////cout<<"\nip ="<<ip<<"\n";
////cout<<"\niq ="<<iq<<"\n";
////cout<<"\n***************\n";

if(ip>iq)
	{
   if(cek_loop==1)
		{
   	loop=ip;
   	for(i=1;i<=ip;i++)
   		{
      	p[i]=p_split[i];
      	}
      	////cout<<"\n";
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
    	}
	else if(cek_loop==0)
		{
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
      //break;
   	}
   hasil_krg[loop]=0;
   for(k=loop;k>=1;k--)
   	{
      hasil_krg[k]+=p[k]-q[k];
      ////cout<<hasil_krg[k]<<" ";
      if(hasil_krg[k]<0 && k!=1)
      	{
         hasil_krg[k]=hasil_krg[k]+10;
         ////cout<<hasil_krg[k]<<" ";
         hasil_krg[k-1]=-1;
         }
      else
      	{
         hasil_krg[k]=hasil_krg[k];
         hasil_krg[k-1]=0;
         }
      }
   }
   else if(ip<iq)
	{
   if(cek_loop==1)
		{
   	loop=iq;
   	for(i=1;i<=iq;i++)
   		{
      	q[i]=kar_q[i-1]-48;
      	}
      	//cout<<"\n";
   	selisih=abs(ip-iq);
   	for(j=iq;j>=1;j--)
   		{
      	if(j<=selisih)
      		{
         	p[j]=0;
         	}
      	else if(j>selisih)
      		{
         	//indek=selisih+1;//agar indek = 0,1,..
      		p[j]=p_split[j-selisih];
      		}
         }
      }
   else if(cek_loop==0)
   	{
      for(i=1;i<=iq;i++)
   		{
      	q[i]=kar_q[i-1]-48;
      	}
      //continue;
      }
   hasil_krg[loop]=0;
   for(k=loop;k>=1;k--)
   	{
      hasil_krg[k]+=q[k]-p[k];
      ////cout<<hasil_krg[k]<<" ";
      if(hasil_krg[k]<0 && k!=1)
      	{
         hasil_krg[k]=hasil_krg[k]+10;
         ////cout<<hasil_krg[k]<<" ";
         hasil_krg[k-1]=-1;
         }
      else
      	{
         hasil_krg[k]=hasil_krg[k];
         hasil_krg[k-1]=0;
         if(k==1 && hasil_krg[k]!=0)
         	{
            hasil_krg[k]=-1*hasil_krg[k];
            }
         else if(k==1 && hasil_krg[k]==0)
         	{
            hasil_krg[k+1]=-1*hasil_krg[k+1];
            }
         }
      }
   }
   else if(ip==iq)
	{
   ////cout<<"iq ="<<iq<<"\n";
   int ii=0,jj=0,kk=0;
   if(cek_loop==1)
		{
      for(i=1;i<=iq;i++)
   		{
      	//p[i]=kar_p[i-1]-48;
      	////cout<<"p["<<i<<"]="<<p[i]<<"\n";
      	q[i]=kar_q[i-1]-48;
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
     else if(cek_loop==0)
     {
     for(i=1;i<=iq;i++)
   		{
         q[i]=kar_q[i-1]-48;
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
    //seharusnya tidak usah dihitung lagi karena pasti tidak membagi habis
    cek_float=1;
    ////cout<<"\n cek_float ="<<cek_float<<"\n";
   // break;
      if(cek_loop==1)
			{
	   	loop=iq;
	   	for(i=1;i<=iq;i++)
	   		{
	      	//p[i]=kar_p[i-1]-48;
	      	q[i]=kar_q[i-1]-48;
	      	}
	      	//cout<<"\n";
	   	selisih=abs(ip-iq);
	   	for(j=iq;j>=1;j--)
	   		{
	      	if(j<=selisih)
	      		{
	         	p[j]=0;
	         	}
	     	 	else if(j>selisih)
	      		{
	      		p[j]=p_split[j-selisih];
	      		}
	      	}
         }
      else if(cek_loop==0)
      	{
         for(i=1;i<=iq;i++)
   			{
         	q[i]=kar_q[i-1]-48;
         	}
         }
	   hasil_krg[loop]=0;
	   for(k=loop;k>=1;k--)
	   	{
	      hasil_krg[k]+=q[k]-p[k];
	      ////cout<<hasil_krg[k]<<" ";
	      if(hasil_krg[k]<0 && k!=1)
	      	{
	         hasil_krg[k]=hasil_krg[k]+10;
	         ////cout<<hasil_krg[k]<<" ";
	         hasil_krg[k-1]=-1;
	         }
	      else
	      	{
	         hasil_krg[k]=hasil_krg[k];
	         hasil_krg[k-1]=0;
	         if(k==1 && hasil_krg[k]!=0)
	         	{
	            hasil_krg[k]=-1*hasil_krg[k];
	            }
	         else if(k==1 && hasil_krg[k]==0)
	         	{
	            hasil_krg[k+1]=-1*hasil_krg[k+1];
	            }
	         }
	      }
      }
      else if(jj==1)
      	{
         ////cout<<"\n jj ="<<jj<<"\n";
      	if(cek_loop==1)
				{
      		loop=ip;
	   		for(i=1;i<=ip;i++)
	   			{
	      		p[i]=p_split[i];
	      		}
	      		////cout<<"\n";
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
         	}
         else if(cek_loop==0)
         	{
            for(i=1;i<=iq;i++)
   				{
         		q[i]=kar_q[i-1]-48;
         		}
            }
	   hasil_krg[loop]=0;
	   for(k=loop;k>=1;k--)
	   	{
	      hasil_krg[k]+=p[k]-q[k];
	      ////cout<<hasil_krg[k]<<" ";
	      if(hasil_krg[k]<0 && k!=1)
	      	{
	         hasil_krg[k]=hasil_krg[k]+10;
	         ////cout<<hasil_krg[k]<<" ";
	         hasil_krg[k-1]=-1;
	         }
	      else
	      	{
	         hasil_krg[k]=hasil_krg[k];
	         hasil_krg[k-1]=0;
	         }
	      }
         }
      else if(kk==iq)
      	{
      ////cout<<"\n kk ="<<kk<<"\n";
         loop=1;
         hasil_krg[1]=0;
         }
   }
   //tampilan hasil pengurangan
   ////cout<<"\nhasil pengurangan dalam array = ";
   kk=1;
	for(k=1;k<=loop;k++)
   	{
      if(loop!=1 && k==1 && hasil_krg[k]==0)
      	{
         continue;
         }
      else
      	{
         cek_hasil_krg[kk]=hasil_krg[k];
         kk++;
         ////cout<<"\nkk ="<<kk<<"\n";
         ////cout<<hasil_krg[k];
         }
      }

   ////cout<<"\npengecekan hasil pengurangan ";
	for(k=1;k<=(kk-1);k++)
   	{
      ////cout<<cek_hasil_krg[k];
      }
   //getch ();
   if((kk-1)>iq)
   	{
      cek_loop=0;
      }
   else if((kk-1)<iq)
   	{
      cek_loop=1;
      cek_float=1;
      }
   else if((kk-1)==iq)
   	{
      if((kk-1)==1)
      	{
         ////cout<<"\nkond_1\n";
         q[1]=kar_q[0]-48;
         ////cout<<"\nq[1] ="<<q[1]<<"\n";
      	////cout<<cek_hasil_krg[k];
         if(cek_hasil_krg[1]==0)
         	{
            cek_loop=1;
            }
         else if(cek_hasil_krg[1]<q[1])
         	{
            ////cout<<"\nkond_1.2\n";
            cek_loop=1;//hasil berupa float
            cek_float=1;
            }
            /*else if(cek_hasil_krg[1]<kar_q[1])
            	{
               cek_loop=1;//hasil berupa float
               cek_float=1;
               p[1]=cek_hasil_krg[1];
               p[2]=0;
               loop=2;
               hasil_bagi_float++;
               }*/
         else if(cek_hasil_krg[1]>q[1] || cek_hasil_krg[1]==q[1])
         	{
            cek_loop=0;
            }
          }
      else if((kk-1)>1)
      	{
         ii=0,jj=0,ll=0;
         for(i=1;i<=(kk-1);i++)
         	{
         	if (cek_hasil_krg[i]<q[i])
            	{
               ii=1;
               break;
               }
            else if(cek_hasil_krg[i]>q[i])
            	{
               jj=1;
               break;
               }
            else if (cek_hasil_krg[i]==q[i])
            	{
               ll++;
               }
            }
         if(ii==1)
           	{
            cek_loop=1;//berhenti, hasil float
            }
         else if(jj==1)
         	{
            cek_loop=0;//loop kembali
            }
         else if(ll==(kk-1))
         	{
            cek_loop=1;
            hasil_bagi_sel++;
            kk=2;
            cek_hasil_krg[1]=0;
            }
         }
      } 
    ////cout<<"\ncek loop ="<<cek_loop<<"\n";
    if(cek_loop==0)
    	{
      hasil_bagi_sel++;
      ////cout<<"\ntukar  cek hasil ke kar_p\n";
      for(k=1;k<=(kk-1);k++)
   		{
      	p[k]=cek_hasil_krg[k];
         ////cout<<"\p["<<k<<"]="<<p[k]<<"\n";
      	}
      for(k=1;k<=iq;k++)
   		{
         ////cout<<"\q["<<k<<"]="<<q[k]<<"\n";
      	}
      //getch ();
      ip=(kk-1);
      loop=ip;
      ////cout<<"\n_ip ="<<ip<<"\n";
		////cout<<"\n_iq ="<<iq<<"\n";
      ////cout<<"\n_loop ="<<loop<<"\n";
      }
    else if(cek_loop==1)
    	{
      hasil_bagi_sel++;
      }

   // perhitungan hasil bagi array

    hasil[1]=hasil_bagi_sel;
    //if(hasil[1]%10!=0 )
    	//{
      ////cout<<"\nhasil[1]="<<hasil[1]<<"\n";
      //getch ();
     // }
    //else if(hasil[1]%10==0)
    	//{
      ////cout<<"\nkond. 2\n";
      //hasil[1]=0;
      //hasil[2]=1;
      //buat nambah array
      ////cout<<"\nbanyak digit = "<<byk_digit<<"\n";
      ////cout<<"\nhasil_bagi_sel = "<<hasil_bagi_sel<<"\n";

      //getch ();
      /*else
      	{
         continue;
         }*/
      /*if(hasil[byk_digit]==10)
      		{
         		//cout<<"\ntambah array\n";
         		byk_digit+=2;
         		//cout<<"\nbanyak digit = "<<byk_digit<<"\n";
         		//hasil[byk_digit]=1;
         	}*/

      for(i=1;i<=byk_digit;i++)
      	{
         if(i==1)
         	{
            ////cout<<"\nkond1. hasil["<<i<<"] = "<<hasil[i]<<"\n";
         	if(hasil[1]==10)
            	{
               if(i==byk_digit)
               	{
                  byk_digit++;
                  }
               hasil_bagi_sel=0;
               hasil[1]=0;
               //hasil[1+1]=1;
               simpan_sisa[1]=1;
               }
         	 else if(hasil[1]<10)
             	{
               hasil[1]=hasil_bagi_sel;
               //hasil[i+1]=0;
               simpan_sisa[1]=0;
               }
            }
         /*else if(i==2)
         	{
            hasil[2]=hasil[2]+simpan_sisa[1];
            ////cout<<"\nkon2. hasil["<<i<<"] = "<<hasil[i]<<"\n";
         	if(hasil[2]==10)
         		{
               if(i==byk_digit)
               	{
                  byk_digit++;
                  }
            	hasil[2]=0;
               //hasil[i+1]=1;
            	simpan_sisa[2]=1;
            	}
         	else if(hasil[2]<10)
         		{
            	hasil[2]=hasil[2];
               //hasil[i+1]=0;
               simpan_sisa[2]=0;
            	}
            }*/
         else if(i>1)
         	{
            hasil[i]=hasil[i]+simpan_sisa[i-1];
            //hasil[i]++;
           // //cout<<"\nkon3. hasil["<<i<<"] = "<<hasil[i]<<"\n";
            if(hasil[i]==10)
         		{
               if(i==byk_digit)
               	{
                  byk_digit++;
                  }
            	hasil[i]=0;
               //hasil[i+1]=0;
            	simpan_sisa[i]=1;
            	}
         	else if(hasil[i]<10)
         		{
               hasil[i]=hasil[i];
               //hasil[i+1]=0;
            	simpan_sisa[i]=0;
            	}
            }
         }

      /*for(i=1;i<=byk_digit;i++)
      	{
         if(i==1)
         	{
            ////cout<<"\nkond1. hasil["<<i<<"] = "<<hasil[i]<<"\n";
         	if(hasil[1]==10)
            	{
               //hasil_bagi_sel=0;
               hasil[1]=0;
               //hasil[1+1]=1;
               simpan_sisa[1]=1;
               }
         	 else if(hasil[1]<10)
             	{
               hasil[1]=hasil_bagi_sel;
               //hasil[i+1]=0;
               simpan_sisa[1]=0;
               }
            }
         /*else if(i==2)
         	{
            hasil[2]=hasil[2]+simpan_sisa[1];
            ////cout<<"\nkon2. hasil["<<i<<"] = "<<hasil[i]<<"\n";
         	if(hasil[2]==10)
         		{
            	hasil[2]=0;
               //hasil[i+1]=1;
            	simpan_sisa[2]=1;
            	}
         	else if(hasil[2]<10)
         		{
            	hasil[2]=hasil[2];
               //hasil[i+1]=0;
               simpan_sisa[2]=0;
            	}
            }*/
         /*else if(i>1)
         	{
            hasil[i]=hasil[i]+simpan_sisa[i-1];
            //hasil[i]++;
            ////cout<<"\nkon3. hasil["<<i<<"] = "<<hasil[i]<<"\n";
            if(hasil[i]==10)
         		{
            	hasil[i]=0;
               //hasil[i+1]=0;
            	simpan_sisa[i]=1;
            	}
         	else if(hasil[i]<10)
         		{
               hasil[i]=hasil[i];
               //hasil[i+1]=0;
            	simpan_sisa[i]=0;
            	}
            }
        }*/
       ////cout<<"\n\n";
      // tampilan hasil

      ////cout<<"\nhasil[1]="<<hasil[1]<<"\n";
      ////cout<<"\nhasil[2]="<<hasil[2]<<"\n";

      //getch ();
      //}
    for(i=1;i<=byk_digit;i++)
      	{
         ////cout<<"\nhasil["<<i<<"] = "<<hasil[i]<<"\n";
         }
    //getch ();
    //update hasil bagi dalam array
   /*loop_array=2;
   hasil[loop_array]=0;
   if(hasil_bagi_sel==10)
   	{
       hasil[loop_array]+=1;
       if(hasil[loop_array]==10)
       loop_array++;
      }
    //cout<<"\nhasil bagi ="<<hasil_bagi<<"\n";
    //cout<<"\ncek_float ="<<cek_float<<"\n";*/


   //getch ();
}while(cek_loop==0);

if(cek_float==0)
	{
	//cout<<"\n\njadi hasil_bagi ";
   	for(i=1;i<=loop_kk;i++)
			{
   		//cout<<p_split[i];
   		}//cout<<" / "<<kar_q<<" = "; //untuk bit yang lebih besar ini, akan pakai array
   file_output<<"\n\njadi hasil_bagi ";
   	for(i=1;i<=loop_kk;i++)
			{
   		file_output<<p_split[i];
   		}file_output<<" / "<<kar_q<<" = ";
	for(i=byk_digit;i>=1;i--)
      	{
         hasil_bagi_asli[loop_bagi]=hasil[i];
         //cout<<hasil_bagi_asli[loop_bagi];
         file_output<<hasil[i];
         loop_bagi++;
         }
   //cout<<"\nmembagi habis\n";
   file_output<<"\nmembagi habis\n";
   //cout<<"sisa = ";
   file_output<<"sisa = ";
   for(k=1;k<=(kk-1);k++)
   	{
      loop_sisa=kk-1;
      sisa_akhir[k]=cek_hasil_krg[k];
      //cout<<cek_hasil_krg[k];
      file_output<<cek_hasil_krg[k];
      }
   }
else if(cek_float==1)
	{
   //cout<<"\n\njadi hasil_bagi ";
   	for(i=1;i<=loop_kk;i++)
			{
   		//cout<<p_split[i];
   		}//cout<<" / "<<kar_q<<" = "; //untuk bit yang lebih besar ini, akan pakai array
   file_output<<"\n\njadi hasil_bagi ";
   	for(i=1;i<=loop_kk;i++)
			{
   		file_output<<p_split[i];
   		}file_output<<" / "<<kar_q<<" = ";
   for(i=byk_digit;i>=1;i--)
      	{
         hasil_bagi_asli[loop_bagi]=hasil[i];
         //cout<<hasil_bagi_asli[loop_bagi];
         file_output<<hasil[i];
         loop_bagi++;
         }
   //cout<<"\ntidak membagi habis\n";
   file_output<<"\ntidak membagi habis\n";
   //cout<<"sisa = ";
   file_output<<"sisa = ";
   for(k=1;k<=(kk-1);k++)
   	{
      loop_sisa=kk-1;
      sisa_akhir[k]=cek_hasil_krg[k];
      //cout<<cek_hasil_krg[k];
      file_output<<cek_hasil_krg[k];
      }
   }
/*//cout<<"\n\nbanyak digit = "<<byk_digit<<"\n";
for(i=1;i<=byk_digit;i++)
      	{
         //cout<<"\nhasil["<<i<<"] = "<<hasil[i]<<"\n";
         }*/
	}

//getch ();



   //***************************************************************************************************************************//
// perkalian hasil bagi p_split dengan q[i]
//cout<<"\nhasil p_split : \n";
 for(i=1;i<=loop_kk;i++)
	{
   //cout<<p_split[i];
   }
 //cout<<"\n\n";
ip=iq;
iq=byk_digit;
//cout<<"\n******pada perkalian*********\n";
//cout<<"\nip ="<<ip<<"\n";
//cout<<"\niq ="<<iq<<"\n";
//cout<<"\n***************\n";
for(i=1;i<=ip;i++)
	{
   p[i]=kar_q[i-1]-48;
   //cout<<p[i];
   }
//cout<<"\n";
ii=1;
for(i=iq;i>=1;i--)
	{
   q[ii]=hasil[i];
   //cout<<q[ii];
   ii++;
   }

/*if(hasil[iq]>=10)
	{
   //cout<<"\nkond > 10 \n";
   hasil_bagi=hasil[iq]/10;
   sisa_hasil_bagi=(hasil[iq])-10*hasil_bagi;
   iq=2; //maksimal 2 array dengan digit selisih = 1
   hasil[1]=hasil_bagi;
   hasil[2]=sisa_hasil_bagi;
   }
else if(hasil[iq]<10)
	{
   hasil[iq]=hasil[iq];
   }*/
selisih=abs(ip-iq);
//cout<<"\nselisih = "<<selisih<<"\n";

if (ip>=iq)
	{
   //cout<<"\n ip>=iq \n";
   for(i=ip;i>=1;i--)
	{
   if(i<=selisih)
   	{
      q[i]=0;
      }
   else if(i>selisih)
   	{
   	q[i]=q[i-selisih];
   	}
   //cout<<"\nhasil["<<i<<"]= "<<q[i]<<"\n";
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
   	if(i<=selisih)
   		{
      	q[i]=0;
      	}
   	else if(i>selisih)
   		{
   		q[i]=p[i-selisih];
   		}
   	//cout<<"\nhasil["<<i<<"]= "<<q[i]<<"\n";
   	}
   ii=1;
   for(i=iq;i>=1;i--)
		{
   	p[ii]=hasil[i];
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
    //cout<<"\n kond.1 \n";
   //cout<<"\nhasil perkalian p * q adalah \n";
   file_output<<"\nhasil perkalian p * q adalah \n";
   c[1]=0;
  	//cout<<c[1];
   file_output<<c[1];
   }
//else if(((kar_p[0]-48)==1 || (kar_q[0]-48)==1) && (ip==1 || iq==1))
 //	{
else if((p[1]==1 && ip==1 ) || (q[1]==1 && iq==1))
	{
    //cout<<"\n kond.2 \n";
   //cout<<"\nhasil perkalian p * q adalah \n";
   file_output<<"\nhasil perkalian p * q adalah \n";
   if(ip==1 && iq==1)
   	{
      hasil_kali[1][1]=p[1]*q[1];
   	if(hasil_kali[1][1]<10)
   		{
      	c[1]=hasil_kali[1][1];
      	//cout<<c[1];
   		file_output<<c[1];
      	kk=2;
      	}
   	else if(hasil_kali[1][1]>=10)
   		{
      	hasil_bagi=((hasil_kali[1][1])/10);
      	sisa_hasil_bagi=(hasil_kali[1][1])-10*hasil_bagi;
      	c[2]=sisa_hasil_bagi;
      	c[1]=hasil_bagi;
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
   //cout<<"\n kond.3 \n";
   //cout<<"\nhasil perkalian p * q adalah \n";
   file_output<<"\nhasil perkalian p * q adalah \n";
   hasil_kali[1][1]=p[1]*q[1];
   if(hasil_kali[1][1]<10)
   	{
      c[1]=hasil_kali[1][1];
      //cout<<c[1];
   	file_output<<c[1];
      kk=2;
      }
   else if(hasil_kali[1][1]>=10)
   	{
      hasil_bagi=((hasil_kali[1][1])/10);
      sisa_hasil_bagi=(hasil_kali[1][1])-10*hasil_bagi;
      c[2]=sisa_hasil_bagi;
      c[1]=hasil_bagi;
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
   //cout<<"\n kond.4 \n";
// untuk ip suda didefinisikan
iq=byk_digit;
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
      p[i]=p[i];
      //cout<<p[i];
      }
      //cout<<"\n";
    	/*selisih=abs(ip-iq);
   	for(j=1;j<=ip;j++)
   		{
      	if(j<=selisih)
      		{
         	q[j]=0;
         	//cout<<q[j];
         	}
      	else if(j>selisih)
      		{
      		q[j]=q[j-selisih];
         	//cout<<q[j];
      		}
         }*/

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
   iq=byk_digit; //untuk meminimalkan bentuk matrik
   file_output<<"\n\n";
   file_output<<"ip ="<<ip<<"\n";
   file_output<<"\niq ="<<iq<<"\n";
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
   file_output<<"ip ="<<ip<<"\n";
   file_output<<"\niq ="<<iq<<"\n";
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
 //cout<<"\nhasil p_split : \n";
 for(i=1;i<=loop_kk;i++)
	{
   //cout<<p_split[i];
   }
//cout<<"\n\n";
//pengurangan p_split dengan c[i]  kondisi
ip=loop_kk;
iq=kk-1;
//cout<<"\n******pada pengurangan*********\n";
//cout<<"\nip ="<<ip<<"\n";
//cout<<"\niq ="<<iq<<"\n";
//cout<<"\n***************\n";
if(ip>iq)
	{
   loop=ip;
   for(i=1;i<=ip;i++)
   	{
      p[i]=p_split[i];
      //cout<<p[i];
      }
      //cout<<"\n";
   selisih=abs(ip-iq);
   for(j=ip;j>=1;j--)
   	{
      if(j<=selisih)
      	{
         q[j]=0;
         //cout<<q[j];
         }
      else if(j>selisih)
      	{
      	q[j]=c[j-selisih];
         //cout<<q[j];
      	}
      }
   hasil_jml[loop]=0;
   for(k=loop;k>=1;k--)
   	{
      hasil_jml[k]+=p[k]-q[k];
      ////cout<<hasil_jml[k]<<" ";
      if(hasil_jml[k]<0 && k!=1)
      	{
         hasil_jml[k]=hasil_jml[k]+10;
         ////cout<<hasil_jml[k]<<" ";
         hasil_jml[k-1]=-1;
         }
      else
      	{
         hasil_jml[k]=hasil_jml[k];
         hasil_jml[k-1]=0;
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
	   selisih=abs(ip-iq);
	   for(j=iq;j>=1;j--)
	   	{
	      if(j<=selisih)
	      	{
	         p[j]=0;
	         }
	      else if(j>selisih)
	      	{
	      	p[j]=p_split[j-selisih];
	      	}
	      }
	   hasil_jml[loop]=0;
	   for(k=loop;k>=1;k--)
	   	{
	      hasil_jml[k]+=q[k]-p[k];
	      ////cout<<hasil_jml[k]<<" ";
	      if(hasil_jml[k]<0 && k!=1)
	      	{
	         hasil_jml[k]=hasil_jml[k]+10;
	         ////cout<<hasil_jml[k]<<" ";
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
	      p[i]=p_split[i];
	      }
	      //cout<<"\n";
	   selisih=abs(ip-iq);
	   for(j=ip;j>=1;j--)
	   	{
	      if(j<=selisih)
	      	{
	         q[j]=0;
	         }
	      else if(j>selisih)
	      	{
	         indek=selisih+1;//agar indek = 0,1,..
	      	q[j]=c[j-selisih];
	      	}
	      }
	   hasil_jml[loop]=0;
	   for(k=loop;k>=1;k--)
	   	{
	      hasil_jml[k]+=p[k]-q[k];
	      //cout<<"\n"<<hasil_jml[k]<<"\n";

	      if(hasil_jml[k]<0 && k!=1)
	      	{
	         hasil_jml[k]=hasil_jml[k]+10;
	         //cout<<"\n"<<hasil_jml[k]<<"\n";
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

   //cek letak nol
   cek_nol=1;
   ////cout<<"\nip - iq ="<<(ip-iq)<<"\n";
   while(hasil_jml[cek_nol]==0){
   cek_nol++;
   }
   //cout<<"\ncek_nol ="<<cek_nol<<endl;
   //tampilan hasil pengurangan
   //cout<<"\nhasil pengurangan dalam array = ";
   file_output<<"\nhasil pengurangan dalam array = ";
   kk=1;
	for(k=1;k<=loop;k++)
   	{
      if(k<cek_nol && loop!=1)
      	{
         continue;
         }
      else
      	{
         hasil_jml[kk]=hasil_jml[k];
         ////cout<<hasil_jml[kk];
         kk++;
         }     
      }

//cout<<"\n\n";
//getch ();
 //******************************************************************************************************************************//
for(k=1;k<=(kk-1);k++)
   	{
      //cout<<hasil_jml[k];
      file_output<<hasil_jml[k];
      }
//cout<<"\n\n";
// untuk p_split yang kedua dan seterusnya
//loop_split=strlen(kar_q)+1;
//iter_split=0;
//cout<<"\nstrlen(kar_p) = "<<strlen(kar_p)<<"\n";
//cout<<"\nloop_split = "<<loop_split<<"\n";
//cout<<"\nloop_kk = "<<kk<<"\n";
//cout<<"\nhasil penambahan satu array dibelakang = ";
file_output<<"\nhasil penambahan satu array dibelakang = ";
for(k=1;k<=((kk-1)+1);k++)
   	{
      p_split[k]=hasil_jml[k];
      if(k==((kk-1)+1) && loop_split<strlen(kar_p))
      	{
         p_split[k]=kar_p[loop_split]-48;
         }
      //cout<<p_split[k];
      file_output<<p_split[k];
      }
//cout<<"\n\n";
//untuk cek apakah p_split[1]=0 atau tidak
if(p_split[1]==0 && kk==2)
	{
//cout<<"\nhasil editing penambahan satu array dibelakang = ";
file_output<<"\nhasil editing penambahan satu array dibelakang = ";
   kk=1;
   p_split[1]=kar_p[loop_split]-48;
   //cout<<p_split[1];
   file_output<<p_split[1];
	}
loop_split++;
loop_kk=kk;
//cout<<"\nloop_split = "<<loop_split<<"\n";
//cout<<"\nloop_kk = "<<kk<<"\n";
//getch ();
}while(loop_split<=strlen(kar_p));
cout<<"sisa :";
file_output<<"sisa :";
cek_nol=1;
   while(sisa_akhir[cek_nol]==0){
   cek_nol++;
   }
	for(k=1;k<=loop_sisa;k++)
   	{
      if(k<cek_nol && loop_sisa!=1)
      	{
         continue;
         }
      else
      	{
      	cout<<sisa_akhir[k];
      	file_output<<sisa_akhir[k];
         }
      }
   }
}
getch ();
}
