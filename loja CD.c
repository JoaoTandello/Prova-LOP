#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
    char banda[50];
    int ano;
    char gen[50];
    int quant;
    float preco;
} CD;

CD cd;

int numCD = 0;

void cadastrarCD();
void visualizarCD();
void realizarVenda();
void pesquisarBanda();
void consultar();

int main() {
    setlocale(LC_ALL, "");
    int op;

    do {
        printf("--- Loja Som & Arte ---\n");
        printf("1- Cadastrar CD\n");
        printf("2- Visualizar CD\n");
        printf("3- Realizar venda\n");
        printf("4- Pesquisar CD por banda\n");
        printf("5- Consultar CD\n");
        printf("0- Sair\n");
        printf("Selecione uma opção: ");
        scanf("%d", &op);

        system("clear");

        switch (op) {
            case 1:
                cadastrarCD();
                break;
            case 2:
                visualizarCD();
                break;
            case 3:
                realizarVenda();
                break;
            case 4:
                pesquisarBanda();
                break;
            case 5:
                consultar();
                break;
            case 0:
                printf("Obrigado!\n");
                break;
            default:
                printf("\nOpção invalida.\n");
                break;
        }
    } while (op != 0);

    return 0;
}

void cadastrarCD() {
    if (numCD >= 1) {
        printf("\nJá existe CD cadastrado!\n");
        return;
    }
    printf("Nome da banda: ");
    scanf(" %[^\n]", cd.banda);
    printf("Ano de lançamento: ");
    scanf("%d", &cd.ano);
    printf("Gênero musical: ");
    scanf(" %[^\n]", cd.gen);
    printf("Quantidade: ");
    scanf("%d", &cd.quant);
    printf("Preço: ");
    scanf("%f", &cd.preco);

    numCD++;
    printf("\nCD cadastrado com sucesso!\n");
}

void visualizarCD() {
    if (numCD == 0) {
        printf("Nenhum CD cadastrado.\n");
        return;
    }
    printf("Banda: %s\n", cd.banda);
    printf("Ano: %d\n", cd.ano);
    printf("Gênero: %s\n", cd.gen);
    printf("Quantidade no estoque: %d\n", cd.quant);
    printf("Preço: R$ %.2f\n", cd.preco);
}

void realizarVenda() {
    if (numCD == 0) {
        printf("Nenhum CD cadastrado.\n");
        return;
    }
    int quant;
    printf("CD: %s\n", cd.banda);
    printf("Quantidade no estoque: %d\n", cd.quant);
    printf("Preço: R$ %.2f\n", cd.preco);
    printf("Quantidade que quer comprar: ");
    scanf("%d", &quant);

    if (quant <= 0) {
        printf("\nQuantidade inválida!\n");
        return;
    }
    if (quant > cd.quant) {
        printf("\nQuantidade insuficiente!", cd.quant);
        return;
    }

    cd.quant -= quant;
    float valor = quant * cd.preco;
    printf("\nVenda realizada! Quantidade: %d, Valor total: R$ %.2f\n", quant, valor);
    printf("Estoque atual: %d unidades\n", cd.quant);
    
}

void pesquisarBanda() {
    if (numCD == 0) {
        printf("Nenhum CD cadastrado.\n");
        return;
    }
    char banda[50];
    printf("Nome da banda: ");
    scanf(" %[^\n]", banda);

    int igual = 1;
    for (int i = 0; i < 50; i++) {
        if (cd.banda[i] != banda[i]) {
            igual = 0;
            break;
        }
    }
    if (igual) {
        printf("\nCD encontrado!\n");
        printf("Banda: %s\n", cd.banda);
        printf("Ano: %d\n", cd.ano);
        printf("Gênero: %s\n", cd.gen);
        printf("Quantidade no estoque: %d\n", cd.quant);
        printf("Preço: R$ %.2f\n", cd.preco);
    } else {
        printf("\nCD não encontrado!\n");
    }
}

void consultar() {
    if (numCD == 0) {
        printf("Nenhum CD cadastrado.\n");
        return;
    }
    char banda[50];
    printf("Nome da banda: ");
    scanf(" %[^\n]", banda);

    int i = 1;
    for (int i = 0; i < 50; i++) {
        if (cd.banda[i] != banda[i]) {
            i = 0;
            break;
        }
    }
    if (i) {
        printf("CD encontrado!\n");
        printf("Banda: %s\n", cd.banda);
        printf("Ano: %d\n", cd.ano);
        printf("Gênero: %s\n", cd.gen);
        printf("Quantidade no estoque: %d\n", cd.quant);
        printf("Preço: R$ %.2f\n", cd.preco);
        if (cd.quant == 0) {
            printf("Estamos sem esse CD no estoque no momemento!\n");
        }
    } else {
        printf("CD nao encontrado!\n");
    }
}