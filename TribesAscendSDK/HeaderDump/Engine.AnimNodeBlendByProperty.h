#pragma once
#include "Engine.AnimNodeBlendList.h"
#include "Engine.Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AnimNodeBlendByProperty." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.AnimNodeBlendByProperty." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.AnimNodeBlendByProperty." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class AnimNodeBlendByProperty : public AnimNodeBlendList
	{
	public:
		ADD_VAR(::FloatProperty, BlendToChild2Time, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BlendToChild1Time, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FloatPropMax, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FloatPropMin, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BlendTime, 0xFFFFFFFF)
		ADD_OBJECT(Actor, CachedOwner)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'CachedByteProperty'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'CachedBoolProperty'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'CachedFloatProperty'!
		ADD_VAR(::NameProperty, CachedPropertyName, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bSynchronizeNodesInEditor, 0x8)
		ADD_VAR(::BoolProperty, bUseSpecificBlendTimes, 0x4)
		ADD_VAR(::BoolProperty, bForceUpdate, 0x2)
		ADD_VAR(::BoolProperty, bUseOwnersBase, 0x1)
		ADD_VAR(::NameProperty, PropertyName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
