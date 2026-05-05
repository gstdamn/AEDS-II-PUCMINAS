#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

int movimentacoes = 0;
int comparacoes = 0;

typedef struct Data{
  int ano;
  int mes;
  int dia;
}Data;

//construtor da struct data
Data *criar_data(int ano, int mes, int dia)
{
  Data *data = (Data *)malloc(sizeof(Data));
  if(data != NULL){
    data->ano = ano;
    data->mes = mes;
    data->dia = dia;
  }
  return data; 
}

int get_data_dia(Data *d)
{
  return d->dia;
}
int get_data_mes(Data *d)
{
  return d->mes;
}
int get_data_ano(Data *d)
{
  return d->ano;
}
void set_data_dia(Data *d, int dia)
{
  d->dia = dia;
}
void set_data_mes(Data *d, int mes)
{
  d->mes = mes;
}
void set_data_ano(Data *d, int ano)
{
  d->ano = ano;
}

Data parse_data(char *s)
{
  Data novaData;
  sscanf(s, "%d-%d-%d", &novaData.ano, &novaData.mes, &novaData.dia);

  return novaData;
}
void formatar_data(Data *d, char *s)
{
  sprintf(s, "%02d/%02d/%04d" , d->dia, d->mes, d->ano);
}

typedef struct Hora{
  int hora;
  int minuto;
}Hora;

// construtor da struct hora
Hora *criar_hora(int hora, int minuto)
{
  Hora *horaCriada = (Hora *)malloc(sizeof(Hora));
  if(horaCriada != NULL){
    horaCriada->hora = hora;
    horaCriada->minuto = minuto;
  }
  return horaCriada;
}
int get_hora(Hora *h)
{
  return h->hora;
}
int get_minuto(Hora *h)
{
  return h->minuto;
}
void set_hora(Hora *h, int hora)
{
  h->hora = hora;
}
void set_minuto(Hora *h, int minuto)
{
  h->minuto = minuto;
}

Hora parse_hora(char *s)
{
  Hora novaHora;
  sscanf(s, "%d:%d", &novaHora.hora, &novaHora.minuto);

  return novaHora;
}
void formatar_hora(Hora *h, char *s)
{
  sprintf(s, "%02d:%02d", h->hora, h->minuto);
}

typedef struct Restaurante{
  int id;
  char *nome;
  char *cidade;
  int capacidade;
  double avaliacao;
  int n_tipos_cozinha;
  char **tipos_cozinha;
  int faixa_preco;
  Hora horario_abertura;
  Hora horario_fechamento;
  Data data_abertura;
  int  aberto;
  
}Restaurante;

// construtor da struct restaurante
Restaurante *criar_restaurante(int id, char *nome, char *cidade, int capacidade, double avaliacao, int n_tipos_cozinha, char **tipos_cozinha, int faixa_preco, Hora horario_abertura, Hora horario_fechamento, Data data_abertura, int aberto)
{
  Restaurante *novoRestaurante = (Restaurante *)malloc(sizeof(Restaurante));
  if(novoRestaurante != NULL){
    novoRestaurante->id = id;
    novoRestaurante->nome = nome;
    novoRestaurante->cidade = cidade;
    novoRestaurante-> capacidade = capacidade;
    novoRestaurante->avaliacao = avaliacao;
    novoRestaurante->n_tipos_cozinha = n_tipos_cozinha;
    novoRestaurante->tipos_cozinha = tipos_cozinha;
    novoRestaurante->faixa_preco = faixa_preco;
    novoRestaurante->horario_abertura = horario_abertura;
    novoRestaurante->horario_fechamento = horario_fechamento;
    novoRestaurante->data_abertura = data_abertura;
    novoRestaurante->aberto = aberto;
  }
  return novoRestaurante;
}
int get_id(Restaurante *r)
{
  return r->id;
}
void set_id(Restaurante *r, int id)
{
  r->id = id;
}

char *get_nome(Restaurante *r)
{
  return r->nome;
}
void set_nome(Restaurante *r, char *nome)
{
  r->nome = nome;
}

char *get_cidade(Restaurante *r)
{
  return r->cidade;
}
void set_cidade(Restaurante *r, char *cidade)
{
  r->cidade = cidade;
}
int get_capacidade(Restaurante *r)
{
  return r->capacidade;
}
void set_capacidade(Restaurante *r, int capacidade)
{
  r->capacidade = capacidade;
}
double get_avaliacao(Restaurante *r)
{
  return r->avaliacao;
}
void set_avaliacao(Restaurante *r, double avaliacao)
{
  r->avaliacao = avaliacao;
}
int get_n_tipos_cozinha(Restaurante *r)
{
  return r->n_tipos_cozinha;
}
void set_n_tipos_cozinha(Restaurante *r , int n_tipos_cozinha)
{
  r->n_tipos_cozinha = n_tipos_cozinha;
}
char **get_tipos_cozinha(Restaurante *r)
{
  return r->tipos_cozinha;
}
void set_tipos_cozinha(Restaurante *r, char **tipos_cozinha)
{
  r->tipos_cozinha = tipos_cozinha;
}
int get_faixa_preco(Restaurante *r)
{
  return r->faixa_preco;
}
void set_faixa_preco(Restaurante *r , int faixa_preco)
{
  r->faixa_preco = faixa_preco;
}
Hora get_horario_abertura(Restaurante *r)
{
  return r->horario_abertura; 
}
void set_horario_abertura(Restaurante *r , Hora horario_abertura)
{
  r->horario_abertura = horario_abertura;
}
Hora get_horario_fechamento(Restaurante *r)
{
  return r->horario_fechamento;
}
void set_horario_fechamento(Restaurante *r, Hora horario_fechamento)
{
  r->horario_fechamento = horario_fechamento;
}
Data get_data_abertura(Restaurante *r)
{
  return r->data_abertura;
}
void set_data_abertura(Restaurante *r, Data data_abertura)
{
  r->data_abertura = data_abertura;
}
int get_aberto(Restaurante *r)
{
  return r->aberto;
}
void set_aberto(Restaurante *r, int aberto)
{
  r->aberto = aberto;
}

