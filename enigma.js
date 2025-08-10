const key = [['Q','W','E','R','T','Y','U','I','O','P'], ['A','S','D','F','G','H','J','K','L'], ['Z','X','C','V','B','N','M']];
const w = ["EKMFLGDQVZNTOWYHXUSPAIBRCJ", "AJDKSIRUXBLHWTMCQGZNPYFVOE", "BDFHJLCPRTXVZNYEIWGAKMUSQO", "ESOVPZJAYQUIRHXLNFTGKDCMWB", "VZBRGITYUPSDNHLXAWMJQOFECK"];
const r = "YRUHQSLDPXNGOKMIEBFZCWVJAT";

class EnigmaMachine{
  constructor(w1_w, w1_p, w2_w, w2_p, w3_w, w3_p, r_w, p){
    this.w1 = new rotor(w1_w, w1_p);
    this.w2 = new rotor(w2_w, w2_p);
    this.w3 = new rotor(w3_w, w3_p);
    this.r = new reflector(r_w);
    this.p = new plugboard(p);
  }

  encryptChar(c){
    this.w1.rotate();
    if(this.w1.atNotch()){
      this.w2.rotate();
      if(this.w2.atNotch())
        this.w3.rotate();
    }

    c = this.p.swap(c);
    c = this.w1.forward(c);
    c = this.w2.forward(c);
    c = this.w3.forward(c);

    c = this.r.forward(c);

    c = this.w3.backward(c);
    c = this.w2.backward(c);
    c = this.w1.backward(c);

    c = this.p.swap(c);

    return c;
  }
}

class rotor{
  constructor(wire, pos){
    this.wire = wire;
    this.flag = 25;
    this.pos = pos % 26;
  }

  forward(c){
    let idx = (c.charCodeAt(0) - 65 + this.pos) % 26;
    let wired = this.wire.charCodeAt(idx) - 65;
    let out = (wired - this.pos + 26) % 26;
    return String.fromCharCode(out + 65);
  }

  backward(c){
    let idx = this.wire.indexOf(String.fromCharCode(((c.charCodeAt(0) - 65 + 26 - this.pos) % 26) + 65));
    let out = (idx + this.pos) % 26;
    return String.fromCharCode(out + 65);
  }

  rotate(){
    this.pos = (this.pos + 1) % 26;
  }

  atNotch(){
    return this.pos === this.flag;
  }
}

class reflector{
  constructor(wire){
    this.wire = wire;
  }

  forward(c){
    return this.wire[c.charCodeAt(0) - 65];
  }

  backward(c){
    return this.forward(c);
  }
}

class plugboard{
  constructor(pairsStr){
    this.wire = new Map();
    if(pairsStr){
      const pairs = pairsStr.toUpperCase().match(/[A-Z]{2}/g) || [];
      const used = new Set();
      for(const p of pairs){
        const a = p[0], b = p[1];
        if(!used.has(a) && !used.has(b)){
          this.wire.set(a,b);
          this.wire.set(b,a);
          used.add(a);
          used.add(b);
        }
      }
    }
  }
  swap(c){
    return this.wire.get(c) || c;
  }
}

const lampboard = document.getElementById('lampboard');
const keyboard = document.getElementById('keyboard');
const reset = document.getElementById('reset-btn');

let enigmaMachine = null;

function createRow(container, letters, isLamp){
  const rowDiv = document.createElement('div');
  rowDiv.className = isLamp ? 'lampboard-row' : 'keyboard-row';

  for(const letter of letters){
    const el = document.createElement(isLamp ? 'div' : 'button');
    el.className = isLamp ? 'lamp' : 'key-btn';
    el.textContent = letter;
    if(!isLamp) el.dataset.letter = letter;
    if(isLamp) el.id = 'lamp-' + letter;
    rowDiv.appendChild(el);
  }

  container.appendChild(rowDiv);
}

function initKeyboardAndLamps(){
  lampboard.innerHTML = '';
  keyboard.innerHTML = '';
  for(const row of key) createRow(lampboard, row, true);
  for(const row of key) createRow(keyboard, row, false);
}

function update(){
  document.getElementById('rotor1-pos-display').textContent = enigmaMachine.w1.pos;
  document.getElementById('rotor2-pos-display').textContent = enigmaMachine.w2.pos;
  document.getElementById('rotor3-pos-display').textContent = enigmaMachine.w3.pos;
}

function initEnigma(){
  const r1 = parseInt(document.getElementById('rotor1-select').value);
  const r2 = parseInt(document.getElementById('rotor2-select').value);
  const r3 = parseInt(document.getElementById('rotor3-select').value);

  const p1 = parseInt(document.getElementById('rotor1-pos').value) || 0;
  const p2 = parseInt(document.getElementById('rotor2-pos').value) || 0;
  const p3 = parseInt(document.getElementById('rotor3-pos').value) || 0;

  const plugboardInput = document.getElementById('plugboard').value;

  enigmaMachine = new EnigmaMachine(w[r1], p1, w[r2], p2, w[r3], p3, r, plugboardInput);
}

initKeyboardAndLamps();

keyboard.addEventListener('click', (e) => {
  if(!enigmaMachine) initEnigma();
  if(!e.target.classList.contains('key-btn')) return;

  const letter = e.target.dataset.letter;
  const cipherLetter = enigmaMachine.encryptChar(letter);

  for(const row of key)
    for(const ltr of row)
      document.getElementById('lamp-' + ltr).classList.remove('on');

  document.getElementById('lamp-' + cipherLetter).classList.add('on');

  update();
});

reset.addEventListener('click', () => {
  enigmaMachine = null;
  for(const row of key)
    for(const ltr of row)
      document.getElementById('lamp-' + ltr).classList.remove('on');
   document.getElementById('rotor1-pos-display').textContent = document.getElementById('rotor1-pos').value || 0;
  document.getElementById('rotor2-pos-display').textContent = document.getElementById('rotor2-pos').value || 0;
  document.getElementById('rotor3-pos-display').textContent = document.getElementById('rotor3-pos').value || 0;
});
