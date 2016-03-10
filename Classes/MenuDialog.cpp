//  Created by Black3rry on 10/3/16.
//  Copyright (c) 2015 Black3rry. All rights reserved.

#include "MenuDialog.h"

// on "init" you need to initialize your instance
bool MenuDialog::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
	//Background gameover
	auto overPanel = Sprite::create("Popup.png");
	overPanel->setPosition(Point(origin.x + visibleSize.width / 2, origin.y + (visibleSize.height / 3) * 2));
	
	this->addChild(overPanel);

	//Score
	//Tạo LabelTTF
	_scoreLabel = Label::createWithTTF("0", "qs.otf", 80);
	_scoreLabel->setPosition(origin.x + visibleSize.width / 2, overPanel->getPositionY() + overPanel->getContentSize().height / 4);

	this->addChild(_scoreLabel);

	_highScoreLabel = Label::createWithTTF("0", "qs.otf", 20);
	_highScoreLabel->setPosition(origin.x + visibleSize.width / 2, _scoreLabel->getPositionY() - _highScoreLabel->getContentSize().height - 30);

	this->addChild(_highScoreLabel);

	//Button
	auto menuBtn = MenuItemImage::create("MenuBtn.png", "MenuBtnSelected.png", CC_CALLBACK_0(MenuDialog::gotoMenuScene, this));
	auto replayBtn = MenuItemImage::create("AgainBtn.png", "AgainBtnSelected.png", CC_CALLBACK_0(MenuDialog::gotoPlayScene, this));

	auto menu = Menu::create(menuBtn, replayBtn, nullptr);
	menu->alignItemsHorizontallyWithPadding(50);
	menu->setPosition(origin.x + visibleSize.width / 2, overPanel->getPositionY() - overPanel->getContentSize().height / 2 + menuBtn->getContentSize().height);

	this->addChild(menu);
    
    return true;
}

void MenuDialog::gotoMenuScene()
{
	//auto menuscene = MenuScene::createScene();
	//Director::getInstance()->replaceScene(TransitionMoveInL::create(0.25f, menuscene));
}

void MenuDialog::gotoPlayScene()
{
    auto moveTo = MoveTo::create(0.25f, Vec2(0,this->getContentSize().height));
    auto callFunc = CallFunc::create([]{
        auto playscene = ShowGame::createScene();
        Director::getInstance()->replaceScene(playscene);
    });
    auto sequence = Sequence::create(moveTo,callFunc, NULL);
    this->runAction(sequence);
	
}
void MenuDialog::setScore(int score)
{
	_score = score;

	auto userdefault = UserDefault::getInstance();
	auto highscore = userdefault->getIntegerForKey("HIGHSCORE", 0);

	if (_score > highscore)
	{
		highscore = _score;
		userdefault->setIntegerForKey("HIGHSCORE", highscore);
	}

	userdefault->flush();

	_scoreLabel->setString(StringUtils::format("%d", _score));
	_highScoreLabel->setString(StringUtils::format("HIGH SCORE: %d", highscore));
}