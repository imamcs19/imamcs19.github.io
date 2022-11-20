#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iomanip.h>
#include <fstream.h>
#include <math.h>
#define max 1000  //can be change

class bigint_add {
	public :
     ~bigint_add();
     void enter_data_character();
     void enter_data_numeric(long double);
     void enter_data_txt(char *);
     void display_data();
     void save_txt(char *);
     bigint_add operator + (bigint_add);

     private :
     int length_byte;
     int diff,index,save_end,result_div,remainder_result_div;
     char char_num[max];
     int num[max],temp[max],result_add[max];
   };

bigint_add::~bigint_add(){}

void bigint_add::enter_data_character()
{
ofstream file_output;
file_output.open("result_add.txt",ios::app);
int i;
cout<<"\n\n> enter big integer max("<<max<<" digit) : ";
cin.getline(char_num,max); 
length_byte=strlen(char_num);
cout<<"\nlength_byte= "<<strlen(char_num)<<" byte = "<<8*strlen(char_num)<<" bit\n";
file_output<<"\nlength "<<strlen(char_num)<<" byte = "<<8*strlen(char_num)<<" bit\n";
	for(i=1;i<=length_byte;i++){
   	num[i]=(char_num[i-1])-48;
      file_output<<num[i];
   }
   file_output<<"\n"; 
}

void bigint_add::enter_data_numeric(long double _num)
{
ofstream file_output;
file_output.open("result_add.txt",ios::app);
long i,ii;
long double remainder,check;
	if(_num>=0){
		ii=0;
		do{
  			check=powl(10,ii);
  			ii++;
		}while(check<=_num);

		length_byte=(ii-1);

		for(i=1;i<=length_byte;i++){
      	num[i]=_num/powl(10,(ii-2)-(i-1));
      	remainder=_num-num[i]*powl(10,(ii-2)-(i-1));
      	_num=remainder;
      	//cout<<num[i];
      	file_output<<num[i];
   	}
   }
   else{
   	_num=-1*(_num);
   	ii=0;
		//num=new int[max];
		do{
  			check=powl(10,ii);
  			ii++;
		}while(check<=_num);

      ii+=1; // because the number is start signed negative(-)
		length_byte=(ii-1);
      num[1]=-3;
		for(i=2;i<=length_byte;i++){
      	num[i]=_num/powl(10,(ii-2)-(i-1));
      	remainder=_num-num[i]*powl(10,(ii-2)-(i-1));
      	_num=remainder;
   	}

      for(i=1;i<=length_byte;i++){
      	if(i==1){
      		//cout<<char(num[i]+48); //character negative(-)
      		file_output<<char(num[i]+48);
         }
         else{
      		//cout<<num[i]; //character negative(-)
      		file_output<<num[i];
         }
   	}
   }
//cout<<"\n";
file_output<<"\n";
//cout<<"\n\nlength_byte= "<<length_byte<<" byte = "<<8*length_byte<<" bit\n";
file_output<<"\nlength "<<length_byte<<" byte = "<<8*length_byte<<" bit\n";
}

void bigint_add::display_data()
{
ofstream file_output;
file_output.open("result_add.txt",ios::app);
int i;
//cout<<"\nresult end :\n";
file_output<<"\nresult end :\n";
	if(num[1]==-3){
   	for(i=1;i<=length_byte;i++){
      	if(i==1){
      		cout<<char(num[i]+48); //character negative(-)
      		file_output<<char(num[i]+48);
         }
         else{
      		cout<<num[i]; //character negative(-)
      		file_output<<num[i];
         }
      }
   }
   else{
		for(i=1;i<=length_byte;i++){
      	cout<<num[i]; //character negative(-)
      	file_output<<num[i];
      }
   }
   file_output<<"\n";
}

