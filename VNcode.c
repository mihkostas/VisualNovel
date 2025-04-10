#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <MMsystem.h>


void delay(int);
void DisplayAscii(FILE*);
void DisplayTB(void);
int DisplayText(FILE*);
void keycheck(FILE*,int);
void SavePos(FILE*,int);
void readSave(FILE*,FILE*);
void PM(char*);


char pos =0;
int state=0;


int main(void){
int c;	
	
FILE *fap;
FILE *fsp;
FILE *fsaves;

fap = fopen("art.txt","r");
fsp = fopen("script.txt","r");
fsaves = fopen("saves.txt","r");

system("color d");

printf("New Game [1] Load save [2]\n");
scanf("%d",&c);

PM("piano.wav");



if(c == 2)readSave(fsaves,fsp);

system("cls");


while(!feof(fsp)){



if(state >= 2 && state < 15)
   DisplayAscii(fap);

      
DisplayTB();
DisplayText(fsp);


keycheck(fsaves,pos);

system("cls");
state++;

}



fclose(fap);
fclose(fsp);


return 0;

}


int DisplayText(FILE *fp){
int i;	
char ch;
int sum=0;

for(i=0;sum != 2 && !feof(fp);i++){
   
   ch = fgetc(fp); 	
   if(ch == '*'){pos++;sum++;}
   if(sum==1 && ch != '*')printf("%c",ch);
   
   
   delay(90);
   

}




}







void DisplayAscii(FILE *fap){

int i;
char ch;

for(i=0;ch != EOF;i++){
	ch = getc(fap);
	printf("%c",ch);
}
printf("\n");
fseek(fap, 0, SEEK_SET);

}



void DisplayTB(void){
int i;
printf("%c",201);
for(i=0;i<50;i++)printf("%c",205);
printf("%c",187);

printf("\n");

}



void delay(int msec) 
{ 
    
  
    clock_t stime = clock(); 
  
    while(clock() < stime + msec); 
} 

void keycheck(FILE *fp,int savep){
char ch;

 ch = getch();	
    
 
if(ch == 's'){
  fp = fopen("saves.txt","w");
  fprintf(fp,"%d",savep);
  printf("  saved");
 }
 
 fclose(fp);	

}

void SavePos(FILE *fp,int point){
	int i;
	int sum=0;
	char ch;
	for(i=0;sum!=point;i++){
	
	ch = fgetc(fp);
	if(ch =='*')sum++;
}
}

void readSave(FILE*fsaves,FILE*fsp){
	static char ch;
	fscanf(fsaves,"%d",&ch);
    pos+=ch;
    SavePos(fsp,ch);
    if(ch != 0)state+= ch/2;
    fclose(fsaves);
   
}


void PM(char *s){
  PlaySound(s, NULL, SND_FILENAME|SND_LOOP|SND_ASYNC);
}



