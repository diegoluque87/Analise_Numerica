/***********************************************
 * \brief   Programa realizado para a Aula de Métodos Númericos em Fenômenos de Transporte
 *          Análise Numérica - Burden, Richard - 10ª edição - Pág. 366
 *          Algoritmo 5.7 - Método de Runge-Kutta de 4ª ordem para Equações Diferenciais

 *
 * \param   Extremidade a
 * \param   Extremidade b
 * \param   Número de Equações m
 * \param   Número de Pontos da Malha n
 * \param   Condições Iniciais w0 ... wn
 * \return  Aproximação wj para uj(t) nos (N+1) valores de t
 *
 ***********************************************/

#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <ctype.h>


/*Função f(solução exata do sistema) equação diferencial ordinária*/
double f(int j, double t, double y)
{
    switch (j)
    {
        case 1 :
            /*validação ex. 1 no intervalo [0,0,5], n = 5, w1,0 = 0 e w2,0 = 0*/
            return(-3.375 * exp(-2 * t) + 1.875 * exp(-0.4 * t) + 1.5);

            /*exercicio 5.9-1a no intervalo [0,1], n = 5, w1,0 = 1 e w2,0 = 1
            return(exp(5 * t) / 3 - exp(-t) / 3 + exp(2 * t));*/

            /*exercicio 5.9-1b no intervalo [0,2], n = 20, w1,0 = 0 e w2,0 = -1
            return(2 * exp(-t) - 2 * exp(-2 * t) + sin(t));*/

            /*exercicio 5.9-2c no intervalo [0,1], n = 10, w1,0 = 3, w2,0 = -1 e w3,0 = 1
            return(-3 * exp(-t) - 3 * sin(t) + 6 * cos(t));*/

            /*exercicio 5.9-2d no intervalo [0,2], n = 10, w1,0 = 5, w2,0 = -9 e w3,0 = -5
            return(2 * exp(3 * t) + 3 * exp(-2 * t) + t);*/

            /*exercicio 5.9-3a no intervalo [0,1], n = 10, w1,0 = 0, w2,0 = 0
            return((pow(t, 3) * exp(t)) / 6 - t * exp(t) + 2 * exp(t) - t - 2);*/

            /*exercicio 5.9-4d no intervalo [1,2], n = 10, w1,0 = 2, w2,0 = 8, w3,0 = 6
            return(2 * t - 1 / t + pow(t, 2) + pow(t, 3) - 1);*/

            /*caso não possua a equação diferencial ordinária
            return(1);*/
            break;
        case 2 :
            /*validação ex. 1 no intervalo [0,0,5], n = 5, w1,0 = 0 e w2,0 = 0*/
            return(-2.25 * exp(-2 * t) + 2.25 * exp(-0.4 * t));

            /*exercicio 5.9-1a no intervalo [0,1], n = 5, w1,0 = 1 e w2,0 = 1
            return(exp(5 * t) / 3 + 2 * exp(-t) / 3 + pow(t, 2) * exp(2 * t));*/

            /*exercicio 5.9-1b no intervalo [0,2], n = 20, w1,0 = 0 e w2,0 = -1
            return(-3 * exp(-t) + 2 * exp(-2 * t));*/

            /*exercicio 5.9-2c no intervalo [0,1], n = 10, w1,0 = 3, w2,0 = -1 e w3,0 = 1
            return(1.5 * exp(-t) + 0.3 * sin(t) - 2.1 * cos(t) - 0.4 * exp(2 * t));*/

            /*exercicio 5.9-2d no intervalo [0,2], n = 10, w1,0 = 5, w2,0 = -9 e w3,0 = -5
            return(-8 * exp(-2 * t) + exp(4 * t) - 2 * exp(3 * t) + sin(t));*/

            /*exercicio 5.9-3a no intervalo [0,1], n = 10, w1,0 = 0, w2,0 = 0
            return(((pow(t, 3) / 6) + (pow(t, 2) / 2) - t + 1) * exp(t) - 1);*/

            /*exercicio 5.9-4d no intervalo [1,2], n = 10, w1,0 = 2, w2,0 = 8, w3,0 = 6
            return(( 3 * pow(t, 4) + 2 * pow(t, 3) + 2 * pow(t, 2) + 1) / pow(t, 2));*/

            /*caso não possua a equação diferencial ordinária
            return(1);*/
            break;
        case 3 :
            /*exercicio 5.9-2c no intervalo [0,1], n = 10, w1,0 = 3, w2,0 = -1 e w3,0 = 1
            return(-1 / exp(t) + 2.4 * cos(t) + 1.8 * sin(t) - 0.4 * exp(2 * t));*/

            /*exercicio 5.9-2d no intervalo [0,2], n = 10, w1,0 = 5, w2,0 = -9 e w3,0 = -5
            return(2 * exp(4 * t) - 4 * exp(3 * t) - exp(-2 * t) - 2);*/

            /*exercicio 5.9-4d no intervalo [1,2], n = 10, w1,0 = 2, w2,0 = 8, w3,0 = 6
            return(( 6 * pow(t, 5) + 2 * pow(t, 4) - 2 * t) / pow(t, 4));*/

            /*caso não possua a 3ª equação diferencial ordinária*/
            return(1);
            break;
        default:
            return 0;
    }
}

