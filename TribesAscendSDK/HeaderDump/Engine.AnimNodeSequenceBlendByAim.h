#pragma once
#include "Engine.AnimNodeSequenceBlendBase.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class AnimNodeSequenceBlendByAim : public AnimNodeSequenceBlendBase
	{
	public:
		ADD_STRUCT(ScriptName, AnimName_RD, 436)
		ADD_STRUCT(ScriptName, AnimName_RC, 428)
		ADD_STRUCT(ScriptName, AnimName_RU, 420)
		ADD_STRUCT(ScriptName, AnimName_CD, 412)
		ADD_STRUCT(ScriptName, AnimName_CC, 404)
		ADD_STRUCT(ScriptName, AnimName_CU, 396)
		ADD_STRUCT(ScriptName, AnimName_LD, 388)
		ADD_STRUCT(ScriptName, AnimName_LC, 380)
		ADD_STRUCT(ScriptName, AnimName_LU, 372)
		ADD_STRUCT(Object::Vector2D, AngleOffset, 364)
		ADD_STRUCT(Object::Vector2D, VerticalRange, 356)
		ADD_STRUCT(Object::Vector2D, HorizontalRange, 348)
		ADD_STRUCT(Object::Vector2D, PreviousAim, 340)
		ADD_STRUCT(Object::Vector2D, Aim, 332)
		void CheckAnimsUpToDate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeSequenceBlendByAim.CheckAnimsUpToDate");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
