/***********************************************
 * \brief   Programa realizado para a Aula de Métodos Númericos em Fenômenos de Transporte
 *          Análise Numérica - Burden, Richard - 10ª edição - Pág. 78
 *          Algoritmo 2.4 - Método da Secante
 *
 * \param   Aproximação Inicial P0
 * \param   Aproximação Inicial P1
 * \return  Raiz da função
 *
 ***********************************************/

#include <stdio.h>
#include <math.h>
#include <locale.h>

#define tol 10e-16  /*valor mínimo de tolerância = 10e-16*/
#define n_max 100   /*valor máximo para iterações = 100*/

double f(double x){
    /*validação ex. 2 no ponto p0 = 0,5 e p1 = 0,785398*/   return (cos(x)-x);
    /*comparação com método da bissecção p0 = 1 e p1 = 2*/  /*return (pow(x,3)+4*pow(x,2)-10);*/
    /*exercicio 2.3-3a no ponto p0=3, p1=2 e n_max=3*/      /*return (pow(x,2) - 6);*/
    /*exercicio 2.3-8a no ponto p0=1 e p1=2 */              /*return (exp(x) + pow(2,-x) + 2 * cos(x) - 6);*/
    /*exercicio 2.3-8b no ponto p0=1,3 e p1=2 */            /*return (log(x - 1) + cos(x - 1));*/
    /*exercicio 2.3-8f em [p0,p1] = [0,1],[3,4],[6,7]*/     /*return (sin(x) - exp(-x));*/
    /*exercicio 2.3-13b em [p0,p1] = [-1,0], [0,1]*/        /*return (230 * pow(x,4) + 18 * pow(x,3) + 9 * pow(x,2) - 221 * x - 9);*/
    /*exercicio 2.3-18 em  [p0,p1] = [pi,pi/2]*/            /*return (1/2 + 1/4 * pow(x,2) - x * sin(x) - 1/2 * cos(2 * x));*/
    /*exercicio 2.3-24 em  [p0,p1] = [0,0057,0,0053]*/      /*return ((1500/x) * (pow((1 + x),240) - 1) - 750000);*/
    /*exercicio 2.3-27 em  [p0,p1] = [0,81,0,84]*/          /*return(((1 + x) / 2) * pow((x / (1 - x + pow(x,2))),21) - 0.5);*/

}

double Secante(double p0, double p1){
    double p2;
    int i = 1;

    do{
        p2 = p1 - (f(p1) * (p1 - p0)) / (f(p1) - f(p0));

        /*printf("i: %i \t p0: %.16f \t p1: %.16f \t p2: %.16f \t f(p2): %.16f \n", i, p0, p1, p2, f(p2));*/
        printf("i: %i p0: %.16f p1: %.16f p2: %.16f f(p2): %.16f \n", i, p0, p1, p2, f(p2));


        if (fabs(f(p2)) <= tol) {return p2;} else {p0 = p1; p1 = p2;}

        i++;
    }while( i <= n_max);

    printf("\nErro! O número máximo de iterações foi atingido.\n\n");
    return p2;
}

int main(void){

    setlocale(LC_ALL,"");

    double p, p0, p1;

    printf("Digite um número para a Aproximação P0: ");
    scanf("%lf", &p0);
    printf("Digite um número para a Aproximação P1: ");
    scanf("%lf", &p1);

    p = Secante(p0, p1);

    if (fabs(f(p)) <= tol)
        {printf("\nRaiz encontrada para P0 = %.16f e P1 = %.16f: %.16f \n\n", p0, p1, p);}
    else
        {printf("\nErro! Não encontrada raiz da função!\n\n");}

    return 0;
}
