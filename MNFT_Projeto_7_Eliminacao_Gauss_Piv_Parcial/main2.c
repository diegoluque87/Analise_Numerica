/***********************************************
 * \brief   Programa realizado para a Aula de Métodos Númericos em Fenômenos de Transporte
 *          Análise Numérica - Burden, Richard - 10ª edição - Pág. 417
 *          Algoritmo 6.3 - Eliminação de Gauss com Pivotamento Parcial com Escala
 *
 * \param   Número de Incógnitas do Sistema n
 * \param   Matriz Aumentada AB
 * \return  Vetor Solução Xn
 *
 ***********************************************/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <locale.h>

#define max(a,b) (a > b) ? a : b

void esc_piv(int, double **, int *, int *, double *);
void solucao(int, double **, int *, int *, double *, double *);

int main(void)
{
    setlocale(LC_ALL,"");

	double **A, *B, *X;
	int *L, *C;
	int i, j, n;

    printf("Digite o número de incógnitas do sistema [n]: "); scanf("%d", &n);

	A = calloc((n+1), sizeof(double *));
    for (i=0; i<=n; i++){A[i] = calloc((n+1), sizeof(double));}
	B = calloc((n+1), sizeof(double));
	X = calloc((n+1), sizeof(double));
	L = calloc((n+1), sizeof(int));
    C = calloc((n+1), sizeof(int));


    /*Entrada de parâmetros dependentes do número de equações*/
    printf("\nDigite os valores da Matriz A[i][j]: \n");
    for (i=1; i<=n; i++){for (j=1; j<=n; j++){printf("A[%d][%d]= ", i, j); scanf ("%lf", &A[i][j]);}}

	/*exemplo para debugação
	A[1][1] = 2.11  ;A[1][2] = -4.21   ;A[1][3] = 0.921;
	A[2][1] = 4.01  ;A[2][2] = 10.2    ;A[2][3] = -1.12;
	A[3][1] = 1.09  ;A[3][2] = 0.987   ;A[3][3] = 0.832;*/

	/*Entrada de parâmetros dependentes do número de equações*/
    printf("\nDigite os valores dos Resultados B[i]: \n");
	for (i=1; i<=n; i++){printf("B[%d]= ", i); scanf ("%lf", &B[i]);}

	/*exemplo para debugação
	B[1]    = 2.01  ;B[2]    = -3.09   ;B[3]    = 4.21;*/

	printf("\nMatrizes\n");
	printf("\nA=");
	for (i = 1; i <= n; i++){for (j = 1; j <= n; j++){printf("\t%+.8f\t", A[i][j]);} printf("\n");}
    printf("\nB=");
	for (i = 1; i <= n; i++){printf("\t%+.8f\t", B[i]); printf("\n");}

	esc_piv(n, A, L, C, B);
	solucao(n, A, L, C, B, X);

	printf("\nSolução\n");

	for (i = 1; i <= n; i++){printf("\nx[%d]= %+.8f", i, X[C[i]]);}
    printf("\n\nFim do programa. ");

	for (i = 0; i <= n; i++){free(A[i]);}
	free(A); free(X); free(B); free(L); free(C);

	system("PAUSE");
    return 0;
}

