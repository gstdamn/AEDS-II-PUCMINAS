import java.util.*;
import java.io.*;

class Data {
  private int ano;
  private int mes;
  private int dia;

//construtor da classe data
  public Data(int ano, int mes, int dia) {
    this.ano = ano;
    this.mes = mes;
    this.dia = dia;
  }

  public int getDia() {
    return this.dia;
  }

  public int getMes() {
    return this.mes;
  }

  public int getAno() {
    return this.ano;
  }

  public void setDia(int dia) {
    this.dia = dia;
  }

  public void setMes(int mes) {
    this.mes = mes;
  }

  public void setAno(int ano) {
    this.ano = ano;
  }

  public static Data parseData(String s) {
    Scanner sc = new Scanner(s);

    sc.useDelimiter("-");

    int ano = sc.nextInt();
    int mes = sc.nextInt();
    int dia = sc.nextInt();

    sc.close();
    return new Data(ano, mes, dia);
  }

  public String formatar() {
    return String.format("%02d/%02d/%04d", dia, mes, ano);
  }
}
class Hora {
  private int hora;
  private int minuto;

//construtor da classe hora
  public Hora(int hora, int minuto) {
    this.hora = hora;
    this.minuto = minuto;
  }

  public int getHora() {
    return this.hora;
  }

  public int getMinuto() {
    return this.minuto;
  }

  public void setHora(int hora) {
    this.hora = hora;
  }
  public void setMinuto(int minuto){
    this.minuto = minuto;
  }

  public static Hora parseHora(String s) {
    Scanner sc = new Scanner(s);
    sc.useDelimiter(":");

    int hora = sc.nextInt();
    int minuto = sc.nextInt();

    sc.close();
    return new Hora(hora, minuto);
  }

  public String formatar() {
    return String.format("%02d:%02d", hora, minuto);

  }
}
class Restaurante
{
  private int id;
  private String nome;
  private String cidade;
  private int capacidade;
  private double avaliacao;
  private String[] tipo_cozinha = new String[2];
  private String faixa_preco;
  private Hora horario_abertura;
  private Hora horario_fechamento;
  private Data data_abertura;
  private boolean aberto;

//construtor da classe restaurante
  public Restaurante(int id, String nome, String cidade, int capacidade, double avaliacao, String[] tipo_cozinha, String faixa_preco, Hora horario_abertura,Hora horario_fechamento,  Data data_abertura, boolean aberto){
    this.id = id;
    this.nome = nome;
    this.cidade = cidade;
    this.capacidade = capacidade;
    this.avaliacao = avaliacao;
    this.tipo_cozinha = tipo_cozinha;
    this.faixa_preco = faixa_preco;
    this.horario_abertura = horario_abertura;
    this.horario_fechamento = horario_fechamento;
    this.data_abertura = data_abertura;
    this.aberto = aberto;
  }
  public int getId(){
    return this.id;
  }
  public void setId(int id){
    this.id = id;
  }
  public String getNome(){
    return this.nome;
  }
  public void setNome(String nome){
    this.nome = nome;
  }
  public String getCidade(){
    return this.cidade;
  }
  public void setCidade(String cidade){
    this.cidade = cidade;
  }
  public int getCapacidade(){
    return this.capacidade;
  }
  public void setCapacidade(int capacidade){
    this.capacidade = capacidade;
  }
  public double getAvaliacao(){
    return this.avaliacao;
  }
  public void setAvaliacao(double avaliacao){
    this.avaliacao = avaliacao;
  }
  public String getTipo_cozinha(){
    return this.tipo_cozinha[0];
  }
  public void setTipo_cozinha(String[] tipo_cozinha){
    for(int i = 0; i < 2; i++)
      this.tipo_cozinha[i] = tipo_cozinha[i];
  }
  public String getFaixa_preco(){
    return this.faixa_preco;
  }
  public void setFaixa_preco(String faixa_preco){
    this.faixa_preco = faixa_preco;
  }
  public Hora getHorario_abertura(){
    return this.horario_abertura;
  }
  public void setHorario_abertura(Hora horario_abertura){
    this.horario_abertura = horario_abertura;
  }
  public Hora getHorario_fechamento(){
    return this.horario_fechamento;
  }
  public void setHorario_fechamento(Hora horario_fechamento){
    this.horario_fechamento = horario_fechamento;
  }
  
  public Data getData_abertura(){
    return this.data_abertura;
  }
  public void setData_abertura(Data data_abertura){
    this.data_abertura = data_abertura;
  }
  public boolean getAberto(){
    return this.aberto;
  }
  public void setAberto(boolean aberto){
    this.aberto = aberto;
  }

