#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.InterpActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.InterpActor." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class InterpActor : public DynamicSMActor
	{
	public:
		ADD_VAR(::BoolProperty, bMonitorMover, 0x2)
		ADD_OBJECT(NavigationPoint, MyMarker)
		ADD_OBJECT(SoundCue, ClosedSound)
		ADD_OBJECT(SoundCue, ClosingAmbientSound)
		ADD_OBJECT(SoundCue, CloseSound)
		ADD_OBJECT(SoundCue, OpenedSound)
		ADD_OBJECT(SoundCue, OpeningAmbientSound)
		ADD_OBJECT(SoundCue, OpenSound)
		ADD_VAR(::FloatProperty, StayOpenTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxZVelocity, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIsLift, 0x80)
		ADD_VAR(::BoolProperty, bShouldShadowParentAllAttachedActors, 0x40)
		ADD_VAR(::BoolProperty, bStopOnEncroach, 0x20)
		ADD_VAR(::BoolProperty, bContinueOnEncroachPhysicsObject, 0x10)
		ADD_VAR(::BoolProperty, bDestroyProjectilesOnEncroach, 0x8)
		ADD_VAR(::BoolProperty, bMonitorZVelocity, 0x4)
		ADD_VAR(::BoolProperty, bShouldSaveForCheckpoint, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
