
function EuclideanAlgorithmRecursive(a,b){

    let min = a < b ? a : b;
    let max = a < b ? b : a;

    if(min == 0){
        return max;
    }

    return EuclideanAlgorithmRecursive(min, max % min);

}

// ax + by = mcd(a,b)

function EuclideanAlgorithmExtendedRecursive(a, b, x, y){

    if(a == 0)
    {
        x = 0;
        y = 0;
        return b;
    }

    let x_i = 1
    let y_i = 1 
    let remainder = b%a;

    let GreatestCommonDivisor = EuclideanAlgorithmExtendedRecursive(remainder, a, x_i, y_i) 
  
    return GreatestCommonDivisor;
}
