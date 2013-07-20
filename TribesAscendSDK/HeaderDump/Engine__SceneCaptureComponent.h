#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.SceneCaptureComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.SceneCaptureComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.SceneCaptureComponent." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class SceneCaptureComponent : public ActorComponent
	{
	public:
			ADD_VAR( ::BoolProperty, bEnabled, 0x1 )
			void SetEnabled( bool bEnable )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SceneCaptureComponent.SetEnabled" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bEnable;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::FloatProperty, MaxStreamingUpdateDist, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxViewDistanceOverride, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxUpdateDist, 0xFFFFFFFF )
			ADD_OBJECT( PostProcessChain, PostProcess )
			ADD_VAR( ::FloatProperty, FrameRate, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SceneLOD, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, ViewMode, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bSkipRenderingDepthPrepass, 0x40 )
			ADD_VAR( ::BoolProperty, bSkipUpdateIfOwnerOccluded, 0x20 )
			ADD_VAR( ::BoolProperty, bSkipUpdateIfTextureUsersOccluded, 0x10 )
			ADD_VAR( ::BoolProperty, bUseMainScenePostProcessSettings, 0x8 )
			ADD_VAR( ::BoolProperty, bEnableFog, 0x4 )
			ADD_VAR( ::BoolProperty, bEnablePostProcess, 0x2 )
			void SetFrameRate( float NewFrameRate )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.SceneCaptureComponent.SetFrameRate" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = NewFrameRate;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
