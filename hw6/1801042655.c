#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ROW 20
#define COLLUM 20
		/*
GEBZE TECHNICAL UNIVERSITY
	CSE 102 HOMEWORK 6
	AUTHOR:AHMET OKUR 
	NUMBER:1801042655
					*/


/*this function returns random character*/
void random_character(char *array);

/*this func. print array*/
void read_array(char array[ROW][COLLUM]);

/*random number generation control*/
int diffirent_words_control(int x,int array[10]);

/*generates random direction*/
int random_direction(int word_size,int column,int row);

/*checks for overlaps and intersections*/
int direction_intersection_control(int column,int row,int direction,int word_size,int column_row_memory[20][20]);

/*prints words and stores their location*/
void direction_storage_and_print(int column_row_memory[20][20],int direction, int word_size,int column,int row,char puzzle[ROW][COLLUM],char word[15]);

/*the program determines the direction of the word with the information received from the user and prints words in capital letters*/
int program_direction_determine(int row_user,int column_user,char word_user[15],int word_size,char puzzle[ROW][COLLUM]);

/*prints the above words in capital letters*/
void top_words_change(char random_words[10][15],char word_user[15]);

int main(){

	srand(time(NULL));
	char puzzle[ROW][COLLUM];/*MY PUZZLE*/
	char words[100][100];/*ALL WORDS*/
	char random_words[10][15];/*RANDOM WORDS*/
	int i,j,k=0,c,words_number[10],random_number_out,strlen_control,word_size;
	int column_row_memory[20][20];/*PUZZLE LOCATİON İF FULL column_row_memory[İ][J]->1 İF EMPTY column_row_memory[İ][J]->0*/
	int column,row;
	int direction,flag,flag_2;
	char word[15];
	
	int column_user;
	char row_user;
	char word_user[15];
	
	/*Storing the letters of the puzzle with 1 and 0*/
	for(i=0;i<20;i++){
		for (j=0;j<20;j++)
		{
			column_row_memory[i][j]=0;
		}
	}
	
	/*transfer of all words to one dimensional string array*/
	i=0;
	FILE *fp;
	fp=fopen("words.txt","r");
	while(!feof(fp)){
		fgets(words[k],15,fp);
		k++;
	}
	fclose(fp);
	
	/*Generating 10 random numbers from 1 to 100*/
	while(i<10){
		c=rand()%99;
		if(diffirent_words_control(c,words_number)==1){
			/*10 random numbers stored*/
			words_number[i]=c;
			i++;
		}
	}
	/*random numbers chose words*/
	for(i=0;i<10;i++){
		random_number_out=words_number[i];
		strcpy(random_words[i],words[random_number_out]);
		strlen_control=strlen(random_words[i]);
		random_words[i][strlen_control-2]='\0';
	}

	/*print a completely random character on the puzzle*/	
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			random_character(&puzzle[i][j]);
						
		}
	}
	/*word locations, conflict status and printing*/
	for(i=0;i<10;i++){
		flag=0;
		while(flag==0){
			/*starting point of the word*/
			column=rand()%20;
			row=rand()%20;
			/*random direction of the word*/
			direction=random_direction(strlen(random_words[i]),column,row);
			/*intersection control*/
			flag=direction_intersection_control(column,row,direction,strlen(random_words[i]),column_row_memory);
				/*if everything is ok it will be printed*/
				if(flag==1){
					
					/*if you want to all words Location please open comment*/
					//printf("row=%c column=%d word=%s\n",row+65,column,random_words[i]);
					
					/*Words are printed in puzzl.Places are stored in column_row_memory*/
					strcpy(word,random_words[i]);
					direction_storage_and_print(column_row_memory,direction,strlen(random_words[i]),column,row,puzzle,word);
				}
		}
	}

	i=0;
	flag=0;
	/*user operations*/
	flag_2=1;
	while (flag_2==1){

		
		for (j= 0; j < 11; j++){
			printf("%s\t",random_words[j]);
		}
		
		printf("\n\n");
		read_array(puzzle);
		printf("\nplease enter the coordinate and the word forex:(B5 random)\n");
		
		scanf("%c%d%s",&row_user,&column_user,word_user);
		
		row_user-=65;
		(int)row_user;
	 	flag=0;
	 	/*program _ direction _ determine also finds the program direction  and here the words are written in capital letters*/
	    flag=program_direction_determine(row_user,column_user,word_user,strlen(word_user),puzzle);
	    

	   if(row_user=='('){

	    	flag_2=0;
	    	system("clear");
	    	for (j= 0; j < 11; j++){
				printf("%s\t",random_words[j]);
			}
		
			printf("\n\n");
			read_array(puzzle);
	    }
	    
	    if(flag==1){
	    	i++;
	    	/*capitalizing the above words*/
	    	top_words_change(random_words,word_user);

	    }
	    else if(flag!=1 && flag_2==1) {

	    	printf("INCORRET ENTRY,PLEASE TRY AGAİN\n");

	    }
	    if (i==10){
			flag_2=0;
			
			for (j= 0; j < 11; j++){
				printf("%s\t",random_words[j]);
			}
		
		printf("\n\n");
		read_array(puzzle);
	    }
	 	
	 	if(i!=10){
	 		system("clear");
	 	}
	}

