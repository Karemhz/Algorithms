
const swap = (arr, x, y) => {
    let temp = arr[x]
    arr[x] = arr[y]
    arr[y] = temp
}

const selectionSort = (arr) => {
    let n = arr.length
    for(let i = 0; i < n-1; i++){
        let min = i
        for(let j = i+1; j < n; j++){
            if(arr[j] < arr[min])
              min = j
        }
    if(min !== i)
        swap(arr, i, min)
    }
    return arr
}


let arr = [89,45,68,90,29,34,17]
let sortedArr = selectionSort(arr)

console.log(sortedArr)