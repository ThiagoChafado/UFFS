package lambda;

import java.util.function.BiFunction;
public class Lambda {
    
    public static double efetuarCalculo(BiFunction<Double,Double,Double> f, double a, double b){
 
        //return f.calcular(a,b);
        return f.apply(a,b);
    }
    
    public static void main(String[] args) {
        
        
        
        System.out.println("Resultado= "+ efetuarCalculo((a,b)->a+b,10,15));
        
       /* Calculavel c = (x,y)->x*2+y*2;
        
        System.out.println("Resultado 2= "+ c.calcular(2,3));
        */
       
       System.out.println("Resultado= "+ efetuarCalculo(Math::max,10,15));
        
       
    }
    
}
