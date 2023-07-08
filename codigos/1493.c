#include <stdio.h>

int longestSubarray(int* nums, int numsSize) {
    int* dp = (int*)malloc(numsSize * sizeof(int));
    int maxLen = 0;
    int currLen = 0;
    int zeroIndex = -1;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) {
            currLen++;
            dp[i] = currLen;
        } else {
            // caso encontre 0
            if (zeroIndex != -1) {
                // calcula o tamanho do subarray do indice atual ate o índice com zero anterior
                currLen = i - zeroIndex;
            } else {
                // se o primeiro 0 for encontrado, aumenta o tamanho
                currLen++;
            }
            // atualiza o indice do zero para o indice atual
            zeroIndex = i;
            dp[i] = currLen;
        }
        // guarda o valor do maior tamanho
        maxLen = (maxLen > dp[i]) ? maxLen : dp[i];
    }

    free(dp);
    // subtrai 1 do tamanho maximo caso positivo, para que seja deletado um elemento
    return maxLen > 0 ? maxLen - 1 : 0;
}

int main() {
    int nums[100];
    int numsSize = 0;
    int num;

    printf("Informe os elementos (insira Ctrl+Z ou Ctrl+D para encerrar):\n");
    while (scanf("%d", &num) != EOF) {
        nums[numsSize] = num;
        numsSize++;
    }

    int result = longestSubarray(nums, numsSize);
    printf("Maior subarray de 1s apos deletar um elemento tem tamanho: %d\n", result);

    return 0;
}
