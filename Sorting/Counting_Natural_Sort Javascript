
function print_array(theArray){
  theArray.forEach(function(element){
    console.log(element);
  })
}

function counting_natural_sort(theArray){

  //Obtain max of array
  var max =  Math.max.apply(Math, theArray);
  
  //Array of 0...max
  var arrayCount = new Array();
  
  //Inicializated array in 0
  for(let index = 0; index < max+1; index++){
    arrayCount[index] = 0;
  }
  
  theArray.forEach(function(element){
        arrayCount[element]++;
  })
  
  var orderArray = [];
  
  //2 * order(n)= 2 O(n) = ord(n)
  for(let index = 0; index < max+1; index++){
    for(let count = 0; count < arrayCount[index]; count++){
      orderArray.push(index);
    }
  }
  
  print_array(orderArray);
  
  return orderArray;
}

