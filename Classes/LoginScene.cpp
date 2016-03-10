//  Created by Black3rry on 10/3/16.
//  Copyright (c) 2015 Black3rry. All rights reserved.

#include "LoginScene.h"

using namespace cocos2d::ui;

Scene* LoginScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = LoginScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool LoginScene::init()
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
    
    
    auto bkg = Sprite::create("bgr_login.jpg");
    bkg->setPosition(Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
    bkg->setScale(w/bkg->getContentSize().width, h/bkg->getContentSize().height);
    this->addChild(bkg);
    
    //hotline
    auto hotlineBtn = Button::create();
    hotlineBtn->setTitleText("Hotline : 19001755");
    hotlineBtn->setTitleFontSize(25);
    hotlineBtn->setPosition(Point(origin.x+hotlineBtn->getContentSize().width/2+15,
                                  origin.y+h-15-hotlineBtn->getContentSize().height/2));
    this->addChild(hotlineBtn);
    
    //version
    auto versionBtn = Button::create();
    versionBtn->setTitleText("Ver 1.0");
    versionBtn->setTitleFontSize(25);
    versionBtn->setPosition(Point(origin.x+w-versionBtn->getContentSize().width/2-15,
                                  origin.y+h-15-versionBtn->getContentSize().height/2));
    this->addChild(versionBtn);
    
    //girl
    auto girl = Sprite::create("girl1.png");
    girl->setPosition(Point(origin.x + visibleSize.width / 4, origin.y+girl->getContentSize().height/2));
    this->addChild(girl);
    
    //loginfacebook Button
    auto login_facebookBtn = Button::create("ic_button_login_facebook.png");
    login_facebookBtn->setTitleText("Đăng nhập facebook");
    login_facebookBtn->setTitleFontSize(30);
    login_facebookBtn->setPosition(Point(w*2/3,h/3.5f));
    this->addChild(login_facebookBtn);
    
    //đăng nhập
    auto login_Btn = Button::create("ic_button_login.png");
    login_Btn->setTitleText("Đăng nhập");
    login_Btn->setTitleFontSize(30);
    login_Btn->setPosition(Point(
                    login_facebookBtn->getPosition().x-login_facebookBtn->getContentSize().width/2+login_Btn->getContentSize().width/2,
                    login_facebookBtn->getPosition().y+login_facebookBtn->getContentSize().height/2+login_Btn->getContentSize().height/2));
    this->addChild(login_Btn);

    //đăng ký
    auto register_Btn = Button::create("ic_button_login.png");
    register_Btn->setTitleText("Đăng ký");
    register_Btn->setTitleFontSize(30);
    register_Btn->setPosition(Point(login_facebookBtn->getPosition().x,
                                    login_Btn->getPosition().y));
    register_Btn->addTouchEventListener( CC_CALLBACK_2(LoginScene::gotoRegisterScene,this) );
    this->addChild(register_Btn);
    
    //chowi ngay
    auto playNow_Btn = Button::create("ic_button_login.png");
    playNow_Btn->setTitleText("Chơi ngay");
    playNow_Btn->setTitleFontSize(30);
    playNow_Btn->setPosition(Point(
                            login_facebookBtn->getPosition().x+login_facebookBtn->getContentSize().width/2-playNow_Btn->getContentSize().width/2,
                            login_Btn->getPosition().y));
    playNow_Btn->addTouchEventListener( CC_CALLBACK_2(LoginScene::gotoPlayScene,this) );
    this->addChild(playNow_Btn);
    
    //quen mk
    auto fogotPassword = Button::create();
    fogotPassword->setTitleText("Quên mật khẩu?");
    fogotPassword->setTitleFontSize(25);
    fogotPassword->setPosition(Point(
                        login_facebookBtn->getPosition().x+login_facebookBtn->getContentSize().width/2-fogotPassword->getContentSize().width/2-5,
                        playNow_Btn->getPosition().y+playNow_Btn->getContentSize().height/2+
                            fogotPassword->getContentSize().height+10));
    this->addChild(fogotPassword);
    
    
    // Textfield mat khau
    auto background_matkhau = Sprite::create("bgr_input_login.png");
    background_matkhau->setPosition(Point(
                        login_facebookBtn->getPosition().x+10,
                        fogotPassword->getPosition().y+fogotPassword->getContentSize().height/2+
                                          background_matkhau->getContentSize().height/2+10));
    this->addChild(background_matkhau);
    
    auto textField_matkhau = ui::TextField::create("Mật khẩu", "Arial", 30);
    textField_matkhau->setAnchorPoint(Point(0,0));
    textField_matkhau->setPosition(Point(
                        background_matkhau->getPosition().x-background_matkhau->getContentSize().width/2+20,
                        background_matkhau->getPosition().y-textField_matkhau->getContentSize().height/2));
    
    this->addChild(textField_matkhau);
    
    textField_matkhau->addEventListener([](Ref* sender,ui::TextField::EventType type){
        auto textField = dynamic_cast<ui::TextField*>(sender);
        switch (type) {
            case ui::TextField::EventType::ATTACH_WITH_IME:
                //label->setString("displayed keyboard");
                CCLOG("displayed keyboard");
                break;
            case ui::TextField::EventType::DETACH_WITH_IME:
                //label->setString("dismissed keyboard");
                CCLOG("dismissed keyboard");
                break;
            case ui::TextField::EventType::INSERT_TEXT:
                //label->setString("inserted text : %s");
                CCLOG("inserted text : %s",
                      textField->getString().c_str());
                break;
            case ui::TextField::EventType::DELETE_BACKWARD:
            default: break;
        }
    });
    
    // Textfield tai khoan
    auto background_user = Sprite::create("bgr_input_login.png");
    background_user->setPosition(Point(
                    background_matkhau->getPosition().x,
                    background_matkhau->getPosition().y+background_matkhau->getContentSize().height/2+
                            background_user->getContentSize().height/2+10));
    this->addChild(background_user);
    
    auto textField_user = ui::TextField::create("Tên tài khoản", "Arial", 30);
    textField_user->setAnchorPoint(Point(0,0));
    textField_user->setPosition(Point(
                            background_user->getPosition().x-background_user->getContentSize().width/2+20,
                            background_user->getPosition().y-textField_user->getContentSize().height/2));
    
    this->addChild(textField_user);
    
    return true;
}

/*void LoginScene::gotoPlayScene()
{
	auto playscene = ShowGame::createScene();
    Director::getInstance()->replaceScene(TransitionCrossFade::create(0.25f, playscene));
    //Director::getInstance()->replaceScene(TransitionMoveInR::create(0.25f, registerscene));
}*/

void LoginScene::gotoPlayScene(cocos2d::Ref *pSender, Widget::TouchEventType eventType){
    if (cocos2d::ui::Widget::TouchEventType::BEGAN == eventType) {
        CCLOG("Button %s Clicked","game_tlmn");
        
    }
}

void LoginScene::gotoRegisterScene(cocos2d::Ref *pSender, Widget::TouchEventType eventType){
    if (cocos2d::ui::Widget::TouchEventType::BEGAN == eventType) {
        CCLOG("Button %s Clicked","game_tlmn");
        
    }
}