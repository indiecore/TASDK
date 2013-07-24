#pragma once
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
		// WARNING: Unknown structure type 'ScriptStruct TribesGame.TrMapMusicInfo.TrMapStingers' for the property named 'm_MapStingers'!
		// WARNING: Unknown structure type 'ScriptStruct TribesGame.TrMapMusicInfo.TrMapMusic' for the property named 'm_MapMusic'!
	};
}
#undef ADD_STRUCT
