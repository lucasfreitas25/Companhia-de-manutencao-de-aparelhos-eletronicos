#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

typedef struct TFuncionario{
	char nome[50];
	char cargo[20];
	float salario;
	int depend;
}TFuncionario;

//FUNÇÃO DO MENU PRINCIPAL
int menuprincipal()
{
	int op;
	
	printf("1 - Quantidade de funcionarios\n");
	printf("2 - Verificar funcionario\n");
	printf("3 - Cadastrar funcionario\n");
	printf("9 - Sair\n");
	scanf(" %d", &op);
	
	return op;
}

//FUNÇÃO PARA ENCERRAR O PROCESSO
int menuSair()
{
	int opcao;
	
	printf(" 1 - Confirmar saida - Continuar\n");
	scanf(" %d", &opcao);
	
	return opcao;
}

//Enfeite
void enfeite()
{
	printf("---------------------------------------- \n");
	printf("----------- MENU - EMPRESA----------- \n");
	printf("---------------------------------------- \n");
	printf(" \n");
}

//Contador de quantidade de funcionarios que tem na empresa
int quant()
{
	FILE *arqExer = fopen("Funcionarios.dat","rb");
	TFuncionario listaFunci;
	int cont = 0;
	if(arqExer != NULL)
	{
		while(fread(&listaFunci, sizeof(TFuncionario), 1, arqExer))
		{
			cont++;
		}
		return cont;
		fclose(arqExer);
	}
	else
	{
		printf("Falha na abertura do arquivo\n");
	}		

}

//Verificador de funcionario especifico
void verificar()
{
	FILE *arqExer = fopen("Funcionarios.dat","rb");
	TFuncionario listaFunci;
	if(arqExer != NULL)
	{
		while(fread(&listaFunci, sizeof(TFuncionario), 1, arqExer))
		{
			if((listaFunci.depend > 1) && (listaFunci.salario >= 2400) && (listaFunci.cargo == "TECNICOS EM ELETRONICA"))
			{
				printf(" %s\n", listaFunci.nome);
			}
		}
		fclose(arqExer);
	}
	else
	{
		printf("Falha na abertura do arquivo\n");
	}
}

//CADASTRO DE FUNCIONARIO
void cadastro()
{
	FILE *arqExer;
	TFuncionario listaFunci;
	arqExer = fopen("Funcionarios.dat","ab");
	if(arqExer != NULL)
	{
		printf("Digite o nome do funcionario:");
        scanf(" %[^\n]s", listaFunci.nome);
        printf("Digite o cargo:");
        scanf(" %[^\n]s", listaFunci.cargo); 
        printf("Digite o salario:");
        scanf(" %f", &listaFunci.salario);
        printf("Quantidade de dependentes:");
        scanf(" %d", &listaFunci.depend);
        fwrite(&listaFunci, sizeof(TFuncionario), 1, arqExer);
        fclose(arqExer);
	}
	else
	{
		printf("Falha na abertura do arquivo\n");
	}
}

void limpatela()
{
	system("cls");
}

//MENU PRINCIPAL
int main(int argc, char const *argv[])
{
	int resp,x,z;
	bool Fim = false;
	
	while (!Fim)
	{
		enfeite();
	 	resp = menuprincipal();
	 	switch(resp)
	 	{
	 		case 1:
	 			limpatela();
	 			x = quant();
	 			printf("A quantidade de funcionarios da empresa e de: %d\n", x);
	 			break;
	 		case 2:
	 			limpatela();
	 			verificar();
	 			break;
	 		case 3:
	 			limpatela();
	 			cadastro();
	 			break;
	 		case 9:
	 			limpatela();
	 			z = menuSair();
           		if(z == 1)
            	{
              		Fim = true;
        		}
        		break;
		}	
	}
}
