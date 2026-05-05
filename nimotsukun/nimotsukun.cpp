// nimotsukun.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include "GameManager.h"
#include <string>
using namespace std;

int main()
{
	GameManager* gm = new GameManager;
	string input = "";
	gm->start();
	while(input == "q") {
		cin >> input;
		gm->update(input);
	}
	delete gm;
}
