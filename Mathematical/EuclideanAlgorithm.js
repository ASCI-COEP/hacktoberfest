
function EuclideanAlgorithmRecursive(a,b){

    let min = a < b ? a : b;
    let max = a < b ? b : a;

    if(min == 0){
        return max;
    }

    return EuclideanAlgorithmRecursive(min, max % min);

}