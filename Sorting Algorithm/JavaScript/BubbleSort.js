
const swap = (arr, x, y)=>{
    let temp = arr[x]
    arr[x] = arr[y]
    arr[y] = temp
}

const bubbleSort = (arr) => {
    let n = arr.length
    
    for(let i = 0; i < n-1; i++)
        for(let j = 0; j < n-1-i; j++)
          if(arr[j+1] < arr[j])
           swap(arr, j , j+1)

    return arr       
}

let arr = [89,45,68,90,29,34,17]
let sortedArr = bubbleSort(arr)
console.log(sortedArr)