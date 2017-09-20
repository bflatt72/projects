//Largest Prime Factor. Not sure why so many people have tried to make this problem more difficult than it is or tried to do more than the problem asked for but this seems to me to be the simplest solution and you don't even need an extra isPrime function. This solution is very slow for larger numbers though.//



function largestPrimeFactor(n){
var i=2;
while (i <= n) {
    if (n % i === 0) {
        n/=i;    
    }
    else{
        i++;
    }
}
console.log(i);
}

largestPrimeFactor(600851475143)
