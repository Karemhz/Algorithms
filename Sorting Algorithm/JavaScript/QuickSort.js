const swap = (arr, x, y) => {
    let temp = arr[x]
    arr[x] = arr[y]
    arr[y] = temp
}
const partition = (arr, left, right) => {
    let pivot = arr[Math.floor((right + left) / 2)], 
        i = left,
        j = right
    while (i <= j) {
        while (arr[i] < pivot) {
            i++
        }
        while (arr[j] > pivot) {
            j--
        }
        if (i <= j) {
            swap(arr, i, j) 
            i++
            j--
        }
    }
    return i
}

const quickSort = (arr, left, right) => {
    let index
    if (arr.length > 1) 
    {
        index = partition(arr, left, right) 
        if (left < index - 1) 
        { 
            quickSort(arr, left, index - 1)
        }
        if (index < right) 
        { 
            quickSort(arr, index, right)
        }
    }
    return arr
}
let arr = [89,45,68,90,29,34,17]
let sortedArray = quickSort(arr, 0, arr.length - 1)
console.log(sortedArray)