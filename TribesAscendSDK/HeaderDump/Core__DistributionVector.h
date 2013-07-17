#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Core.DistributionVector." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Core.DistributionVector." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Core.DistributionVector." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class DistributionVector : public Component
	{
	public:
			ADD_VAR( ::BoolProperty, bIsDirty, 0x2 )
			ADD_VAR( ::BoolProperty, bCanBeBaked, 0x1 )
			Vector GetVectorValue( float F, int LastExtreme )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Core.DistributionVector.GetVectorValue" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )( params + 0 ) = F;
				*( int* )( params + 4 ) = LastExtreme;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
