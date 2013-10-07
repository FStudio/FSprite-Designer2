#ifndef _SD_DATA_OPERATOR_H_
#define _SD_DATA_OPERATOR_H_ 

class SdProject;
class SdSprite;
class SdAnimation;
class SdDataOperator 
{
	public:
		SdDataOperator();
		~SdDataOperator();

	public:
		SdProject* getCurProject();
		void setCurProject(SdProject* proj);

		/* sprite */
		void setCurSprite(SdSprite* sprite);
		SdSprite* getCurSprite();

		void addSprite(SdProject* proj,SdSprite* sprite);
		void addSprite(SdProject* proj,SdSprite* sprite,int pos);
        void removeSprite(SdProject* proj,SdSprite* sprite);


		void setSpriteName(const char* name);
		void setSpriteName(SdSprite* sprite,const char* name);


		void setCurAnimation(SdAnimation* anim);
		SdAnimation* getCurAnimation();


		/* redo/undo */

        bool canRedo();
        bool canUndo();
		void redo();
		void undo();
};




#endif /*_SD_DATA_OPERATOR_H_*/

