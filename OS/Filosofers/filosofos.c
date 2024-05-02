// Resource Hierarchy
//      Another simple solution is achieved by assigning a partial order to the
//    resources(in this case, the forks) and
// making the convention that the resources are requested in that order and returned in the reverse order.Also,
// there should not be two resources out of order used by the same unit of work.

// Let the resources(forks)
// be numbered from 1 to 5, and each worker unit(philosopher)

// always takes the lowest - numbered fork first, and then the highest - numbered fork of the two available.Next,
// the philosopher puts down the fork with the higher number first, then the one with the smaller one.In this case, if four out of five philosophers
// take the lowest numbered fork at the same time,

//   the highest possible numbered fork will remain on the table.Thus, the fifth philosopher will not 
//be able to take a single fork.Moreover, only one philosopher will have access to the highest numbered fork,
//    so he can eat with two forks.When he has finished using the forks, he will first place the higher numbered 
//fork on the table, then the smaller one, thus allowing the other philosopher to pick up the missing fork and start eating.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define NUMFILO 5

pthread_t filosofo[NUMFILO];
sem_t hashi[NUMFILO]; // semáforo para cada hashi
int contador[NUMFILO] = {0};
int contador_total = 0;

// espaços para separar as colunas de impressão
char *space[] = {"", "\t", "\t\t", "\t\t\t", "\t\t\t\t"};

// espera um tempo aleatório entre 0 e n segundos (float)
void espera(int n)
{
     sleep(random() % n);       // pausa entre 0 e n segundos (inteiro)
     usleep(random() % 100000); // pausa entre 0 e 0.1 segundo (float)
}

// filósofo comendo
void come(int f)
{
    printf("%sF%d COMENDO\n", space[f], f);
    contador[f]++;
    contador_total++;
    //espera(1);
}

// filósofo meditando
void medita(int f)
{
    printf("%sF%d meditando\n", space[f], f);
    //espera(1);
}


// pega o hashi
void pega_hashi(int f, int h1, int h2)
{
  printf("%sF%d quer  h%d\n", space[f], f, h1);
  sem_wait(&hashi[h1]);
  printf("%sF%d pegou h%d\n", space[f], f, h1);
  printf("%sF%d quer  h%d\n", space[f], f, h2);
  sem_wait(&hashi[h2]);
  printf("%sF%d pegou h%d\n", space[f], f, h2);
}

// larga o hashi
void larga_hashi(int f, int h1, int h2)
{
  printf("%sF%d larga h%d\n", space[f], f, h2);
  sem_post(&hashi[h2]);
  printf("%sF%d larga h%d\n", space[f], f, h1);
  sem_post(&hashi[h1]);
}
// corpo da thread filósofo

void *threadFilosofo(void *arg)
{
  int contador = 0;
  int i = (long int)arg;
  while (contador < 100)
  {
    medita(i);
    //filosofos pegam hashi menor
    pega_hashi(i, i, (i + 1) % NUMFILO);
    come(i);
    //filosofos largam hashi maior
    larga_hashi(i, (i + 1) % NUMFILO, i);
    contador++;
  }
  pthread_exit(NULL);
}


// programa principal
int main(int argc, char *argv[])
{
    long i, status;

    // para o printf não se confundir com a threads
    setvbuf(stdout, 0, _IONBF, 0);

    // inicializa os hashis
    for (i = 0; i < NUMFILO; i++)
        sem_init(&hashi[i], 0, 1);


    // inicia os filósofos
    for (i = 0; i < NUMFILO; i++)
    {
        status = pthread_create(&filosofo[i], NULL, threadFilosofo, (void *)i);
    }
    for (i = 0; i < NUMFILO; i++)
    {
        // ESPERA TREADS terminarem
        status = pthread_join(filosofo[i], NULL);
        if (status != 0)
        {
            exit(EXIT_FAILURE);
        }
    }

    // print
    for (i = 0; i < NUMFILO; i++)
    {
        printf("Filosofo %ld comeu %d vezes\n", i, contador[i]);
    }
    printf("Total de filosofos que comeram: %d", contador_total);

    // a main encerra aqui
    pthread_exit(NULL);
}
