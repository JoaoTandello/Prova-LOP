#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
    char nome[50];
    int quant;
    float preco;
} Pizza;

typedef struct {
    char nome[50];
} Cliente;

Pizza pizza;
Cliente cliente;

int numPizza;
int numCliente;

void cadastrarPizza();
void cadastrarCliente();
void listarPizzas();
void listarClientes();
void realizarVenda();

int main() {
    setlocale(LC_ALL, "");
    int op;

    do {
        printf("\n--- PIZZARIA NOSTRA PIZZA ---\n");
        printf("1- Cadastrar pizza\n");
        printf("2- Cadastrar cliente\n");
        printf("3- Listar pizzas\n");
        printf("4- Listar clientes\n");
        printf("5- Realizar venda\n");
        printf("0- Sair\n");
        printf("Escolha a opção desejada: ");
        scanf("%d", &op);
        system("clear");

        switch (op) {
            
            case 1:
                cadastrarPizza();
                break;
                
            case 2:
                cadastrarCliente();
                break;
                
                
            case 3:
                listarPizzas();
                break;
            
            case 4:
                listarClientes();
                break;
                
            case 5:
                realizarVenda();
                break;
                
            case 0:
                printf("Obrigado!\n");
                break;
                
            default:
                printf("\nInvalido.\n");
                break;
        }
    } while (op != 0);

    return 0;
}

void cadastrarPizza() {
 
    printf("Sabor da pizza: ");
    scanf(" %[^\n]", pizza.nome);
    printf("Quantidade: ");
    scanf("%d", &pizza.quant);
    printf("Preço: ");
    scanf("%f", &pizza.preco);

    numPizza++;
    printf("\nPizza cadastrada com sucesso!\n");
}

void cadastrarCliente() {
    printf("Nome do cliente: ");
    scanf(" %[^\n]", cliente.nome);
    numCliente++;
    printf("\nCliente cadastrado com sucesso!\n");
}

void listarPizzas() {
    if (numPizza == 0) {
        printf("Nenhuma pizza cadastrada!\n");
        return;
    }
    printf("Nome: %s\n", pizza.nome);
    printf("Quantidade: %d\n", pizza.quant);
    printf("Preço da pizza: R$%.2f\n", pizza.preco);
}

void listarClientes() {
    if (numCliente == 0) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }
    printf("Nome: %s\n", cliente.nome);
}

void realizarVenda() {
    if (numCliente == 0) {
        printf("Nenhum cliente cadastrado, por favor, faça o cadastro antes.\n");
        return;
    }
    if (numPizza == 0) {
        printf("Nenhuma pizza cadastrada!\n");
        return;
    }
    int quant;
    printf("Pizza: %s\n", pizza.nome);
    printf("Quantidade: %d\n", pizza.quant);
    printf("Preco: R$ %.2f\n", pizza.preco);
    printf("Quantas pizzas gostaria de comprar?: ");
    scanf("%d", &quant);

    if (quant <= 0) {
        printf("\nQuantidade invalida!\n");
        return;
    }
    if (quant > pizza.quant) {
        printf("\nPizzas insuficientes! Disponivel: %d\n", pizza.quant);
        return;
    }

    pizza.quant -= quant;
    float valor = quant * pizza.preco;
    printf("\nVenda realizada para %s!\n", cliente.nome);
    printf("Pizza comprada: %s\n", pizza.nome);
    printf("Quantidade: %d\n", quant);
    printf("Valor total: R$ %.2f\n", valor);
    printf("Pizzas no estoque: %d unidades\n", pizza.quant);
    if (pizza.quant == 0) {
        printf("Pizza em falta!\n");
    }
}