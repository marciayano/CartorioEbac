#include <stdio.h> //biblioteca de comunicacao com o usuario
#include <stdlib.h> //biblioteca para alocar espacos em memoria
#include <locale.h> //biblioteca de alocacoes de texto por regiao
#include <string.h> //biblioteca responsavel por cuidar das strings

int registrar(){
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo no banco de dados = meu pc. acesse FILE e crie file
	file = fopen(arquivo, "w"); //w= write
	fprintf(file,cpf); //salvar valor da variavel no file
	fclose(file); //fechar o file
	
	file = fopen(arquivo,"a"); //atualizar file
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a"); //atualizar file
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a"); //atualizar file
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	int decisaoRegistro=0;
				
					printf("\n\nDeseja registrar mais um usuário?\n\n"); //inicio do menu
					printf("\t1 - Sim\n");
					printf("\t2 - Voltar para o menu principal\n");
					printf("Opcao: "); //fim do menu
	
					scanf("%d", &decisaoRegistro);
					system("cls"); 
				
					switch(decisaoRegistro){
						case 1:
							registrar();
							break;
						
						case 2:
							break;
					
						default:
							printf("esta opcao nao esta disponivel\n");
							system("pause");
					}
					
	system("pause");	
}

int consultar(){
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //r = read
	
	if(file==NULL){
		printf("Arquivo nao localizado! \n");
	}
	
	while(fgets(conteudo,200,file) != NULL){
		printf("\nEssas sao as informacoes do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	fclose(file);
	
	system("pause");
}

int deletar(){
	char cpf[40];
	
	printf("Digite o CPF do usuario a ser deletado: "); //msg ao usuario
	scanf("%s",cpf); //armazenando em cpf
	
	remove(cpf); //deletando cpf
	
	FILE *file; //entrar na biblioteca FILE e puxar os arquivos file
	file = fopen(cpf,"r");
	fclose(file);
	
	if(file == NULL){
		printf("usuario não localizado\n");
		system("pause");
	}

	
}


int main(){
	
	int opcao=0; //definindo variavel
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cartório da EBAC ###\n\n");
	printf("login de administrador\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada,"admin");
	
	if(comparacao == 0){
		
		system("cls");
		for(laco=1;laco=1;){ // inicio do laco | repetir enquanto for | ++ ou -- ou vazio
		
			setlocale(LC_ALL, "Portuguese"); //set linguagem para aceitar caracter especial
		
			printf("### Cartório da EBAC ###\n\n"); //inicio do menu
			printf("Escolha a opção desejada do menu:\n\n"); 
			printf("\t1 - Registrar nomes \n");
			printf("\t2 - Consultar nomes \n");
			printf("\t3 - Deletar nomes \n"); 
			printf("\t4 - Sair do sistema \n\n");
			printf("Opcao: "); //fim do menu
		
			scanf("%d", &opcao); //armazenando a escolha do usuario
				
			system("cls"); //apaga mensagens anteriores
		
			switch(opcao){
				case 1:
					registrar();
					break;
			
				case 2:
					consultar();
					break;
				
				case 3:
					deletar();
					break;
			
				case 4:
					printf("Obrigado por utilizar o sistema!\n");
					return 0;
					break;
				
				default:
					printf("esta opcao nao esta disponivel\n");
					system("pause");
				
			}
			
			printf("\nEsse Software é de livre uso para fins didáticos\n");
			system("cls"); 
		
		}
	}
	else
		printf("senha incorreta!");
}
