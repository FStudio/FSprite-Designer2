#ifndef _SD_ANIMATION_H_
#define _SD_ANIMATION_H_ 

#include <string>
#include <vector>

#include "core/SdIdentify.h"

class SdTimeLine;
class SdSprite;

class SdAnimationAttribute
{
	public:
		std::string name;
		int playSpeed;
};

class SdAnimation :public SdIdentify
{
	public:
		SdAnimation(const std::string& name);
		~SdAnimation();

	public:
		int getClassType();
		const char* className();

	public:
		void setName(const std::string& name);
		std::string getName();

		SdSprite* getSprite();
		void setSprite(SdSprite* sprite);

		SdTimeLine* createTimeLine(const std::string& name);
		void removeTimeLine(SdTimeLine* line);
		void addTimeLine(int pos,SdTimeLine* line);
		void addTimeLine(SdTimeLine* line);


		int getTimeLineNu();
		SdTimeLine* getTimeLine(int index);

		bool hasTimeLineWithName(const std::string& name);
		bool hasTimeLine(SdTimeLine* line);

		int getTimeLinePos(SdTimeLine* line);

		void setPlaySpeed(int fps);
		int getPlaySpeed();

		void setAttribute(const SdAnimationAttribute& attr);

		SdAnimationAttribute getAttribute();



	private:
		SdSprite* m_sprite;
		SdAnimationAttribute m_attr;
		std::vector<SdTimeLine*> m_timelines;
};

#endif /*_SD_ANIMATION_H_*/

