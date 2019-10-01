const readline = require('readline');
const rl = readline.createInterface({
  input:process.stdin,
  output:process.stdout
});

// function to calculate factorial
function factorial (number) {
  if (number <= 1) {
    return 1;
  }
  return number * factorial (number - 1)
}

// asking for input from user
rl.question(' enter the value of n ', (n) => {
  rl.question(' enter the value of r ', (r) => {
    if (n < r) {
      console.log('enter the correct n and r');
      rl.close();
    } else {

      //calling factorial function
        var nCr = factorial(n) / (factorial(r) * factorial(n-r));
        console.log('\n the nalue of nCr is :   ', nCr);
        rl.close();
    }
  })
})
