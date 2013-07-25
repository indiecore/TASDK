#pragma once
#include "TribesGame.TrMapMusicInfo.h"
#include "UDKBase.UDKMapInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrMapInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrMapInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrMapInfo : public UDKMapInfo
	{
	public:
		ADD_VAR(::NameProperty, m_DefaultPhysicalMaterialName, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, m_WeatherEffect)
		ADD_OBJECT(TrMapMusicInfo, m_MapMusicInfo)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
