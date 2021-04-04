#include <stdio.h>
#include <math.h>/*for sqrt and fabs function*/
/*BY AHMET OKUR*/
	
	int draw_triangle(int side1,int side2,int side3){
		(double)side1;
		(double)side2;
		(double)side3;

		/*triangle rule control*/ 
		if(fabs(side1-side2)<side3 && side1+side2>side3){
			return 1;
		}
		else if(fabs(side1-side3)<side2 && side1+side3>side2){
			return 1;
		}
		else if(fabs(side2-side3)<side1 && side2+side3>side1){
			return 1;
		}		

			return 0;

	}
	
	
	void type_triangle(int side1,int side2, int side3){
		/*triangle type control*/
		
		if(side1==side2 && side1==side3){
			printf("\n\nIT is a equilateral Triangle");
		}
		else if(side1==side2 || side1==side3 || side2==side3){
			printf("\n\nIT is a isosceles Triangle");
		}
		else{
			printf("\n\nIT is a scalene Triangle");
		}
	}
	

	int perimeter_triangle(int side1,int side2, int side3){
		return (side1+side2+side3);/*sum of triangle edges*/ 
	}

	
	
	double area_triangle(int side1,int side2, int side3,int perimeter){
		double area;
		float p;
		p=(((float)side1+(float)side2+(float)side3)/2);
		/* Type conversion for square function*/
		(double)p;
		/*area calculation of the triangle*/
		area=sqrt(p*(p-side1)*(p-side2)*(p-side3));
		return area;
	}
	

	int main(){
		
		int side1,side2,side3;

		printf("<MISSION 1>\n");
		printf("The length of first side:");
		scanf("%d",&side1);

		printf("The length of second side:");
		scanf("%d",&side2);

		printf("The length of third side:");
		scanf("%d",&side3);
		
		if(draw_triangle(side1,side2,side3)==1){
			
			printf("According to the triangle inequality theorem, this triangle can be drawn");
			
			type_triangle(side1,side2,side3);
			printf("\nThe perimeter of the triangle:%d",perimeter_triangle(side1,side2,side3));

			printf("\nThe area of the triangle:%lf",area_triangle(side1,side2,side3,perimeter_triangle(side1,side2,side3)));
		}
		else{
			printf("According to the triangle inequality theorem, this triangle cannot be drawn.");
		}

		
		return 0;
	}