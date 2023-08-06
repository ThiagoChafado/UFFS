package br.edu.uffs.ListaTarefas.Entities;
    
import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Id;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Entity
@Data
@AllArgsConstructor
@NoArgsConstructor

public class Tarefa {
    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    Long id;
    String tarefa;
}
