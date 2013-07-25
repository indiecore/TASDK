#pragma once
#include "Engine__InterpTrackFloatBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.InterpTrackMoveAxis." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.InterpTrackMoveAxis." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class InterpTrackMoveAxis : public InterpTrackFloatBase
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Engine.InterpTrackMove.InterpLookupTrack' for the property named 'LookupTrack'!
		ADD_VAR(::ByteProperty, MoveAxis, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
