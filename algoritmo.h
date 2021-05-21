#ifndef ALGORITMO_H
#define ALGORITMO_H


int get_troca();
int get_comparacao();
unsigned long int contador_trocas ();
unsigned long int contador_comp();
void bubble_sort(int *v, int tam);
void insertion_rec_sort(int *v, int n);
void insertion_sort_bin(int *v, int n);
void shell_sort(int *a, int n);
void selection_sort( int *v, int n);
void cria_heap(int *v, int inicio, int fim);
void heap_sort(int *v, int n); 
void particao_quick_sort(int *v, int esquerda, int direita, int *i, int *j); 
void quick_sort(int *v, int esquerda, int direita);
void merge(int *v, int inicio, int fim, int meio); 
void merge_sort(int *v, int inicio, int fim); 
void radix_sort(int *v, int n);
void bucket_sort(int *v, int tam, int num_bucket);

#endif /* ALGORITMO_H */