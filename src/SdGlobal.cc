#include <assert.h>
#include "SdGlobal.h"
#include "SdMsgCenter.h"


#include "core/SdProject.h"
#include "core/SdSprite.h"
#include "core/SdAnimation.h"


SdMsgCenter* SdGlobal::m_msgCenter=NULL;
SdProject* SdGlobal::m_curProject=NULL;

SdMsgCenter* SdGlobal::getMsgCenter()
{
	return m_msgCenter;
}


SdProject* SdGlobal::getCurProject()
{
	return m_curProject;
}



void SdGlobal::setCurProject(SdProject* p)
{
	if(m_curProject)
	{
		delete m_curProject;
	}
	m_curProject=p;
}

SdSprite* SdGlobal::getCurSprite()
{
	SdProject* proj=SdGlobal::getCurProject();
	assert(proj);
	return proj->getCurSprite();
}


void SdGlobal::setCurSprite(SdSprite* sprite)
{
	SdProject* proj=SdGlobal::getCurProject();
	assert(proj);
    proj->setCurSprite(sprite);
}

SdAnimation* SdGlobal::getCurAnimation()
{
	SdSprite* sprite=SdGlobal::getCurSprite();
	assert(sprite);
	return sprite->getCurAnimation();
}

void SdGlobal::setCurAnimation(SdAnimation* anim)
{
	SdSprite* sprite=SdGlobal::getCurSprite();
	assert(sprite);
	sprite->setCurAnimation(anim);
}






void SdGlobal::moduleInit()
{
    m_msgCenter=new SdMsgCenter();
	m_curProject=NULL;
}

void SdGlobal::moduleExit()
{
	delete m_msgCenter;
	if(m_curProject)
	{
		delete m_curProject;
	}

	m_msgCenter=NULL;
	m_curProject=NULL;
}





