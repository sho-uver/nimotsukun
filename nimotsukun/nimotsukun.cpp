
#include <iostream>
#include "GameManager.h"
#include <string>
#include "InputCommand.h"
using namespace std;

int main()
{
	GameManager gm;
	string input;
	gm.start();
	while(true) {
		if (gm.isClear()) {
			cin >> input;
			if (gm.toInputCommand(input) == Command_Quit) return 0;
			continue;
		}
		cout << ".にoを置いたらクリア" << endl;
		cout << "pはw,z,a,sでそれぞれ上下左右で動きます" << endl;
		cout << "ゲームをやめるときはqを入力してください" << endl;
		cin >> input;
		InputCommand ic = gm.toInputCommand(input);
		switch (ic) {
		case Command_Quit:
			return 0;

		case Command_None:
			cout << "w/a/s/z/q のいずれかを入力してください。" << endl;
			gm.draw();
			continue;
		}
		gm.update(ic);
		gm.draw();
	}
}
