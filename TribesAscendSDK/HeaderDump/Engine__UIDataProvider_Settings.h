#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.UIDataProvider_Settings." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.UIDataProvider_Settings." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.UIDataProvider_Settings." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UIDataProvider_Settings : public UIDynamicDataProvider
	{
	public:
			ADD_VAR( ::BoolProperty, bIsAListRow, 0x1 )
			ADD_OBJECT( Settings, Settings )
			void ArrayProviderPropertyChanged( class UIDataProvider* SourceProvider, ScriptName PropTag )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataProvider_Settings.ArrayProviderPropertyChanged" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class UIDataProvider** )params = SourceProvider;
				*( ScriptName* )( params + 4 ) = PropTag;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnSettingValueUpdated( ScriptName SettingName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.UIDataProvider_Settings.OnSettingValueUpdated" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = SettingName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
