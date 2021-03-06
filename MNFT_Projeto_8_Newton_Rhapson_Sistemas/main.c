/***********************************************
 * \brief   Programa realizado para a Aula de M�todos N�mericos em Fen�menos de Transporte
 *          An�lise Num�rica - Burden, Richard - 10� edi��o - P�g. 716
 *          Algoritmo 10.1 - M�todo de Newton-Rhapson para Solu��o de Sistemas de Equa��es N�o Lineares
 *
 * \param   N�mero de Equa��es n
 * \param   Aproxima��es Iniciais w[n]
 * \return  Solu��o Aproximada w[n]
 *
 ***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#define max(a,b) (a > b) ? a : b    /*fun��o m�ximo*/
#define tol 10e-16                  /*valor m�nimo de toler�ncia = 10e-16*/
#define n_max 100                   /*valor m�ximo para itera��es = 100*/

/*declara��o das fun��es*/
void esc_piv(int, double **, int *, double *);
void sistema(int, double **, int *, double *, double *);
void df(int, int, double *, double **, double);
double funcao(int, double *);

int main(void)
{
	setlocale(LC_ALL,"");

	double **J, *w, *_w, *F, *X;
	int *L;
	int k, i, n;
	double h, erro, erro_max;

	/*Defini��o do h para o calculo da deriva��o num�rica*/
	h = tol * 10;
	if(h <= 1e-8){h = 0.00000001;}

	/*Entrada de par�metros*/
	printf("Digite o n�mero de inc�gnitas do sistema [n]: "); scanf("%d", &n);

	J = calloc((n+1), sizeof(double *));
	for (i=0; i<=n; i++){J[i] = calloc((n+1), sizeof(double));}
	w = calloc((n+1), sizeof(double));
	_w = calloc((n+1), sizeof(double));
	F = calloc((n+1), sizeof(double));
	X = calloc((n+1), sizeof(double));
	L = calloc((n+1), sizeof(int));

    printf("Digite as aproxima��es iniciais para o sistema w[n]: \n");
    for (i=1; i<=n; i++){printf("w[%d]= ", i); scanf ("%lf", &w[i]); _w[i] = w[i];}
    printf("\n");

	for(k=0; k<=n_max; k++)
    {

        /*Exibi��o dos valores calculados para o usu�rio*/
        printf("k= %d", k);
        for (i = 1; i <= n; i++){printf("\tw[%d]= %+.8f", i, w[i]);}
        printf("\terro= %+.8f", erro_max);
        printf("\n");

        /*C�lculo do vetor -F(x)*/
        for (i=1; i<=n; i++){F[i] = - funcao(i, w);}

        /*C�lculo da Matriz Jacobiana*/
        df(k, n, w, J, h);

        /*C�lculo da solu��o do Sistema Linear*/
        esc_piv(n, J, L, F);
        sistema(n, J, L, F, X);

        /*C�lculo do novo w*/
        for (i=1; i<=n; i++){w[i] = X[i] + w[i];}

        /*C�lculo do Res�duo*/
        erro_max = 0;
        for (i=1; i<=n; i++){erro = fabs(funcao(i, w)); erro_max = max(erro_max, erro);}



        /*Crit�rios de parada*/
        if(erro_max<=tol){printf("\nO m�todo atingiu a toler�ncia especificada.\n"); break;}
        if(k>=n_max){printf("\nO m�todo atingiu o n�mero m�ximo de itera��es especificado.\n"); break;}
    }

    printf("\nFim do programa.\n\n");

	for (i=0; i<=n; i++){free(J[i]);}
	free(J); free(w); free(_w); free(F); free(X); free(L);

	system("PAUSE");
	return 0;
}

