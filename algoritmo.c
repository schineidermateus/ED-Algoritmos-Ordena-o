#include <stdio.h>
#include <stdlib.h>
#include <string.h>
unsigned long int contador_trocas()
{
	static unsigned long int contador_t = -1;
	contador_t++;
	//printf ("troca: %ld ", contador_t);
	return contador_t;
}

unsigned long int contador_comp()
{
	static unsigned long int contador_c = -1;
	contador_c++;
	//printf ("comparação: %ld ", contador_c);
	return contador_c;
}

int get_troca()
{
	return contador_trocas();
}

int get_comparacao()
{
	return contador_comp();
}

//bubble_sort
void bubble_sort(int *v, int n_max)
{
    int i, j, aux;
    for(i = n_max - 1; i >= 1; i--)
    {
        for(j = 0; j < i; j++)
        {
			contador_comp();
            if(v[j] > v[j + 1])
            {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
				contador_trocas();
            }
        }
    }
}

//inserção_direta
void insertion_rec_sort(int *v, int n)
{
    int  i, aux;
	
    if(n > 1)
	{	
		insertion_rec_sort(v, n - 1);
		contador_comp();
	}
		
	aux = v[n];
	i = n - 1;
    
	while(i >= 0 && v[i] > aux)
	{
        v[i + 1] = v[i];
        i = i - 1;
        v[i + 1] = aux;
		contador_trocas();
    }
}

//inserção_binária
void insertion_sort_bin(int *v, int n)
{
    int i, j, meio, esquerda, direita, aux;

    for (i = 1; i < n; i++)
    {	
		aux = v[i];
        esquerda = 0;
        direita = i;
		
		contador_comp();
		
        while (esquerda < direita)
        {
            meio = (esquerda + direita) / 2;
            
			if (v[meio] <= aux)
			{
                esquerda = meio + 1;
			}
			else
			{
                direita = meio;
			}
		}
        for (j = i; j > esquerda; j--) 
		{
            v[j] = v[j-1];
			contador_trocas();
        }
        v[direita] = aux;
    }
}

//shell_sort
void shell_sort(int *v, int n)
{
    int aux, i, j, h = 1;
    
	
    while (h < n) 
	{
        h = 3 * h + 1;
		//contador_comp();
    }

    while (h > 1)
    {
        h /= 3;

        for (i = h; i < n; i++) 
		{
            aux = v[i];
            j = i - h;
			contador_comp();
			
            while (j >= 0 && aux < v[j]) 
			{
                v[j + h] = v[j];
                j -= h;
				
				contador_trocas();
            }
            v[j + h] = aux;
        }
    }
}

//seleção_direta
void selection_sort(int *v, int n)
{
    int i, j, min, aux;

    for (i = 0; i < (n-1); i++)
    {
        min = i;
		
        for (j = (i + 1); j < n; j++)
        {
			contador_comp();
            if (v[j] < v[min])
			{
                min = j;
			}
        }
        if (i != min) 
		{
            aux = v[min];
            v[min] = v[i];
            v[i] = aux;
			contador_trocas();
        }
    }
}

//heap_sort
void cria_heap(int *v, int inicio, int fim)
{
    int aux = v[inicio];
    int j = inicio * 2 + 1;
    
	while (j <= fim) 
	{
		
        if (j < fim) 
		{
			contador_comp();
			
            if (v[j] < v[j + 1]) 
			{
				contador_comp();
                j++;
            }
        }
        if (aux < v[j]) 
		{
			contador_trocas();
            v[inicio] = v[j];
            inicio = j;
            j = 2 * inicio + 1;
        }
        else 
		{
            j = fim + 1;
        }
    }
    v[inicio] = aux;
}

void heap_sort(int *v, int n) 
{
    int i;
    int aux;
    for (i = (n - 1)/2; i >= 0; i--) 
	{
		cria_heap(v, i, n - 1);	
    }

    for (i = n-1; i >= 1; i--) 
	{
		contador_trocas();
        aux = v[0];
        v[0] = v[i];
        v[i] = aux;
        cria_heap(v, 0, i - 1);
    }
}

