
// PAULO HENRIQUE ZIEMER DOS SANTOS - ADS MÓDULO II - TURMA A

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int ID;
    char Nome[100];
    char DescR[300];
} Recursos;

typedef struct
{
    int ID;
    char NomeA[100];
    char DescA[300];

    Recursos *Recursos[10];
    int NRecursos;
} Aplication;

typedef struct
{
    int ID;
    char nome[100];
    char pais[100];
    int anoFund;

    Aplication *Aplication[10];
    int NAplication;
} Empresa;


void interface();

Empresa *CadEmp(int idE);
void ListEmp(Empresa *empresas[], int idE);

Aplication *CadAp(int idA);
void ListAp(Aplication *Ap[], int idA);

Recursos *CadR(int idR);
void ListR(Recursos *R[], int idR);

void *AsocAplEmp(Empresa *EmpresaAsoc, Aplication *AplicacaoAsoc);
void *AsocRecApl(Aplication *AplicationAsoc, Recursos *RecursosAsoc);

void ListEmpApl(Empresa *empresas[], int idE, int idA);
void ListAplRec(Aplication *AplicationL[], int idA, int idR);
void ListGeral(Empresa *EmpresaL[], int idE, int idA, int idR);

int main()
{
    Empresa *EmpresaM[5];
    Aplication *AplicationM[5];
    Recursos *RecursosM[5];

    int idE = 0, idA = 0, idR = 0;
    int NE = 0, NA = 0, NR = 0;
    int op, c=0;
    int AsocEmp, AsocApl, AsocReq;

    while(c == 0)
    {
        interface(op);
        printf("--> ");
        scanf("%d", &op);
        switch(op)
        {
            case 1:
                EmpresaM[idE] = CadEmp(idE);
                idE++;
                NE++;
            break;

            case 2:
                ListEmp(EmpresaM, idE);
            break;

            case 3:
                AplicationM[idA] = CadAp(idA);
                idA++;
                NA++;
            break;

            case 4:
                ListAp(AplicationM, idA);
            break;

            case 5:
                RecursosM[idR] = CadR(idR);
                idR++;
                NR++;
            break;

            case 6:
                ListR(RecursosM, idR);
            break;

            case 7: //Associar Aplicacao a Empresa

            if(NE == 0)
            {
                puts("\nSem Empresas Cadastradas\n");
            }
            else
            {
                if(NA == 0)
                {
                    puts("\nSem Aplicacao cadastrada\n");
                }
                else
                {
                    ListEmp(EmpresaM, idE);
                    puts("-- Digite a seguir o ID da empresa --");
                    scanf("%d", &AsocEmp);

                    ListAp(AplicationM, idA);
                    puts("\n\n-- Digite a seguir o ID da aplicacao --");
                    scanf("%d", &AsocApl);

                    AsocAplEmp(EmpresaM[AsocEmp], AplicationM[AsocApl]);

                    puts("\n\n-- Aplicacao vinculada a empresa com sucesso --\n\n");
                }
            }
            break;

            case 8: //Associar Recursos a Aplicação
                
                if(NA == 0)
                {
                    puts("\nSem aplicacoes cadastradas\n");
                }
                else
                {
                    if(NR == 0)
                    {
                        puts("\nSem recursos cadastrados\n");
                    }
                    else
                    {
                        ListAp(AplicationM, idA);
                        puts("\n-- Digite a seguir o ID da Aplicacao --");
                        scanf("%d", &AsocApl);

                        ListR(RecursosM, idR);
                        puts("\n\n-- Digite a seguir o ID do Recurso --");
                         scanf("%d", &AsocReq);

                        AsocRecApl(AplicationM[AsocApl], RecursosM[AsocReq]);

                        puts("\n\n-- Recurso vinculado a aplicacao com sucesso --\n\n");
                    }
                }
            break;

            case 9:
                if(NE == 0)
                {
                    puts("\nSem empresas cadastradas\n");
                }
                else
                {
                    if(NA == 0)
                    {
                        puts("\nSem aplicacoes cadastradas\n");
                    }
                    else
                    {
                        ListEmpApl(EmpresaM, idE, idA);
                    }
                }
            break;

            case 10:
                if(NA == 0)
                {
                    puts("\nSem Aplicacoes cadastradas\n");
                }
                else
                {
                    if(NR == 0)
                    {
                        puts("\nSem Recursos cadastrados");
                    }
                    else
                    {
                        ListAplRec(AplicationM, idA, idR);
                    }
                }
            break;

            case 11:
                if(NE == 0)
                {
                    puts("\nSem Empresas cadastradas\n");
                }
                else
                {
                    if(NA == 0)
                    {
                        puts("\nSem Aplicacoes cadastradas\n");
                    }
                    else
                    {
                        if(NR == 0)
                        {
                            puts("\nSem Recursos cadastrados\n");
                        }
                        else
                        {
                            ListGeral(EmpresaM, idE, idA, idR);
                        }
                    }
                }
        }
    }
}

