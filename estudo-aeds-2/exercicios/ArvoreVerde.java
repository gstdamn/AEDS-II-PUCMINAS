import java.util.*;
class Node
{
    int elemento;
    Node esq, dir;

    public Node(int x){
        this.elemento = x;
        this.esq = null;
        this.dir = null;
    }
}
class Arvore
{
    Node raiz;

    public Arvore(){
        raiz = null;
    }

    public void inserir(int x){
        Node tmp = new Node(x);

        if(raiz == null){
            raiz = tmp;
            return;
        }

        Node pai = null;
        Node atual = raiz;

        while(atual != null){
            if(atual.elemento > x){
                pai = atual;
                atual = atual.esq;
            }else{
                pai = atual;
                atual = atual.dir;
            }
        }

        if(pai.elemento > x)
            pai.esq = tmp;
        else
            pai.dir = tmp;
    }
    public void pesquisar(int y){
        if(raiz == null){
           System.out.println("N");
            return;
        }

        Node atual = raiz;

        while(atual != null &&  atual.elemento != y){
            if(atual.elemento > y){
                System.out.print(atual.elemento + " ");
                atual = atual.esq;
            }
            else{
                System.out.print(atual.elemento + " ");
                atual = atual.dir;
            }
        }
        if(atual == null)
            System.out.println("N");
        else
            System.out.println(atual.elemento + " S");
    }

    public void caminharPre(Node i){
        if(i != null){
            System.out.print(i.elemento + " ");
            caminharPre(i.esq);
            caminharPre(i.dir);
        }
    }
    public void caminharPos(Node i){
        if(i != null){
            caminharPos(i.esq);
            caminharPos(i.dir);
            System.out.print(i.elemento + " ");
        }
    }
    public void caminharOrdem(Node i){
        if(i != null){
            caminharOrdem(i.esq);
            System.out.print(i.elemento + " ");
            caminharOrdem(i.dir);
        }
     }
}

public class ArvoreVerde
{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        Arvore arvore = new Arvore();
        String comando;
        int valor;

        while(sc.hasNext()){
            comando = sc.next();
            if(comando.compareTo("I") == 0){
                valor = sc.nextInt();
                arvore.inserir(valor);
            }else if(comando.compareTo("P") == 0){
                valor = sc.nextInt();
                arvore.pesquisar(valor);
            }else if(comando.compareTo("PRE") == 0){
                if(arvore.raiz == null)
                    System.out.println("V");
                else{
                    arvore.caminharPre(arvore.raiz);
                    System.out.println();
                }
            }else if(comando.compareTo("POS") == 0){
                if(arvore.raiz == null)
                    System.out.println("V");
                else{
                    arvore.caminharPos(arvore.raiz);
                    System.out.println();
                }
            }else if(comando.compareTo("EM") == 0){
                if(arvore.raiz == null)
                    System.out.println("V");
                else{
                    arvore.caminharOrdem(arvore.raiz);
                    System.out.println();
                }
            }
        }
        sc.close();
    }
}
