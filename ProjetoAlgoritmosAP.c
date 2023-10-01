#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Discente: Juanny Thayssa Guedes de Freitas
//Curso: Bacharelado em Tecnologia da Informação



// O projeto consiste em uma biblioteca, onde é possível pegar livros emprestados, devolver, doar, 
//sortear um livro aleatoriamente (caso esteja indeciso) e saber quão fiel os clientes são
//Foi implementado tambem um login e verificação de email, alem de uma cartela de sorteio, como prospoto pelo professor.

#define MAX_USERS 100
#define MAX_EMAIL_LEN 80

// Estrutura para armazenar informações do usuário
typedef struct {
    char usuario[50];
    char senha[50];
    char email[MAX_EMAIL_LEN];
} User;

// Vetor para armazenar os usuários cadastrados
User usuarios[MAX_USERS];
int numUsuarios = 0;

// Função para realizar o login
int login() {
    char usuario[50];
    char senha[50];

    printf("Digite seu nome de usuario: ");
    scanf("%s", usuario);
    printf("Digite sua senha: ");
    scanf("%s", senha);

    for (int i = 0; i < numUsuarios; i++) {
        if (strcmp(usuarios[i].usuario, usuario) == 0 && strcmp(usuarios[i].senha, senha) == 0) {
            printf("Bem-vindo a biblioteca Skoob, %s!\n", usuario);
            return i;
        }
    }

    printf("Nome de usuario ou senha incorretos. Tente novamente.\n");
    return -1;
}

// Função para verificar a validade do e-mail
int validarEmail(char *email) {
    if (strlen(email) >= MAX_EMAIL_LEN || strchr(email, '@') == NULL) {
        return 0; // Inválido
    }

    for (int i = 0; i < numUsuarios; i++) {
        if (strcmp(usuarios[i].email, email) == 0) {
            return 0; // E-mail já cadastrado
        }
    }

    return 1; // Válido
}

// Função para cadastrar um novo usuário
void cadastrarUsuario() {
    char usuario[50];
    char senha[50];
    char email[MAX_EMAIL_LEN];

    printf("Digite seu nome de usuario: ");
    scanf("%s", usuario);
    printf("Digite sua senha: ");
    scanf("%s", senha);

    while (1) {
        printf("Digite seu e-mail: ");
        scanf("%s", email);
        if (validarEmail(email)) {
            break;
        } else {
            printf("E-mail invalido ou ja cadastrado. Tente novamente.\n");
        }
    }

    strcpy(usuarios[numUsuarios].usuario, usuario);
    strcpy(usuarios[numUsuarios].senha, senha);
    strcpy(usuarios[numUsuarios].email, email);
    numUsuarios++;

    printf("Cadastro realizado com sucesso!\n");
}

// Função para listar os usuários cadastrados
void listarUsuarios() {
    printf("LISTA DE USUARIOS CADASTRADOS:\n");
    for (int i = 0; i < numUsuarios; i++) {
        printf("Nome de usuario: %s, E-mail: %s\n", usuarios[i].usuario, usuarios[i].email);
    }
}

// Função para exibir a tela principal
void exibirTelaPrincipal() {
    printf("======== TELA INICIAL ========\n");
    printf("[1] PEGAR UM LIVRO EMPRESTADO\n");
    printf("[2] DEVOLVER UM LIVRO\n");
    printf("[3] FIDELIDADE DOS CLIENTES\n");
    printf("[4] DOAR LIVROS\n");
    printf("[5] SORTEAR LIVRO ALEATORIAMENTE\n");
    printf("[6] ENCERRAR E SAIR\n");
}

void exibirMenuGenero() {
    printf("====== GENEROS DISPONIVEIS ======\n");
    printf("[1] FICCAO\n");
    printf("[2] ROMANCE\n");
    printf("[3] TERROR\n");
    printf("[4] SUSPENSE\n");
    printf("[6] VOLTAR PARA TELA INICIAL\n");
    printf("[7] ENCERRAR E SAIR\n");
}

void exibirMenuLivrosFiccao() {
    printf("====== FICCAO ======\n");
    printf("[1] FAHRENHEIT 451\n");
    printf("[2] ADMIRAVEL NOVO MUNDO\n");
    printf("[3] FRANKENSTEIN\n");
    printf("[4] DUNA\n");
    printf("[5] 2001: UMA ODISSEIA NO ESPAÇO\n");
    printf("[6] VOLTAR PARA TELA INICIAL\n");
    printf("[7] ENCERRAR E SAIR\n");
}

