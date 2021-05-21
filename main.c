#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "algoritmo.h"


void grava_arq (int *vet, int n, FILE *arq)
{
	for (int i = 0; i < n; i++)
	{
		fprintf (arq,"%d\n", vet[i]);
	}
}

void ler_arq (int *vet, FILE *arq, int n)
{   
	for (int i = 0; i < n; i++)
    {
        fscanf(arq, "%d", &vet[i]);
    }
}

/*
void mostra_resultado (double tempo, char *nome_algoritmo, FILE *arq, int n_elem)
{
	printf("Algoritmo: %s.\n", nome_algoritmo);
	printf("Comparações feitas: %d\n", get_comparacao());
	printf("Trocas realizadas: %d\n", get_troca());
	printf("Tempo de execução: %f\n", tempo);
	
	//para o artigo
	fprintf (arq, "%s |", nome_algoritmo);
	fprintf (arq, " Número de elementos testados: %d |", n_elem);
	fprintf (arq," Comparações: %d |", get_comparacao());
	fprintf (arq," Trocas: %d |", get_troca());
	fprintf (arq," Tempo(ms): %g |", tempo);
	fprintf (arq,"\n");
}
*/

int main(int argc, char **argv) 
{    

    if(argc != 4)
    {
        printf("\nNumero de argumentos invalidos.\n");
        printf("\nExemplo: ordena [algoritmo] n [entrada.txt]");
    }
    else
    {
		//Programa principal:
		
		FILE *arq_entrada;
		arq_entrada = fopen (argv[3], "r");
		int n_elem = atoi(argv[2]);
		
		int vet[n_elem];
		
		ler_arq(vet, arq_entrada, n_elem);
		
		fclose(arq_entrada);
		/*
		FILE *arq_saida_artigo;
		arq_saida_artigo = fopen("artigo.txt", "at");
        */
		FILE *arq_saida;
		arq_saida = fopen("saida.txt", "wt");
        
		//clock_t Ticks[2];
		
		
        if(strcmp(argv[1], "bolha") == 0)
        {
			
			
			//Ticks[0] = clock();
			
			bubble_sort(vet, n_elem);
			
			//Ticks[1] = clock();
			
			//double tempo_final = ((Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC);
			
			//mostra_resultado (/*int comp, int trocas,*/ tempo_final, argv[1], arq_saida_artigo, n_elem);
			
			grava_arq (vet, n_elem, arq_saida);
			
			fclose (arq_saida);
			//fclose (arq_saida_artigo);

		}
        else if (strcmp(argv[1], "insercaoDireta") == 0)
		{
			//Ticks[0] = clock();
			
			insertion_rec_sort(vet, n_elem - 1);
			
			//Ticks[1] = clock();
			
			//double tempo_final = ((Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC);
			
			//mostra_resultado (/*int comp, int trocas,*/ tempo_final, argv[1], arq_saida_artigo, n_elem);
			
			grava_arq (vet, n_elem, arq_saida);
			
			fclose (arq_saida);
			//fclose (arq_saida_artigo);
		}
		else if (strcmp(argv[1], "insercaoBinaria") == 0)
		{
			//Ticks[0] = clock();
			
			insertion_sort_bin(vet, n_elem);
			
			//Ticks[1] = clock();
			
			//double tempo_final = ((Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC);
			
			//mostra_resultado (/*int comp, int trocas,*/ tempo_final, argv[1], arq_saida_artigo, n_elem);
			
			grava_arq (vet, n_elem, arq_saida);
			
			fclose (arq_saida);
			//fclose (arq_saida_artigo);
		}
		else if (strcmp(argv[1], "shellsort") == 0)
		{
			//Ticks[0] = clock();
			
			shell_sort(vet, n_elem);
			
			//Ticks[1] = clock();
			
			//double tempo_final = ((Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC);
			
			//mostra_resultado (/*int comp, int trocas,*/ tempo_final, argv[1], arq_saida_artigo, n_elem);
			
			grava_arq (vet, n_elem, arq_saida);
			
			fclose (arq_saida);
			//fclose (arq_saida_artigo);
		}
		else if (strcmp(argv[1], "selecaoDireta") == 0)
		{
			//Ticks[0] = clock();
			
			selection_sort(vet, n_elem);
			
			//Ticks[1] = clock();
			
			//double tempo_final = ((Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC);
			
			//mostra_resultado (/*int comp, int trocas,*/ tempo_final, argv[1], arq_saida_artigo, n_elem);
			
			grava_arq (vet, n_elem, arq_saida);
			
			fclose (arq_saida);
			//fclose (arq_saida_artigo);
		}
		else if (strcmp(argv[1], "heapsort") == 0)
		{
			//Ticks[0] = clock();
			
			heap_sort(vet, n_elem);
			
			//Ticks[1] = clock();
			
			//double tempo_final = ((Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC);
			
			//mostra_resultado (/*int comp, int trocas,*/ tempo_final, argv[1], arq_saida_artigo, n_elem);
			
			grava_arq (vet, n_elem, arq_saida);
			
			fclose (arq_saida);
			//fclose (arq_saida_artigo);
		}
		else if (strcmp(argv[1], "quicksort") == 0)
		{
			//Ticks[0] = clock();
			
			quick_sort(vet, 0, n_elem - 1);
			
			//Ticks[1] = clock();
			
			//double tempo_final = ((Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC);
			
			//mostra_resultado (tempo_final, argv[1], arq_saida_artigo, n_elem);
			
			grava_arq (vet, n_elem, arq_saida);
			
			fclose (arq_saida);
			//fclose (arq_saida_artigo);
		}
		else if (strcmp(argv[1], "mergesort") == 0)
		{
			//Ticks[0] = clock();
			
			merge_sort(vet, 0, n_elem - 1);
			
			//Ticks[1] = clock();
			
			//double tempo_final = ((Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC);
			
			//mostra_resultado (/*int comp, int trocas,*/ tempo_final, argv[1], arq_saida_artigo, n_elem);
			
			grava_arq (vet, n_elem, arq_saida);
			
			fclose (arq_saida);
			//fclose (arq_saida_artigo);
		}
		else if (strcmp(argv[1], "radixsort") == 0)
		{
			//Ticks[0] = clock();
			
			radix_sort(vet, n_elem);
			
			//Ticks[1] = clock();
			
			//double tempo_final = ((Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC);
			
			//mostra_resultado (tempo_final, argv[1], arq_saida_artigo, n_elem);
			
			grava_arq (vet, n_elem, arq_saida);
			
			fclose (arq_saida);
			//fclose (arq_saida_artigo);
		}
		else if (strcmp(argv[1], "bucketsort") == 0)
		{
			int n_elem2 = n_elem;
			
			//Ticks[0] = clock();
			
			bucket_sort(vet, n_elem, n_elem2);
			
			//Ticks[1] = clock();
			
			//double tempo_final = ((Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC);
			
			//mostra_resultado (/*int comp, int trocas,*/ tempo_final, argv[1], arq_saida_artigo, n_elem);
			
			grava_arq (vet, n_elem, arq_saida);
			
			fclose (arq_saida);
			//fclose (arq_saida_artigo);
		}
        else
        {
            printf("nome do parametro %s é invalido.\n", argv[1]);
        }
    }
    return 0;
}