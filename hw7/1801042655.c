#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*		GEBZE TECHNICAL UNIVERSITY 
		CSE 102 HOMEWORK 7
		AUTHOR:AHMET OKUR 1801042655
*/

void games_stored(char all_games[2000][100]);/*thic func. read all game*/
void genre_strode(char genre[12][20],float float_datas[2000][7]);/*this func .read genres and stored float_datas*/
void platform_strode(char platform[10][20],float float_datas[2000][7]);/*this func .read platforms and stored float_datas*/
void flaot_data_stored(float float_datas[2000][7]);/*this func read file and stored float datas*/
void menu(char all_games[2000][100],char genre[12][20],char platform[10][20],float float_datas[2000][7]);


int main(){
	
	char all_games[2000][100];
	char genre[12][20],platform[10][20];
	float float_datas[2000][7];
		
		games_stored(all_games);
		genre_strode(genre,float_datas);
		platform_strode(platform,float_datas);
		flaot_data_stored(float_datas);
		menu(all_games,genre,platform,float_datas);

		return 0;
}
void games_stored(char all_games[2000][100]){
	char ch;
	int i=0,j=0,row_control=0;
	FILE *fp;
	fp=fopen("Video_Games.txt","r");
		while(!feof(fp)){
			fscanf(fp,"%c",&ch);
			if(ch=='\n'){
				j=0;
				if(row_control>0){
					i++;
				}
				row_control++;
				
				continue;
			}

				if(row_control>0){
					all_games[i][j]=ch;
					
					if(ch==','){
						all_games[i][j]='\0';
					}
					j++;
				}
			
		}
		fclose(fp);
}
void genre_strode(char genre[10][20],float float_datas[2000][7]){
	char all_genre[2001][20];
	char ch;
	int i=0,j=0;
	int count_column=0;
	int k=1,flag=0;
	/*all genre stored in all_genre*/
	
	FILE *fp;
	fp=fopen("Video_Games.txt","r");
		while(!feof(fp)){
			fscanf(fp,"%c",&ch);
			if (count_column==1)
			{
				all_genre[i][j]=ch;
				j++;
			}

			if(ch=='\n'){
				j=0;
				i++;
				count_column=0;
				continue;
			}
			
			if(ch==','){
				count_column++;
			}
			
			if (count_column==2)
			{
				all_genre[i][j-1]='\0';
			}

		}
		fclose(fp);
	
	/*overlopping control*/	
	strncpy(genre[0],all_genre[1],20);
	for(i=1;i<2001;i++){
		flag=0;
		for(j=0;j<12;j++){
			if(strcmp(genre[j],all_genre[i])==0){
				flag=1;
			}
		}
		if(flag==0){
			strncpy(genre[k],all_genre[i],20);
			k++;
		}
	}
	
	/*genre float stored*/
	for(i=1;i<2001;i++){
		for(j=0;j<12;j++){
			if(strcmp(all_genre[i],genre[j])==0){
				float_datas[i-1][0]=j;
			
			}
		}
	}



}


