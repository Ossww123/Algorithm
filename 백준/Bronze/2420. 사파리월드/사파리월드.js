let [a, b] = require('fs').readFileSync(0, 'utf-8').split(' ');
a = Number(a); b = Number(b);

console.log(Math.abs(a - b));