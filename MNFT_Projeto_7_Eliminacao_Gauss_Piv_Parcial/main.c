/***********************************************
 * \brief   Programa realizado para a Aula de M�todos N�mericos em Fen�menos de Transporte
 *          An�lise Num�rica - Burden, Richard - 10� edi��o - P�g. 417
 *          Algoritmo 6.3 - Elimina��o de Gauss com Pivotamento Parcial com Escala
 *
 * \param   N�mero de Inc�gnitas do Sistema n
 * \param   Matriz Aumentada AB
 * \return  Vetor Solu��o Xn
 *
 ***********************************************/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <locale.h>

#define max(a,b) (a > b) ? a : b

void esc_piv(int, double **, int *, double *);
void solucao(int, double **, int *, double *, double *);

int main(void)
{
	setlocale(LC_ALL,"");

	double **A, *B, *X;
	int *L;
	int i, j, n;

	/*Entrada de par�metros
	printf("Digite o n�mero de inc�gnitas do sistema [n]: "); scanf("%d", &n);*/
	n=3;

	A = calloc((n+1), sizeof(double *));
	for (i=0; i<=n; i++){A[i] = calloc((n+1), sizeof(double));}
	B = calloc((n+1), sizeof(double));
	X = calloc((n+1), sizeof(double));
	L = calloc((n+1), sizeof(int));


	/*Entrada de par�metros dependentes do n�mero de equa��es
	printf("\nDigite os valores da Matriz A[i][j]: \n");
	for (i=1; i<=n; i++){for (j=1; j<=n; j++){printf("A[%d][%d]= ", i, j); scanf ("%lf", &A[i][j]);}}*/

	/*exemplo para debuga��o*/
	A[1][1] = 2.11  ;A[1][2] = -4.21   ;A[1][3] = 0.921;
	A[2][1] = 4.01  ;A[2][2] = 10.2    ;A[2][3] = -1.12;
	A[3][1] = 1.09  ;A[3][2] = 0.987   ;A[3][3] = 0.832;

	/*Entrada de par�metros dependentes do n�mero de equa��es
	printf("\nDigite os valores dos Resultados B[i]: \n");
	for (i=1; i<=n; i++){printf("B[%d]= ", i); scanf ("%lf", &B[i]);}*/

	/*exemplo para debuga��o*/
	B[1]    = 2.01  ;B[2]    = -3.09   ;B[3]    = 4.21;

	printf("\nMatrizes\n");
	printf("\nA=");
	for (i = 1; i <= n; i++){for (j = 1; j <= n; j++){printf("\t%+.8f\t", A[i][j]);} printf("\n");}
	printf("\nB=");
	for (i = 1; i <= n; i++){printf("\t%+.8f\t", B[i]); printf("\n");}

	esc_piv(n, A, L, B);
	solucao(n, A, L, B, X);

	printf("\nSolu��o\n");

	for (i = 1; i <= n; i++){printf("\nx[%d]= %+.8f", i, X[i]);}
	printf("\n\nFim do programa. ");

	for (i = 0; i <= n; i++){free(A[i]);}
	free(A); free(X); free(B); free(L);

	system("PAUSE");
	return 0;
}

void esc_piv(int n, double **A, int *L, double *B)
{
	int i, j, k, _i, _k;
	double S[n+1];
	double xmult, smax, rmax, ratio;

	/*Defini��o do fator de escala s*/
	for (i = 1; i <= n; i++)
	{
		L[i] = i;
		smax = 0.0;
		for (j = 1; j <= n; j++){smax = max (smax, fabs(A[i][j]));}
        S[i] = smax;
	}

	printf("\nDefini��o do fator de escala\n");
	for (i = 1; i <= n; i++){printf("\n\ts[%d]=%+.8f", i, S[i]);}

	/*Pivotamento de Colunas com escala */
	for (k = 1; k < n; k++)
	{
		printf("\n\nRealizando as Elimina��es\n");

		rmax = 0.0;
		for (i = k ; i <= n; i++)
		{
			_i = L[i];
			ratio = fabs(A[_i][k]) / S[_i];
			printf("\n\tr[%d]= %+.8f", i, ratio);
			if (ratio > rmax)
			{
				rmax = ratio;
				j = i;
			}
		}

	/*Troca a refer�ncia das linhas*/
	_k = L[j];
	L[j] = L[k];
	L[k] = _k;

	printf("\n\trmax= %+.8f ou seja, linha %d troca com a linha %d\n", rmax, j, L[j]);

	printf("\nA[%d]=",k);
	for (i = 1; i <= n; i++){for (j = 1; j <= n; j++){printf("\t%+.8f\t", A[L[i]][j]);} printf("\n");}
	printf("\nB[%d]=",k);
	for (i = 1; i <= n; i++){printf("\t%+.8f\n", B[L[i]]);}

		for (i = k+1; i <= n; i++)
		{
			_i = L[i];
			xmult = A[_i][k] / A[_k][k];
			printf("\n\tmultiplicador[%d,%d]= %+.8f", i, k, xmult);
			A[_i][k] = 0.0;
			for (j = k+1; j<= n; j++){A[_i][j] -= xmult * A[_k][j];}
			B[_i] -= xmult * B[_k];
		}

	printf("\n\nA[%d]=",k);
	for (i = 1; i <= n; i++){for (j = 1; j <= n; j++){printf("\t%+.8f\t", A[L[i]][j]);} printf("\n");}
	printf("\nB[%d]=",k);
	for (i = 1; i <= n; i++){printf("\t%+.8f\t", B[L[i]]); printf("\n");}
	}
}

/*Calculo da solu��o X*/
void solucao(int n, double **A, int *L, double *B, double *X)
{
	int i, j, k, _i, _k, _n;
	double soma;

	for (k = 1; k < n ; k++)
	{
		_k = L[k];
		for (i = k+1; i <= n; i++)
		{
			_i = L[i];
			B[_i] -= A[_i][k] * B[_k];
		}
	}
	_n = L[n];
	X[n] = B[_n] / A[_n][n];

	printf("\nSistema Linear de Inc�gnitas\n");
	printf("\nA[%d]=",k);
	for (i = 1; i <= n; i++){for (j = 1; j <= n; j++){printf("\t%+.8f\t", A[L[i]][j]);} printf("\n");}
	printf("\nB[%d]=",k);
	for (i = 1; i <= n; i++){printf("\t%+.8f\t", B[L[i]]); printf("\n");}

	for (i = n-1; i>= 1; i--)
	{
		_i = L[i];
		soma = B[_i];
		for (j = i+1; j <= n ; j++){soma -= A[_i][j] * X[j];}
		X[i] = soma / A[_i][i];
	}
}
