#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.Texture2DComposite." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.Texture2DComposite." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.Texture2DComposite." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class Texture2DComposite : public Texture
	{
	public:
			ADD_VAR( ::IntProperty, MaxTextureSize, 0xFFFFFFFF )
			bool SourceTexturesFullyStreamedIn(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Texture2DComposite.SourceTexturesFullyStreamedIn" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void UpdateCompositeTexture( int NumMipsToGenerate )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Texture2DComposite.UpdateCompositeTexture" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = NumMipsToGenerate;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ResetSourceRegions(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Texture2DComposite.ResetSourceRegions" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
