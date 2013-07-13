#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.GameUISceneClient." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.GameUISceneClient." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.GameUISceneClient." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GameUISceneClient : public UISceneClient
	{
	public:
			ADD_VAR( ::BoolProperty, bCaptureUnprocessedInput, 0x10 )
			ADD_VAR( ::BoolProperty, bRenderDebugInfo, 0x8 )
			ADD_VAR( ::BoolProperty, bEnableDebugInput, 0x4 )
			ADD_VAR( ::BoolProperty, bUpdateSceneViewportSizes, 0x2 )
			ADD_VAR( ::BoolProperty, bUpdateInputProcessingStatus, 0x1 )
			ADD_VAR( ::FloatProperty, LatestDeltaTime, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
