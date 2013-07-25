#pragma once
#include "Engine__PathConstraint.h"
#include "Engine__Pawn.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.Path_AlongLine." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class Path_AlongLine : public PathConstraint
	{
	public:
		ADD_STRUCT(::VectorProperty, Direction, 0xFFFFFFFF
		bool AlongLine(class Pawn* P, Vector Dir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Path_AlongLine.AlongLine");
			byte* params = (byte*)malloc(20);
			*(class Pawn**)params = P;
			*(Vector*)(params + 4) = Dir;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void Recycle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Path_AlongLine.Recycle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