  public static Restaurante parseRestaurante(String s){
    Scanner sc = new Scanner(s);
    sc.useDelimiter(",");
    sc.useLocale(Locale.US);
    
     int id = sc.nextInt();
     String nome = sc.next();
     String cidade = sc.next();
     int capacidade = sc.nextInt();
     double avaliacao = sc.nextDouble();
     String tipos_cozinha_auxiliar = sc.next();


     Scanner aux = new Scanner(tipos_cozinha_auxiliar);
     aux.useDelimiter(";");
         
     String[] tipo_cozinha = new String[2]; // todos os restaurante possuem 2 tipos de cozinha, de maneira mais simples, coloquei um valor fixo
     tipo_cozinha[0] = aux.next();
     tipo_cozinha[1] = aux.next();

     aux.close();
     
     String faixa_preco = sc.next();

     String horariosAuxiliar = sc.next();
     Scanner auxHorarios = new Scanner(horariosAuxiliar);
     auxHorarios.useDelimiter("-"); // scanner auxiliar para poder ler o horario de abertura e horario de fechamento
     Hora horario_abertura = Hora.parseHora(auxHorarios.next());
     Hora  horario_fechamento = Hora.parseHora(auxHorarios.next());

     auxHorarios.close();
     
     Data data_abertura = Data.parseData(sc.next());
     boolean aberto = sc.nextBoolean();

    sc.close();

    return new Restaurante(id, nome, cidade, capacidade, avaliacao, tipo_cozinha, faixa_preco, horario_abertura, horario_fechamento, data_abertura, aberto);
  }

 public String formatar(){
   String faixaPrecoAuxiliar = "";
   for(int i =0; i < faixa_preco.length(); i++){
     faixaPrecoAuxiliar += "$"; // trocando o simbolo para formatar o faixa preco
   }

     return String.format(Locale.US, "[%d ## %s ## %s ## %d ## %.1f ## [%s,%s] ## %s ## %s-%s ## %s ## %s]" , this.id, this.nome, this.cidade, this.capacidade, this.avaliacao, this.tipo_cozinha[0], this.tipo_cozinha[1], faixaPrecoAuxiliar,
      this.horario_abertura.formatar(), this.horario_fechamento.formatar(), this.data_abertura.formatar(), this.aberto);
    }
    
}
class ColecaoRestaurante
{
  private int tamanho;
  private Restaurante[] restaurantes;

//construtor da classe restaurante
  public ColecaoRestaurante(){
     this.restaurantes = new Restaurante[501];
  }

  public int getTamanho(){
    return this.tamanho;
  }
  public void setTamanho(int tamanho){
    this.tamanho = tamanho;  
  }
  public Restaurante[] getRestaurantes(){
    return this.restaurantes;
  }
  public void  setRestaurantes(Restaurante[] restaurantes){
    this.restaurantes = restaurantes;
  }

  public void lerCsv(String path)
  {
    try{
      Scanner sc = new Scanner(new File(path));
      this.tamanho = 0;

      if(sc.hasNextLine())
        sc.nextLine();
      while(sc.hasNextLine()){
        String entrada = sc.nextLine();
        this.restaurantes[tamanho++] = Restaurante.parseRestaurante(entrada);
      }
    }catch(FileNotFoundException e){
      System.out.println("Erro ao procurar o arquivo");
      e.printStackTrace();
    }
  }

  public static ColecaoRestaurante lerCsv(){
    ColecaoRestaurante colecao = new ColecaoRestaurante();
    //colecao.lerCsv("/home/gst/Downloads/restaurantes.csv");
    colecao.lerCsv("/tmp/restaurantes.csv");
    return colecao;
  }
  public Restaurante buscaId(int id){
    for(int i = 0; i < tamanho; i++){
      if(restaurantes[i].getId() == id )
        return restaurantes[i];
    }
    return null;
  }
  public static void swap(Restaurante[] r, int i, int j){
    Restaurante tmp = r[i];
    r[i] = r[j];
    r[j] = tmp;
  }
  public int compareTo(Restaurante e1, String e2){
    int resp = e1.getNome().compareTo(e2);
    return resp;
  }
  public void selecao(Restaurante[] r, int tam, int k ){
    int  menor;
    for(int  i = 0; i < k; i++){
      menor = i;
      for(int j = i + 1; j < tam; j++){
        if(r[j].getNome().compareTo(r[menor].getNome()) <  0){
          menor = j;
          OrdenacaoParcial.comparacoes += 1;
        }
      }
      if(menor != i){
        ColecaoRestaurante.swap(r, i, menor);
        OrdenacaoParcial.movimentacoes += 3;
      }
    }
  }
  public void mostrar(Restaurante[] r, int tam){
    for(int i = 0; i < tam; i++){
      System.out.println(r[i].formatar());
    }
  }
}    
public class OrdenacaoParcial {
  public static int movimentacoes = 0;
  public static int comparacoes = 0;
  
  public static boolean isFim(String s){ // metodo fim para deixar o codigo mais limpo e legivel
    return(s.compareTo("-1") == 0);
  }
  
  public static void main(String[] args) throws Exception {
    Scanner sc = new Scanner(System.in);

    ColecaoRestaurante colecao = ColecaoRestaurante.lerCsv();
    Restaurante[] entradas = new Restaurante[51];
    String entrada = sc.nextLine();
    

    int tamanho = 0;
    while(!isFim(entrada)){
      int id = Integer.parseInt(entrada);
      Restaurante r = colecao.buscaId(id);
      if(r != null)
        entradas[tamanho++] = r;
      entrada = sc.nextLine();
    }
    
    double inicio = new Date().getTime();
    colecao.selecao(entradas, tamanho, 10);
    colecao.mostrar(entradas, tamanho);
    double fim = new Date().getTime();
    double tempoExecucao = (fim - inicio) / 1000.0;
    
    FileWriter log = new FileWriter("905087_selecao_parcial.txt");
    log.write("905087" + movimentacoes + "\t" + comparacoes + "\t" + tempoExecucao);
    log.close();
    sc.close();
  }
  
}
