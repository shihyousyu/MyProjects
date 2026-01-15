<script setup>
	import {ref} from 'vue'
	
	let grid = [];
	let score = 0;

	function init(){
		grid = Array.from({length: 4}, () => Array(4).fill(0));
		add();
		add();
		update();
	}

	function add(){
		let t = [];
		for(let i = 0; i < 4; i++){
			for(let j = 0; j < 4; j++){
				if(grid[i][j] == 0){
					t.push([i, j]);
				}
			}
		}
		if(t.length == 0) return;
		
		let [x, y] = t[Math.floor(Math.random() * t.length)];
		grid[x][y] = (Math.random() < 0.7) ? 2 : 4;
	}

	function rotate(times){
		while(times--){
			grid = grid[0].map((_, i) => grid.map(row => row[i]).reverse());
		}
	}

	function left(){
		let flag = false;

		for(let i = 0; i < 4; i++){
			let row = grid[i].filter(v => v != 0);
			for(let j = 0; j < row.length - 1; j ++){
				if(row[j] == row[j + 1]){
					row[j] *= 2;
					score += row[j];
					row[j + 1] = 0;
				}
			}
			row = row.filter(v => v != 0);
			while(row.length < 4){
				row.push(0);
			}
			if(row.some((v, idx) => v != grid[i][idx])){
				flag = true;
			}
			grid[i] = row;
		}
		return flag;
	}

	function right(){
		rotate(2);
		let flag = left();
		rotate(2);
		return flag;
	}

	function up(){
		rotate(3);
		let flag = left();
		rotate(1);
		return flag;
	}

	function down(){
		rotate(1);
		let flag = left();
		rotate(3);
		return flag;
	}

	function canMove(){
		for(let i = 0; i < 4; i++){
			for(let j = 0; j < 4; j++){
				if(grid[i][j] == 0){
					return true;
				}
				if(j < 3 && grid[i][j] == grid[i][j + 1]){
					return true;
				}
				if(i < 3 && grid[i][j] == grid[i + 1][j]){
					return true;
				}
			}
		}
		return false;
	}

	function check(){
		for(let i = 0; i < 4; i++){
			for(let j = 0; j < 4; j++){
				if(grid[i][j] == 2048){
					return true;
				}
			}
		}
		return false;
	}

	document.addEventListener('keydown', e => {
		let move = false;
		switch(e.key){
			case 'ArrowLeft':
				move = left();
				break;
			case 'ArrowRight':
				move = right();
				break;
			case 'ArrowUp':
				move = up();
				break;
			case 'ArrowDown':
				move = down();
				break;			
		}

		if(move){
			add();
			update();
			if(check()){
				document.getElementById("message").textContent = 'You Win';
			}
			else if(!canMove()){
				document.getElementById("message").textContent = 'game over';
			}
		}
	});

	function update(){
		for(let i = 0; i < 4; i++){
			for(let j = 0; j < 4; j++){
				let cell = document.getElementById(`cell-${i}-${j}`);
				let val = grid[i][j];
				cell.textContent = val ? val : '';
				cell.className = 'cell cell-' + val;
			}
		}
		document.getElementById("score").textContent = 'score: ' + score;
	}

	window.onload = init;
</script>

<template>
	<h1>2048</h1>
	<div id="score">score: 0</div><br><br>
	<div id="grid">
		<div class="cell" id="cell-0-0"></div>
		<div class="cell" id="cell-0-1"></div>
		<div class="cell" id="cell-0-2"></div>
		<div class="cell" id="cell-0-3"></div>

		<div class="cell" id="cell-1-0"></div>
		<div class="cell" id="cell-1-1"></div>
		<div class="cell" id="cell-1-2"></div>
		<div class="cell" id="cell-1-3"></div>

		<div class="cell" id="cell-2-0"></div>
		<div class="cell" id="cell-2-1"></div>
		<div class="cell" id="cell-2-2"></div>
		<div class="cell" id="cell-2-3"></div>

		<div class="cell" id="cell-3-0"></div>
		<div class="cell" id="cell-3-1"></div>
		<div class="cell" id="cell-3-2"></div>
		<div class="cell" id="cell-3-3"></div>
	</div>
	<div id="message"></div>
</template>

<style>
	body{
		font-family: Arial, sans-serif;
		background: #faf8ef;
		height: 100vh;

		display: flex;
		flex-direction: column;
		align-items: center;
	}

	#score, h1{
		color: #776e65;
		font-weight: 700;
	}

	#grid{
		display: grid;
		grid-template-columns: repeat(4, 100px);
		grid-auto-rows: repeat(4, 100px);
		gap: 15px;
		border-radius: 20px;
	}

	.cell{
		width: 100px;
		height: 100px;
		font-size: 40px;

		background: #cdc1b4;
		color: #776e65;

		font-weight: 700;

		border-radius: 12px;
		
		display: flex;
		align-items: center;
		justify-content: center;
	}
	.cell-0{background: #b88d60; color: #cdc1b4;}
	.cell-2{background: #eee4da; color: #776e65;}
	.cell-4{background: #ede0c8; color: #776e65;}
	.cell-8{background: #f2b179; color: #f9f6f2;}
	.cell-16{background: #f59563; color: #f9f6f2;}
	.cell-32{background: #f67c5f; color: #f9f6f2;}
	.cell-64{background: #f65e3b; color: #f9f6f2;}
	.cell-128{background: #edcf72; color: #f9f6f2;}
	.cell-256{background: #edcc61; color: #f9f6f2;}
	.cell-512{background: #edc850; color: #f9f6f2;}
	.cell-1024{background: #edc53f; color: #f9f6f2;}
	.cell-2048{background: #edc22e; color: #f9f6f2;}

	#message{
		margin-top: 20px;
		font-size: 40px;
		color: rgb(174, 50, 50);
		font-weight: 700;
	}
</style>
