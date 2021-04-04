#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
/*CSE 102 HOMEWORK 4
AUTHOR:AHMET OKUR 1801042655*/

char decrypt_numbers(int number);
void decrypt_and_printf(char* file_path);/*PART1*/
void deep_decrypt_and_print (char* file_path);/*PART2*/

void track_machine ();/*PART3*/
void refresh_position(int *X, int *Y, double *D, double *R);/*PART3*/

void encrypt_messages (char* file_path);/*PART4*/
int encrypt_char(char ch);/*PART4*/
void encrypt_write_p4(int a,char flag,int *count);/*PART4*/

void menu();


int main(void){
	menu();
}

void menu(){
	int selection,flag=1;
	while(flag==1){
		printf("\n1-)Decrypt and print encrypted_p1.img\n2-)Decrypt and print encrypted_p2.img\n3-)Switch on the tracking machine\n4-)Encrypted the message\n5-)Switch off\n");
		printf("Please make your choice:");
		scanf("%d",&selection);
		
		switch (selection){
			case 1:decrypt_and_printf("encrypted_p1.img");break;
			case 2:deep_decrypt_and_print("encrypted_p2.img");break;
			case 3:track_machine ();break;
			case 4:encrypt_messages ("decrypted_p4.img");break;
			case 5:flag=0;printf("\nGood byee!!\n");break;
			default:printf("\nIncorrect entry please try again!!!!!!\n");break;
		}
	}
}

void decrypt_and_printf(char* file_path){
	int number;
	char ch;
	FILE *fp;
	if((fp=fopen(file_path,"r"))==NULL){
		printf("FILE NOT FOUND!!!!");
	}
	else{
	fp=fopen(file_path,"r");
	
	while(!feof(fp)){
		fscanf(fp,"%c",&ch);
		/*converting characters to numbers*/
		number=ch-'0';
		/*number -38==\n */
		if(number==-38){
			number=0;
			printf("%c",decrypt_numbers(number));
			printf("\n");
		}
		
		else{
			printf("%c",decrypt_numbers(number));
		}
	
	}
	fclose(fp);
}
}
void deep_decrypt_and_print (char* file_path){
	int number,result=0,index=0;
	char ch;
	FILE *fp;
	if((fp=fopen(file_path,"r"))==NULL){
		printf("FILE NOT FOUND!!!");
	}
	else{
		fp=fopen(file_path,"r");
		
		while(!feof(fp)){
			fseek(fp,index,SEEK_SET);
			fscanf(fp,"%c",&ch);
			
			if(ch=='\n'){
				printf("\n");
				index++;
				printf("%c",decrypt_numbers(result));
			}
			else{
				/*application of the formula*/
				fseek(fp,index,SEEK_SET);
				fscanf(fp,"%c",&ch);
				number=ch-'0';
				result=result+number;
				
				fseek(fp,index+1,SEEK_SET);
				fscanf(fp,"%c",&ch);
				number=ch-'0';
				result=result+number;
				
				fseek(fp,index+2,SEEK_SET);
				fscanf(fp,"%c",&ch);
				number=ch-'0';
				result=result+number;		
				
				result=result%7;
				/*printing the result*/
				printf("%c",decrypt_numbers(result));
				result=0;
			}
			/*switch to next index*/
			index++;
		}
		fclose(fp);
	}
}



char decrypt_numbers(int number){
	
	switch (number){
		case 0: return ' ';
		case 1: return '-';
		case 2: return '_';
		case 3: return '|';
		case 4: return '/';
		case 5: return '\\';
		case 6: return 'O';
		default:return ' ';
	}	

}
int encrypt_char(char ch){
	switch (ch){
		case ' ': return 0;	
		case '-': return 1;	
		case '_': return 2;
		case '|': return 3;		
		case '/': return 4;			
		case '\\': return 5;		
		case 'O': return 6;
		case '\n': return 0;
		}
}



void track_machine (){
	int Ox=6,Oy=6,X=1,Y=1;
	
	double R;
	double D=7.071068;/*first value*/
	
	char selection='R';
	while(selection=='R'){	
		/*coordinate system*/
		for(int i=1;i<12;i++){
			for(int j=1;j<12;j++){
				if(Ox==i && Oy==j){
					printf("O");
				}

				else if(X==i && Y==j){
					printf("E");
				}
				else{
					printf(".");
				}
				printf("\t");
		
			}
			printf("\n");
		}

			printf("\n");
			printf("Enemies X position: %d, Y position: %d,Displacement: %lf,Distance to our camp: %lf",X,Y,R,D);
			printf("\nFOR EXİT=E,FOR REFRESH=R");
			
			printf("\nCommand waiting...");
			scanf(" %c",&selection);
			
			
			if(selection=='R'){
				refresh_position(&X,&Y,&R,&D);
			}

			else if(selection=='E'){
				printf("Machine turned off");
			}
			else{
				printf("\n\nIncorrect entry PLEASE TRY AGAİN!!!!\a\a\n\n");
			}
			printf("\n");
	}

	
}
void refresh_position(int *X, int *Y, double *R, double *D){
	int X2,Y2;
	X2=*X;
	Y2=*Y;
	/*for random number*/
	srand(time(NULL));
	
	*X=rand()%11+1;
	*Y=rand()%11+1;
	
	/*R shows the distance between current position and the last position of the enemy camp*/
	*R=sqrt((*X-X2)*(*X-X2)+(*Y-Y2)*(*Y-Y2));
	/*D is the distance of enemy to our camp*/
	*D=sqrt((6-*X)*(6-*X)+(6-*Y)*(6-*Y));
}

void encrypt_messages (char* file_path){
		int number=0,result=0,index=0,temp,count=1;;
		char ch,flag;
		FILE *fp;
		if((fp=fopen(file_path,"r"))==NULL){
		printf("FILE NOT FOUND!!!");
		}
		else{
			fp=fopen(file_path,"r");
			
			while(!feof(fp)){
				/*flag checks line break*/
				flag='b';
				if(ch=='\n'){
					
					flag='a';
					encrypt_write_p4(result,flag,&count);			
				
				}
				flag='b';
				/*application of the formula*/
				fseek(fp,index-2,SEEK_SET);
				fscanf(fp,"%c",&ch);
				number=encrypt_char(ch);
				result=number+result;
				
				
				fseek(fp,index-1,SEEK_SET);
				fscanf(fp,"%c",&ch);
				number=encrypt_char(ch);
				result=number+result;
				temp=-number;
				
				fseek(fp,index,SEEK_SET);
				fscanf(fp,"%c",&ch);
				number=encrypt_char(ch);
				result=number+result;			
				/*switch to next index*/
				index++;
				
				if(ch=='\n'){
					/*action required for line breaks*/
					result=temp;
					count++;
					
					continue;
				}
				result=result%7;
				
				/*writing for each result*/
				encrypt_write_p4(result,flag,&count);
				result=0;
				count++;
				

			}
		printf("encrypted_p4.img is ready!!!!\n\n");
		fclose(fp);
	}

}
void encrypt_write_p4(int a,char flag,int *count){
	FILE *fp;
	/*Img file is cleared for 1 time*/
	if(*count==1){
		fp=fopen("encrypted_p4.img","w");
		fclose(fp);
	}
	
	fp=fopen("encrypted_p4.img","a");	
	if(flag=='a'){
		fprintf(fp,"\n");
	}
	else if(a>=0){
		fprintf(fp,"%d",a);
	}	
	fclose(fp);	
	
}
