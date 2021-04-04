#include <stdio.h>
#include <math.h>
/*	GEBZE TECHNİCAL UNIVERSITY 
	CSE 102 HOMEWORK 8
	AUTHOR:AHMET OKUR 1801042655
*/


void part1();
void generate_hofstadters_sequence (int *arr, int n);
int find_max (int arr[], int index, int max_value);
int sum_array (int arr[]);
double std_array (int arr[], double *mean, int n, int index);
void zero_array(int arr[],int n);

void part2();
void arr_zero(int visited[8][8],int x,int y);
void install_pipes (int visited[8][8], int x, int y, int orientation,int *count);

void part3();
char* remove_duplicates (char* str);

void menu();

void main(){
	menu();
}

void menu(){
	int selection;
	int flag=1;
	while(flag==1){	
		printf("\nWelcome to homework 8,please chose one of the parts to continue\n");
		printf("1)Execute part 1 \n2)Execute part 2\n3)Execute part 3\n4)Exit\n");
		scanf("%d",&selection);
		switch (selection){
			case 1:part1();
				break;
			case 2:part2();
				break;
			case 3: part3();
				break;
			case 4:flag=0;
				break;
			default:printf("please try again\n");

		}
	}
}
void part1(){
	int array[500];
	int n;
	int index=1;
	int max_value=-1;
	int sum;
	int selection;
	int flag=1;
	double mean=0;
	int i;
	while(flag==1){
		printf("Please make your choice:\n");
		printf("1)Fill Array\n2)Find Biggest Number\n3)Calculate Sum\n4)Calculate Standard Deviation\n5)Exit\n");
		scanf("%d",&selection);	
		
		switch (selection){
			case 1:
				printf("please enter the range\n");
				scanf("%d",&n);
				generate_hofstadters_sequence (array,n);
				zero_array(array,n);
				break;

			case 2:
				
				max_value=find_max (array,index,max_value);
				printf("\nmax value=%d\n",max_value);
				break;
			
			case 3:
					
					sum=sum_array(array);
					printf("\nsum of numbers=%d\n",sum);
					array[1]=1;
					array[0]=1;
				break;
			case 4:
				mean=0;
				mean=std_array (array,&mean,n,index);
				printf("\nstandard deviation=%lf\n",mean);
				array[1]=1;
				array[0]=1;
				break;
				

			case 5: flag=0;
				break;
			
			default:printf("Please try again\n");
		}
	}
}

void generate_hofstadters_sequence (int *arr, int n){
	/*ilk indise kadar gider sonra geri dönerek işlemleri kaydeder arraye*/
	if(n>1){
		
		generate_hofstadters_sequence(arr,n-1);
		arr[n]=(arr[n-arr[n-1]])+(arr[n-arr[n-2]]);
		
	}
	else{
		arr[0]=1;
		arr[1]=1;
	}
}
void zero_array(int arr[],int n){
	/*arrayin geri kalan kısmını sıfırlama*/
	if(n!=500){
		arr[n]=0;
		n++;
		zero_array(arr,n);
	}
}
int find_max (int arr[], int index, int max_value){
	/*max sayıyı bulma */
	if(index!=500){
		if(arr[index]>max_value){
			
			max_value=arr[index];
	
		}
		find_max (arr,index+1,max_value);
	}
	else{
		
	return max_value;
	}	
	
}

int sum_array (int arr[]){
	/*0ıncı indisi sayaç olarak kullandım 1. indisi toplama yeri*/
	if(arr[0]!=500){
		arr[1]=arr[1]+arr[arr[0]];
		arr[0]++;
		sum_array((arr));
		
	
	}
	else{
		return arr[1];
	}
}

double std_array (int arr[], double *mean, int n, int index){
		/*ilk önce arrayın toplamını aldım*/
		if(index<n){
		arr[0]=arr[0]+arr[index];
		index++;
		std_array (arr,mean,n,index);
		
		index--;
		
		}
		/*burada da standart sapma formulunu uyguladım*/
		if(index<2*n && index>=n){
			
			if(index==n){
				*mean=(((float)(arr[0])/n-arr[1])*((float)(arr[0])/n-arr[1]))+*mean;				
				 
				 std_array (arr,mean,n,index+1);
				
				
			}
			else{
				*mean=(((float)(arr[0])/n-arr[index-n])*((float)(arr[0])/n-arr[index-n]))+*mean;
				
				index++;
				std_array (arr,mean,n,index);
				
			}
		}
		else if(index>=2*n){

			*mean=(float)*mean/(n-1);

			*mean=sqrt(*mean);
			

			return *mean;			
		}					
}



