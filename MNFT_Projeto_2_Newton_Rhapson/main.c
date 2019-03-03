/***********************************************
 * \brief   Programa realizado para a Aula de Métodos Númericos em Fenômenos de Transporte
 *          Análise Numérica - Burden, Richard - 10ª edição - Pág. 73
 *          Algoritmo 2.3 - Método de Newton Rhapson
 *
 * \param   Aproximação Inicial P0
 * \return  Raiz da função
 *
 ***********************************************/

#include <stdio.h>
#include <math.h>
#include <locale.h>

#define tol 10e-16  /*valor mínimo de tolerância = 10e-16*/
#define n_max 100   /*valor máximo para iterações = 100*/

double f(double x){
    /*validação ex. 1 no ponto p0 = 0,785398*/  return (cos(x)-x);
    /*comparação com método da bissecção*/      /*return (pow(x,3)+4*pow(x,2)-10);*/
    /*exercicio 2.3-1 no ponto p0=1 */          /*return (pow(x,2) - 6);*/
    /*exercicio 2.3-6a no ponto p0=2 */         /*return (exp(x) + pow(2,-x) + 2 * cos(x) - 6);*/
    /*exercicio 2.3-6b no ponto p0=2 */         /*return (log(x - 1) + cos(x - 1));*/
    /*exercicio 2.3-6f no ponto p0=0, 3 e 6 */  /*return (sin(x) - exp(-x));*/
    /*exercicio 2.3-13 no ponto p0=-1 e 0*/     /*return (230 * pow(x,4) + 18 * pow(x,3) + 9 * pow(x,2) - 221 * x - 9);*/
    /*exercicio 2.3-18 no ponto p0=pi()/2*/     /*return (1/2 + 1/4 * pow(x,2) - x * sin(x) - 1/2 * cos(2 * x));*/
}
double df(double x){
    /*validação ex. 1 no intervalo [1,2]*/      return (-sin(x)-1);
    /*comparação com método da bissecção*/      /*return (3 * pow(x,2) + 8 * x);*/
    /*exercicio 2.3-1 no ponto p0=1 */          /*return (exp(x) - log(2) / pow(2,x) - 2 * sin(x));*/
    /*exercicio 2.3-6b no ponto p0=2 */         /*return (1 / (x - 1) - sin(x - 1));*/
    /*exercicio 2.3-6f no ponto p0=0, 3 e 6 */  /*return (cos(x) + exp(-x));*/
    /*exercicio 2.3-13 no ponto p0=-1 e 0*/     /*return (920 * pow(x,3) + 54 * pow(x,2) + 18 * x - 221);*/
    /*exercicio 2.3-18 no ponto p0=pi()/2*/     /*return (-1/2 * ( x - 2 * sin(x))*(2 * cos(x) - 1));*/
}

double Newton(double p0){
    double p1;
    int i = 1;

    do{
        p1 = p0 - (f(p0) / df(p0));

        printf("i: %i \t p0: %.16f \t p1: %.16f \t f(p1): %.16f \n", i, p0, p1, f(p1));

        if (fabs(f(p1)) <= tol) {return p1;} else {p0 = p1;}

        i++;
    }while( i <= n_max);

    printf("\nErro! O número máximo de iterações foi atingido.\n\n");
    return p1;
}

int main(void){

    setlocale(LC_ALL,"");

    double p, p0;

    printf("Digite um número para a Aproximação P0: ");
    scanf("%lf", &p0);

    p = Newton(p0);

    if (fabs(f(p)) <= tol)
        {printf("\nRaiz encontrada para P0 = %.16f: %.16f \n\n", p0, p);}
    else
        {printf("\nErro! Não encontrada raiz da função!\n\n");}

    return 0;
}