bigint_add bigint_add::operator + (bigint_add m2)
{
int i,j,k,loop;
int check_zero,ii,jj,kk; //extra from subtraction variable 
bigint_add result2;
result2.length_byte=length_byte;
	if(num[1]==-3 && m2.num[1]==-3){ //if condition negative(-) + negative(-)
   	length_byte-=1;
      m2.length_byte-=1;
      for(k=1;k<=length_byte;k++){
      	num[k]=num[k+1];
         ////cout<<num[k];
      }
      ////cout<<"\n";
      for(k=1;k<=m2.length_byte;k++){
      	m2.num[k]=m2.num[k+1];
         ////cout<<m2.num[k];
      }
      ////cout<<"\n";
		if (length_byte>=m2.length_byte){
   		loop=length_byte;
   		diff=abs(length_byte-m2.length_byte);
   		for(j=length_byte;j>=1;j--){
      		m2.num[j+diff]=m2.num[j];
      		if(j<=diff){
         		m2.num[j]=0;
         	}
      		else if(j>diff){
         		m2.num[j]=m2.num[j-diff];
      		}
      	}
   		result_add[loop]=0;
   		for(k=loop;k>=1;k--){
      		result_add[k]+=num[k]+m2.num[k];
      		////cout<<result_add[k]<<" ";
      		if(result_add[k]>=10 && k!=1){
         		result_add[k-1]=result_add[k];
               result_add[k]=result_add[k-1]%10;
         		result_add[k-1]=floor(result_add[k-1]/10);
         	}
      		else{
         		result_add[k]=result_add[k];
         		result_add[k-1]=0;
         	}
      	}
   	}
		else if(length_byte<m2.length_byte){
   		loop=m2.length_byte;
   		for(i=1;i<=m2.length_byte;i++){
      		temp[i]=num[i];
      	}
   		for(i=1;i<=m2.length_byte;i++){
      		num[i]=m2.num[i];
      	}
   		diff=abs(m2.length_byte-length_byte);
   		for(j=m2.length_byte;j>=1;j--){
      		if(j<=diff){
         		m2.num[j]=0;
         	}
      		else if(j>diff){
         		m2.num[j]=temp[j-diff];
      		}
      	}
   		result_add[loop]=0;
   		for(k=loop;k>=1;k--){
      		result_add[k]+=m2.num[k]+num[k];
      		if(result_add[k]>=10 && k!=1){
         		result_add[k-1]=result_add[k];
               result_add[k]=result_add[k-1]%10;
         		result_add[k-1]=floor(result_add[k-1]/10);
         	}
      		else{
         		result_add[k]=result_add[k];
         		result_add[k-1]=0;
         	}
      	}
   	}
      num[1]=-3; //to show the result addition is negative(-)
      loop+=1;
		for(k=2;k<=loop;k++){
      	num[k]=result_add[k-1];
      }
   	result2.length_byte=loop; // update value length_byte
   	for(k=1;k<=loop;k++){
      	result2.num[k]=num[k];
      }
	} //endif(num[1]==-3 && m2.num[1]==-3)

   else if(num[1]!=-3 && m2.num[1]!=-3){ //if the condition is positive(+) + positive(+)
		if (length_byte>=m2.length_byte){
   		loop=length_byte;
   		diff=abs(length_byte-m2.length_byte);
   		for(j=length_byte;j>=1;j--){
      		m2.num[j+diff]=m2.num[j];
      		if(j<=diff){
         		m2.num[j]=0;
         	}
      		else if(j>diff){
         		m2.num[j]=m2.num[j-diff];
      		}
      	}
   		result_add[loop]=0;
   		for(k=loop;k>=1;k--){
      		result_add[k]+=num[k]+m2.num[k];
      		////cout<<result_add[k]<<" ";
      		if(result_add[k]>=10 && k!=1){
         		result_add[k-1]=result_add[k];
               result_add[k]=result_add[k-1]%10;
         		result_add[k-1]=floor(result_add[k-1]/10);
         	}
      		else{
         		result_add[k]=result_add[k];
         		result_add[k-1]=0;
         	}
      	}
   	}
		else if(length_byte<m2.length_byte){
   		loop=m2.length_byte;
   		for(i=1;i<=m2.length_byte;i++){
      		temp[i]=num[i];
      	}
   		for(i=1;i<=m2.length_byte;i++){
      		num[i]=m2.num[i];
      	}
   		diff=abs(m2.length_byte-length_byte);
   		for(j=m2.length_byte;j>=1;j--){
      		if(j<=diff){
         		m2.num[j]=0;
         	}
      		else if(j>diff){
         		m2.num[j]=temp[j-diff];
      		}
      	}
   		result_add[loop]=0;
   		for(k=loop;k>=1;k--){
      		result_add[k]+=m2.num[k]+num[k];
      		if(result_add[k]>=10 && k!=1){
         		result_add[k-1]=result_add[k];
               result_add[k]=result_add[k-1]%10;
         		result_add[k-1]=floor(result_add[k-1]/10);
         	}
      		else{
         		result_add[k]=result_add[k];
         		result_add[k-1]=0;
         	}
      	}
   	}
		for(k=1;k<=loop;k++){
      	num[k]=result_add[k];
      }
   	result2.length_byte=loop; // update value length_byte

   	for(k=1;k<=loop;k++){
      	result2.num[k]=num[k];
      }
	} //endif(num[1]!=-3 && m2.num[1]!=-3)
   else if(num[1]!=-3 && m2.num[1]==-3){ //if the condition is positive(+) + negative(-)
      m2.length_byte-=1;
      for(k=1;k<=length_byte;k++){
         //cout<<num[k];
      }
      //cout<<"\n";
      for(k=1;k<=m2.length_byte;k++){
      	m2.num[k]=m2.num[k+1];
         //////cout<<m2.num[k];
      }        
		if(length_byte>m2.length_byte){
   		loop=length_byte;
   		diff=abs(length_byte-m2.length_byte); 
   		for(j=length_byte;j>=1;j--){ //after condition is m2.num positive(+)
      		if(j<=diff){
         		m2.num[j]=0;
         	}
      		else if(j>diff){
      			m2.num[j]=m2.num[j-diff];
      		}
      	}

         //display number to ready operation
         for(j=1;j<=length_byte;j++){
         	//cout<<num[j]<<" "; //appear after normal with give value zero in front
         }
         //cout<<"\n";
         for(j=1;j<=length_byte;j++){
         	//cout<<m2.num[j]<<" "; //appear after normal with give value zero in front
         }       
   		//cout<<"\n";
   	result_add[length_byte]=0;
   	for(k=length_byte;k>=1;k--){
      	result_add[k]+=(num[k]-m2.num[k]);
      	if((result_add[k]<0 || result_add[k]>=10)&& k!=1){
               if(result_add[k]>=10){           
               	result_add[k-1]=result_add[k];
               	result_add[k]=result_add[k-1]%10;
               	result_add[k-1]=floor(result_add[k-1]/10);
            	}
               else{
               	result_add[k-1]=result_add[k];
                  result_add[k]=(result_add[k-1]%10)+10;
                  result_add[k-1]=(-1 + floor(result_add[k-1]/10));
               }
            }
      		else{ //for k=1
         		if(num[k]< m2.num[k]){
                  result_add[k-1]=result_add[k];
                  result_add[k]=(result_add[k-1]%10)+10;
                  result_add[k-1]=(-1 + floor(result_add[k-1]/10));
            	}
            	else if(num[k]>= m2.num[k]){ 
               	result_add[k]=result_add[k];
               	result_add[k-1]=0;
            	} 
         	}
      	}
   	}
   else if(length_byte<m2.length_byte){
   	loop=m2.length_byte;
   	for(i=1;i<=m2.length_byte;i++){
	      temp[i]=num[i];
      }
      //cout<<"\n";
	   for(i=1;i<=m2.length_byte;i++){
	      num[i]=m2.num[i];
         //////////cout<<num[i];
      }     
	   diff=abs(length_byte-m2.length_byte);
	   for(j=m2.length_byte;j>=1;j--){
	      if(j<=diff){
	         m2.num[j]=0;
         }
	      else if(j>diff){
            m2.num[j]=temp[j-diff];
         }
         //////////cout<<m2.num[j];
      }
      //////////cout<<"\n";

      //display number ready to operation
         for(j=1;j<=m2.length_byte;j++){
         	//cout<<num[j]<<" "; //appear after normal with give value zero in front
         }
         //cout<<"\n";
         for(j=1;j<=m2.length_byte;j++){
         	//cout<<m2.num[j]<<" "; //appear after normal with give value zero in front
         }
   	//cout<<"\n";

	   result_add[m2.length_byte]=0;
	   for(k=m2.length_byte;k>=1;k--){
	      result_add[k]+=num[k]-m2.num[k];
	      if((result_add[k]<0 || result_add[k]>=10) && k!=1){
            if(result_add[k]>=10){       
               result_add[k-1]=result_add[k];
               result_add[k]=result_add[k-1]%10;
               result_add[k-1]=floor(result_add[k-1]/10);
            }
            else{
            	result_add[k-1]=result_add[k];
            	result_add[k]=(result_add[k-1]%10)+10;
            	result_add[k-1]=(-1 + floor(result_add[k-1]/10));
            }
         }
	      else{
	         result_add[k]=result_add[k]; //actually is nothing declare
	         result_add[k-1]=0;   
         }
      }      
   }
   else if(length_byte==m2.length_byte){ 
      ii=0,jj=0,kk=0;
      for(i=1;i<=m2.length_byte;i++){
   		if (num[i]<m2.num[i]){
      		ii=1;
            break;
         }
     	 	else if(num[i]>m2.num[i]){
         	jj=1;
            break;
         }
      	else if (num[i]==m2.num[i]){
         	kk++;
         }
      }

    	if(ii==1){
	   	loop=m2.length_byte;
	   	for(i=1;i<=m2.length_byte;i++){
	      	temp[i]=num[i];
	      }
	   	for(i=1;i<=m2.length_byte;i++){
	      	num[i]=m2.num[i];
	      }
	   	diff=abs(length_byte-m2.length_byte);

	   	for(j=m2.length_byte;j>=1;j--){
	      	if(j<=diff){
	         	m2.num[j]=0;
	         }
	      	else if(j>diff){ 
               m2.num[j]=temp[j-diff];
	      	}
	      }

         //display number ready to operation
         for(j=1;j<=length_byte;j++){
         	//cout<<num[j]<<" "; //appear after normal with give value zero in front
         }
         //cout<<"\n";
         for(j=1;j<=length_byte;j++){
         	//cout<<m2.num[j]<<" "; //appear after normal with give value zero in front
         }
   		//cout<<"\n";

	   	result_add[m2.length_byte]=0;
	   	for(k=m2.length_byte;k>=1;k--){
            result_add[k]+=(num[k]-m2.num[k]);
	      	if(result_add[k]<0 && k!=1){   
               result_add[k-1]=result_add[k];
               result_add[k]=(result_add[k-1]%10)+10;
         		result_add[k-1]=(-1 + floor(result_add[k-1]/10));
	         }
	      	else{
	         	result_add[k-1]=0;  
	         }
	      }
      }
      else if(jj==1){
      	loop=length_byte;
	   	result_add[length_byte]=0;
	   	for(k=length_byte;k>=1;k--){
	      	result_add[k]+=num[k]-m2.num[k];
	      	if(result_add[k]<0 && k!=1){
               result_add[k-1]=result_add[k];
               result_add[k]=(result_add[k-1]%10)+10;
         		result_add[k-1]=(-1 + floor(result_add[k-1]/10));
	         }
	      	else{
	         	result_add[k]=result_add[k]; //actually is nothing declare
	         	result_add[k-1]=0;
	         }
	      }
      }
      else if(kk==m2.length_byte){
         loop=1;
         result_add[1]=0;
         result2.num[1]=0;
      }
   }

   	check_zero=0; //check position zero
		while(result_add[(check_zero+1)]==0){
			check_zero++;
		};
   	if(check_zero<=loop){
   		kk=1;
   		for(k=1;k<=loop;k++){
      		if(k<=check_zero){
         		continue;
         	}
      		else{
     				num[kk]=result_add[k];
         		kk++;
       		}
      	}
   	}
   	else if(check_zero>loop){
     	 	kk=2;
      	for(i=1;i<=(kk-1);i++){
      		num[1]=0;
      	}
   	}
   	loop=kk-1;

   	//cout<<"\ndisplay num :\n";
   	for(k=1;k<=loop;k++){
      	//cout<<num[k];
      }
      //cout<<"\n";
      //condition if result negative(-)
      if(length_byte<m2.length_byte || ii==1){
      	loop+=1;
   		result2.length_byte=loop;
      	result2.num[1]=-3;
			for(k=2;k<=loop;k++){
      		result2.num[k]=num[k-1];
   		}
         //////cout<<"\n";
         for(k=1;k<=loop;k++){
      		//////cout<<result2.num[k];
   		}
         //////cout<<"\n";
      }

      else{
   		//cout<<"\nloop ="<<loop<<"\n";
   		result2.length_byte=loop;
         //////cout<<"\n";
			for(k=1;k<=loop;k++){
      		result2.num[k]=num[k];
      		//////cout<<result2.num[k];
   		}
         //////cout<<"\n";
      }                                        
	} //endif(num[1]!=-3 && m2.num[1]==-3)

   else if(num[1]==-3 && m2.num[1]!=-3){ //if the condition is negative(-) + positive(+)
      length_byte-=1;
      //m2.length_byte-=1;

      for(k=1;k<=length_byte;k++){
      	num[k]=num[k+1];
         ////cout<<num[k];
      }
		if(length_byte>m2.length_byte){
      	//cout<<"\nkond length_byte > m2.length_byte"<<"\n";
         //////getch();

   		loop=length_byte;
   		////////cout<<"\nnum[1] ="<<num[1]<<"\n";
   		diff=abs(length_byte-m2.length_byte);  
   		for(j=length_byte;j>=1;j--){ //after condition m2.num positive(+)
      		if(j<=diff){
         		m2.num[j]=0;
         	}
      		else if(j>diff){
      			m2.num[j]=m2.num[j-diff];
      		}
      	////////cout<<m2.num[j]; //appear is the reverse
      	}

         //display number ready to operation
         for(j=1;j<=length_byte;j++){
         	//cout<<num[j]<<" "; //appear after normal with give value zero in front
         }
         //cout<<"\n";
         for(j=1;j<=length_byte;j++){
         	//cout<<m2.num[j]<<" "; //appear after normal with give value zero in front
         }
   	//cout<<"\n";
   	result_add[length_byte]=0;
   	for(k=length_byte;k>=1;k--){
      	result_add[k]+=(num[k]-m2.num[k]);
      	if((result_add[k]<0 || result_add[k]>=10)&& k!=1){ 
               if(result_add[k]>=10){
               	result_add[k-1]=result_add[k];
               	result_add[k]=result_add[k-1]%10;
               	result_add[k-1]=floor(result_add[k-1]/10);
            	}
               else{
               	result_add[k-1]=result_add[k];
                  result_add[k]=(result_add[k-1]%10)+10;
                  result_add[k-1]=(-1 + floor(result_add[k-1]/10));
               }  
            }
      		else{ //for k=1
         		if(num[k]< m2.num[k]){
                  result_add[k-1]=result_add[k];
                  result_add[k]=(result_add[k-1]%10)+10;
                  result_add[k-1]=(-1 + floor(result_add[k-1]/10));
            	}
            	else if(num[k]>= m2.num[k]){
               	result_add[k]=result_add[k];
               	result_add[k-1]=0;
            	}
         	}
      	}
   	}
   else if(length_byte<m2.length_byte){
   	//cout<<"\nkond length_byte < m2.length_byte"<<"\n";
   	loop=m2.length_byte;
   	for(i=1;i<=m2.length_byte;i++){
	      temp[i]=num[i];
      }
	   for(i=1;i<=m2.length_byte;i++){
	      num[i]=m2.num[i];
         ////////cout<<num[i];
      }         
	   diff=abs(length_byte-m2.length_byte);

	   for(j=m2.length_byte;j>=1;j--){
	      if(j<=diff){
	         m2.num[j]=0;
         }
	      else if(j>diff){
            m2.num[j]=temp[j-diff];
         }
         ////////cout<<m2.num[j];
      }
      ////////cout<<"\n";

      //display number ready to operation
         for(j=1;j<=m2.length_byte;j++){
         	//cout<<num[j]<<" "; //appear after normal with give value zero in front
         }
         //cout<<"\n";
         for(j=1;j<=m2.length_byte;j++){
         	//cout<<m2.num[j]<<" "; //appear after normal with give value zero in front
         }
   	//cout<<"\n";
      
	   result_add[m2.length_byte]=0;
	   for(k=m2.length_byte;k>=1;k--){
	      result_add[k]+=num[k]-m2.num[k];
	      if((result_add[k]<0 || result_add[k]>=10) && k!=1){
            if(result_add[k]>=10){
               result_add[k-1]=result_add[k];
               result_add[k]=result_add[k-1]%10;
               result_add[k-1]=floor(result_add[k-1]/10);
            }
            else{
            	result_add[k-1]=result_add[k];
            	result_add[k]=(result_add[k-1]%10)+10;
            	result_add[k-1]=(-1 + floor(result_add[k-1]/10));
            }
         }
	      else{
	         result_add[k]=result_add[k]; //actually is not to declaration 
	         result_add[k-1]=0;
         }
      }
   }
   else if(length_byte==m2.length_byte){ 
      ii=0,jj=0,kk=0;
      for(i=1;i<=m2.length_byte;i++){
   		if (num[i]<m2.num[i]){
      		ii=1;
            break;
         }
     	 	else if(num[i]>m2.num[i]){
         	jj=1;
            break;
         }
      	else if (num[i]==m2.num[i]){
         	kk++;
         }
      }
         
    	if(ii==1){
	   	loop=m2.length_byte;
	   	for(i=1;i<=m2.length_byte;i++){
	      	temp[i]=num[i];
	      }
	   	for(i=1;i<=m2.length_byte;i++){
	      	num[i]=m2.num[i];
	      }
	   	diff=abs(length_byte-m2.length_byte);

	   	for(j=m2.length_byte;j>=1;j--){
	      	if(j<=diff){
	         	m2.num[j]=0;
	         }
	      	else if(j>diff){  
               m2.num[j]=temp[j-diff];
	      	}
	      }

         //display number ready to operation
         for(j=1;j<=length_byte;j++){
         	//cout<<num[j]<<" "; //appear after normal with give value zero in front
         }
         //cout<<"\n";
         for(j=1;j<=length_byte;j++){
         	//cout<<m2.num[j]<<" "; //appear after normal with give value zero in front
         }
      	//}
   		//cout<<"\n";

	   	result_add[m2.length_byte]=0;
      	//save_ii=0;
	   	for(k=m2.length_byte;k>=1;k--){
            result_add[k]+=(num[k]-m2.num[k]);
	      	if(result_add[k]<0 && k!=1){
               result_add[k-1]=result_add[k];
               result_add[k]=(result_add[k-1]%10)+10;
         		result_add[k-1]=(-1 + floor(result_add[k-1]/10));
	         }
	      	else{
	         	result_add[k-1]=0; 
	         }
	      }
      }
      else if(jj==1){
      	loop=length_byte;
	   	result_add[length_byte]=0;
	   	for(k=length_byte;k>=1;k--){
	      	result_add[k]+=num[k]-m2.num[k];
	      	if(result_add[k]<0 && k!=1){
               result_add[k-1]=result_add[k];
               result_add[k]=(result_add[k-1]%10)+10;
         		result_add[k-1]=(-1 + floor(result_add[k-1]/10));
	         }
	      	else{
	         	result_add[k]=result_add[k]; //actually is nothing declare
	         	result_add[k-1]=0;
	         }
	      }
      }
      else if(kk==m2.length_byte){
         loop=1;
         result_add[1]=0;
         result2.num[1]=0;
      }
   }
   	//result2.length_byte=loop;

   	check_zero=0; //check position zero
		while(result_add[(check_zero+1)]==0){
			check_zero++;
		};         
   	if(check_zero<=loop){
   		kk=1;
   		for(k=1;k<=loop;k++){
      		if(k<=check_zero){
         		continue;
         	}
      		else{
     				num[kk]=result_add[k];
         		kk++;
       		}
      	}
   	}
   	else if(check_zero>loop){
     	 	kk=2;
      	for(i=1;i<=(kk-1);i++){
      		num[1]=0;
      		////////cout<<num[1];
      	}
   	}
   	loop=kk-1;

      ////////cout<<"\ndisplay num :\n";
   	for(k=1;k<=loop;k++){
      	////////cout<<num[k];
      }
      ////////cout<<"\n";
      //condition if result negative(-)
      if(length_byte<m2.length_byte || ii==1){
      	//////cout<<"\nloop ="<<loop<<"\n";
   		result2.length_byte=loop;
			for(k=1;k<=loop;k++){
      		result2.num[k]=num[k];
      		//cout<<result2.num[k];
   		}
         //cout<<"\n";
      }

      else{
         loop+=1;
   		result2.length_byte=loop;            
      	result2.num[1]=-3;
			for(k=2;k<=loop;k++){
      		result2.num[k]=num[k-1];
   		}
         //cout<<"\n";
         for(k=1;k<=loop;k++){
      		//cout<<result2.num[k];
   		}
         //cout<<"\n";
      }

	} //endif(num[1]==-3 && m2.num[1]!=-3)

   return result2;
}

