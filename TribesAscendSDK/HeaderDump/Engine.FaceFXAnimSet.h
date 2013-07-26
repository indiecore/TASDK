#pragma once
#include "Core.Object.h"
#include "Core.Object.Pointer.h"
#include "Engine.FaceFXAsset.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.FaceFXAnimSet." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.FaceFXAnimSet." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.FaceFXAnimSet." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class FaceFXAnimSet : public Object
	{
	public:
		ADD_VAR(::IntProperty, NumLoadErrors, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, InternalFaceFXAnimSet, 0xFFFFFFFF)
		ADD_OBJECT(FaceFXAsset, DefaultFaceFXAsset)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
