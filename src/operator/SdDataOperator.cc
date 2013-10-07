#include <assert.h>
#include "operator/SdDataOperator.h"
#include "core/SdProject.h"
#include "core/SdSprite.h"
#include "SdGlobal.h"
#include "command/SdCommand.h"
#include "command/SdSpriteAttrChangeCommand.h"
#include "command/SdSpriteAddCommand.h"
#include "command/SdSpriteRemoveCommand.h"


SdDataOperator::SdDataOperator()
{
}


SdDataOperator::~SdDataOperator()
{

}

SdProject* SdDataOperator::getCurProject()
{
	return SdGlobal::getCurProject();
}

void SdDataOperator::setCurProject(SdProject* proj)
{
	SdGlobal::setCurProject(proj);
	/* emit signal */
}

/* cur sprite */
SdSprite* SdDataOperator::getCurSprite()
{
	return SdGlobal::getCurSprite();
}

void SdDataOperator::setCurSprite(SdSprite* sprite)
{
	SdGlobal::setCurSprite(sprite);
	/* emit signal */
}


void SdDataOperator::addSprite(SdProject* proj,SdSprite* sprite)
{
	addSprite(proj,sprite,proj->getSpriteNu());
}


void SdDataOperator::addSprite(SdProject* proj,SdSprite* sprite,int pos)
{
	SdSpriteAddCommand* cmd=new SdSpriteAddCommand(proj,sprite,pos);
	proj->pushCommand(cmd);
	cmd->redo();
	cmd->emitRedoSignal();
}

void SdDataOperator::removeSprite(SdProject* proj,SdSprite* sprite)
{
    SdSpriteRemoveCommand* cmd=new SdSpriteRemoveCommand(proj,sprite);
    proj->pushCommand(cmd);
    cmd->redo();
    cmd->emitRedoSignal();
}



void SdDataOperator::setSpriteName(const char* name)
{
    SdSprite* sprite=getCurSprite();
	assert(sprite);
	setSpriteName(sprite,name);
}
void SdDataOperator::setSpriteName(SdSprite* sprite,const char* name)
{

	SdProject* proj=getCurProject();

    SdSpriteAttribute attr_old=sprite->getAttribute();
    SdSpriteAttribute attr_new=sprite->getAttribute();

    attr_new.name=std::string(name);

	SdSpriteAttrChangeCommand* cmd=new SdSpriteAttrChangeCommand(sprite,attr_old,attr_new);

	proj->pushCommand(cmd);
	cmd->redo();
	cmd->emitRedoSignal();
}



/* cur animation */
SdAnimation* SdDataOperator::getCurAnimation()
{
	return SdGlobal::getCurAnimation();
}


void SdDataOperator::setCurAnimation(SdAnimation* anim)
{
	SdGlobal::setCurAnimation(anim);
	/* emit signal */
}



/* redo/undo */


bool SdDataOperator::canRedo()
{
	return SdGlobal::canRedo();
}

bool SdDataOperator::canUndo()
{
	return SdGlobal::canUndo();
}

void SdDataOperator::redo()
{
	assert(canRedo());

	SdProject* proj=getCurProject();
	SdCommand* command=proj->redo();
	command->emitRedoSignal();
}

void SdDataOperator::undo()
{
	assert(canUndo());
	SdProject* proj=getCurProject();
	SdCommand* command=proj->undo();
	command->emitUndoSignal();
}




























