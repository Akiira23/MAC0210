#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//troca posicoes no vetor m se m_true e igual a 1 e no vetor p caso contrario
//nas posicoes i_a com a i_b.
void swap(int i_a, int i_b, int m_true, float *m, int *p){
	if (m_true) {
		float aux;
		aux = m[i_a];
		m[i_a] = m[i_b];
		m[i_b] = aux;
	}
	else {
		int aux;
		aux = p[i_a];
		p[i_a] = p[i_b];
		p[i_b] = aux;		
	}
}
//loop da decomposicao
void lu (float *m, int n, int *p){
	//vetor da permutacao
	for (int i = 0; i < n; ++i)
		p[i] = i;
	for (int k = 0; k < n - 1; ++k){
		int i_first = (n*k + k);
		int i_max = i_first;
		float v_max = m[i_first];
		int p_i = 0;
		//busca o maior elemento da coluna i
		for (int i = k + 1; i < n; ++i){
			int i_col = n*i + k;
			if (m[i_col] > v_max){
				i_max = i_col;
				v_max = m[i_col];
				p_i = i;
			}
		}
		//se houve permutacao troca suas posicoes
		if (i_max > i_first){
			int i_a = i_first;
			int i_b = i_max;
			for (int j = i_first; j < n; ++j, ++i_a, ++i_b)
				swap(i_a, i_b, 1, m, p);
			swap(k, p_i, 0, m, p);
		}
		//faz L e U inplace no vetor m[]
		for (int i = k + 1; i < n; ++i){
			int i_col = n*i + k;
			m[i_col] = m[i_col]/m[i_first];
			for (int j = k + 1; j < n; ++j)
				m[j + i*n] = m[n*k + j]*(-m[i_col]) + m[j + i*n];	
		}
	}
}

int main() {
	int n, *p;
	float *m;
	scanf("%d", &n);
	p = malloc(n * sizeof (int));
	m = malloc(n*n * sizeof(float));
	for (int i = 0; i < n*n; i++)
		scanf("%f", &m[i]);
	printf("antes\n");
	lu(m, n, p);
	for (int i = 0; i < n*n; i++) {
		if (i%n == 0)
			printf("\n");
		printf(" %f", m[i]);
	}
	printf("\n");
	return 0;
}
