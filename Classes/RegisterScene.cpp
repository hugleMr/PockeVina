//  Created by Black3rry on 10/3/16.
//  Copyright (c) 2015 Black3rry. All rights reserved.

#include "RegisterScene.h"

Scene* RegisterScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = RegisterScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool RegisterScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    float w = visibleSize.width;
    float h = visibleSize.height;
    
    
    auto bkg = Sprite::create("bgr_register.jpg");
    bkg->setPosition(Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
    bkg->setScale(w/bkg->getContentSize().width, h/bkg->getContentSize().height);
    bkg->setColor(Color3B(52, 30, 164));
    this->addChild(bkg);
    
    auto bigken = Sprite::create("bigken_logo.png");
    bigken->setPosition(Point(origin.x+bigken->getContentSize().width/2+20,
                              origin.y+h-bigken->getContentSize().height-20));
    this->addChild(bigken);
    
    auto girl = Sprite::create("girl2.png");
    girl->setPosition(Point(origin.x+visibleSize.width/6+girl->getContentSize().width/2,origin.y+girl->getContentSize().height/2));
    this->addChild(girl);
    
    /////////////////////////////
	/*auto menuBG = Sprite::create("MenuSceneBG.png");
	menuBG->setPosition(Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
	this->addChild(menuBG);
     */
    
    //regis Button
	auto regisBtn = MenuItemImage::create("ic_button_register.png", "ic_button_register.png", CC_CALLBACK_0(RegisterScene::gotoRegisterScene, this));
	auto regisBtnMenu = Menu::create(regisBtn, nullptr);
	regisBtnMenu->setPosition(Point(origin.x + visibleSize.width-50-regisBtn->getContentSize().width/2,
                            origin.y + visibleSize.height / 3));
	this->addChild(regisBtnMenu);
    
    // nhap lai mat khau
    auto nhaplaiBtn = MenuItemImage::create("ic_button_password.png", "ic_button_password.png", CC_CALLBACK_0(RegisterScene::gotoRegisterScene, this));
    auto nhaplaiBtnMenu = Menu::create(nhaplaiBtn, nullptr);
    nhaplaiBtnMenu->setPosition(Point(
                            origin.x + visibleSize.width-50-nhaplaiBtn->getContentSize().width/2,
                            origin.y + visibleSize.height / 2));
    this->addChild(nhaplaiBtnMenu);
    
    // nhap mat khau
    auto nhapMkBtn = MenuItemImage::create("ic_button_password.png", "ic_button_password.png", CC_CALLBACK_0(RegisterScene::gotoRegisterScene, this));
    auto nhapMkBtnMenu = Menu::create(nhapMkBtn, nullptr);
    nhapMkBtnMenu->setPosition(Point(origin.x + visibleSize.width-50-nhapMkBtn->getContentSize().width/2,
                                      origin.y + visibleSize.height*2 / 3));
    this->addChild(nhapMkBtnMenu);
    
    // nhap sdt
    auto nhapSdtBtn = MenuItemImage::create("ic_button_isdn.png", "ic_button_isdn.png", CC_CALLBACK_0(RegisterScene::gotoRegisterScene, this));
    auto nhapSdtBtnMenu = Menu::create(nhapSdtBtn, nullptr);
    nhapSdtBtnMenu->setPosition(Point(
                                      origin.x + visibleSize.width-50-nhapSdtBtn->getContentSize().width/2,
                                      origin.y + visibleSize.height*5 / 6));
    
    
    //======
    
    
    
    auto nhapSdtText = cocos2d::ui::TextField::create("Số điện thoại...","Arial",39);
    // make this TextField password enabled
    //nhapSdtText->setPasswordEnabled(true);
    
    // set the maximum number of characters the user can enter for this TextField
    nhapSdtText->setMaxLength(11);
    nhapSdtText->setTextHorizontalAlignment(cocos2d::TextHAlignment::LEFT);
    nhapSdtText->setTextVerticalAlignment(cocos2d::TextVAlignment::CENTER);
    //nhapSdtText->addEventListener(CC_CALLBACK_2(StartScene::textFieldEvent,this));
    
    nhapSdtBtnMenu->addChild(nhapSdtText);
    this->addChild(nhapSdtBtnMenu);


    return true;
}

void RegisterScene::gotoRegisterScene()
{
	//auto registerscene = RegisterScene::createScene();
	//Director::getInstance()->replaceScene(TransitionMoveInR::create(0.25f, registerscene));
}
