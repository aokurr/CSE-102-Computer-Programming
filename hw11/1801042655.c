#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define LNGTH 1000000

typedef struct n{
	int x;
	struct n *next;
}node;

struct diffirence{
	int n1;
	int n2;
};
/*PART 1*/
/*DİNAMİK İNT ARRAYE VERİLER DEPOLANIR VE RETURN EDİLİR*/
int *read_array(char *filename,int *array,int *count_d);
/*LİNKED LİSTE VERİLER DEPOLANIR VE MAİNDE RETURN EDİLİR*/
node *read_linkedlist(char *filename,node *root);

/*İKİ FONKSİYONDA DİNAMİK FLOAT ARRAYE İSTENEN DEĞERLERİ KAYDEDER VE FLOAT ARRAYLER MAİNE RETURN EDİLİR*/
float * stats_array(int *array,float *array_values);
float * stats_linkedlist(node *root,float *linked_values);

/*PART 2*/
/*BU FONKSİYONDA KULLANICIDAN ALDIĞIM DEĞERLERİ LİNNKLİSTE DEPOLADIM VE MAİNDE RETURN ETTİM*/
node *part2_linkedlist(node *root);

/*BU FONKSİYONDA KULLANICIDAN ALDIĞIM DEĞERLERİ DİNAMİK ARRAYE DEPOLADIM VE MAİNE RETURN ETTİM*/
int *part2_array(int *array);

/*BU FONKSİYONDA KULLANICADAN ALINAN DİNAMİK ARRAY VE LİNKED LİSTTEKİ BİRBİRİNE KARŞILIK DEĞERLERİ FARKLIYSA DİNAMİK STRUCT ARREYE DEPOLADIM VE MAİNE RETURN ETTİM*/
struct diffirence *diffirence_part2(struct diffirence *diff,node *root,int *array);

void main(){
	node *root;
	int *array,count_d=0,count_l=0;
	int i;
	char filename[]="list.txt";
	
	clock_t start, end;
	double cpu_time_used_read=0,cpu_time_used_stats=0;
	
	/*HESAPLAMALAR İÇİN GEREKLİ FLOAT ARRAY TANIMI*/
	float *array_values,*linked_values;

	int *array_part2;
	/*DİNAMİK STRUCT ARRAYİMİZ*/
	struct diffirence *diff;
	
	array=read_array(filename,array,&count_d);
	root=read_linkedlist(filename,root);
	
	array_values=stats_array(array,array_values);
	linked_values=stats_linkedlist(root,linked_values);
	
	printf("*************PART 1***********\n\n");
	printf("*****ARRAY******\nNUMBER OF BYETE USED=%d(including -1)\nMIN NUMBER=%f\nMAX NUMBER=%f\nMEAN=%f\nSTD=%f",(count_d+1)*4,array_values[0],array_values[1],array_values[2],array_values[3]);
	printf("\n\n*****LİNKEDLİST******\nNUMBER OF BYETE USED=%d\nMIN NUMBER=%f\nMAX NUMBER=%f\nMEAN=%f\nSTD=%f\n",count_d*(4+4),linked_values[0],linked_values[1],linked_values[2],linked_values[3]);
	
	/*BU 2 DÖNGÜDE SÜRELER HESAPLANIR*/
	for(i=0;i<4;i++){
		start = clock();
		read_array(filename,array,&count_d);
		end=clock();
		cpu_time_used_read=(((double) (end - start)) / CLOCKS_PER_SEC)+cpu_time_used_read;

		start = clock();
		stats_array(array,array_values);
		end=clock();
		cpu_time_used_stats = (((double) (end - start)) / CLOCKS_PER_SEC)+cpu_time_used_stats;

	}
	printf("\n\nAverage processing time (4 time) (*read_array)=%lf\nAverage processing time (4 time) (*stats_array)%lf\n",cpu_time_used_read/4,cpu_time_used_stats/4);
	
	for(i=0;i<4;i++){
		start = clock();
		read_linkedlist(filename,root);
		end=clock();
		cpu_time_used_read=(((double) (end - start)) / CLOCKS_PER_SEC)+cpu_time_used_read;

		start = clock();
		stats_linkedlist(root,linked_values);
		end=clock();
		cpu_time_used_stats = (((double) (end - start)) / CLOCKS_PER_SEC)+cpu_time_used_stats;

	}
	printf("\n\nAverage processing time (4 time) (*read_linkedlist)=%lf\nAverage processing time (4 time) (*stats_linkedlist)%lf\n",cpu_time_used_read/4,cpu_time_used_stats/4);

	printf("\n");


/**************PART2*************/
	printf("********PART 2 ************\n");
	printf("PLEASE ENTER SAME LENGTH!!!!\n");
	
	free(array);
	array=part2_array(array);
	
	printf("\n\n");
	
	free(root);
	root=part2_linkedlist(root);

	diff=diffirence_part2(diff,root,array);
	
	free(array);
	free(root);
	printf("\n");
	
	for(i=0;diff[i].n1!=-1;i++){
		printf("%d to diffirent %d\n",diff[i].n1,diff[i].n2);
	}
	free(diff);
	
}

