# Enigma Machine Simulator

This project is a simulator of the Enigma machine used during World War II. It allows users to configure rotors, initial rotor positions, and plugboard settings to encrypt individual letters, displaying the resulting cipher letter on a lampboard.  
[here](https://shihyousyu.github.io/EnigmaMachineSimulator/)  

## Features

- Select from 5 different rotors and set their initial positions (0–25).
- Configure plugboard connections using paired letter swaps.
- Interactive on-screen keyboard to input letters.
- Visual lampboard showing the encrypted output letter for each input.
- Rotors automatically step with a simple notch turnover simulation.
- Reset button to clear the current state and reset rotors.

## Usage
1. Select Rotor 1, Rotor 2, and Rotor 3 types from the dropdown menus.  
2. Set the initial position (0–25) for each rotor.  
3. Enter plugboard pairs in the input box (format: AB CD EF).  
4. Click letters on the on-screen keyboard to input.  
5. The encrypted letter will light up on the lampboard.  
6. Click Reset to start over.

## Project Structure
`C++ folder`  C++ Edition  
`index.html`  Main page with the UI layout  
`style.css`  Styles for layout, keyboard, lampboard, and controls  
`enigma.js`  Enigma machine logic and UI interaction  

## Notes

- Rotor notch positions are fixed for simplicity; real Enigma rotors had specific notch positions.
- Plugboard input format requires pairs of letters separated by spaces.
- Only uppercase English letters A–Z are supported.

## License

This project is open source and available under the MIT License.
