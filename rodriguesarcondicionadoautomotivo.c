#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

struct Cliente
{
	int posicao;
	char nome[80];
	float divida;
};

struct Cliente listacliente[1000];
int numClientes = 0;

// DECLARANDO AS FUNÇÕES DO PROGRAMA
void Cadastrar();
void Opcao(void);
void Listar();
void Excluir();
int Pesquisar();
void Menu();
void Editar();
int Email(char email[80], int tentativa);
void Sorteio();
void PrintClient(struct Cliente cliente);

int main()
{
	setlocale(LC_ALL, "Portuguese");

	char loginCadastro[80], loginEntrar[80];
	char senhaEntrar[80], senhaCadastro[80];
	int op;
	int sair = 0;
	char limpar;
	char email[80];

	// ETAPA DA FUNÇÃO DO CADASTRO
	system("color 03");
	printf(">> REALIZE O SEU CADASTRO <<\n");
	printf("\n");

	printf("Digite o seu login:\n");
	scanf("%s", loginCadastro);

	printf("Digite a sua senha:\n");
	scanf("%s", senhaCadastro);
	printf("\n");
	Email(email, 0);
	printf("\n");
	printf("Cadastro realizado!");
	printf("\n");
	system("pause");
	system("cls");

	// ETAPA DA FUNÇÃO DO LOGIN
	printf(">> REALIZE O SEU LOGIN <<\n");
	printf("\n");
	printf("Informe seu login cadastrado:\n");
	scanf("%s", loginEntrar);

	if (strcmp(loginEntrar, loginEntrar) != 0)
	{
		printf("Usuario nao encontrado, informe novamente:\n");
		scanf("%s", loginEntrar);
	}

	printf("Informe sua senha: \n");
	scanf("%s", senhaEntrar);

	if (strcmp(senhaEntrar, senhaCadastro) != 0)
	{
		printf("Senha incorreta, informe novamente:\n");
		scanf("%s", senhaEntrar);
	}

	system("pause");
	system("cls");

	// MENU INICIAL DO PROGRAMA
	printf("RODRIGUES AR-CONDICIONADO AUTOMOTIVO\n");
	printf("\n");
	printf("Bem vindo %s, estamos felizes pela sua presenca na nossa empresa!\n", loginCadastro);
	printf("\n");

	// UTILIZANDO O SWITCH CASE PARA ACESSAR AS FUNÇÕES
	do
	{
		Opcao();
		scanf("%i", &op);
		system("cls");
		switch (op)
		{
		case 1:
			Cadastrar();
			system("cls");
			break;
		case 2:
			Listar();
			printf("\n");
			system("pause");
			system("cls");
			break;
		case 7:
			printf("Deseja sair? |1-SIM| |2-NAO|\n");
			scanf("%i", &sair);
			break;
		case 4:
			Pesquisar();
			system("pause");
			system("cls");
			break;
		case 5:
			Excluir();
			system("pause");
			system("cls");
			break;
		case 3:
			Menu();
			system("pause");
			system("cls");
			break;
		case 6:
			Editar();
			system("pause");
			system("cls");
			break;
		case 8:
			Sorteio();
			system("pause");
			system("cls");
		}
	} while (sair != 1);

	return 0;
}

// ETAPA DE CADASTRAR CLIENTE
void Cadastrar()
{
	int continuar = 0;
	do
	{
		printf("Informe os clientes\n");
		printf("Numero de identificacao?\n");
		scanf("%i", &listacliente[numClientes].posicao);
		printf("Nome?\n");
		scanf("%s", &listacliente[numClientes].nome);
		printf("Divida?\n");
		scanf("%f", &listacliente[numClientes].divida);
		numClientes++;
		printf("1. Desejar continuar? |1-SIM| |2-NAO|\n");
		scanf("%d", &continuar);
		system("cls");
	} while (continuar != 2);
}

// Essa função foi criada para evitar código duplicado
// Quando você tiver trechos iguais sendo utilizado em vários lugares, use função e chame ela
// Isso diminui o seu código e facilita as alterações que venha a acontecer, pois você vai precisar alterar em apenas um lugar
void PrintClient(struct Cliente cliente)
{
	printf("\nID: %i\n", cliente.posicao);
	printf("Cliente: %s\n", cliente.nome);
	printf("Divida: %.2f\n", cliente.divida);
}

void Opcao(void)
{
	printf(">> MENU DE OPCOES <<\n");
	printf("\n");
	printf("(1) - Cadastrar\n");
	printf("(2) - Listar\n");
	printf("(3) - Menu\n");
	printf("(4) - Pesquisar\n");
	printf("(5) - Excluir\n");
	printf("(6) - Editar\n");
	printf("(7) - Sair\n");
	printf("(8) - Participe do nosso sorteio\n");
	printf("\n");
}

// ETAPA DE LISTAR OS CLIENTES
void Listar()
{
	if (numClientes == 0) {
		printf("Não foi encontrado clientes cadastrados...");
	} else {
		// Você pode declarar o i dentro do for
		for (int i = 0; i < numClientes; i++)
		{
			PrintClient(listacliente[i]);
		}
	}
}

