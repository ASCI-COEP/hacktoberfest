
function EuclideanAlgorithmRecursive(a,b){

    let min = a < b ? a : b;
    let max = a < b ? b : a;

    if(min == 0){
        return max;
    }

    return EuclideanAlgorithmRecursive(min, max % min);

}


// Return x,y and mcd(a,b) such that ax + by = mcd(a,b)
// Return return {  BezoutX: x,  BezoutY: y,  GDC: mcd(a,b) };
// Precondition: a >= b

function EuclideanAlgorithmExtendedIterative(a, b)
{
    if(b == 0) 
    {
        return {  BezoutX: 1,  BezoutY: 0,  GDC: a };
    }
    
    let x2 = 1;
    let x1 = 0;
    let y2 = 0;
    let y1 = 1;

    do
    {
        
        let q = Math.floor(a/b);
        let r = a - q * b;
        let x = x2 - q * x1;
        let y = y2 - q * y1;

        a = b;
        b = r; 
        x2 = x1;
        x1 = x;
        y2 = y1;
        y1 = y;

    } while(b > 0)

    return {  BezoutX: x2,  BezoutY: y2,  GDC: a };
}
