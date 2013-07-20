#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.GFxUDKFrontEnd_Settings." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.GFxUDKFrontEnd_Settings." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.GFxUDKFrontEnd_Settings." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxUDKFrontEnd_Settings : public GFxUDKFrontEnd_SettingsBase
	{
	public:
			void SetSelectedOptionSet(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_Settings.SetSelectedOptionSet" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateListDataProvider(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_Settings.UpdateListDataProvider" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PopulateOptionDataProviderForIndex( int Index, class GFxObject* &OutDataProvider, ScriptArray< wchar_t > &OutDefaultValue, int &OutDefaultIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUDKFrontEnd_Settings.PopulateOptionDataProviderForIndex" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( int* )params = Index;
				*( class GFxObject** )( params + 4 ) = OutDataProvider;
				*( ScriptArray< wchar_t >* )( params + 8 ) = OutDefaultValue;
				*( int* )( params + 20 ) = OutDefaultIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				OutDataProvider = *( class GFxObject** )( params + 4 );
				OutDefaultValue = *( ScriptArray< wchar_t >* )( params + 8 );
				OutDefaultIndex = *( int* )( params + 20 );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
