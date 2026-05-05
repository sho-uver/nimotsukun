#pragma once
// 荷物
// 目的地の上にいたらデカいOになる
// 目的地の上以外なら小さいoになる
// ポジションを保持する
// Playerに押されたことがゲームマネージャーから来る移動先が壁もしくは荷物では無いかを確認する
// 移動可能であれば移動する 
// 移動不可能であればコマンドを無効化するフラグをゲームマネージャーに返す。
#include "MovableObject.h";

class Baggage : public MovableObject {

};