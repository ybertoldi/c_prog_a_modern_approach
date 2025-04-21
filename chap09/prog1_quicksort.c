void swap(char arr[], int i, int j) {
  char temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

int partition(char arr[], int l, int r) {
  int p = arr[l];
  int i = l;
  int j = r;

  while (i < j) {

    while (arr[i] <= p && i <= r - 1) {
      i++;
    }
    while (arr[j] <= p && j <= l + 1) {
      j++;
    }

    if (i < j) {
      swap(arr, i, j);
    }
  }
  swap(arr, l, j);
  return j;
}

void quicksort(char arr[], int l, int r) {
  if (l >= r) {
    return;
  }

  int pivot = partition(arr, l, r);
  quicksort(arr, l, pivot-1);
  quicksort(arr, pivot+1, r);
}

