//  Created by Black3rry on 10/3/16.
//  Copyright (c) 2015 Black3rry. All rights reserved.

#ifndef __MENU_DIALOG_LAYER_H__
#define __MENU_DIALOG_LAYER_H__

#include "cocos2d.h"
#include "ShowGame.h"

USING_NS_CC;

class MenuDialog : public cocos2d::Layer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
	void setScore(int score);
    
    // implement the "static create()" method manually
	CREATE_FUNC(MenuDialog);
private:
	void gotoMenuScene();
	void gotoPlayScene();
	int _score;
	Label* _scoreLabel;
	Label* _highScoreLabel;
};

#endif // __MENU_DIALOG_LAYER_H__
