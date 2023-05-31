void mergeSort(int arr[], int inicio, int fim){
    if (inicio < fim)
    {
        // Encontra o ponto médio para dividir o array em duas metades
        int meio = inicio + (fim - inicio) / 2;

        // Ordena a primeira e a segunda metade
        mergeSort(arr, inicio, meio);
        mergeSort(arr, meio + 1, fim);

        // Mescla as duas metades ordenadas
        merge(arr, inicio, meio, fim);
    }
}
void merge(int arr[], int inicio, int meio, int fim){
    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    // Cria vetores temporários para os subvetores da esquerda e direita
    int INICIO[n1], FIM[n2];

    // Copia os dados para os vetores temporários
    for (i = 0; i < n1; i++)
        INICIO[i] = arr[inicio + i];
    for (j = 0; j < n2; j++)
        FIM[j] = arr[meio + 1 + j];

    // Intercala os dois vetores temporários de volta ao vetor original arr[l..r]
    i = 0; // Índice inicial do primeiro subvetor
    j = 0; // Índice inicial do segundo subvetor
    k = inicio; // Índice inicial do vetor mesclado

    while (i < n1 && j < n2)
    {
        if (INICIO[i] <= FIM[j])
        {
            arr[k] = INICIO[i];
            i++;
        }
        else
        {
            arr[k] = FIM[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L[], se houver algum
    while (i < n1)
    {
        arr[k] = INICIO[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R[], se houver algum
    while (j < n2)
    {
        arr[k] = FIM[j];
        j++;
        k++;
    }
}

