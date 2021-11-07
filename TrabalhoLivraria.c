#include <stdio.h>
#include <string.h>
#include <time.h>

#define LIVROS "Livros.dat"
#define CLIENTES "Clientes.dat"
#define VENDAS "Vendas.dat"

/*código, título, preço, código do autor1, código do autor2,
código do autor3, código do autor4, código da categoria (assunto),
código da editora, edição, ano de publicação e quantidade em estoque
*/
struct reg_livro{
  int pklivro; //Codigo do Livro
  char titulo[50]; //Titulo do Livro
  float preco; //Preço do Livro
  int codautor1;
  int codautor2;
  int codautor3;
  int codautor4;
  int codcategoria;
  int codeditora;
  int edicao;
  int ano;
  int qtdestoque;
};
//código, sobrenome, nome
struct reg_autor{
  int pkautor;
  char sobrenome[50];
  char nome[14];
};
/*
código da categoria, descrição da categoria (por exemplo: romance,
ficção, policial, biografias, direito, informática, etc.)*/
struct reg_categoria{
  int pkcategoria;
  char descricaocategoria[50];
};
// código,  nome, contato, fone, e-mail.
struct reg_editora{
  int pkeditora;
  char nome[50];
  char contato[50];
  char fone[50];
  char email[50];
};

void CadastrarLivro(){
  FILE *fplivro;
  struct reg_livro livro;
  char opc;
  //Entrada das informações sobre o Livro
  printf("\n--Cadastro de Livro--");
  printf("\nDigite o Codigo: ");
  fflush(stdin); scanf("%i",&livro.pklivro);
  printf("Digite o Titulo: ");
  fflush(stdin); gets(&livro.titulo);
  printf("Digite o Preco: ");
  fflush(stdin); scanf("%f",&livro.preco);
  printf("\nDigite o Codigo do Autor 1: ");
  fflush(stdin); scanf("%i",&livro.codautor1);
  printf("\nDigite o Codigo do Autor 2: ");
  fflush(stdin); scanf("%i",&livro.codautor2);
  printf("\nDigite o Codigo do Autor 3: ");
  fflush(stdin); scanf("%i",&livro.codautor3);
  printf("\nDigite o Codigo do Autor 4: ");
  fflush(stdin); scanf("%i",&livro.codautor4);
  printf("\nDigite o Codigo da Categoria: ");
  fflush(stdin); scanf("%i",&livro.codcategoria);
  printf("\nDigite o Codigo da Editora: ");
  fflush(stdin); scanf("%i",&livro.codeditora);
  printf("\nDigite a Edicao: ");
  fflush(stdin); scanf("%i",&livro.edicao);
  printf("\nDigite o Ano: ");
  fflush(stdin); scanf("%i",&livro.ano);
  printf("\nDigite a Quantidade em estoque: ");
  fflush(stdin); scanf("%i",&livro.qtdestoque);

  //Pedir confirmação se deseja gravar
  printf("\nGravar?(S/N) ");
  fflush(stdin); scanf("%c",&opc);
  if ((opc!='S')&&(opc!='s')){
    printf("\nOperacao Cancelada!");
    return;
  }

  //Gravar os dados no Arquivo
  //-> Abrir o Arquivo
  fplivro = fopen("livro.dat","ab");
  //-> Gravar
  fwrite(&livro,sizeof(livro),1,fplivro);
  //-> Fechar
  fclose(fplivro);

  printf("\nLivro Cadastrado com Sucesso.");

}//Fim cadastrarLivro()

void CadastrarAutor(){
  FILE *fpautor;
  struct reg_autor autor;
  char opc;
/*int pkautor;
  char sobrenome[50];
  char nome[14];*/
  //Solicitar os dados do Cliente
  printf("\nDigite o Codigo: ");
  fflush(stdin); scanf("%i",&autor.pkautor);
  printf("Digite o Sobrenome: ");
  fflush(stdin); gets(&autor.sobrenome);
  printf("Digite o Nome: ");
  fflush(stdin); gets(&autor.nome);

  //Pedir confirmação se deseja gravar
  printf("\nGravar?(S/N) ");
  fflush(stdin); scanf("%c",&opc);
  if ((opc!='S')&&(opc!='s')){
    printf("\nOperacao Cancelada!");
    return;
  }
  //Gravar os dados no Arquivo
  //-> Abrir o Arquivo
  fpautor = fopen("autor.dat","ab");
  //-> Gravar
  fwrite(&autor,sizeof(autor),1,fpautor);
  //-> Fechar
  fclose(fpautor);

  printf("\nAutor Cadastrado com Sucesso.");

}//Fim CadastrarAutor()