void part2(){
	int visited[8][8];
	int x=0,y=0,i,j;
	int orientation,counter=0;
	int selection;
	arr_zero(visited,x,y);
	visited[0][0]=1;
printf("HOCAM 3 4 SAAT SÜRÜYOR DEVAM ETMEK İÇİN 1 ÇIKMAK İÇİN 0\n");
scanf("%d",&selection);
if(selection==1){
	install_pipes (visited,x,y,orientation,&counter);
	}	
}
/*bu kısımda arrayi sıfıladım*/
void arr_zero(int visited[8][8],int x,int y){
	if(x<8){
		visited[x][y]=0;
		y++;
		
		if(y>7){
			y=0;
			x++;
		}
		arr_zero(visited,x,y);
	}
}
void install_pipes (int visited[8][8], int x, int y, int orientation,int *count){
	int i,j;
	int flag=0;
	int counter=0;
	/*bu array her girilen fonksiyon için yönleri depoluyor*/
	int array[8]={0,0,0,0,0,0,0,0};
	
	if(visited[y][x]<64 && *count<10){

		printf("now(%d,%d)has water",x,y);
		/*1. yönelim*/
		if(x+1<8 && y+2<8 && visited[y+2][x+1]==0 &&  array[0]==0 &&*count<10){
			x=x+1;
			y=y+2;
			visited[y][x]=1+visited[y-2][x-1];
			/*eğer 64 boru da yerleşirse burada çizilecek*/
			if(visited[y][x]>=64){
				(*count)++;
				printf("\n");
				for(i=0;i<8;i++){
					for(j=0;j<8;j++){
						printf("%-3d ",visited[i][j]);
					}
					printf("\n");
				}
			}

				install_pipes (visited,x,y,orientation,count);
			/*geri dönüş sonrası dönülen yeri 0 lama işlemi ve dönülen yeri kaydetme*/	
				if(visited[y][x]<80){
					visited[y][x]=0;
					x=x-1;
					y=y-2;
					array[0]=1;
			}
				
		}
		
		/*2. yönelim*/
		 if(x-2>-1 && y+1<8 && visited[y+1][x-2]==0 &&  array[1]==0&&*count<10){
			x=x-2;
			y=y+1;
			visited[y][x]=1+visited[y-1][x+2];
			/*eğer 64 boru da yerleşirse burada çizilecek*/
			if(visited[y][x]>=64){
				(*count)++;
				printf("\n");
				for(i=0;i<8;i++){
					for(j=0;j<8;j++){
						printf("%-3d ",visited[i][j]);
					}
				printf("\n");
				}
			}

			install_pipes (visited,x,y,orientation,count);
			/*geri dönüş sonrası dönülen yeri 0 lama işlemi ve dönülen yeri kaydetme*/
			if(visited[y][x]<80){
				visited[y][x]=0;
				y=y-1;
				x=x+2;
				array[1]=2;
			}	
			
		}
		/*3. yönelim*/
		if(x-1>-1 && y-2>-1 && visited[y-2][x-1]==0 &&  array[2]==0&&*count<10){
			x=x-1;
			y=y-2;
			visited[y][x]=1+visited[y+2][x+1];
			/*eğer 64 boru da yerleşirse burada çizilecek*/
			if(visited[y][x]>=64){
				(*count)++;
				printf("\n");
				for(i=0;i<8;i++){
					for(j=0;j<8;j++){
						printf("%-3d ",visited[i][j]);
				}
				printf("\n");
			}

			}

			install_pipes (visited,x,y,orientation,count);
			/*geri dönüş sonrası dönülen yeri 0 lama işlemi ve dönülen yeri kaydetme*/
			if(visited[y][x]<80){
				visited[y][x]=0;
				y=y+2;
				x=x+1;
				array[2]=3;
			}								
		}
		/*4. yönelim*/
		if(x+2<8 && y-1>-1 && visited[y-1][x+2]==0&&  array[3]==0&&*count<10){
			
			x=x+2;
			y=y-1;
			visited[y][x]=1+visited[y+1][x-2];
				/*eğer 64 boru da yerleşirse burada çizilecek*/
				if(visited[y][x]>=64){
					(*count)++;
					printf("\n");
					for(i=0;i<8;i++){
						for(j=0;j<8;j++){
							printf("%-3d ",visited[i][j]);
						}
					printf("\n");
					}
				}

			install_pipes (visited,x,y,orientation,count);
			/*geri dönüş sonrası dönülen yeri 0 lama işlemi ve dönülen yeri kaydetme*/
			if(visited[y][x]<80){
				visited[y][x]=0;
				y=y+1;
				x=x-2;
				array[3]=4;
			}		
		}
		/*5. yönelim*/
		 if(x+2<8 && y+1<8 && visited[y+1][x+2]==0 &&  array[4]==0&&*count<10){
		
			x=x+2;
			y=y+1;
			visited[y][x]=1+visited[y-1][x-2];
			/*eğer 64 boru da yerleşirse burada çizilecek*/
			if(visited[y][x]>=64){
				(*count)++;
				printf("\n");
				for(i=0;i<8;i++){
					for(j=0;j<8;j++){
						printf("%-3d ",visited[i][j]);
					}
				printf("\n");
					}
			}
			install_pipes (visited,x,y,orientation,count);
			/*geri dönüş sonrası dönülen yeri 0 lama işlemi ve dönülen yeri kaydetme*/	
			if(visited[y][x]<80){
				visited[y][x]=0;
				y=y-1;
				x=x-2;
				array[4]=5;
			}		
					
		}
		/*6. yönelim*/
		if(x-1>-1 && y+2<8 && visited[y+2][x-1]==0 &&  array[5]==0&&*count<10){		
				x=x-1;
				y=y+2;

				visited[y][x]=1+visited[y-2][x+1];
				/*eğer 64 boru da yerleşirse burada çizilecek*/
				if(visited[y][x]>=64){
					(*count)++;
					printf("\n");
					for(i=0;i<8;i++){
						for(j=0;j<8;j++){
							printf("%-3d ",visited[i][j]);
						}
					printf("\n");
					}

				}				
				install_pipes (visited,x,y,orientation,count);
				/*geri dönüş sonrası dönülen yeri 0 lama işlemi ve dönülen yeri kaydetme*/
				if(visited[y][x]<80){
					visited[y][x]=0;
					y=y-2;
					x=+1;
					array[5]=6;
				}									
		}
		/*7. yönelim*/	
		if(x-2>-1 && y-1>-1 && visited[y-1][x-2]==0 &&  array[6]==0&&*count<10){
		
			x=x-2;
			y=y-1;
			visited[y][x]=1+visited[y+1][x+2];
			/*eğer 64 boru da yerleşirse burada çizilecek*/
			if(visited[y][x]>=64){
				(*count)++;
				printf("\n");
				for(i=0;i<8;i++){
					for(j=0;j<8;j++){
						printf("%-3d ",visited[i][j]);
					}
					printf("\n");
				}
			}
			install_pipes (visited,x,y,orientation,count);
			/*geri dönüş sonrası dönülen yeri 0 lama işlemi ve dönülen yeri kaydetme*/
			if(visited[y][x]<80){
				visited[y][x]=0;
				y=y+1;
				x=x+2;
				array[6]=7;
			}						
		}
		/*8. yönelim*/
    	if(x+1<8 && y-2>-1 && visited[y-2][x+1]==0 &&  array[7]==0&&*count<10){
			x=x+1;
			y=y-2;

			visited[y][x]=1+visited[y+2][x-1];
			/*eğer 64 boru da yerleşirse burada çizilecek*/	
				if(visited[y][x]>=64){
					(*count)++;
					printf("\n");
					for(i=0;i<8;i++){
						for(j=0;j<8;j++){
							printf("%-3d ",visited[i][j]);
						}
					printf("\n");
					}	
				}			
			install_pipes (visited,x,y,orientation,count);
		/*geri dönüş sonrası dönülen yeri 0 lama işlemi ve dönülen yeri kaydetme*/	
			if(visited[y][x]<80){
				visited[y][x]=0;
				y=y+2;
				x=x-1;
				array[7]=8;
			}											
		}
		

		/*üsttekilerin aynısı while kullanamadığım için tekrar yazdım*/
		if(x+1<8 && y+2<8 && visited[y+2][x+1]==0 &&  array[0]==0 &&*count<10){
			x=x+1;
			y=y+2;
			visited[y][x]=1+visited[y-2][x-1];
			
			if(visited[y][x]>=64){
				(*count)++;
				printf("\n");
				
				for(i=0;i<8;i++){
					for(j=0;j<8;j++){
						printf("%-3d ",visited[i][j]);
					}
					printf("\n");
				}
			}


				install_pipes (visited,x,y,orientation,count);
				if(visited[y][x]<80){
					visited[y][x]=0;
					x=x-1;
					y=y-2;
					array[0]=1;
			}				
		}
		

		 if(x-2>-1 && y+1<8 && visited[y+1][x-2]==0 &&  array[1]==0&&*count<10){
				x=x-2;
				y=y+1;
				visited[y][x]=1+visited[y-1][x+2];
				
				if(visited[y][x]>=64){
					(*count)++;
					printf("\n");
					for(i=0;i<8;i++){
						for(j=0;j<8;j++){
							printf("%-3d ",visited[i][j]);
						}
					printf("\n");
					}
				}


			install_pipes (visited,x,y,orientation,count);
			if(visited[y][x]<80){
				visited[y][x]=0;
				y=y-1;
				x=x+2;
				array[1]=2;
			}	
			
		}
		if(x-1>-1 && y-2>-1 && visited[y-2][x-1]==0 &&  array[2]==0&&*count<10){
			x=x-1;
			y=y-2;
			visited[y][x]=1+visited[y+2][x+1];
			if(visited[y][x]>=64){
				(*count)++;
				printf("\n");
				for(i=0;i<8;i++){
					for(j=0;j<8;j++){
						printf("%-3d ",visited[i][j]);
					}
				printf("\n");
				}
			}


			install_pipes (visited,x,y,orientation,count);
			if(visited[y][x]<80){
				visited[y][x]=0;
				y=y+2;
				x=x+1;
				array[2]=3;
			}								
		}
		if(x+2<8 && y-1>-1 && visited[y-1][x+2]==0&&  array[3]==0&&*count<10){			
			x=x+2;
			y=y-1;
			visited[y][x]=1+visited[y+1][x-2];
				if(visited[y][x]>=64){
					(*count)++;
					printf("\n");
					for(i=0;i<8;i++){
						for(j=0;j<8;j++){
							printf("%-3d ",visited[i][j]);
					}
					printf("\n");
					}
				}
		
			install_pipes (visited,x,y,orientation,count);
			if(visited[y][x]<80){
					visited[y][x]=0;
					y=y+1;
					x=x-2;
				array[3]=4;
			}
		}
		
		 if(x+2<8 && y+1<8 && visited[y+1][x+2]==0 &&  array[4]==0&&*count<10){
		
			x=x+2;
			y=y+1;
			visited[y][x]=1+visited[y-1][x-2];
			if(visited[y][x]>=64){
				(*count)++;
				printf("\n");
				for(i=0;i<8;i++){
					for(j=0;j<8;j++){
						printf("%-3d ",visited[i][j]);
					}
				printf("\n");
				}
			}
			install_pipes (visited,x,y,orientation,count);
			if(visited[y][x]<80){
				visited[y][x]=0;
				y=y-1;
				x=x-2;
				array[4]=5;
			}					
		}
		
		if(x-1>-1 && y+2<8 && visited[y+2][x-1]==0 &&  array[5]==0&&*count<10){
		
			x=x-1;
			y=y+2;

			visited[y][x]=1+visited[y-2][x+1];
			if(visited[y][x]>=64){
				(*count)++;
				printf("\n");
				for(i=0;i<8;i++){
					for(j=0;j<8;j++){
						printf("%-3d ",visited[i][j]);
					}
					printf("\n");
				}
			}				
			
			install_pipes (visited,x,y,orientation,count);
			if(visited[y][x]<80){
				visited[y][x]=0;
				y=y-2;
				x=+1;
				array[5]=6;
			}									
		}
		
		if(x-2>-1 && y-1>-1 && visited[y-1][x-2]==0 &&  array[6]==0&&*count<10){
	
			x=x-2;
			y=y-1;
			visited[y][x]=1+visited[y+1][x+2];
			if(visited[y][x]>=64){
				(*count)++;
				printf("\n");
				for(i=0;i<8;i++){
					for(j=0;j<8;j++){
						printf("%-3d ",visited[i][j]);
					}
				printf("\n");
				}
			}
			
			install_pipes (visited,x,y,orientation,count);		
			if(visited[y][x]<80){
				visited[y][x]=0;
				y=y+1;
				x=x+2;
				array[6]=7;
			}
		}
		
       if(x+1<8 && y-2>-1 && visited[y-2][x+1]==0 &&  array[7]==0&&*count<10){
			x=x+1;
			y=y-2;

			visited[y][x]=1+visited[y+2][x-1];
			if(visited[y][x]>=64){
				(*count)++;
				printf("\n");
				for(i=0;i<8;i++){
					for(j=0;j<8;j++){
						printf("-%-3d ",visited[i][j]);
					}
				printf("\n");
				}

			}			
			
			install_pipes (visited,x,y,orientation,count);
			if(visited[y][x]<80){
				visited[y][x]=0;
				y=y+2;
				x=x-1;
				array[7]=8;
			}			
		}		
	}
}
void part3(){
	char str[500];
	printf("\nplease enter the string\n");
	scanf(" %[^\n]",str);
	printf("\n");
	remove_duplicates(str);
	
}
char* remove_duplicates (char* str){
	if(*(str)!='\0'){
		if(*(str)==*(str+1)){
			printf("%c",*(str+1));
			remove_duplicates ((str+2));
		}
		else{
			printf("%c",*(str));
			remove_duplicates((str+1));
		}
	}
	else{
		return str;
	}
		

}