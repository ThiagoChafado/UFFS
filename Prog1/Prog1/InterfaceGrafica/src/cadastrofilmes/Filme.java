package cadastrofilmes;
    

public class Filme {
    private String titulo;
    private String tituloOriginal;
    private String sinopse;

    public Filme(String titulo, String tituloOriginal, String sinopse) {
        this.titulo = titulo;
        this.tituloOriginal = tituloOriginal;
        this.sinopse = sinopse;
    }

    public String getTitulo() {
        return titulo;
    }

    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }

    public String getTituloOriginal() {
        return tituloOriginal;
    }

    public void setTituloOriginal(String tituloOriginal) {
        this.tituloOriginal = tituloOriginal;
    }

    public String getSinopse() {
        return sinopse;
    }

    public void setSinopse(String sinopse) {
        this.sinopse = sinopse;
    }

    @Override
    public String toString() {
        return "Filme{" + "titulo=" + titulo + ", tituloOriginal=" + tituloOriginal + ", sinopse=" + sinopse + '}';
    }
    
    
}