//quick_sort
void particao_quick_sort(int *v, int esquerda, int direita, int *i, int *j) 
{
    int pivo, aux;
    *i = esquerda;
    *j = direita;
    pivo = v[(esquerda + direita) / 2];

    while(*i <= *j) 
	{
		contador_comp();
		
        while(v[*i] < pivo && *i < direita) 
		{
			contador_comp();
            (*i)++;
        }
        while(v[*j] > pivo && *j > esquerda) 
		{
			contador_comp();
            (*j)--;
        }
        if(*i <= *j) 
		{		
            aux = v[*i];
            v[*i] = v[*j];
            v[*j] = aux;
            (*i)++;
            (*j)--;
			contador_comp();
			contador_trocas();
        }
    }
}

void quick_sort(int *v, int esquerda, int direita) 
{
    int i, j;
	
    particao_quick_sort(v, esquerda, direita, &i, &j);

    if(j > esquerda) 
	{
        quick_sort(v, esquerda, j);
    }
    if(i < direita) 
	{
        quick_sort(v,  i, direita);
    }
}


//merge_sort
void merge(int *v, int inicio, int fim, int meio) 
{
    int i, j, k;
    int *vetor_temp;
    i = inicio;
    j = meio + 1;
    k = 0;
	
    vetor_temp = (int *) malloc(sizeof(int) * (fim - inicio + 1));
	while( i <= meio || j  <= fim ) 
	{
      if ( i == meio + 1 || (v[j] < v[i] && j != fim + 1)) 
	  {
		contador_comp();
        vetor_temp[k] = v[j];
        j++;
        k++;
      }
      else 
	  {
		contador_comp();
        vetor_temp[k] = v[i];
        i++;
        k++;
      }
    }
    for( i = inicio; i <= fim; i++ ) 
	{
		contador_trocas();
		v[i] = vetor_temp[i-inicio];
    }
    free(vetor_temp);
}

void merge_sort(int *v, int inicio, int fim) 
{
    int meio;

    if ( inicio < fim ) 
	{
        meio = ( inicio + fim )/2;
        merge_sort( v, inicio, meio );
        merge_sort( v, meio+1,fim );
        merge( v, inicio, fim, meio );
    }
}

//radix_sort
void radix_sort(int *v, int n) 
{
    int i;
    int *b;
    int maior = v[0];
    int exp = 1;

    b = (int *)calloc(n, sizeof(int));

    for (i = 0; i < n; i++) 
	{
        if (v[i] > maior)
		{
    	    maior = v[i];
		}
    }

    while (maior/exp > 0) 
	{
        int bucket_radix[10] = { 0 };
		for (i = 0; i < n; i++)
		{
			contador_comp();
			bucket_radix[(v[i] / exp) % 10]++;
		}
		for (i = 1; i < 10; i++)
    	{    
			contador_comp();
			bucket_radix[i] += bucket_radix[i - 1];
		}
		for (i = n - 1; i >= 0; i--)
    	{    
			contador_comp();
			b[--bucket_radix[(v[i] / exp) % 10]] = v[i];
		}
		for (i = 0; i < n; i++)
    	{    
			contador_comp();
			contador_trocas();
			v[i] = b[i];
		}
		exp *= 10;
    }

    free(b);
}

void bucket_sort(int *v, int n_max, int n_elem)
{
	typedef struct {
	int topo;
    int balde[n_max];
	} bucket;

	
    bucket b[n_elem];
    
	int i, j, k;

	for(i = 0; i < n_elem; i++)
	{
        b[i].topo = 0;
	}
	for(i = 0; i < n_max; i++)
	{                         
		j = n_elem - 1;
		while(1)
		{
			if(j < 0)
			{	
				break;
			}
			if(v[i] >= j*10)
			{
				contador_comp();
				b[j].balde[b[j].topo] = v[i];
				(b[j].topo)++;
				break;
			}
			j--;
		}
	}

	for(i = 0; i < n_elem; i++) 
	{                    
        if(b[i].topo)
		{
			bubble_sort(b[i].balde, b[i].topo);
		}
	}
	
    i = 0;
	
	for(j = 0; j < n_elem; j++)
	{                    
		for(k = 0; k < b[j].topo; k++)
		{
			contador_comp();
			v[i] = b[j].balde[k];
            i++;
        }
    }
}