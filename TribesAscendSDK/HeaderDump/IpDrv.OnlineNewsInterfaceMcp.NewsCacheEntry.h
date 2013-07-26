#pragma once
#include "Core.Object.Pointer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " OnlineNewsInterfaceMcp.NewsCacheEntry." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty OnlineNewsInterfaceMcp.NewsCacheEntry." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class NewsCacheEntry
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, HttpDownloader, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIsUnicode, 0x1)
		ADD_VAR(::FloatProperty, TimeOut, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, NewsItem, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, NewsType, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, ReadState, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, NewsUrl, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