void exibirMenuLivrosRomance(){
    printf("====== ROMANCE ======\n");
    printf("[1] VERMELHO, BRANCO E SANGUE AZUL\n");
    printf("[2] TETO PARA DOIS\n");
    printf("[3] A CULPA E DAS ESTRELAS\n");
    printf("[4] ROMEU E JULIETA\n");
    printf("[5] ELEANOR E PARK\n");
    printf("[6] VOLTAR PARA TELA INICIAL\n");
    printf("[7] ENCERRAR E SAIR\n");
}

void exibirMenuLivrosTerror(){
    printf("====== TERROR ======\n");
    printf("[1] IT: A COISA\n");
    printf("[2] CORALINE\n");
    printf("[3] O VILAREJO\n");
    printf("[4] MISERY\n");
    printf("[5] E NÃO SOBROU NENHUM\n");
    printf("[6] VOLTAR PARA TELA INICIAL\n");
    printf("[7] ENCERRAR E SAIR\n");
}

void exibirMenuLivrosSuspense(){
    printf("====== SUSPENSE ======\n");
    printf("[1] A PACIENTE SILENCIOSA\n");
    printf("[2] O HOMEM DE GIZ\n");
    printf("[3] VERITY\n");
    printf("[4] A GAROTA DO LAGO\n");
    printf("[5] A CORRENTE\n");
    printf("[6] VOLTAR PARA TELA INICIAL\n");
    printf("[7] ENCERRAR E SAIR\n");
}

void alugarLivro() {
    printf("[1] PEGAR ESSE LIVRO EMPRESTADO\n");
    printf("[2] VOLTAR PARA TELA INICIAL\n");
}

void aluguelRegistrado() {
    printf("Emprestimo registrado, sua data de devolucao esta marcada para 29/09/2023, faca bom uso!!!\n");
}

//Função para exibir opção para confirmação de empréstimo
void escolhaLivros(){
    int alugar;
    alugarLivro();
    scanf("%d", &alugar);
    switch(alugar){
        case 1:
            aluguelRegistrado();
            break;
    }
}

// Lista de livros disponíveis
char *livros[] = {
    "FAHRENHEIT 451 - RAY BRADBURY",
    "ADMIRAVEL NOVO MUNDO - ALDOUS HUXLEY",
    "FRANKENSTEIN - MARY SHELLEY",
    "DUNA - FRANK HERBERT",
    "2001: UMA ODISSEIA NO ESPACO - ARTHUR C. CLARKE",
    "VERMELHO, BRANCO E SANGUE AZUL - CASEY MCQUISTON",
    "TETO PARA DOIS - BETH O'LEARY",
    "A CULPA E DAS ESTRELAS - JOHN GREEN",
    "ROMEU E JULIETA - WILLIAM SHAKESPEARE",
    "ELEANOR E PARK - RAINBOW ROWELL",
    "IT: A COISA - STEPHEN KING",
    "CORALINE - NEIL GAIMAN",
    "O VILAREJO - RAPHAEL MONTES",
    "MISERY - STEPHEN KING",
    "E NAO SOBROU NENHUM - AGATHA CHRISTIE",
    "A PACIENTE SILENCIOSA - ALEX MICHAELIDES",
    "O HOMEM DE GIZ - C. J. TUDOR",
    "VERITY - COLLEEN HOOVER",
    "A GAROTA DO LAGO - CHARLIE DONLEA",
    "A CORRENTE - ADRIAN MCKINTY",
    // Adicione mais livros conforme necessário
};

int numLivros = sizeof(livros) / sizeof(livros[0]);

// Função para sortear um livro aleatoriamente
char *sortearLivro() {
    // Inicializa o gerador de números aleatórios com o tempo atual
    srand(time(NULL));

    // Gera um índice aleatório dentro do intervalo válido
    int indice = rand() % numLivros;

    // Retorna o livro sorteado
    return livros[indice];
}

#define NUM_LINHAS 5
#define NUM_COLUNAS 5
#define MAX_NUM 25 // Número máximo na cartela

