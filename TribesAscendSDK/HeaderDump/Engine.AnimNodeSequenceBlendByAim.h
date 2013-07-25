#pragma once
#include "Engine.AnimNodeSequenceBlendBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AnimNodeSequenceBlendByAim." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.AnimNodeSequenceBlendByAim." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class AnimNodeSequenceBlendByAim : public AnimNodeSequenceBlendBase
	{
	public:
		ADD_VAR(::NameProperty, AnimName_RD, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, AnimName_RC, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, AnimName_RU, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, AnimName_CD, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, AnimName_CC, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, AnimName_CU, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, AnimName_LD, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, AnimName_LC, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, AnimName_LU, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'AngleOffset'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'VerticalRange'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'HorizontalRange'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'PreviousAim'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'Aim'!
		void CheckAnimsUpToDate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNodeSequenceBlendByAim.CheckAnimsUpToDate");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
