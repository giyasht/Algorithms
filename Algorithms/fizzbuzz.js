// Fizz buzz is a group word game for children to teach them about division. Players take turns to count incrementally, replacing any number divisible by three with the word "fizz", and any number divisible by five with the word "buzz".

const FizzBuzz = (num) => {
  for (let i = 0; i <= num; i++) {
    let output = "";
    if (i % 3 == 0) {
      output += "Fizz";
    }
    if (i % 5 == 0) {
      output += "Buzz";
    }
    if (output == "") {
      output = i;
    }
    console.log(output);
  }
};

FizzBuzz(100);
