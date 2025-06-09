#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
    char nome[50];
    int quant;
    float preco;
} Produto;

Produto produto;

int numProduto = 0; 

void cadastrarProduto();
void visualizarProduto();
void realizarCompra();

int main() {
    setlocale(LC_ALL, "");
    int op;

    do {
        printf("---- Supermercado SuperMais ----\n");
        printf("1- Cadastrar produto\n");
        printf("2- Visualizar produto\n");
        printf("3- Realizar compra\n");
        printf("0- Sair\n");
        printf("Selecione uma opção: ");
        scanf("%d", &op);

        system("clear"); 

        switch (op) {
            case 1:
                cadastrarProduto();
                break;
            case 2:
                visualizarProduto();
                break;
            case 3:
                realizarCompra();
                break;
            case 0:
                printf("Obrigado!\n");
                break;
            default:
                printf("\nOpção inválida.\n");
                break;
        }
       
    } while (op != 0);

    return 0;
}

void cadastrarProduto() {
    if (numProduto >= 1) {
        printf("\nJá existe um produto cadastrado!\n");
        return;
    }
    printf("Nome do produto: ");
    scanf(" %[^\n]", produto.nome);
    printf("Quantidade: ");
    scanf("%d", &produto.quant);
    printf("Preço: ");
    scanf("%f", &produto.preco);
    
    numProduto++;
    printf("\nProduto cadastrado com sucesso!\n");
}

void visualizarProduto() {
    if (numProduto == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }
    printf("Nome: %s\n", produto.nome);
    printf("Quantidade em estoque: %d\n", produto.quant);
    printf("Preço unitário: R$ %.2f\n", produto.preco);
}

void realizarCompra() {
    if (numProduto == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }
    int quant;
    printf("Produto: %s", produto.nome);
    printf ("Quantidade em estoque: %d", produto.quant);
    printf ("Preço: R$ %.2f\n", produto.preco);
    printf("Quantidade que quer comprar: ");
    scanf("%d", &quant);
    
    if (quant <= 0) {
        printf("\nQuantidade inválida!\n");
        return;
    }
    if (quant > produto.quant) {
        printf("\nEstoque insuficiente! Disponível: %d\n", produto.quant);
        return;
    }
    
    produto.quant -= quant;
    float valor = quant * produto.preco;
    printf("\nCompra realizada! Quantidade: %d, Valor total: R$ %.2f\n", quant, valor);
    printf("Estoque atualizado: %d unidades\n", produto.quant);
}