void CadastrarCategoria(){
  FILE *fpcategoria;
  struct reg_categoria categoria;
  char opc;
/*struct reg_categoria{
  int pkcategoria;
  char descricaocategoria[50];
};*/
  //Solicitar os dados do Cliente
  printf("\nDigite o Codigo: ");
  fflush(stdin); scanf("%i",&categoria.pkcategoria);
  printf("Digite a Descricao da Categoria: ");
  fflush(stdin); gets(&categoria.descricaocategoria);

  //Pedir confirmação se deseja gravar
  printf("\nGravar?(S/N) ");
  fflush(stdin); scanf("%c",&opc);
  if ((opc!='S')&&(opc!='s')){
    printf("\nOperacao Cancelada!");
    return;
  }
  //Gravar os dados no Arquivo
  //-> Abrir o Arquivo
  fpcategoria = fopen("categoria.dat","ab");
  //-> Gravar
  fwrite(&categoria,sizeof(categoria),1,fpcategoria);
  //-> Fechar
  fclose(fpcategoria);

  printf("\n Categoria Cadastrada com Sucesso.");

}//Fim CadastrarCategoria()

void CadastrarEditora(){
/*reg_editora{
  int pkeditora;
  char nome[50];
  char contato[50];
  char fone[50];
  char email[50];*/
  FILE *fpeditora;
  struct reg_editora editora;
  char opc;
  //Solicitar os dados do Cliente
  printf("\nDigite o Codigo: ");
  fflush(stdin); scanf("%i",&editora.pkeditora);
  printf("Digite o Nome da Editora: ");
  fflush(stdin); gets(&editora.nome);
  printf("Digite o Contato: ");
  fflush(stdin); gets(&editora.contato);
  printf("Digite o Fone: ");
  fflush(stdin); gets(&editora.fone);
  printf("Digite o Email: ");
  fflush(stdin); gets(&editora.email);

  //Pedir confirmação se deseja gravar
  printf("\nGravar?(S/N) ");
  fflush(stdin); scanf("%c",&opc);
  if ((opc!='S')&&(opc!='s')){
    printf("\nOperacao Cancelada!");
    return;
  }
  //Gravar os dados no Arquivo
  //-> Abrir o Arquivo
  fpcategoria = fopen("editora.dat","ab");
  //-> Gravar
  fwrite(&editora,sizeof(editora),1,fpeditora);
  //-> Fechar
  fclose(fpeditora);

  printf("\n Editora Cadastrada com Sucesso.");
}//Fim CadastrarEditora()


void listarTodosLivros(){
  FILE *fplivro;
  struct reg_livro livro;

  //Abrir o Arquivo
  fplivro = fopen(LIVROS,"rb");

  printf("\n      * * *  Relatorio de Todos os Livros  * * *\n");
  printf("\nCodigo Titulo                         Preco");
  //Ler registro por registro
  while (fread(&livro,sizeof(livro),1,fplivro)==1){
    //Mostrar na Tela
    printf("\n %-6i %-30s %5.2f",livro.pklivro,livro.titulo, livro.preco);

  }


  //Fechar arquivo
  fclose(fplivro);

}//Fim listarTodosLivros()

