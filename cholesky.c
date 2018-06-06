void Cholesky(float **m, int n){
  int i, i, k;
  float soma;
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      soma = 0.0;
      if (i == j){
        for(k = 0; k < i; k++)
          soma = soma + m[i][k];
        m[i][j] = sqrt(m[i][j] - soma);
      }
      else if (i < j)
        m[i][j] = 0.0;
      else {
        for(k = 0; k < j; k++)
          soma = soma + m[i][k]*m[j][k];
        m[i][j] = m[i][j] - soma;
        m[i][j] = m[i][j]/m[j][j];
      }
    }
  }
}
