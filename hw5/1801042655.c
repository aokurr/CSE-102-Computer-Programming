#include <stdio.h>
/*
********GEBZE TECHNİCAL UNIVERSITY*******
	CSE 102 HOMEWORK->5  
	AUTHOR=AHMET OKUR NUMBER:1801042655
*/
/*NOT:BAZI KISIMALRI SİZE DAHA İYİ ANLATABİLMEK İÇİN TÜRKÇE YAZMAK ZORUNDA KALDIM :(*/	

void menu();
/*a,b*/
void read_news(char buffer[500], char file_path[11], int is_Only_Title);
void append_file(char* file_path, char c);
/*c*/
void read_magic_numbers(char buffer_magic[11], char buffer_news[500]);

double f_func(int x);
double g_func(double f(int x), int a);

int main(void){
	menu();
}

void menu(){
	
	int is_Only_Title=0;
	char file_path[11]="news/1.txt";
	char buffer[500],a,selection,c;
	char flag='y',news_number;
	char buffer_magic[11]="news/1.txt",buffer_news[500],magic_number;

	
	printf("******Daily Press*****\n");
	printf("\nToday's news are listed for you");
	/*reading titles*/
	for(int i=1;i<5;i++){
		printf("\nTitle of %d news:",i);
		
		/*action for each title*/
		a=i+'0';
		file_path[5]=a;
		/*if is_Only_Title=0 reads only title*/
		read_news(buffer,file_path,is_Only_Title);
	}
	while(flag=='y'){
		printf("what do you want to do?\n");
		printf("a.Read a new\nb.List the readed news\nc.Get decrypted information from the news\n");
		scanf(" %c",&selection);
		
		switch (selection){
			case 'a':printf("Which news do you want to read:\n");
				
				/*if is_Only_Title=1 the program reads the news*/
				is_Only_Title=1;
				scanf(" %c",&news_number);
				/*check news number*/
				if(news_number=='1'||news_number=='2'||news_number=='3'||news_number=='4'){
					
					file_path[5]=news_number;
					read_news(buffer,file_path,is_Only_Title);
				}
				else{
					printf("ERROR!! Please try again");
					is_Only_Title=0;
				}
				break;
			
			case 'b':printf("Readed news are listed below\n");
					c='o';
					append_file("readed_news_id.txt",c);
					break;
			
			case'c':printf("which news would you like to decrypted\n");
					scanf(" %c",&magic_number);
					
					if(magic_number=='1'||magic_number=='2'||magic_number=='3'||magic_number=='4'){
						buffer_magic[5]=magic_number;
						read_magic_numbers(buffer_magic,buffer_news);
					}
					else{
						printf("ERROR!!! Please try again");
					}
					break;
			
			default:printf("ERROR PLEASE TRY AGAİN");
		}
		
		printf("\nDo you want continue?Yes(y) No(n)\n");
		scanf(" %c",&flag);
		
		if(flag=='n'){
			printf("\nGood Bye!!\n");
		}
		if(flag!='n' && flag!='y'){
			printf("ERROR!! The program is closing\n");
		}
	}
}

void read_news(char buffer[500], char file_path[11], int is_Only_Title){
	
	FILE *fp;
	int i=0;
	fp=fopen(file_path,"r");
	char ch=file_path[5],c;
	/*the program only reads the title in this section */
	if(is_Only_Title==0){
		fgets(buffer,500,fp);
		puts(buffer);
	}
	else{
		
		/*is_Only_Title=1 ise menü de a seçeneği seçilmiştir*/
		if(is_Only_Title==1){
			/*menude a seçeneği seçilirse daha önce okunmuş mu diye append_file fonksiyonuna gider */
			/*append_file fonksiyonunda tekrar  read_news fonksiyonunu çağırdım tekrar buraya girmemesi için is_Only_Title ı 2 ye eşitledim yoksa sonsuz döngüye girer*/
			append_file("readed_news_id.txt",ch);
			is_Only_Title=2;
		}
		
		/*is_Only_Title==5 ve is_Only_Title==3 kontrolü nedir?*/
		/*void append_file(char* file_path, char c) fonksiyonunda bulunduğumuz void read_news(char buffer[500], char file_path[11], int is_Only_Title) fonksiyonu tekrar çağrılıyor*/
		/*is_Only_Title==5 demek void append_file(char* file_path, char c) fonksiyonunda bize okunmuş haberi tekrar okumak ister misin diye sorar evet dersek is_only_title 5 e eşitlenir*/
		/*is_Only_Title==3 demek void append_file(char* file_path, char c)fonksiyonunda okunmamış haberi okundu diye dosyaya kaydeder*/
		if(is_Only_Title==5 || is_Only_Title==3){
			/*reading from file*/
			while(!feof(fp)){
				
				c=fgetc(fp);
				buffer[i]=c;
				i++;
			}
			i=i-1;
			buffer[i]='\0';
			puts(buffer);
	}
	}
	fclose(fp);
	
}


