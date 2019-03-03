/***********************************************
 * \brief   Programa realizado para a Aula de M�todos N�mericos em Fen�menos de Transporte
 *          An�lise Num�rica - Burden, Richard - 10� edi��o - P�g. 78
 *          Algoritmo 5.1 - M�todo de Euler
 *
 * \param   Extremidade a
 * \param   Extremidade b
 * \param   N�mero de Pontos da Malha
 * \param   Condi��o Inicial w0
 * \return  Aproxima��o w de y em (N+1) valores de t
 *
 ***********************************************/

#include <stdio.h>
#include <math.h>
#include <locale.h>

/*Fun��o f(solu��o da equa��o diferencial ordin�ria*/
float f(float t, float y)
{
    /*valida��o ex. 1 no intervalo [0,2], n = 10, w0 = 0,5*/        /*return(pow((t + 1), 2) - 0.5 * exp(t));*/
    /*exercicio 5.2-1a no intervalo [0,1], n = 2, w0 = 0,5*/        return(1 / (exp(2 * t) / 25) + (t * exp(3 * t) / 5) - (exp(3 * t) / 25));
    /*exercicio 5.2-1b no intervalo [2,3], n = 2, w0 = 2*/          /*return(t + (1 / (1 - t)));*/
    /*exercicio 5.2-2c no intervalo [2,3], n = 4, w0 = 2*/          /*return(pow((t - 2 + sqrt(2) * exp(1) * 1 / exp(t / 2)),2));*/
    /*exercicio 5.2-2d no intervalo [1,2], n = 4, w0 = 2*/          /*return((4 + cos(2) - cos(2 * t)) / (2 * pow(t, 2)));*/
    /*exercicio 5.2-5a no intervalo [1,2], n = 10, w0 = 1*/         /*return(t / (1 + log(t)));*/
    /*exercicio 5.2-5b no intervalo [1,3], n = 10, w0 = 0*/         /*return(t * tan(log(t)));*/
    /*exercicio 5.2-6c no intervalo [1,3], n = 10, w0 = -2*/        /*return((2 * t) / (1 - 2 * t));*/
    /*exercicio 5.2-6d no intervalo [0,1], n = 10, w0 = 1/3*/       /*return(sqrt(4 - 3 * exp(-pow(t,2))));*/
    /*exercicio 5.2-16 no intervalo [0,10], n = 100, w0 = 0*/       /*return(1);*/
}

/*Fun��o derivada f'*/
float dy(float t, float w)
{
    /*valida��o ex. 1 no intervalo [0,2], n = 10, w0 = 0,5*/        /*return(w - pow(t, 2) +1);*/
    /*exercicio 5.2-1a no intervalo [0,1], n = 2, w0 = 0,5*/        return(t * exp(3 * t) - 2 * w);
    /*exercicio 5.2-1b no intervalo [2,3], n = 2, w0 = 2*/          /*return(1 + pow((t - w),2));*/
    /*exercicio 5.2-2c no intervalo [2,3], n = 4, w0 = 2*/          /*return(-w + t * sqrt(w));*/
    /*exercicio 5.2-2d no intervalo [1,2], n = 4, w0 = 2*/          /*return(pow(t, -2) * (sin(2 * t) - 2 * t * w));*/
    /*exercicio 5.2-5a no intervalo [1,2], n = 10, w0 = 1*/         /*return(w / t - pow((w / t), 2));*/
    /*exercicio 5.2-5b no intervalo [1,3], n = 10, w0 = 0*/         /*return(1 + w / t + pow((w / t), 2));*/
    /*exercicio 5.2-6c no intervalo [1,3], n = 10, w0 = -2*/        /*return(pow(t, -1) * (pow(w, 2) +w));*/
    /*exercicio 5.2-6d no intervalo [0,1], n = 10, w0 = 1/3*/       /*return(-t * w + 4 * t * (1 / w));*/
    /*exercicio 5.2-16 no intervalo [0,10], n = 100, w0 = 0*/       /*return(1 / exp(0.188496 * t) * ((-1.20238) * cos(2 * t) + (0.735745) * sin(2 * t)));*/
}

/*Programa principal*/
int main(void)
{
    setlocale(LC_ALL,"");

    /*Declara��o de vari�veis*/
    double a, b, alpha, h, t, w;
    double y, e;
    int n, i;

    /*Entrada de par�metros*/
    printf("Digite o in�cio do intervalo [a]: ");
    scanf("%lf", &a);
    printf("Digite o fim do intervalo [b]: ");
    scanf("%lf", &b);
    printf("Digite o n�mero de pontos da malha [n]: ");
    scanf("%d", &n);
    printf("Digite a condi��o inicial do valor [alpha]: ");
    scanf("%lf", &alpha);

    /*Exibi��o dos par�metros de c�culo para o usu�rio*/
    printf ("\nOs par�metros digitados foram: [a]= %.3f [b]= %.3f [n]= %i [alpha] = %.3f \n", a, b, n, alpha);

    /*C�lculo do Passo h*/
    h = (b - a) / n;
    t = a;
    w = alpha;

    for(i=0; i<=n; i++)
    {
        /*C�lculo de ti*/
        t = a + i * h;

        /*C�lculo da solu��o da equa��o diferencial*/
        y = f(t , w);

        /*Erro (diferen�a do valor exato y com a aproxima��o w)*/
        e = fabs(y - w);

        /*Exibi��o dos valores calculados para o usu�rio*/
        printf("i= %d \t t= %.8f \t w= %.8f \t y= %.8f \t e= %.8f \n", i, t, w, y, e);

        /*Equa��o de diferen�a de Euler*/
        w = w + h * dy(t, w);
    }

    return 0;
}


