const Merge = (left, right) => {
    let resultArray = [], leftIndex = 0, rightIndex = 0;

    while (leftIndex < left.length && rightIndex < right.length) {
      if (left[leftIndex] < right[rightIndex])
      {
        resultArray.push(left[leftIndex]);
        leftIndex++; 
      } 
      else 
      {
        resultArray.push(right[rightIndex]);
        rightIndex++; 
      }
    }
  
    return resultArray
            .concat(left.slice(leftIndex))
            .concat(right.slice(rightIndex));
  }


const mergeSort = (arr) => {
  if (arr.length <= 1) {
    return arr;
  }
  const middle = Math.floor(arr.length / 2);

  const left = arr.slice(0, middle);
  const right = arr.slice(middle);

  return Merge(
    mergeSort(left), mergeSort(right)
  );
}



let arr = [89,45,68,90,29,34,17]
n = arr.length
let sortedArr = mergeSort(arr)
console.log(sortedArr)