void consultarPeloCodigo(){
  FILE *fplivro;
  struct reg_livro livro;
  int cod, achou=0;

  //Solicitar o codigo do Livro
  printf("\nDigite o Codigo do Livro a ser Localizado: ");
  fflush(stdin); scanf("%i",&cod);

  //Abrir o Arquivo
  fplivro = fopen(LIVROS,"rb");

  //Localizar o Livro que tenha o código procuradp
  while ((achou==0)&&(fread(&livro,sizeof(livro),1,fplivro)==1)){
    //printf("\nLivro->%i",livro.codigo);
    if (livro.pklivro == cod){
      printf("\nCodigo: %i",livro.pklivro);
      printf("\nTitulo: %s",livro.titulo);
      printf("\nPreco: %5.2f",livro.preco);
      achou=1;
    }
  }

  //if (achou==0)
  if (!achou)
    printf("\n Livro NAO Localizado!!");

  //Fechar o Arquivo
  fclose(fplivro);

}//Fim consultarPeloCodigo()

void consultarPeloTitulo(){
  FILE *fplivro;
  struct reg_livro livro;
  int achou=0;
  char tit[50];

  //Solicitar o Titulo do Livro
  printf("\nDigite o Titulo do Livro a ser Localizado: ");
  fflush(stdin); gets(tit);

  //Abrir o Arquivo
  fplivro = fopen(LIVROS,"rb");

  //Localizar o Livro que tenha o título procurado
  while ((achou==0)&&(fread(&livro,sizeof(livro),1,fplivro)==1)){
    //printf("\nLivro->%i",livro.codigo);
    if (strcmp(livro.titulo,tit)==0){  //Strings iguais - Achei o Livro
      printf("\nCodigo: %i",livro.pklivro);
      printf("\nTitulo: %s",livro.titulo);
      printf("\nPreco: %5.2f",livro.preco);
      achou=1;
    }
  }

  //if (achou==0)
  if (!achou)
    printf("\n Livro NAO Localizado!!");

  //Fechar o Arquivo
  fclose(fplivro);

}//Fim consultarPeloTitulo()

void consultarPalavraTitulo(){
  FILE *fplivro;
  struct reg_livro livro;
  char palavra[30];
  int achou=0;


  //Solcitar a Palavra-Chave
  printf("\nDigite a Palavra-Chave: ");
  fflush(stdin); gets(palavra);

  //Abrir o Arquivo de Livros
  fplivro = fopen(LIVROS,"rb");

  //Ler registro por registro e comparar se aparece a palavra no titulo e mostrar
  while (fread(&livro,sizeof(livro),1,fplivro)==1){
      if (strstr(livro.titulo,palavra)!=NULL){
        achou++;
        if (achou==1){
          printf("\nCodigo Titulo                         Preco");
        }
        printf("\n%-6i %-30s %5.2f",livro.pklivro,livro.titulo, livro.preco);
      }
  }

  if (achou==0){
    printf("\nNenhum Livro Encontrado com a palavra %s no Titulo.",palavra);
  }

  //Fechar o Arquivo
  fclose(fplivro);

}//consultarPalavraTitulo()

void ConsultarParteIncialNomeAutor(){
  FILE *fpautor;
  struct reg_autor autor;
  char parteinicial[30];
  int achou=0;


  //Solcitar a Parte Inicial do Nome
  printf("\nDigite a parte inicial do Nome: ");
  fflush(stdin); gets(parteinicial);

  //Abrir o Arquivo de Livros
  fpautor = fopen("autor.dat","rb");

  //Ler registro por registro e comparar se aparece a PARTE INICIAL DO NOME
  while (fread(&autor,sizeof(autor),1,fpautor)==1){
      if (strncmp(autor.nome,parteinicial,strlen(parteinicial))==0){
        achou++;
        if (achou==1){
          printf("\Codigo Nome                                Fone           Email               ");
        }
        printf("\n%-6i %-35s %-14s %-20s",autor.pkautor,autor.nome,autor.sobrenome);
      }
  }

  if (achou==0){
    printf("\nNenhum Cliente Encontrado com esta parte Inicial do Nome.");
  }

  //Fechar o Arquivo
  fclose(fpautor);

}//Fim consultarParteIncialNomeCliente()

