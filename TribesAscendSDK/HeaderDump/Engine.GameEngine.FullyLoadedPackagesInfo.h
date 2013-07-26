#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameEngine.FullyLoadedPackagesInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class FullyLoadedPackagesInfo
	{
	public:
		ADD_VAR(::StrProperty, Tag, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, FullyLoadType, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
