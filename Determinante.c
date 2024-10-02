#include <stdio.h>
#define L 4
#define C 4


void PrintarMatriz(int l, int c, double Matriz[l][c])
{
    printf("\n");
    for(int i = 0; i < l; i++)
    {
        for(int j = 0; j < c; j++)
        {
            printf("%lf ", Matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void TrocarLinha(double Matriz[L][C], int l1, int l2)
{
    double T;

    for(int i = 0; i < C; i++)
    {
        T = Matriz[l1][i];
        Matriz[l1][i] = Matriz[l2][i];
        Matriz[l2][i] = T;
    }
}

void EscreverMatriz(int l, int c, double Matriz[l][c])
{
    for(int i = 0; i < l; i++)
    {
        printf("Linha %d\n", i + 1);
        for(int j = 0; j < c; j++)
        {
            scanf("%lf", &Matriz[i][j]);
        }
    }
}

int main()
{
    double A[L][C] = {2, 1, 1, 1, 1, 4, 0, 3, 2};
    double fator, l, det = 1, p = 0;

    printf("Escreva oa elementos da Matriz\n");
    EscreverMatriz(L, C, A);

    printf("\nMatriz antes da Eliminacao Gaussiana\n");
    PrintarMatriz(L, C, A);


    for(int c = 0; c < C - 1; c++)
    {
        for(int i = c + 1; i < L; i++)
        {
            l = L;
            do
            {
                l--;
                if(A[c][c] == 0)
                {
                    TrocarLinha(A, c, l);
                    det *= -1;
                }
            } while (A[c][c] == 0 && l >= i);
            if(l < i)
            {
                printf("Sistema indeterminado ou impossível\n");
                p = 1;
                break;
                det = 0;
            }
            

            fator = A[i][c]/A[c][c];
            for(int j = c + 1; j < C; j++)
            {
                A[i][j] -= A[c][j] * fator;
                A[i][c] = 0;
            }
        }
        if(p == 1)
            break;
    }

    for(int i = 0; i < L; i++)
        det *= A[i][i];

    printf("Matriz apos a Eliminacao Gaussiana\n");
    PrintarMatriz(L, C, A);
    printf("O determinante da matriz vale %lf\n", det);

    return 0;
}

