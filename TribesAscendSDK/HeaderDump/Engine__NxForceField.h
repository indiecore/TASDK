#pragma once
#include "Engine__SeqAct_Toggle.h"
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.NxForceField." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.NxForceField." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class NxForceField : public Actor
	{
	public:
		ADD_VAR(::IntProperty, SceneIndex, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'U2NRotation'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'ForceField'!
		ADD_VAR(::ByteProperty, RBChannel, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.PrimitiveComponent.RBCollisionChannelContainer' for the property named 'CollideWithChannels'!
		ADD_VAR(::BoolProperty, bForceActive, 0x1)
		ADD_VAR(::IntProperty, ExcludeChannel, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'DoInitRBPhys'
		// Here lies the not-yet-implemented method 'OnToggle'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
