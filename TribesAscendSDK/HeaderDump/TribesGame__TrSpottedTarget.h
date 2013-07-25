#pragma once
#include "Engine__Actor.h"
#include "Engine__MaterialInstanceConstant.h"
#include "Engine__Texture2D.h"
#include "Engine__Canvas.h"
#include "Engine__PlayerController.h"
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
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'SetSpottedActor'
		// Here lies the not-yet-implemented method 'PostRenderFor'
		// Here lies the not-yet-implemented method 'ShouldRenderMarker'
		// Here lies the not-yet-implemented method 'GetMarker'
		// Here lies the not-yet-implemented method 'GetMarkerColor'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
