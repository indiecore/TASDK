#pragma once
#include "Core.Object.Pointer.h"
#include "Engine.OnlineSubsystem.TitleFile.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty OnlineTitleFileDownloadMcp.TitleFileMcp." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TitleFileMcp : public TitleFile
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, HttpDownloader, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
