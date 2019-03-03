/***********************************************
* \brief    Programa realizado para a Aula de M�todos N�mericos em Fen�menos de Transporte
*           An�lise Num�rica - Burden, Richard - 10� edi��o - P�g. 53
*           Algoritmo 2.1 - M�todo da Bisecc��o
*
* \param    Inicio do intervalo a ser estudado
* \param    Fim do intervalo a ser estudado
* \return   Raiz da fun��o dentro do intervalo
*
***********************************************/
#include <stdio.h>
#include <math.h>
#include <locale.h>
double f(double x){
    /*valida��o ex. 1 no intervalo [1,2]*/      return (pow(x,3)+4*pow(x,2)-10);
    /*exercicio 2.1-1 no intervalo [0,1] */     /*return (sqrt(x) - cos(x));*/
    /*exercicio 2.1-6a no intervalo [1,2]*/     /*return (3*x-exp(x));*/
    /*exercicio 2.1-6c no intervalo [1,2]*/     /*return (pow(x,2)-4*x+4-log(x));*/
    /*exercicio 2.1-7 no intervalo [1,5,2]*/    /*return (2*sin(x)-x);*/
    /*exercicio 2.1-9 no intervalo [1,2]*/      /*return (cos(exp(x)-2)-(exp(x)-2));*/
    /*exercicio 2.1-13 no intervalo [,]*/       /*return (pow(x,3)-25);*/
}
double biseccao(double a, double b, double tol, int n_max){
    double c, c_anterior;
    int i = 1;
    do{
        c = a + (b - a) / 2;
        printf("i: %i \t a: %.16f \t b: %.16f \t c: %.16f \t f(c): %.16f \n", i, a, b, c, f(c));
        if(f(a) * f(c) > 0) {a = c;} else {b = c;}
        if ((fabs(c - c_anterior) <= tol) && (fabs(f(c)) <= tol)) {return c;} else {c_anterior = c;}
        i++;
    } while (i <= n_max);
    printf("\nErro! O n�mero m�ximo de itera��es foi atingido.\n\n");
    return c;
}
int main(void){
    setlocale(LC_ALL,"");
    double a, b, c, tol;
    int n_max;
    tol = 10e-16; /*valor m�nimo de toler�ncia = 10e-16*/
    n_max = 100; /*valor m�ximo para itera��es = 100*/
    do{
        printf("Digite um n�mero para o in�cio do intervalo: ");
        scanf("%lf", &a);
        printf("Digite um n�mero para o fim do intervalo: " );
        scanf("%lf", &b);
        if (a >= b) {printf("\nErro! O valor do in�cio do intervalo deve ser inferior ao valor do fim do intervalo.\n\n");}
        else {break;}
    }while(1);
    c = biseccao(a, b, tol, n_max);
    if (fabs(f(c)) <= tol)
        {printf("\nRaiz no intervalo [%f,%f]: %.16f \n\n", a, b, c);}
    else
        {printf("\nErro! N�o encontrada raiz da fun��o no intervalo [%f,%f] \n\n", a, b);}
    return 0;
}
