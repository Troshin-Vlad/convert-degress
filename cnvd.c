#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define VERSION 1.0

#define CLR_RED "\033[31m"
#define CLR_GRN "\033[32m"
#define CLR_DEF "\033[0m"

void error(const char *str);
void version();
void help();

int main(int argc,char *argv[]){

	/*
	  -C - Цельсий 
	  -F - Фаренгейт
	  -K - Кельвин
	  -Re - Реамюр
	  -Ra - Ранкин
	  -Ro - Рёмер
	  -N - Ньютон
	  -D - Делисле
	*/

	int i = 0;
	while(i < argc){
		if(strcmp(argv[i],"-h") == 0)
			help();
		else if(strcmp(argv[i],"-v") == 0)
			version();
		i++;
	}

	if( argc != 4 ){
		error("you need select 2 option");
	}

	//chars for options
	char Cl[3] = "-C";
	char Fr[3] = "-F";
	char Ke[3] = "-K";
	char Re[4] = "-Re";
	char Ra[4] = "-Ra";
	char Ro[4] = "-Ro";
	char Ne[3] = "-N";
	char De[3] = "-D";

	float Cel,Fah,Kel,Rea,Ran,Rom,New,Del,teil;
	double deg = atof(argv[2]);

	char *begin_char;
	char *end_char;

	begin_char 	= 	argv[1];
	end_char 	= 	argv[3];


		if( strcmp(begin_char,"-C") == 0){
			Cel = deg;
			printf("Цельсия(Celsius): %0.2f\n",Cel);
		}
		else if( strcmp(begin_char, Fr) == 0 ){
			Fah = deg;
			Cel = (5.0/9.0)*(Fah-32);
			printf("Фаренгейт(Fahrenheit): %0.2f\n",Fah);
		}
		else if( strcmp(begin_char, Ke) == 0 ){
			Kel = deg;
			Cel = Kel - 273.15;
			printf("Кельвин(Kelvin): %0.2f\n",Kel);
		}
		else if( strcmp(begin_char, Re) == 0 ){
			Rea = deg;
			Cel = Rea*1.25;
			printf("Реамюр(Reaumur): %0.2f\n",Rea);
		}
		else if( strcmp(begin_char, Ra) == 0 ){
			Ran = deg;
			Cel = (Ran-491.67)*(5.0/9.0);
			printf("Ранкин(Rankine): %0.2f\n",Ran);
		}
		else if( strcmp(begin_char, Ro) == 0 ){
			Rom = deg;
			Cel = (Rom - 7.5)*(40.0/21.0);
			printf("Рёмер(Romer): %0.2f\n",deg);
		}
		else if( strcmp(begin_char, Ne) == 0 ){
			New = deg;
			Cel = New*100.0/33.0;
			printf("Ньютон(Newton): %0.2f\n",New);
		}
		else if( strcmp(begin_char, De) == 0 ){
			Del = deg;
			Cel = 100 - Del*(2.0/3.0);
			printf("Делисле(Delisle): %0.2f\n",Del);
		}
		else{
			error("unknow frist option");
		}


		if( strcmp(end_char,"-C") == 0){
			printf("Цельсий(Celsius): %0.2f\n",Cel);
		}
		else if( strcmp(end_char, Fr) == 0 ){
			Fah = (9.0/5.0)*Cel+32;
			printf("Фаренгейт(Fahrenheit): %0.2f\n",Fah);
		}
		else if( strcmp(end_char,Ke) == 0 ){
			Kel = Cel + 273.15;
			printf("Кельвин(Kelvin): %0.2f\n",Kel);
		}
		else if( strcmp(end_char, Re) == 0 ){
			Rea = Cel*0.8;
			printf("Реамюр(Reaumur): %0.2f\n",Rea);
		}
		else if( strcmp(end_char, Ra) == 0 ){
			Ran = (Cel+273.15)*(9.0/5.0);
			printf("Ранкин(Rankine): %0.2f\n",Ran);
		}
		else if( strcmp(end_char, Ro) == 0 ){
			Rom = Cel*(21.0/40.0)+7.5;
			printf("Рёмер(Romer): %0.2f\n",Rom);
		}
		else if( strcmp(end_char, Ne) == 0 ){
			New = Cel*33.0/100.0;
			printf("Ньютон(Newton): %0.2f\n",New);
		}
		else if( strcmp(end_char, De) == 0 ){
			Del = (100 - Cel)*3.0/2.0;
			printf("Делисле(Delisle): %0.2f\n",Del);
		}
		else{
			error("unknow last option");
		}

	return 0;

}

void error(const char *str){
	printf("[%serror%s]: %s\n",CLR_RED,CLR_DEF,str);
	printf("print help page: cnvd -h\n");
	exit(1);
}

void version(){
	printf("version %0.2f\n",VERSION);
	printf(" [%s+%s]: %s\n",CLR_GRN,CLR_DEF,"rename program (temp > cnvd)");
	printf(" [%s+%s]: %s\n",CLR_GRN,CLR_DEF,"optimization program");
	exit(0);
}

void help(){
	printf("Usage: cnvd [-C|-F|-K|-Re|-Ra|-Ro|-N|-D] <n> [-C|-F|-K|-Re|-Ra|-Ro|-N|-D]\n");
	printf("  -C <n>: Цельсий(Celsius)\n");
	printf("  -F <n>: Фаренгейт(Fahrenheit)\n");
	printf("  -K <n>: Кельвин(Kelvin)\n");
	printf("  -Re <n>: Реамюр(Reaumur)\n");
	printf("  -Ra <n>: Ранкин(Rankine)\n");
	printf("  -Ro <n>: Рёмер(Romer)\n");
	printf("  -N <n>: Ньютон(Newton)\n");
	printf("  -D <n>: Делисле(Delisle)\n");
	printf("Exemple:\n(convert Celsius to Fahrenheit): cnvd -C 31 -F\n(convert Fahrenheit to Reaumur):  cnvd -F 245 -Re\n");
	exit(0);
}