void main (){
long double b2,b3,b4,b5; // max 18-19 digit for type long double
b2=23874983254368;
b3=6532754723436534;
b4=5487126438621874;
b5=8932187438921;
bigint_add a1,a2,a3,a4,a5,a6,a7;
cout<<"Overloading Operator to Addition Big Integer :\n";
cout<<"=====================================================\n";
a1.enter_data_numeric(b2); //convert number to array
a2.enter_data_numeric(b3);
a3.enter_data_numeric(b4);
a4.enter_data_numeric(b5);

cout<<"\na1 = ";
a1.display_data();

cout<<"\na2 = ";
a2.display_data();

cout<<"\na3 = ";
a3.display_data();

cout<<"\na4 = ";
a4.display_data();

a6.enter_data_character(); // maximum <= #define max 1000
cout<<"a6 = ";
a6.display_data();

a7.enter_data_character(); // maximum <= #define max 1000
cout<<"a7 = ";
a7.display_data();
cout<<"\n\n";

cout<<"Count addition a5 = a1 + a2 + a3 + a4 = ";
a5=a1 + a2 + a3 + a4;
a5.display_data();
cout<<"\n\n";

cout<<"Count addition a5 = a5 + a6 = ";
a5=a5 + a6;
a5.display_data();
cout<<"\n\n";

cout<<"Count addition a5 = a6 + a7 = ";
a5=a6 + a7;
a5.display_data();
getch ();
}
