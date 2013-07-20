#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Core.DistributionFloat." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Core.DistributionFloat." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Core.DistributionFloat." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class DistributionFloat : public Component
	{
	public:
			ADD_VAR( ::BoolProperty, bIsDirty, 0x2 )
			ADD_VAR( ::BoolProperty, bCanBeBaked, 0x1 )
			float GetFloatValue( float F )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.DistributionFloat.GetFloatValue" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = F;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
