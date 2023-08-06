package testes;



public class ItemPedido {
    private Produto prod;
    private int quantidade;
    
    //Sets e gets

    public Produto getProd() {
        return prod;
    }

    public void setProd(Produto prod) {
        this.prod = prod;
    }

    public int getQuantidade() {
        return quantidade;
    }

    public void setQuantidade(int quantidade) {
        this.quantidade = quantidade;
    }
    
    //Construtor

    public ItemPedido(Produto prod, int quantidade) {
        this.prod = prod;
        this.quantidade = quantidade;
    }
    
}
