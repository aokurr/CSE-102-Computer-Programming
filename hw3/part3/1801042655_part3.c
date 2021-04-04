#include <stdio.h>
/*Author=AHMET OKUR 
*NUMBER=1801042655*/
int length(int number){
	/*find the length of the number*/
	int count=0;
	/*divides by 10 until the number is 0*/
	while((number/10)!=0){
		number=number/10;
		count++;/*counter increases in each section*/
	}
	return count+1;/*the length of the number*/
}

int binary(int number,int length){
	/*determines the type of the number*/
	int count=0;
	int digit;	
		/*the loop continues until the counter is equal to the length*/
		while(count!=length){
			digit=number%10;/*determination of the last digit*/

			/*last digit check*/
			if(digit==1 || digit==0){
				/*if the check is correct, the number is divided by 10 and the next step is passed*/
				number=number/10;
			}
			else{
				/*If the control is wrong, the function ends with a value of 0.*/
				return 0;
			}
			count++;
		}
	return 1;
}

int andop(int a,int b){
	int length1,result=0,pow=1,count=0,x;
	length1=length(a);/*length of the number*/

/*the loop turns until the counter is equal to the length*/
	while(count!=length1){
	/*digit control of both numbers is checked*/
		if(a%10==1 && b%10==1){		
		x=1;
	/*divided by 10 for other digits*/	
		a=a/10;
		b=b/10;
		
		result=result+x*pow;
	/*çıkan sayıları basamak değerlerine ulaştırabilmek için üs değerleri hesaplama*/ 	
		pow=pow*10;
		
		}
		
		else{
	/*çıkan sayıları basamak değerlerine ulaştırabilmek için üs değerleri hesaplama*/ 		
		pow=pow*10;
	/*divided by 10 for other digits*/	
		a=a/10;
		b=b/10;
		
		}
		count++;
	}	
return result;

}


int main(){

	int first_number,second_number;
	int flag=0,flag2=0,a;
	
while(flag2==0){
	/*length control loop*/
	while(flag==0){
		printf("First integer:");
		scanf("%d",&first_number);

		printf("second integer:");
		scanf("%d",&second_number);
	/*number length control*/	
		if(length(first_number)==length(second_number)){
			flag=1;/*if the process is correct, exit the loop*/
			
		}
		else{
			printf("Integers should have the same length,please enter 2 new integers\n");
		}
	}
	/*number type control loop*/
	flag=0;
	while(flag==0){
		flag=0;
		a=0;
	/*bu kısım iki sayının eşit uzunlukta fakat binary olmayan sayı girilmesi ardından
	girilen sayıların eşit olmayan uzunlukta girilmesi sonucu hata verdiren kısımdır
	yani 12345  24567 sayılarından sonra 110  11 girilmesi gibi*/	
		if(length(first_number)==length(second_number)){
			flag=1;
			a=1;
		}
		else{
			printf("Integers should have the same length,please enter 2 new integers\n");	
		}
		
	/*everything is right in this section*/	
		if(binary(first_number,length(first_number))==1 && binary(second_number,length(second_number))==1 && flag==1){
			
			printf("%d AND %d =%d",first_number,second_number,andop(first_number,second_number));
			flag2=1;/*if the process is correct, exit the loop*/			
		}
		else{
			flag=0;
			
		}
		
		if(flag==0){
			if(a==1){
				printf("Integers should be binary\n");
			}		
		printf("First integer:");
		scanf("%d",&first_number);

		printf("second integer:");
		scanf("%d",&second_number);
		}
	}
}

	return 0;
}