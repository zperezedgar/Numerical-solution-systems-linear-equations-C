#include <stdio.h>
#include <stdlib.h>
#include <math.h>  //////////corrigiendo!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!para la inversa

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

	double	MatrizC[n][2*n+1];		//Matriz de elementos (coeficientes) aumentada
	double	MatrizS[n][2*n+1];		//Matriz solucion

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
		for(j=n+1; j<=(2*n); j++)
		{
			if((j-n)==(i+1))
			{
				MatrizC[i][j]=1;
				MatrizS[i][j]=1;
			}
			else
			{
				MatrizC[i][j]=0;
				MatrizS[i][j]=0;
			}
		}
	}
		

	//Creacion de la matriz diagonal
	for(k=0; k<=(n-1); k++) 
	{
		if(MatrizS[k][k]==0)
		{
		
		//****************** PIVOTEO PARCIAL ********************************/
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
			dummy=MatrizS[p][2*n];
			MatrizS[p][2*n]=MatrizS[k][2*n];
			MatrizS[k][2*n]=dummy;
			cont++;
		}
		//******************************************************************/
	}
		
		for(i=0; i<=(n-1); i++)
		{
			if(i!=k)
			{
				factor=MatrizS[i][k]/MatrizS[k][k];
			
				for(j=0; j<=(2*n); j++)
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
		for(j=0; j<=(n); j++)	//Para visualizar la matriz inversa hasta este paso(matriz identidad), ir hasta j<=2n
		{
			printf("%.1f\t", MatrizC[i][j]);
		}
		printf("\n");
	}	
	
	
	printf("\nMatriz Diagonal:\n");
	for(i=0; i<=(n-1); i++)	
	{
		for(j=0; j<=(n); j++)	//Para visualizar la matriz inversa hasta este paso, ir hasta j<=2n
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
	printf("\nDeterminante= %.1f\n", D);
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
		for(i=0; i<=(n-1); i++)
		{
			for(j=n; j<=(2*n); j++)
			{
				MatrizS[i][j]=MatrizS[i][j]/MatrizS[i][i];
			}

			MatrizS[i][i]=MatrizS[i][i]/MatrizS[i][i];
		}
		
	if(bandera==1)
	{
		printf("\nVector Solucion:\n");  //Solucion del sistema
		for(i=0; i<=(n-1); i++)	
		{
			printf("%.4f\t", MatrizS[i][n]);
			printf("\n");
		}
	}
		
		printf("\nMatriz Inversa:\n");  //Muestra la matriz(inversa) extendida
		for(i=0; i<=(n-1); i++)	
		{
			for(j=0; j<=(2*n); j++)
			{//poner un if j no es igual a n para que no imprima el vector solucion!!
				if(j!=n)
				{
					if(j<n)
					{
						printf("%.0f\t", MatrizS[i][j]);	
					}
					else
					{
						printf("%.3f\t", MatrizS[i][j]);	
					}
				}
			}
			printf("\n");
		}
	
	
system("PAUSE");
	return 0;
}
