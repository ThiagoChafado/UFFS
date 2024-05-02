// controle de acesso a portas
// senha numerica - 4 digitos
// senha escolhidda - 1327

function dfa(m, string) {
    const [q, sigma, delta, q0, f] = m;
    let qA = q0;
    for (let x of string) {
        qA = delta[qA][x]
    }
    return f.includes(qA)
}

const delta = {
    ['q0']: { '0': 'q0', '1': 'q1','2': 'q0','3': 'q0','4': 'q0','5': 'q0','6': 'q0','7': 'q0','8': 'q0','9': 'q0'},
    ['q1']: { '0': 'q0', '1': 'q0','2': 'q0','3': 'q2','4': 'q0','5': 'q0','6': 'q0','7': 'q0','8': 'q0','9': 'q0'},
    ['q2']: { '0': 'q0', '1': 'q0','2': 'q3','3': 'q0','4': 'q0','5': 'q0','6': 'q0','7': 'q0','8': 'q0','9': 'q0'},
    ['q3']: { '0': 'q0', '1': 'q0','2': 'q0','3': 'q0','4': 'q0','5': 'q0','6': 'q0','7': 'q4','8': 'q0','9': 'q0'},
    ['q4']: { '0': 'q0', '1': 'q0','2': 'q0','3': 'q0','4': 'q0','5': 'q0','6': 'q0','7': 'q4','8': 'q0','9': 'q0'}
}

const q = ['q0','q1', 'q2', 'q3', 'q4'];
const f = ['q4'];
const sigma = ['0', '1', '2', '3','4', '5', '6', '7', '8', '9'];

console.log(dfa([q,sigma, delta, 'q0', f], '001234')) //false
console.log(dfa([q,sigma, delta, 'q0', f], '567800')) //false
console.log(dfa([q,sigma, delta, 'q0', f], '0000')) //false
console.log(dfa([q,sigma, delta, 'q0', f], '1326')) //false
console.log(dfa([q,sigma, delta, 'q0', f], '1327')) //true
console.log(dfa([q,sigma, delta, 'q0', f], '132700'))//false