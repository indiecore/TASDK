#pragma once
#include "TribesGame.TrMapMusicInfo.h"
#include "UDKBase.UDKMapInfo.h"
#include "TribesGame.TrInvalidDeployableVolume.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class TrMapInfo : public UDKMapInfo
	{
	public:
		ADD_STRUCT(ScriptName, m_DefaultPhysicalMaterialName, 104)
		ADD_OBJECT(ScriptClass, m_WeatherEffect, 112)
		ADD_STRUCT(ScriptArray<class TrInvalidDeployableVolume*>, m_BEInvalidDeployableVolumes, 68)
		ADD_STRUCT(ScriptArray<class TrInvalidDeployableVolume*>, m_DSInvalidDeployableVolumes, 80)
		ADD_STRUCT(ScriptArray<class TrInvalidDeployableVolume*>, m_NeutralInvalidDeployableVolumes, 92)
		ADD_OBJECT(TrMapMusicInfo, m_MapMusicInfo, 64)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
