#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.GFxTrPage_WatchNow." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.GFxTrPage_WatchNow." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.GFxTrPage_WatchNow." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxTrPage_WatchNow : public GFxTrPage
	{
	public:
			ADD_VAR( ::StrProperty, strCmntyVideos, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, strTrainVideos, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, strHiRezVideos, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, strLiveStreams, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NumCmntyVideos, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NumTrainVideos, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NumHiRezVideos, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NumLiveStreams, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
