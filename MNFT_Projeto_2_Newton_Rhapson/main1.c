/* Método da Bisecção */
/* Exercício 2.1 - Análise Numérica - Richard L. Burden */

#include <stdio.h>
#include <math.h>

double f(double x){

    return (pow(x,3)+4*pow(x,2)-10);
}

double bissec(double a, double b, double tol, int nmax){
    double p, p_anterior;
    int i = 1;

      do{

            /*if(fabs(f(a)) <= tol) {return a;}
            if(fabs(f(b)) <= tol) {return b;}*/

            p = a + (b - a)/ 2;

            /*if(fabs(f(p)) <= tol) {return p;}*/

            if(f(a) * f(p) > 0) {a = p;} else {b = p;}

            printf("i: %i \t a: %f \t b: %f \t p: %f \t f(p): %f \n", i, a, b, p, f(p));

            if (fabs(p - p_anterior) <= tol) {return p;} else {p_anterior = p;}

            i++;

        }while (i <= nmax);

    printf ("\n Atingido quantidade maxima de interacoes");
    return p;
}

int main (void){

    double a, b, p, tol;
    int nmax;

    nmax = 40;
    tol = 10e-5;

    do{
        printf("Digite um número para o início do intervalo: ");
        scanf("%lf", &a);
        printf("Digite um número para o fim do intervalo: " );
        scanf("%lf", &b);

        if (a >= b) {printf ("O inicio do intervalo devera ser inferior ao final do intervalo");}
        else {break;}

    }while(1);

    p = bissec(a, b, tol, nmax);

    if(fabs(f(p)<=tol))
        {printf("\nRaiz no intervalo [%f, %f]: %.20f \n\n", a, b, p);}
    else
        {printf("\nErro! Nao encontrada raiz da funcao no intervalo [%f,%f] \n\n", a, b);}

}