/*C�lculo dos valores da fun��o*/
double funcao(int f, double *w)
{
    switch (f)
    {
        case 1 :
            /*valida��o ex. 2 com valores iniciais [0.1,0.1,-0.1]*/
            return(3 * w[1] - cos(w[2] * w[3]) - 0.5);

            /*Exerc�cio 10.2-1c com valores iniciais [0,0,0]
            return(w[1] * (1 - w[1]) + 4 * w[2] - 12);*/

            /*Exerc�cio 10.2-1d com valores iniciais [0,0,0]
            return(5 * pow(w[1], 2) - pow(w[2], 2));*/

            /*Exerc�cio 10.2-2a com valores iniciais [0,0,0]
            return(3 * w[1] - cos(w[2] * w[3]) - 0.5);*/

            /*Exerc�cio 10.2-2b com valores iniciais [0,0,0]
            return(pow(w[1], 2) + w[2] - 37);*/

            /*Exerc�cio 10.2-8a com valores iniciais [1,1,1,1]
            return(4 * w[1] - w[2] + w[3] - w[1] * w[4]);*/

            /*Exerc�cio 10.2-10a com valores iniciais [0,0,0]
            return(w[1] * exp(w[2] * 1) + w[3] * 1 - 10);*/
            break;
        case 2:
            /*valida��o ex. 2 com valores iniciais [0.1,0.1,-0.1]*/
            return(pow(w[1], 2) - 81 * pow((w[2] + 0.1), 2) + sin(w[3]) + 1.06);

            /*Exerc�cio 10.2-1c com valores iniciais [0,0,0]
            return(pow(w[1] - 2, 2) + pow(2 * w[2] - 3, 2) - 25);*/

            /*Exerc�cio 10.2-1d com valores iniciais [0,0,0]
            return(w[2] - 0.25 * (sin(w[1]) + cos(w[2])));*/

            /*Exerc�cio 10.2-2a com valores iniciais [0,0,0]
            return(4 * pow(w[1], 2) - 625 * pow(w[2], 2) + 2 * w[2] - 1);*/

            /*Exerc�cio 10.2-2b com valores iniciais [0,0,0]
            return(w[1] - pow(w[2], 2) - 5);*/

            /*Exerc�cio 10.2-8a com valores iniciais [1,1,1,1]
            return(w[1] - 2 * w[2] + 3 * w[3] - w[3] * w[4]);*/

            /*Exerc�cio 10.2-10a com valores iniciais [0,0,0]
            return(w[1] * exp(w[2] * 2) + w[3] * 2 - 12);*/

            break;
        case 3:
            /*valida��o ex. 2 com valores iniciais [0.1,0.1,-0.1]*/
            return(exp(-w[1] * w[2]) + 20 * w[3] + (10 * M_PI - 3) / 3);

            /*Exerc�cio 10.2-2a com valores iniciais [0,0,0]
            return(exp(-w[1] * w[2]) + 20 * w[3] + (10 * M_PI - 3) / 3);*/

            /*Exerc�cio 10.2-2b com valores iniciais [0,0,0]
            return(w[1] + w[2] + w[3] - 3);*/

            /*Exerc�cio 10.2-8a com valores iniciais [1,1,1,1]
            return(- w[1] + 3 * w[2] - 2 * w[3] - w[2] * w[4]);*/

            /*Exerc�cio 10.2-10a com valores iniciais [0,0,0]
            return(w[1] * exp(w[2] * 3) + w[3] * 3 - 15);*/

            break;
        case 4:
            /*Exerc�cio 10.2-8a com valores iniciais [1,1,1,1]
            return(pow(w[1], 2) + pow(w[2], 2) + pow(w[3], 2) - 1);*/

            break;
        default:
            return 0;
    }
}

/*C�lculo da Matriz Jacobiana*/
void df(int k, int n, double *w, double **J, double h)
{
    double *_w1, *_w2, *_w3, *_w4;
    _w1 = calloc((n+1), sizeof(double *));
    _w2 = calloc((n+1), sizeof(double *));
    _w3 = calloc((n+1), sizeof(double *));
    _w4 = calloc((n+1), sizeof(double *));
    int i, j, _i;

    for (i = 1; i <= n ; i++)
    {
        for (j = 1; j <= n; j++)
        {
            for (_i = 1; _i <= n; _i++){_w1[_i] = w[_i]; _w2[_i] = w[_i]; _w3[_i] = w[_i]; _w4[_i] = w[_i];}
            _w1[j] = _w1[j] - 2 * h;
            _w2[j] = _w2[j] - h;
            _w3[j] = _w3[j] + h;
            _w4[j] = _w4[j] + 2 * h;
            J[i][j] = (funcao(i, _w3) - funcao(i, w)) / h;
            /*J[i][j] = (funcao(i, _w3) - funcao(i, _w2)) / (2 * h);*/
            /*J[i][j] = (funcao(i, _w1) - 8 * funcao(i, _w2) + 8 * funcao(i, _w3) - funcao(i, _w4)) / (12 * h);*/
        }
    }
}

/*Pivotamento parcial de colunas com escalonamento*/
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

	/*Pivotamento de Colunas com escala */
	for (k = 1; k < n; k++)
	{
		rmax = 0.0;
		for (i = k ; i <= n; i++)
		{
			_i = L[i];
			ratio = fabs(A[_i][k]) / S[_i];
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

		for (i = k+1; i <= n; i++)
		{
			_i = L[i];
			xmult = A[_i][k] / A[_k][k];
			/*printf("\n\tmultiplicador[%d,%d]= %+.8f", i, k, xmult);*/
			A[_i][k] = 0.0;
			for (j = k+1; j<= n; j++){A[_i][j] -= xmult * A[_k][j];}
			B[_i] -= xmult * B[_k];
		}
	}
}

/*C�lculo da solu��o do sistema linear X*/
void sistema(int n, double **A, int *L, double *B, double *X)
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

	for (i = n-1; i>= 1; i--)
	{
		_i = L[i];
		soma = B[_i];
		for (j = i+1; j <= n ; j++){soma -= A[_i][j] * X[j];}
		X[i] = soma / A[_i][i];
	}
}
