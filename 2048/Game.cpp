#pragma once

#include "Game.h"

Game::Game(){
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			map[i][j] = 0;
	int x = Random(0, 3);
	int y = Random(0, 3);
	map[x][y] = 2;
};

void Game::run(){
	int x = Random(0, 3);
	int y = Random(0, 3);
	int way = 0;
	if (Input::KeyUp.clicked)
		way = 1;
	else if (Input::KeyDown.clicked)
		way = 2;
	else if (Input::KeyRight.clicked)
		way = 3;
	else if (Input::KeyLeft.clicked)
		way = 4;

	if (way == 0)
		return;

	if (way == 1){
		for (int i = 0; i < 4; i++){
			for (int j = 0; j < 3; j++){
				if (map[i][j] != 0){
					int t = j+1;
					while (t < 4){
						if (map[i][t] > 0 && map[i][j] != map[i][t])
							break;
						else if (map[i][j] == map[i][t]){
							map[i][j] += map[i][t];
							map[i][t] = 0;
							t++;
							break;
						}
						t++;
					}
					t--;
					j = t;
				}
			}
		}
		for (int k = 0; k < 4; k++){
			for (int i = 0; i < 4; i++){
				for (int j = 0; j < 3; j++){
					if (map[i][j] == 0 && map[i][j + 1] != 0){
						map[i][j] = map[i][j + 1];
						map[i][j + 1] = 0;
					}
				}
			}
		}
	}else if (way == 2){
		for (int i = 0; i < 4; i++){
			for (int j = 3; j > 0; j--){
				if (map[i][j] != 0){
					int t = j-1;
					while (t >= 0){
						if (map[i][t] > 0 && map[i][j] != map[i][t])
							break;
						else if (map[i][j] == map[i][t]){
							map[i][j] += map[i][t];
							map[i][t] = 0;
							t--;
							break;
						}
						t--;
					}
					t++;
					j = t;
				}
			}
		}
		for (int k = 0; k < 4; k++){
			for (int i = 0; i < 4; i++){
				for (int j = 3; j > 0; j--){
					if (map[i][j] == 0 && map[i][j - 1] != 0){
						map[i][j] = map[i][j - 1];
						map[i][j - 1] = 0;
					}
				}
			}
		}
	}else if (way == 3){
		for (int i = 0; i < 4; i++){
			for (int j = 3; j > 0; j--){
				if (map[j][i] != 0){
					int t = j-1;
					while (t < 4){
						if (map[t][i] > 0 && map[j][i] != map[t][i])
							break;
						else if (map[j][i] == map[t][i]){
							map[j][i] += map[t][i];
							map[t][i] = 0;
							t--;
							break;
						}
						t--;
					}
					t++;
					j = t;
				}
			}
		}
		for (int k = 0; k < 4; k++){
			for (int i = 0; i < 4; i++){
				for (int j = 3; j > 0; j--){
					if (map[j][i] == 0 && map[j - 1][i] != 0){
						map[j][i] = map[j - 1][i];
						map[j - 1][i] = 0;
					}
				}
			}
		}
	}else if (way == 4){
		for (int i = 0; i < 4; i++){
			for (int j = 0; j < 3; j++){
				if (map[j][i] != 0){
					int t = j+1;
					while (t < 4){
						if (map[t][i] > 0 && map[j][i] != map[t][i])
							break;
						else if (map[j][i] == map[t][i]){
							map[j][i] += map[t][i];
							map[t][i] = 0;
							t++;
							break;
						}
						t++;
					}
					t--;
					j = t;
				}
			}
		}
		for (int k = 0; k < 4; k++){
			for (int i = 0; i < 4; i++){
				for (int j = 0; j < 3; j++){
					if (map[j][i] == 0 && map[j + 1][i] != 0){
						map[j][i] = map[j + 1][i];
						map[j + 1][i] = 0;
					}
				}
			}
		}
	}




	while (map[x][y] != 0){
		x = Random(0, 3);
		y = Random(0, 3);
	}
	int a = Random(1, 2);
	map[x][y] = a * 2;
}

void Game::draw(){
	static Font font(30);
	static Font font2(25);
	static Font font3(20);
	for (int i = 1; i < 4; i++){
		Line(0, 100 * i + i, 404, 100 * i + i).draw();
		Line(100 * i + i, 0, 100 * i + i, 404).draw();
	}
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			if (map[i][j] != 0){
				if (map[i][j] >= 1000){
					Rect(i * 100 + i, j * 100 + j, 100, 100).draw(Color(Palette::Black, 127));
					font3(map[i][j]).drawCenter({ i * 100 + 50, j * 100 + 50 });
				}
				else if (map[i][j] >= 100){
					Rect(i * 100 + i, j * 100 + j, 100, 100).draw(Color(Palette::Yellow, 127));
					font2(map[i][j]).drawCenter({ i * 100 + 50, j * 100 + 50 });
				}
				else{
					Rect(i * 100 + i, j * 100 + j, 100, 100).draw(Color(Palette::Orange, 127));
					font(map[i][j]).drawCenter({ i * 100 + 50, j * 100 + 50 });
				}
			}
			else
				Rect(i * 100 + i, j * 100 + j, 100, 100).draw(Color(Palette::White, 127));

		}
	}
}

int Game::check(){
	int X[4] = { 1, 0, -1, 0 };
	int Y[4] = { 0, 1, 0, -1 };
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			for (int k = 0; k < 4; k++){
				int x = X[k] + i;
				int y = Y[k] + j;
				if (x >= 0 && y >= 0 && x < 4 && y < 4 && map[i][j] == map[x][y]){
					return 0;
				}
			}
		}
	}
	return 1;
}