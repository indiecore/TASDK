#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrMainMenuContentData." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrMainMenuContentData." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrMainMenuContentData." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrMainMenuContentData : public Object
	{
	public:
			void SendPaperDollANewMesh( class TrPaperDollMainMenu* MainMenuPaperDoll, byte ContentDataType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrMainMenuContentData.SendPaperDollANewMesh" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( class TrPaperDollMainMenu** )params = MainMenuPaperDoll;
				*( byte* )( params + 4 ) = ContentDataType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PreloadTextures( float ForceDuration )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrMainMenuContentData.PreloadTextures" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = ForceDuration;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
