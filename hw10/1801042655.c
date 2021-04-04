#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct points{
	char name[5];
	double x;
	double y;
};
struct lines{
	char name[6];
	struct points line_2[2];
	
};
struct plygon_p{
	char name[5];
	int number_of_components;
	struct points polygon_2[20];

};
struct plygon_l{
	char name[5];
	int number_of_components;
	struct lines polygon_3[20];
	
};
/*this function stores information in array*/
void informaiton_store_array(char all_information[500][100]);

/*this function stored point in struct*/
void point_stored(char all_information[500][100],struct points point[100],struct lines line[100],int *count_L_P,int *count_L_Pg,int *count_P_Pg,struct plygon_p p_plygon[100],
																																				 struct plygon_l l_plygon[100]);
/*this function stored line and polygon in struct*/
void line_polygon_stored(char all_information[500][100],struct points point[100],int count,struct lines line[100],int *count_L_P,int *count_L_Pg,int *count_P_Pg,struct plygon_p p_plygon[100],
																																				 				 struct plygon_l l_plygon[100]);
/*this function read actions*/
void actions_read(char all_information[500][100],struct points point[100],
												struct lines line[100],
												struct plygon_p p_plygon[100],
												struct plygon_l l_plygon[100]);

/*this function, file writing operations and calculations*/
void action_write(char all_information[500][100],char actions_word[3][25],struct points point[100],struct lines line[100],struct plygon_p p_plygon[100],struct plygon_l l_plygon[100]);

void main(){
	int i;
	int count_L_P=0;
	char all_information[500][100];
	int count_L_Pg=0,count_P_Pg=0;
	struct points point[100];
	struct lines line[100];
	struct plygon_p p_plygon[100];
	struct plygon_l l_plygon[100];

	for(i=0;i<500;i++){
		all_information[i][0]='\0';
	}	
	
	informaiton_store_array(all_information);	
	point_stored(all_information,point,line,&count_L_P,&count_L_Pg,&count_P_Pg,p_plygon,l_plygon);
	actions_read(all_information,point,line,p_plygon,l_plygon);
}

