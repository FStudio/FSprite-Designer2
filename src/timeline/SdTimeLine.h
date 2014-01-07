#ifndef _SD_TIME_LINE_H_
#define _SD_TIME_LINE_H_

#include <string>
#include "SdSubTimeLine.h"

class SdTimeLineUiData;

class SdSubTimeLineSet;

class SdAnimation;
class SdTimeLine 
{
	public:
		SdTimeLine(const std::string& name);
		~SdTimeLine();

	public:
		void setName(const std::string& name);
		std::string getName();

		bool getVisible();
		void setVisible(bool v);

		bool getSelect();
		void setSelect(bool v);

		bool getExpand();
		void setExpand(bool expand);




	private:
		bool m_visible;
		bool m_select;
		bool m_expand;

		std::string m_name;

		/* Sub Time Line */
		SdSubTimeLineSet* m_subTimeSet;

		/* Animation */
		SdAnimation* m_animation;
};


#endif /*_SD_TIME_LINE_H_*/

