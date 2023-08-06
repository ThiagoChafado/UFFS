package trabalhobaralho;


public class Cartas {
    public static final String[] naipesPossiveis = {"Espadas", "Copas", "Paus", "Ouros"};
    public static final String[] valoresPossiveis = {"Ás", "Dois", "Três", "Quatro", "Cinco", "Seis", "Sete", "Oito", "Nove", "Dez", "Dama", "Valete", "Rei"};
    private String naipe;
    private String valor;
    public Cartas(String naipe, String valor){
        try{
            setValor(valor);
            setNaipe(naipe);
        } catch (Exception e){
            System.out.println(e);
        }
    }
    
    public String[] getNaipesPossiveis(){
        return naipesPossiveis;
    }
    
    public String[] getValoresPossiveis(){
        return valoresPossiveis;
    }
    
    public void setValor(String valor){
        int i = 0;
        for(String elem : valoresPossiveis){
            if(elem.equals(valor)){
                this.valor = valor;
                i = 1;
            }
        }
        if(i == 0){
            throw new RuntimeException("Valor de carta inválido!");
        }
    }
    
    public void setNaipe(String naipe){
        int i = 0;
        for(String elem : naipesPossiveis){
            if(elem.equals(naipe)){
                this.naipe = naipe;
                i = 1;
            }
        }
        if(i == 0){
            throw new RuntimeException("Naipe inválida!");
        }
    }
    
    public String getValor(){
        return this.valor;
    }
    
    public String getNaipe(){
        return this.naipe;
    }
}