void esc_piv(int n, double **A, int *L, int *C, double *B)
{
	int i, j, k, _i, _j, _k;
	double S1[n+1], S2[n+1];
	double xmult, s1max, s2max, rmax, ratio;

    /*Pivotamento de colunas*/
    /*Definição do fator de escalas para colunas*/
	for (j = 1; j <= n; j++)
	{
		C[j] = j;
		s1max = 0.0;
		for (i = 1; i <= n; i++){s1max = max (s1max, fabs(A[i][j]));}
        S1[j] = s1max;
    }

    printf("\nDefinição do fator de escala para Colunas\n");
    for (i = 1; i <= n; i++){printf("\n\ts[%d]=%+.8f", i, S1[i]);}

    for (k = 1; k < n; k++)
	{
        printf("\n\nRealizando as Trocas de Colunas\n");

	    rmax = 0.0;
		for (j = k ; j <= n; j++)
		{
			_j = C[j];
			if (S1[_j] > rmax)
			{
				rmax = S1[_j];
				i = j;
			}
		}

        /*Troca a referência das colunas*/
		_k = C[i];
		C[i] = C[k];
		C[k] = _k;

        printf("\n\trmax= %+.8f ou seja, coluna %d troca com a coluna %d\n", rmax, i, C[i]);

        printf("\nA[%d]=",k);
        for (i = 1; i <= n; i++){for (j = 1; j <= n; j++){printf("\t%+.8f\t", A[i][C[j]]);} printf("\n");}
        printf("\nB[%d]=",k);
        for (i = 1; i <= n; i++){printf("\t%+.8f\n", B[i]);}
	}


    /*Pivotamento para Linhas*/
	/*Definição do fator de escalas para linhas*/
	for (i = 1; i <= n; i++)
	{
		L[i] = i;
		s2max = 0.0;
		for (j = 1; j <= n; j++){s2max = max (s2max, fabs(A[i][C[j]]));}
        S2[i] = s2max;
    }

    printf("\nDefinição do fator de escala para Linhas\n");
    for (i = 1; i <= n; i++){printf("\n\ts[%d]=%+.8f", i, S2[i]);}

	/*Pivotamento de Colunas com escala */
	for (k = 1; k < n; k++)
	{
        printf("\n\nRealizando as Eliminações\n");

	    rmax = 0.0;
		for (i = k ; i <= n; i++)
		{
			_i = L[i];
			ratio = fabs(A[_i][C[k]]) / S2[_i];
			printf("\n\tr[%d]= %+.8f", i, ratio);
			if (ratio > rmax)
			{
				rmax = ratio;
				j = i;
			}
		}

        /*Troca a referência das linhas*/
		_k = L[j];
		L[j] = L[k];
		L[k] = _k;

        printf("\n\trmax= %+.8f ou seja, linha %d troca com a linha %d\n", rmax, j, L[j]);

        printf("\nA[%d]=",k);
        for (i = 1; i <= n; i++){for (j = 1; j <= n; j++){printf("\t%+.8f\t", A[L[i]][C[j]]);} printf("\n");}
        printf("\nB[%d]=",k);
        for (i = 1; i <= n; i++){printf("\t%+.8f\n", B[L[i]]);}

		for (i = k+1; i <= n; i++)
		{
			_i = L[i];
			xmult = A[_i][C[k]] / A[_k][C[k]];
            printf("\n\tmultiplicador[%d,%d]= %+.8f", i, k, xmult);
			A[_i][C[k]] = 0.0;
			for (j = k+1; j<= n; j++){A[_i][C[j]] -= xmult * A[_k][C[j]];}
			B[_i] -= xmult * B[_k];
		}

        printf("\n\nA[%d]=",k);
        for (i = 1; i <= n; i++){for (j = 1; j <= n; j++){printf("\t%+.8f\t", A[L[i]][C[j]]);} printf("\n");}
        printf("\nB[%d]=",k);
        for (i = 1; i <= n; i++){printf("\t%+.8f\t", B[L[i]]); printf("\n");}
    }
}

/*Calculo da solução X*/
void solucao(int n, double **A, int *L, int *C, double *B, double *X)
{
	int i, j, k, _i, _k, _n;
	double soma;

	for (k = 1; k < n ; k++)
	{
		_k = L[k];
		for (i = k+1; i <= n; i++)
		{
			_i = L[i];
			B[_i] -= A[_i][C[k]] * B[_k];
		}
	}
	_n = L[n];
	X[C[n]] = B[_n] / A[_n][C[n]];

    printf("\nSistema Linear de Incógnitas\n");
    printf("\nA[%d]=",k);
    for (i = 1; i <= n; i++){for (j = 1; j <= n; j++){printf("\t%+.8f\t", A[L[i]][C[j]]);} printf("\n");}
    printf("\nB[%d]=",k);
    for (i = 1; i <= n; i++){printf("\t%+.8f\t", B[L[i]]); printf("\n");}

	for (i = n-1; i>= 1; i--)
	{
		_i = L[i];
		soma = B[_i];
		for (j = i+1; j <= n ; j++){soma -= A[_i][C[j]] * X[C[j]];}
		X[C[i]] = soma / A[_i][C[i]];
	}
}


