#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define QTD_PALAVRAS 26

int compara(const char a[], const char b[])
{
    for (int i=0; a[i]!='\0'; i++ )
        if (toupper(a[i]) != toupper(b[i]))
            return 0;
    return 1;
}

int isReservada(char *palavra)
{
    char *reservadas[QTD_PALAVRAS] = {"Program", "Var", ";", "Const", "Begin", "Read", "End.", ",", ":", "(", ")", "=", "+",
                                      "Write", "A", "x" ,"b", "B", "real", "y", "*", "2", "3", ":=", "b;", "Pgrau"};
    int i;

    for(i=0; i<QTD_PALAVRAS; i++)
    {
            //if(!strcmp(palavra, reservadas[i]))

            if(!compara(palavra, reservadas[i]))
                return 1;
    }
    return 0;
}

int main()
{
    FILE *fp = fopen("codigo.txt", "rt");
    char linha[MAX], *token;
    int i = 0, corrente = 0;


    if(fp == NULL)
		printf("Erro ao abrir arquivo.\n");
	else
    {
        while(!feof(fp)) {
            putchar(fgetc(fp));
        }
        rewind(fp);
        while (!feof(fp))
        {
            corrente++;
            fgets(linha, MAX, fp);
            token = strtok(linha," ");
            if(token[strlen(token)-1] == '\n')
                token[strlen(token)-1] = '\0';
            if(!isReservada(token))
            {
                printf("\n\nErro lexico na linha %d: Palavra %s nao reconhecida.\n", corrente, token);
                return 0;
            }
            i++;
            do
            {
                token = strtok(NULL," ");
                if(token != NULL)
                {
                    if(token[strlen(token)-1] == '\n')
                        token[strlen(token)-1] = '\0';
                    if(!isReservada(token))
                    {
                        printf("\n\nErro lexico na linha %d: Palavra %s nao reconhecida.\n", corrente, token);
                        return 0;
                    }
                }
            }while(token != NULL);
        }
 	}
 	printf("\n\nO codigo acima pertence ao alfabeto regular.\n");
    return 1;
}