printf("EXİSTİNG...\n");

return 0;
}
void random_character(char *array){
	char ch;
	ch=rand()%25+97;
	*array=ch;
	
}

void read_array(char array[ROW][COLLUM]){
	int i,j;
	printf(" ");
	for(i=0;i<10;i++){
		printf("  %d",i);
	}
	
	for(i=10;i<20;i++){
		printf(" %d",i);
	}

	printf("\n");
	for(i=0;i<20;i++){
		printf("%c) ",i+65);
			
		for(j=0;j<20;j++){
			printf("%c ",array[i][j]);
			printf(" ");
		}
		printf("\n\n");
	}
}


int diffirent_words_control(int x,int array[10]){
	for(int i=0;i<10;i++){
		if(x==array[i]){
			return 0;
		}
	}
	return 1;
}
int random_direction(int word_size,int column,int row){
	int flag=0,direction;
	while(1){
	
		direction=rand()%8;
		if(direction==0){ /*East*/
			if((20-column)>word_size){
				return 0;
			}

		}
		
		else if(direction==1){ /*West*/
			if(column>word_size){
				return 1;
			}
		}
		
		else if(direction==2){ /*North*/
			if(row>word_size){	
			return 2;	
			}
		}
		
		else if(direction==3){ /*South*/
			if(20-row>word_size){	
				return 3;
			}
		}
		
		else if(direction==4){ /*northwest*/
			if(column>word_size && row>word_size){		
				return 4;
			}
		}
		
		else if(direction==5){ /*northeast*/
			if(20-column>word_size && row>word_size){		
				return 5;
			}
		}
		
		else if(direction==6){ /*South West*/
			if(column>word_size&&20-row>word_size){		
				return 6;
			}
		}
		
		else if(direction==7){ /*south east*/
			if(20-column>word_size && 20-row>word_size){			
				return 7;
			}
		}
	
	}

}