int *read_array(char *filename,int *array,int *count_d){
	char file_information[LNGTH];
	char ch;
	char *str;
	int i=0;
	
	FILE *fp;
	fp=fopen(filename,"r");
	fgets(file_information,LNGTH,fp);
	fclose(fp);
	
	array=malloc(sizeof(int));
	array[i]=strtol(file_information,&str,10);
	
	while(*(str+1)!='\0'){
		i++;
		array=realloc(array,(i+1)*sizeof(int));
		array[i]=strtol((str+1),&str,10);
	}
	array=realloc(array,(i+1)*sizeof(int));
	array[i+1]=-1;
	*count_d=i+1;

	return array;
}
node *read_linkedlist(char *filename,node *root){

	char file_information[LNGTH];
	char ch;
	char *str;
	node *iter;
	FILE *fp;
	fp=fopen(filename,"r");
	fgets(file_information,LNGTH,fp);
	fclose(fp);
		
	root=malloc(sizeof(node));
	root->x=strtol(file_information,&str,10);
	root->next=NULL;
	iter=root;
	while(*(str+1)!='\0'){
			
		root->next=malloc(sizeof(node));
		root=root->next;
		root->x=strtol(str+1,&str,10);
		root->next=NULL;



	}
	return iter;
}

float * stats_array(int *array,float *array_values){
	int i;
	array_values=malloc(sizeof(float)*4);
	/*min number*/
	array_values[0]=array[0];
	/*max number*/
	array_values[1]=array[0];
	/*mean value*/
	array_values[2]=0;
	/*std value*/
	array_values[3]=0;
	
	for (i=0;array[i]!=-1; ++i){
		
		if(array_values[0]>array[i]){
			array_values[0]=array[i];
		}
		if(array_values[1]<array[i]){
			array_values[1]=array[i];
		}
		
		array_values[2]=array[i]+array_values[2];
	}

	array_values[2]=array_values[2]/(i);
	for (i = 0;array[i]!=-1 ;++i){	
		array_values[3]=((array[i]-array_values[2])*(array[i]-array_values[2]))+array_values[3];
	}
	array_values[3]=array_values[3]/(i-1);
	array_values[3]=sqrt(array_values[3]);
	return array_values;

}

float * stats_linkedlist(node *root,float *linked_values){
	int i=0;
	linked_values=malloc(sizeof(float)*4);
	
	/*min number*/
	linked_values[0]=root->x;
	/*max number*/
	linked_values[1]=root->x;
	/*mean value*/
	linked_values[2]=0;
	/*std value*/
	linked_values[3]=0;

	node *iter;
	iter=root;
	while(iter!=NULL){
		i++;
		if(linked_values[0] > iter->x){
			linked_values[0]=iter->x;
		}
		if(linked_values[1] < iter->x){
			linked_values[1]=iter->x;
		}
		linked_values[2]=iter->x+linked_values[2];
		iter=iter->next;
	}
	linked_values[2]=linked_values[2]/i;
	
	iter=root;
	while(iter!=NULL){
		linked_values[3]=(iter->x - linked_values[2])*(iter->x - linked_values[2])+linked_values[3];
		iter=iter->next;
	}
	linked_values[3]=linked_values[3]/(i-1);
	linked_values[3]=sqrt(linked_values[3]);

	return linked_values;


}
int *part2_array(int *array){
	int i=1;
	printf("\nPART 2 DYNMICAL ARRAY\n\n");
	printf("please enter %d.number\n",i);
	array=malloc(sizeof(int));
	scanf("%d",&array[0]);
	while(1){
		printf("please enter %d.number (for exit please enter '-1')\n",i+1);
		array=realloc(array,(i+1)*sizeof(int));
		scanf("%d",&array[i]);
		//i++;
		if(array[i]==-1){
			
			break;
		}
		i++;
	}
	return array;

}
node *part2_linkedlist(node *root){
	int i=1;
	node* iter;
	root=malloc(sizeof(node));
	iter=root;
	
	printf("PART 2 LINKEDLIST\n\n");
	printf("please enter %d.number\n",i);
	scanf("%d",&root->x);
	
	while(1){
		i++;
		printf("please enter %d.number\n",i);
		
		root->next=malloc(sizeof(node));
		root=root->next;
		root->next=NULL;
		scanf("%d",&root->x);
		
		if(root->x==-1){
			break;
		}
	}
	return iter;
}
struct diffirence *diffirence_part2(struct diffirence *diff,node *root,int *array){
	int i=0;
	int j=0;
	node *iter;
	
	printf("\nDYNMICAL ARRAY={");
	
	while(array[i]!=-1){
		
		printf("%d",array[i]);
		if(array[i+1]!=-1){
			printf(",");
		}
		i++;
	}
	
	printf("}\n");
	printf("\nLINKEDLIST={");
	
	while(iter->x!=-1){
		printf("%d",iter->x);
		if(iter->next->x!=-1){
			printf(",");
		}
		iter=iter->next;
	}
	printf("}\n");
	
	i=0;
	diff=malloc(sizeof(struct diffirence));
	while(array[i]!=-1){
		if(array[i]!=root->x){
			diff[j].n1=array[i];
			diff[j].n2=root->x;
			j++;
			diff=realloc(diff,(j+1)*sizeof(struct diffirence));
		}
		i++;
		root=root->next;
	}
	diff[j].n1=-1;
	
	return diff;

}