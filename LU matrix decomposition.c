#include <stdio.h>
#include <stdlib.h>

int n, r, c, j, i, k;
double elemento, factor, producto;

int main(int argc, char *argv[]) 
{
	//ELIMINACION HACIA ADELANTE (Reduccion de Gauss)
	
	//Solicitar matriz de n X n
	printf("\nBIENVENIDO AL ALGORITMO PARA LA DESCOMPOSICION [L][U] DE UNA MATRIZ\n");
	printf("\nIntroduzca el tamanio de la Matriz Cuadrada\n");
	scanf("%i", &n);
	
	double	MatrizC[n][n];		//Matriz de elementos (coeficientes) 
	double	MatrizL[n][n];		//Matriz L
	double	MatrizU[n][n];		//Matriz U
	
	r=1;
	for(i=0; i<n; i++)
	{
		c=1;
		for(j=0; j<n; j++)
		{
			printf("\nIngrese Dato%i%i\n", r, c);
			scanf("%lf", &elemento);
			MatrizC[i][j]=elemento;
			MatrizU[i][j]=elemento;
			c++;
		}
		r++;
	}	
	
	
	//Relleno de la Matriz L (Matriz Unitaria)
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			if(i==j)
			{
				MatrizL[i][j]=1.0;
			}
			else
			{
				MatrizL[i][j]=0.0;
			}	
		}
	}
	

	//Elimicacion hacia adelante (Sin Pivoteo)
	for(k=0; k<n; k++)
	{
		//NO PIVOTEO
		
		for(i=k+1; i<n; i++)
		{
			factor=MatrizU[i][k]/MatrizU[k][k];
			MatrizL[i][k]=factor;
			
			for(j=0; j<n; j++)
			{
				MatrizU[i][j]=MatrizU[i][j]-((MatrizU[k][j])*factor);
			}
				
		}
	}
	
	system("cls");
	printf("\n");
	printf("\nMatriz ingresada:\n");
	for(i=0; i<n; i++)	
	{
		for(j=0; j<n; j++)	
		{
			printf("%.3f\t", MatrizC[i][j]);
		}
		printf("\n");
	}	
	
	printf("\n");
	printf("\nFactorizaciones:\n");
	printf("\nMatriz [L]:\n");
	for(i=0; i<n; i++)	
	{
		for(j=0; j<n; j++)	
		{
			printf("%.3f\t", MatrizL[i][j]);
		}
		printf("\n");
	}

	printf("\nMatriz [U]:\n");
	for(i=0; i<n; i++)	
	{
		for(j=0; j<n; j++)	
		{
			printf("%.3f\t", MatrizU[i][j]);
		}
		printf("\n");
	}
	
	//Calcular producto [L][U]
	double MatrizLU[n][n];

	for(i=0; i<n; i++) //algoritmo para la multiplicacion de matrices
	{
		for(j=0; j<n; j++)
		{
			producto=0;
							
			for(k=0; k<n; k++)
			{
				producto=producto+(MatrizL[i][k]*MatrizU[k][j]);
			}
			MatrizLU[i][j]=producto;
		}			
	}
	
	printf("\n");
	printf("\nComprobacion:\n");
	printf("\nMatriz producto [L][U]:\n");
	for(i=0; i<n; i++)	
	{
		for(j=0; j<n; j++)	
		{
			printf("%.3f\t", MatrizLU[i][j]);
		}
		printf("\n");
	}
	
	printf("\n");
	
	system("PAUSE");
	return 0;
}
