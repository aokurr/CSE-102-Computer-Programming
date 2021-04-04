#include <stdio.h>
#include <math.h>

	
	void find_root(){
	
		int a,b,c;//a(x^2)+ b(x)+c
		double root1,root2,diskriminant,diskriminant_squre;
		
/*I WANTED THE COEFFICIENTS IN PART 1. THE COEFFICIENTS a, b, c ARE THE VARIABLES*/
		printf("please Enter the first coefficient:"); 
		scanf("%d",&a);
	
		printf("please Enter the second coefficient:");
		scanf("%d",&b);

		printf("Please Enter the third coefficient:");
		scanf("%d",&c);
		
		diskriminant=(b*b)-(4*a*c); /*I CALCULATED THE DISKRIMINANT.*/
		

		/*IF THE DISCRIMINANT=>0 ,THERE A REAL ROOT.I CHECKED*/
		if(diskriminant>=0){
			diskriminant_squre=sqrt(diskriminant);

			root1=((-b)-diskriminant_squre)/2*a;
			root2=((-b)+diskriminant_squre)/2*a;
			
			printf("Your equation %dx^2+(%dx)+(%d) have real roots {%.3lf,%.3lf}",a,b,c,root1,root2);
			
		}	
			
			/*IF THE DISKRIMINANT<0 THERE IS NO ROOT*/

			else{
				printf("your equation %dx^2+(%dx)+(%d) does not have any real roots.",a,b,c);
			}
			
	}





	void find_newtonian_root(){

		
		int a,b,c;/*ax^2+bx+c*/ 
		float Fx,x1,x2,x3,x4,x5;
		double root1,root2,diskriminant,diskriminant_squre,root,initial;
		/*I WANTED THE COEFFICIENTS IN PART 1. THE COEFFICIENTS a, b, c ARE THE VARIABLES*/
		printf("Please enter first coefficient:");
		scanf("%d",&a);
		
		printf("Please enter second coefficient:");
		scanf("%d",&b);
		
		printf("Please enter third coefficient:");
		scanf("%d",&c);
		
		printf("Please enter the initial:");
		scanf("%lf",&initial);
		printf("\nStep\tx\tf(x)\tDifference\n");
		
		/* I have to know the root for diffirence. I found the root*/
		diskriminant=(b*b)-(4*a*c);
		diskriminant_squre=sqrt(diskriminant);
		root1=((-b)-diskriminant_squre)/2*a;
		root2=((-b)+diskriminant_squre)/2*a;
		/*I found the root closest to initial*/
		if(fabs(initial-root1)<=fabs(initial-root2)){
			root=root1;
		}	
		else{
			root=root2;
		}


			x1=initial-(((a*initial*initial)+(b*initial)+(c)))/((2*a*initial)+b);/*Newtons formula.I COLCULATED.I CALCULATED STEP 1*/		
			Fx=(((a*x1*x1)+(b*x1)+(c)));/*I CALCULATED THE FUNCTION*/
			printf("x1   ");
			printf("%.4f   %.4f   %.4f\n",x1,Fx,fabs(root-x1));/* STEP1 ,f(x1),diffirance*/	
			initial=x1;/*I RENEWED THE INITIAL FOR FORMULA -->x1=x0-f(x0)/f'(x0)*/
			
			x2=initial-(((a*initial*initial)+(b*initial)+(c)))/((2*a*initial)+b);/*I CALCULATED STEP 2*/		
			Fx=(((a*x2*x2)+(b*x2)+(c)));
			printf("\nx2   ");
			printf("%.4f   %.4f   %.4f\n",x2,Fx,fabs(root-x2));/* STEP2 ,f(x2),diffirance*/	
			initial=x2;/*I RENEWED THE INITIAL FOR FORMULA -->x2=x1-f(x1)/f'(x1)*/
			
			x3=initial-(((a*initial*initial)+(b*initial)+(c)))/((2*a*initial)+b);/*I CALCULATED STEP 3*/		
			Fx=(((a*x3*x3)+(b*x3)+(c)));
			printf("\nx3   ");
			printf("%.4f   %.4f   %.4f\n",x3,Fx,fabs(root-x3));/* STEP3 ,f(x3),diffirance*/		
			initial=x3;/*I RENEWED THE INITIAL FOR FORMULA -->x3=x2-f(x2)/f'(x2)*/
			
			x4=initial-(((a*initial*initial)+(b*initial)+(c)))/((2*a*initial)+b);/*I CALCULATED STEP 4*/		
			Fx=(((a*x4*x4)+(b*x4)+(c)));
			printf("\nx4   ");
			printf("%.4f   %.4f   %.4f\n",x4,Fx,fabs(root-x4));/* STEP4 ,f(x4),diffirance*/			
			initial=x4;/*I RENEWED THE INITIAL FOR FORMULA -->x4=x3-f(x3)/f'(x3)*/

			x5=initial-(((a*initial*initial)+(b*initial)+(c)))/((2*a*initial)+b);/*I CALCULATED STEP 5*/		
			Fx=(((a*x5*x5)+(b*x5)+(c)));
			printf("\nx5   ");/*I RENEWED THE INITIAL FOR FORMULA -->x5=x4-f(x4)/f'(x4)*/
			printf("%.4f   %.4f   %.4f\n",x5,Fx,fabs(root-x5));/* STEP5 ,f(x5),diffirance*/	

	}





	int find_multiple_closest(int a,int b){
		int mod,close_number;
		
		
			if(a%b==0){/*FULL SECTIONABLE CONTROL*/
				return printf("Closet number to %d that is multiple of %d is itself\n",a,b);
			}

			mod=a%b; /*I RECEIVED THE MODE AND I CAN DETERMINE THE NEAR MULTIPLIER. FOR EXAMPLE 76 AND 15."HOCAM BU KISIMDA ÇEVİRİDE ZORLANDIM :(" 15 İN 76 YA YAKIN KATI 75  VE  90 DAN HANGİSİNE DAHA YAKIN ONU ÖLÇTÜM*/
			if(b/2>=mod){
				close_number=a-mod;/*ÖRENEĞİN 76 VE 15 SAYISI; 76 NIN 15 MODU 1 DİR BURADA 76 DAN 1 ÇIKARARAK 15 İN KATINA ULAŞIRIZ*/ 
				return 	printf("Closest number to %d that is multiple of %d is %d\n",a,b,close_number);
			}
		
			else{
				close_number=b-mod+a;/*ÖRENEĞİN 85 VE 15 SAYISI; 85 İN 15 MODU 10 DUR 85+15-10 YAPARSAK 90 A ULAŞIRIZ*/  
				return 	printf("Closest number to %d that is multiple of %d is %d\n",a,b,close_number);
			}

	}	

	int main(){
		printf("NAME:AHMET SURNAME:OKUR\n NUMBER:1801042655\n");
		
		printf("\nPART 1\n");/*ORGANIZED PARTIES*/
		find_root();
		
		printf("\n\nPART 2\n");/*ORGANIZED PARTIES*/
		find_newtonian_root();

		printf("\nPART 3\n");/*ORGANIZED PARTIES*/
		int a,b;
		printf(" Enter the first integer");
		scanf("%d",&a);
		printf("Enter the second integer");
		scanf("%d",&b);
		find_multiple_closest(a,b);


		return 0;
}