/***********************************************
 * \brief   Programa realizado para a Aula de Métodos Númericos em Fenômenos de Transporte
 *          Análise Numérica - Burden, Richard - 10ª edição - Pág. 316
 *          Algoritmo 5.2 - Método de Runge-Kutta de 4ª ordem
 *
 * \param   Extremidade a
 * \param   Extremidade b
 * \param   Número de Pontos da Malha
 * \param   Condição Inicial w0
 * \return  Aproximação w de y em (N+1) valores de t
 *
 ***********************************************/

#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <ctype.h>


/*Função f(solução da equação diferencial ordinária*/
float f(float t, float y)
{
    /*validação ex. 1 no intervalo [0,2], n = 10, w0 = 0,5*/         return(pow((t + 1), 2) - 0.5 * exp(t));
    /*exercicio 5.4-13a no intervalo [0,1], n = 2, w0 = 0,5*/        /*return((t * exp(3 * t) / 5) - (exp(3 * t) / 25) + (pow(exp(2 * t), -1) / 25));*/
    /*exercicio 5.4-13b no intervalo [2,3], n = 2, w0 = 2*/          /*return(t + (1 / (1 - t)));*/
    /*exercicio 5.4-14c no intervalo [2,3], n = 4, w0 = 2*/          /*return(pow((t - 2 + sqrt(2) * exp(1) * 1 / exp(t / 2)),2));*/
    /*exercicio 5.4-14d no intervalo [1,2], n = 4, w0 = 2*/          /*return((4 + cos(2) - cos(2 * t)) / (2 * pow(t, 2)));*/
    /*exercicio 5.4-15a no intervalo [1,2], n = 10, w0 = 1*/         /*return(t / (1 + log(t)));*/
    /*exercicio 5.4-15b no intervalo [1,3], n = 10, w0 = 0*/         /*return(t * tan(log(t)));*/
    /*exercicio 5.4-16c no intervalo [1,3], n = 10, w0 = -2*/        /*return((2 * t) / (1 - 2 * t));*/
    /*exercicio 5.4-16d no intervalo [0,1], n = 10, w0 = 1/3*/       /*return(sqrt(4 - 3 * exp(-pow(t,2))));*/
    /*exercicio 5.4-28a no intervalo [0,600], n = 30, w0 = 8*/       /*return(1);*/
    /*exercicio 5.4-28b no intervalo [0,1600], n = 80, w0 = 08*/     /*return(1);*/
}

/*Função derivada f'*/
float dy(float t, float w)
{
    /*validação ex. 1 no intervalo [0,2], n = 10, w0 = 0,5*/         return(w - pow(t, 2) +1);
    /*exercicio 5.4-13a no intervalo [0,1], n = 2, w0 = 0,5*/        /*return(t * exp(3 * t) - 2 * w);*/
    /*exercicio 5.4-13b no intervalo [2,3], n = 2, w0 = 2*/          /*return(1 + pow((t - w),2));*/
    /*exercicio 5.4-14c no intervalo [2,3], n = 4, w0 = 2*/          /*return(-w + t * sqrt(w));*/
    /*exercicio 5.4-14d no intervalo [1,2], n = 4, w0 = 2*/          /*return(pow(t, -2) * (sin(2 * t) - 2 * t * w));*/
    /*exercicio 5.4-15a no intervalo [1,2], n = 10, w0 = 1*/         /*return(w / t - pow((w / t), 2));*/
    /*exercicio 5.4-15b no intervalo [1,3], n = 10, w0 = 0*/         /*return(1 + w / t + pow((w / t), 2));*/
    /*exercicio 5.4-16c no intervalo [1,3], n = 10, w0 = -2*/        /*return(pow(t, -1) * (pow(w, 2) +w));*/
    /*exercicio 5.4-16d no intervalo [0,1], n = 10, w0 = 1/3*/       /*return(-t * w + 4 * t * (1 / w));*/
    /*exercicio 5.4-28a no intervalo [0,600], n = 30, w0 = 8*/       /*return(- 0.6 * pow(0.1, 2) * sqrt(2 * 32.1) * (sqrt(w) / pow(w, 2)));*/
    /*exercicio 5.4-28b no intervalo [0,1600], n = 80, w0 = 08*/     /*return(- 0.6 * pow(0.1, 2) * sqrt(2 * 32.1) * (sqrt(w) / pow(w, 2)));*/
    /*return (6.22e-19 * pow((2000 - w / 2), 2) * pow((2000 - w / 2), 2) * pow((3000 -  3 * w / 4), 3)) ;*/
}

/*Programa principal*/
int main(void)
{
    setlocale(LC_ALL,"");

    /*Declaração de variáveis*/
    double a, b, h, t, w, k1, k2, k3, k4, y, e;
    int n, i;

    /*Entrada de parâmetros*/
    printf("Digite o início do intervalo [a]: ");
    scanf("%lf", &a);
    printf("Digite o fim do intervalo [b]: ");
    scanf("%lf", &b);
    printf("Digite o número de pontos da malha [n]: ");
    scanf("%d", &n);
    printf("Digite a condição inicial do valor [alpha]: ");
    scanf("%lf", &w);

    /*Exibição dos parâmetros de cáculo para o usuário*/
    printf ("\nOs parâmetros digitados foram: [a]= %.3f [b]= %.3f [n]= %i [alpha] = %.3f \n", a, b, n, w);

    /*Cálculo do Passo h*/
    h = (b - a) / n;
    t = a;

    for(i=0; i<=n; i++)
    {
        /*Cálculo de ti*/
        t = a + i * h;

        /*Cálculo da solução da equação diferencial*/
        y = f(t , w);

        /*Erro (diferença do valor exato y com a aproximação w)*/
        e = fabs(y - w);

        /*Exibição dos valores calculados para o usuário*/
        printf("i= %d \t t= %.8f \t w= %.8f \t y= %.8f \t e= %.8f \n", i, t, w, y, e);

        /*Cálculo das notações */
        k1 = h * dy(t, w);
        k2 = h * dy(t + h / 2, w + k1 / 2);
        k3 = h * dy(t + h / 2, w + k2 / 2);
        k4 = h * dy(t + h, w + k3);

        /*Equação de diferença*/
        w = w + (k1 + 2 * k2 + 2 * k3 + k4) / 6;

    }
    return 0;
}
