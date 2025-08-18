//DIEGO CARVALHO E ISRAEL LUCAS

// inclusão das bibliotecas usadas
#include <stdio.h>
#include <string.h>

int main(){
    // declaração das variaveis gerais usadas
    int opcao, prod, quant, indiceMaior;
    float maiscaro;
    // declaração das variaveis usadas como contador de produtos e faturamento
    int cont = 0;
    float faturado = 0;
    // declaração dos vetores para armazenar os dados obtidos
    int cod[10], est[10];
    float preco[10];
    char nome[10][30];

    //looping para o menu de opções sempre aparecer após uma ação ser realizada e deixar maleável a escolha do usuário sem
    //a necessidade de cadastrar todos os produtos de uma vez, ou vender todos de uma vez
    do{
    printf("\n EScolha a opção que deseja realizar: \n 1 para cadastrar produto \n 2 para venda \n 3 para relatório \n 4 para sair: ");
    scanf("%d", &opcao);
    //verificação das opção escolhida pelo usuário e encaminhamento para o bloco correspondente
    if(opcao == 1){
        if(cont >= 10){ // limitador de produtos cadastrados
            printf("\nLimite de produtos cadastrado atingido!");
        } else{ //atribuição de dados aos vetores
            printf("\nDigite o codigo do produto: ");   scanf("%d", &cod[cont]);
            printf("\nDigite o nome do produto: ");
            getchar(); // limpa o \n que sobra do scanf
            fgets(nome[cont], 30, stdin);
            nome[cont][strcspn(nome[cont], "\n")] = '\0'; //remove o \n deixado pelo enter do fgets
            printf("\nDigite o preço do produto: ");   scanf("%f", &preco[cont]);
            printf("\nDigite a quantidade em estoque do produto: ");   scanf("%d", &est[cont]);
            cont++;
        }

    }else if(opcao == 2){
        //coleta de dados para a venda dos produtos baseado no codigo e quantidade
        printf("\nDigite o codigo do produto: ");
        scanf("%d", &prod);
        printf("\nDigite a quantidade comprada: ");
        scanf("%d", &quant);
        for(int i = 0; i < cont; i++){
            if(prod == cod[i]){ // verifica o codigo digitado com os cadastrados para realizar a venda
                if(quant > est[i]){
                    // exibe o estoque atual em caso de excedente de compra
                    printf("Quantidade superior a existente no estoque!!: %d unidades", est[i]);
                } else{
                    est[i] -= quant; // reduz a quantidade vendida do estoque
                    faturado += quant * preco[i]; // acumula o valor faturado
                }
                break; //interrompe o loop e retorna ao menu
            }
        }

    }else if(opcao == 3){
        //exibe o relatorio vendas, estoque baixo e produto mais caro presente no estoque
        for(int i = 0; i < cont; i++){
            if(est[i] < 5) // verifica quais produtos estão com estoque abaixo de 5 unidades e exibe seus dados
                printf("\nProduto %s (codígo %d) está com estoque baixo: %d unidades!", nome[i], cod[i], est[i]);
        }
        printf("\nTotal faturado: R$ %.2f", faturado); // exibe o total faturado
        
        maiscaro = 0;
        indiceMaior = -1;

        for (int i = 0; i < cont; i++){ //loop de verificação para encontrar o produto com maior quantidade e valor em estoque
            float valorTotal = est[i] * preco[i];
            if(valorTotal > maiscaro){
                maiscaro = valorTotal;
                indiceMaior = i;
            }
        }
        if(indiceMaior != -1){ //se for encontrado, o indice será diferente de -1, assim exibindo o produto
            // é necessario manter o indice como -1 para acessar todas as casas do vetor
            printf("\nO produto mais caro em estoque é %s (código %d) com %d unidades e valor total de R$ %.2f", nome[indiceMaior], cod[indiceMaior], est[indiceMaior], maiscaro);
        }
        
    }

    } while(opcao != 4);
    //exibe uma mensagem de logout ao sair do sistema
        printf("\nLogout realizado com sucesso!");
    
    return 0;
}