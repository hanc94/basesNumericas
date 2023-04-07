#include <stdio.h>
#include <string.h>
#include <math.h>

int num2dec(char* num, int base);
void dec2num(int dec, char* num, int base);
void hex2bin(char* hex, char* bin);
void bin2hex(char* bin, char* hex);

int main()
{
	//Escribir el código de prueba de las funciones aquí
	/*Declaración de variables.*/
	char num[50]={0},hex[50]={0};
	int base,dec,i;
	/*Variables a pedir*/
	printf("ingrese numero:\t");
	gets(hex);//Para pobrar la conversión num2dec, hex2bin y bin2hex.
	//scanf("%d",&dec);//Para probar dec2num.

	/*Para probar num2dec y dec2num */	
	//printf("ingrese base:\t");
	//scanf("%d",&base);

	//dec=num2dec(num,base);//para probar num2dec
	//printf("%d\n",dec);//imprimir el numero decimal resultado
	//hex2bin(hex,num);//Prueba hex2bin

	bin2hex(hex,num);//prueba bin2hex
	/*para imprimir caracteres diferentes a decimales */

	for(i=0;i<(strlen(num));i++){
		printf("%c",num[i]);
	}
	printf("\n");	
	return 0;	
}

int num2dec(char* num, int base)
{
	/*
		Entrada: 
			num  = Arreglo de caracteres con el número a convertir
			base = Entero que indica la base a la que se va a convertir (2, 8, 10, 16)
		Salida:
			La función debe retornar el número en decimal 
	*/
	// Escribir el código aquí
	int i,j,dec,aux,aux1=base,flag=1;//declaración de las variables, el flag es para la primera iteración.
	
	for(i=strlen(num)-1;i>=0;i--){
		aux=num[i]-'0';//conversión de caracter a entero.
		switch (aux){/* switch de caso multiple para tomar caracteres hexadecimales, acepta mayusculas y minusculas*/
			case 17:
			case 49:
				aux=10;
				break;
			case 50:
			case 18:
				aux=11;
				break;
			case 51:
			case 19:
				aux=12;
				break;
			case 52:
			case 20:
				aux=13;
				break;
			case 53:
			case 21:
				aux=14;
				break;
			case 54:
			case 22:
				aux=15;
				break;

		}
		if(flag==1){
			if(aux>0){
				dec=aux;
				flag=0;
			}
			else{
				dec=0;
				flag=0;
			}
		}
		else{
			for(j=1,aux1=base;j<strlen(num)-i-1;j++)//ciclo para realizar la operación de potencia
				aux1=base*aux1;
		
			dec+=aux*aux1;//conversión final del numero decimal.
		}
	}
	return dec;//retorno de la variable resultado.
}

void dec2num(int dec, char* num, int base)
{
	/*
		Entrada: 
			dec  = Entero con el número a convertir 
			num  = Arreglo de caracteres con el número convertido
			base = Entero que indica la base a la que se va a convertir (2, 8, 16)
		Salida:
			La función no retorna nada
			El retorno se hace por referencia con el parámetro num
	*/
	
	// Escribir el código aquí
	int i=0,res[50],j;//declaración de variables.
	for(;;i++){//loop para una cantidad maxima del tamaño del vector de entrada.
		res[i]=dec%base;//operación modulo para obtener el residuo de la división del numero decimal divido la base.
		/*switch para dar valores de las letras al vector de residuos, si el valor es res>=10 se le modifica el valor para las mayusculas de A-F*/
		switch(res[i]){
			case 10:
				res[i]=17;
				break;
			case 11:
				res[i]=18;
				break;
			case 12:
				res[i]=19;
				break;
			case 13:
				res[i]=20;
				break;
			case 14:
				res[i]=21;
				break;
			case 15:
				res[i]=22;
				break;
		}
		dec=floor(dec/base);//se lleva el numero al entero mas cercano, inecesario si es una operación entera.
		if(dec==0)//condicional para salir del loop
			break;
	}
	for(j=0;i>=0;j++){
		num[j]=res[i]+'0';//convierte de decimal a caracter.
		i--;
	}
}

void hex2bin(char* hex, char* bin)
{
	/*
		Entrada: 
			hex = Arreglo de caracteres con el número en hexadecimal a convertir
			bin = Arreglo de caracteres con el número en binario convertido
		Salida:
			La función no retorna nada
			El retorno se hace por referencia con el parámetro bin
	*/
	// Escribir el código aquí
	int dec;//declaración de la variable contenedora
	
	dec=num2dec(hex,16);//se utiliza la función para obtener el numero decimal. 
	dec2num(dec,bin,2);//se hace la conversión a binario.
}

void bin2hex(char* bin, char* hex)
{
	/*
		Entrada: 
			bin = Arreglo de caracteres con el número en binario a convertir
			hex = Arreglo de caracteres con el número en hexadecimal convertido
		Salida:
			La función no retorna nada
			El retorno se hace por referencia con el parámetro hex
	*/
	// Escribir el código aquí
	int dec;//declaración variable auxiliar.
	dec=num2dec(bin,2);//se utiliza la función para obtener el numero decimal.
	dec2num(dec,hex,16);//Se hace la conversión a hexadecimal partiendo del decimal.
}
