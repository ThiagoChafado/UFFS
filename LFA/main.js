function dfa(m, string) {
    const [q, sigma, delta, q0, f] = m;
    let qA = q0;
    for (let x of string) {
        qA = delta[qA][x];
    }
    return f.includes(qA);
}

const delta = {
    ['q0']: { '0': 'q0', '1': 'q1' },
    ['q1']: { '0': 'q2', '1': 'q1' },
    ['q2']: { '0': 'q1', '1': 'q1' }
};

const q = ['q0', 'q1', 'q2'];
const f = ['q1'];
const sigma = ['0', '1'];

console.log(dfa([q, sigma, delta, 'q0', f], '000101010'));
