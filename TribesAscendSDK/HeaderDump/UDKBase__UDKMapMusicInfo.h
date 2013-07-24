#pragma once
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
		// WARNING: Unknown structure type 'ScriptStruct UDKBase.UDKMapMusicInfo.StingersForAMap' for the property named 'MapStingers'!
		// WARNING: Unknown structure type 'ScriptStruct UDKBase.UDKMapMusicInfo.MusicForAMap' for the property named 'MapMusic'!
	};
}
#undef ADD_STRUCT