int direction_intersection_control(int column,int row,int direction,int word_size,int column_row_memory[20][20]){
	int i,j;
	int column_2=column,row_2=row;
	if(direction==0){/*East*/
		i=row;
		j=column;

		for (j;j<column+word_size;j++){
			if(column_row_memory[i][j]==1){
				return 0;
			}
		}
	}
	if(direction==1){/*West*/
		i=row;
		j=column;
		for (j;j>column-word_size;j--){
			if(column_row_memory[i][j]==1){
				return 0;
			}
		}
	}
	if(direction==2){/*North*/
		i=row;
		j=column;
		for (i;i>row-word_size;i--){
			if(column_row_memory[i][j]==1){
				return 0;
			}
		}
	}
	if(direction==3){/*South*/
		i=row;
		j=column;
		for (i;i<row+word_size;i++){
			if(column_row_memory[i][j]==1){
				return 0;
			}
		}
	}
	if(direction==4){/*northwest*/
		i=row;
		j=column;
		for (i;i>row-word_size;i--){
			if(column_row_memory[i][j]==1){
				return 0;
			}
			j--;
		}
	}
	if(direction==5){/*northeast*/
		i=row;
		j=column;
		for (i;i>row-word_size;i--){
			if(column_row_memory[i][j]==1){
				return 0;
			}
			j++;
		}
	}
	if(direction==6){/*SouthWest*/
		i=row;
		j=column;
		for (i;i<row+word_size;i++){
			if(column_row_memory[i][j]==1){
				return 0;
			}
			j--;
		}
	}
	if(direction==7){/*southeast*/
		i=row;
		j=column;
		for (i;i<row+word_size;i++){			
			if(column_row_memory[i][j]==1){
				return 0;
			}
			j++;
		}
	}
		
	return 1;
}
void direction_storage_and_print(int column_row_memory[20][20],int direction, int word_size,int column,int row,char puzzle[ROW][COLLUM],char word[15]){
	int i,j,k=0;
	if(direction==0){/*East*/
		i=row;
		j=column;
		for (j;j<column+word_size;j++)
		{
			column_row_memory[i][j]=1;
			puzzle[i][j]=word[k];
			
			k++;
		}
	}
	if(direction==1){/*West*/
		i=row;
		j=column;
		for (j;j>column-word_size;j--)
		{
			column_row_memory[i][j]=1;
			puzzle[i][j]=word[k];
			
			k++;
		}
	}
	if(direction==2){/*North*/
		i=row;
		j=column;
		for (i;i>row-word_size;i--)
		{
			column_row_memory[i][j]=1;
			puzzle[i][j]=word[k];
			
			k++;
		}
	}
	if(direction==3){/*South*/
		i=row;
		j=column;
		for (i;i<row+word_size;i++)
		{
			column_row_memory[i][j]=1;
			puzzle[i][j]=word[k];
			
			k++;
		}
	}

	if(direction==4){/*northwest*/
		i=row;
		j=column;
		for (i;i>row-word_size;i--)
		{
			column_row_memory[i][j]=1;
			puzzle[i][j]=word[k];
			
			j--;
			k++;
		}
	}
	if(direction==5){/*northeast*/
		i=row;
		j=column;
		for (i;i>row-word_size;i--)
		{
			column_row_memory[i][j]=1;			
			puzzle[i][j]=word[k];
			
			k++;
			j++;
		}
	}
	if(direction==6){/*SouthWest*/
		i=row;
		j=column;
		for (i;i<row+word_size;i++)
		{
			column_row_memory[i][j]=1;			
			puzzle[i][j]=word[k];
			
			k++;
			j--;
		}
	}
	if(direction==7){/*southeast*/
		i=row;
		j=column;
		for (i;i<row+word_size;i++)
		{
			column_row_memory[i][j]=1;
			puzzle[i][j]=word[k];
			
			k++;
			j++;
		}
	}

}
int program_direction_determine(int row_user,int column_user,char word_user[15],int word_size,char puzzle[ROW][COLLUM]){
	int i,j,k,flag;
	flag=0;
		i=row_user;
		j=column_user;
		k=0;
		for (j;j<column_user+word_size;j++)/*East*/
		{
			if(puzzle[i][j]==word_user[k]){
				flag++;

			}

			k++;
		}
		if(flag==word_size){
		
			for (j=column_user;j<column_user+word_size;j++)
			{
				puzzle[i][j]=puzzle[i][j]-32;
				
			}
		return 1;
		}
		
		flag=0;
		i=row_user;
		j=column_user;
		k=0;
		for (j;j>column_user-word_size;j--)/*West*/
		{
			if(puzzle[i][j]==word_user[k]){
				flag++;
			}
			k++;
		}
		if(flag==word_size){
			for (j=column_user;j>column_user-word_size;j--){
				puzzle[i][j]=puzzle[i][j]-32;
			}
			return 1;
		}
		
		flag=0;
		i=row_user;
		j=column_user;
		k=0;
		for (i;i>row_user-word_size;i--)/*North*/
		{
			if(puzzle[i][j]==word_user[k]){
				flag++;
			}
			k++;
		}
		if(flag==word_size){
			for (i=row_user;i>row_user-word_size;i--){
				puzzle[i][j]=puzzle[i][j]-32;
			}
			return 1;
		}
		
		flag=0;
		i=row_user;
		j=column_user;
		k=0;
		for (i;i<row_user+word_size;i++)/*South*/
		{
			if(puzzle[i][j]==word_user[k]){
				flag++;
			}
			k++;
		}
		if(flag==word_size){
			for (i=row_user;i<row_user+word_size;i++){
				puzzle[i][j]=puzzle[i][j]-32;
			}
			return 1;
		}
		
		flag=0;
		i=row_user;
		j=column_user;
		k=0;		
		for (i;i>row_user-word_size;i--)/*northwest*/
		{
			if(puzzle[i][j]==word_user[k]){
				flag++;
			}
			k++;
			j--;
		}
		if(flag==word_size){
			j=column_user;
			for (i=row_user;i>row_user-word_size;i--){
				puzzle[i][j]=puzzle[i][j]-32;
				j--;
			}
			return 1;
		}
		
		flag=0;
		i=row_user;
		j=column_user;
		k=0;		
		for (i;i>row_user-word_size;i--)/*northeast*/
		{
			if(puzzle[i][j]==word_user[k]){
				flag++;
			}
			k++;
			j++;
		}
		if(flag==word_size){
			j=column_user;
			for (i=row_user;i>row_user-word_size;i--){
					puzzle[i][j]=puzzle[i][j]-32;
					j++;
			}
			return 1;
		}
		
		flag=0;
		i=row_user;
		j=column_user;
		k=0;		
		for (i;i<row_user+word_size;i++)/*SouthWest*/
		{
			if(puzzle[i][j]==word_user[k]){
				flag++;
			}
			k++;
			j--;
		}
		if(flag==word_size){
			j=column_user;
			for (i=row_user;i<row_user+word_size;i++){
				puzzle[i][j]=puzzle[i][j]-32;
				j--;
			}
			return 1;
		}
		
		flag=0;
		i=row_user;
		j=column_user;
		k=0;		
		for (i;i<row_user+word_size;i++)/*southeast*/
		{
			if(puzzle[i][j]==word_user[k]){
				flag++;
			}
			k++;
			j++;
		}
		if(flag==word_size){
			j=column_user;
			for (i=row_user;i<row_user+word_size;i++){
				puzzle[i][j]=puzzle[i][j]-32;
				j++;
			}
			return 1;
		}


	return 0;
}

void top_words_change(char random_words[10][15],char word_user[15]){
	int i,j;
	for (i = 0; i < 10; ++i)
	{
		if(strcmp(random_words[i],word_user)== 0){
			for (j= 0; j <strlen(random_words[i]) ; j++){
			
				random_words[i][j]-=32;
			}
		}
	}
}