void platform_strode(char platform[12][20],float float_datas[2000][7]){
	char all_platform[2001][20];
	char ch;
	int i=0,j=0;
	int count_column=0;
	int flag=0,k=1;
	int row_control=0;
	/*all platform stored in all_platform*/
	FILE *fp;
	fp=fopen("Video_Games.txt","r");
		while(!feof(fp)){
			fscanf(fp,"%c",&ch);
				if (count_column==2)
				{
					all_platform[i][j]=ch;
					j++;
				}

				if(ch=='\n'){
					j=0;
					i++;
					count_column=0;
					continue;
				}
				
				if(ch==','){
					count_column++;
				}
				
				if (count_column==3){
					all_platform[i][j-1]='\0';
				}
			

		}
		fclose(fp);
	/*overlopping control*/
	strncpy(platform[0],all_platform[1],20);
	for(i=1;i<2001;i++){
		flag=0;
		for(j=0;j<10;j++){
			if(strcmp(platform[j],all_platform[i])==0){
				flag=1;
			}
		}
		if(flag==0){
			strncpy(platform[k],all_platform[i],20);
			k++;
		}
	}

	/*paltform float stored*/
	for(i=1;i<2001;i++){
		for(j=0;j<10;j++){
			if(strcmp(all_platform[i],platform[j])==0){
				float_datas[i-1][1]=j;
			
			}
		}
	}

}
void flaot_data_stored(float float_datas[2000][7]){
	int i=0,a=2;
	char ch;
	int file_count=0;
	char string_convert_float[15];/*stores every word*/
	int colum_count=0;
	char *ptr;
   float float_convert;

	FILE *fp;
	fp=fopen("Video_Games.txt","r");
	while(!feof(fp)){
		fscanf(fp,"%c",&ch);
		if(ch=='\n'){
			if(file_count>0){
			float_convert= strtod(string_convert_float, &ptr);
			float_datas[file_count-1][a]=float_convert;
			}
			file_count++;
			colum_count=0;
			a=2;
			i=0;
			continue;

		}
	
	
	if(ch==','&& file_count>0){
		
		if(colum_count>2){
			float_convert= strtod(string_convert_float, &ptr);
			float_datas[file_count-1][a]=float_convert;
			a++;
		}
		bzero(string_convert_float,15);
		i=0;
		colum_count++;
		continue;

	}
	if(colum_count>2 && file_count>0){

		string_convert_float[i]=ch;
		i++;
	}

	}

}
void menu(char all_games[2000][100],char genre[12][20],char platform[10][20],float float_datas[2000][7]){
	int selection,flag=0,i,j;
	int since_until,since_until_selection,name_number,genre_platform_count;
	int count=0;
	double average=0;
	char game_name[100];
	
	while(flag==0){
		
		printf("\n0: List of the genres\n1: List of the platforms\n2: List of the game through the years\n3: All information of a single game\n4: Avarage of the user Score\n");
		printf("5: Georographical information of a single game\n6: Frequence of the genres\n7: Frequence of the platform\n8: Exit");
		printf("\n\nPlease select an operation:");
		scanf("%d",&selection);
		
		switch(selection){
			case 0: 
				printf("\n");
				for (int i = 0; i <12; ++i){
					printf("%s\n",genre[i]);
				}
				break;
			
			case 1:
				printf("\n");
				for (int i = 0; i <10; ++i){
					printf("%s\n",platform[i]);
				}
				break;
			case 2:
				count=0;
				
				printf("Enter a year:");
				scanf("%d",&since_until);
				
				printf("Until (0) or Since (1) %d:\n",since_until);
				scanf("%d",&since_until_selection);

				for (int i = 0; i <2000; ++i)
				{
					if(since_until_selection==0){
						if(float_datas[i][2]<since_until){
							printf("%s\n",all_games[i]);
							count++;
						}
						
						if(i==1999 && count==0){
							printf("PLEASE TRY AGAIN\n");
						}
					}
					
					else if(since_until_selection==1){
						if (float_datas[i][2]>=since_until){
							printf("%s\n",all_games[i]);
							count++;
						}
						if(i==1999 && count==0){
							printf("PLEASE TRY AGAIN\n");
						}
					}
					else{
						printf("PLEASE TRY AGAİN");
						break;
					}
				}

				break;
			case 3:
				
				printf("Please enter the name of the game\n");
				scanf("%s",game_name);
				
				/*firstly I found the game's indices*/
				for(i=0;i<2000;i++){
					if(strcmp(game_name,all_games[i])==0){
						break;
					}
				}
				
				printf("Name: %s\n",all_games[i]);
				
				name_number=float_datas[i][0];
				printf("Genre: %s\n",genre[name_number]);
				
				name_number=float_datas[i][1];
				printf("Platform: %s\n",platform[name_number]);
				
				printf("Year: %.0f\n",float_datas[i][2]);
				printf("Sales IN NA: %f\n",float_datas[i][3]);
				printf("Sales IN EU: %f\n",float_datas[i][4]);
				
				if(float_datas[i][5]==0){
					printf("TOTAL SALES: Not avaliable\n");
				}
				
				else{
					printf("TOTAL SALES: %f\n",float_datas[i][5]);
				}
				
				printf("User score: %f\n",float_datas[i][6]);
				break;
			
			case 4:
				average=0;
				
				for(i=0;i<2000;i++){
					average+=float_datas[i][6];
				}
				average=(average/2000);
				printf("Average:%lf\n",average);
				break;
			
			case 5:
				printf("Please enter the name of the game\n");
				scanf("%s",game_name);
				/*firstly I found the game's indices*/
				for(i=0;i<2000;i++){
					if(strcmp(game_name,all_games[i])==0){
						break;
					}
				}
			
				if(float_datas[i][3]>float_datas[i][4]){
					printf("This game was more popular in North America\n");
				}
				
				else{
					printf("This game was more popular in Europe\n");
				}
				break;
			
			case 6:
				for(i=0;i<12;i++){
					genre_platform_count=0;
					
					for(j=0;j<2000;j++){
						
						if(float_datas[j][0]==i){
							genre_platform_count++;
						}
					}
					printf("%s  %d\n",genre[i],genre_platform_count);
				}
			break;
			
			case 7:

				for(i=0;i<10;i++){
					genre_platform_count=0;

					for(j=0;j<2000;j++){
						
						if(float_datas[j][1]==i){
							genre_platform_count++;
						}
					}
					printf("%s  %d\n",platform[i],genre_platform_count);
				}
				break;

			case 8: flag=1;
				break;	
			
			default: printf("PLEASE TRY AGAİN\n");
		}

	}

}