Restaurante *parse_restaurante(char *s)
{
  Restaurante *newRestaurante = (Restaurante *)malloc(sizeof(Restaurante));


  newRestaurante->nome = (char *)malloc(100 * sizeof(char));
  newRestaurante->cidade = (char *)malloc(100 * sizeof(char));

// criei auxiliares para ser mais facil na hora de alocar corretamente cada atributo
  char tmp_tipos_cozinha[150];
  char *tmp_horario_abertura = (char *)malloc(50 * sizeof(char));
  char *tmp_horario_fechamento = (char *)malloc(50 * sizeof(char));
  char *tmp_data_abertura = (char *)malloc(50 * sizeof(char));
  char *tmp_faixa_preco = (char *)malloc(20 * sizeof(char));
  char tmp_horarios[30];
  char tmp_aberto[10];

  sscanf(s, "%d,%[^,],%[^,],%d,%lf,%[^,],%[^,],%[^,],%[^,],%s", &newRestaurante->id, newRestaurante->nome, newRestaurante->cidade, &newRestaurante->capacidade, &newRestaurante->avaliacao,
         tmp_tipos_cozinha, tmp_faixa_preco, tmp_horarios, tmp_data_abertura, tmp_aberto);


  sscanf(tmp_horarios, "%[^-]-%[^,]", tmp_horario_abertura, tmp_horario_fechamento);

  newRestaurante->n_tipos_cozinha = 1;
  for(int i =0; tmp_tipos_cozinha[i] != '\0'; i++){
    if(tmp_tipos_cozinha[i] == ';')
      newRestaurante->n_tipos_cozinha += 1;
  }
  newRestaurante->tipos_cozinha = (char **)malloc(newRestaurante->n_tipos_cozinha * sizeof(char *));
  char *ptr = tmp_tipos_cozinha;
  for(int i = 0; i < newRestaurante->n_tipos_cozinha; i++){
    int tamanho_auxiliar = 0;
    while(ptr[tamanho_auxiliar] != ';' && ptr[tamanho_auxiliar] != '\0'){
      tamanho_auxiliar++;
    }
    newRestaurante->tipos_cozinha[i] = (char *)malloc((tamanho_auxiliar + 1) * sizeof(char));
        for(int j = 0; j < tamanho_auxiliar; j++) {
            newRestaurante->tipos_cozinha[i][j] = ptr[j];
        }
        newRestaurante->tipos_cozinha[i][tamanho_auxiliar] = '\0';

        ptr += tamanho_auxiliar;
        if(*ptr == ';')
           ptr++;
    }

  newRestaurante->faixa_preco = 0;
  for(int i = 0; tmp_faixa_preco[i] != '\0'; i++){
    newRestaurante->faixa_preco += 1;
  }
  if(strcmp(tmp_aberto, "true") == 0){
    newRestaurante->aberto = 1;
  }else{
    newRestaurante->aberto = 0;
  }
  Hora horario_abertura_auxiliar = parse_hora(tmp_horario_abertura);
  Hora horario_fechamento_auxiliar = parse_hora(tmp_horario_fechamento);
  Data data_abertura_auxiliar = parse_data(tmp_data_abertura);

  newRestaurante->horario_abertura = horario_abertura_auxiliar;
  newRestaurante->horario_fechamento = horario_fechamento_auxiliar;
  newRestaurante->data_abertura = data_abertura_auxiliar;

  free(tmp_horario_abertura);
  free(tmp_horario_fechamento);
  free(tmp_data_abertura);
  free(tmp_faixa_preco);

  return newRestaurante;
}
void formatar_restaurante(Restaurante *r , char *s)
{
  char tmp_faixa_preco[5];
  char tmp_tipos_cozinha[100];
  char horario_abertura_auxiliar[10];
  char horario_fechamento_auxiliar[10];
  char data_abertura_auxiliar[20];

  formatar_hora(&r->horario_abertura, horario_abertura_auxiliar);
  formatar_hora(&r->horario_fechamento, horario_fechamento_auxiliar);
  formatar_data(&r->data_abertura, data_abertura_auxiliar);

  int posicao = 0;
    for(int i = 0; i < r->n_tipos_cozinha; i++) {
        for(int j = 0; r->tipos_cozinha[i][j] != '\0'; j++) {
            tmp_tipos_cozinha[posicao++] = r->tipos_cozinha[i][j];
        }
        if(i < r->n_tipos_cozinha - 1) {
            tmp_tipos_cozinha[posicao++] = ',';
        }
    }
  tmp_tipos_cozinha[posicao] = '\0';
  
  for(int i = 0; i < r->faixa_preco; i++){
    tmp_faixa_preco[i] = '$';
  }
  tmp_faixa_preco[r->faixa_preco] = '\0';
  char *aberto_auxiliar = (r->aberto > 0) ? "true" : "false";
  sprintf(s, "[%d ## %s ## %s ## %d ## %.1lf ## [%s] ## %s ## %s-%s ## %s ## %s]", r->id, r->nome, r->cidade, r->capacidade, r->avaliacao, tmp_tipos_cozinha, tmp_faixa_preco,
         horario_abertura_auxiliar, horario_fechamento_auxiliar, data_abertura_auxiliar, aberto_auxiliar);
}
typedef struct Colecao_Restaurantes{
  int tamanho;
  Restaurante **restaurantes;
}Colecao_Restaurantes;

