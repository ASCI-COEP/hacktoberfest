

function binary_search_iterative(theArray, size, element){
  let left = 0
  let right = size-1;
  while(left <= right){
    m = Math.floor((left + right) / 2)
    if(theArray[m] < element){
      left = m + 1;
    }
    else if (theArray[m] > element){
      right = m - 1;
    }
    else{
      return m;
    }
  }
  return -1;
}
