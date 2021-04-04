#include <stdio.h>
#include <math.h>/*for log and pow function*/
/*BY AHMET OKUR*/
 int number_length(int number){
 	int digit;
 	(double)number;
 	
 	if(number!=0){
 	/*number of length calculation*/
 	digit=log10(number)+1;
 	return digit;
 	}
 	
 	digit=1;/*if the number is 0 it is an exception*/
 	return digit;
 }
 
 int find_digit(int number, int index){
 		
	 	int result,mod,length;
	 	double pow_x=10,pow_y;
	 	
	 	length=number_length(number);
	 	/* for example 123456 index=16 length=6 mod=4*/ 
	 	mod=index%length;
	 	
	 	if(mod==0){
	 		mod=length;
	 	}
	 	
	 	pow_y=length-mod;/* length=6 mod=4 pow_y=2*/
	 	
	 	result=number/pow(pow_x,pow_y);/*123456/10^2 I have moved the desired index to the last step -->1234*/
	 	
	 	result=result%10;/*1234 ü 10 a mod alarak isteneni elde ettim*/
	 	return result;
 }
 	

int main(){

	int number,index;
	
	printf("Enter a number (maximum 6 digit):");
	scanf("%d",&number);
	
	if(number_length(number)<7){
		printf("Your number has %d digit\n",number_length(number));
		
		printf("When your number is written 100 times next to each other, which digit of this number would you like to see?: \n");
		scanf("%d",&index);
		
		printf("%d.th digit of the big number sequence:%d",index,find_digit(number,index));
	}
	else{
		printf("MAXIMUM 6 DIGIT!!!");
	}

	return 0;
}