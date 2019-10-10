const readline = require('readline');
const rl = readline.createInterface({
  input:process.stdin,
  output:process.stdout
});

// function to calculate perfect
function perfect (number) {
  var sum =0 ;

  for (let i =1; i<=number/2;i++) {
    if (number % i === 0) {
      sum+=i;
    }
  }
  if (sum === number) {
    console.log(`The given number ${number} is perfect`)
  } else {
    console.log(`The given number ${number} is not perfect`)
  }
}

// asking for input from user
rl.question(' enter the value of n ', (n) => {
  perfect(Number(n))
  rl.close(); 
})