// -------------------------------------------------------- EMPRESA --------------------------------------------------------
Empresa *CadEmp(int idE)
{
    Empresa *NE = (Empresa *)malloc(sizeof(Empresa));
    NE->ID = idE;

    puts("\nNome do Empresa: ");
    scanf(" %[^\n]s", NE->nome);
    puts("\nPais em que a empresa foi fundada: ");
    scanf(" %[^\n]s", NE->pais);
    puts("\nAno em que a empresa foi fundada: ");
    scanf(" %d", &NE->anoFund);

    NE->NAplication = 0;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
    return NE;
}

void ListEmp(Empresa *empresas[], int idE)
{
    puts("\n");
    for(int i = 0; i < idE; i++)
    {
        printf("ID Empresa: %d\nNome da Empresa: %s\nDescricao da Empresa: %s\nAno de Fundacao: %d\n", empresas[i]->ID, empresas[i]->nome, empresas[i]->pais, empresas[i]->anoFund);
    }
    puts("\n");
}////

// -------------------------------------------------------- APLICAÇÃO --------------------------------------------------------
Aplication *CadAp(int idA)
{
    Aplication *NAp = (Aplication *)malloc(sizeof(Aplication));
    NAp->ID = idA;

    puts("\nNome da aplicacao: ");
    scanf(" %[^\n]s", NAp->NomeA);

    puts("\nDescricao da aplicacao: ");
    scanf(" %[^\n]s", NAp->DescA);

    NAp->NRecursos= 0;
    return NAp;
}

void ListAp(Aplication *Ap[], int idA)
{
    puts("\n");
    for(int i=0; i<idA; i++)
    {
        printf("ID Aplicacao: %d\nNome da Aplicacao: %s\nDescricao da Aplicacao: %s\n", Ap[i]->ID, Ap[i]->NomeA, Ap[i]->DescA);
    }   
    puts("\n");
}

// -------------------------------------------------------- RECURSOS --------------------------------------------------------
Recursos *CadR(int idR)
{
    Recursos *NewR = (Recursos *)malloc(sizeof(Recursos));
    NewR->ID = idR;

    puts("\nNome do Recurso: ");
    scanf(" %[^\n]s", NewR->Nome);

    puts("\nDescricao do Recurso:");
    scanf(" %[^\n]s", NewR->DescR);

    return NewR;
}

void ListR(Recursos *R[], int idR)
{
    puts("\n");
    for(int i=0; i<idR; i++)
    {
        printf("ID Recurso: %d\nNome Recurso: %s\nDescrição Recurso: %s\n", R[i]->ID, R[i]->Nome, R[i]->DescR);
    }
    puts("\n");
}

// -------------------------------------------------------- ASSOCIAÇÃO --------------------------------------------------------
void *AsocAplEmp(Empresa *EmpresaAsoc, Aplication *AplicacaoAsoc)
{
    EmpresaAsoc->Aplication[EmpresaAsoc->NAplication] = AplicacaoAsoc;
    EmpresaAsoc->NAplication++;
}

