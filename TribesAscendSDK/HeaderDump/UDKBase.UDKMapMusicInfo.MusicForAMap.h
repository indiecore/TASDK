#pragma once
#include "UDKBase.UDKMapMusicInfo.MusicSegment.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKMapMusicInfo.MusicForAMap." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UDKMapMusicInfo.MusicForAMap." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class MusicForAMap
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<MusicSegment>, Victory, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<MusicSegment>, Tension, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<MusicSegment>, Suspense, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<MusicSegment>, Intro, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<MusicSegment>, Ambient, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<MusicSegment>, Action, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Tempo, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
