#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SoundClass." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SoundClass." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SoundClass : public Object
	{
	public:
		ADD_VAR(::IntProperty, MenuID, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIsChild, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct Engine.SoundClass.SoundClassProperties' for the property named 'Properties'!
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
