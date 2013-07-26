#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Font.FontCharacter." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class FontCharacter
	{
	public:
		ADD_VAR(::IntProperty, VerticalOffset, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, TextureIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, VSize, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, USize, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, StartV, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, StartU, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
