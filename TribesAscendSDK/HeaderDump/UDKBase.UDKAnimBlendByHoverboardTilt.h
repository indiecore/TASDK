#pragma once
#include "Engine.AnimNodeBlendBase.h"
#include "Core.Object.Vector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKAnimBlendByHoverboardTilt." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UDKBase.UDKAnimBlendByHoverboardTilt." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKAnimBlendByHoverboardTilt : public AnimNodeBlendBase
	{
	public:
		ADD_VAR(::NameProperty, UpperBodyName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TiltYScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TiltDeadZone, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TiltScale, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, UpVector, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
