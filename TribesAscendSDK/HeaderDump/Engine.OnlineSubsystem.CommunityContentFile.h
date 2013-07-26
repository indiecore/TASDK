#pragma once
#include "Engine.OnlineSubsystem.UniqueNetId.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " OnlineSubsystem.CommunityContentFile." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty OnlineSubsystem.CommunityContentFile." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class CommunityContentFile
	{
	public:
		ADD_VAR(::IntProperty, ContentId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, FileId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ContentType, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, FileSize, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<UniqueNetId>, Owner, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, DownloadCount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AverageRating, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, RatingCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LastRatingGiven, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, LocalFilePath, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
