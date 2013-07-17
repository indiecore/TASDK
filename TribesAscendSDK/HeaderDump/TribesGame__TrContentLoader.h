#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrContentLoader." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrContentLoader." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrContentLoader." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrContentLoader : public Object
	{
	public:
			bool StartLoadingDeviceContentPackage( ScriptClass* WeaponClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrContentLoader.StartLoadingDeviceContentPackage" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )( params + 0 ) = WeaponClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void StartLoadingPlayerSkin( int ClassId, int skinId, bool bLoad1PData )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrContentLoader.StartLoadingPlayerSkin" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )( params + 0 ) = ClassId;
				*( int* )( params + 4 ) = skinId;
				*( bool* )( params + 8 ) = bLoad1PData;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
