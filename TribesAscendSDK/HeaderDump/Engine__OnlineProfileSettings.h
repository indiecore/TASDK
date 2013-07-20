#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.OnlineProfileSettings." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.OnlineProfileSettings." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.OnlineProfileSettings." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class OnlineProfileSettings : public OnlinePlayerStorage
	{
	public:
			bool GetProfileSettingDefaultId( int ProfileSettingId, int &DefaultId, int &ListIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineProfileSettings.GetProfileSettingDefaultId" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )params = ProfileSettingId;
				*( int* )( params + 4 ) = DefaultId;
				*( int* )( params + 8 ) = ListIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				DefaultId = *( int* )( params + 4 );
				ListIndex = *( int* )( params + 8 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetProfileSettingDefaultInt( int ProfileSettingId, int &DefaultInt )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineProfileSettings.GetProfileSettingDefaultInt" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = ProfileSettingId;
				*( int* )( params + 4 ) = DefaultInt;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				DefaultInt = *( int* )( params + 4 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool GetProfileSettingDefaultFloat( int ProfileSettingId, float &DefaultFloat )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineProfileSettings.GetProfileSettingDefaultFloat" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = ProfileSettingId;
				*( float* )( params + 4 ) = DefaultFloat;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				DefaultFloat = *( float* )( params + 4 );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetToDefaults(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineProfileSettings.SetToDefaults" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AppendVersionToReadIds(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineProfileSettings.AppendVersionToReadIds" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ModifyAvailableProfileSettings(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.OnlineProfileSettings.ModifyAvailableProfileSettings" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
