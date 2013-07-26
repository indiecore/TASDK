#pragma once
#include "UDKBase.UDKMapMusicInfo.h"
#include "TribesGame.TrMapMusicInfo.TrMapStingers.h"
#include "TribesGame.TrMapMusicInfo.TrMapMusic.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrMapMusicInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrMapMusicInfo : public UDKMapMusicInfo
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<TrMapStingers>, m_MapStingers, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<TrMapMusic>, m_MapMusic, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
