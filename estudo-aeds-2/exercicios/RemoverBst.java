 public class RemoverBst
{
  public void remover(int x){
    if(raiz == null)
        return;

    No pai = null;
    No atual = raiz;

    while(atual != null && atual.elemento != x){
        if(atual.elemento > x){
            pai = atual;
            atual = atual.esq;
        }else{
            pai = atual;
            atual = atual.dir;
        }
    }

    if(atual.elemento != x)
        return;

    if(atual.dir != null && atual.esq != null){
        No paiSuc = atual;
        No suc = atual.dir;
        while(suc.esq != null){
            paiSuc = suc;
            suc = suc.esq;
        }
        atual.elemento = suc.elemento;
        atual = suc;
        pai = paiSuc;
    }

    No filho = (atual.esq != null) ? atual.esq : atual.dir;

    if(pai == null)
        raiz = filho;
    else if(pai.esq == atual)
        pai.esq = filho;
    else
        pai.dir = filho;
   
   }

}