void append_file(char* file_path, char c){
	FILE *fp_write,*fp_read;
	int flag=0,read_again,is_Only_Title;
	char control,readed;
	char buffer[500];
	char file_path_again[11]="news/1.txt";
/* menudeki c seceneğini seçersek bu kısımda okunmuş haberleri bize iletir*/	
	if(c=='o'){
		fp_read=fopen(file_path,"r");
		while(!feof(fp_read)){
			fscanf(fp_read,"%c",&readed);
			if(readed!='\n'){
				printf("%c.news are readed\n",readed);
			}
		}
		fclose(fp_read);
	}
	
	else{
		file_path_again[5]=c;
		fp_read=fopen(file_path,"r");
		while(!feof(fp_read)){
			fscanf(fp_read,"%c",&control);
			/*haber daha önce okunmuş mu kontrolü*/
			if(control==c){
				flag=1;	/*eğer flag=0 olursa aşşağıda dosyaya belirtilen haberi okundu diye yazacak*/		
				
				printf("This new is readed.Do you want to read again?YES(1)/NO(0):");
				scanf("%d",&read_again);
			
				if(read_again==1){
					is_Only_Title=5;
					read_news(buffer,file_path_again,is_Only_Title);
				}
				else if(read_again==0){
					is_Only_Title=6;
					read_news(buffer,file_path_again,is_Only_Title);
				}
				else{
					printf("ERROR!!!Please try again");
				}
				break;
		}
		}
		fclose(fp_read);
	}
/*haber daha önce okunmadıysa burada okundu diye geçecek*/
	if(flag==0&&c!='o'){

		fp_write=fopen(file_path,"a");
		fprintf(fp_write,"%c\n",c);
		fclose(fp_write);
		is_Only_Title=3;
		read_news(buffer,file_path_again,is_Only_Title);
	}

}

void read_magic_numbers(char buffer_magic[11], char buffer_news[500]){
	FILE *fp;
	char ch;
	int i=0,x,j=0;
	double result=0;
	fp=fopen(buffer_magic,"r");
	/*haberi okumak ve haberdeki magic numberları bulmak*/
	while(!feof(fp)){
		fscanf(fp,"%c",&ch);	
		buffer_news[j]=ch;
		j++;
		/*magic number bulma*/
		if(ch=='#'){
			fscanf(fp,"%c",&ch);	
			buffer_news[j]=ch;
			j++;
			
			fseek(fp,i+1,SEEK_SET);
			fscanf(fp,"%d",&x);	
			/*secret number hesaplama*/
			result=result+ g_func(f_func,x);
			i++;/*dosaydki haberin her bir harf indeksi*/
		}
		i++;
	}
	fclose(fp);
	j=j-1;
	buffer_news[j]='\0';

	puts(buffer_news);
	if(buffer_magic[5]=='1'){
		printf("number of tests performed.=%.3lf",result);
	}
	else if(buffer_magic[5]=='2'){
		printf("number of sick people.=%.3lf",result);
	}
	else if(buffer_magic[5]=='3'){
		printf("represent the number of deaths.=%.3lf",result);
	}
	else if(buffer_magic[5]=='4'){
		printf("expected number of sick people.=%.3lf",result);
	}
}
/*f(x) fonksiyonu*/
double f_func(int x){
	double result;
	result=(x*x*x)-(x*x)+2;
	return result;
}
/*g(f(x)) fonksiyonu hesaplama*/
double g_func(double f(int x), int a){
	double result=0;
	result=f(a)*f(a);
	return result;
}