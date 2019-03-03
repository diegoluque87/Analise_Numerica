/********************************************//**
 * \brief   Programa realizado para a Aula de Métodos Númericos em Fenômenos de Transporte
 *          Aula 2 - Método da Biseccção
 *
 * \param   Inicio do intervalo a ser estudado
 * \param   Fim do intervalo a ser estudado
 * \return  Raiz da função dentro do intervalo
 *
 ***********************************************/

#include <stdio.h>
#include <math.h>

double f(double x){
    /*return (pow(x,3)+4*pow(x,2)-10);*/
    /*return (sqrt(x) - cos(x));*/
    /*return (pow(x,3)-x);*/
    return(cos(x));
}

double biseccao(double a, double b){
    double c, c_anterior;
    int i = 1;

    do{
        if(f(a)==0) {return a;}
        if(f(b)==0) {return b;}

        c = (a+b)/2;
        if(f(c)==0) {return c;}

        if(f(a) * f(c) > 0) {a = c;} else {b = c;}

        //printf("a: %.20f \t b: %.20f \t c: %.20f \t i: %i \n", a, b, f(c), i);

        if (c == c_anterior) {return c;} else {c_anterior = c;}

        i++;
    } while (1);

    return c;
}

int main(void){
    double a, b, raiz, a_anterior, b_inicial;

    printf("Digite um numero para o inicio do intervalo: ");
    scanf("%lf", &a);
    printf("Digite um numero para o fim do intervalo: ");
    scanf("%lf", &b);

    a_anterior = a;
    b_inicial = b;

    int i = -10;

    do{

        do{
            b = a + pow(10,i);

            raiz = biseccao(a, b);

            if (f(raiz) == 0) {
                printf("\nRaiz no intervalo [%f,%f]: %.20f \n", a, b, raiz);
                a = raiz;
                break;
            }
            else {}

            i++;
        }while (i <= 15);

        i = -10;
        b = b_inicial;

    }while (a != a_anterior);

    return 0;
}


