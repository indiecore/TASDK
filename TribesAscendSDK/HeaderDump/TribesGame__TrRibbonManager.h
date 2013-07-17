#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrRibbonManager." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrRibbonManager." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrRibbonManager." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrRibbonManager : public Object
	{
	public:
			ADD_VAR( ::BoolProperty, bDirty, 0x1 )
			int GetClassRibbon( int ClassId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrRibbonManager.GetClassRibbon" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = ClassId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int GetTypeRibbon( int ClassId, int Type )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrRibbonManager.GetTypeRibbon" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = ClassId;
				*( int* )( params + 4 ) = Type;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int GetEquipRibbon( int EquipId )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrRibbonManager.GetEquipRibbon" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = EquipId;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, bHaveUnlocks, 0x2 )
			ADD_VAR( ::BoolProperty, bOnlyUnlocks, 0x4 )
			ADD_VAR( ::BoolProperty, bHaveUpgrades, 0x8 )
			ADD_VAR( ::BoolProperty, bOnlyUpgrades, 0x10 )
			ADD_VAR( ::IntProperty, PreviousGold, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PreviousXP, 0xFFFFFFFF )
			void CalculateRibbons( int Gold, int XP, bool bForce )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrRibbonManager.CalculateRibbons" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )( params + 0 ) = Gold;
				*( int* )( params + 4 ) = XP;
				*( bool* )( params + 8 ) = bForce;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
