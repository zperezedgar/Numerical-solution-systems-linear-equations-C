#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n, r, i, j, c, contdom, k, h;
double mayor, elemento, suma;
int Nmax, conterrores=0, iteraciones=0;
double Emin;

int main(int argc, char *argv[]) 
{
	//Solicitar matriz aumentada de n X (n+1)
	printf("\nBIENVENIDO AL ALGORITMO DE GAUSS-SEIDEL PARA UN SISTEMA DE ECUACIONES LINEALES\n");
	printf("\nIntroduzca el Numero de Variables\n");
	scanf("%i", &n);
	printf("\nIntroduzca el Error Minimo (Sugerencia: 10E-06)\n");
	scanf("%lf", &Emin);
	printf("\nIntroduzca el Numero Maximo de Iteraciones (Sugerencia: 1000)\n");
	scanf("%i", &Nmax);

	double	MatrizC[n][n+1];		//Matriz de elementos (coeficientes) aumentada
	double	MatrizS[n][n+1];		//Matriz solucion
	double  temp[n][n+1];
	double	Xant[n];
	double	Xact[n];
	double	Error[n];
	
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
	
	
	k=0;
	for(j=0; j<n; j++)
	{
		mayor=0;
		
		for(i=0; i<n; i++)
		{
			if(fabs(MatrizS[i][j])>=fabs(mayor))
			{
				mayor=MatrizS[i][j];
			}
		}
	
	//	printf("\nMayor: %f\n", mayor);
		
		for(i=0; i<n-1; i++)
		{
			if(MatrizS[i][j]==mayor)
			{
				//////////////////////////
				for(h=0; h<n+1; h++) //algortimo burbuja
				{
					temp[i][h]=MatrizS[i][h];
				}
				
				for(h=0; h<n+1; h++) 
				{
					MatrizS[i][h]=MatrizS[k][h];
				}
				
				for(h=0; h<n+1; h++) 
				{
					MatrizS[k][h]=temp[i][h];
				}
				//////////////////////////
			}
		}
		k++;
	}
	
	contdom=0;
	for(i=0; i<n; i++)
	{
		suma=0;
		for(j=0; j<n; j++)
		{
			if(j!=i)
			{
				suma=suma+fabs(MatrizS[i][j]);
			}
		}
		
		if(fabs(MatrizS[i][i])>suma)
		{
			contdom++;
		}
	}

	printf("\nMatriz ingresada:\n");
	for(i=0; i<=(n-1); i++)	
	{
		for(j=0; j<=n; j++)	
		{
			printf("%.3f\t", MatrizC[i][j]);
		}
		printf("\n");
	}

	if(contdom==n)
	{
		printf("\n\nEl Sistema es Diagonalmente Dominante!\n");
	}
	else
	{
		printf("\n\nEl Sistema No es Diagonalmente Dominante.\n");
	}

	
	for(i=0; i<n; i++)
	{
		Xant[i]=0;
	}


	for(i=0; i<n; i++)
	{
		Error[i]=1.0;
	}

	while((conterrores<n)&&(iteraciones<Nmax))
	{
		
		for(i=0; i<n; i++)
		{
			suma=0;
			for(j=0; j<n; j++)
			{
				if(i!=j)
				{
					suma+=MatrizS[i][j]*Xant[j];	
				}
			}
				
				Xact[i]=(MatrizS[i][n]-suma)/(MatrizS[i][i]);
				
				if(iteraciones!=0)
				{
					Error[i]=fabs((Xact[i]-Xant[i])/Xact[i]);
				}	
		}
			
			conterrores=0;
			for(i=0; i<n; i++)
			{
				if(Error[i]<=Emin)
				{
					conterrores++;
				}
			}
			
			for(i=0; i<n; i++)
			{
				Xant[i]=Xact[i];
			}	
			
			iteraciones++;
		
	}
	
	printf("\nVector Solucion:\n");
	for(i=0; i<=(n-1); i++)	
	{
		printf("%.3f\t", Xact[i]);
		printf("\n");
	}
	
	printf("\nLos Errores son:\n");
	for(i=0; i<=(n-1); i++)	
	{
		printf("%.9e\t", Error[i]);
		printf("\n");
	}
	
	printf("\nEl numero de Iteraciones fue: %i\n", iteraciones);
	printf("\n");
	
	system("PAUSE");
	return 0;
}
