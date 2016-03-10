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
    
    
    auto bkg = Sprite::create("bg.png");
    bkg->setPosition(Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
    bkg->setScale(w/bkg->getContentSize().width, h/bkg->getContentSize().height);
    bkg->setColor(Color3B(30, 164,68));
    this->addChild(bkg);

    /////////////////////////////
	/*auto menuBG = Sprite::create("MenuSceneBG.png");
	menuBG->setPosition(Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
	this->addChild(menuBG);
     */
    
    //regis Button
	auto regisBtn = MenuItemImage::create("register.png", "register.png", CC_CALLBACK_0(RegisterScene::gotoPlayScene, this));
	auto regisBtnMenu = Menu::create(regisBtn, nullptr);
	regisBtnMenu->setPosition(Point(origin.x + visibleSize.width-50-regisBtn->getContentSize().width/2,
                            origin.y + visibleSize.height / 3));
	this->addChild(regisBtnMenu);
    
    // nhap lai mat khau
    auto nhaplaiBtn = MenuItemImage::create("button_text_hidden.png", "button_text_hidden.png", CC_CALLBACK_0(RegisterScene::gotoPlayScene, this));
    auto nhaplaiBtnMenu = Menu::create(nhaplaiBtn, nullptr);
    nhaplaiBtnMenu->setPosition(Point(
                            origin.x + visibleSize.width-50-nhaplaiBtn->getContentSize().width/2,
                            origin.y + visibleSize.height / 2));
    this->addChild(nhaplaiBtnMenu);
    
    // nhap mat khau
    auto nhapMkBtn = MenuItemImage::create("button_text_hidden.png", "button_text_hidden.png", CC_CALLBACK_0(RegisterScene::gotoPlayScene, this));
    auto nhapMkBtnMenu = Menu::create(nhapMkBtn, nullptr);
    nhapMkBtnMenu->setPosition(Point(origin.x + visibleSize.width-50-nhapMkBtn->getContentSize().width/2,
                                      origin.y + visibleSize.height*2 / 3));
    this->addChild(nhapMkBtnMenu);
    
    // nhap sdt
    auto nhapSdtBtn = MenuItemImage::create("button_text_hidden.png", "button_text_hidden.png", CC_CALLBACK_0(RegisterScene::gotoPlayScene, this));
    auto nhapSdtBtnMenu = Menu::create(nhapSdtBtn, nullptr);
    nhapSdtBtnMenu->setPosition(Point(
                                      origin.x + visibleSize.width-50-nhapSdtBtn->getContentSize().width/2,
                                      origin.y + visibleSize.height*5 / 6));
    this->addChild(nhapSdtBtnMenu);


    return true;
}

void RegisterScene::gotoPlayScene()
{
	auto playscene = ShowGame::createScene();
    Director::getInstance()->replaceScene(TransitionCrossFade::create(0.25f, playscene));
    //Director::getInstance()->replaceScene(TransitionMoveInR::create(0.25f, registerscene));
}
