#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.GFxUI_InventoryButton." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.GFxUI_InventoryButton." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.GFxUI_InventoryButton." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxUI_InventoryButton : public GFxClikWidget
	{
	public:
			ADD_OBJECT( GFxObject, IconMC )
			ADD_VAR( ::StrProperty, Content, 0xFFFFFFFF )
			void SetContent( ScriptArray< wchar_t > newContent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUI_InventoryButton.SetContent" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )params = newContent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetIconMC( class GFxObject* iconClip )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.GFxUI_InventoryButton.SetIconMC" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class GFxObject** )params = iconClip;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
