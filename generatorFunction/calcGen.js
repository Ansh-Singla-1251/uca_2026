function* calculator(initialValue) {
  let current = initialValue;

  while(true){
    const input = yield current;

    if(!input || typeof input.operation !== "string" || typeof input.value !== "number"){
      current = "Invalid input";
      continue;
    }

    switch(input.operation){
      case "add":
        current += input.value;
        break;
      case "subtract":
        current -= input.value;
        break;
      case "multiply":
        current *= input.value;
        break;
      case "divide":
        if(input.value === 0){
          current = "Division by zero error";
        } 
        else{
          current /= input.value;
        }
        break;
      default:
        current = "Unknown operation";
    }
  }
}

const calc = calculator(50);

console.log(calc.next().value);
console.log(calc.next({operation: "add", value: 30}).value);
console.log(calc.next({operation: "multiply", value: 2}).value);
console.log(calc.next({operation: "add", value: "30"}).value);
console.log(calc.next({operation: "multiply", value: 0}).value); 
