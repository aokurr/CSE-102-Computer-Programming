#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

struct Hospital{
	char* name;
	char citiesServed[3];
};

struct card {
	const char *face;
	const char *suit;
};

void part1();
int numPathsHome(int street, int avenue);


void part2();
int canOfferCovidCoverage(char cities[6],char locations[4][3],int numHospitals,struct Hospital results[4]);
void struct_store(struct Hospital results[4],int count_1,int count_2,char locations[4][3]);


void part3();
int randomm(int array[52],int number);

void menu();


void main(){
menu();
}

void menu(){
	int selection,flag=1;
	while(flag==1){
			printf("\nWELCOME TO GTU HOMEWORK 9\n");
			printf("\nPlease select\npart1 (1) \npart2 (2)\npart3 (3)\nexit (4)\n");
			scanf("%d",&selection);
		switch(selection){
			case 1:part1();
				break;
			case 2:part2();
				break;
			case 3:part3();
				break;
			case 4:flag=0;
				break;
			default:printf("please try again\n");
		}
	}
}


void part1(){
	int street,avenue;
	
	printf("Enter the street number\n");
	scanf("%d",&street);
	
	printf("Enter the avenue number\n");
	scanf("%d",&avenue);
	printf("NUMBER OF OPTİMAL PATHS TO TAKE BACK HOME: %d\n",numPathsHome(street-1,avenue-1));
}
/*kombinasyon işlemiyle çözümü buldum*/
int numPathsHome(int street,int avenue){
	int toplam;
	toplam=street+avenue;
	if(toplam>2){
		
		if(street>1){

			return numPathsHome(street-1,avenue)*toplam/street;
		}
		else if(avenue>1){

			return numPathsHome(street,avenue-1)*toplam/avenue;
			
		}
	}
	else{
		return toplam;
	}	

}

void part2(){
	struct Hospital results[4];
	char cities[6]={'A','B','C','D','E','F'};
	char locations[4][3]={{'A', 'B','C'},{'A','C','D'},{'B','F'},{'C','E','F'}};
	int count_1=0,count_2=0,numHospitals;
	struct_store(results,count_1,count_2,locations);
	
	printf("Enter the maximum number of hospitals that can be constructed\n");
	scanf("%d",&numHospitals);
	
	if(numHospitals>2){
		printf("Yes,can offer health care to all!\n");
		if (numHospitals>3){
			numHospitals=3;
			canOfferCovidCoverage(cities,locations,numHospitals,results);
		}
		else
			canOfferCovidCoverage(cities,locations,numHospitals,results);
	}
	else{
		printf("No,some cities are not covered\n");
	}
	
	
}
/*structa verileri depolama*/
void struct_store(struct Hospital results[4],int count_1,int count_2,char locations[4][3]){
	if(count_1!=4){
		if(count_2<3){
			results[count_1].citiesServed[count_2]=locations[count_1][count_2];
			results[count_1].citiesServed[count_2+1]='\0';
			struct_store(results,count_1,count_2+1,locations);
		}
		else{
			count_2=0;
			
			struct_store(results,count_1+1,count_2,locations);
		}	
	}
}
/*hocam bu kısmı yapamadım*/
int canOfferCovidCoverage(char cities[6],char locations[4][3],int numHospitals,struct Hospital results[4]){
	if(numHospitals>0){
			numHospitals=numHospitals+2;
			printf("hospital %d \nHospital location:%s\n",-(numHospitals-6),results[numHospitals-2].citiesServed);
			return canOfferCovidCoverage(cities,locations,numHospitals-3,results);
		
	}
}



void part3(){
	srand(time(NULL));
	int i,j,K=0;
	char suits[4][10]={"Hearts","Diamond","Clubs","Spades"};
	char faces[13][8]={"Ace","Deuce","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King"};
	struct card cards[52];
	int array[52];	
	int number;
	int flag;
	/*52 lik struct array doldurdum*/
	for(i=0;i<4;i++){
		for(j=0;j<13;j++){
			cards[K].suit=suits[i];
			cards[K].face=faces[j];
			array[K]=-1;
			K++;
		}
	}
	
	i=0;
	/*52 tane 52 ye kadar random sayı oluşturdum*/
	while(i<52){
		number=rand()%52;
		flag=randomm(array,number);
		if(flag==1){
			array[i]=number;
			i++;
		}
	}
	/*52 random sayıyı 52 lik array structa point ettim*/
	for(i=0;i<52;i++){
		printf("%s %s",cards[array[i]].suit,cards[array[i]].face);
		if(i%2==0){
			printf("\t");
		}
		else{
			printf("\n");
		}
	}

}


int randomm(int array[52],int number){
	int i;
	for(i=0;i<52;i++){
		if(array[i]==number){
			return 0;
		}
	}
	return 1;
}