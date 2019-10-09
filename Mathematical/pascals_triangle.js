
function printPascal(n){
    for(let row = 1; row < n + 1; row++)
    {
        let ct = 1;
        let store = "1";
        for(let i = 1; i < row;i++)
        {
            ct = Math.trunc(ct * (row - i) / i);
            store += " " + ct;
        }
        console.log(store);
    };
}
     
function printRowRPascal(r){
        let ct = 1;
        let store = "1";
        for(let i = 1; i < r;i++)
        {
            ct = Math.trunc(ct * (r - i) / i);
            store += " " + ct;
        }
        console.log(store);
}
       
