#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " GFxUI.GFxAction_OpenMovie." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty GFxUI.GFxAction_OpenMovie." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty GFxUI.GFxAction_OpenMovie." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxAction_OpenMovie : public SequenceAction
	{
	public:
			ADD_OBJECT( TextureRenderTarget2D, RenderTexture )
			ADD_VAR( ::ByteProperty, RenderTextureMode, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bDisplayWithHudOff, 0x10 )
			ADD_VAR( ::BoolProperty, bEnableGammaCorrection, 0x8 )
			ADD_VAR( ::BoolProperty, bStartPaused, 0x4 )
			ADD_VAR( ::BoolProperty, bCaptureInput, 0x2 )
			ADD_VAR( ::BoolProperty, bTakeFocus, 0x1 )
			ADD_OBJECT( GFxMoviePlayer, MoviePlayer )
			ADD_OBJECT( ScriptClass, MoviePlayerClass )
			ADD_OBJECT( SwfMovie, Movie )
			bool IsValidLevelSequenceObject(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GFxUI.GFxAction_OpenMovie.IsValidLevelSequenceObject" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