/*Função derivada f'*/
double dy(int j, double t, double w[])
{
    switch (j)
    {
        case 1 :
            /*validação ex. 1 no intervalo [0,0,5], n = 5, w1,0 = 0 e w2,0 = 0*/
            return(-4 * w[1] + 3 * w[2] + 6);

            /*exercicio 5.9-1a no intervalo [0,1], n = 5, w1,0 = 1 e w2,0 = 1
            return(3 * w[1] + 2 * w[2] - (2 * pow(t, 2) + 1) * exp(2 * t));*/

            /*exercicio 5.9-1b no intervalo [0,2], n = 20, w1,0 = 0 e w2,0 = -1
            return(-4 * w[1] - 2 * w[2] + cos(t) + 4 * sin(t));*/

            /*exercicio 5.9-2c no intervalo [0,1], n = 10, w1,0 = 3, w2,0 = -1 e w3,0 = 1
            return(w[1] + 2 * w[2] - 2 * w[3] + exp(-t));*/

            /*exercicio 5.9-2d no intervalo [0,2], n = 10, w1,0 = 5, w2,0 = -9 e w3,0 = -5
            return(3 * w[1] + 2 * w[2] - w[3] - 1 - 3 * t - 2 * sin(t));*/

            /*exercicio 5.9-3a no intervalo [0,1], n = 10, w1,0 = 0, w2,0 = -0
            return(w[2]);*/

            /*exercicio 5.9-4d no intervalo [1,2], n = 10, w1,0 = 2, w2,0 = 8, w3,0 = 6
            return(w[2]);*/

            /*exercicio 5.9-5 no intervalo [0,4], n = 40, w1,0 = 1000 e w2,0 = 500
            return(3 * w[1] - 0.002 * w[1] * w[2]);*/

            /*exercicio 5.9-6 no intervalo [0,4], n = 40, w1,0 = 10000 e w2,0 = 10000
            return(w[1] * (4 - 0.0003 * w[1] - 0.0004 * w[2]));*/
            break;
        case 2 :
            /*validação ex. 1 no intervalo [0,0,5], n = 5, w1,0 = 0 e w2,0 = 0*/
            return(-2.4 * w[1] + 1.6 * w[2] + 3.6);

            /*exercicio 5.9-1a no intervalo [0,1], n = 5, w1,0 = 1 e w2,0 = 1
            return(4 * w[1] + w[2] + (pow(t, 2) + 2 * t - 4) * exp(2 * t));*/

            /*exercicio 5.9-1b no intervalo [0,2], n = 20, w1,0 = 0 e w2,0 = -1
            return(3 * w[1] + w[2] - 3 * sin(t));*/

            /*exercicio 5.9-2c no intervalo [0,1], n = 10, w1,0 = 3, w2,0 = -1 e w3,0 = 1
            return(w[2] + w[3] - 2 * exp(-t));*/

            /*exercicio 5.9-2d no intervalo [0,2], n = 10, w1,0 = 5, w2,0 = -9 e w3,0 = -5
            return(w[1] - 2 * w[2] + 3 * w[3] + 6 - t + 2 * sin(t) + cos(t));*/

            /*exercicio 5.9-3a no intervalo [0,1], n = 10, w1,0 = 0, w2,0 = -0
            return(t * exp(t) - t + 2 * w[2] - w[1]);*/

            /*exercicio 5.9-4d no intervalo [1,2], n = 10, w1,0 = 2, w2,0 = 8, w3,0 = 6
            return(w[3]);*/

            /*exercicio 5.9-5 no intervalo [0,4], n = 40, w1,0 = 1000 e w2,0 = 500
            return(0.0006 * w[1] * w[2] - 0.5 * w[2]);*/

            /*exercicio 5.9-6 no intervalo [0,4], n = 40, w1,0 = 10000 e w2,0 = 10000
            return(w[2] * (2 - 0.0002 * w[1] - 0.0001 * w[2]));*/
            break;
        case 3 :
            /*exercicio 5.9-2c no intervalo [0,1], n = 10, w1,0 = 3, w2,0 = -1 e w3,0 = 1
            return(w[1] + 2 * w[2] + exp(-t));*/

            /*exercicio 5.9-2d no intervalo [0,2], n = 10, w1,0 = 5, w2,0 = -9 e w3,0 = -5
            return(2 * w[1] + 4 * w[3] + 8 - 2 * t);*/

            /*exercicio 5.9-4d no intervalo [1,2], n = 10, w1,0 = 2, w2,0 = 8, w3,0 = 6
            return((8 * pow(t, 3) - 2 - pow(t, 2) * w[3] + 2 * t * w[2] - 2 * w[1]) / pow(t, 3));*/

            /*caso não possua a 3ª equação diferencial*/
            return(1);
            break;
        default:
            return 0;
    }
}

