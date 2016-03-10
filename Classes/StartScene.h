#ifndef __START_SCENE_H__
#define __START_SCENE_H__

#include "cocos2d.h"
#include "RegisterScene.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

class StartScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
	
	// implement the "static create()" method manually
	CREATE_FUNC(StartScene);

private:
	void gotoRegisterScene();
    void touchEvent();
};

#endif // __MENU_SCENE_H__
