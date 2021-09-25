void Swap(int *A, int i, int j){
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int Partition(int *A, int starting_index, int last_index){
    int pivot = A[last_index];
    int pIndex = starting_index;
    for(int i = starting_index; i < last_index; i++){
        if(A[i] <= pivot){
            Swap(A, i, pIndex);
            pIndex++;
        }
    }
    Swap(A, pIndex, last_index);
    return pIndex;
}

void QuickSort(int *A, int starting_index, int last_index){
    if(starting_index < last_index){
        int partition_index = Partition(A, starting_index, last_index);
        QuickSort(A, starting_index, partition_index - 1);
        QuickSort(A, partition_index + 1, last_index);
    }
}