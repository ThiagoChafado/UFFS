package testes;


public class Pedido {
       private ItemPedido itens[];
       private double valorTotal;

       //sets
    public ItemPedido[] getItens() {
        return itens;
    }

    public void setItens(ItemPedido[] itens) {
        this.itens = itens;
    }

    public double getValorTotal() {
        return valorTotal;
    }

    public void setValorTotal(double valorTotal) {
        this.valorTotal = valorTotal;
    }
    
     public void adicionarItem(ItemPedido item) {
         for(int i=0;i<itens.length;i++){
             if(itens[i] == null){
                 itens[i] = item;
                 return;
             }
         }System.out.println("Não foi possivel adicionar");
    
    
    
    }
     public double obterTotal(){
         double soma=0;
         for(ItemPedido p : itens){
             p.getQuantidade();
             p.getProd().getValor();
             double valor = p.getQuantidade() * p.getProd().getValor();
             soma +=valor;
             
         }
         return soma;
         
     }
       
       
}
