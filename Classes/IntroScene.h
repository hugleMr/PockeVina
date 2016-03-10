//  Created by Black3rry on 10/3/16.
//  Copyright (c) 2015 Black3rry. All rights reserved.

#ifndef __INTRO_SCENE_H__
#define __INTRO_SCENE_H__

#include "cocos2d.h"
#include "LoginScene.h"

USING_NS_CC;

class IntroScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
	CREATE_FUNC(IntroScene);
private:
	void gotoStartScene(float dt);
};

#endif // __INTRO_SCENE_H__