void ler_csv_colecao(Colecao_Restaurantes *c, char *path )
{
  FILE *csv;
  csv = fopen(path , "r");

  if(csv == NULL){
    printf("Erro ao tentar abrir o arquivo\n");
  }
  char entrada[300];
  c->tamanho = 0;
  while(fgets(entrada, 300, csv)){
    c->tamanho++;
  }
  fclose(csv);
  
  c->restaurantes = (Restaurante **)malloc(c->tamanho * sizeof(Restaurante *));
  csv = fopen(path, "r");
  fgets(entrada, 300, csv); 
  for(int i =0; i < c->tamanho; i++){
    fgets(entrada, 300, csv);
    c->restaurantes[i] = parse_restaurante(entrada);
  }
  fclose(csv);  
}

Colecao_Restaurantes *ler_csv()
{
  Colecao_Restaurantes *c = (Colecao_Restaurantes *)malloc(sizeof(Colecao_Restaurantes));
  char *path = "/home/gst/Downloads/restaurantes.csv";
  //char *path = "/tmp/restaurantes.csv";

  ler_csv_colecao(c , path);

  return c;
}
Restaurante *buscaId(Colecao_Restaurantes *c, int id)
{
  for(int i = 0; i < c->tamanho; i++){
    if(get_id(c->restaurantes[i]) == id)
      return c->restaurantes[i];
  }
  return NULL;
}
typedef struct Celula{
    Restaurante *restaurante;
    struct Celula *prox;
}Celula;
bool isFim(int id) // função para ver o fim do arquivo e deixar o codigo mais limpo
{
  return (id <  0) ? true : false;
}
Celula *criar_lista(){ // funcao pra criar lista
    Celula *primeiro = (Celula *)malloc(sizeof(Celula));
    primeiro->prox = NULL;
    primeiro->restaurante = NULL;

    return primeiro;
}
void inserir(Celula *c, Restaurante *r){ // funçao para inserir os nomes na lista, todas no inicio
    Celula *tmp = (Celula *)malloc(sizeof(Celula));
    tmp->restaurante = r;
    tmp->prox = c->prox;
    c->prox = tmp;
}
void ordenacao_nome(Celula *c){ // funcao para ordernar pelos nomes
    Celula *i;
    for(i = c->prox; i != NULL; i = i->prox){
        Celula *menor = i;
        comparacoes += 1; // incremento nas comparacoes 
        for(Celula *j = i->prox; j != NULL; j = j->prox){
            if(strcmp(j->restaurante->nome, menor->restaurante->nome) < 0)
                menor = j;
        }
        Restaurante *tmp = i->restaurante; // ao inves de usar uma funcao com metodo swap optei por colocar dentro da funcao de uma vez
        i->restaurante = menor->restaurante;
        menor->restaurante = tmp;

        movimentacoes += 3; // incremento nas movimentacoes 
    }
}
void mostrar(Celula *c){ // funcao para mostrar os restaurantes
    Celula *i;
    for(i = c->prox; i != NULL; i = i->prox){
       char buffer[501];
       formatar_restaurante(i->restaurante, buffer);
       printf("%s\n" , buffer);
    }
}
int main()
{
  Colecao_Restaurantes *colecao = ler_csv();
  int id;
    scanf("%d", &id);
  
  Celula *c = criar_lista();
  while(!isFim(id)){
    Restaurante *r = buscaId(colecao, id);
    if(r != NULL)
      inserir(c , r);
    scanf("%d", &id);
  }
  clock_t inicio = clock();
  ordenacao_nome(c);
  mostrar(c);
  clock_t fim = clock();
  double tempoExecucao = (fim - inicio) / 1000.0;

  FILE *log = fopen("905087_selecao_flexivel.txt" , "w");
  fprintf(log, "905087\t%d\t%d\t%lf", movimentacoes, comparacoes, tempoExecucao);
  fclose(log);
  free(colecao);
}