/*Programa principal*/
int main(void)
{
    setlocale(LC_ALL,"");

    /*Declaração de variáveis*/
    int m, n, i, j;
    double a, b, h, t;

    /*Entrada de parâmetros*/
    printf("Digite o início do intervalo [a]: ");           scanf("%lf", &a);
    printf("Digite o fim do intervalo [b]: ");              scanf("%lf", &b);
    printf("Digite o número de equações estudadas [m]: ");  scanf("%d", &m);
    printf("Digite o número de pontos da malha [n]: ");     scanf("%d", &n);

    /*Declaração de variáveis dependentes do número de equações*/
    j = m - 1;
    double w[j], k1[j], k2[j], k3[j], k4[j], y[j], e[j], _k1[j], _k2[j], _k3[j];

    /*Entrada de parâmetros dependentes do número de equações*/
    printf("Digite as condições iniciais do valor [alpha]:\n");
    for (j=1; j<=m; j++){printf("alpha[%d]= ", j); scanf ("%lf", &w[j]);}

    /*Exibição dos parâmetros de cáculo para o usuário*/
    printf ("\nOs parâmetros digitados foram: [a]= %.3f [b]= %.3f [m]= %i [n]= %i", a, b, m, n);
    for (j=1; j<=m; j++){printf(" alpha[%d]= [%.4f]", j, w[j]);}
    printf("\n\n");

    /*Cálculo do Passo h*/
    h = (b - a) / n;
    t = a;

    for(i=0; i<=n; i++)
    {
        /*Cálculo de ti*/
        t = a + i * h;

        /*Cálculo da solução da equação diferencial e erro em relação ao valor exato*/
        for (j=1; j<=m; j++){y[j] = f(j, t , w[j]); e[j] = fabs(y[j] - w[j]);}

        /*Exibição dos valores calculados para o usuário*/
        printf("i= %d \t t= %.4f \t ", i, t);
        for (j=1; j<=m; j++){printf ("w[%d]= %.8f \t", j, w[j]);}
        for (j=1; j<=m; j++){printf ("y[%d]= %.8f \t", j, y[j]);}
        for (j=1; j<=m; j++){printf ("e[%d]= %.8f \t", j, e[j]);}
        printf("\n");

        /*Cálculo das notações */
        for (j=1; j<=m; j++){k1[j] = h * dy(j, t, w);}

        for (j=1; j<=m; j++){_k1[j] = w[j] + k1[j] / 2;}
        for (j=1; j<=m; j++){k2[j] = h * dy(j, t + h / 2, _k1);}

        for (j=1; j<=m; j++){_k2[j] = w[j] + k2[j] / 2;}
        for (j=1; j<=m; j++){k3[j] = h * dy(j, t + h / 2, _k2);}

        for (j=1; j<=m; j++){_k3[j] = w[j] + k3[j];}
        for (j=1; j<=m; j++){k4[j] = h * dy(j, t + h, _k3);}

        /*Equação de diferença*/
        for (j=1; j<=m; j++){w[j] = w[j] + (k1[j] + 2 * k2[j] + 2 * k3[j] + k4[j]) / 6;}
    }
    return 0;
}
