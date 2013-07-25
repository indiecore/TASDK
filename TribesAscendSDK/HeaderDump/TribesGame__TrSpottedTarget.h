#pragma once
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrSpottedTarget." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrSpottedTarget." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrSpottedTarget." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrSpottedTarget : public Actor
	{
	public:
		ADD_OBJECT(Actor, m_SpottedActor)
		ADD_VAR(::FloatProperty, m_fLastSpottedTimestamp, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSpottedActorDuration, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'm_MarkerSize'!
		ADD_OBJECT(MaterialInstanceConstant, m_MarkerMIC)
		ADD_VAR(::FloatProperty, m_fMarkerOpacity, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMarkerZOffset, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, m_CachedTeamIndex, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
