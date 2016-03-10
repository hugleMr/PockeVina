#include "ShowGame.h"

#define BUTTON_1 1
#define BUTTON_2 2
#define BUTTON_3 3
#define BUTTON_4 4
#define BUTTON_5 5
#define BUTTON_6 6

using namespace cocos2d::ui;

Scene* ShowGame::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = ShowGame::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool ShowGame::init()
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
    bkg->setColor(Color3B(52, 30, 164));
    this->addChild(bkg);

    // btn back
    auto backBtn = MenuItemImage::create("button_image.png", "button_image.png", CC_CALLBACK_0(ShowGame::gotoPlayScene, this));
    auto backBtnMenu = Menu::create(backBtn, nullptr);
    backBtnMenu->setPosition(Point(
                            origin.x +10+backBtn->getContentSize().width/2,
                            origin.y + visibleSize.height-10- backBtn->getContentSize().height/2));
    this->addChild(backBtnMenu);
    
    //btn Menu
    // btn back
    auto menukBtn = MenuItemImage::create("button_image.png", "button_image.png", CC_CALLBACK_0(ShowGame::gotoPlayScene, this));
    auto menuBtnMenu = Menu::create(menukBtn, nullptr);
    menuBtnMenu->setPosition(Point(
                                   origin.x +w-10-menukBtn->getContentSize().width/2,
                                   origin.y + visibleSize.height-10- menukBtn->getContentSize().height/2));
    this->addChild(menuBtnMenu);
    
    //add scroll view
    Size scollFrameSize = Size(visibleSize.width, visibleSize.height/2);
    auto scrollView = ScrollView::create();
    scrollView->setContentSize(scollFrameSize);
   
    scrollView->setPosition(Point(0, visibleSize.height*1/6));
    scrollView->setDirection(ScrollView::Direction::HORIZONTAL);
    scrollView->setScrollBarEnabled(false);
    scrollView->setBounceEnabled(true);
    scrollView->setInertiaScrollEnabled(true);
    scrollView->setTouchEnabled(true);
    auto containerSize = Size(scollFrameSize.width*1.5f, scollFrameSize.height);
    scrollView->setInnerContainerSize(containerSize);
    
    this->addChild(scrollView);
    
    float widthFixScroll = containerSize.width - 40;
    
    auto button1 = Button::create("item.png");
    button1->setTouchEnabled(true);
    button1->addTouchEventListener( CC_CALLBACK_2(ShowGame::button1Click, this) );
   // button1->loadTextures("item.png", "item.png");
    button1->setPosition(Point(widthFixScroll-button1->getContentSize().width/2,
                               containerSize.height/2));
    scrollView->addChild(button1);
    
    auto button2 = Button::create("item.png");
    button2->setTouchEnabled(true);
    button2->addTouchEventListener( CC_CALLBACK_2(ShowGame::button2Click, this) );
    //button2->loadTextures("item.png", "item.png");
    button2->setPosition(Point(widthFixScroll*5/6-button1->getContentSize().width/2,
                               containerSize.height / 2));
    scrollView->addChild(button2);
    
    auto button3 = Button::create("item.png");
    button3->setTouchEnabled(true);
    button3->addTouchEventListener( CC_CALLBACK_2(ShowGame::button3Click, this) );
    //button3->loadTextures("item.png", "item.png");
    button3->setPosition(Point(widthFixScroll*4/6-button1->getContentSize().width/2,
                               containerSize.height / 2));
    scrollView->addChild(button3);
    
    auto button4 = Button::create("item.png");
    button4->setTouchEnabled(true);
    button4->addTouchEventListener( CC_CALLBACK_2(ShowGame::button4Click, this) );
    //button4->loadTextures("item.png", "item.png");
    button4->setPosition(Point(widthFixScroll*3/6-button1->getContentSize().width/2,
                               containerSize.height / 2));
    scrollView->addChild(button4);

    auto button5 = Button::create("item.png");
    button5->setTouchEnabled(true);
    button5->addTouchEventListener( CC_CALLBACK_2(ShowGame::button5Click, this) );
    //button5->loadTextures("item.png", "item.png");
    button5->setPosition(Point(widthFixScroll*2/6-button1->getContentSize().width/2,
                               containerSize.height / 2));
    scrollView->addChild(button5);
    
    auto button6 = Button::create("item.png");
    button6->setTouchEnabled(true);
    button6->addTouchEventListener( CC_CALLBACK_2(ShowGame::button6Click, this) );
    ///button6->loadTextures("item.png", "item.png");
    button6->setPosition(Point(widthFixScroll*1/6-button1->getContentSize().width/2,
                               containerSize.height / 2));
    scrollView->addChild(button6);
    
    CCLOG("Created");

    return true;
}

void ShowGame::button1Click(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType eventType){
    if (cocos2d::ui::Widget::TouchEventType::ENDED == eventType) {
        CCLOG("Button %d Clicked",1);
    }
    
}

void ShowGame::button2Click(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType eventType){
    if (cocos2d::ui::Widget::TouchEventType::ENDED == eventType) {
        CCLOG("Button %d Clicked",1);
    }
}

void ShowGame::button3Click(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType eventType){
    if (cocos2d::ui::Widget::TouchEventType::ENDED == eventType) {
        CCLOG("Button %d Clicked",1);
    }
}

void ShowGame::button4Click(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType eventType){
    if (cocos2d::ui::Widget::TouchEventType::ENDED == eventType) {
        CCLOG("Button %d Clicked",1);
    }
}

void ShowGame::button5Click(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType eventType){
    if (cocos2d::ui::Widget::TouchEventType::ENDED == eventType) {
        CCLOG("Button %d Clicked",1);
    }
}

void ShowGame::button6Click(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType eventType){
    if (cocos2d::ui::Widget::TouchEventType::ENDED == eventType) {
        CCLOG("Button %d Clicked",1);
    }
}


void ShowGame::gotoPlayScene()
{
	//auto playscene = PlayScene::createScene();
//	Director::getInstance()->replaceScene(playscene);
}
