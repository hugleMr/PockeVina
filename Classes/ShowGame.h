#ifndef __SHOWGAME_SCENE_H__
#define __SHOWGAME_SCENE_H__

#include "cocos2d.h"
#include "CocosGUI.h"
#include "cocos-ext.h"

USING_NS_CC;

class ShowGame : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
	
	// implement the "static create()" method manually
	CREATE_FUNC(ShowGame);

private:
	void gotoPlayScene();
    void buttonPressed();
    void button1Click(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType eventType);
    void button2Click(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType eventType);
    void button3Click(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType eventType);
    void button4Click(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType eventType);
    void button5Click(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType eventType);
    void button6Click(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType eventType);
};

#endif // __SHOWGAME_SCENE_H__
