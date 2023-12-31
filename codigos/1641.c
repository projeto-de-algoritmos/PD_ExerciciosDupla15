int countVowelStrings(int n) {
    int dp[n + 1][6];  // cria um array de pd

    // inicializa com o caso base
    for (int i = 1; i <= 5; i++) {
        dp[1][i] = 1;  // Para n = 1, ha uma unica forma para cada vogal
    }

    // preenche a tabela:
    for (int i = 2; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= 5; j++) {
            sum += dp[i - 1][j];  // calcula a soma
            dp[i][j] = sum;       // armazena a soma para o indice atual
        }
    }

    // calcula o total para strings de tamanho n:
    int totalCount = 0;
    for (int i = 1; i <= 5; i++) {
        totalCount += dp[n][i];
    }

    return totalCount;
}