void alterarLivro(){
  FILE *fplivro;
  struct reg_livro livro;
  int cod, achou=0;
  char opc;

  //Solicitar o codigo do Livro a ser Alterado
  printf("\nDigite o Codigo do Livro a ser ALTERADO: ");
  fflush(stdin); scanf("%i",&cod);

  //Abrir o Arquivo
  fplivro = fopen(LIVROS,"rb+");

  //Localizar o Livro que tenha o código procuradO
  while ((achou==0)&&(fread(&livro,sizeof(livro),1,fplivro)==1)){
    //printf("\nLivro->%i",livro.codigo);
    if (livro.pklivro == cod){
      printf("\nCodigo: %i",livro.pklivro);
      printf("\nTitulo: %s",livro.titulo);
      printf("\nPreco: %5.2f",livro.preco);
      achou=1;
    }
  }

  //if (achou==0)
  if (!achou){
    printf("\n Livro NAO Localizado!!");
    //Fechar o Arquivo
    fclose(fplivro);
    return;
  }

  //Pedir os novos dados
  printf("\nDeseja alterar o Titulo?(S/N) ");
  fflush(stdin);  scanf("%c",&opc);
  if ((opc=='S')||(opc=='s')){
    printf("\nDigite o novo Titulo: ");
    fflush(stdin); gets(livro.titulo);
  }
  printf("\nDeseja alterar o Preco?(S/N) ");
  fflush(stdin);  scanf("%c",&opc);
  if ((opc=='S')||(opc=='s')){
    printf("\nDigite o novo Preco: ");
    fflush(stdin); scanf("%f",&livro.preco);
  }

  //Confirmar Alteração e Gravar
  printf("\nGravar Alteracoes?(S/N) ");
  fflush(stdin);  scanf("%c",&opc);
  if ((opc!='S')&&(opc!='s')){
    printf("\nAlteracao Cancelada.");
    fclose(fplivro);
    return;
  }

  //Gravar alteracao no Arquivo
  //Voltar o ponteiro no arquivo para o registro anterior
  fseek(fplivro,-sizeof(livro),1);
  fwrite(&livro,sizeof(livro),1,fplivro); //Gravou o registro com os dados alterados
  fclose(fplivro);

  //Mostrar mensagem de feedback para o usuário
  printf("\nLivro Alterado com Sucesso.");

} //Fim alterarLivro()

void excluirLivro(){
  FILE *fplivro, *fplivrosnew;
  struct reg_livro livro;
  int cod, achou=0;
  char opc;

  //Solicitar o codigo do Livro a ser Excluido
  printf("\nDigite o Codigo do Livro a ser EXCLUIDO: ");
  fflush(stdin); scanf("%i",&cod);

  //Abrir o Arquivo
  fplivro = fopen(LIVROS,"rb");

  //Localizar o Livro que tenha o código procuradO
  while ((achou==0)&&(fread(&livro,sizeof(livro),1,fplivro)==1)){
    //printf("\nLivro->%i",livro.codigo);
    if (livro.pklivro== cod){
      printf("\nCodigo: %i",livro.pklivro);
      printf("\nTitulo: %s",livro.titulo);
      printf("\nPreco: %5.2f",livro.preco);
      achou=1;
    }
  }

    //Fechar o Arquivo
    fclose(fplivro);


  //if (achou==0)
  if (!achou){
    printf("\n Livro NAO Localizado!!");
    return;
  }

  //Confirmar EXCLUSÃO
  printf("\nConfirma Exclusao?(S/N) ");
  fflush(stdin);  scanf("%c",&opc);
  if ((opc!='S')&&(opc!='s')){
    printf("\nEXCLUSAO Cancelada.");
    return;
  }

  //Excluir o Registro do Livro

  //Copiar todos os registros (menos aquele a ser removido) para um arquivo temporario
  fplivro = fopen(LIVROS,"rb");
  fplivrosnew = fopen("livrosnew.dat","wb");
  while(fread(&livro,sizeof(livro),1,fplivro)==1){ //Le do arquivo original
    if (livro.pklivro!=cod)
      fwrite(&livro,sizeof(livro),1,fplivrosnew); //Grava no arquivo temporario
  }
  fclose(fplivro);
  fclose(fplivrosnew);

  system("del livros.dat"); //Remove o arquivo Original
  system("ren livrosnew.dat Livros.dat"); //Renomeia o temporario para o nome do Original

  printf("\nLivro Excluido com Sucesso.");
}//Fim excluirLvro()

