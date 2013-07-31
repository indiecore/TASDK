#pragma once
#include "Core.Object.h"
namespace UnrealScript
{
	class GFxTrMenuSounds : public Object
	{
	public:
		enum EMenuSound : byte
		{
			EMS_CLASS_ROLLOVER = 0,
			EMS_CLASS_SELECTED = 1,
			EMS_CLASS_UNLOCKED = 2,
			EMS_CLASS_DENIED = 3,
			EMS_SKILL_ROLLOVER = 4,
			EMS_SKILL_SELECTED = 5,
			EMS_SKILL_UNLOCKED = 6,
			EMS_QUEUE_SELECTED = 7,
			EMS_QUEUE_EXIT = 8,
			EMS_TOOLTIP_OPEN = 9,
			EMS_TOOLTIP_CLOSE = 10,
			EMS_XP_GAIN = 11,
			EMS_XP_POINT_POSITIVE = 12,
			EMS_XP_POINT_NEGATIVE = 13,
			EMS_PAGE_FORWARD = 14,
			EMS_PAGE_BACK = 15,
			EMS_MAX = 16,
		};
		void SoundToolTip(bool bOpened)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56597);
			byte params[4] = { NULL };
			*(bool*)params = bOpened;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SoundXPGain(int val)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56599);
			byte params[4] = { NULL };
			*(int*)params = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SoundSkillType(int val)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56601);
			byte params[4] = { NULL };
			*(int*)params = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SoundClassType(int val)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56603);
			byte params[4] = { NULL };
			*(int*)params = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SoundPurchaseSkill()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56605);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SoundSelectedQueue()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56606);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void LeaveQueue()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56607);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PageForward()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56608);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PageBack()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56609);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClassRollover()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56610);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClassSelected()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56611);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClassLocked()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56612);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayMenuSound(GFxTrMenuSounds::EMenuSound MenuSound)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56613);
			byte params[1] = { NULL };
			*(GFxTrMenuSounds::EMenuSound*)params = MenuSound;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
