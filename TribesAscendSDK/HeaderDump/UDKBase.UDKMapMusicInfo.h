#pragma once
#include "Core.Object.h"
#include "UDKBase.UDKMapMusicInfo.StingersForAMap.h"
#include "UDKBase.UDKMapMusicInfo.MusicForAMap.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UDKBase.UDKMapMusicInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKMapMusicInfo : public Object
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<StingersForAMap>, MapStingers, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<MusicForAMap>, MapMusic, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
