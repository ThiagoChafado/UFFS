

package br.edu.uffs.ListaTarefas.Repositories;

import br.edu.uffs.ListaTarefas.Entities.Tarefa;
import org.springframework.data.jpa.repository.JpaRepository;


public interface TarefaRepository  extends JpaRepository<Tarefa, Long>{
    
    
}
