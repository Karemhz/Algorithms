const insertionSort = (arr) => {
    for (let i = 1; i < arr.length; i++) {
      let j = i - 1
      let tmp = arr[i]
      while (j >= 0 && arr[j] > tmp) {
        arr[j + 1] = arr[j]
        j--
      }
      arr[j+1] = tmp
    }
    return arr
  }

let arr = [89,45,68,90,29,34,17]
let sortedArray = insertionSort(arr)
console.log(sortedArray)