void listarTodosAutores(){
  FILE *fpautor;
  struct reg_autor autor;

  //Abrir o Arquivo
  fpautor = fopen("autor.dat","rb");

  printf("\n      * * *  Relatorio de Todos os Clientes  * * *\n");
  printf("\nCodigo Nome                                Fone           Email                    ");
  //Ler registro por registro
  while (fread(&autor,sizeof(autor),1,fpautor)==1){
    //Mostrar na Tela
    printf("\n%-6i %-35s %-14s ",autor.pkautor,autor.nome,autor.sobrenome);
  }


  //Fechar arquivo
  fclose(fpautor);

}//Fim listarTodosClientes()

/*
struct reg_cliente localizarClientePeloCodigo(int codcli){
  FILE *fpcliente;
  struct reg_cliente cliente;
  int achou=0;

  //Abrir o Arquivo
  fpcliente = fopen(CLIENTES,"rb");

  //Localizar o CLIENTE que tenha o código procurado
  achou=0;
  while ((achou==0)&&(fread(&cliente,sizeof(cliente),1,fpcliente)==1)){
    if (cliente.codigo == codcli){
      achou=1;
    }
  }

  if (!achou){ //Não encontrou nenhum cliente com o código procurado
    cliente.codigo = -1; //sinaliza que NÃO ACHOU O CLIENTE COM O CÓDIGO PROCURADO
  }

  fclose(fpcliente);

  return cliente;
}//Fim localizarClientePeloCodigo()

*/

/*
void efetuarVenda(){
  FILE *fpcliente, *fplivro, *fpvenda;
  struct reg_cliente cliente;
  struct reg_livro livro;
  struct reg_venda venda;
  int codcli, codliv, codvenda;
  int achou,qtde;
  char op;
  struct tm *datalocal;
  time_t t;
  char hora[9];

  //Solicitar o Codigo da Venda
  printf("\nDigite o Codigo da Venda: ");
  fflush(stdin); scanf("%i",&codvenda);

  //Solicitar o Código do Cliente
  printf("\nDigite o Codigo do Cliente: ");
  fflush(stdin); scanf("%i",&codcli);

  //Abrir o Arquivo
  fpcliente = fopen(CLIENTES,"rb");

  //Localizar o CLIENTE que tenha o código procurado
  achou=0;
  while ((achou==0)&&(fread(&cliente,sizeof(cliente),1,fpcliente)==1)){
    if (cliente.codigo == codcli){
      printf("\nCodigo: %i",cliente.codigo);
      printf("\nNome: %s",cliente.nome);
      printf("\nFone: %s",cliente.fone);
      achou=1;
    }
  }

  //if (achou==0)
  if (!achou){
    printf("\n cliente NAO Localizado!!");
    fclose(fpcliente);
    return;  //Retorna para o Menu Principal
  }

  //Se localizou o cliente, pedir confirmação
  printf("\nConfirma Cliente(S/N)? ");
  fflush(stdin); scanf("%c",&op);

  if ((op=='N')||(op=='n')){
    printf("\n cliente NAO Confirmado!!");
    fclose(fpcliente);
    return;  //Retorna para o Menu Principal
  }

  //Solicitar o Código do Livro a ser vendido
  printf("\nDigite o Codigo do Livro: ");
  fflush(stdin); scanf("%i",&codliv);

  //Abrir o Arquivo
  fplivro = fopen(LIVROS,"rb");

  //Localizar o Livro que tenha o código procurado
  achou=0;
  while ((achou==0)&&(fread(&livro,sizeof(livro),1,fplivro)==1)){
    if (livro.codigo == codliv){
      printf("\nCodigo: %i",livro.codigo);
      printf("\nTitulo: %s",livro.titulo);
      printf("\nPreco: %5.2f",livro.preco);
      achou=1;
    }
  }

  //if (achou==0)
  if (!achou){
    printf("\n Livro NAO Localizado!!");
    fclose(fplivro);
    return; //Retorna para o Menu Principal
  }

  //Fechar o Arquivo
  fclose(fplivro);

  //Pedir confirmação
  printf("\nConfirma Livro(S/N)? ");
  fflush(stdin); scanf("%c",&op);

  if ((op=='N')||(op=='n')){
    printf("\n Livro NAO Confirmado!!");
    fclose(fplivro);
    return;  //Retorna para o Menu Principal
  }

  //Solicitar a Qtde
  printf("\nDigite a Qtde: ");
  fflush(stdin); scanf("%i",&qtde);

  printf("\nValor da venda deste Livro: %5.2f",livro.preco*qtde);

  //Confirmar a Venda
  printf("\nConfirma Venda(S/N)? ");
  fflush(stdin); scanf("%c",&op);

  if ((op=='N')||(op=='n')){
    printf("\n Venda NAO Confirmada!!");
    return;  //Retorna para o Menu Principal
  }

  //Gravar a Venda
  venda.codigo = codvenda;
  venda.cod_cliente = cliente.codigo;
  venda.cod_livro = livro.codigo;
  venda.qtde = qtde;
  venda.valor_venda = livro.preco*qtde;

  t = time(NULL);
  datalocal = localtime(&t);
  sprintf(venda.data_venda,"%d/%d/%d",datalocal->tm_mday,datalocal->tm_mon+1,datalocal->tm_year+1900);
  //sprintf(hora,"%d:%d:%d",datalocal->tm_hour,datalocal->tm_min,datalocal->tm_sec);


  fpvenda = fopen(VENDAS,"ab");
  fwrite(&venda,sizeof(venda),1,fpvenda);
  fclose(fpvenda);

  printf("\nVenda registrada com Sucesso.");

}//Fim efetuarVenda()

*/