void informaiton_store_array(char all_information[500][100]){
	char ch;
	int i=0,j=0,k;
	int flag=1;
	FILE *fp;
	fp=fopen("commands.txt","r");
	while(!feof(fp)){
		fscanf(fp,"%c",&ch);
		if(ch=='\n'){
			all_information[i][j-1]='\0';
			i++;
			j=0;
			continue;
		}
		else{
			all_information[i][j]=ch;
		}
		j++;

	}
	for(i=0;i<500;i++){
		for(j=0;j<100;j++){
			k=j;
			if(all_information[i][j]=='/'){
				while(flag==1){

					if(all_information[i][k-1]==' '||all_information[i][k-1]=='	'){
						all_information[i][k-1]='\0';
						k--;
					}
					else{
						flag=0;
					}
				}
				flag=1;

			}
		}
	}
	fclose(fp);

}
void point_stored(char all_information[500][100],struct points point[100],struct lines line[100],int *count_L_P,int *count_L_Pg,int *count_P_Pg,struct plygon_p p_plygon[100],
																																				 struct plygon_l l_plygon[100]){
	const char space[1] = " ";
	char *p;	
	int i=2,k;
	int j=0;
	int count=0;
	int t;
	char* number_translation;
    int data_number;
  	double x_,y_;
  	char component_process[3][5];
  	
  	/*finding the data and determining the number under the data*/
	for(i=0;i<500;i++){
		if(strcmp(all_information[i],"data")==0){
			data_number=strtod (all_information[i+1], &number_translation);
			break;
		}
	}	
	count=i+2;
	while(count<data_number+i+2){
		/*point is determined and stored in the structure.It is separated into words with strtok function*/
		if(all_information[count][0]=='-'|| all_information[count][0]==' ' || all_information[count][0]<='9' && all_information[count][0]>='0'){ 
			
			p= strtok(all_information[count],space);		
			k=0;
			while(p!=NULL){
				
				strcpy(component_process[k],p);
				p=strtok(NULL,space);
				
				if(k==0){
					x_ = atof(component_process[0]);
					point[j].x=x_;
				}
				else if(k==1){
					y_ = atof (component_process[1]);
					point[j].y=y_;
				}
				else{
					strcpy(point[j].name,component_process[2]);
				}
				k++;
			}
			j++;

		}
		/*line and polygon stored in struct*/
		else{
			line_polygon_stored(all_information,point,count,line,count_L_P,count_L_Pg,count_P_Pg,p_plygon,l_plygon);
		
		}
		
		count++;
	}

}
void line_polygon_stored(char all_information[500][100],struct points point[100],int count,struct lines line[100],int *count_L_P,int *count_L_Pg,int *count_P_Pg,struct plygon_p p_plygon[100],
																																				 				 struct plygon_l l_plygon[100]){
	int i;
	int j=0;
	int word_count=0;
	
	char commands[21][5];
	for(i=0;i<21;i++){
		commands[i][0]='\0';
	}
	
	/*sentence is divided into words and stored in the command array*/
	const char space[1] = " ";
	char *p;  
	p= strtok(all_information[count],space);	
	i=0;
	while(p!=NULL){
		
		strcpy(commands[i],p);
		p=strtok(NULL,space);
		i++;
	}
	/*how many words are there*/
	for (i = 0;commands[i][0]!='\0'; ++i)
	{
		word_count++;
	}
	
	/*if it is 3 words this is the line and stored struct*/
	if(word_count==3){
		strcpy(line[*count_L_P].name,commands[2]);
		for(i=0;i<2;i++){
			for(j=0;j<100;j++){
				if(strcmp(commands[i],point[j].name)==0){
					line[*count_L_P].line_2[i]=point[j];
				}
			}
		}
		(*count_L_P)++;
		
	}
	
	/*If more than 3, this is polygon and stored struct*/
	else{
		if(commands[0][0]=='L'){
			strcpy(l_plygon[*count_L_Pg].name,commands[word_count-1]);
			l_plygon[*count_L_Pg].number_of_components=word_count-1;
			for(i=0;i<word_count-1;i++){
				for(j=0;j<100;j++){
					if(strcmp(commands[i],line[j].name)==0){
						l_plygon[*count_L_Pg].polygon_3[i]=line[j];

					}
				}
				
			}
			(*count_L_Pg)++;

		}
		else{
			strcpy(p_plygon[*count_P_Pg].name,commands[word_count-1]);
			p_plygon[*count_P_Pg].number_of_components=word_count-1;
			for(i=0;i<word_count-1;i++){
				for(j=0;j<100;j++){
					if(strcmp(commands[i],point[j].name)==0){
						p_plygon[*count_P_Pg].polygon_2[i]=point[j];

					}
				}
				
			}
			(*count_P_Pg)++;	

		}

	}
}
void actions_read(char all_information[500][100],struct points point[100],
												struct lines line[100],
												struct plygon_p p_plygon[100],
												struct plygon_l l_plygon[100]){
	

	int i=0,j=0;
	int action_number,starting_point_action;
	char actions_word[3][25];
	const char space[1] = " ";
	char *p;
	
	/*finding action */
	while(strcmp(all_information[i],"actions")!=0){
		i++;
	}
	
	starting_point_action=i+3;
	action_number=atof(all_information[i+2]);
	
	/*Printing to the file according to the number under action*/
	for(i=starting_point_action; i<starting_point_action+action_number ;i++){
		
		p= strtok(all_information[i],space);
		while(p!=NULL){
			
			strcpy(actions_word[j],p);
			p=strtok(NULL,space);
			j++;
		}
		/*action procedures are done*/
		action_write(all_information,actions_word,point,line,p_plygon,l_plygon);

		j=0;
	}

}
void action_write(char all_information[500][100],char actions_word[3][25],struct points point[100],struct lines line[100],struct plygon_p p_plygon[100],struct plygon_l l_plygon[100]){
	int i,j,txt_name;
	double x[2],y[2];
	double result=0;
	double a,b,c;
	double length_1,length_2;
	/*determining the name of the file to be written*/
	for(i=0;i<500;i++){
		if(strcmp(all_information[i],"actions")==0){
			break;
		}
	}
	txt_name=i+1;

	FILE *fp;
	fp=fopen(all_information[txt_name],"a+");
	/*analytical formulas are applied for all processes*/
	if(strcmp(actions_word[0],"Distance")==0){
		if(actions_word[1][0]=='P'&&actions_word[2][0]=='P'){
			
			for(i=0;i<100;i++){
				if(strcmp(actions_word[1],point[i].name)==0){
					x[0]=point[i].x;
					y[0]=point[i].y;
				}
				if(strcmp(actions_word[2],point[i].name)==0){
					x[1]=point[i].x;
					y[1]=point[i].y;
				}
			}
			result=sqrt(pow((x[0]-x[1]),2)+pow((y[0]-y[1]),2));
		}
		else{
			for(i=0;i<100;i++){
				if(strcmp(actions_word[1],line[i].name)==0 || strcmp(actions_word[2],line[i].name)==0){
					x[0]=line[i].line_2[0].x;
					x[1]=line[i].line_2[1].x;
					y[0]=line[i].line_2[0].y;
					y[1]=line[i].line_2[1].y;
					
					a=(y[1]-y[0]);
					b=-(x[1]-x[0]);
					c=-a*x[1]-b*y[1];
				}
			}
			for(i=0;i<100;i++){
				if(strcmp(actions_word[1],point[i].name)==0 || strcmp(actions_word[2],point[i].name)==0){
					x[0]=point[i].x;
					y[0]=point[i].y;					
				}
			}
			
			result=(a*x[0])+(b*y[0])+c;
			result=result/sqrt(pow(x[0],2)+pow(y[0],2));
		}
		fprintf(fp,"Distance(%s,%s)=%.1lf\n",actions_word[1],actions_word[2],result);
	}
	
	if(strcmp(actions_word[0],"Angle")==0){
		
		for(i=0;i<100;i++){
			if(strcmp(actions_word[1],line[i].name)==0){
				
				x[0]=fabs(line[i].line_2[0].x-line[i].line_2[1].x);
				y[0]=fabs(line[i].line_2[0].y-line[i].line_2[1].y);
				length_1=sqrt(pow(line[i].line_2[0].x-line[i].line_2[1].x,2)+pow(line[i].line_2[0].y-line[i].line_2[1].y,2));
			
			}
			if(strcmp(actions_word[2],line[i].name)==0){
				
				x[1]=fabs(line[i].line_2[0].x-line[i].line_2[1].x);
				y[1]=(line[i].line_2[0].y-line[i].line_2[1].y);
				length_2=sqrt(pow(line[i].line_2[0].x-line[i].line_2[1].x,2)+pow(line[i].line_2[0].y-line[i].line_2[1].y,2));	
			}
		}
		result=(x[0]*x[1]+y[0]*y[1])/(length_1*length_2);
		result=acos(result)*(180/3.1415);

		fprintf(fp,"Angle(%s,%s)=%.1lf\n",actions_word[1],actions_word[2],result);
	}
	
	if(strcmp(actions_word[0],"Length")==0){
		for(i=0;i<100;i++){
			
			if(strcmp(actions_word[1],line[i].name)==0){
				
				x[0]=line[i].line_2[0].x;
				x[1]=line[i].line_2[1].x;
				y[0]=line[i].line_2[0].y;
				y[1]=line[i].line_2[1].y;
				result=sqrt(pow((x[0]-x[1]),2)+pow((y[0]-y[1]),2));
			}
			
			if(strcmp(actions_word[1],l_plygon[i].name)==0){
				for(j=0;j<l_plygon[i].number_of_components;j++){
					
					x[0]=l_plygon[i].polygon_3[j].line_2[0].x;
					x[1]=l_plygon[i].polygon_3[j].line_2[1].x;
					y[0]=l_plygon[i].polygon_3[j].line_2[0].y;
					y[1]=l_plygon[i].polygon_3[j].line_2[1].y;
					result=sqrt(pow((x[0]-x[1]),2)+pow((y[0]-y[1]),2))+result;
				}
			}
			
			if(strcmp(actions_word[1],p_plygon[i].name)==0){				
				for(j=0;j<p_plygon[i].number_of_components-1;j++){	
					
					x[0]=p_plygon[i].polygon_2[j].x;
					x[1]=p_plygon[i].polygon_2[j+1].x;
					y[0]=p_plygon[i].polygon_2[j].y;
					y[1]=p_plygon[i].polygon_2[j+1].y;
					result=sqrt(pow((x[0]-x[1]),2)+pow((y[0]-y[1]),2))+result;
				}
					x[0]=p_plygon[i].polygon_2[0].x;
					x[1]=p_plygon[i].polygon_2[j].x;
					y[0]=p_plygon[i].polygon_2[0].y;
					y[1]=p_plygon[i].polygon_2[j].y;
					result=sqrt(pow((x[0]-x[1]),2)+pow((y[0]-y[1]),2))+result;
			}

		}
		fprintf(fp,"Length(%s)=%.1lf\n",actions_word[1],result);
	}
	
	if(strcmp(actions_word[0],"Area")==0){
		for(i=0;i<100;i++){
			
			if(strcmp(actions_word[1],p_plygon[i].name)==0){
				for(j=0;j<p_plygon[i].number_of_components-1;j++){
					result=p_plygon[i].polygon_2[j].x*p_plygon[i].polygon_2[j+1].y - p_plygon[i].polygon_2[j].y*p_plygon[i].polygon_2[j+1].x+result;
					
				}
				result=p_plygon[i].polygon_2[j].x*p_plygon[i].polygon_2[0].y - p_plygon[i].polygon_2[j].y*p_plygon[i].polygon_2[0].x+result;
			}			
			
			if(strcmp(actions_word[1],l_plygon[i].name)==0){
				for(j=0;j<l_plygon[i].number_of_components;j++){
					result=l_plygon[i].polygon_3[j].line_2[0].x*l_plygon[i].polygon_3[j].line_2[1].y - l_plygon[i].polygon_3[j].line_2[0].y*l_plygon[i].polygon_3[j].line_2[1].x+result;					
				}
			}
		}
		result=fabs(result/2);
		fprintf(fp,"Area(%s)=%.1lf\n",actions_word[1],result);
	}
	fclose(fp);

}
