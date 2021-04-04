#include <stdio.h>
/* BY AHMET OKUR*/
int main(){
	double amount;
	int chocie1,chocie2;
	printf("****Welcome to AHMET Exchange Office****");
	
	printf("\nEnter your amount:");
	scanf("%lf",&amount);
	
	printf("please select your currency\n");
	printf("1. TURKISH LIRAS\n");
	printf("2. EURO\n");
	printf("3. DOLLAR\n");
	scanf("%d",&chocie1);
	/*currency slection*/
	switch(chocie1){
		case 1:
			printf("You have %lf Turkish Liras",amount);
			break;
		case 2:
			printf("You have %lf Euro ",amount);
			amount=amount*6.69;/*I wrote the calculations in Turkish currency type*/
			break;
		case 3:
			printf("You have %lf Dollar",amount);
			amount=amount*6.34;/*I wrote the calculations in Turkish currency type*/
			break;
		default:
			printf("Your selection is invalid");
	}
	
	/*currency conversion*/
	if(chocie1==1 || chocie1==2 || chocie1==3){
	
		printf("\nChoose which currency you want to convert:");
		scanf("%d",&chocie2);
		
		switch(chocie2){
			case 1:
				printf("you have %lf Turkish Liras",amount);
				break;
			case 2:
				printf("You have %lf Euro",(amount/6.69));
				break;
			case 3:
				printf("You have %lf Dollar",(amount/6.34));
				break;
			default:
				printf("Your selection is invalid");
		}
	}

	return 0;
}