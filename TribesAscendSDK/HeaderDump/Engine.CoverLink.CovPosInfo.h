#pragma once
#include "Engine.CoverLink.h"
#include "Core.Object.Vector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " CoverLink.CovPosInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty CoverLink.CovPosInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty CoverLink.CovPosInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class CovPosInfo
	{
	public:
		ADD_OBJECT(CoverLink, Link)
		ADD_VAR(::IntProperty, LtSlotIdx, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, RtSlotIdx, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LtToRtPct, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, Location, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, Normal, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, Tangent, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
