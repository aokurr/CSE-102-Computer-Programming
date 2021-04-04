#include <stdio.h>
#include <math.h>
/*Author=AHMET OKUR 
*NUMBER=1801042655*/

int isprime(int a){

	for(int i=2;i<=sqrt((double)a);i++){
	/*is not prime if the number is divided*/	
		if(a%i==0){
			return i;
		}
		}
		return 0;	
}

int main(){
	int number,i;
	
	printf("please enter an integer:");
	scanf("%d",&number);
	/* this loop shows the natural numbers up to the number entered*/
	for(i=2;i<number;i++){
		/*prime number control*/
		if(isprime(i)==0){
			printf("\n%d is prime number",i);
		}
		else{
			printf("\n%d is not prime number,it is divisible by %d",i,isprime(i));
		}

	}

	return 0;
}