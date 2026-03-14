function quicksort(arr, low, high):
    if low < high:
        pivotIndex = partition(arr, low, high)
        quicksort(arr, low, pivotIndex - 1)
        quicksort(arr, pivotIndex + 1, high)

function partition(arr, low, high):
    pivot = arr[high]
    i = low - 1
    for j from low to high-1:
        if arr[j] < pivot:
            i = i + 1
            swap arr[i] and arr[j]
    swap arr[i+1] and arr[high]
    return i + 1