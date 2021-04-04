#include <stdio.h>
/*Author=AHMET OKUR 
*NUMBER=1801042655*/

int sum(int n,int flag){
	int i,result;

	switch(flag){
		case 0: 
			i=0;/*for even numbers*/
			result=i;
			/*required algorithm for plus sign*/
			while(i<=n){
				printf("%d",i);
				/*for even numbers. for example 0 2 4 6 */
				i=i+2;
				result=i+result;/*Addition of even numbers*/
				
				if(i==n+1 || i==n+2){
					printf("=");
				}
					
				else{
					printf("+");
				}		
			}
		return result-i;			
		
		case 1:	
			i=1;/*for odd numbers*/
			result=i;
			/*required algorithm for plus sign*/
			while(i<=n){
				printf("%d",i);
				/*for odd numbers. for example 1 3 5 7 */
				i=i+2;
				result=i+result;/*Addition of odd numbers*/
				
				if(i==n+1 || i==n+2){
					printf("=");
				}
					
				else{
					printf("+");
				}
			
			}
			return result-i;
		/*if the flag is not 1 or 0*/
		default: return flag;
		}		
	
}

int mult(int n,int flag){
	int i,result;

	switch(flag){
		case 0: 
			i=2;/*for even numbers*/
			result=i;
			/*required algorithm for multiplication sign*/
			while(i<=n){
				printf("%d",i);
				
				i=i+2;/*for even numbers. for example  2 4 6 */
				result=i*result;/*product of even numbers*/

				
				if(i==n+1 || i==n+2){
					printf("=");
				}
					
				else{
					printf("*");
				}
			
			}
		return result/i;			
		
		case 1:	
			i=1;/*for odd numbers*/
			result=i;
			/*required algorithm for multiplication sign*/
			while(i<=n){
				printf("%d",i);
				
				i=i+2;/*for odd numbers. for example 1 3 5 7 */
				result=i*result;/*product of even numbers*/
				
				if(i==n+1 || i==n+2){
					printf("=");
				}
					
				else{
					printf("*");
				}			
			}
		
		return result/i;

		default: return flag;
		}	
}

int main(){

	int n,flag;
	
	printf("Enter an integer:");
	scanf("%d",&n);
	
	printf("Please enter '0' for sum,'1' for multiplication:");
	scanf("%d",&flag);
	
/*addition and subtraction selection*/
	switch(flag){
		case 0:
			printf("Please enter '0' to work on even number,'1'to work on odd numbers:");
			scanf("%d",&flag);/*2nd choice*/

			
			printf("%d",sum(n,flag));
			/* if 2nd choice is incorrect*/
			if(flag!=0 || flag!=1){
				printf(" ınvalid value for odd/even selection");
			}
			break ;
		
		case 1:
			printf("Please enter '0' to work on even number,'1'to work on odd numbers:");
			scanf("%d",&flag);/*2nd choice*/
			
			printf("%d",mult(n,flag));
			/* if 2nd choice is incorrect*/
			if(flag!=0 || flag!=1){
				printf(" ınvalid value for odd/even selection");
			}

			break;
		default:
			printf("Unsported operation");
	}

	return 0;
}