import java.util.*;

class Celula
{
    public int elemento;    
    public Celula inf, sup, esq, dir;

    public Celula(){
        this(0);
    }

    public Celula(int elemento){
        this(elemento, null, null, null, null);
    }

  /*  public Celula(int elemento, Celula inf, Celula sup, Celula esq, Celula dir){
        this.elemento = elemento;
        this.inf = inf;
        this.sup = sup;
        this.esq = esq;
        this.dir = dir;
    } */
}

class Matriz
{
    private Celula inicio;
    private int linhas, colunas;
    Scanner scanner = new Scanner(System.in);
    public Matriz(int linhas, int coluna){
        Matriz matriz = new Matriz();
        matriz.linhas = linhas;
        matriz.coluna = coluna;
    }
    
    public inserir(int elemento){
        if(inicio == null){
            inicio.elemento = elemento;
            inicio.sup = null;
            inicio.inf = null;
            inicio.dir = null;
            inicio.esq = null;
        }else{
           Celula i = m.inicio;

           for(int i = 0; i < m.linhas; i++){
             Celula novo = new Celula(elemento);
             int linhaAnterior = m.linhas - 1;
             Celula iSup = m.linhaAnterior.inicio;

             for(int j = 0; j < m.colubas; j++){
                if(i.dir != null){
                    i.dir = novo;
                    novo.esq = i;
                    novo.dir = null;
                    i = novo;
                }
                if(linhaAnterior >= 0){
                   novo.sup = iSup;
                   iSup.inf = novo;
                   iSup = iSup.dir;
                }
             }
           }
        }
     }
}

public class Nine
{
    public static void main(String[] args){
        Scanner sc = new Scanner(Sytem.in);

        int conjutoMatrizes = sc.nextInt();
        int linhas, colunas;

        for(int i = 0; i < conjutoMatrizes; i++){
           linhas = sc.nextInt();
           colunas = sc.nextInt();
           Matriz m = new Matriz(linhas, colunas);

           for(int j = 0; j < m.linahs * m.colunas ; j++){
            int elemento = sc.nextInt();
            m.inserir(elemento);
           }
        }
    }
}
