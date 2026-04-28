import java.util.*;
class Celula
{
  public int elemento;
  public Celula prox;

  public Celula(){
    this(0);
  }
  public Celula(int elemento){
    this.elemento = elemento;
    this.prox = null;
  }
}
public class Fila
{
  private Celula primeiro;
  private Celula ultimo;

  public Fila(){
    primeiro = new Celula();
    ultimo = primeiro;
   }
  public void inserir(int x){
    
    Celula tmp = new Celula(x);
    ultimo.prox = tmp;
    ultimo = tmp; 
  }
  public int remover(){
    int valor;
    if(primeiro == ultimo)
      return -1;

    Celula tmp = primeiro;
    primeiro = primeiro.prox;
    valor = primeiro.elemento;
    tmp.prox = null;
    tmp = null;

    return valor; 
  }
  
  public void mostrar(){
    Celula i;
    if(primeiro == ultimo){
      System.out.println("V");
      return;
    }
    for(i = primeiro.prox; i != null; i = i.prox){
      if(i.prox != null)
        System.out.print(i.elemento + " ");
      else 
        System.out.print(i.elemento);
    }
    System.out.println();
  }
  public void pesquisar(int x){
    Celula i;
    boolean answer = false;
    for(i = primeiro.prox; i != null; i = i.prox){
      if(i.elemento == x){
        answer = true;
      }
    }
    System.out.println(answer  ? "S" : "N");
  }

  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    Fila fila = new Fila();
    String comando;
    int numero;
      
    while(sc.hasNext()){
      comando = sc.next();
      if(comando.charAt(0) == 'E'){
        numero = sc.nextInt();
        fila.inserir(numero);
      }else if(comando.charAt(0) == 'D'){
        System.out.println(fila.remover());
      }else if(comando.charAt(0) == 'M'){
        fila.mostrar();
      }else if(comando.charAt(0) == 'P'){
        numero = sc.nextInt();
        fila.pesquisar(numero);
      }
   }
   sc.close();
  }
}