void *AsocRecApl(Aplication *AplicationAsoc, Recursos *RecursosAsoc)
{
    AplicationAsoc->Recursos[AplicationAsoc->NRecursos] = RecursosAsoc;
    AplicationAsoc->NRecursos++;
}

// -------------------------------------------------------- LISTAGEM GERAL --------------------------------------------------------
void ListEmpApl(Empresa *empresas[], int idE, int idA)
{
    puts("\n");
    printf("\nID\t| Empresa\t| Aplicacao\t| Descricao\n");
    for(int i = 0; i < idE; i++)
    {
        for(int k = 0; k < idA; k++)
        {
            printf("ID Empresa: %d\nNome da Empresa: %s\nNome da Aplicacao: %s\nDescricao da Aplicacao %s\n", empresas[i]->ID, empresas[i]->nome, empresas[i]->Aplication[k]->NomeA, empresas[i]->Aplication[k]->DescA);
        }
    }
    puts("\n");
}

void ListAplRec(Aplication *AplicationL[], int idA, int idR)
{
    puts("\n");
    for(int i = 0; i < idA; i++)
    {
        for(int k = 0; k < idR; k++)
        {
            printf("\nID Aplicacao: %d\nID Recurso: %d\nNome da Aplicacao: %s\nNome do Recurso: %s\nDescricao do Recurso:%s\n", AplicationL[i]->ID, AplicationL[i]->Recursos[k]->ID, AplicationL[i]->NomeA, AplicationL[i]->Recursos[k]->Nome, AplicationL[i]->Recursos[k]->DescR);
        }                                                                                                                                                                                                  
    }
    puts("\n");
}

void ListGeral(Empresa *EmpresaL[], int idE, int idA, int idR)
{
    puts("\n");
    for(int i = 0; i < idE; i++)
    {
        for(int k = 0; k < idA; k++)
        {
            for(int j = 0; j < idR; j++)
            {
                printf("\nID Empresa: %d\nNome da Empresa: %s\nPais da Empresa: %s\nAno de Fundacao: %d\n", EmpresaL[i]->ID, EmpresaL[i]->nome, EmpresaL[i]->pais, EmpresaL[i]->anoFund);
                printf("\nID Empresa: %d\nID Aplicacao: %d\nNome da Aplicacao:%s\nDescricao da Aplicacao:%s\n", EmpresaL[i]->ID,EmpresaL[i]->Aplication[k]->ID, EmpresaL[i]->Aplication[k]->NomeA, EmpresaL[i]->Aplication[k]->DescA);
                printf("\nID Empresa: %d\nID Aplicacao %d\nID Recurso:%d\nNome do Recurso: %s\nDescricao do Recurso: %s\n",EmpresaL[i]->ID,EmpresaL[i]->Aplication[k]->ID,EmpresaL[i]->Aplication[k]->Recursos[j]->ID,EmpresaL[i]->Aplication[k]->Recursos[j]->Nome,EmpresaL[i]->Aplication[k]->Recursos[j]->DescR);
            }
        }
    }
}

// -------------------------------------------------------- INTERFACE --------------------------------------------------------
void interface()
{
    puts("\n----------------EMPRESA----------------\n");
    puts("1 - Cadastrar Empresa");
    puts("2 - Visualizar Empresa");
    puts("\n----------------APLICACAO--------------\n");
    puts("3 - Cadastrar Aplicacao");
    puts("4 - Visualizar Aplicacoes");
    puts("\n----------------RECURSOS---------------\n");
    puts("5 - Cadastrar Recursos");
    puts("6 - Visualizar Recursos");
    puts("\n----------------ASSOCIAR---------------\n");
    puts("7 - Associar Aplicacao a Empresa");
    puts("8 - Associar Recursos a Aplicacao");
    puts("\n----------------LISTAGEM---------------\n");
    puts("9 - Listar Empresa com Aplicacoes");
    puts("10 - Listar Aplicacoes com recursos");
    puts("11 - Visao geral das empresas");
}