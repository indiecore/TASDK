#pragma once
#include "PlatformCommon__TgGameEngine.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrGameEngine." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrGameEngine : public TgGameEngine
	{
	public:
		ADD_VAR(::FloatProperty, fBGMVolume, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
