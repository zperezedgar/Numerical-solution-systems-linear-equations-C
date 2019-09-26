#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n, i, j, k, r, c, p, cont=0, bandera=1;
double factor, elemento, suma;
double dummy, big, D;

int main(int argc, char *argv[]) 
{
	//ELIMINACION HACIA ADELANTE (Reduccion de Gauss)
	
	//Solicitar matriz aumentada de n X (n+1)
	printf("\nBIENVENIDO AL ALGORITMO DE GAUSS-JORDAN PARA UN SISTEMA DE ECUACIONES LINEALES\n");
	printf("\nIntroduzca el Numero de Variables\n");
	scanf("%i", &n);

	double	MatrizC[n][n+1];		//Matriz de elementos (coeficientes) aumentada
	double	MatrizS[n][n+1];		//Matriz solucion

	r=1;
	for(i=0; i<=(n-1); i++)
	{
		c=1;
		for(j=0; j<=n; j++)
		{
			printf("\nIngrese Dato%i%i\n", r, c);
			scanf("%lf", &elemento);
			MatrizC[i][j]=elemento;
			MatrizS[i][j]=elemento;
			c++;
		}
		r++;
	}
		

	//Eliminacion hacia adelante
	for(k=0; k<=(n-1); k++)
	{
		if(MatrizS[k][k]==0)
		{
		
		//****************** PIVOTEO PARCIAL ********************************//
		p=k;
		big=abs(MatrizS[k][k]);
		
		for(i=k+1; i<n; i++)	//Rutina para identificar el coeficiente mayor
		{
			dummy=abs(MatrizS[i][k]);
			if(dummy>big) 
			{
				big=dummy;
				p=i;
				
			}
		}
			
		if(p!=k)	//Burbuja
		{
			for(j=k; j<=(n-1); j++)
			{
				dummy=MatrizS[p][j];
				MatrizS[p][j]=MatrizS[k][j];
				MatrizS[k][j]=dummy;
				 
			}
			dummy=MatrizS[p][n];
			MatrizS[p][n]=MatrizS[k][n];
			MatrizS[k][n]=dummy;
			cont++;
		}
		//******************************************************************//
		}
		
		for(i=0; i<=(n-1); i++)
		{
			if(i!=k)
			{
				factor=MatrizS[i][k]/MatrizS[k][k];
			
				for(j=0; j<=n; j++)
				{
					MatrizS[i][j]=MatrizS[i][j]-((MatrizS[k][j])*factor);
				}	
			}
		}
	}
	
	system("cls");
	printf("\nMatriz ingresada:\n");
	for(i=0; i<=(n-1); i++)	
	{
		for(j=0; j<=n; j++)	
		{
			printf("%.3f\t", MatrizC[i][j]);
		}
		printf("\n");
	}	
	
	
	printf("\nMatriz Diagonal:\n");
	for(i=0; i<=(n-1); i++)	
	{
		for(j=0; j<=n; j++)	
		{
			printf("%.1f\t", MatrizS[i][j]);
		}
		printf("\n");
	}
	
	//****************** DETERMINANTE ********************************//
	D=1;
	for(i=0; i<=(n-1); i++)
	{
		D=D*MatrizS[i][i];
	}
	D=D*pow(-1,cont);
	printf("\nDeterminante= %.3f\n", D);
	//****************************************************************//
	
	
	//*******************MENSAJE DE ALERTA***************************//
	if((fabs(D)==0)&&(abs(MatrizS[n-1][n])==0))
	{
		printf("\n*** SISTEMA SINGULAR!\n*** NUMERO INFINITO DE SOLUCIONES!\n");
		bandera=0;
	}
	if((fabs(D)==0)&&(abs(MatrizS[n-1][n])!=0))
	{
		printf("\n*** SISTEMA INCONSISTENTE!\n*** NO EXISTEN SOLUCIONES!\n");
		bandera=0;
	}
	//****************************************************************//
	
	
	//Normalizacion
	if(bandera==1)
	{
		for(i=0; i<=(n-1); i++)
		{
			MatrizS[i][n]=MatrizS[i][n]/MatrizS[i][i];
			MatrizS[i][i]=MatrizS[i][i]/MatrizS[i][i];
		}
		
	
		printf("\nVector Solucion:\n");  //Solucion del sistema
		for(i=0; i<=(n-1); i++)	
		{
			printf("%.3f\t", MatrizS[i][n]);
			printf("\n");
		}
	}
	printf("\n");
	
	
system("PAUSE");
	return 0;
}
