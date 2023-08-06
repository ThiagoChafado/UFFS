
package trabalhobaralho;

import java.util.*;

public class Baralho {
    private ArrayList<Cartas> cartas = new ArrayList<Cartas>();
    
    public void encheBaralho(){
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 13; j++){
                cartas.add(new Cartas(Cartas.naipesPossiveis[i], Cartas.valoresPossiveis[j]));
            }
        }
    }
    
    @Override
    public String toString(){
        String baralho = "";
        for(int i = 0; i < cartas.size(); i++){
            baralho = baralho + cartas.get(i).getValor() + " de " + cartas.get(i).getNaipe() + "\n";
        }
        return baralho;
    }
    
    public void embaralha(){
        Random random = new Random();
        Cartas temp;
        int posicao;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 52; j++){
                posicao = random.nextInt(cartas.size());
                temp = cartas.get(j);
                cartas.set(j, cartas.get(posicao));
                cartas.set(posicao, temp);
            }
        }
    }
    public void adicionaCarta(Cartas carta){
        int contador = 0;
        if(cartas.size() <= 52){
            for(int i = cartas.size()-1; i>-1; i--){
                if(cartas.get(i).getNaipe().equals(carta.getNaipe())){
                    contador++;
                }
            }
            if(contador >= 13){
                throw new RuntimeException("Limite de cartas dessa naipe já atingido!");
            } else {
                cartas.add(carta);
            }
        } else {
            throw new RuntimeException("Baralho já cheio!");
        }
    }
}
