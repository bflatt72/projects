//Find the sum of even Fibonacci numbers


var x=0;
var y=1;
var z=1;
var sum=0;

while (z < 4e6) {
   if (z%2 == 0) {
      sum+=z;
   }
   x=y;
   y=z;
   z = x+y;
}
console.log(sum);