/*
void listarVendas(){
  FILE *fpvendas;
  struct reg_venda venda;
  struct reg_cliente cliente;


  //Abrir Arquivo de Vendas
  fpvendas = fopen(VENDAS,"rb");

  //Ler registro por registro e mostrar na tela
  while (fread(&venda,sizeof(venda),1,fpvendas)==1){
    printf("\nCodigo da Venda: %i",venda.codigo);
    cliente = localizarClientePeloCodigo(venda.cod_cliente);
    if (cliente.codigo==-1){ //Cliente NÃO localizado
      strcpy(cliente.nome,"NÃO LOCALIZADO!");
    }
    printf("\nCliente %i - %s",venda.cod_cliente,cliente.nome);
    printf("\nCodigo do Livro: %i",venda.cod_livro);
    printf("\nQuantidade: %i",venda.qtde);
    printf("\nValor da Venda: %5.2f",venda.valor_venda);
    printf("\nData da Venda: %s",venda.data_venda);
    printf("\n----------------------------------------------------------------------------");
  }

  //Fechar Arquivo de Vendas
  fclose(fpvendas);

}//Fim listarVendas()

*/

/*
void listarVendasTXT(){
  FILE *fpvendas, *fprelvendastxt;
  struct reg_venda venda;
  struct reg_cliente cliente;
  char saida[200];


  //Abrir Arquivo de Vendas
  fpvendas = fopen(VENDAS,"rb");
  fprelvendastxt = fopen("RelatorioVendas.txt","w");

  fputs("       * * *  LIVRARIA DO SABER * * * \n",fprelvendastxt);
  fputs("    ---------RELATORIO DE VENDAS-------------\n",fprelvendastxt);
  fputs("Codigo Cliente                                      Livro Valor     Data        \n",fprelvendastxt);


  //Ler registro por registro e gravar no arquivo texto
  while (fread(&venda,sizeof(venda),1,fpvendas)==1){
    //printf("\nCodigo da Venda: %i",venda.codigo);
    cliente = localizarClientePeloCodigo(venda.cod_cliente);
    if (cliente.codigo==-1){ //Cliente NÃO localizado
      strcpy(cliente.nome,"NÃO LOCALIZADO!");
    }
    //printf("\nCliente %i - %s",venda.cod_cliente,cliente.nome);
    //printf("\nCodigo do Livro: %i",venda.cod_livro);
    //printf("\nQuantidade: %i",venda.qtde);
    //printf("\nValor da Venda: %5.2f",venda.valor_venda);
    //printf("\nData da Venda: %s",venda.data_venda);
    //printf("\n----------------------------------------------------------------------------");
    sprintf(saida,"%-6i %-3i-%-40s %-5i R$ %-5.2f %-10s\n",venda.codigo,cliente.codigo,cliente.nome,venda.cod_livro,venda.valor_venda,venda.data_venda);

    //printf("%s",saida);

    fputs(saida,fprelvendastxt);
  }


  //Fechar Arquivo de Vendas
  fclose(fpvendas);
  fclose(fprelvendastxt);

  printf("\nRelatorio de Vendas gravado no Arquivo Texto com Sucesso.");

}//Fim listarVendasTXT()

*/