// ETAPA DE PESQUISAR OS CLIENTES
int Pesquisar()
{
	int i;
	int buscaPosicao;
	printf("Informe o numero de identificacao a ser pesquisado: ");
	scanf("%i", &buscaPosicao);

	for (i = 0; i < numClientes; i++)
	{
		if (listacliente[i].posicao == buscaPosicao)
		{
			PrintClient(listacliente[i]);
			return i;
		}
	}
	printf("Cliente nao encontrado.\n");
	return -1;
}

// ETAPA DE EXCLUIR OS CLIENTES
void Excluir()
{
	int pos = Pesquisar();
	if (pos >= 0 && pos <= numClientes)
	{
		for (int i = pos; i < numClientes - 1; i++)
		{
			listacliente[i] = listacliente[i + 1];
		}
		numClientes--;
	}
}

// ETAPA DO MENU DE SERVIÇOS
void Menu()
{
	int escolha;
	float total = 0.0;

	printf("\nMENU DE SERVICOS\n");
	printf("1 - Troca do compressor - R$1000,00\n");
	printf("2 - Troca do filtro de ar (cabine) - R$30,00\n");
	printf("3 - Troca do evaporador - R$450,00\n");
	printf("4 - Troca do condensador - R$250,00\n");
	printf("5 - Limpeza no sistema completo - R$300,00\n");
	printf("6 - Carga de gas no sistema - R$150,00\n");
	printf("7 - Finalizar escolha de servicos\n");

	do
	{
		printf("Escolha um servico (1-7): ");
		scanf("%d", &escolha);

		switch (escolha)
		{
		case 1:
			total += 1000.0;
			break;
		case 2:
			total += 30.0;
			break;
		case 3:
			total += 450.0;
			break;
		case 4:
			total += 250.0;
			break;
		case 5:
			total += 300.0;
			break;
		case 6:
			total += 150.0;
			break;
		case 7:
			break;
		default:
			printf("Opcao invalida. Tente novamente.\n");
		}
	} while (escolha != 7);

	if (total >= 1700.0)
	{
		printf("Desconto de 9%% aplicado. Total a pagar: R$%.2lf\n", total * 0.91);
		printf("VOCE FOI CLASSIFICADO COMO UM CLIENTE FAMILIA\n");
	}
	else if (total >= 1000.0)
	{
		printf("Desconto de 7%% aplicado. Total a pagar: R$%.2lf\n", total * 0.93);
		printf("VOCE FOI CLASSIFICADO COMO UM CLIENTE AMIGO\n");
	}
	else if (total >= 500.0)
	{
		printf("Desconto de 5%% aplicado. Total a pagar: R$%.2lf\n", total * 0.95);
		printf("VOCE FOI CLASSIFICADO COMO UM CLIENTE PARCEIRO\n");
	}
	else
	{
		printf("Total a pagar: R$%.2lf\n", total);
	}
}

// ETAPA DO SORTEIO
void Sorteio()
{
	setlocale(LC_ALL, "Portuguese");

	int tabela[5][10];
	int numero = 1;
	int sorteio;

	printf("Sorteio de uma limpeza no sistema do ar-condicionado!\n");

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			tabela[i][j] = numero;
			numero++;
		}
	}
	printf("____________________________________\n");
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			printf("%2d  ", tabela[i][j]);
		}
		printf("\n");
	}
	printf("____________________________________\n");
	printf("\n");

	printf("Escolha dois numeros de 1 a 50:\n");
	scanf("%i\n", &sorteio);

	do
	{
		if (sorteio > 50)
		{
			printf("Por favor, digite dois numeros disponiveis na tabela:\n");
			scanf("%i\n", &sorteio);
		}

	} while (sorteio > 50);

	printf("O sorteio sera realizado em breve, o resultado estara disponivel no nosso perfil do instagram @_rodriguesar. Obrigado por nos escolher!\n");
}

// ETAPA DE EDITAR OS CLIENTES
void Editar()
{
	int buscaPosicao;

	printf("Informe o numero de identificacao do cliente a ser alterado:\n");
	scanf("%i", &buscaPosicao);

	for (int i = 0; i < numClientes; i++)
	{

		if (listacliente[i].posicao == buscaPosicao)
		{
			PrintClient(listacliente[i]);

			printf("Informe a nova divida do cliente:\n");
			scanf("%f", &listacliente[i].divida);
			printf("Dados do cliente atualizados com sucesso.\n");
			return;
		}
	}
}

// ETAPA DO CADASTRO DO E-MAIL

// Nesta função foi utilizado um recurso mais complexo em algoritmo que chamamos de recursão
// Recursão é uma função que chama ela mesma, precisa ter um pouco de cuidado para usar esse recurso pois pode ficar em loop infinito
// Da forma como estava, se fosse digitado um email invalido na segunda vez daria certo, agora ele não sai nunca até que seja digitido um válido
// Na prática seria interessante colocar um limite no número de tentativa, para não ficar preso nessa função.
// Podendo ser um if no tentativa igual ao limite, isso caracteriza uma condição de parada na recursão.
int Email(char email[80], int tentativa)
{
	if (tentativa == 0) {
		printf("Informe um endereco de e-mail valido:\n");
	} else {
		printf("email invalido, informe seu e-mail novamente:\n");
	}
	scanf("%s", email);

	if (strchr(email, '@') == NULL)
	{
		tentativa++;
		Email(email, tentativa);
	}
}