// Função para exibir a cartela de rifa e permitir ao usuário escolher um número
int escolherNumero() {
    int cartela[NUM_LINHAS][NUM_COLUNAS];

    // Preenche a cartela com números em ordem crescente de 1 a MAX_NUM
    int numero = 1;
    for (int i = 0; i < NUM_LINHAS; i++) {
        for (int j = 0; j < NUM_COLUNAS; j++) {
            cartela[i][j] = numero++;
        }
    }

    // Exibe a cartela
    printf("------ Cartela de Rifa do Box de Harry Potter ------\n");
    for (int i = 0; i < NUM_LINHAS; i++) {
        for (int j = 0; j < NUM_COLUNAS; j++) {
            printf("%2d\t", cartela[i][j]);
        }
        printf("\n");
    }

    // Solicita que o usuário escolha um número
    int numeroEscolhido;
    printf("Escolha um numero da cartela (1 a %d) para participar do sorteio: ", MAX_NUM);
    scanf("%d", &numeroEscolhido);

    // Verifica se o número escolhido está dentro do intervalo válido
    if (numeroEscolhido < 1 || numeroEscolhido > MAX_NUM) {
        printf("Numero fora do intervalo válido. Escolha um numero de 1 a %d.\n", MAX_NUM);
        return escolherNumero(); // Chama a função novamente
    }
    else {
        printf("Numero %d registrado.\n", numeroEscolhido);
    }

    return numeroEscolhido;
}