main(){
  int op;
/*
  Cadastro de Livros, autores, categorias e editoras;
  Listar todos os Livros, Autores, Categorias e Editoras;
  Exclusão de Categorias (Remoção Física do registro);
  Consulta de Livro por palavra-chave no Título;
  Consulta de Autores pela parte inicial do Nome (Mostrar o Nome e o Sobrenome);
  Relatório de Livros por categoria (assunto);
  Relatório de todos os Livros de um Autor;
  Relatório, em arquivo texto, de Livros com estoque abaixo de uma determinada quantidade;
  Relatório de Livro mais caro de uma categoria (pode ser que exista mais do que um);

Observações:
 1.  Tanto nas consultas quanto nos relatórios, mostrar todos os dados dos Livros,
  incluindo nome dos autores, nome da categoria e nome da editora;
 2.  No relatório de Livros com estoque abaixo de uma determinada quantidade,
  o operador deverá digitar a quantidade e o sistema deve mostrar todos os
  livros com quantidade em estoque igual ou inferior a essa quantidade.
  Entretanto, ao invés de listar na tela, este relatório deve ser impresso
  em um arquivo texto;
*/
  do{

    printf("\n\n    # # #  Livraria do Saber  # # # \n");
    printf("\n 1) Cadastro de Livro");
    printf("\n 11) Cadastro de Autor");
    printf("\n 12) Cadastro de Categoria");
    printf("\n 13) Cadastro de Editora");
    printf("\n 2) Listar Todos os Livros");
    printf("\n 21) Listar Todos os Autores");
    printf("\n 22) Listar Todos as Categorias");
    printf("\n 23) Listar Todos os Editores");
    printf("\n 3) Excluir Categoria");
    printf("\n 4) Consulta de Livro por palavra-chave no Titulo");
    printf("\n 5) Consulta de Autores pela parte inicial do Nome (Mostrar o Nome e o Sobrenome)");
    printf("\n 6) Relatorio de Livros por categoria (assunto)");
    printf("\n 7) Relatorio de todos os Livros de um Autor)");
    printf("\n 8) Relatorio, em arquivo texto, de Livros com estoque abaixo de uma determinada quantidade");
    printf("\n 9) Relatorio de Livro mais caro de uma categoria (pode ser que exista mais do que um)");
    printf("\n 0) Sair");
    printf("\n\n opcao-> ");
    fflush(stdin); scanf("%i",&op);

    switch(op){
        case 1:
            CadastrarLivro();//feito
            break;
        case 11:
            CadastrarAutor();//feito
            break;
        case 12:
            CadastrarCategoria();//feito
            break;
        case 13:
            CadastrarEditora();//feito
            break;
        case 2:
            //ListarTodosLivros();
            break;
        case 21:
            //ListarTodosAutores();
            break;
        case 22:
            //ListarTodasCategorias();
            break;
        case 23:
           // ListarTodosEditores();
            break;
        case 3:
           // ExcluirCategoria();
            break;
        case 4:
           // ConsultarLivroPalavraChaveNoTitulo();
            break;
        case 5:
         //   ConsultarAutorParteInicialNome();
            break;
        case 6:
         //   RelatorioLivroCategoria();
            break;
        case 7:
         //   RelatorioTodosLivrosAutor();
            break;
        case 8:
          //  GeraRelatorioArquivoTextoLivrosEstoqueAbaixoDeterminadaQuantidade();
            break;
        case 9:
           // RetornaRelatorioLivrosMaisCarosDaCategoria();
            break;

    }

  }while(op!=0);


}//Fim main()