// Função principal
int main() {
    int primeiraOpcao;
    int genero;
    int escolha;
    int dias;
    int clienteFiel;
    int sorteio;
    int continuar = 1; // Variável para controlar o loop
    int opcao;
    int usuarioLogado = -1;

    //Só é possivel fazer login depois de fazer um cadastro, pois não há usuário pré-definido
    while (usuarioLogado == -1) {
        printf("====== TELA DE LOGIN ======\n");
        printf("[1] LOGIN\n");
        printf("[2] CADASTRAR USUARIO\n");
        printf("DIGITE A OPCAO DESEJADA: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                usuarioLogado = login();
                break;
            case 2:
                cadastrarUsuario();
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    }

    while (1) {
        printf("====== MENU ======\n");
        printf("[1] LISTAR USUARIOS CADASTRADOS\n");
        printf("[2] REALIZAR OPERACOES SOBRE ITENS\n");
        printf("[3] SORTEIO DE UM BOX DE LIVROS\n");
        printf("[4] SAIR\n");
        printf("DIGITE A OPCAO DESEJADA: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                listarUsuarios();
                break;
            case 2:
                while (continuar) { // Loop principal
                    exibirTelaPrincipal();
                    scanf("%d", &primeiraOpcao);
                    switch (primeiraOpcao) {
                        case 1:
                            exibirMenuGenero();
                            scanf("%d", &genero);
                            switch (genero) {
                                case 1:
                                    exibirMenuLivrosFiccao();
                                    scanf("%d", &escolha);
                                    switch(escolha) {
                                        case 1: 
                                            printf("=== FAHRENHEIT 541 ===\n");
                                            escolhaLivros();
                                            break;
                                        case 2:
                                            printf("=== ADMIRAVEL MUNDO NOVO ===\n");
                                            escolhaLivros();
                                            break;
                                        case 3:
                                            printf("=== FRANKENSTEIN ===\n");
                                            escolhaLivros();
                                            break;
                                        case 4:
                                            printf("=== DUNA ===\n");
                                            escolhaLivros();
                                            break;
                                        case 5:
                                            printf("=== 2001: UMA ODISSEIA NO ESPACO ===\n");
                                            escolhaLivros();
                                            break;
                                        case 6:
                                            break; // Voltar para a tela inicial
                                        case 7:
                                            continuar = 0; // Encerrar o programa
                                            break;
                                        default:
                                        printf("Opção invalida.\n");
                                        break;
                                    }
                                    break;
                                case 2:
                                    exibirMenuLivrosRomance();
                                    scanf("%d", &escolha);
                                    switch(escolha) {
                                        case 1: 
                                            printf("=== VERMELHO, BRANCO E SANGUE AZUL ===\n");
                                            escolhaLivros();
                                            break;
                                        case 2:
                                            printf("=== TETO PARA DOIS ===\n");
                                            escolhaLivros();
                                            break;
                                        case 3:
                                            printf("=== A CULPA E DAS ESTRELAS ===\n");
                                            escolhaLivros();
                                            break;
                                        case 4:
                                            printf("=== ROMEU E JULIETA ===\n");
                                            escolhaLivros();
                                            break;
                                        case 5:
                                            printf("=== ELEANOR E PARK ===\n");
                                            escolhaLivros();
                                            break;
                                        case 6:
                                            break; // Voltar para a tela inicial
                                        case 7:
                                            continuar = 0; // Encerrar o programa
                                            break;
                                        default:
                                            printf("Opção invalida.\n");
                                            break;
                                    }
                                    break;
                                case 3:
                                    exibirMenuLivrosTerror();
                                    scanf("%d", &escolha);
                                    switch(escolha) {
                                        case 1: 
                                            printf("=== IT: A COISA ===\n");
                                            escolhaLivros();
                                            break;
                                        case 2:
                                            printf("=== CORALINE ===\n");
                                            escolhaLivros();
                                            break;
                                        case 3:
                                            printf("=== O VILAREJO ===\n");
                                            escolhaLivros();
                                            break;
                                        case 4:
                                            printf("=== MISERY ===\n");
                                            escolhaLivros();
                                            break;
                                        case 5:
                                            printf("=== E NAO SOBROU NENHUM ===\n");
                                            escolhaLivros();
                                            break;
                                        case 6:
                                            break; // Voltar para a tela inicial
                                        case 7:
                                            continuar = 0; // Encerrar o programa
                                            break;
                                        default:
                                            printf("Opção invalida.\n");
                                            break;
                                    }
                                    break;
                                case 4:
                                    exibirMenuLivrosSuspense();
                                    scanf("%d", &escolha);
                                    switch(escolha) {
                                        case 1:
                                            printf("=== A PACIENTE SILENCIOSA ===\n");
                                            escolhaLivros();
                                            break;
                                        case 2:
                                            printf("=== O HOMEM DE GIZ ===\n");
                                            escolhaLivros();
                                            break;
                                        case 3:
                                            printf("=== VERITY ===\n");
                                            escolhaLivros();
                                            break;
                                        case 4:
                                            printf("=== A GAROTA DO LAGO ===\n");
                                            escolhaLivros();
                                            break;
                                        case 5:
                                            printf("=== A CORRENTE ===\n");
                                            escolhaLivros();
                                            break;
                                        case 6:
                                            break; // Voltar para a tela inicial
                                        case 7:
                                            continuar = 0; // Encerrar o programa
                                            break;
                                        default:
                                            printf("Opção invalida.\n");
                                            break;
                                    }
                                    break;
                                case 5:
                                    break; // Voltar para a tela inicial
                                case 6:
                                    continuar = 0; // Encerrar o programa
                                    break;
                                default:
                                    printf("Opção invalida.\n");
                                    break;
                            }
                            break;
                        case 2:
                            printf("====== DEVOLUCAO DE LIVROS ======\n");
                            printf("Informe quantos dias voce ficou com o livro: \n");
                            scanf("%d", &dias);
                                if (dias <= 20){
                                    printf("Voce devolveu o livro dentro do prazo, obrigado por seu comprometimento para com a nossa biblioteca.\n");
                                }
                                else {
                                    printf("Voce devolveu o livro com atraso, informamos que nao sera possivel disponibilizarmos outro livro para voce nos proximos 15 dias.\n");
                                }
                            break; 
                        case 3:
                            printf("====== CLIENTE FIEL ======\n");
                            printf("Descubra se voce e um cliente BRONZE, PRATA ou OURO e que recompensas temos para voce!!!\n");
                            printf("Quantos livros da nossa biblioteca voce ja leu? ");
                            scanf("%d", &clienteFiel);
                                if (clienteFiel <= 5) {
                                    printf("Voce ainda e um cliente BRONZE.\n");
                                } 
                                else if (clienteFiel > 5 && clienteFiel < 15) {
                                    printf("Voce e um cliente PRATA!!!\n");
                                } 
                                else if (clienteFiel >= 15) {
                                    printf("Voce e um cliente OURO, parabens, agradecemos a preferencia.\n");
                                }
                            break;
                        case 4:
                            printf("====== TELA DE DOACAO DE LIVROS ======\n");
                            printf("Nossa biblioteca recompensa quem doa livros com empréstimos grátis de acordo com a quantidade de livros doados.\n");
                            int doacao;
                            printf("Quantos livros deseja doar?\n");
                            scanf("%d", &doacao);
                            printf("Agradecemos a sua colaboracao com a nossa biblioteca, voce tras novos universos para nossos leitores, esperamos voce aqui novamente!!!\n");
                            break;
                        case 5:
                            printf("Nao sabe qual livro ler? Aqui temos um sorteio, desafie-se e conheca novos universos.\n");
                            printf("[1] SORTEAR UM LIVRO\n");
                            printf("[2] VOLTAR PARA TELA INICIAL\n");
                            scanf("%d", &sorteio); 
                            switch(sorteio){
                                case 1:
                                    printf("\nLivro sorteado: %s\n", sortearLivro());
                                case 2:
                                    break;
                            }
                            break;
                        case 6:
                            continuar = 0; // Encerrar o programa
                            break;
                        default:
                            printf("Opcao invalida.\n");
                            break;
                    }
                }
                break;
            case 3:
                escolherNumero();
                break;
            case 4:
                printf("Saindo...\n");
                exit(0);
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    }

    return 0;
}